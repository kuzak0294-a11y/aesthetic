#include "manipulator.h"
float GetEffectScale(Projectile* _This)
{
	if (_This->invisible()) return 0.f;
	if (_This->traveledDistance() < 8.f) return 0.f;
	return Vector3::InverseLerp(12.f, 20.f, _This->currentVelocity().UnityMagnitude());
}

void bullet_move(Projectile* _This)
{
	float delta_time = 0.03125f;
	Transform* transform = _This->transform();
	Vector3 previous_position = _This->previousPosition();
	if (_This->traveledTime() != 0.f)
		_This->previousPosition(_This->currentPosition());

	_This->currentPosition() = transform->position();
	if (_This->traveledTime() == 0.f) {
		_This->sentPosition(_This->previousPosition());
		_This->previousPosition(_This->currentPosition());
	}
	delta_time *= Time::timeScale();
	bool res = _This->_Movement(delta_time);
	if (!res)
	{
		_This->DoVelocityUpdate(delta_time);
	}
	transform->position(_This->currentPosition());
	transform->rotation(Vector4::QuaternionLookRotation(_This->currentVelocity(), { 0.f, 1.f, 0.f }));
	if (_This->integrity() <= 0.01f || _This->maxDistance() <= _This->traveledDistance() || _This->traveledTime() > 8.f)
		_This->Retire();
	else
	{
		_This->SetEffectScale(GetEffectScale(_This));
		_This->DoFlybySound();
	}
}

void reLaunch(Projectile* projectile)
{
	const float moveDeltaTime = 0.03125f;
	while (projectile->isAlive() && (projectile->traveledDistance() < projectile->initialDistance() || projectile->traveledTime() < 0.1f)) {
		bulletchecker(projectile);
		
		Vector3 nextBulletPos = projectile->currentPosition() + (projectile->currentVelocity() * Time::fixedDeltaTime());
		if ((vars::weapon::piercematerials &&
			LineOfSight(projectile->currentPosition(), nextBulletPos) && LineOfSight(nextBulletPos, projectile->currentPosition()))
			&& (!LineOfSight(projectile->currentPosition(), nextBulletPos, true || !LineOfSight(projectile->currentPosition(), nextBulletPos, true))))
		{
			bullet_move(projectile);
			continue;
		}
		projectile->UpdateVelocity(moveDeltaTime);
	}
	projectile->launchTime(Time::fixedTime() - projectile->traveledTime());

	//DDraw::Capsule(projectile->currentPosition(), Quaternion(), 0.2, 2 * 0.2, { 0, 1, 0, 1 }, 10.000f, false, true);

	if (!projectile->isAlive())
	{
		projectile->Retire();
	}
	else
	{
		projectile->SetEffectScale(1);
		projectile->DoFlybySound();
	}
}

void hkProjectileUpdate(Projectile* projectile) {
	if (!projectile->isAlive()) {
		return u_hooks::orig::hk_ProjectileUpdate(projectile);
	}
	if (projectile->owner() != local_player) {
		return u_hooks::orig::hk_ProjectileUpdate(projectile);
	}
	if (projectile->traveledTime() == 0) {
		if ((target_player && vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey)) || vars::weapon::nospread) {
			if (projectile_velocity != Vector3::Zero() && projectile_eyepos != Vector3::Zero())
				projectile->currentVelocity(projectile_velocity);
			if (target_player && vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey)) {
				projectile->transform()->position(projectile_eyepos);
				projectile->currentPosition(projectile_eyepos);
			}
		}
		//initialPosition[projectile->projectileID()] = projectile->currentPosition();
	}
	Vector3 nextBulletPos = projectile->currentPosition() + (projectile->currentVelocity() * Time::fixedDeltaTime());


	float num = Mathf::Clamp(projectile->traveledTime(), projectile->traveledTime(), 8.f);
	float num2 = 1.f + 0.5f;
	float num4 = Mathx::Decrement(projectile->launchTime() + 0.13f);
	float num5 = Mathf::Clamp(Mathx::Increment(Time::fixedTime()) - num4, 0.f, 8.f);
	float num6 = num;
	float num8 = min(num5, num6);
	float num9 = 2.f / 60.f;
	float num10 = 2.f * Mathx::Max(Time::deltaTime(), Time::smoothDeltaTime(), Time::fixedDeltaTime());
	float num11 = (vars::manipulator::desync + num8 + num9 + num10) * num2;
	float num12 = ((vars::manipulator::desync + num9 + num10) * num2);
	float num14 = local_player->eyes()->position().Distance(target_player->GetBoneByID(target_bone));
	//float num14 = initialPosition[projectile->projectileID()].Distance(projectile->currentPosition());
	float num21 = target_player->MaxVelocity() + target_player->GetParentVelocity().Magnitude();
	float num22 = num12 * num21;
	float magnitude2 = projectile->initialVelocity().Magnitude();
	float num23 =/* projectile->initialDistance() +*/ num11 * magnitude2;
	float num24 = projectile->traveledDistance() + 1.f + Vector3::Zero().Magnitude() + num22 + Vector3::Zero().Magnitude();
	float num25 = /*hitEntity.HasParent() ? 0.32f : */0.26f;
	float num26 = num14 * (1.f + num25);
	if (num14 > projectile->initialDistance() && num14 >= 25.f && num24 > num26)
	{
		return;
	}


	if ((projectile->traveledDistance() < projectile->initialDistance() || projectile->traveledTime() < 0.1f)) {
		reLaunch(projectile);
	}
	else
	{
		bulletchecker(projectile);

		if ((vars::weapon::piercematerials &&
			LineOfSight(projectile->currentPosition(), nextBulletPos) && LineOfSight(nextBulletPos, projectile->currentPosition()))
			&& (!LineOfSight(projectile->currentPosition(), nextBulletPos, true || !LineOfSight(projectile->currentPosition(), nextBulletPos, true))))
		{
			bullet_move(projectile);
			return;
		}


		return u_hooks::orig::hk_ProjectileUpdate(projectile);
	}
}