void hkWriteToStream(ProjectileShoot* _This, Stream* Stream)
{
	if (local_player)
	{
		auto weapon = local_player->active_weapon();
		auto baseprojectile = local_player->active_entity<BaseProjectile>();
		if (!weapon || !baseprojectile) return ProjectileShoot::WriteToStream_(_This, Stream);
		auto classname = baseprojectile->get_class_name();
		if (!classname) return ProjectileShoot::WriteToStream_(_This, Stream);
		if (u_crt::m_strcmp(classname, _("BaseProjectile")) || u_crt::m_strcmp(classname, _("BowWeapon")) || u_crt::m_strcmp(classname, _("CompoundBowWeapon")) ||
			u_crt::m_strcmp(classname, _("BaseLauncher")) || u_crt::m_strcmp(classname, _("CrossbowWeapon")) || u_crt::m_strcmp(classname, _("FlintStrikeWeapon"))
			|| u_crt::m_strcmp(classname, _("SnowballGun")) || u_crt::m_strcmp(classname, _("SpinUpWeapon")))
		{
			uintptr_t projectile_list = *rc<uintptr_t*>(*rc<uintptr_t*>((uintptr_t)baseprojectile + values::BaseProjectile::createdProjectiles) + 0x10);
			if (!projectile_list) return ProjectileShoot::WriteToStream_(_This, Stream);
			uintptr_t shoot_list = *(uintptr_t*)(*(uintptr_t*)(_This + 0x18) + 0x10);
			if (!shoot_list) return ProjectileShoot::WriteToStream_(_This, Stream);
			auto size = *(int*)(*(uintptr_t*)(_This + 0x18) + 0x18);
			if (!size) return ProjectileShoot::WriteToStream_(_This, Stream);
			for (int i = 0; i < size; i++) {
				uintptr_t projectile = u_mem::read<uintptr_t>(shoot_list + (0x20 + (i * 0x8)));
				auto projectilezxc = *(Projectile**)((uintptr_t)projectile_list + 0x20 + i * 0x8);

				if (vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey) && target_player) {
					Vector3 targetpos = target_player->GetTransform(target_bone)->position();
					if (BulletPos != Vector3::Zero()) targetpos = BulletPos;

					if (vars::manipulator::m_manipulate != Vector3::Zero())
						projectile_eyepos = vars::manipulator::m_manipulate;
					else
						projectile_eyepos = local_player->eyes()->position();
					Vector3 startVel = u_mem::read<Vector3>(projectile + 0x20);


					projectile_velocity = (Basepredict(projectile_eyepos, targetpos) - projectile_eyepos).Normalized() * startVel.Length();
					*rc<Vector3*>(projectile + 0x14) = projectile_eyepos;
				}
				else if (vars::weapon::nospread) {
					auto baseprojectile = local_player->active_entity<BaseProjectile>();
					auto projectileVelocitymenu = projectilezxc->mod()->projectileVelocity();
					auto projectileVelocityScale = baseprojectile->GetProjectileVelocityScale(false);
					Vector3 vector = AimConeUtil::GetModifiedAimConeDirection(0.f, local_player->eyes()->rotation() * Vector3(0.f, 0.f, 1.f), false);
					Vector3 vector2 = vector * (projectileVelocitymenu * projectileVelocityScale);
					projectile_velocity = vector2;
				}
				if ((vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey) && target_player) || vars::weapon::nospread) {
					*rc<Vector3*>(projectile + 0x20) = projectile_velocity;

					if (projectile_velocity != Vector3::Zero() && projectile_eyepos != Vector3::Zero())
						projectilezxc->currentVelocity(projectile_velocity);
					if (target_player && vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey)) {
						projectilezxc->transform()->position(projectile_eyepos);
						projectilezxc->currentPosition(projectile_eyepos);
					}
				}

				//if (projectile->traveledTime() == 0) {
				//	if ((target_player && vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey)) || vars::weapon::nospread) {
				//		if (projectile_velocity != Vector3::Zero() && projectile_eyepos != Vector3::Zero())
				//			projectile->currentVelocity(projectile_velocity);
				//		if (target_player && vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey)) {
				//			projectile->transform()->position(projectile_eyepos);
				//			projectile->currentPosition(projectile_eyepos);
				//		}
				//	}
				//	//initialPosition[projectile->projectileID()] = projectile->currentPosition();
				//}
			}
			for (int i = 0; i < ((BaseProjectile*)projectile_list)->size(); i++) {
				auto projectile = *(Projectile**)((uintptr_t)projectile_list + 0x20 + i * 0x8);
				if (!projectile) continue;
				if (vars::weapon::thick_bullet)
					projectile->thickness(vars::weapon::bullet_hitbox_size);
				else
					projectile->thickness(0.1f);
				if (vars::weapon::bullet_resize) {
					projectile->transform()->scale({ vars::weapon::bullet_size, vars::weapon::bullet_size, vars::weapon::bullet_size });
				}

			}
			did_reload = false;
			just_shot = true;
			baseprojectile->createdProjectiles()->clear();
		}
		else if (u_crt::m_strcmp(classname, _("BaseMelee")))
		{
			uintptr_t shoot_list = *(uintptr_t*)(*(uintptr_t*)(_This + 0x18) + 0x10);
			if (!shoot_list) return ProjectileShoot::WriteToStream_(_This, Stream);
			auto size = *(int*)(*(uintptr_t*)(_This + 0x18) + 0x18);
			if (!size) return ProjectileShoot::WriteToStream_(_This, Stream);
			for (int i = 0; i < size; i++) {
				if (target_player && vars::psilent::psilent && Input::GetKey(vars::psilent::psilentkey)) {
					Vector3 targetpos = target_player->GetTransform(target_bone)->position();
					if (BulletPos != Vector3::Zero()) targetpos = BulletPos;
					if (vars::manipulator::m_manipulate != Vector3::Zero())
						projectile_eyepos = vars::manipulator::m_manipulate;
					else
						projectile_eyepos = local_player->eyes()->position();
					uintptr_t projectile = u_mem::read<uintptr_t>(shoot_list + (0x20 + (i * 0x8)));
					Vector3 rpc_position = u_mem::read<Vector3>(projectile + 0x14); // public Vec3 startPos;
					Vector3 original_vel = u_mem::read<Vector3>(projectile + 0x20); // public Vec3 startVel;

					projectile_velocity = (Meleepredict(projectile_eyepos, targetpos) - projectile_eyepos).Normalized() * original_vel.Length();
					*rc<Vector3*>(projectile + 0x20) = projectile_velocity;
					*rc<Vector3*>(projectile + 0x14) = projectile_eyepos;
				}
				else if (vars::weapon::nospread) {
					projectile_velocity = Vector3::Zero();
				}
			}
		}

	}
	return ProjectileShoot::WriteToStream_(_This, Stream);
}