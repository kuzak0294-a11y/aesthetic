

void DrawCircle(Vector3 center, float radius)
{
	Color color = Color(97, 97, 189, 255);
	const int numSegments = 20;
	const float angleIncrement = 2.0f * static_cast<float>(M_PI) / static_cast<float>(numSegments);

	//if (visible) color = Color(1, 1, 1, 1);
	//else color = Color(77, 0, 0, 77);

	for (int i = 0; i < numSegments; ++i)
	{
		float angle = angleIncrement * static_cast<float>(i);
		float x = center.x + radius * Mathf::Cos(angle);
		float z = center.z + radius * Mathf::Sin(angle);

		angle += angleIncrement;
		float x1 = center.x + radius * Mathf::Cos(angle);
		float z1 = center.z + radius * Mathf::Sin(angle);

		DDraw::Line(Vector3(x, center.y, z), Vector3(x1, center.y, z1), color, 0.01f, false, true);
	}
}
const float NoClipMargin = 0.21f;
const float NoClipRadius = 0.5f - NoClipMargin;
bool TestNoClippingNew(Vector3 oldPos, Vector3 newPos, float radius, float backtracking, bool sphereCast, Collider*& collider, bool vehicleLayer, BaseEntity* ignoreEntity)
{
	const int num = vehicleLayer ? 1537286401 : (1537286401 & -8193);

	Vector3 normalized = (newPos - oldPos).UnityNormalizeVec3();
	Vector3 vector = oldPos - normalized * backtracking;
	float magnitude = (newPos - vector).UnityMagnitude();
	Ray ray(vector, normalized);
	RaycastHit hitInfo;

	if ((ignoreEntity == nullptr && Physics::Raycast(ray, hitInfo, magnitude + radius, num, QueryTriggerInteraction::Ignore))
		|| (ignoreEntity != nullptr && GamePhysics::Trace(ray, 0.f, hitInfo, magnitude + radius, num, QueryTriggerInteraction::Ignore, ignoreEntity)))
	{
		collider = (Collider*)hitInfo.m_Collider;
		return true;
	}

	if (sphereCast && GamePhysics::Trace(ray, radius, hitInfo, magnitude, num, QueryTriggerInteraction::Ignore, ignoreEntity))
	{
		collider = (Collider*)hitInfo.m_Collider;
		return true;
	}

	return false;
}

bool ValidateEyePos(Vector3 eyePos, Vector3 realEye, float num7, float num10)
{
	bool flag = true;

	float num8 = realEye.Distance(eyePos);
	float num11 = Mathf::Abs(realEye.y - eyePos.y);

	if (num8 > num7 || num11 > num10) return false;


	Collider* collider;

	float num16 = realEye.Distance(eyePos);
	if ((num16 > 0.06f && TestNoClippingNew(realEye, eyePos, NoClipRadius, 0.01f, true, collider, false, nullptr)) ||
		num16 > 0.01f && TestNoClippingNew(realEye, eyePos, 0.01f, 0.01f, true, collider, false, nullptr))
		return false;

	return flag;
}

bool CalculateValidHitS_pos(Vector3 eye)
{
	float radius_ = 2.60f;
	Vector3 targetheadpos = target_player->playerModel()->position() + Vector3(0, 1.2, 0);
	if (BulletPos.Distance(targetheadpos) > 2.7f) BulletPos = Vector3::Zero();
	for (int i = 0; i < (int)vars::bulletteleport::maxangle; ++i)
	{
		float theta = static_cast<float>(math::rand()) / static_cast<float>(0x7fff) * 2 * M_PI;
		float phi = static_cast<float>(math::rand()) / static_cast<float>(0x7fff) * M_PI;

		float x = radius_ * Mathf::Sin(phi) * Mathf::Cos(theta);
		float y = radius_ * Mathf::Sin(phi) * Mathf::Sin(theta);
		float z = radius_ * Mathf::Cos(phi);

		Vector3 point = targetheadpos + Vector3(x, y, z);
		if (vars::weapon::sphere_hitscan1) {
		DDraw::Capsule(point, Quaternion(), 0.1, 2 * 0.1, { 1, 1, 1, 1 }, 0.001f, false, true);
		}
		if (!LineOfSight(targetheadpos, point) || !LineOfSight(point, targetheadpos)) continue;
		if (!LineOfSight(eye, point) || !LineOfSight(point, eye)) continue;
		BulletPos = point;

		return true;
	}

	return false;
}



bool CalculateValidHitS_pos1(Vector3 eye)
{
	float radius_ = 1.f;
	Vector3 targetheadpos = target_player->playerModel()->position() + Vector3(0, 1.2, 0);
	if (BulletPos.Distance(targetheadpos) > 1.f) BulletPos = Vector3::Zero();
	for (int i = 0; i < (int)vars::bulletteleport::maxangle; ++i)
	{
		float theta = static_cast<float>(math::rand()) / static_cast<float>(0x7fff) * 2 * M_PI;
		float phi = static_cast<float>(math::rand()) / static_cast<float>(0x7fff) * M_PI;

		float x = radius_ * Mathf::Sin(phi) * Mathf::Cos(theta);
		float y = radius_ * Mathf::Sin(phi) * Mathf::Sin(theta);
		float z = radius_ * Mathf::Cos(phi);

		Vector3 point = targetheadpos + Vector3(x, y, z);
		if (vars::weapon::sphere_hitscan) {
		DDraw::Capsule(point, Quaternion(), 0.1, 2 * 0.1, { 1, 1, 1, 1 }, 0.001f, false, true);
		}
		if (!LineOfSight(targetheadpos, point) || !LineOfSight(point, targetheadpos)) continue;
		if (!LineOfSight(eye, point) || !LineOfSight(point, eye)) continue;
		BulletPos = point;

		return true;
	}

	return false;
}

float maxmanipulator = 8.0f;
void validatemanipulatorpos()
{
	Vector3 realEye = local_player->GetNetworkEyePosition();

	float num = 1.f + 0.5f;
	float eye_clientframes = 2.f;
	float eye_serverframes = 2.f;
	float num2 = eye_clientframes / 60.f;
	float num3 = eye_serverframes * Mathx::Max(Time::deltaTime(), Time::smoothDeltaTime(), Time::fixedDeltaTime());
	float num4 = (vars::manipulator::desync + num2 + num3) * num;
	float num5 = estimatedVelocity.Magnitude() + local_player->GetParentVelocity().Magnitude();
	float num6 = /*(local_player->HasParent() || local_player->isMounted()) ? 2.f :*/ 0.f;
	float num7 = local_player->BoundsPadding() + num4 * num5 + num6; //eye_distance //eye_distance (max 8m)

	float num9 = Mathf::Abs(local_player->GetMountVelocity().y + local_player->GetParentVelocity().y);
	float num10 = local_player->BoundsPadding() + num4 * num9 + local_player->GetJumpHeight(); //eye_altitude

	float min_y = min(num7, num10);


	DrawCircle(local_player->GetBoneByID(penis), num7);
	//float num10 = 5.5 + local_player->GetParentVelocity().Magnitude() + local_player->GetMountVelocity().Magnitude();
	//float num11 = local_player->BoundsPadding() + num4 * num10 + 0.125f;
	//DDraw::Capsule(local_player->lastSentTick()->position(), Quaternion(), 1.0, 2 * 0.1, {0, 1, 1, 1}, 0.05f, false, true);
	// Устанавливаем минимальное значение для манипулятора
	if (maxmanipulator < 8.0f) maxmanipulator = 8.0f;

	for (int i = 0; i < (int)vars::manipulator::maxangle; ++i)
	{
		float theta = static_cast<float>(math::rand()) / static_cast<float>(0x7fff) * 2 * M_PI;
		float phi = static_cast<float>(math::rand()) / static_cast<float>(0x7fff) * M_PI;

		float x = num7 * Mathf::Sin(phi) * Mathf::Cos(theta);
		float y = min_y * Mathf::Sin(phi) * Mathf::Sin(theta);
		float z = num7 * Mathf::Cos(phi);

		Vector3 point = realEye + Vector3(x, y, z);
		if (!LineOfSight(realEye, point)) {
			RaycastHit outRay;

			Vector3 normalized = (point - realEye).UnityNormalizeVec3();
			Vector3 vector = realEye - normalized * 0.01f;

			auto CheckayCast = rc<bool(*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(g_base + CO::RaycastHit);
			if (CheckayCast(vector, normalized, &outRay, maxmanipulator, 256 | 2048 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
			{
				point = outRay.m_Point;
				point = MoveTowards(point, realEye, 0.4);
			}
		}
		//DDraw::Capsule(point, Quaternion(), 0.1, 2 * 0.1, { 1, 1, 0, 1 }, 0.05f, false, true);
		if (point == Vector3::Zero() || !ValidateEyePos(point, realEye, num7, num10)) continue;
		//DDraw::Capsule(point, Quaternion(), 0.1, 2 * 0.1, { 0, 1, 0, 1 }, 0.01f, false, true);
		if (LineOfSight(point, target_player->GetBoneByID(head))) {
			BulletPos = Vector3::Zero();
		}

		else if (vars::weapon::thick_bullet && vars::bulletteleport::hitscan1) {
			if (!CalculateValidHitS_pos1(point)) continue;
		}
		else if (vars::bulletteleport::tp_bullet && vars::bulletteleport::hitscan) {
			if (!CalculateValidHitS_pos(point)) continue;
		}
		else {
			BulletPos = Vector3::Zero();
			continue;
		}
		vars::manipulator::m_manipulate = point;

		//local_player->ClientTick();
		reLaunchProjectile(local_player->active_entity<BaseProjectile>());
		return;
	}
}


Vector3 lastPos__;
bool onlyonecheck;
void aimbot_manipulator() {
	double desyncTimeClamped = (Time::realtimeSinceStartup() - local_player->lastSentTickTime()) - 0.03125f;
	vars::manipulator::desync = desyncTimeClamped;

	const auto player_movement = local_player->movement();


	if (desyncTimeClamped < 0.025f) {
		if (onlyonecheck) {
			if (local_player->transform()->position() == local_player->lastSentTick()->position())
				estimatedVelocity = Vector3::Zero();
			else
				estimatedVelocity = player_movement->TargetMovement();
			//estimatedVelocity = (lastPos__ - local_player->transform()->position()) / Time::fixedDeltaTime();
			onlyonecheck = false;
		}
	}
	else {
		onlyonecheck = true;
	}
	if (vars::manipulator::manipulator && Input::GetKey(vars::manipulator::manipulatorkey) && vars::manipulator::stopo) {
		local_player->clientTickInterval(0.99f);
		auto LastSentTickPos = local_player->lastSentTick()->position();
		player_movement->TargetMovement(Vector3());
		player_movement->TeleportTo(Vector3(LastSentTickPos.x, LastSentTickPos.y - 0.001, LastSentTickPos.z), local_player);
		player_movement->body()->velocity(Vector3());
	}
	lastPos__ = local_player->transform()->position();
	if (vars::manipulator::manipulator && Input::GetKey(vars::manipulator::manipulatorkey) && !vars::manipulator::stopo) {
		local_player->clientTickInterval(0.70f);
	}
	else if (!vars::psilent::psilent || !Input::GetKey(vars::psilent::psilentkey)) {
		local_player->clientTickInterval(0.05f);
		return;
	}
	if (vars::weapon::instant_hit && Input::GetKey(vars::psilent::psilentkey)) {
		
	}
	if (vars::manipulator::manipulator && Input::GetKey(vars::manipulator::manipulatorkey)) {
		if (target_player != nullptr) {
			//if (vars::psilent::lags - 0.1 < local_player->lastSentTickTime())
			validatemanipulatorpos();
		}
	}
	else {

		vars::manipulator::m_manipulate = Vector3::Zero();
		local_player->clientTickInterval(0.05f);
		if (target_player != nullptr && local_player->eyes()) {
			// STW (Shoot Through Walls) - прострел через стены
			if (vars::weapon::stw_enabled && Input::GetKey(vars::weapon::stw_key)) {
				STW_Tick();
			}
			else if (LineOfSight(local_player->eyes()->position(), target_player->GetBoneByID(head)) && LineOfSight(local_player->eyes()->position(), target_player->GetBoneByID(head))) {
				BulletPos = Vector3::Zero();
				reLaunchProjectile(local_player->active_entity<BaseProjectile>());
			}
			else if (vars::weapon::thick_bullet && vars::bulletteleport::hitscan1) {
				if (CalculateValidHitS_pos1(local_player->eyes()->position())) {
					reLaunchProjectile(local_player->active_entity<BaseProjectile>());
				}
			}
			else if (vars::bulletteleport::tp_bullet && vars::bulletteleport::hitscan) {
				if (CalculateValidHitS_pos(local_player->eyes()->position())) {
					reLaunchProjectile(local_player->active_entity<BaseProjectile>());
				}
			}
		}
	}
	if (target_player == nullptr) {
		vars::manipulator::m_manipulate = Vector3::Zero();
		BulletPos = Vector3::Zero();
	}
}