
void reLaunchProjectile(BaseProjectile* held)
{
	if (!local_player || local_player->active_weapon() == nullptr || !held || RPC_Counter.Calculate() > 100) return;
	if (local_player->is_dead() || local_player->is_sleeping() || local_player->is_wounded()) return;
	if (!Reload(held) || Time::time() < held->nextAttackTime() || local_player->active_weapon()->isBroken()) return;
	
	auto classname = held->get_class_name();
	if (!classname) return;
	Vector3 outputpredict_, projectile_eyepos_;
	if (vars::manipulator::m_manipulate != Vector3::Zero()) {
		projectile_eyepos_ = vars::manipulator::m_manipulate;
		//local_player->lastSentTick()->position(local_player->playerModel()->position());
		//auto SendClientTick = rc<void(*)(BasePlayer* target)>(g_base + 0x9717A0);
		//SendClientTick(local_player);
	}
	else
		projectile_eyepos_ = local_player->eyes()->position();
	Vector3 targetpos = target_player->GetTransform(target_bone)->position();
	if (BulletPos != Vector3::Zero()) targetpos = BulletPos;
	

	if (u_crt::m_strcmp(classname, _("BaseMelee")) || u_crt::m_strcmp(classname, _("Paddle")))
	{
		outputpredict_ = Meleepredict(projectile_eyepos_, targetpos, true);
		if (outputpredict_ == Vector3::Zero()) return;

		float nexttime = Time::time() - lastmeleeshottime;
		if (!u_crt::m_strcmp(classname, _("Jackhammer")) && !u_crt::m_strcmp(classname, _("Planner")) && !u_crt::m_strcmp(classname, _("Hammer"))) {
			if (nexttime >= 1) {
				lastmeleeshottime = Time::time();
				return ((BaseMelee*)held)->DoThrow();
			}
		}
	}
	if (u_crt::m_strcmp(classname, _("BaseProjectile")) || u_crt::m_strcmp(classname, _("BowWeapon")) || u_crt::m_strcmp(classname, _("CompoundBowWeapon")) ||
		u_crt::m_strcmp(classname, _("BaseLauncher")) || u_crt::m_strcmp(classname, _("CrossbowWeapon")) || u_crt::m_strcmp(classname, _("FlintStrikeWeapon")) || u_crt::m_strcmp(classname, _("SnowballGun"))
		|| u_crt::m_strcmp(classname, _("SpinUpWeapon")))
	{
		outputpredict_ = Basepredict(projectile_eyepos_, targetpos, true);
		if (outputpredict_ == Vector3::Zero()) return;

		if (held->fractionalReload() && held->primaryMagazine()->contents() < held->primaryMagazine()->capacity() &&
			time_since_last_shot > 0.2f && !did_reload)
			held->ServerRPC(_(L"Reload"));

		if (!validateshot(held)) return;
		auto m = held->repeatDelay() * 0.75f;
		int r = vars::manipulator::desync / m;
		if (vars::weapon::instakill && r > 1) {
			float NextShot = lastshottime + held->repeatDelay() + 0.2;
			if (Time::fixedTime() > NextShot) {
				for (int i = 0; i <= r; i++)
				{
					if (!validateshot(held)) continue;
					if (i >= 4) break;
					held->startshot(false);
					RPC_Counter.Increment();
				}
				lastshottime = Time::fixedTime();
				return;
			}
		}
		else {
			if (!validateshot(held)) return;
			lastshottime = Time::fixedTime();
			held->startshot(true);
			RPC_Counter.Increment();
		}
	}
	
}

float nextActionTime = 0, period = 1.4721f;
void hkDoAttack(BaseProjectile* held)
{
	if (vars::weapon::norecoil) {
		auto recoil = u_mem::read<uintptr_t>((uintptr_t)held + values::BaseProjectile::recoil);
		auto recoilNew = u_mem::read<uintptr_t>(recoil + 0x78); //public RecoilProperties newRecoilOverride;
		if (recoilNew) {
			u_mem::write<float>(recoilNew + 0x18, vars::weapon::norecoil_value_x / 33.3f);
			u_mem::write<float>(recoilNew + 0x1C, vars::weapon::norecoil_value_x / 33.3f);
			u_mem::write<float>(recoilNew + 0x20, -vars::weapon::norecoil_value_y / 33.3f);
			u_mem::write<float>(recoilNew + 0x24, -vars::weapon::norecoil_value_y / 33.3f);
		}
		else
		{
			u_mem::write<float>(recoil + 0x18, vars::weapon::norecoil_value_x / 33.3f);
			u_mem::write<float>(recoil + 0x1C, vars::weapon::norecoil_value_x / 33.3f);
			u_mem::write<float>(recoil + 0x20, -vars::weapon::norecoil_value_y / 33.3f);
			u_mem::write<float>(recoil + 0x24, -vars::weapon::norecoil_value_y / 33.3f);
		}
	}
	if (vars::weapon::automatic)
		u_mem::write<bool>((uintptr_t)held + values::BaseProjectile::automatic, true);
	if (vars::weapon::eokachance) {
		u_mem::write<bool>((uintptr_t)held + values::BowWeapon::attackReady, true);
		u_mem::write<bool>((uintptr_t)held + values::BowWeapon::wasAiming, true);
	}
	if (vars::weapon::no_sway) {
		u_mem::write<float>((uintptr_t)local_player + 0x9A4, 1.f);
		u_mem::write<float>((uintptr_t)held + values::BaseProjectile::aimSway, 0);
		u_mem::write<float>((uintptr_t)held + values::BaseProjectile::aimSwaySpeed, 0);
	}
	if (vars::weapon::changebulletspeed)
		u_mem::write<float>((uintptr_t)held + values::BaseProjectile::projectileVelocityScale, vars::weapon::bulletspeed);
	else
		u_mem::write<float>((uintptr_t)held + values::BaseProjectile::projectileVelocityScale, 1.f);

	u_hooks::orig::DoAttack((uintptr_t)held);
	

	if (vars::weapon::rapidfire && held && vars::weapon::rapidfire_speed > 1.0f) {
		float current_next_attack = u_mem::read<float>((uintptr_t)held + values::AttackEntity::nextAttackTime);
		float repeat_delay = u_mem::read<float>((uintptr_t)held + values::AttackEntity::repeatDelay);
		
		
		float time_reduction = repeat_delay - (repeat_delay / vars::weapon::rapidfire_speed);
		float modified_next_attack = current_next_attack - time_reduction;
		
		
		if (modified_next_attack < Time::time()) {
			modified_next_attack = Time::time();
		}
		u_mem::write<float>((uintptr_t)held + values::AttackEntity::nextAttackTime, modified_next_attack);
	}
}