namespace AntiHack
{
	static float noclip_margin_dismount = 0.22f;
	static float noclip_backtracking = 0.01f;
	static bool reporting = false;
	static bool admincheat = true;
	static bool objectplacement = true;
	static bool modelstate = true;
	static bool forceposition = true;
	static int userlevel = 2;
	static int enforcementlevel = 1;
	static float maxdesync = 1.f;
	static float maxdeltatime = 1.f;
	static float tickhistorytime = 0.5f;
	static float tickhistoryforgiveness = 0.1f;
	static float relaxationrate = 0.1f;
	static float relaxationpause = 10.f;
	static float maxviolation = 100.f;
	static int terrain_protection = 1;
	static int terrain_timeslice = 64;
	static float terrain_padding = 0.3f;
	static float terrain_penalty = 100.f;
	static bool terrain_kill = true;
	static bool terrain_check_geometry = false;
	static int noclip_protection = 3;
	static bool noclip_reject = true;
	static float noclip_penalty = 0.f;
	static float noclip_margin = 0.09f;
	static float noclip_stepsize = 0.1f;
	static int noclip_maxsteps = 15;
	static int speedhack_protection = 2;
	static bool speedhack_reject = true;
	static float speedhack_penalty = 0.f;
	static float speedhack_forgiveness = 2.f;
	static float speedhack_forgiveness_inertia = 10.f;
	static float speedhack_slopespeed = 10.f;
	static int flyhack_protection = 3;
	static bool flyhack_reject = false;
	static float flyhack_penalty = 100.f;
	static float flyhack_forgiveness_vertical = 1.5f;
	static float flyhack_forgiveness_vertical_inertia = 10.f;
	static float flyhack_forgiveness_horizontal = 1.5f;
	static float flyhack_forgiveness_horizontal_inertia = 10.f;
	static float flyhack_extrusion = 2.f;
	static float flyhack_margin = 0.05f;
	static float flyhack_stepsize = 0.1f;
	static int flyhack_maxsteps = 15;
	static int projectile_protection = 6;
	static float projectile_penalty = 0.f;
	static float projectile_forgiveness = 0.5f;
	static float projectile_serverframes = 2.f;
	static float projectile_clientframes = 2.f;
	static float projectile_trajectory = 1.f;
	static float projectile_anglechange = 60.f;
	static float projectile_velocitychange = 1.1f;
	static float projectile_desync = 1.f;
	static float projectile_backtracking = 0.01f;
	static float projectile_losforgiveness = 0.2f;
	static int projectile_damagedepth = 2;
	static int projectile_impactspawndepth = 1;
	static bool projectile_terraincheck = true;
	static bool projectile_vehiclecheck = true;
	static bool projectile_positionoffset = true;
	static int melee_protection = 4;
	static float melee_penalty = 0.f;
	static float melee_forgiveness = 0.5f;
	static float melee_serverframes = 2.f;
	static float melee_clientframes = 2.f;
	static float melee_backtracking = 0.01f;
	static float melee_losforgiveness = 0.2f;
	static bool melee_terraincheck = true;
	static bool melee_vehiclecheck = true;
	static int eye_protection = 4;
	static float eye_penalty = 0.f;
	static float eye_forgiveness = 0.5f;
	static float eye_serverframes = 2.f;
	static float eye_clientframes = 2.f;
	static bool eye_terraincheck = true;
	static bool eye_vehiclecheck = true;
	static float eye_noclip_cutoff = 0.06f;
	static float eye_noclip_margin = 0.21f;
	static float eye_noclip_backtracking = 0.01f;
	static float eye_losradius = 0.18f;
	static float eye_history_penalty = 100.f;
	static float eye_history_forgiveness = 0.1f;
	static float build_losradius = 0.01f;
	static float build_losradius_sleepingbag = 0.3f;
	static bool build_terraincheck = true;
	static bool build_vehiclecheck = true;
	static int build_inside_check = 2;
	static int debuglevel = 1;
}

bool VerifyClientRPC(BasePlayer* player)
{
	if (player == NULL) return false;
	if (player != local_player) return false;
	if (player->is_dead()) return false;
	if (player->is_wounded()) return false;
	if (player->is_sleeping()) return false;
	if (vars::manipulator::desync > AntiHack::maxdesync) return false;
	Item* ownerItem = local_player->GetHeldItme();
	if (ownerItem == NULL) return false;
	if (ownerItem->isBroken()) return false;
	return true;
}
bool VerifyClientAttack(BasePlayer* player, BaseMelee* _this)
{
	if (!VerifyClientRPC(player)) return false;
	if (_this->HasAttackCooldown()) return false;
	return true;
}
float maxmeleedist;
bool MeleePlayerAttack(BaseMelee* _this, BasePlayer* hitent, Vector3 killpos)
{
	BasePlayer* player = local_player; BaseEntity* ent_player = (BaseEntity*)player;
	BasePlayer* basePlayer = hitent; BaseEntity* hitEntity = (BaseEntity*)basePlayer;
	if (!VerifyClientAttack(player, _this)) return false;
	PlayerAttack* playerAttack = PlayerAttack::New();
	if (playerAttack != NULL)
	{
		bool flag = basePlayer != NULL;
		bool flag2 = flag && basePlayer->is_sleeping();
		bool flag3 = flag && basePlayer->is_wounded();
		bool flag4 = flag && basePlayer->isMounted();
		bool flag5 = flag && basePlayer->HasParent();
		bool flag6 = hitEntity != NULL;
		bool flag7 = flag6 && basePlayer->playerModel()->isNpc();
		if (AntiHack::melee_protection > 0)
		{
			bool flag8 = true;
			float num = 1.f + AntiHack::melee_forgiveness;
			float melee_clientframes = AntiHack::melee_clientframes;
			float melee_serverframes = AntiHack::melee_serverframes;
			float num2 = melee_clientframes / 60.f;
			float num3 = melee_serverframes * Max3(Time::deltaTime(), Time::smoothDeltaTime(), Time::fixedDeltaTime());
			float num4 = (vars::manipulator::desync + num2 + num3) * num;
			int num5 = 2162688;
			if (AntiHack::melee_terraincheck)
			{
				num5 |= 8388608;
			}
			if (AntiHack::melee_vehiclecheck)
			{
				num5 |= 134217728;
			}
			if (AntiHack::melee_protection >= 2)
			{
				if (flag6)
				{
					float num6 = hitEntity->MaxVelocity() + hitEntity->GetParentVelocity().Magnitude();
					float num7 = hitEntity->BoundsPadding() + num4 * num6;
					float num8 = hitEntity->Distance(killpos);
					if (num8 > num7) flag8 = false;
				}
				if (AntiHack::melee_protection >= 4 && flag8 && flag && !flag7 && !flag2 && !flag3 && !flag4 && !flag5)
				{
					float magnitude = hitEntity->GetParentVelocity().Magnitude();
					float num9 = hitEntity->BoundsPadding() + num4 * magnitude + AntiHack::tickhistoryforgiveness;
					float num10 = hitEntity->Distance(killpos);
					if (num10 > num9) flag8 = false;
				}
			}
			if (AntiHack::melee_protection >= 1)
			{
				if (AntiHack::melee_protection >= 4)
				{
					float magnitude2 = ent_player->GetParentVelocity().Magnitude();
					float num11 = ent_player->BoundsPadding() + num4 * magnitude2 + num * _this->maxDistance();
					float num12 = ent_player->Distance(killpos);
					if (num12 > num11) flag8 = false;
				}
				else
				{
					float num13 = ent_player->MaxVelocity() + ent_player->GetParentVelocity().Magnitude();
					float num14 = ent_player->BoundsPadding() + num4 * num13 + num * _this->maxDistance();
					float num15 = ent_player->Distance(killpos);
					if (num15 > num14) flag8 = false;
				}
			}
			if (AntiHack::melee_protection >= 3)
			{
				if (flag6 && player && player->eyes())
				{
					Vector3 pointStart = player->eyes()->position();
					Vector3 hitPositionWorld = killpos;
					Vector3 center = player->eyes()->center();
					Vector3 position = pointStart;
					Vector3 vector = pointStart;
					Vector3 vector2 = hitPositionWorld + ((hitPositionWorld - pointStart) * 0.001f);
					Vector3 vector3 = hitPositionWorld;
					bool flag9 = LineOfSight(center, position) && LineOfSight(position, vector) && LineOfSight(vector, vector2) && LineOfSight(vector2, vector3);
					if (!flag9) flag8 = false;
				}
				if (flag8 && flag && !flag7 && basePlayer && basePlayer->eyes())
				{
					Vector3 hitPositionWorld2 = killpos;
					Vector3 position2 = basePlayer->eyes()->position();
					Vector3 vector4 = basePlayer->GetBoneByID(spine4).midPoint(basePlayer->eyes()->position().midPoint(basePlayer->playerModel()->position()));
					float melee_losforgiveness = AntiHack::melee_losforgiveness;
					bool flag10 = LineOfSight(hitPositionWorld2, position2) && LineOfSight(position2, hitPositionWorld2);
					if (!flag10)
					{
						flag10 = LineOfSight(hitPositionWorld2, vector4) && LineOfSight(vector4, hitPositionWorld2);
					}
					if (!flag10) flag8 = false;
				}
			}
			return flag8;
		}
	}
}

void SimulateProjectile(Vector3 position, Vector3 velocity, float partialTime, float travelTime, Vector3 gravity, float drag, Vector3 prevPosition, Vector3 prevVelocity)
{
	float num = 0.03125f;
	prevPosition = position;
	prevVelocity = velocity;
	if (partialTime > 0)
	{
		float num2 = num - partialTime;
		if (travelTime < num2)
		{
			prevPosition = position;
			prevVelocity = velocity;
			position += velocity * travelTime;
			partialTime += travelTime;
			return;
		}
		prevPosition = position;
		prevVelocity = velocity;
		position += velocity * num2;
		velocity += gravity * num;
		velocity -= velocity * (drag * num);
		travelTime -= num2;
	}
	int num3 = int(travelTime / num);
	for (int i = 0; i < num3; i++)
	{
		prevPosition = position;
		prevVelocity = velocity;
		position += velocity * num;
		velocity += gravity * num;
		velocity -= velocity * (drag * num);
	}
	partialTime = travelTime - num * (float)num3;
	if (partialTime > 0)
	{
		prevPosition = position;
		prevVelocity = velocity;
		position += velocity * partialTime;
	}
}
/*
bool OnProjectileAttack(Projectile* projectile, Vector3 HitPositionWorld)
{
	float timeSinceLastTick = (Time::realtimeSinceStartup() - local_player->lastSentTickTime());
	float desyncTimeRaw = max(timeSinceLastTick, 0.f);
	float desyncTimeClamped = min(desyncTimeRaw, 1.f);

	Vector3 position = projectile->currentPosition();
	Vector3 positionOffset = projectile->positionOffset;
	Vector3 velocity = projectile->currentVelocity();
	//float partialTime = firedProjectile.partialTime;
	float travelTime = projectile->traveledTime();
	float num = Mathf::Clamp(projectile->traveledTime(), projectile->traveledTime(), 8.f);
	Vector3 gravity = Physics::gravity() * projectile->gravityModifier();
	float drag = projectile->drag();
	BaseEntity* hitEntity = target_player;
	BasePlayer* basePlayer = target_player;
	bool flag = basePlayer != NULL;
	bool flag2 = flag && basePlayer->is_sleeping();
	bool flag3 = flag && basePlayer->is_wounded();
	bool flag4 = flag && basePlayer->isMounted();
	bool flag5 = flag && basePlayer->HasParent();
	bool flag6 = hitEntity != NULL;
	bool flag7 = flag6 && basePlayer->playerModel()->isNpc();
	bool flag8 = false;
	{
		bool flag9 = true;
		float num2 = 1.f + AntiHack::projectile_forgiveness;
		float num3 = 1.f - AntiHack::projectile_forgiveness;
		float projectile_clientframes = AntiHack::projectile_clientframes;
		float projectile_serverframes = AntiHack::projectile_serverframes;
		float num4 = Mathx::Decrement(projectile->firedTime);
		float num5 = Mathf::Clamp(Mathx::Increment(Time::realtimeSinceStartup()) - num4, 0.f, 8.f);
		float num6 = num;
		float num7 = Mathf::Abs(num5 - num6);
		//firedProjectile.desyncLifeTime = num7;
		float num8 = min(num5, num6);
		float num9 = projectile_clientframes / 60.f;
		float num10 = projectile_serverframes * Max3(Time::deltaTime(), Time::smoothDeltaTime(), Time::fixedDeltaTime());
		float num11 = (desyncTimeClamped + num8 + num9 + num10) * num2;
		float num12 = ((desyncTimeClamped + num9 + num10) * num2);
		float num13 = (num5 - desyncTimeClamped - num9 - num10) * num3;
		float num14 = projectile->initialPosition.Distance(HitPositionWorld);
		int num15 = 2162688;
		if (AntiHack::projectile_terraincheck)
		{
			num15 |= 8388608;
		}
		if (AntiHack::projectile_vehiclecheck)
		{
			num15 |= 134217728;
		}
		if (flag8)
		{
			if (flag6)
			{
				flag9 = false;
			}
		}

		//if (flag6)
		//{
		//	float num16 = hitEntity->MaxVelocity() + hitEntity->GetParentVelocity().Magnitude();
		//	float num17 = hitEntity->BoundsPadding() + num12 * num16;
		//	float num18 = hitEntity->Distance(HitPositionWorld);
		//	if (num18 > num17)
		//	{
		//		flag9 = false;
		//	}
		//}
		//if (flag9 && flag && !flag7 && !flag2 && !flag3 && !flag4 && !flag5)
		//{
		//	float magnitude = basePlayer->GetParentVelocity().Magnitude();
		//	float num19 = basePlayer->BoundsPadding() + num12 * magnitude + AntiHack::tickhistoryforgiveness;
		//	float num20 = basePlayer->Distance(HitPositionWorld);
		//	if (num20 > num19)
		//	{
		//		flag9 = false;
		//	}
		//}

		{
			float num21 = flag6 ? (hitEntity->MaxVelocity() + hitEntity->GetParentVelocity().Magnitude()) : 0.f;
			float num22 = flag6 ? (num12 * num21) : 0.f;
			float magnitude2 = projectile->initialVelocity().Magnitude();
			float num23 = projectile->initialDistance() + num11 * magnitude2;
			//float num24 = projectile->ProjectileDistance + 1.f + positionOffset.Magnitude() + num22;
			if (num14 > num23)
			{
				flag9 = false;
			}
			//if (num14 > num24)
			//{
			//	flag9 = false;
			//}
			if (num7 > AntiHack::projectile_desync)
			{
				flag9 = false;
			}

			float magnitude3 = velocity.Magnitude();
			float num31 = num13 * magnitude3;
			if (num14 < num31)
			{
				flag9 = false;
			}
		}
		return flag9;
	}
}
*/
bool Reload(BaseProjectile* _this) {
	if (!_this) return true;
	if (_this->HasReloadCooldown()) return false;
	return true;
}
bool CLProject(BaseProjectile* _this) {
	if (!_this) return true;

	const auto mag = _this->primaryMagazine();
	if (!mag) return false;
	auto ammo = mag->contents();
	if (ammo <= 0) return false;
	return true;
}

bool validateshot(BaseProjectile* _this) {
	if (!Reload(_this) || !CLProject(_this) || Time::time() < _this->nextAttackTime() || local_player->active_weapon()->isBroken() || _this->HasAttackCooldown()) return false;
	return true;
}
inline float flyhackPauseTime;
inline float flyhackDistanceVertical = 0.f;
inline float flyhackDistanceHorizontal = 0.f;

bool inAir(BasePlayer* ply, Vector3 oldPos, Vector3 newPos)
{
	bool isFlying = false;
	float num = 2.0f;

	float radius = ply->GetRadius();
	float height = ply->GetHeight();
	Vector3 vector = (oldPos + newPos) * 0.5f;

	if (!ply->HasParent() && !WaterLevel::WaterLevelTest(vector - Vector3(0.0f, num, 0.0f), true, ply) && (EnvironmentManager::Get(vector) & EnvironmentType::Elevator) == (EnvironmentType)0)
	{
		Vector3 vector2 = vector + Vector3(0.0f, radius - num, 0.0f);
		Vector3 vector3 = vector + Vector3(0.0f, height - radius, 0.0f);
		float radius2 = radius - 0.05f;
		isFlying = !Physics::CheckCapsule(vector2, vector3, radius2, 1503731969, QueryTriggerInteraction::Ignore);
	}

	return isFlying;
}
bool isInAir;
bool TestFlying(BasePlayer* ply, Vector3 oldPos, Vector3 newPos)
{
	isInAir = inAir(ply, oldPos, newPos);
	Vector3 vector = (oldPos + newPos) * 0.5f;
	flyhackPauseTime = max(0.f, flyhackPauseTime - Time::deltaTime());
	if (isInAir)
	{
		if (!ply->is_sleeping() && !ply->OnLadder() && !ply->isMounted())
		{
			bool flag = false;
			Vector3 vector4 = newPos - oldPos;
			float num2 = math::abs(vector4.y);
			float num3 = vector4.Magnitude2D();
			if (vector4.y >= 0.0f)
			{
				flyhackDistanceVertical += vector4.y;
				flag = true;
			}
			if (num2 < num3)
			{
				flyhackDistanceHorizontal += num3;
				flag = true;
			}
			if (flag)
			{
				float num4 = max((flyhackPauseTime > 0.0f) ? 10.f : 1.5f, 0.0f);
				float num5 = (ply->GetJumpHeight() + num4) * 2.6;
				vars::antihack::maxverticalflyhack = num5;
				float num6 = max((flyhackPauseTime > 0.f) ? 10.f : 1.5f, 0.f);
				float num7 = (5.0f + num6) * 2.6;
				vars::antihack::maxhorisontalflyhack = num7;
				if (flyhackDistanceVertical >= num5) return true;
				if (flyhackDistanceHorizontal >= num7) return true;
			}
		}
		else {
			flyhackDistanceVertical = 0.0f;
			flyhackDistanceHorizontal = 0.0f;
		}
	}
	else {
		flyhackDistanceVertical = 0.0f;
		flyhackDistanceHorizontal = 0.0f;
	}

	vars::antihack::horisontalflyhack = flyhackDistanceHorizontal;
	vars::antihack::verticalflyhack = flyhackDistanceVertical;
	return false;
}


/*

MetalDetectorSource* metalDetectorSource = (MetalDetectorSource*)entity;
		if (metalDetectorSource) {
			List<Vector3>* treasureList = metalDetectorSource->SpawnLocations();
			if (treasureList) {
				int locationAmount = treasureList->get_size();
				for (int treasureIndex = 0; treasureIndex < locationAmount; treasureIndex++) {
					Vector3 treasurePosition = treasureList->GetArray(treasureIndex);
					other::DrawObject(nullptr, vars::object::show_ores_distance, vars::object::max_ores_distance, _(L"Treasure"), { 255, 215, 0, 255 }, false, treasurePosition);
				}
			}
		}
*/

bool TestInsideTerrain(Vector3 pos)
{
	auto Meta = TerrainMeta::New();
	if (!Meta) return false;
	if (!Meta->HeightMap()) return false;
	if (!Meta->terrain()) return false;
	if (!Meta->Collision()) return false;

	float height = Meta->HeightMap()->GetHeight(pos);

	if (pos.y > height - 0.3f)
		return false;

	float gaysex = Meta->Position().y + Meta->terrain()->SampleHeight(pos);
	return pos.y <= gaysex - 0.3f && !Meta->Collision()->GetIgnore(pos, 0.01f);
}
bool IsInsideTerrain(bool prevent = false)
{
	BasePlayer* player = local_player;
	bool result = TestInsideTerrain(player->transform()->position());
	if (prevent && result)
		player->ForcePositionTo(player->lastSentTick()->position());
	return result;
}
Vector3 findClosestPoint(Vector3 targetPoint, Vector3(&points)[20]) {

	Vector3 closestPoint = points[0];
	float minDistance = targetPoint.Distance(closestPoint);

	for (int i = 0; i < 20; ++i) {
		if (points[i] == Vector3::Zero()) continue;
		float currentDistance = targetPoint.Distance(points[i]);
		if (currentDistance < minDistance) {
			minDistance = currentDistance;
			closestPoint = points[i];
		}
	}
	return closestPoint;
}
//void farmbot(bool prevent = false)
//{
//	if (!prevent) return;
//
//	RaycastHit lookdir;
//	auto CheckayCast = rc<bool(*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(g_base + CO::RaycastHit);
//	if (CheckayCast(MainCamera::Camera()->position(), MainCamera::Camera()->forward(), &lookdir, 1000.f, 256 | 2048 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
//	{
//		DDraw::Capsule(lookdir.m_Point, Quaternion(), 0.2, 2 * 0.2, {1, 1, 1, 1), 0.001f, false, true);
//	}
//
//	Vector3 down_localpos = local_player->playerposition();
//
//	const int numSegments = 20;
//	const float angleIncrement = 2.0f * static_cast<float>(M_PI) / static_cast<float>(numSegments);
//	
//	int radius = 1;
//	for (int i = 0; i < 10; ++i)
//	{
//		Vector3 points[numSegments];
//		for (int i = 0; i < numSegments; ++i)
//		{
//			float angle = angleIncrement * static_cast<float>(i);
//			float x = down_localpos.x + radius * math::cos(angle);
//			float z = down_localpos.z + radius * math::sin(angle);
//			Vector3 point = Vector3(x, down_localpos.y, z);
//			Vector3 point_up = Vector3(x, down_localpos.y + 1.5f, z);
//
//			Vector3 normalized = (point - point_up).UnityNormalizeVec3();
//			Vector3 vector = point_up - normalized * 0.01f;
//			RaycastHit outRay;
//
//			auto CheckayCast = rc<bool(*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(g_base + CO::RaycastHit);
//			if (CheckayCast(vector, normalized, &outRay, 30, 256 | 2048 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
//			{
//				points[i] = outRay.m_Point;
//				DDraw::Sphere(outRay.m_Point, 0.1f, {1,0,0,1), 0.01f, false, false);
//			}
//		}
//		Vector3 closestPoint = findClosestPoint(lookdir.m_Point, points);
//		DDraw::Sphere(closestPoint, 0.15f, {0, 1, 0, 1), 0.01f, false, false);
//
//		radius += 1;
//	}
//
//}
/*
Color validcheck;
				if (down_localpos.Distance(lookdir.m_Point) > outRay.m_Point.Distance(lookdir.m_Point))
					validcheck = {0, 1, 0, 1);
				else
					validcheck = {1, 0, 0, 1);

				DDraw::Sphere(outRay.m_Point, 0.1f, validcheck, 0.01f, false, false);
*/