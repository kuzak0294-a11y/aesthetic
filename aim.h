Vector3 Basepredict(/*Projectile* projectile, */Vector3 eyepos, Vector3 targetpos, bool checkLOS = false) {
	if (target_player == nullptr) return Vector3::Zero();

	auto baseprojectile = local_player->active_entity<BaseProjectile>();
	auto mod = ((Networkable*)baseprojectile->primaryMagazine()->ammoType())->GetComponent(il2cpp::type_object(_(""), _("ItemModProjectile")));

	auto projectileObject = u_mem::read<uintptr_t>((uintptr_t)mod + values::ItemModProjectile::projectileObject);
	if (!projectileObject) return Vector3::Zero();
	UINT_PTR projectileType = (UINT_PTR)il2cpp::type_object(_(""), _("Projectile"));
	if (!projectileType) return Vector3::Zero();
	Type* projectileClass = (Type*)GetClassObject(projectileObject);
	if (!projectileClass) return Vector3::Zero();
	Projectile* projectile = (Projectile*)GameObject::GetGameObjectComponent(projectileType, (UINT_PTR)projectileClass);


	if (projectile == nullptr) return Vector3::Zero();
	bool mounted = target_player->isMounted();
	auto projectileVelocitymenu = ((ItemModProjectile*)mod)->projectileVelocity(); auto projectileVelocityScale = baseprojectile->GetProjectileVelocityScale(false);
	float drag = projectile->drag(); float gravityModifier = projectile->gravityModifier(); auto gravity = Physics::gravity();
	auto get_fixedDeltaTime = Time::fixedDeltaTime(); auto get_timeScale = Time::timeScale(); float deltaTime = get_fixedDeltaTime * get_timeScale;
	Vector3 actualtargetposition = targetpos; Vector3 localPosition = eyepos; Vector3 targetPosition = actualtargetposition;
	Vector3 playerVelocity = Vector3(target_player->GetWorldVelocity().x, 0, target_player->GetWorldVelocity().z) /** 0.75f*/;
	if (mounted) {
		playerVelocity = Vector3(target_player->GetWorldVelocity().x, target_player->GetWorldVelocity().y, target_player->GetWorldVelocity().z)/* * 0.75f*/;
	}
	float bulletTime;
	{
		bool hightqwality = false;
		for (int simulations = 1; simulations <= 15; simulations++) {
			bool hitPlayers = false;
			Vector3 _aimdirection = AimConeUtil::GetModifiedAimConeDirection(0.f, targetPosition - localPosition, false);
			Vector3 velocity = _aimdirection * projectileVelocitymenu * projectileVelocityScale;
			auto currentPosition = localPosition;
			Vector3 previousPosition = currentPosition;
			Vector3 offset = Vector3().Zero();

			Vector3 closestPoint(100000000, 100000000, 100000000);
			for (int i = -1; i < ((int)(8.f / deltaTime)); i++)
			{
				previousPosition = currentPosition;
				currentPosition += velocity * deltaTime;
				velocity += gravity * gravityModifier * deltaTime;
				velocity -= velocity * drag * deltaTime;
				DDraw::Line(previousPosition, currentPosition, { 1,1,1,1 }, 0.001f, false, true);
				if (!hightqwality) {
					Line updateLine = Line(previousPosition, currentPosition);
					Vector3 closestUpdateToPlayer = updateLine.ClosestPoint(actualtargetposition);
					float distanceToPlayer = closestUpdateToPlayer.Distance(actualtargetposition);
					if (eyepos.Distance2D(actualtargetposition) <= eyepos.Distance2D(closestUpdateToPlayer))
					{
						if (actualtargetposition.y - previousPosition.y > 0)
							offset += Vector3(0, actualtargetposition.y - previousPosition.y, 0);
						else hightqwality = true;
						break;
					}
				}
				else {
					auto line = (currentPosition - previousPosition); auto len = line.UnityMagnitude(); line.UnityNormalize();
					auto v = actualtargetposition - previousPosition; auto d = Vector3().UnityDot(v, line);

					if (d < 0.f) d = 0.f;
					else if (d > len) d = len;

					Vector3 nearestPoint = previousPosition + line * d;
					if (nearestPoint.Distance(actualtargetposition) < 0.01f)
					{
						bulletTime = i * deltaTime;
						hitPlayers = true;
						break;
					}
					else if (nearestPoint.Distance(actualtargetposition) < closestPoint.Distance(actualtargetposition))
					{
						closestPoint = nearestPoint;
						offset = actualtargetposition - nearestPoint;
						//DDraw::Capsule(closestPoint, Quaternion(), 0.1, 2 * 0.1, { 0, 1, 0, 1 }, 3.000f, false, true);
					}
				}
			}

			if (hitPlayers) break;
			else if (simulations == 15) return Vector3::Zero();
			targetPosition += offset;
		}
	}
	actualtargetposition += playerVelocity * (bulletTime - (2 * 0.03125f));

	if (!mounted) {
		Vector3 head_pos = targetpos; RaycastHit head_outRay;
		auto CheckayCast = rc<bool(*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(g_base + CO::RaycastHit);
		Vector3 head_down_pos; float dist_to_head;
		if (CheckayCast(head_pos, Vector3(0, -1, 0), &head_outRay, 1000.f, 256 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
		{
			head_down_pos = head_outRay.m_Point;
			dist_to_head = head_down_pos.Distance(head_pos);
		}
		float dist_to_next = targetpos.Distance(actualtargetposition);
		Vector3 cur_next_pos;
		Vector3 dont_try_this = actualtargetposition;
		for (int i = 1; i < 30; i++) {
			RaycastHit next_head_outRay;
			if (CheckayCast(dont_try_this + Vector3(0, 100, 0), Vector3(0, -1, 0), &next_head_outRay, 1000.f, 256 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
			{
				if (targetpos.Distance(next_head_outRay.m_Point) > dist_to_next + 0.05f) {
					dont_try_this = MoveTowards(dont_try_this, targetpos, 0.025f);
					//DDraw::Capsule(dont_try_this, Quaternion(), 0.1, 2 * 0.1, { 0, 1, 0, 1 }, 10.000f, false, true);
					if (i != 29) continue;
				}
				if (targetpos.Distance(next_head_outRay.m_Point) < dist_to_next - 0.05f) {
					dont_try_this = MoveTowards(dont_try_this, actualtargetposition, 0.025f);
					//DDraw::Capsule(dont_try_this, Quaternion(), 0.1, 2 * 0.1, { 0, 0, 1, 1 }, 10.000f, false, true);
					if (i != 29) continue;
				}
				cur_next_pos = next_head_outRay.m_Point;
				//DDraw::Capsule(cur_next_pos, Quaternion(), 0.1, 2 * 0.1, { 1, 1, 1, 1 }, 10.000f, false, true);
				cur_next_pos += Vector3(0, dist_to_head, 0);
				break;
			}
		}
		if (targetpos.y > cur_next_pos.y) {
			if (targetpos.y - cur_next_pos.y > 5) {
				if (LineOfSight(targetpos, cur_next_pos, true))
					actualtargetposition = cur_next_pos;
			}
		}
		else {
			if (cur_next_pos.y - targetpos.y > 5) {
				if (LineOfSight(targetpos, cur_next_pos, true))
					actualtargetposition = cur_next_pos;
			}
		}
	}

	{
		bool hightqwality = false;
		targetPosition = actualtargetposition;
		for (int simulations = 1; simulations <= 15; simulations++) {
			bool hitPlayers = false;
			Vector3 _aimdirection = AimConeUtil::GetModifiedAimConeDirection(0.f, targetPosition - localPosition, false);
			Vector3 velocity = _aimdirection * projectileVelocitymenu * projectileVelocityScale;
			auto currentPosition = localPosition;
			Vector3 previousPosition = currentPosition;
			Vector3 offset = Vector3().Zero();

			Vector3 closestPoint(100000000, 100000000, 100000000);
			for (int i = -1; i < ((int)(8.f / deltaTime)); i++)
			{
				previousPosition = currentPosition;
				currentPosition += velocity * deltaTime;
				velocity += gravity * gravityModifier * deltaTime;
				velocity -= velocity * drag * deltaTime;

				if (!hightqwality) {
					Line updateLine = Line(previousPosition, currentPosition);
					Vector3 closestUpdateToPlayer = updateLine.ClosestPoint(actualtargetposition);
					float distanceToPlayer = closestUpdateToPlayer.Distance(actualtargetposition);
					if (eyepos.Distance2D(actualtargetposition) <= eyepos.Distance2D(closestUpdateToPlayer))
					{
						if (actualtargetposition.y - previousPosition.y > 0)
							offset += Vector3(0, actualtargetposition.y - previousPosition.y, 0);
						else hightqwality = true;
						break;
					}
				}
				else {
					auto line = (currentPosition - previousPosition); auto len = line.UnityMagnitude(); line.UnityNormalize();
					auto v = actualtargetposition - previousPosition; auto d = Vector3().UnityDot(v, line);

					if (d < 0.f) d = 0.f;
					else if (d > len) d = len;

					Vector3 nearestPoint = previousPosition + line * d;
					if (nearestPoint.Distance(actualtargetposition) < 0.01f)
					{
						hitPlayers = true;
						break;
					}
					else if (nearestPoint.Distance(actualtargetposition) < closestPoint.Distance(actualtargetposition))
					{
						closestPoint = nearestPoint;
						offset = actualtargetposition - nearestPoint;
					}
				}
			}

			if (hitPlayers) break;
			else if (simulations == 15) return Vector3::Zero();
			targetPosition += offset;
		}
	}
	if (checkLOS) {
		Vector3 _aimdirection = AimConeUtil::GetModifiedAimConeDirection(0.f, targetPosition - localPosition, false);
		Vector3 velocity = _aimdirection * projectileVelocitymenu * projectileVelocityScale;

		auto currentPosition = localPosition; Vector3 previousPosition = currentPosition;

		for (int i = -1; i < ((int)(8.f / deltaTime)); i++)
		{
			previousPosition = currentPosition;
			currentPosition += velocity * deltaTime;
			velocity += gravity * gravityModifier * deltaTime;
			velocity -= velocity * drag * deltaTime;

			Line updateLine = Line(previousPosition, currentPosition);
			Vector3 closestUpdateToPlayer = updateLine.ClosestPoint(actualtargetposition);
			float distanceToPlayer = closestUpdateToPlayer.Distance(actualtargetposition);
			
			if (!LineOfSight(previousPosition, currentPosition) || !LineOfSight(currentPosition, previousPosition)) {
				if (distanceToPlayer >= 0.01f)
					return Vector3::Zero();
			}
			
			
			if (distanceToPlayer < 0.01f || currentPosition.Distance(eyepos) > actualtargetposition.Distance(eyepos)) break;
		}

	}

	return targetPosition;
}

Vector3 Meleepredict(Vector3 eyepos, Vector3 targetpos,bool checkLOS = false) {
	if (target_player == nullptr) return Vector3::Zero();
	Vector3 actualtargetposition = targetpos;
	auto itemmodproj = ((Networkable*)local_player->active_weapon()->info_item())->GetComponent(il2cpp::type_object(_(""), _("ItemModProjectile")));

	auto projectileObject = u_mem::read<uintptr_t>((uintptr_t)itemmodproj + values::ItemModProjectile::projectileObject);
	if (!projectileObject) return Vector3::Zero();
	UINT_PTR projectileType = (UINT_PTR)il2cpp::type_object(_(""), _("Projectile"));
	if (!projectileType) return Vector3::Zero();
	Type* projectileClass = (Type*)GetClassObject(projectileObject); 
	if (!projectileClass) return Vector3::Zero();
	Projectile* projectile = (Projectile*)GameObject::GetGameObjectComponent(projectileType, (UINT_PTR)projectileClass);

	if (projectile == nullptr) return Vector3::Zero();
	bool mounted = target_player->isMounted();
	float drag = projectile->drag(); float gravityModifier = projectile->gravityModifier(); auto gravity = Physics::gravity();
	auto get_fixedDeltaTime = Time::fixedDeltaTime(); auto get_timeScale = Time::timeScale(); float deltaTime = get_fixedDeltaTime * get_timeScale;
	Vector3 localPosition = eyepos; Vector3 targetPosition = actualtargetposition;
	Vector3 playerVelocity = Vector3(target_player->GetVelocity().x, 0, target_player->GetVelocity().z)/* * 0.75f*/;
	if (mounted) {
		playerVelocity = Vector3(target_player->GetWorldVelocity().x, target_player->GetWorldVelocity().y, target_player->GetWorldVelocity().z)/* * 0.75f*/;
	}
	float bulletTime;
	{
		bool hightqwality = false;
		for (int simulations = 1; simulations <= 15; simulations++) {
			bool hitPlayers = false;
			Vector3 _aimdirection = AimConeUtil::GetModifiedAimConeDirection(0.f, targetPosition - localPosition, false);
			Vector3 velocity = _aimdirection * ((ItemModProjectile*)itemmodproj)->projectileVelocity();
			auto currentPosition = localPosition;
			Vector3 previousPosition = currentPosition;
			Vector3 offset = Vector3().Zero();

			Vector3 closestPoint(100000000, 100000000, 100000000);
			for (int i = -1; i < ((int)(8.f / deltaTime)); i++)
			{
				previousPosition = currentPosition;
				currentPosition += velocity * deltaTime;
				velocity += gravity * gravityModifier * deltaTime;
				velocity -= velocity * drag * deltaTime;
				//DDraw::Line(previousPosition, currentPosition, { 1,1,1,1 }, 0.001f, false, true);
				if (!hightqwality) {
					Line updateLine = Line(previousPosition, currentPosition);
					Vector3 closestUpdateToPlayer = updateLine.ClosestPoint(actualtargetposition);
					float distanceToPlayer = closestUpdateToPlayer.Distance(actualtargetposition);
					if (eyepos.Distance2D(actualtargetposition) <= eyepos.Distance2D(closestUpdateToPlayer))
					{
						if (actualtargetposition.y - previousPosition.y > 0)
							offset += Vector3(0, actualtargetposition.y - previousPosition.y, 0);
						else hightqwality = true;
						break;
					}
				}
				else {
					auto line = (currentPosition - previousPosition); auto len = line.UnityMagnitude(); line.UnityNormalize();
					auto v = actualtargetposition - previousPosition; auto d = Vector3().UnityDot(v, line);

					if (d < 0.f) d = 0.f;
					else if (d > len) d = len;

					Vector3 nearestPoint = previousPosition + line * d;
					if (nearestPoint.Distance(actualtargetposition) < 0.01f)
					{
						bulletTime = i * deltaTime;
						hitPlayers = true;
						break;
					}
					else if (nearestPoint.Distance(actualtargetposition) < closestPoint.Distance(actualtargetposition))
					{
						closestPoint = nearestPoint;
						offset = actualtargetposition - nearestPoint;
						//DDraw::Capsule(closestPoint, Quaternion(), 0.1, 2 * 0.1, { 0, 1, 0, 1 }, 3.000f, false, true);
					}
				}
			}

			if (hitPlayers) break;
			else if (simulations == 15) return Vector3::Zero();
			targetPosition += offset;
		}
	}
	actualtargetposition += playerVelocity * (bulletTime - (2 * 0.03125f));

	if (!mounted) {
		Vector3 head_pos = targetpos; RaycastHit head_outRay;
		auto CheckayCast = rc<bool(*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(g_base + CO::RaycastHit);
		Vector3 head_down_pos; float dist_to_head;
		if (CheckayCast(head_pos, Vector3(0, -1, 0), &head_outRay, 1000.f, 256 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
		{
			head_down_pos = head_outRay.m_Point;
			dist_to_head = head_down_pos.Distance(head_pos);
		}
		float dist_to_next = targetpos.Distance(actualtargetposition);
		Vector3 cur_next_pos;
		Vector3 dont_try_this = actualtargetposition;
		for (int i = 1; i < 30; i++) {
			RaycastHit next_head_outRay;
			if (CheckayCast(dont_try_this + Vector3(0, 100, 0), Vector3(0, -1, 0), &next_head_outRay, 1000.f, 256 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
			{
				if (targetpos.Distance(next_head_outRay.m_Point) > dist_to_next + 0.05f) {
					dont_try_this = MoveTowards(dont_try_this, targetpos, 0.025f);
					//DDraw::Capsule(dont_try_this, Quaternion(), 0.1, 2 * 0.1, { 0, 1, 0, 1 }, 10.000f, false, true);
					if (i != 29) continue;
				}
				if (targetpos.Distance(next_head_outRay.m_Point) < dist_to_next - 0.05f) {
					dont_try_this = MoveTowards(dont_try_this, actualtargetposition, 0.025f);
					//DDraw::Capsule(dont_try_this, Quaternion(), 0.1, 2 * 0.1, { 0, 0, 1, 1 }, 10.000f, false, true);
					if (i != 29) continue;
				}
				cur_next_pos = next_head_outRay.m_Point;
				//DDraw::Capsule(cur_next_pos, Quaternion(), 0.1, 2 * 0.1, { 1, 1, 1, 1 }, 10.000f, false, true);
				cur_next_pos += Vector3(0, dist_to_head, 0);
				break;
			}
		}
		if (targetpos.y > cur_next_pos.y) {
			if (targetpos.y - cur_next_pos.y > 5) {
				if (LineOfSight(targetpos, cur_next_pos, true))
					actualtargetposition = cur_next_pos;
			}
		}
		else {
			if (cur_next_pos.y - targetpos.y > 5) {
				if (LineOfSight(targetpos, cur_next_pos, true))
					actualtargetposition = cur_next_pos;
			}
		}
	}

	{
		targetPosition = actualtargetposition;
		bool hightqwality = false;
		for (int simulations = 1; simulations <= 15; simulations++) {
			bool hitPlayers = false;
			Vector3 _aimdirection = AimConeUtil::GetModifiedAimConeDirection(0.f, targetPosition - localPosition, false);
			Vector3 velocity = _aimdirection * ((ItemModProjectile*)itemmodproj)->projectileVelocity();
			auto currentPosition = localPosition;
			Vector3 previousPosition = currentPosition;
			Vector3 offset = Vector3().Zero();

			Vector3 closestPoint(100000000, 100000000, 100000000);
			for (int i = -1; i < ((int)(8.f / deltaTime)); i++)
			{
				previousPosition = currentPosition;
				currentPosition += velocity * deltaTime;
				velocity += gravity * gravityModifier * deltaTime;
				velocity -= velocity * drag * deltaTime;
				//DDraw::Line(previousPosition, currentPosition, { 1,1,1,1 }, 0.001f, false, true);
				if (!hightqwality) {
					Line updateLine = Line(previousPosition, currentPosition);
					Vector3 closestUpdateToPlayer = updateLine.ClosestPoint(actualtargetposition);
					float distanceToPlayer = closestUpdateToPlayer.Distance(actualtargetposition);
					if (eyepos.Distance2D(actualtargetposition) <= eyepos.Distance2D(closestUpdateToPlayer))
					{
						if (actualtargetposition.y - previousPosition.y > 0)
							offset += Vector3(0, actualtargetposition.y - previousPosition.y, 0);
						else hightqwality = true;
						break;
					}
				}
				else {
					auto line = (currentPosition - previousPosition); auto len = line.UnityMagnitude(); line.UnityNormalize();
					auto v = actualtargetposition - previousPosition; auto d = Vector3().UnityDot(v, line);

					if (d < 0.f) d = 0.f;
					else if (d > len) d = len;

					Vector3 nearestPoint = previousPosition + line * d;
					if (nearestPoint.Distance(actualtargetposition) < 0.01f)
					{
						hitPlayers = true;
						break;
					}
					else if (nearestPoint.Distance(actualtargetposition) < closestPoint.Distance(actualtargetposition))
					{
						closestPoint = nearestPoint;
						offset = actualtargetposition - nearestPoint;
						//DDraw::Capsule(closestPoint, Quaternion(), 0.1, 2 * 0.1, { 0, 1, 0, 1 }, 3.000f, false, true);
					}
				}
			}

			if (hitPlayers) break;
			else if (simulations == 15) return Vector3::Zero();
			targetPosition += offset;
		}
	}
	if (checkLOS) {
		Vector3 _aimdirection = AimConeUtil::GetModifiedAimConeDirection(0.f, targetPosition - localPosition, false);
		Vector3 velocity = _aimdirection * ((ItemModProjectile*)itemmodproj)->projectileVelocity();

		auto currentPosition = localPosition;
		Vector3 previousPosition = currentPosition;

		for (int i = -1; i < ((int)(8.f / deltaTime)); i++)
		{
			previousPosition = currentPosition;
			currentPosition += velocity * deltaTime;
			velocity += gravity * gravityModifier * deltaTime;
			velocity -= velocity * drag * deltaTime;

			Line updateLine = Line(previousPosition, currentPosition);
			Vector3 closestUpdateToPlayer = updateLine.ClosestPoint(actualtargetposition);
			float distanceToPlayer = closestUpdateToPlayer.Distance(actualtargetposition);

			if (!LineOfSight(previousPosition, currentPosition) || !LineOfSight(currentPosition, previousPosition)) {
				if (distanceToPlayer >= 0.01f)
					return Vector3::Zero();
			}


			if (distanceToPlayer < 0.01f || currentPosition.Distance(eyepos) > actualtargetposition.Distance(eyepos)) break;
		}

	}
	return targetPosition;
}