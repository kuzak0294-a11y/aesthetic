#pragma once
float time_last_upgrade = 0.f;
static float Orig_ClothingMoveSpeedReduction = 0.f;
static bool HasGotOrig = false;
float start_a_ReloadTime;
float next_a_ReloadTime;
int fractionalInsertCounter; int fractionalReloadDesiredCount;
void Other()
{
	if (vars::misc::speedhack && Input::GetKey(vars::misc::speedhackkey)) {
		if (!HasGotOrig) {
			Orig_ClothingMoveSpeedReduction = local_player->clothingMoveSpeedReduction();
			HasGotOrig = true;
		}
		if (HasGotOrig)
			local_player->clothingMoveSpeedReduction(-vars::misc::speedhackspeed);
	}
	else {
		if (HasGotOrig)
			local_player->clothingMoveSpeedReduction(Orig_ClothingMoveSpeedReduction);
	}
	if (vars::misc::admin_mode) local_player->set_flag(4);
	if (vars::localplayer::doorspammer && RPC_Counter.Calculate() <= 5) {
		if (objects::closest_Door_see && objects::closest_Door_dist < 3) {
			objects::closest_Door->ServerRPC(_(L"RPC_KnockDoor"));
			RPC_Counter.Increment();
		}
	}
	/*if (vars::localplayer::silentstash && RPC_Counter.Calculate() <= 5) {
		if (objects::closest_Stash_see && objects::closest_Stash_dist < 3) {
			objects::closest_Stash->ServerRPC(_(L"RPC_OpenLoot"));
			RPC_Counter.Increment();
		}
	}*/
	/*if (vars::localplayer::keepinstantrevive && Input::GetKey(vars::localplayer::keepinstantrevive_key) && target_player != nullptr) {
		if (target_player->is_wounded() && local_player->eyes()->position().Distance(target_player->eyes()->position()) < 3.f) {
			u_sdk::ServerRPC((DWORD64)target_player, _(L"RPC_Assist"));
		}
	}
	if (vars::localplayer::keeptargetalive && Input::GetKey(vars::localplayer::keeptargetalive_key) && target_player != nullptr) {
		if (target_player->is_wounded() && local_player->eyes()->position().Distance(target_player->eyes()->position()) < 3.f) {
			u_sdk::ServerRPC((DWORD64)target_player, _(L"RPC_KeepAlive"));
		}
	}*/
	if (vars::localplayer::silentcollectiblet && RPC_Counter.Calculate() <= 5)
	{
		if (objects::closest_CollectibleEntity_see && objects::closest_CollectibleEntity_dist < 4.f) {
			objects::closest_CollectibleEntity->ServerRPC(_(L"Pickup"));
			RPC_Counter.Increment();
		}
	}

	if (vars::localplayer::silentturret && RPC_Counter.Calculate() <= 5) {
		if (objects::closest_turret_see && objects::closest_turret != 0)
		{
			if (objects::closest_turret_dist < 3) objects::closest_turret->ServerRPC(_(L"AddSelfAuthorize"));
			RPC_Counter.Increment();
		}
	}
	{
		float last_recycler = 0.f;
		if (vars::localplayer::stoprecycler && RPC_Counter.Calculate() <= 5 && Time::fixedTime() > last_recycler + 0.35f) {
			if (objects::closest_recycler_see && objects::closest_recycler != 0)
			{
				if (objects::closest_recycler_dist < 3) {
					objects::closest_recycler->ServerRPC(_(L"SVSwitch"));
					last_recycler = Time::fixedTime();
					RPC_Counter.Increment();
				}
			}
		}
	}
	if (vars::localplayer::auto_upgrade && RPC_Counter.Calculate() <= 5) {
		if (objects::closest_BuildingBlock_see && objects::closest_BuildingBlock_dist < 5.5f) {
			auto block = (BuildingBlock*)objects::closest_BuildingBlock;
			BuildingGrade::Enum upgrade_tier = (BuildingGrade::Enum)(vars::localplayer::upgrade + 1);
			if (block->grade() != upgrade_tier && !block->IsUpgradeBlocked()) {
				if (Time::fixedTime() > time_last_upgrade + 0.35f) {
					if ((int)upgrade_tier == 1) {
						if (block->CanAffordUpgrade(BuildingGrade::Enum::Wood, 0, local_player)
							&& block->CanChangeToGrade(BuildingGrade::Enum::Wood, 0, local_player))
						{
							block->UpgradeToGrade(BuildingGrade::Enum::Wood, 0, local_player);
							time_last_upgrade = Time::fixedTime();
							RPC_Counter.Increment();
						}
					}
					else if ((int)upgrade_tier == 2) {
						if (block->CanAffordUpgrade(BuildingGrade::Enum::Stone, 0, local_player)
							&& block->CanChangeToGrade(BuildingGrade::Enum::Stone, 0, local_player))
						{
							block->UpgradeToGrade(BuildingGrade::Enum::Stone, 0, local_player);
							time_last_upgrade = Time::fixedTime();
							RPC_Counter.Increment();
						}
					}
					else if ((int)upgrade_tier == 3) {
						if (block->CanAffordUpgrade(BuildingGrade::Enum::Metal, 0, local_player)
							&& block->CanChangeToGrade(BuildingGrade::Enum::Metal, 0, local_player))
						{
							block->UpgradeToGrade(BuildingGrade::Enum::Metal, 0, local_player);
							time_last_upgrade = Time::fixedTime();
							RPC_Counter.Increment();
						}
					}
					else if ((int)upgrade_tier == 4) {
						if (block->CanAffordUpgrade(BuildingGrade::Enum::TopTier, 0, local_player)
							&& block->CanChangeToGrade(BuildingGrade::Enum::TopTier, 0, local_player))
						{
							block->UpgradeToGrade(BuildingGrade::Enum::TopTier, 0, local_player);
							time_last_upgrade = Time::fixedTime();
							RPC_Counter.Increment();
						}
					}
				}
			}
		}
	}
	if (vars::localplayer::gesture_spam && RPC_Counter.Calculate() <= 5) {
		float last_gesture_rpc = 0.f;
		if (Time::fixedTime() > last_gesture_rpc + 0.35f)
		{
			switch (vars::localplayer::gesture) {
			case 0:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"clap"));
				break;
			case 1:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"friendly"));
				break;
			case 2:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"thumbsdown"));
				break;
			case 3:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"thumbsup"));
				break;
			case 4:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"ok"));
				break;
			case 5:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"point"));
				break;
			case 6:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"shrug"));
				break;
			case 7:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"victory"));
				break;
			case 8:
				local_player->SendSignalBroadcast(Signal::Gesture, _(L"wave"));
				break;
			}
			last_gesture_rpc = Time::fixedTime();
			RPC_Counter.Increment();
		}
	}

	if (vars::misc::raycast_sphere) {
		RaycastHit outRay;
		auto CheckayCast = rc<bool(*)(Vector3, Vector3, RaycastHit*, float, int, QueryTriggerInteraction)>(g_base + CO::RaycastHit);
		if (CheckayCast(MainCamera::Camera()->position(), MainCamera::Camera()->forward(), &outRay, 1000.f, 256 | 2048 | 65536 | 1073741824 | 8388608 | 2097152 | 4194304 | 67108864 | 134217728 | 33554432 | 32768 | 8192 | 512 | 1, QueryTriggerInteraction::Ignore))
		{
			DDraw::Capsule(outRay.m_Point, Quaternion(), pulsation(0.1, 0.5, 0.5), 2 * pulsation(0.1, 0.5, 0.5), {vars::misc::raycast_sphere_color.r / 255.f, vars::misc::raycast_sphere_color.g / 255.f, vars::misc::raycast_sphere_color.b / 255.f, vars::misc::raycast_sphere_color.a / 255.f }, 0.001f, false, true);
		}
	}
}
int iarr;
float send_time = Time::realtimeSinceStartup();
float last_refill_rpc = Time::realtimeSinceStartup();
BaseProjectile* last_weapon_after;
void WeaponSet()
{
	Other();
	auto active_weapon = local_player->active_weapon();
	auto baseprojectile = local_player->active_entity<BaseProjectile>();
	auto basemelee = local_player->active_entity<BaseMelee>();
	auto thrownweapon = local_player->active_entity<ThrownWeapon>();
	if (!active_weapon) {
		local_player->clientTickInterval(0.05f);
		vars::psilent::tarer_fov = vars::psilent::setter_fov;
		return;
	}
	/*if (last_weapon_after != baseprojectile) {
		last_weapon_after = baseprojectile;
		baseprojectile->StartAttackCooldown(baseprojectile->deployDelay() * 0.9f);
	}*/
	if (vars::psilent::show_fov) {
		auto CalculateCircleRadius = [&](float fov, float defaultRadius) {
			float fovRad = fov * (M_PI / 180.0f);
			float radius = defaultRadius / math::tan(fovRad / 2.0f);
			return radius;
			};
		vars::psilent::tarer_fov = CalculateCircleRadius(baseprojectile->GetFovOverride(), vars::psilent::setter_fov);
	}
	if (vars::localplayer::autoheal && RPC_Counter.Calculate() <= 5 && local_player->health() <= 95) {
		if (active_weapon->item_def_id() == 1079279582 || active_weapon->item_def_id() == -2072273936) {
			auto time = Time::realtimeSinceStartup();
			if (baseprojectile->timeSinceDeploy() > baseprojectile->deployDelay() && baseprojectile->nextAttackTime() <= time) {
				if (time > nextActionTime) {
					if (active_weapon->item_def_id() == 1079279582)
						nextActionTime = time + period;
					else if (active_weapon->item_def_id() == -2072273936)
						nextActionTime = time + (period * 2);
					baseprojectile->ServerRPC(_(L"UseSelf"));
					RPC_Counter.Increment();
				}
			}
		}
	}
	auto classname = baseprojectile->get_class_name();
	if (!classname) return;
	aimbot_manipulator();

	if (vars::weapon::hamerdraw && u_crt::m_strcmp(classname, _("Hammer"))) {
		Vector3 arr[81] = {
					local_player->transform()->position() + Vector3(1.0, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.9, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.8, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.7, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.6, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.5, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.4, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.3, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.2, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.1, 2.0, 0.0),
					local_player->transform()->position() + Vector3(0.0, 2.0, 0.0),

					local_player->transform()->position() + Vector3(0.0, 1.9, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.8, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.7, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.6, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.5, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.4, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.3, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.2, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.1, 0.0),
					local_player->transform()->position() + Vector3(0.0, 1.0, 0.0),


					local_player->transform()->position() + Vector3(0.0, 0.9, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.8, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.7, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.6, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.5, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.4, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.3, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.2, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.1, 0.0),
					local_player->transform()->position() + Vector3(0.0, 0.0, 0.0),

					local_player->transform()->position() + Vector3(-0.1, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.2, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.3, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.4, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.5, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.6, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.7, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.8, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-0.9, 0.0, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 0.0, 0.0),


					local_player->transform()->position() + Vector3(-0.1, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.2, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.3, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.4, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.5, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.6, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.7, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.8, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-0.9, 1.0, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.0, 0.0),

					local_player->transform()->position() + Vector3(-1.0, 1.1, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.2, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.3, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.4, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.5, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.6, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.7, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.8, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 1.9, 0.0),
					local_player->transform()->position() + Vector3(-1.0, 2.0, 0.0),


					local_player->transform()->position() + Vector3(0.1, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.2, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.3, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.4, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.5, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.6, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.7, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.8, 1.0, 0.0),
					local_player->transform()->position() + Vector3(0.9, 1.0, 0.0),
					local_player->transform()->position() + Vector3(1.0, 1.0, 0.0),

					local_player->transform()->position() + Vector3(1.0, 0.9, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.8, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.7, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.6, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.5, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.4, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.3, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.2, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.1, 0.0),
					local_player->transform()->position() + Vector3(1.0, 0.0, 0.0)
		};

		if (iarr > 81) iarr = 0;
		if (VerifyClientAttack(local_player, basemelee))
		{
			Vector3 hitpoint = arr[iarr];
			if (MeleePlayerAttack(basemelee, NULL, hitpoint)) {
				Vector3 origin = local_player->eyes()->position();
				Vector3 localDir = local_player->eyes()->bodyforward();
				localDir.y = 0.00f;

				HitTest* hit = HitTest::New();
				hit->HitEntity(NULL);
				hit->DidHit(true);
				hit->MaxDistance(basemelee->maxDistance());
				hit->HitTransform(nullptr);
				hit->AttackRay(Ray(hitpoint, Vector3::Zero()));
				hit->HitNormal(localDir);
				hit->HitPoint(hitpoint);
				hit->HitTest_HitMaterial((String*)il2cpp::methods::new_string(_("glass")));
				basemelee->ProcessAttack(hit);
				basemelee->StartAttackCooldown(0.01f);
			}
			iarr += 1;
		}
	}
	if (u_crt::m_strcmp(classname, _("BaseMelee")) || u_crt::m_strcmp(classname, _("Jackhammer"))) {
		if (vars::weapon::silent_melee) {
			if (vars::weapon::show_silent_radius)
				Show_Melee_Radius(basemelee);
			if (target_player) {
				if (MeleePlayerAttack(basemelee, target_player, target_player->GetBoneByID(head))) {
					HitTest* hit_test = HitTest::New();

					Transform* playerTransform = target_player->GetTransform(target_bone);

					if (playerTransform) {
						Ray ray = Ray(local_player->eyes()->position(), (playerTransform->position() - local_player->eyes()->position()).Normalized());

						hit_test->MaxDistance(basemelee->maxDistance());
						hit_test->HitTransform(playerTransform);
						hit_test->AttackRay(ray);
						hit_test->DidHit(true);
						hit_test->HitEntity(target_player);
						hit_test->HitPoint(playerTransform->InverseTransformPoint(target_player->GetBoneByID(head)));
						hit_test->HitNormal(Vector3(0, 0, 0));
						hit_test->damageProperties(baseprojectile->damageProperties());
						basemelee->StartAttackCooldown(baseprojectile->repeatDelay());
						basemelee->ProcessAttack(hit_test);
					}
				}
			}
		}

		if (vars::weapon::autofarmtree) {
			if (objects::closest_TreeEntity_see && objects::closest_TreeEntity_dist <= 3 && objects::closest_TreeEntity_dist < objects::closest_OreResourceEntity_dist)
			{
				if (objects::closest_TreeMarker_see && objects::closest_TreeMarker_dist <= 3)
				{
					auto entity = (uintptr_t)objects::closest_TreeMarker;
					auto object = u_mem::read<uintptr_t>(entity + 0x10);
					if (isvalid(object)) {
						auto classname = (char*)u_mem::read<DWORD64>(u_mem::read<DWORD64>(u_mem::read<DWORD64>(object + 0x28)) + 0x10);
						if (classname) {
							if (u_crt::m_strstr(classname, _("TreeMarker"))) {
								DoOreAttack(objects::closest_TreeMarker->transform()->position(), (BaseEntity*)objects::closest_TreeEntity, basemelee, true);
							}
							else {
								memory_client_entities_count = 0;
								objects::closest_TreeEntity_see = false;
							}
						}
						else {
							memory_client_entities_count = 0;
							objects::closest_TreeEntity_see = false;
						}
					}
					else {
						memory_client_entities_count = 0;
						objects::closest_TreeEntity_see = false;
					}
				}
				else {
					auto entity = (uintptr_t)objects::closest_TreeEntity;
					auto object = u_mem::read<uintptr_t>(entity + 0x10);
					if (isvalid(object)) {
						auto classname = (char*)u_mem::read<DWORD64>(u_mem::read<DWORD64>(u_mem::read<DWORD64>(object + 0x28)) + 0x10);
						if (classname) {
							if (u_crt::m_strstr(classname, _("TreeEntity"))) {
								Vector3 treepos = objects::closest_TreeEntity->transform()->position() + Vector3(0, 1, 0);
								for (int i = 0; i < 5; i++) {
									if (!LineOfSight(local_player->GetBoneByID(head), treepos)) {
										treepos = MoveTowards(treepos, local_player->GetBoneByID(head), 0.05f);
									}
									else break;
								}
								DoOreAttack(objects::closest_TreeEntity->transform()->position() + Vector3(0, 1, 0), (BaseEntity*)objects::closest_TreeEntity, basemelee, true);
							}
							else {
								memory_client_entities_count = 0;
								objects::closest_TreeEntity_see = false;
							}
						}
						else {
							memory_client_entities_count = 0;
							objects::closest_TreeEntity_see = false;
						}
					}
					else {
						memory_client_entities_count = 0;
						objects::closest_TreeEntity_see = false;
					}
				}
			}
		}
		if (vars::weapon::autofarmore) {
			if (objects::closest_OreResourceEntity_see && objects::closest_OreResourceEntity_dist <= 3 && objects::closest_OreResourceEntity_dist < objects::closest_TreeEntity_dist)
			{
				if (objects::closest_OreHotSpot_see && objects::closest_OreHotSpot_dist <= 3)
				{
					auto entity = (uintptr_t)objects::closest_OreHotSpot;
					auto object = u_mem::read<uintptr_t>(entity + 0x10);
					if (isvalid(object)) {
						auto classname = (char*)u_mem::read<DWORD64>(u_mem::read<DWORD64>(u_mem::read<DWORD64>(object + 0x28)) + 0x10);
						if (classname) {
							if (u_crt::m_strstr(classname, _("OreHotSpot"))) {
								DoOreAttack(objects::closest_OreHotSpot->transform()->position(), (BaseEntity*)objects::closest_OreResourceEntity, basemelee, false);
							}
							else {
								memory_client_entities_count = 0;
								objects::closest_OreResourceEntity_see = false;
							}
						}
						else {
							memory_client_entities_count = 0;
							objects::closest_OreResourceEntity_see = false;
						}
					}
					else {
						memory_client_entities_count = 0;
						objects::closest_OreResourceEntity_see = false;
					}
				}
			}
		}
	}
	if (vars::localplayer::autorefill && RPC_Counter.Calculate() <= 5) {
		if (u_crt::m_strcmp(classname, _("Jackhammer")) && last_refill_rpc + 0.3f < Time::fixedTime()) {
			BasePlayer::ItemCommand((unsigned int)active_weapon->uid(), _(L"refill"));
			last_refill_rpc = Time::fixedTime();
			RPC_Counter.Increment();
		}
	}
	if (u_crt::m_strcmp(classname, _("BaseMelee")) || u_crt::m_strcmp(classname, _("Paddle")) || u_crt::m_strcmp(classname, _("Jackhammer")) ||
		u_crt::m_strcmp(classname, _("Planner")) || u_crt::m_strcmp(classname, _("Hammer"))) return;
	{
		float current_time = Time::realtimeSinceStartup();
		if (vars::weapon::weaponspam && Input::GetKey(vars::weapon::weaponspam_key)) {
			float delay = vars::weapon::weaponspam_delay / 100;
			if (current_time - send_time > delay)
			{
				baseprojectile->SendSignalBroadcast(Signal::Attack, _(L""));
				send_time = current_time;
			}
		}
	}

	if (!u_crt::m_strcmp(classname, _("BaseProjectile")) && !u_crt::m_strcmp(classname, _("BowWeapon")) && !u_crt::m_strcmp(classname, _("CompoundBowWeapon")) &&
		!u_crt::m_strcmp(classname, _("BaseLauncher")) && !u_crt::m_strcmp(classname, _("CrossbowWeapon")) && !u_crt::m_strcmp(classname, _("FlintStrikeWeapon")) &&
		!u_crt::m_strcmp(classname, _("SnowballGun"))) return;

	if (vars::weapon::autoreload) {
		if (RPC_Counter.Calculate() <= 5 && baseprojectile->primaryMagazine()->CanReload(local_player)) {
			if (baseprojectile->fractionalReload()) {
				if (!did_reload) time_since_last_shot = (Time::fixedTime() - baseprojectile->lastShotTime());
				if (just_shot && (time_since_last_shot > 0.2f)) {

					baseprojectile->ServerRPC(_(L"StartReload"));
					baseprojectile->SendSignalBroadcast(Signal::Reload, _(L""));
					RPC_Counter.Increment();
					next_a_ReloadTime = baseprojectile->CalculateCooldownTime(next_a_ReloadTime, baseprojectile->GetReloadDuration(), false);
					start_a_ReloadTime = next_a_ReloadTime - baseprojectile->GetReloadDuration();
					fractionalReloadDesiredCount = min(baseprojectile->primaryMagazine()->capacity() - baseprojectile->primaryMagazine()->contents(), baseprojectile->GetAvailableAmmo());
					fractionalInsertCounter = 0;
					just_shot = false;
				}
				if (baseprojectile->primaryMagazine()->contents() < baseprojectile->primaryMagazine()->capacity()) {
					if (time_since_last_shot > 0.2f && !did_reload) {
						if (time_since_last_shot <= baseprojectile->GetReloadDuration()) {
							if (Time::time() >= start_a_ReloadTime + baseprojectile->reloadStartDuration()) {
								if (Time::time() >= start_a_ReloadTime + baseprojectile->reloadStartDuration() + (float)fractionalInsertCounter * baseprojectile->reloadFractionDuration()) {
									fractionalInsertCounter++;
									baseprojectile->ServerRPC(_(L"ServerFractionalReloadInsert"));
									RPC_Counter.Increment();
								}
							}
						}
					}
				}
				else {
					if (!did_reload && time_since_last_shot > baseprojectile->GetReloadDuration() && !just_shot)
					{
						if (Time::time() >= start_a_ReloadTime + baseprojectile->reloadStartDuration()) {
							if (Time::time() >= start_a_ReloadTime + baseprojectile->reloadStartDuration() + (float)fractionalInsertCounter * baseprojectile->reloadFractionDuration()) {

								baseprojectile->ServerRPC(_(L"Reload"));
								RPC_Counter.Increment();

								did_reload = true;
								time_since_last_shot = 0;
							}
						}
					}
				}
			}
			else {
				if (!did_reload) time_since_last_shot = (Time::fixedTime() - baseprojectile->lastShotTime());
				if (just_shot && (time_since_last_shot > 0.2f)) {

					baseprojectile->ServerRPC(_(L"StartReload"));
					baseprojectile->SendSignalBroadcast(Signal::Reload, _(L""));
					RPC_Counter.Increment();

					just_shot = false;
				}
				if (time_since_last_shot > baseprojectile->GetReloadDuration() + 0.3f && !did_reload && !just_shot) {

					baseprojectile->ServerRPC(_(L"Reload"));
					RPC_Counter.Increment();

					did_reload = true;
					time_since_last_shot = 0;
				}
			}
		}
	}
}

bool aspect = false;

bool _time; float _timeorig;
bool _starsc; float _stars_a_corig; float _stars_s_corig;
bool _skycolorc; Color _skycolor_day_corig; Color _skycolor_night_corig;
bool _brightcave; float _ambientmult; float _reflectmult;
void SkySet()
{
	//auto tod_sky_class = u_mem::read<uintptr_t>(g_base + CO::TOD_Sky_c);
	UINT64 klass = il2cpp::init_class(_("TOD_Sky"), _(""));
	auto fields = u_mem::read<uintptr_t>(klass + 0xB8);
	auto instances = u_mem::read<uintptr_t>(fields);
	auto tod_list = u_mem::read<uintptr_t>(instances + 0x10);
	auto tod_sky = u_mem::read<uintptr_t>(tod_list + 0x20);

	if (vars::misc::brightcave) {
		auto day_tod_sky = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Day);
		if (!_brightcave) {
			_ambientmult = u_mem::read<float>(day_tod_sky + 0x50);
			_reflectmult = u_mem::read<float>(day_tod_sky + 0x54);
			_brightcave = true;
		}
		u_mem::write<float>(day_tod_sky + 0x50, 1.f);
		u_mem::write<float>(day_tod_sky + 0x54, 1.f);
	}
	else if (_brightcave) {
		auto day_tod_sky = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Day);
		u_mem::write<float>(day_tod_sky + 0x50, _ambientmult);
		u_mem::write<float>(day_tod_sky + 0x54, _reflectmult);
	}

	if (vars::misc::sky_color_changer) {
		auto day_tod_sky = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Day);
		auto dsky_color = u_mem::read<uintptr_t>(day_tod_sky + 0x28);
		auto dsky_gradient = u_mem::read<uintptr_t>(dsky_color + 0x10);

		auto night_tod_sky = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Night);
		auto nsky_color = u_mem::read<uintptr_t>(night_tod_sky + 0x28);
		auto nsky_gradient = u_mem::read<uintptr_t>(nsky_color + 0x10);

		auto clr = Color(vars::misc::sky_color.r / 255.f, vars::misc::sky_color.g / 255.f, vars::misc::sky_color.b / 255.f, vars::misc::sky_color.a / 255.f );

		if (!_skycolorc) {
			_skycolor_day_corig = u_mem::read<Color>(dsky_gradient);
			_skycolor_night_corig = u_mem::read<Color>(nsky_gradient);
			_skycolorc = true;
		}
		u_mem::write<Color>(dsky_gradient, clr);
		u_mem::write<Color>(nsky_gradient, clr);
	}
	else if (_skycolorc) {
		auto day_tod_sky = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Day);
		auto dsky_color = u_mem::read<uintptr_t>(day_tod_sky + 0x28);
		auto dsky_gradient = u_mem::read<uintptr_t>(dsky_color + 0x10);

		auto night_tod_sky = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Night);
		auto nsky_color = u_mem::read<uintptr_t>(night_tod_sky + 0x28);
		auto nsky_gradient = u_mem::read<uintptr_t>(nsky_color + 0x10);

		u_mem::write<Color>(dsky_gradient, _skycolor_day_corig);
		u_mem::write<Color>(nsky_gradient, _skycolor_night_corig);
	}
	
	if (vars::misc::stars_changer) {
		auto stars = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Stars);
		if (!_starsc) {
			_stars_a_corig = u_mem::read<uintptr_t>(stars + 0x14);
			_stars_s_corig = u_mem::read<uintptr_t>(stars + 0x10);
			_starsc = true;
		}
		u_mem::write<float>(stars + 0x14, vars::misc::stars_amount);
		u_mem::write<float>(stars + 0x10, vars::misc::stars_size);
	}
	else if (_starsc)
	{
		auto stars = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Stars);
		u_mem::write<float>(stars + 0x14, _stars_a_corig);
		u_mem::write<float>(stars + 0x10, _stars_s_corig);
	}
	
	if (vars::misc::ambient_changer)
	{
		auto ambient = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Ambient);
		u_mem::write<float>(ambient + 0x18, 99999);

		RenderSettings::ambientMode(AmbientMode::Custom);
		RenderSettings::ambientIntensity(6.f);
		RenderSettings::ambientLight({ vars::misc::ambient_color.r / 255.f, vars::misc::ambient_color.g / 255.f, vars::misc::ambient_color.b / 255.f, vars::misc::ambient_color.a / 255.f });
	}
	else
	{
		auto ambient = u_mem::read<uintptr_t>(tod_sky + values::TOD_Sky::Ambient);
		u_mem::write<float>(ambient + 0x18, 1);
	}
	
	if (vars::misc::rayleigh_changer)
		RenderSettings::atmosphere_rayleigh(vars::misc::rayleigh);
	else
		RenderSettings::atmosphere_rayleigh(-1.f);
	if (vars::misc::mie_changer)
		RenderSettings::atmosphere_mie(vars::misc::mie);
	else
		RenderSettings::atmosphere_mie(-1.f);
	if (vars::misc::brightness_changer)
		RenderSettings::atmosphere_brightness(vars::misc::brightness);
	else
		RenderSettings::atmosphere_brightness(-1.f);
	if (vars::misc::noclouds)
		RenderSettings::cloud_opacity(0.f);
	else
		RenderSettings::cloud_opacity(-1.f);
	if (vars::misc::atmospherecontrast)
		RenderSettings::atmosphere_contrast(5.f);
	else
		RenderSettings::atmosphere_contrast(-1.f);
	if (vars::misc::nofog)
		RenderSettings::fog(0.f);
	else
		RenderSettings::fog(-1.f);
	if (vars::misc::norain)
		RenderSettings::rain(0.f);
	else
		RenderSettings::rain(-1.f);
	if (vars::misc::nothunder)
		RenderSettings::thunder(0.f);
	else
		RenderSettings::thunder(-1.f);
	if (vars::misc::nowind)
		RenderSettings::wind(0.f);
	else
		RenderSettings::wind(-1.f);
	
	if (vars::misc::time_changer) {
		auto convar_admin = il2cpp::init_class(_("Admin"), _("ConVar"));
		//auto convar_admin = u_mem::read<uintptr_t>(g_base + CO::ConVar_Admin_c);
		auto admintime = u_mem::read<uintptr_t>(convar_admin + 0xB8);
		if (!_time) {
			_timeorig = u_mem::read<uintptr_t>(admintime + 0x0);
			_time = true;
		}
		u_mem::write<float>(admintime + 0x0, vars::misc::time_amount);
	}
	else if (_time) {
		auto convar_admin = il2cpp::init_class(_("Admin"), _("ConVar"));
		auto admintime = u_mem::read<uintptr_t>(convar_admin + 0xB8);
		u_mem::write<float>(admintime + 0x0, _timeorig);
	}
	
	{
		auto convar_graph = il2cpp::init_class(_("Graphics"), _("ConVar"));
		auto _fov = u_mem::read<uintptr_t>(convar_graph + 0xB8);
		if (vars::misc::fov_changer) {
			u_mem::write<float>(_fov + 0x18, vars::localplayer::zoom && Input::GetKey(vars::localplayer::zoomkey) ? 30.f : vars::misc::fov_amount);
		}
		else
			u_mem::write<float>(_fov + 0x18, 90.f);
	}
	/*
	if (vars::misc::thirdperson_changer) {
		auto convar_client = u_mem::read<uintptr_t>(g_base + CO::ConVar_Client_c);
		auto thfov = u_mem::read<uintptr_t>(convar_client + 0xB8);
		u_mem::write<float>(thfov + 0x48, vars::misc::th_dist);
		u_mem::write<float>(thfov + 0x58, vars::misc::th_fov);
	}
	else
	{
		auto convar_client = u_mem::read<uintptr_t>(g_base + CO::ConVar_Client_c);
		auto thfov = u_mem::read<uintptr_t>(convar_client + 0xB8);
		u_mem::write<float>(thfov + 0x48, 2);
		u_mem::write<float>(thfov + 0x58, 70);
	}
	*/
	if (vars::misc::ratio_changer) {
		Camera::aspect(vars::misc::ratio_amount);
		aspect = true;
	}
	else if (aspect) Camera::aspect(1.70f);
}
