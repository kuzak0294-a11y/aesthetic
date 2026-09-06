
void hkOnAttacked(void* baseentity, HitInfo* info) {
	if (vars::weapon::hit_material) {
		info->HitMaterial(432631845);
	}
	
	
	u_hooks::orig::hk_OnAttacked(baseentity, info);
}
#include "set.h"
bool show_once = false;

void hand_chams(BasePlayer* entity) {
	if (!entity->playerModel()) return;
	if (!entity->playerModel()->_multiMesh()) return;
	if (!entity->playerModel()->_multiMesh()->Renderers()) return;
	if (!chams1)
		chams1 = (Material*)AssetBundle::LoadAsset(ghkghjggh, _(L"assets/debil pack/diamondmat.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams2)
		chams2 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams2.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams3)
		chams3 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams3.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams4)
		chams4 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams4.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));

	if (!chams5_material)
		chams5_material = (Material*)AssetBundle::LoadAsset(cheat_bundle222, _(L"assets/galaxy.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams5_shader)
		chams5_shader = (Shader*)AssetBundle::LoadAsset(cheat_bundle222, _(L"assets/optimizedshaders/galaxy/poiyomi pro geometric dissolve.shader"), il2cpp::type_object(_("UnityEngine"), _("Shader")));
	if (!chams6)
		chams6 = (Material*)AssetBundle::LoadAsset(offlinetray_bundle, _(L"assets/ghost/ghost.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams7)
		chams7 = (Material*)AssetBundle::LoadAsset(offlinetray_bundle, _(L"assets/matcapfx/golden.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams8)
		chams8 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams8.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams9)
		chams9 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams9.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams10)
		chams10 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams10.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams11)
		chams11 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams11.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams12)
		chams12 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams12.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams13)
		chams13 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams13.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams14)
		chams14 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams14.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
	if (!chams15)
		chams15 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams15.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));

	Shader* chams_shader = nullptr;
	switch (vars::localplayer::chams_type) {
	case 0: chams_shader = chams1 ? chams1->GetShader() : nullptr; break;
	case 1: chams_shader = chams2 ? chams2->GetShader() : nullptr; break;
	case 2: chams_shader = chams3 ? chams3->GetShader() : nullptr; break;
	case 3: chams_shader = chams4 ? chams4->GetShader() : nullptr; break;
	case 4: chams_shader = chams5_shader; break;
	case 5: chams_shader = chams15 ? chams15->GetShader() : nullptr; break;
	case 6: chams_shader = chams6 ? chams6->GetShader() : nullptr; break;
	case 7: chams_shader = chams7 ? chams7->GetShader() : nullptr; break;
	case 8: chams_shader = chams8 ? chams8->GetShader() : nullptr; break;
	case 9: chams_shader = chams9 ? chams9->GetShader() : nullptr; break;
	case 10: chams_shader = chams10 ? chams10->GetShader() : nullptr; break;
	case 11: chams_shader = chams11 ? chams11->GetShader() : nullptr; break;
	case 12: chams_shader = chams12 ? chams12->GetShader() : nullptr; break;
	case 13: chams_shader = chams13 ? chams13->GetShader() : nullptr; break;
	case 14: chams_shader = chams14 ? chams14->GetShader() : nullptr; break;
	default: return;
	}
	if (!chams_shader) return;

	auto model = BaseViewModel::ActiveModel();
	if (!model) return;
	auto renderers = ((Networkable*)model)->GetComponentsInChildren(il2cpp::type_object(_("UnityEngine"), _("Renderer")));
	if (!renderers) return;

	for (int i = 0; i < renderers->get_size(); i++) {
		auto renderer = *reinterpret_cast<Renderer_**>(renderers + 0x20 + i * 0x8);
		if (!renderer) continue;
		Material* material = renderer->material();
		if (!material) continue;
		auto mat_name = material->get_name();
		if (!mat_name) continue;

		if (mat_name->Contains((String*)il2cpp::methods::new_string(_("Hand"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("hand"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Arm"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("arm"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("DiverSuit_Gloves"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Suit_Blue"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("ArcticHazmat_Body"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("BoneArmour"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Jumpsuit"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("BunnyOnesie"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("BurlapHandWraps"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("shirt.burlap"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Wetsuit"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("MakeshiftHazmat_torso"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("HeavyPlateGloves"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("hoodie.red"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("jacket.vagabond"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("gloves.leather"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("tshirt.long.blue"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("lumberjack_hoodie"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Lumberjack_hazmat_torso"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("ninja_suit_viewmodel"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("NomadSuit_torso"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("RoadsignGloves"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("jacket_snow"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("TacticalGloves"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Surgeon_Outfit_main"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("fumes"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("flash"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("holosight"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Particle"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("particle"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Effect"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("effect"))))
		{
			continue;
		}

		if (material->GetShader() == chams_shader)
			continue;

		material->set_shader(chams_shader);
		material->SetInt((String*)il2cpp::methods::new_string(_("_SrcBlend")), 5);
		material->SetInt((String*)il2cpp::methods::new_string(_("_DstBlend")), 10);
		material->SetInt((String*)il2cpp::methods::new_string(_("_Cull")), 0);
		material->SetInt((String*)il2cpp::methods::new_string(_("_ZTest")), 8);
		material->SetInt((String*)il2cpp::methods::new_string(_("_ZWrite")), 0);
	}
}
void hkBasePlayerClientInput(BasePlayer* baseplayer, InputState* state) {
	if (!show_once) {
		il2cpp::hook_virtual_function(_("PlayerWalkMovement"), _("ClientInput"), &hkPlayerWalkMovementClient);
		il2cpp::hook_virtual_function(_("BaseMelee"), _("ProcessAttack"), &hkProcessAttack);
		il2cpp::hook_virtual_function(_("PlayerWalkMovement"), _("DoFixedUpdate"), &hkDoFixedUpdate);
		il2cpp::hook_virtual_function(_("BasePlayer"), _("OnAttacked"), &hkOnAttacked);
		il2cpp::hook_virtual_function(_("ItemIcon"), _("TryToMove"), &hkTryToMove);
		il2cpp::hook_virtual_function(_("BaseProjectile"), _("DoAttack"), &hkDoAttack);
		//il2cpp::hook_virtual_function(_("BaseProjectile"), _("LaunchProjectile"), &hkLaunchProjectile);
		il2cpp::hook_virtual_function(_("SteamPlatform"), _("Update"), &SteamPlatformUpdate, _("Rust.Platform.Steam"));
		show_once = true;
	}
	
	
	if (baseplayer && state && vars::misc::antiaim) {
		Vector3 real_angles = state->current()->aimAngles();
		Vector3 spin_angles = Vector3::Zero();
		bool targeted = (target_player != nullptr);
		int jitter_speed = 10;
		int spin_speed = vars::misc::spinspeed > 0 ? vars::misc::spinspeed : 5;
		
		switch (vars::misc::antiaim_mode)
		{
		case 0: //backwards
			spin_angles.y = real_angles.y + (targeted ? (math::rand() % -180 + 1) : 180.f);
			break;
		case 1: //backwards (down)
			spin_angles.x = (targeted ? 999.f : -999.f);
			spin_angles.z = 0.f;
			spin_angles.y = real_angles.y + 180.f;
			break;
		case 2: //backwards (up)
			spin_angles.x = (targeted ? -999.f : 999.f);
			spin_angles.z = (targeted ? -999.f : 999.f);
			spin_angles.y = real_angles.y + 180.f;
			break;
		case 3: //left
			spin_angles.y = real_angles.y + (targeted ? (math::rand() % -90 + 1) : 90.f);
			break;
		case 4: //left (down)
			spin_angles.x = (targeted ? 999.f : -999.f);
			spin_angles.z = 0.f;
			spin_angles.y = real_angles.y + (targeted ? (math::rand() % -90 + 1) : 90.f);
			break;
		case 5: //right
			spin_angles.y = real_angles.y + (targeted ? (math::rand() % 90 + 1) : -90.f);
			break;
		case 6: //right (down)
			spin_angles.x = (targeted ? 999.f : -999.f);
			spin_angles.z = 0.f;
			spin_angles.y = real_angles.y + (targeted ? (math::rand() % 90 + 1) : -90.f);
			break;
		case 7: //jitter
			if (jitter <= jitter_speed * 1)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % 45 + 1) : -45.f);
			}
			else if (jitter <= jitter_speed * 2)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % 45 + 1) : 45.f);
			}
			else if (jitter <= jitter_speed * 3)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % 180 + 1) : -180.f);
				jitter = 1;
			}
			jitter = jitter + 1;
			break;
		case 8: //jitter (down)
			if (jitter <= jitter_speed * 1)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % 45 + 1) : -45.f);
			}
			else if (jitter <= jitter_speed * 2)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % -45 + 1) : 45.f);
			}
			else if (jitter <= jitter_speed * 3)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % -180 + 1) : 180.f);
				jitter = 1;
			}
			jitter = jitter + 1;
			spin_angles.x = (targeted ? (math::rand() % 999 + 1) : -999.f);
			spin_angles.z = 0.f;
			break;
		case 9: //jitter (up)
			if (jitter <= jitter_speed * 1)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % -45 + 1) : 45.f);
			}
			else if (jitter <= jitter_speed * 2)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % 45 + 1) : -45.f);
			}
			else if (jitter <= jitter_speed * 3)
			{
				spin_angles.y = real_angles.y + (targeted ? (math::rand() % 180 + 1) : -180.f);
				jitter = 1;
			}
			jitter = jitter + 1;
			spin_angles.x = (targeted ? -999.f : 999.f);
			spin_angles.z = (targeted ? -999.f : 999.f);
			break;
		case 10: //spin
			spin_angles.y = targeted ? -(real_angles.y + (spin_speed * spin++)) : real_angles.y + (spin_speed * spin++);
			if (spin_speed > 0 && spin > (360 / spin_speed))
				spin = 1;
			break;
		case 11: //spin (down)
			spin_angles.x = (targeted ? 999.f : -999.f);
			spin_angles.z = 0.f;
			spin_angles.y = targeted ? -(real_angles.y + (spin_speed * spin++)) : real_angles.y + (spin_speed * spin++);
			if (spin_speed > 0 && spin > (360 / spin_speed))
				spin = 1;
			break;
		case 12: //spin (up)
			spin_angles.x = (targeted ? -999.f : 999.f);
			spin_angles.y = targeted ? -(real_angles.y + (spin_speed * spin++)) : real_angles.y + (spin_speed * spin++);
			spin_angles.z = (targeted ? -999.f : 999.f);
			if (spin_speed > 0 && spin > (360 / spin_speed))
				spin = 1;
			break;
		case 13: //random
			spin_angles = Vector3((math::rand() % 999 + -999), (math::rand() % 999 + -999), (math::rand() % 999 + -999));
			break;
		}

		if (spin_angles != Vector3::Zero())
			state->current()->aimAngles(spin_angles);
	}
	
	if (baseplayer) {
		il2cpp::hook_virtual_function(_("ProjectileShoot"), _("WriteToStream"), &hkWriteToStream, _("ProtoBuf"));
		local_player = baseplayer;
		il2cpp::hook_virtual_function(_("ProjectileShoot"), _("WriteToStream"), &hkWriteToStream, _("ProtoBuf"));
		local_player = baseplayer;
		WeaponSet();
		SkySet();
		/*DDraw::Capsule(target_player->playerModel()->position() + Vector3(0, 1.2, 0), Quaternion::Quaternion(), 2.8f Color(1, 0, 0, 1), 0.001f, false, true);*/
		if (vars::weapon::sphere_RADIUS) {
			/*DDraw::Sphere(target_player->playerModel()->position() + Vector3(0, 1., 0), 1.00,{ 1, 0, 0, 1 },0.001f,false,true);*/
			DDraw::Capsule(target_player->playerModel()->position() + Vector3(0, 1.2, 0), Quaternion::Quaternion(), 1.f, 0.5f, Color(1, 0, 0, 1), 0.001f, false, true);
		}
		if (vars::psilent::HitBone == 0) {
			target_bone = head;
		}
		else if (vars::psilent::HitBone == 1) {
			target_bone = neck;
		}
		else if (vars::psilent::HitBone == 2) {
			target_bone = spine2;
		}
		else if (vars::psilent::HitBone == 3) {
			int num = math::rand() % 100;
			if (num > 90)
			{
				target_bone = head;
			}
			else if (num < 90 && num > 80)
			{
				target_bone = neck;
			}
			else if (num < 80 && num > 70)
			{
				target_bone = r_hip;
			}
			else if (num < 70 && num > 60)
			{
				target_bone = pelvis;
			}
			else if (num < 60 && num > 50)
			{
				target_bone = l_clavicle;
			}
			else if (num < 50 && num > 40)
			{
				target_bone = l_upperarm;
			}
			else if (num < 40 && num > 30)
			{
				target_bone = l_foot;
			}
			else if (num < 30 && num > 20)
			{
				target_bone = r_foot;
			}
			else if (num < 20 && num > 10)
			{
				target_bone = l_hand;
			}
			else if (num < 10)
			{
				target_bone = r_hand;
			}
			else
			{
				target_bone = spine1;
			}
		}
		if (vars::localplayer::chams) {
			auto convar_graph = il2cpp::init_class(_("Graphics"), _("ConVar"));
			auto static_fields = u_mem::read<DWORD64>(convar_graph + 0xb8);
			u_mem::write<bool>(static_fields + 0x85, false);

			hand_chams(local_player);
		}
		//SoundEsp_Loop();
	}
	return u_hooks::orig::hk_BasePlayer_ClientInput(baseplayer, state);
}