#pragma once
Vector3 projectile_velocity;
Vector3 projectile_eyepos;


void bulletchecker(Projectile* projectile)
{
	if (!projectile->isAuthoritative() || !projectile->isAlive() || !projectile->projectileID() || projectile->integrity() == 0 || RPC_Counter.Calculate() > 100) return;
	if (projectile->swimScale() != Vector3::Zero()) projectile->swimScale(Vector3(0.f, 0.f, 0.f));
	Vector3 tpcurrentPosition = projectile->currentPosition();
	Vector3 tpcurrentVelocity = projectile->currentVelocity();
	float tptraveledDistance = projectile->traveledDistance();
	float tptraveledTime = projectile->traveledTime();
	Vector3 nextBulletPos = tpcurrentPosition + (tpcurrentVelocity * Time::fixedDeltaTime());
	if (vars::trasers::bullet_tracers)
		DDraw::Line(tpcurrentPosition, nextBulletPos, { vars::trasers::bullet_tracers_color.r / 255.f, vars::trasers::bullet_tracers_color.g / 255.f, vars::trasers::bullet_tracers_color.b / 255.f, vars::trasers::bullet_tracers_color.a / 255.f }, vars::trasers::bullet_tracers_time, false, true);
	if (objects::target_heli_see && target_heli != nullptr && vars::bulletteleport::tp_heli_bullet)
	{
		Transform* transform = 0;
		int health = (int)target_heli->health();
		if (health <= 5000) {
			transform = target_heli->GetTransform(19); 
		}
		else {
			transform = target_heli->GetTransform(22); 
		}
		Vector3 point = projectile->currentPosition();
		Vector3 tar = transform->position();

		if (LineOfSight(tar, point) && point.Distance(tar) < 30)
		{
			HitTest* hitTest = projectile->hitTest();
			hitTest->DidHit(true);
			hitTest->HitPart(2699525250);
			hitTest->HitEntity(target_heli);
			hitTest->HitTransform(transform);
			hitTest->HitPoint(transform->InverseTransformPoint(point));
			hitTest->HitNormal(transform->InverseTransformDirection(point));
			hitTest->AttackRay(Ray(point, tar - point));
			projectile->DoHit(hitTest, hitTest->HitPointWorld(), hitTest->HitNormalWorld());
			RPC_Counter.Increment();
			return;
		}
	}

	if (target_player == nullptr) return;
	if (vars::bulletteleport::tp_bullet) {
		Transform* playerTransform = target_player->GetTransform(target_bone);
		Vector3 playerPos = playerTransform->position();

		Line updateLine = Line(tpcurrentPosition, nextBulletPos);
		Vector3 closestUpdateToPlayer = updateLine.ClosestPoint(playerPos);

		Vector3 newBulletPos = MoveTowards(closestUpdateToPlayer, playerPos, 0.99f); Vector3 newBulletPosx2 = MoveTowards(newBulletPos, playerPos, 0.99f);
		if (newBulletPos == newBulletPosx2) {
			newBulletPosx2.y += 0.01f;
		}

		float distanceToPlayer = closestUpdateToPlayer.Distance(playerPos);

		if (distanceToPlayer <= 4 && closestUpdateToPlayer.Distance(newBulletPos) <= 1.f) {
			Vector3 velocityPerTick = tpcurrentVelocity * Time::fixedDeltaTime();
			float velocityPerTickSpeed = velocityPerTick.Length();
			float speedPerSecond = 1.f / velocityPerTickSpeed;
			float distanceTraveled = (closestUpdateToPlayer - tpcurrentPosition).Length();
			float sstraveledTime = distanceTraveled * speedPerSecond * Time::fixedDeltaTime();

			Vector3 pointStart = newBulletPos;
			Vector3 vector = newBulletPosx2;
			vector -= tpcurrentVelocity.Normalized() * 0.001f;
			Vector3 vector2 = vector;
			Vector3 b2 = (pointStart - closestUpdateToPlayer).Normalized() * 0.01f;
			Vector3 b3 = (vector2 - pointStart).Normalized() * 0.01f;

			auto CenterPosition = target_player->PivotPoint() + Vector3(0.f, 0.9f, 0.f);
			if (LineOfSight(tpcurrentPosition, closestUpdateToPlayer) && LineOfSight(tpcurrentPosition, newBulletPos) &&
				LineOfSight(newBulletPos, newBulletPosx2) && LineOfSight(newBulletPosx2, playerPos) &&
				LineOfSight(newBulletPosx2, CenterPosition) && LineOfSight(playerPos, newBulletPos) &&
				LineOfSight(closestUpdateToPlayer - b2, pointStart + b2) && LineOfSight(pointStart - b3, vector2) &&
				LineOfSight(vector2, vector)) {

				float timeSinceLastTick = (Time::realtimeSinceStartup() - local_player->lastSentTickTime());
				float last_tick_time = max(0.f, min(timeSinceLastTick, 1.f));

				float num = 1.5f;
				float eye_clientframes = 2.0f;
				float eye_serverframes = 2.0f;
				float num2 = eye_clientframes / 60.f;
				float num3 = eye_serverframes * Max3(Time::deltaTime(), Time::smoothDeltaTime(), Time::fixedDeltaTime());
				float num4 = (last_tick_time + num2 + num3) * num;

				float num5 = local_player->GetMaxSpeed() + local_player->GetParentVelocity().Magnitude();
				float num6 = local_player->BoundsPadding() + num4 * num5;

				/*float magnitude = target_player->GetParentVelocity().UnityMagnitude();
				float num19 = 0.1f + num4 * magnitude + 0.1f;
				float num20 = target_player->Distance(newBulletPosx2);

				float num16 = target_player->MaxVelocity() + target_player->GetParentVelocity().UnityMagnitude();
				float num17 = 0.1f + num4 * num16;
				float num18 = target_player->Distance(newBulletPosx2);*/

				Vector3 centerserver_t = target_player->playerModel()->position() + Vector3(0, 1.2, 0);
				float num18 = centerserver_t.Distance(closestUpdateToPlayer);

				float travel = max((tptraveledTime + sstraveledTime) - projectile->closeFlybyDistance(), 0);
				Vector3 gr = Physics::gravity();

				Vector3 a; Vector3 b;
				SimulateProjectile(newBulletPos, projectile->currentVelocity(), projectile->tumbleSpeed(), travel, gr * projectile->gravityModifier(), projectile->drag(), a, b);

				Vector3 positionOffset = Vector3(); float num25 = 0.f;

				float num26 = target_player->GetParentVelocity().UnityMagnitude();
				num25 = num6 * num26;

				Line line_1 = Line(a - b, newBulletPos + b);
				float num27 = max(line_1.Distance(newBulletPos) - positionOffset.UnityMagnitude() - num25, 0.f);
				float num28 = max(line_1.Distance(newBulletPosx2) - positionOffset.UnityMagnitude() - num25, 0.f);

				bool flag6 = target_player != nullptr;
				float num14 = newBulletPos.Distance(newBulletPosx2);
				float num21 = flag6 ? (target_player->MaxVelocity() + target_player->GetParentVelocity().UnityMagnitude()) : 0.f;
				float num22 = flag6 ? (num6 * num21) : 0.f;
				float num24 = (tptraveledDistance + distanceTraveled) + 1.f + positionOffset.UnityMagnitude() + num22;

				//if (num18 <= num17 && num20 <= num19 && num27 <= 1.f && num28 <= 1.f && num14 <= num24) {
				if (num27 <= 1.f && num28 <= 1.f && num14 <= num24 && num18 <= 2.9) {
					HitTest* hitTest = projectile->hitTest();
					PlayerProjectileUpdate* ppu = PlayerProjectileUpdate::New();
					PlayerProjectileAttack* ppa = PlayerProjectileAttack::New();
					if (ppu && ppa && hitTest) {
						projectile->traveledDistance(tptraveledDistance + distanceTraveled);
						projectile->traveledTime(tptraveledTime + sstraveledTime);
						ppu->projectileID(projectile->projectileID());
						ppu->travelTime(tptraveledTime + sstraveledTime);
						ppu->curVelocity(tpcurrentVelocity);
						ppu->curPosition(closestUpdateToPlayer);
						projectile->owner()->SendProjectileUpdate(ppu);
						RPC_Counter.Increment();
						ppu->curPosition(newBulletPos);
						projectile->owner()->SendProjectileUpdate(ppu);
						RPC_Counter.Increment();
						hitTest->DidHit(true);
						hitTest->HitEntity(target_player);
						hitTest->HitTransform(playerTransform);
						hitTest->HitPoint(playerTransform->InverseTransformPoint(newBulletPosx2));
						hitTest->HitNormal(playerTransform->InverseTransformDirection(newBulletPosx2));
						hitTest->AttackRay(Ray(newBulletPos, Vector3()));
						hitTest->damageProperties(projectile->damageProperties());
						hitTest->MaxDistance(1000.0f);

						projectile->DoHit(hitTest, newBulletPosx2, Vector3());
						DDraw::Capsule(closestUpdateToPlayer, Quaternion(), 0.3f, 2 * 0.3f, { 10, 10, 10, 10 }, 5.f, false, true);
						RPC_Counter.Increment();
					}
				}
			}
		}
	}
}