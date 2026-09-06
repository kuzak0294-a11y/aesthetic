#include <vector>

float get_fov(BasePlayer* entity) {
	Vector2 screen_pos;
	if (!entity || (uintptr_t)entity < 0x10000) return 1000.f;
	
	auto head_transform = entity->GetTransform(head);
	if (!head_transform || (uintptr_t)head_transform < 0x10000) return 1000.f;
	
	if (!other::world_to_screen(head_transform->position(), screen_pos)) return 1000.f;
	return (Vector2(Screen::get_width() / 2, Screen::get_height() / 2)).Distance(screen_pos);
}
void player_chams(BasePlayer* player) {
	if (!vars::esp::player_chams) return;
	if (!player || (uintptr_t)player < 0x10000) return;
	
	auto playerModel = player->playerModel();
	if (!playerModel || (uintptr_t)playerModel < 0x10000) return;
	
	Material* current_shader1 = nullptr;
	Shader* current_shader = nullptr;
	
	if (vars::esp::player_chams_type == 0) {
		
		if (!player_chams_shader)
			player_chams_shader = (Shader*)AssetBundle::LoadAsset(ghost_effect_bundle1, _(L"assets/shaders/rainbow.shader"), il2cpp::type_object(_("UnityEngine"), _("Shader")));
		current_shader = player_chams_shader;
	} else if (vars::esp::player_chams_type == 1) {
		
		if (!player_chams_shader_flat)
			player_chams_shader_flat = (Shader*)AssetBundle::LoadAsset(ghost_effect_bundle1, _(L"assets/shaders/vischeck.shader"), il2cpp::type_object(_("UnityEngine"), _("Shader")));
		current_shader = player_chams_shader_flat;
	}
	else if (vars::esp::player_chams_type == 2) {
		
		if (!player_chams_shader_flat12)
			player_chams_shader_flat12 = (Material*)AssetBundle::LoadAsset(cheat_bundle, _(L"chams8.mat"), il2cpp::type_object(_("UnityEngine"), _("Material")));
		current_shader1 = player_chams_shader_flat12;
	}
	
	if (!current_shader) return;
	
	static auto setColorMethod = il2cpp::method(_("Material"), _("SetColor"), 2, _(""), _("UnityEngine"));
	static auto setColorFunc = rc<void(*)(uintptr_t, String*, Color)>(*rc<uintptr_t*>(setColorMethod));
	static auto setFloatMethod = il2cpp::method(_("Material"), _("SetFloat"), 2, _(""), _("UnityEngine"));
	static auto setFloatFunc = rc<void(*)(uintptr_t, String*, float)>(*rc<uintptr_t*>(setFloatMethod));
	auto renderers = ((Networkable*)playerModel)->GetComponentsInChildren(il2cpp::type_object(_("UnityEngine"), _("Renderer")));
	if (!renderers || (uintptr_t)renderers < 0x10000) return;
	
	
	for (int i = 0; i < renderers->get_size(); i++) {
		auto renderer = *reinterpret_cast<Renderer_**>(renderers + 0x20 + i * 0x8);
		if (!renderer || (uintptr_t)renderer < 0x10000) continue;
		Material* material = renderer->material();
		if (!material || (uintptr_t)material < 0x10000) continue;
		auto mat_name = material->get_name();
		if (!mat_name || (uintptr_t)mat_name < 0x10000) continue;
		if (mat_name->Contains((String*)il2cpp::methods::new_string(_("blood"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Blood"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("gore"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Gore"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("decal"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Decal"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Particle"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("particle"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Effect"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("effect"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("FX"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("fumes"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("flash"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("fx"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Plane"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("plane"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Quad"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("quad"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("dust"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Dust"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("impact"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Impact"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("hit"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Hit"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("splash"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Splash"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("spark"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Spark"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("weapon"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Weapon"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("rifle"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("gun"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("pistol"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("bow"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("arrow"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("rock"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("torch"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("tool"))) ||
			mat_name->Contains((String*)il2cpp::methods::new_string(_("Tool")))) {
			continue; 
		}
		
		material->set_shader(current_shader);
		material->SetInt((String*)il2cpp::methods::new_string(_("_SrcBlend")), 5); 
		material->SetInt((String*)il2cpp::methods::new_string(_("_DstBlend")), 10); 
		material->SetInt((String*)il2cpp::methods::new_string(_("_Cull")), 0); 
		material->SetInt((String*)il2cpp::methods::new_string(_("_ZTest")), 8); 
		material->SetInt((String*)il2cpp::methods::new_string(_("_ZWrite")), 0); 
		
		
		if (vars::esp::player_chams_type == 0 && setFloatFunc) {
			setFloatFunc((uintptr_t)material, (String*)il2cpp::methods::new_string(_("_Speed")), vars::esp::player_chams_rainbow_speed);
		}
		
		if (setColorFunc) {
			
			Color visible_color = vars::esp::player_chams_visible_color.ToUnity(); 
			visible_color.a = vars::esp::player_chams_alpha; 
			setColorFunc((uintptr_t)material, (String*)il2cpp::methods::new_string(_("_ColorVisible")), visible_color);
			
			
			Color behind_color = vars::esp::player_chams_invisible_color.ToUnity(); 
			behind_color.a = vars::esp::player_chams_alpha; 
			setColorFunc((uintptr_t)material, (String*)il2cpp::methods::new_string(_("_ColorBehind")), behind_color);
		}
	}
}

void draw_radar(BasePlayer* player)
{
	if (!vars::esp::radar || menu_alfa >= 222) return;
	if (!player || (uintptr_t)player < 0x10000) return;
	
	auto playerModel = player->playerModel();
	if (!playerModel || (uintptr_t)playerModel < 0x10000) return;
	
	auto main_cam = Camera::main_camera();
	if (!main_cam || main_cam < 0x10000) return;
	
	auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
	if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;
	
	auto transform = player->GetTransform(47);
	if (!transform || (uintptr_t)transform < 0x10000) return;
	
	Vector3 LocalPos = cam_transform->position();
	Vector3 PlayerPos = transform->position();
	Vector4 cam_rotation_v4 = cam_transform->rotation();
	Quaternion cam_rotation = {cam_rotation_v4.x, cam_rotation_v4.y, cam_rotation_v4.z, cam_rotation_v4.w};
	Vector3 eulerAngles = math::EulerAngles(cam_rotation);
	float Distance1 = LocalPos.Distance2D(PlayerPos); Distance1 *= 0.66f;
	if (Distance1 > 400) return;
	const float y1 = LocalPos.x - PlayerPos.x;
	const float x1 = LocalPos.z - PlayerPos.z;
	const float num1 = math::atan(y1, x1) * 57.29578f - 270 - eulerAngles.y;
	float RealDist1 = 0.0;

	if (Distance1 > 198)
	{
		float Calc1 = Distance1 - 198;
		RealDist1 = Distance1 - Calc1;
	}
	else RealDist1 = Distance1;

	float PointPos_X1 = RealDist1 * math::cos(num1 * 0.0174532924f);
	float PointPos_Y1 = RealDist1 * math::sin(num1 * 0.0174532924f);
	PointPos_X1 = PointPos_X1 * (vars::esp::radar_size / 200);
	PointPos_Y1 = PointPos_Y1 * (vars::esp::radar_size / 200);
	Vector2 point1 = { vars::esp::radar_pos.x + vars::esp::radar_size + PointPos_X1, vars::esp::radar_pos.y + vars::esp::radar_size + PointPos_Y1 };

	if (vars::esp::looking_direction)
	{
		auto eyes = player->eyes();
		if (!eyes || (uintptr_t)eyes < 0x10000) {
			
			u_render::texturebox({ point1.x, point1.y }, { 4, 4 }, vars::esp::namecolor, 0, 260);
			return;
		}
		
		Vector3 headPos = player->GetBoneByID(head);
		if (headPos.is_empty()) {
			
			u_render::texturebox({ point1.x, point1.y }, { 4, 4 }, vars::esp::namecolor, 0, 260);
			return;
		}
		
		const Vector3 PlayerPos2 = (headPos + (eyes->bodyforward() * 40));
		float Distance2 = LocalPos.Distance2D(PlayerPos2); Distance2 *= 0.66f;

		const float y2 = LocalPos.x - PlayerPos2.x;
		const float x2 = LocalPos.z - PlayerPos2.z;
		const float num2 = math::atan(y2, x2) * 57.29578f - 270 - eulerAngles.y;
		float RealDist2 = 0.0;

		if (Distance2 > 198)
		{
			float Calc2 = Distance2 - 198;
			RealDist2 = Distance2 - Calc2;
		}
		else
		{
			RealDist2 = Distance2;
		}
		float PointPos_X2 = RealDist2 * math::cos(num2 * 0.0174532924f);
		float PointPos_Y2 = RealDist2 * math::sin(num2 * 0.0174532924f);
		PointPos_X2 = PointPos_X2 * (vars::esp::radar_size / 200);
		PointPos_Y2 = PointPos_Y2 * (vars::esp::radar_size / 200);
		Vector2 point2 = { vars::esp::radar_pos.x + vars::esp::radar_size + PointPos_X2, vars::esp::radar_pos.y + vars::esp::radar_size + PointPos_Y2 };
		u_render::drawline({ point2.x + (4 / 2), point2.y + (4 / 2) }, { point1.x + (4 / 2), point1.y + (4 / 2) }, vars::esp::looking_directioncolor, 0.5f);

		//u_render::drawline({ point2.x + (4 / 2), point2.y + (4 / 2) }, { point1.x + (4 / 2), point1.y + (4 / 2) }, vars::esp::looking_directioncolor, 1.2f);
	}
	u_render::texturebox({ point1.x, point1.y }, { 4, 4 }, vars::esp::namecolor, 0, 260);
}
void oofind(BasePlayer* ply) {
	if (!vars::esp::oofindicators) return;
	if (!ply || (uintptr_t)ply < 0x10000) return;
	
	auto main_cam = Camera::main_camera();
	if (!main_cam || main_cam < 0x10000) return;
	
	auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
	if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;
	
	Vector3 headPos = ply->GetBoneByID(head);
	if (headPos.is_empty()) return; 
	
	Vector3 local = cam_transform->position();
	float y = local.x - headPos.x;
	float x = local.z - headPos.z;
	Vector4 cam_rotation_v4 = cam_transform->rotation();
	Quaternion cam_rotation = {cam_rotation_v4.x, cam_rotation_v4.y, cam_rotation_v4.z, cam_rotation_v4.w};
	Vector3 eulerAngles = math::euler_angles(cam_rotation);
	float angleYawRad = math::atan(y, x) * 57.29578f - 180.f - eulerAngles.y;
	Vector2 tp = math::calculate_rotation_point(angleYawRad, 255.f, screen_center.x, screen_center.y, 165.f + 50.f);
	u_render::circle(tp, 7, Color(0, 0, 0, (float)pulsation(50, 255)), 0);
	u_render::circle( tp , 6, Color(vars::esp::namecolor.r, vars::esp::namecolor.g, vars::esp::namecolor.b, (float)pulsation(50, 255)), 0);
}
float belt_size; float belt_alpha = 0;
inline void draw_targetbelt() {
	if (!vars::psilent::target_belt) return;
	
	
	if (menu_alfa >= 3) return;
	
	
	if (target_player)
	{
		belt_alpha = 255;
	}
	else
	{
		belt_alpha = 0;
	}

	if (target_player == nullptr) return;
	
	float slot_size = vars::psilent::target_belt_size;
	float slot_spacing = slot_size + 5;
	float Pos = 5;

	for (int i = 0; i < 6; i++)
	{
		
		u_render::texturebox({ vars::psilent::belt_pos.x + Pos, vars::psilent::belt_pos.y }, { slot_size, slot_size }, {30, 30, 30, 200}, 0, 10);
		
		Item* ActWeapon = target_player->weapon_info(i);
		if (ActWeapon && ActWeapon != nullptr && ActWeapon != 0) {
			int getAmount = ActWeapon->GetAmount();
			
			
			if (getAmount > 0) {
				auto sprite = ActWeapon->get_iconSprite(); 
				if (sprite) {
					auto texture = (DWORD64)Sprite::get_texture(sprite);
					if (texture) {
						Color col = target_player->active_weapon() == ActWeapon ? Color(176, 224, 230, 140) :  Color(255, 255, 255, 0);
						
						
						if (target_player->active_weapon() == ActWeapon) {
							u_render::texturebox({ vars::psilent::belt_pos.x + Pos, vars::psilent::belt_pos.y }, { slot_size, slot_size }, {col.r, col.g, col.b, col.a}, 0, 10);
						}
						
					
						GUI::DrawTexture(Rect(vars::psilent::belt_pos.x + Pos, vars::psilent::belt_pos.y, slot_size, slot_size), texture, 0, true, 0, { 1, 1, 1, belt_alpha / 255 }, Vector4(0, 0, 0, 0), Vector4(0, 0, 0, 0), true);

						wchar_t outputText[512];
						il2cpp::methods::f_swprint(outputText, _(L"x%d"), getAmount);
						u_render::text({ vars::psilent::belt_pos.x + Pos + (slot_size / 2), vars::psilent::belt_pos.y + slot_size - 3 }, outputText, { 255 , 255, 255, 255 }, true, 10, vars::esp::outline);
					}
				}
			}
		}

		Pos += slot_spacing;
	}
}
Vector2 targetheadpos;
uintptr_t rustentity[99999];
int addedindx;
void find_cash_object(uintptr_t entity) {
	auto object = u_mem::read<uintptr_t>(entity + 0x10); if (object <= 100000) return;
	auto object_class = u_mem::read<uintptr_t>(object + 0x30); if (object_class <= 100000) return;
	auto tag = u_mem::read<WORD>(object_class + 0x54);
	auto classname = (char*)u_mem::read<DWORD64>(u_mem::read<DWORD64>(u_mem::read<DWORD64>(object + 0x28)) + 0x10);

	if (tag == 6)
	{
		rustentity[addedindx] = entity;
		addedindx += 1;
		return;
	}

	BasePlayer* entity_ = (BasePlayer*)entity;
	if (vars::object::debug_ent && entity_->transform()->position().Distance(local_player->transform()->position()) <= 90.0f) {
		rustentity[addedindx] = entity;
		addedindx += 1;
		return;
	}

	unsigned int PrefabId = u_mem::read<UINT64>((UINT64)entity + values::BaseNetworkable::prefabID); if (!PrefabId) return;

	bool sulfur_ore = (PrefabId == 3058967796 || PrefabId == 1227527004 || PrefabId == 2204178116 || PrefabId == 152562243);
	bool mini_sulfur_ore = (PrefabId == 2972237931);
	bool metal_ore = (PrefabId == 3774647716 || PrefabId == 4225479497 || PrefabId == 3345228353 || PrefabId == 3327726152);
	bool mini_metal_ore = (PrefabId == 4060169083);
	bool stone_ore = (PrefabId == 4124824587 || PrefabId == 266547145 || PrefabId == 723721358 || PrefabId == 960501790);
	bool mini_stone_ore = (PrefabId == 2422310333);

	bool yellow_berry = (PrefabId == 3056106441);
	bool blue_berry = (PrefabId == 2764599810);
	bool red_berry = (PrefabId == 1378329388);
	bool green_berry = (PrefabId == 3306182606);
	bool black_berry = (PrefabId == 3408978181);
	bool white_berry = (PrefabId == 1989241797);

	bool mini_copter = PrefabId == 2278499844;
	bool bradley = PrefabId == 1456850188;
	bool rowboat = PrefabId == 1283317166;
	bool rhib = PrefabId == 2226588638;
	bool scrap_transport_heli = PrefabId == 3484163637;
	bool patrol_heli_copter = PrefabId == 3029415845;

	bool elite_crate = (PrefabId == 3286607235 || PrefabId == 96231181);
	bool basic_crate = (PrefabId == 1603759333);
	bool normal_crate = (PrefabId == 2857304752 || PrefabId == PrefabId == 2857304752);
	bool normal_crate2 = (PrefabId == 1546200557 || PrefabId == PrefabId == 2276830067);
	bool tool_crate = (PrefabId == 1892026534 || PrefabId == 3027334492);

	bool wolf = (PrefabId == 2144238755);
	bool boar = (PrefabId == 502341109);
	bool bear = (PrefabId == 1799741974);
	bool horse = (PrefabId == 3880446623 || PrefabId == 2421623959);

	bool flame_turret = (PrefabId == 4075317686);
	bool land_mine = (PrefabId == 1463807579);
	bool sam_site = (PrefabId == 2059775839);
	bool gun_trap = (PrefabId == 1348746224);
	bool bear_trap = (PrefabId == 922529517);
	bool turrents = (PrefabId == 3312510084);

	bool hemp = (PrefabId == 3006540952 || PrefabId == 3587624038);
	bool corn = (PrefabId == 112964822 || PrefabId == 3019211920);
	bool potato = (PrefabId == 451737085 || PrefabId == 726972295);
	bool pumpkin = (PrefabId == 1524652375 || PrefabId == 2251957318);
	bool mushroom = (PrefabId == 2697239269 || PrefabId == 178882626);
	bool corpse = (PrefabId == 2400390439 || PrefabId == 3842948583 || PrefabId == 1236143239 || PrefabId == 2604534927 || PrefabId == 391715894);
	bool backpack = (PrefabId == 1519640547);
	//bool stash = PrefabId == 2568831788;

	bool stop_recycler = PrefabId == 1729604075;
	bool hackable_crate = (PrefabId == 209286362 || PrefabId == 2043434947 || PrefabId == 3527151681);
	bool dropped_items = (PrefabId == -1039821371);

	bool tool_cupboard = PrefabId == 2476970476;
	bool furnace_large = PrefabId == 1374462671;
	bool furnace = (PrefabId == 2931042549 || PrefabId == 1402456403);
	bool bed = PrefabId == 3928883189;
	bool large_woodbox = PrefabId == 2206646561;
	bool campfire = (PrefabId == 4160694184 || PrefabId == 1339281147);
	bool researchtable = (PrefabId == 146554961 || PrefabId == 1827442529);
	bool vendingmachine = PrefabId == 186002280;
	bool workbench1 = (PrefabId == 2561955800 || PrefabId == 1899388596);
	bool workbench2 = (PrefabId == 601265145 || PrefabId == 1457273871);
	bool workbench3 = PrefabId == 2764275075;
	bool treasures = (PrefabId == 1244235496);
	bool diesel = (PrefabId == 1388355532);

	if (sulfur_ore || mini_sulfur_ore || metal_ore || mini_metal_ore || stone_ore || mini_stone_ore || blue_berry || yellow_berry || red_berry || green_berry || black_berry || white_berry || mini_copter || 
		bradley || rowboat || rhib || scrap_transport_heli || patrol_heli_copter || elite_crate || basic_crate || normal_crate || normal_crate2 || tool_crate || hackable_crate || wolf || boar || bear || 
		horse || flame_turret || land_mine || sam_site || gun_trap || bear_trap || turrents /*|| stash*/ || tool_cupboard || furnace || furnace_large || bed || large_woodbox || campfire || researchtable || 
		vendingmachine || workbench1 || workbench2 || workbench3 || hemp || corn || potato || pumpkin || mushroom || diesel || corpse || backpack || dropped_items || treasures || stop_recycler ||
		u_crt::m_strstr(classname, _("OreResourceEntity")) || u_crt::m_strstr(classname, _("OreHotSpot")) || u_crt::m_strstr(classname, _("TreeEntity")) || u_crt::m_strstr(classname, _("TreeMarker")) ||
		u_crt::m_strstr(classname, _("BuildingBlock")) || u_crt::m_strstr(classname, _("CollectibleEntity")) || u_crt::m_strstr(classname, _("Door")) || turrents /*|| tag == 6*/)
	{
		rustentity[addedindx] = entity;
		addedindx += 1;
		return;
	}
}
void items_loop(BasePlayer* entity, char* classname)
{
	unsigned int PrefabId = u_mem::read<UINT64>((UINT64)entity + values::BaseNetworkable::prefabID); if (!PrefabId) return;

	if (vars::object::debug_ent && entity->transform()->position().Distance(local_player->transform()->position()) <= 30.0f) {
		const char* charString = entity->get_class_name();
		size_t bufferSize = u_crt::strlen(charString) + 1;
		wchar_t wcharBuffer[256];
		u_crt::ConvertCharToWchar(charString, wcharBuffer, bufferSize);

		const char* charString_ = entity->get_class_name();
		size_t bufferSize_ = u_crt::strlen(charString_) + 1;
		wchar_t wcharBuffer_[256];
		u_crt::ConvertCharToWchar(charString_, wcharBuffer_, bufferSize_);
		other::DrawDebug(entity, wcharBuffer, wcharBuffer_, PrefabId, { 255, 255, 255, 255 });
	}

	bool sulfur_ore = (PrefabId == 3058967796 || PrefabId == 1227527004 || PrefabId == 2204178116 || PrefabId == 152562243);
	bool mini_sulfur_ore = (PrefabId == 2972237931);
	bool metal_ore = (PrefabId == 3774647716 || PrefabId == 4225479497 || PrefabId == 3345228353 || PrefabId == 3327726152);
	bool mini_metal_ore = (PrefabId == 4060169083);
	bool stone_ore = (PrefabId == 4124824587 || PrefabId == 266547145 || PrefabId == 723721358 || PrefabId == 960501790);
	bool mini_stone_ore = (PrefabId == 2422310333);

	bool yellow_berry = (PrefabId == 3056106441);
	bool blue_berry = (PrefabId == 2764599810);
	bool red_berry = (PrefabId == 1378329388);
	bool green_berry = (PrefabId == 3306182606);
	bool black_berry = (PrefabId == 3408978181);
	bool white_berry = (PrefabId == 1989241797);

	bool mini_copter = PrefabId == 2278499844;
	bool bradley = PrefabId == 1456850188;
	bool rowboat = PrefabId == 1283317166;
	bool rhib = PrefabId == 2226588638;
	bool scrap_transport_heli = PrefabId == 3484163637;
	bool patrol_heli_copter = PrefabId == 3029415845;

	bool elite_crate = (PrefabId == 3286607235 || PrefabId == 96231181);
	bool basic_crate = (PrefabId == 1603759333);
	bool normal_crate = (PrefabId == 2857304752 || PrefabId == PrefabId == 2857304752);
	bool normal_crate2 = (PrefabId == 1546200557 || PrefabId == PrefabId == 2276830067);
	bool tool_crate = (PrefabId == 1892026534 || PrefabId == 3027334492);

	bool wolf = (PrefabId == 2144238755);
	bool boar = (PrefabId == 502341109);
	bool bear = (PrefabId == 1799741974);
	bool horse = (PrefabId == 3880446623 || PrefabId == 2421623959);

	bool flame_turret = (PrefabId == 4075317686);
	bool land_mine = (PrefabId == 1463807579);
	bool sam_site = (PrefabId == 2059775839);
	bool gun_trap = (PrefabId == 1348746224);
	bool bear_trap = (PrefabId == 922529517);
	bool turrents = (PrefabId == 3312510084);

	bool hemp = (PrefabId == 3006540952 || PrefabId == 3587624038);
	bool corn = (PrefabId == 112964822 || PrefabId == 3019211920);
	bool potato = (PrefabId == 451737085 || PrefabId == 726972295);
	bool pumpkin = (PrefabId == 1524652375 || PrefabId == 2251957318);
	bool mushroom = (PrefabId == 2697239269 || PrefabId == 178882626);
	bool corpse = (PrefabId == 2400390439 || PrefabId == 3842948583 || PrefabId == 1236143239 || PrefabId == 2604534927 || PrefabId == 391715894);
	bool backpack = (PrefabId == 1519640547);
	//bool stash = PrefabId == 2568831788;

	bool stop_recycler = PrefabId == 1729604075;
	bool hackable_crate = (PrefabId == 209286362 || PrefabId == 2043434947 || PrefabId == 3527151681);
	bool dropped_items = (PrefabId == -1039821371);

	bool tool_cupboard = PrefabId == 2476970476;
	bool furnace_large = PrefabId == 1374462671;
	bool furnace = (PrefabId == 2931042549 || PrefabId == 1402456403);
	bool bed = PrefabId == 3928883189;
	bool large_woodbox = PrefabId == 2206646561;
	bool campfire = (PrefabId == 4160694184 || PrefabId == 1339281147);
	bool researchtable = (PrefabId == 146554961 || PrefabId == 1827442529);
	bool vendingmachine = PrefabId == 186002280;
	bool workbench1 = (PrefabId == 2561955800 || PrefabId == 1899388596);
	bool workbench2 = (PrefabId == 601265145 || PrefabId == 1457273871);
	bool workbench3 = PrefabId == 2764275075;
	bool treasures = (PrefabId == 1244235496);
	bool diesel = (PrefabId == 1388355532);
	
	if (!local_player || !local_player->eyes()) return;
	Vector3 LocalPos = local_player->eyes()->position();
	

	
	//Ore
	if (vars::object::ores[0] && sulfur_ore) 
	{
		other::DrawObject(entity, vars::object::show_ores_distance, vars::object::max_ores_distance, _(L"Sulfur Ore"), { 255, 215, 0, 255 }, vars::object::show_ores_ico, _(L"sulfur.ore.png"), false); return;
	}
	if (vars::object::ores[1] && mini_sulfur_ore) 
	{
		other::DrawObject(entity, vars::object::show_ores_distance, vars::object::max_ores_distance, _(L"mini Sulfur Ore"), { 255, 140, 0, 255 }, vars::object::show_ores_ico, _(L"sulfur.ore.png"), false); return;
	}
	if (vars::object::ores[2] && metal_ore) 
	{
		other::DrawObject(entity, vars::object::show_ores_distance, vars::object::max_ores_distance, _(L"Metal Ore"), { 222, 184, 135, 255 }, vars::object::show_ores_ico, _(L"metal.ore.png"), false); return;
	}
	if (vars::object::ores[3] && mini_metal_ore) 
	{
		other::DrawObject(entity, vars::object::show_ores_distance, vars::object::max_ores_distance, _(L"mini Metal Ore"), { 128, 128, 128, 255 }, vars::object::show_ores_ico, _(L"metal.ore.png"), false); return;
	}
	if (vars::object::ores[4] && stone_ore) 
	{
		other::DrawObject(entity, vars::object::show_ores_distance, vars::object::max_ores_distance, _(L"Stone Ore"), { 169, 169, 169, 255 }, vars::object::show_ores_ico, _(L"stones.png"), false); return;
	}
	if (vars::object::ores[5] && mini_stone_ore) 
	{
		other::DrawObject(entity, vars::object::show_ores_distance, vars::object::max_ores_distance, _(L"mini Stone Ore"), { 128, 128, 128, 255 }, vars::object::show_ores_ico, _(L"stones.png"), false); return;
	}
	//BlueBerry
	if (vars::object::berrys[0] && blue_berry) 
	{
		other::DrawObject(entity, vars::object::show_berrys_distance, vars::object::max_berrys_distance, _(L"Blue Berry"), { 0, 0, 255, 255 }, vars::object::show_berrys_ico, _(L"blue.berry.png")); return;
	}
	if (vars::object::berrys[1] && yellow_berry) 
	{
		other::DrawObject(entity, vars::object::show_berrys_distance, vars::object::max_berrys_distance, _(L"Yellow Berry"), { 255, 186, 0, 255 }, vars::object::show_berrys_ico, _(L"yellow.berry.png")); return;
	}
	if (vars::object::berrys[2] && red_berry) 
	{
		other::DrawObject(entity, vars::object::show_berrys_distance, vars::object::max_berrys_distance, _(L"Red Berry"), { 255, 0, 0, 255 }, vars::object::show_berrys_ico, _(L"red.berry.png")); return;
	}
	if (vars::object::berrys[3] && green_berry) 
	{
		other::DrawObject(entity, vars::object::show_berrys_distance, vars::object::max_berrys_distance, _(L"Green Berry"), { 0, 255, 0, 255 }, vars::object::show_berrys_ico, _(L"green.berry.png")); return;
	}
	if (vars::object::berrys[4] && black_berry)
	{
		other::DrawObject(entity, vars::object::show_berrys_distance, vars::object::max_berrys_distance, _(L"Black Berry"), { 0, 255, 0, 255 }, vars::object::show_berrys_ico, _(L"black.berry.png")); return;
	}
	if (vars::object::berrys[5] && white_berry)
	{
		other::DrawObject(entity, vars::object::show_berrys_distance, vars::object::max_berrys_distance, _(L"White Berry"), { 0, 255, 0, 255 }, vars::object::show_berrys_ico, _(L"white.berry.png")); return;
	}
	//Vehicle
	if (vars::object::vehicles[0] && mini_copter) 
	{
		other::DrawObject(entity, vars::object::show_vehicles_distance, vars::object::max_vehicles_distance, _(L"Minicopter"), { 250, 250, 0, 255 }, false, _(L"")); return;
	}
	if (vars::object::vehicles[1] && bradley) 
	{
		other::DrawObject(entity, vars::object::show_vehicles_distance, vars::object::max_vehicles_distance, _(L"Bradley"), { 250, 152, 0, 255 }, false, _(L"")); return;
	}
	if (vars::object::vehicles[2] && rowboat) 
	{
		other::DrawObject(entity, vars::object::show_vehicles_distance, vars::object::max_vehicles_distance, _(L"Rowboat"), { 255, 142, 13, 255 }, false, _(L"")); return;
	}
	if (vars::object::vehicles[3] && rhib) 
	{
		other::DrawObject(entity, vars::object::show_vehicles_distance, vars::object::max_vehicles_distance, _(L"Rhib"), { 128, 58, 0, 255 }, false, _(L"")); return;
	}
	if (vars::object::vehicles[4] && scrap_transport_heli) 
	{
		other::DrawObject(entity, vars::object::show_vehicles_distance, vars::object::max_vehicles_distance, _(L"Scrap Helicopter"), { 250, 0, 9, 255 }, false, _(L"")); return;
	}
	if (patrol_heli_copter && vars::object::vehicles[5]) 
	{
		other::DrawObject(entity, vars::object::show_vehicles_distance, vars::object::max_vehicles_distance, _(L"Patrol Helicopter"), { 255, 0, 0, 255 }, false, _(L""), true); return;
	}
	//Crate
	if (vars::object::crates[0] && elite_crate) 
	{
		other::DrawObject(entity, vars::object::show_crates_distance, vars::object::max_crates_distance, _(L"Elite Crate"), { 60, 179, 113, 255 }, false, _(L"")); return;
	}
	if (vars::object::crates[1] && basic_crate) 
	{
		other::DrawObject(entity, vars::object::show_crates_distance, vars::object::max_crates_distance, _(L"Basic Crate"), { 250, 152, 0, 255 }, false, _(L"")); return;
	}
	if (vars::object::crates[2] && normal_crate) 
	{
		other::DrawObject(entity, vars::object::show_crates_distance, vars::object::max_crates_distance, _(L"Military Crate"), { 34, 139, 34, 255 }, false, _(L"")); return;
	}
	if (vars::object::crates[3] && normal_crate2) 
	{
		other::DrawObject(entity, vars::object::show_crates_distance, vars::object::max_crates_distance, _(L"Normal Crate"), { 222, 184, 135, 255 }, false, _(L"")); return;
	}
	if (vars::object::crates[4] && tool_crate) 
	{
		other::DrawObject(entity, vars::object::show_crates_distance, vars::object::max_crates_distance, _(L"Tool Crate"), { 205, 92, 92, 255 }, false, _(L"")); return;
	}
	if (vars::object::crates[5] && hackable_crate) 
	{
		other::HackableCrate(entity, vars::object::show_crates_distance, vars::object::max_crates_distance); return;
	}
	//Animal
	if (vars::object::animals[0] && wolf) 
	{
		other::DrawObject(entity, vars::object::show_animals_distance, vars::object::max_animals_distance, _(L"Wolf"), { 32, 32, 32, 255 }, false, _(L"")); return;
	}
	if (vars::object::animals[1] && boar) 
	{
		other::DrawObject(entity, vars::object::show_animals_distance, vars::object::max_animals_distance, _(L"Boar"), { 51, 25, 0, 255 }, false, _(L"")); return;
	}
	if (vars::object::animals[2] && bear) 
	{
		other::DrawObject(entity, vars::object::show_animals_distance, vars::object::max_animals_distance, _(L"Bear"), { 61, 31, 0, 255 }, false, _(L"")); return;
	}
	if (vars::object::animals[3] && horse) 
	{
		other::DrawObject(entity, vars::object::show_animals_distance, vars::object::max_animals_distance, _(L"Horse"), { 160, 82, 45, 255 }, false, _(L"")); return;
	}
	//Trap
	if (vars::object::traps[0] && flame_turret) 
	{
		other::DrawObject(entity, vars::object::show_traps_distance, vars::object::max_traps_distance, _(L"Flame Turret"), { 153, 0, 0, 255 }, vars::object::show_traps_ico, _(L"flameturret.png")); return;
	}
	if (vars::object::traps[1] && land_mine) 
	{
		other::DrawObject(entity, vars::object::show_traps_distance, vars::object::max_traps_distance, _(L"LandMine"), { 72, 61, 139, 255 }, vars::object::show_traps_ico, _(L"trap.landmine.png")); return;
	}
	if (vars::object::traps[2] && sam_site) 
	{
		other::DrawObject(entity, vars::object::show_traps_distance, vars::object::max_traps_distance, _(L"Sam Site"), { 98, 86, 74, 255 }, vars::object::show_traps_ico, _(L"samsite.png")); return;
	}
	if (vars::object::traps[3] && gun_trap) 
	{
		other::DrawObject(entity, vars::object::show_traps_distance, vars::object::max_traps_distance, _(L"Shotgun Trap"), { 98, 86, 74, 255 }, vars::object::show_traps_ico, _(L"guntrap.png")); return;
	}
	if (vars::object::traps[4] && bear_trap) 
	{
		other::DrawObject(entity, vars::object::show_traps_distance, vars::object::max_traps_distance, _(L"Bear Trap"), { 114, 99, 85, 255 }, vars::object::show_traps_ico, _(L"trap.bear.png")); return;
	}
	if (turrents && vars::object::traps[5]) 
	{
		other::DrawObject(entity, vars::object::show_traps_distance, vars::object::max_traps_distance, _(L"Auto Turret"), { 191, 81, 73, 255 }, vars::object::show_traps_ico, _(L"autoturret.png")); return;
	}
	/*if (stash && vars::object::mainobjects[0]) 
	{
		other::DrawStash(entity, vars::object::show_mainobjects_distance, vars::object::max_mainobjects_distance); return;
	}*/
	//Home Objects
	if (vars::object::homeobjects[0] && tool_cupboard)  
	{
		other::DrawToolCupboard(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance); return;
	}
	if (vars::object::homeobjects[1] && furnace) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Furnace"), { 255, 160, 122, 255 }, vars::object::show_homeobjects_ico, _(L"furnace.png")); return;
	}
	if (vars::object::homeobjects[2] && furnace_large) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Big Furnace"), { 255, 99, 71, 255 }, vars::object::show_homeobjects_ico, _(L"furnace.large.png")); return;
	}
	if (vars::object::homeobjects[3] && bed) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Bed"), { 211, 211, 211, 255 }, vars::object::show_homeobjects_ico, _(L"bed.png")); return;
	}
	if (vars::object::homeobjects[4] && large_woodbox) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Large Wood Box"), { 222, 184, 135, 255 }, vars::object::show_homeobjects_ico, _(L"box.wooden.large.png")); return;
	}
	if (vars::object::homeobjects[5] && campfire) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Camp Fire"), { 128, 128, 128, 255 }, vars::object::show_homeobjects_ico, _(L"campfire.png")); return;
	}
	if (vars::object::homeobjects[6] && researchtable) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Vending Machine"), { 100, 149, 237, 255 }, vars::object::show_homeobjects_ico, _(L"vending.machine.png")); return;
	}
	if (vars::object::homeobjects[7] && vendingmachine) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Research Table"), { 30, 144, 255, 255 }, vars::object::show_homeobjects_ico, _(L"research.table.png")); return;
	}
	if (vars::object::homeobjects[8] && workbench1) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Workbench Level 1"), { 205, 133, 63, 255 }, vars::object::show_homeobjects_ico, _(L"workbench1.png")); return;
	}
	if (vars::object::homeobjects[9] && workbench2) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Workbench Level 2"), { 169, 169, 169, 255 }, vars::object::show_homeobjects_ico, _(L"workbench2.png")); return;
	}
	if (vars::object::homeobjects[10] && workbench3) 
	{
		other::DrawObject(entity, vars::object::show_homeobjects_distance, vars::object::max_homeobjects_distance, _(L"Workbench Level 3"), { 46, 139, 87, 255 }, vars::object::show_homeobjects_ico, _(L"workbench3.png")); return;
	}
	//Misc
	if (vars::object::others[0] && hemp) 
	{
		other::DrawObject(entity, vars::object::show_others_distance, vars::object::max_others_distance, _(L"Hemp"), { 60, 225, 60, 255 }, vars::object::show_others_ico, _(L"clone.hemp.png")); return;
	}
	if (vars::object::others[1] && corn) 
	{
		other::DrawObject(entity, vars::object::show_others_distance, vars::object::max_others_distance, _(L"Corn"), { 60, 225, 60, 255 }, vars::object::show_others_ico, _(L"corn.png")); return;
	}
	if (vars::object::others[2] && potato) 
	{
		other::DrawObject(entity, vars::object::show_others_distance, vars::object::max_others_distance, _(L"Potato"), { 60, 225, 60, 255 }, vars::object::show_others_ico, _(L"potato.png")); return;
	}
	if (vars::object::others[3] && pumpkin) 
	{
		other::DrawObject(entity, vars::object::show_others_distance, vars::object::max_others_distance, _(L"Pumpkin"), { 60, 225, 60, 255 }, vars::object::show_others_ico, _(L"pumpkin.png")); return;
	}
	if (vars::object::others[4] && mushroom) 
	{
		other::DrawObject(entity, vars::object::show_others_distance, vars::object::max_others_distance, _(L"Mushroom"), { 60, 225, 60, 255 }, vars::object::show_others_ico, _(L"mushroom.png")); return;
	}
	if (vars::object::others[5] && diesel)
	{
		other::DrawObject(entity, vars::object::show_others_distance, vars::object::max_others_distance, _(L"DieselBarrel"), { 20, 20, 20, 255 }, vars::object::show_others_ico, _(L"diesel_barrel.png")); return;
	}
	if (vars::object::mainobjects[0] && corpse)
	{
		other::DrawObject(entity, vars::object::show_mainobjects_distance, vars::object::max_mainobjects_distance, _(L"Corpse"), { 255, 0, 0, 255 }, false, _(L"")); return;
	}
	if (vars::object::mainobjects[1] && backpack)
	{
		other::DrawObject(entity, vars::object::show_mainobjects_distance, vars::object::max_mainobjects_distance, _(L"BackPack"), { 255, 66, 184, 255 },false, _(L"")); return;
	}
	if (vars::object::mainobjects[2] && dropped_items)
	{
		other::DroppedItems(entity, vars::object::show_mainobjects_distance, vars::object::max_mainobjects_distance, vars::object::show_dropeeditems_ico); return;
	}
	if (vars::object::mainobjects[3] && treasures) {
		MetalDetectorSource* metalDetectorSource = (MetalDetectorSource*)entity;
		if (metalDetectorSource) {
			List<Vector3>* treasureList = metalDetectorSource->SpawnLocations();
			if (treasureList) {
				int locationAmount = treasureList->get_size();
				for (int treasureIndex = 0; treasureIndex < locationAmount; treasureIndex++) {
					Vector3 treasurePosition = treasureList->GetArray(treasureIndex);
					if (!LineOfSight(treasurePosition + Vector3(0, 0.5, 0), treasurePosition - Vector3(0, 0.5, 0), true))
						other::DrawObject(nullptr, vars::object::show_mainobjects_distance, vars::object::max_mainobjects_distance, _(L"Treasure"), { 50, 205, 50, 255 }, false, _(L""), false, treasurePosition);
				}
			}
		}
		return;
	}
	if (vars::localplayer::stoprecycler) {
		if (stop_recycler) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_recycler_dist) {
				objects::closest_recycler_see = true;
				objects::closest_recycler = entity;
				objects::closest_recycler_dist = dist;
			}
			return;
		}
	}

	if (vars::weapon::alwayshotspot || vars::weapon::autofarmtree || vars::weapon::autofarmore) {
		if (u_crt::m_strstr(classname, _("OreResourceEntity"))) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_OreResourceEntity_dist) {
				objects::closest_OreResourceEntity_see = true;
				objects::closest_OreResourceEntity = entity;
				objects::closest_OreResourceEntity_dist = dist;
			}
			return;
		}
		if (u_crt::m_strstr(classname, _("OreHotSpot"))) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_OreHotSpot_dist) {
				objects::closest_OreHotSpot_see = true;
				objects::closest_OreHotSpot = entity;
				objects::closest_OreHotSpot_dist = dist;
			}
			return;
		}
		if (u_crt::m_strstr(classname, _("TreeEntity"))) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_TreeEntity_dist) {
				objects::closest_TreeEntity_see = true;
				objects::closest_TreeEntity = entity;
				objects::closest_TreeEntity_dist = dist;
			}
			return;
		}
		if (u_crt::m_strstr(classname, _("TreeMarker"))) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_TreeMarker_dist) {
				objects::closest_TreeMarker_see = true;
				objects::closest_TreeMarker = entity;
				objects::closest_TreeMarker_dist = dist;
			}
			return;
		}
	}
	if (vars::localplayer::auto_upgrade) {
		if (u_crt::m_strstr(classname, _("BuildingBlock"))) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_BuildingBlock_dist) {
				objects::closest_BuildingBlock_see = true;
				objects::closest_BuildingBlock = entity;
				objects::closest_BuildingBlock_dist = dist;
			}
			return;
		}
	}
	if (vars::localplayer::silentcollectiblet) {
		if (u_crt::m_strstr(classname, _("CollectibleEntity"))) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_CollectibleEntity_dist) {
				objects::closest_CollectibleEntity_see = true;
				objects::closest_CollectibleEntity = entity;
				objects::closest_CollectibleEntity_dist = dist;
			}
			return;
		}
	}
	if (vars::localplayer::doorspammer) {
		if (u_crt::m_strstr(classname, _("Door"))) {
			float dist = LocalPos.Distance(entity->transform()->position());
			if (dist < 3 && dist < objects::closest_Door_dist) {
				objects::closest_Door_see = true;
				objects::closest_Door = entity;
				objects::closest_Door_dist = dist;
			}
			return;
		}
	}
	if (patrol_heli_copter)
	{
		target_heli = entity;
		objects::target_heli_see = true;
		return;
	}
	if (vars::localplayer::silentturret && turrents)
	{
		float dist = LocalPos.Distance(entity->transform()->position());
		if (dist < 3 && dist < objects::closest_turret_dist) {
			objects::closest_turret_see = true;
			objects::closest_turret = entity;
			objects::closest_turret_dist = dist;
		}
		return;
	}
}

//void OOF(BasePlayer* ply) {
//	if (vars::esp::oofindicators) {
//		Vector3 local = MainCamera::Camera()->position();
//		float y = local.x - ply->GetBoneByID(head).x;
//		float x = local.z - ply->GetBoneByID(head).z;
//		Vector3 eulerAngles = math::euler_angles(MainCamera::Camera()->rotation());
//		float angleYawRad = math::atan(y, x) * 57.29578f - 180.f - eulerAngles.y;
//		Vector2 tp0 = math::calculate_rotation_point(angleYawRad, 255.f, screen_center.x, screen_center.y, 170.f + 50.f);
//		Vector2 tp1 = math::calculate_rotation_point(angleYawRad + 2.f, 255.f, screen_center.x, screen_center.y, 158.f + 50.f);
//		Vector2 tp2 = math::calculate_rotation_point(angleYawRad, 255.f, screen_center.x, screen_center.y, 163.f + 50.f);
//		Vector2 tp3 = math::calculate_rotation_point(angleYawRad - 2.f, 255.f, screen_center.x, screen_center.y, 158.f + 50.f);
//		Vector2 tp5 = math::calculate_rotation_point(angleYawRad, 255.f, screen_center.x, screen_center.y, 130.f + 50.f);
//
//
//		u_render::drawline({ tp0.x, tp0.y }, { tp1.x, tp1.y }, Color(0, 0, 0, (float)pulsation(50, 255)), 3.6);
//		u_render::drawline({ tp1.x, tp1.y }, { tp2.x, tp2.y }, Color(0, 0, 0, (float)pulsation(50, 255)), 3.6);
//		u_render::drawline({ tp2.x, tp2.y }, { tp3.x, tp3.y }, Color(0, 0, 0, (float)pulsation(50, 255)), 3.6);
//		u_render::drawline({ tp3.x, tp3.y }, { tp0.x, tp0.y }, Color(0, 0, 0, (float)pulsation(50, 255)), 3.6);
//
//		u_render::drawline({ tp0.x, tp0.y }, { tp1.x, tp1.y }, Color(vars::esp::namecolor.r, vars::esp::namecolor.g, vars::esp::namecolor.b, (float)pulsation(50, 255)), 1.2);
//		u_render::drawline({ tp1.x, tp1.y }, { tp2.x, tp2.y }, Color(vars::esp::namecolor.r, vars::esp::namecolor.g, vars::esp::namecolor.b, (float)pulsation(50, 255)), 1.2);
//		u_render::drawline({ tp2.x, tp2.y }, { tp3.x, tp3.y }, Color(vars::esp::namecolor.r, vars::esp::namecolor.g, vars::esp::namecolor.b, (float)pulsation(50, 255)), 1.2);
//		u_render::drawline({ tp3.x, tp3.y }, { tp0.x, tp0.y }, Color(vars::esp::namecolor.r, vars::esp::namecolor.g, vars::esp::namecolor.b, (float)pulsation(50, 255)), 1.2);
//	}
//}

void esp_loop(BasePlayer* entity) {

	if (!entity || (uintptr_t)entity < 0x10000) return;
	
	
	
	if (entity->health() <= 0.0f) return;
	
		auto playerModel = entity->playerModel();
	if (!playerModel || (uintptr_t)playerModel < 0x10000) return;
	

	auto eyes = entity->eyes();
	if (!eyes || (uintptr_t)eyes < 0x10000) return;
	
	if ((playerModel->isNpc() && !vars::esp::show_choose[1]) ||
		(!playerModel->isNpc() && !vars::esp::show_choose[0]) ||
		(entity->is_sleeping() && !vars::esp::show_choose[5]) ||
		(entity->InSafeZone() && !vars::esp::show_choose[3]) ||
		(entity->is_wounded() && !vars::esp::show_choose[2]) ||
		(entity->is_dead() && !vars::esp::show_choose[6]) ||
		(local_player->is_teammate(entity) && !vars::esp::show_choose[4])) return;
	
	if (false) { 
	}
	
	oofind(entity);
	
	
	if (false) { 
	}
	
	draw_radar(entity);
	
	if (false) { 
	}
	
	player_chams(entity);
	if (vars::misc::look_allert)
	{
		if (false) { 
		}
		
		
		auto eyes_check = entity->eyes();
		if (!eyes_check || (uintptr_t)eyes_check < 0x10000) {
			if (false) { 
			}
			
			goto skip_look_allert;
		}
		
		auto playerpos = entity->GetBoneByID(head);
		if (playerpos.is_empty()) {
			if (false) { 
			}
			goto skip_look_allert;
		}
		
		auto localpos = local_player->GetBoneByID(head);
		if (localpos.is_empty()) {
			if (false) { 
			}
			goto skip_look_allert;
		}
		
		auto distance = playerpos.Distance(localpos);
		auto fwd = playerpos + (eyes_check->bodyforward() * distance);

		auto dist = fwd.Distance(localpos);
		auto r = (distance / 50.f); r = (r < 1.f ? 1.f : r);
		if (dist < r)
		{
			wchar_t namechar[256];
			il2cpp::methods::f_swprint(namechar, _(L"%s is looking at you!"), entity->name());
			u_render::text(Vector2(screen_center.x, screen_center.y + 30), namechar, { 255, 0, 0, 255 }, true, 11, vars::esp::outline);
		}
		
		if (false) { 
		}
	}
	skip_look_allert:
	
	
	if (false) { 
	}
	box_bounds bounds;
	Vector3 player_head_pos;
	Vector3 body_forward;
	struct bone_t {
		Vector3 screen;
		int8_t index;
		Vector3 world_position;
	};
	std::initializer_list<bone_t> bones = {
		bone_t{ Vector3{}, 17, Vector3{} }, bone_t{ Vector3{}, 18, Vector3{} },
		bone_t{ Vector3{}, 15, Vector3{} }, bone_t{ Vector3{}, 14, Vector3{} },
		bone_t{ Vector3{}, 1, Vector3{} },  bone_t{ Vector3{}, 2, Vector3{} },
		bone_t{ Vector3{}, 3, Vector3{} },  bone_t{ Vector3{}, 6, Vector3{} },
		bone_t{ Vector3{}, 5, Vector3{} },  bone_t{ Vector3{}, 21, Vector3{} },
		bone_t{ Vector3{}, 23, Vector3{} }, bone_t{ Vector3{}, 48, Vector3{} },
		bone_t{ Vector3{}, 24, Vector3{} }, bone_t{ Vector3{}, 25, Vector3{} },
		bone_t{ Vector3{}, 26, Vector3{} }, bone_t{ Vector3{}, 27, Vector3{} },
		bone_t{ Vector3{}, 55, Vector3{} }, bone_t{ Vector3{}, 56, Vector3{} },
		bone_t{ Vector3{}, 57, Vector3{} }, bone_t{ Vector3{}, 76, Vector3{} }
	};
	const auto get_bounds = [&](box_bounds& out, float expand = 0) -> bool {
		if (false) { 
		}
		
		bounds = { FLT_MAX, FLT_MIN, FLT_MAX, FLT_MIN };

		for (auto bone : bones) {
			
			auto transform = entity->GetTransform(bone.index);
			if (!transform) {
				if (false) { 
				}
				continue;
			}

			bone.world_position = transform->position();

			if (bone.index == 48)
				bone.world_position.y += 0.2f;
			bone.screen = other::WorldToScreen(bone.world_position);
			if (bone.screen.x < bounds.left)
				bounds.left = bone.screen.x;
			if (bone.screen.x > bounds.right)
				bounds.right = bone.screen.x;
			if (bone.screen.y < bounds.top)
				bounds.top = bone.screen.y;
			if (bone.screen.y > bounds.bottom)
				bounds.bottom = bone.screen.y;
		}

		if (bounds.left == FLT_MAX) {
			if (false) { 
			}
			return false;
		}
		if (bounds.right == FLT_MIN) {
			if (false) { 
			}
			return false;
		}
		if (bounds.top == FLT_MAX) {
			if (false) { 
			}
			return false;
		}
		if (bounds.bottom == FLT_MIN) {
			if (false) { 
			}
			return false;
		}

		bounds.left -= expand;
		bounds.right += expand;
		bounds.top -= expand;
		bounds.bottom += expand;

		out = bounds;

		if (false) {
		}
		return true;
		};
	if (get_bounds(bounds, 4)) {
		if (false) { 
		}
		
		float box_width = bounds.right - bounds.left;
		float box_height = bounds.bottom - bounds.top;

		Vector2 topPos = { bounds.left + box_width / 2 , bounds.top - 10.f };
		Vector2 footPos = { bounds.left + box_width / 2, bounds.bottom + 10.f };

		//if (LineOfSight(MainCamera::Camera()->position(), entity->eyes()->position())) ccolor = {10,10,30,255);
		//else ccolor = {255, 255, 255, 255};
		if (vars::esp::box) {
			if (false) { 
			}
			if (vars::esp::box_mode == 0)
			{
				u_render::texturebox({ bounds.left, bounds.top }, { box_width, box_height }, vars::esp::boxcolor, 1);
				if (vars::esp::outline) {
					u_render::texturebox({ bounds.left - 1, bounds.top - 1 }, { box_width + 2, box_height + 2 }, {0, 0, 0, 255}, 1);
					u_render::texturebox({ bounds.left + 1, bounds.top + 1 }, { box_width - 2, box_height - 2 }, {0, 0, 0, 255}, 1);
				}
			}
			if (vars::esp::box_mode == 1)
			{
				if (vars::esp::outline) {
					u_render::texturebox({ bounds.left - 1, bounds.top - 1 }, { box_width / 4 + 2, 3 }, {0, 0, 0, 255});
					u_render::texturebox({ bounds.left + box_width - 1, bounds.top - 1 }, { -(box_width / 4) , 3 }, {0, 0, 0, 255});
					u_render::texturebox({ bounds.left - 1, bounds.top - 1 }, { 3 ,box_height / 4 + 2 }, {0, 0, 0, 255});
					u_render::texturebox({ bounds.left - 1, bounds.top + box_height - 1 }, { 3, -(box_height / 4) }, {0, 0, 0, 255});
					u_render::texturebox({ bounds.left - 1, bounds.top + box_height - 1 }, { box_width / 4 + 2, 3 }, {0, 0, 0, 255});
					u_render::texturebox({ bounds.left + box_width + 2, bounds.top + box_height - 1 }, { -(box_width / 4 + 3), 3 }, {0, 0, 0, 255});
					u_render::texturebox({ bounds.left + box_width - 1, bounds.top - 1 }, { 3, box_height / 4 + 2 }, {0, 0, 0, 255});
					u_render::texturebox({ bounds.left + box_width - 1, bounds.top + box_height + 1 }, { 3, -(box_height / 4 + 2) }, {0, 0, 0, 255});
				}

				u_render::texturebox({ bounds.left, bounds.top }, { box_width / 4, 1 }, vars::esp::boxcolor);
				u_render::texturebox({ bounds.left + box_width, bounds.top }, { -(box_width / 4), 1 }, vars::esp::boxcolor);
				u_render::texturebox({ bounds.left, bounds.top }, { 1,box_height / 4 }, vars::esp::boxcolor);
				u_render::texturebox({ bounds.left, bounds.top + box_height }, { 1, -(box_height / 4) }, vars::esp::boxcolor);
				u_render::texturebox({ bounds.left, bounds.top + box_height }, { box_width / 4, 1 }, vars::esp::boxcolor);
				u_render::texturebox({ bounds.left + box_width, bounds.top + box_height }, { -(box_width / 4), 1 }, vars::esp::boxcolor);
				u_render::texturebox({ bounds.left + box_width, bounds.top }, { 1, box_height / 4 }, vars::esp::boxcolor);
				u_render::texturebox({ bounds.left + box_width, bounds.top + box_height + 1 }, { 1, -(box_height / 4 + 1) }, vars::esp::boxcolor);
			}
		}


		if (vars::esp::healthbar)
		{
			int health = (int)entity->health();
			Color healthcolor;
			if (health > 50) healthcolor = {0, 255, 0, 255};
			else if (health > 25) healthcolor = {245, 245, 4, 255};
			else healthcolor = {255, 0, 0, 255};
			float maxheal = entity->playerModel()->isNpc() ? entity->maxHealth() : 100.f;
			const auto health_pc = min((float)entity->health() / maxheal, 1);
			const auto height = box_height * health_pc;
			u_render::texturebox({ bounds.left - 6, bounds.top - 1 }, { 4 , box_height + 2 }, {0, 0, 0, 200});
			u_render::texturebox({ bounds.left - 5, bounds.bottom }, { 2, -height }, healthcolor);
			u_render::texturebox({ bounds.left - 6, bounds.top - 1 }, { 4 , box_height + 2 }, {0, 0, 0, 255}, 1);
			wchar_t mybuf[256];
			il2cpp::methods::f_swprint(mybuf, _(L"%d"), health);
			if (health < 99)
				u_render::text({ bounds.left - 5, bounds.top + box_height - height - 2 }, mybuf, {255, 255, 255, 255}, true, 11, vars::esp::outline);
		}
		
		if (vars::esp::skeleton)
		{
		
			auto get_bone_screen = [&](BoneList bone_id) -> Vector3 {
				auto bone_pos = entity->GetBoneByID(bone_id);
				if (bone_pos.is_empty()) return Vector3::Zero();
				return other::WorldToScreen(bone_pos);
			};
			
			
			Vector3 head_scr = get_bone_screen(head);
			Vector3 neck_scr = get_bone_screen(neck);
			if (!head_scr.is_empty() && !neck_scr.is_empty())
				u_render::drawline({head_scr.x, head_scr.y}, {neck_scr.x, neck_scr.y}, vars::esp::skeletoncolor, 0.5f);
			
		
			Vector3 spine4_scr = get_bone_screen(spine4);
			if (!neck_scr.is_empty() && !spine4_scr.is_empty())
				u_render::drawline({neck_scr.x, neck_scr.y}, {spine4_scr.x, spine4_scr.y}, vars::esp::skeletoncolor, 0.5f);
			
			
			Vector3 pelvis_scr = get_bone_screen(pelvis);
			if (!spine4_scr.is_empty() && !pelvis_scr.is_empty())
				u_render::drawline({spine4_scr.x, spine4_scr.y}, {pelvis_scr.x, pelvis_scr.y}, vars::esp::skeletoncolor, 0.5f);
			
			Vector3 l_upperarm_scr = get_bone_screen(l_upperarm);
			Vector3 l_forearm_scr = get_bone_screen(l_forearm);
			Vector3 l_hand_scr = get_bone_screen(l_hand);
			if (!neck_scr.is_empty() && !l_upperarm_scr.is_empty())
				u_render::drawline({neck_scr.x, neck_scr.y}, {l_upperarm_scr.x, l_upperarm_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!l_upperarm_scr.is_empty() && !l_forearm_scr.is_empty())
				u_render::drawline({l_upperarm_scr.x, l_upperarm_scr.y}, {l_forearm_scr.x, l_forearm_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!l_forearm_scr.is_empty() && !l_hand_scr.is_empty())
				u_render::drawline({l_forearm_scr.x, l_forearm_scr.y}, {l_hand_scr.x, l_hand_scr.y}, vars::esp::skeletoncolor, 0.5f);
		
			Vector3 r_upperarm_scr = get_bone_screen(r_upperarm);
			Vector3 r_forearm_scr = get_bone_screen(r_forearm);
			Vector3 r_hand_scr = get_bone_screen(r_hand);
			if (!neck_scr.is_empty() && !r_upperarm_scr.is_empty())
				u_render::drawline({neck_scr.x, neck_scr.y}, {r_upperarm_scr.x, r_upperarm_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!r_upperarm_scr.is_empty() && !r_forearm_scr.is_empty())
				u_render::drawline({r_upperarm_scr.x, r_upperarm_scr.y}, {r_forearm_scr.x, r_forearm_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!r_forearm_scr.is_empty() && !r_hand_scr.is_empty())
				u_render::drawline({r_forearm_scr.x, r_forearm_scr.y}, {r_hand_scr.x, r_hand_scr.y}, vars::esp::skeletoncolor, 0.5f);
			
		
			Vector3 l_hip_scr = get_bone_screen(l_hip);
			Vector3 l_knee_scr = get_bone_screen(l_knee);
			Vector3 l_foot_scr = get_bone_screen(l_foot);
			if (!pelvis_scr.is_empty() && !l_hip_scr.is_empty())
				u_render::drawline({pelvis_scr.x, pelvis_scr.y}, {l_hip_scr.x, l_hip_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!l_hip_scr.is_empty() && !l_knee_scr.is_empty())
				u_render::drawline({l_hip_scr.x, l_hip_scr.y}, {l_knee_scr.x, l_knee_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!l_knee_scr.is_empty() && !l_foot_scr.is_empty())
				u_render::drawline({l_knee_scr.x, l_knee_scr.y}, {l_foot_scr.x, l_foot_scr.y}, vars::esp::skeletoncolor, 0.5f);
			
			
			Vector3 r_hip_scr = get_bone_screen(r_hip);
			Vector3 r_knee_scr = get_bone_screen(r_knee);
			Vector3 r_foot_scr = get_bone_screen(r_foot);
			if (!pelvis_scr.is_empty() && !r_hip_scr.is_empty())
				u_render::drawline({pelvis_scr.x, pelvis_scr.y}, {r_hip_scr.x, r_hip_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!r_hip_scr.is_empty() && !r_knee_scr.is_empty())
				u_render::drawline({r_hip_scr.x, r_hip_scr.y}, {r_knee_scr.x, r_knee_scr.y}, vars::esp::skeletoncolor, 0.5f);
			if (!r_knee_scr.is_empty() && !r_foot_scr.is_empty())
				u_render::drawline({r_knee_scr.x, r_knee_scr.y}, {r_foot_scr.x, r_foot_scr.y}, vars::esp::skeletoncolor, 0.5f);
		}
		if (vars::esp::distance || vars::esp::name) {
			if (false) { 
			}
			
			auto main_cam = Camera::main_camera();
			if (!main_cam || main_cam < 0x10000) {
				if (false) { 
				}
				return;
			}
			
			auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
			if (!cam_transform || (uintptr_t)cam_transform < 0x10000) {
				if (false) { 
				}
				return;
			}
			
			Vector3 cam_pos = cam_transform->position();
			auto head_transform = entity->GetTransform(head);
			if (!head_transform || (uintptr_t)head_transform < 0x10000) {
				if (false) { 
				}
				return;
			}
			
			float newDistance = cam_pos.Distance(head_transform->position());
			wchar_t namechar[256]; wchar_t distancechar[256]; wchar_t distancenamechar[256];
			il2cpp::methods::f_swprint(namechar, _(L"%s"), entity->name());
			il2cpp::methods::f_swprint(distancechar, _(L"%.1fm"), newDistance);
			il2cpp::methods::f_swprint(distancenamechar, _(L"%s [%.1fm]"), entity->name(), newDistance);
			if (vars::esp::distance && vars::esp::name)
			{
				u_render::text(topPos, distancenamechar, vars::esp::namecolor, true, 11, vars::esp::outline);
			}
			else if (vars::esp::distance)
			{
				u_render::text({ bounds.right + 3, bounds.top - 2 }, distancechar, vars::esp::distancecolor, false, 11, vars::esp::outline);
			}
			else if (vars::esp::name) {
				u_render::text(topPos, namechar, vars::esp::namecolor, true, 11, vars::esp::outline);
			}
			
			if (false) { 
			}
		}
		if (vars::esp::weapon) {
			if (false) { 
			}
			
			auto ActWeapon = entity->active_weapon();
			if (ActWeapon) {
				u_render::text(footPos, ActWeapon->weapon_name(), vars::esp::weaponcolor, true, 11, vars::esp::outline);
				footPos.y += 10;
			}
			
			if (false) { 
			}
		}
		if (vars::esp::flags)
		{
			if (false) { 
			}
			const wchar_t* CurFlag = _(L"");

			if (entity->InSafeZone()) {
				CurFlag = _(L"SafeZone");
			}
			else if (entity->isMounted()) {
				CurFlag = _(L"Mounted");
			}
			else if (entity->is_wounded()) {
				CurFlag = _(L"Wounded");
			}
			else if (!entity->playerModel()->isNpc()) {
			
				auto main_cam = Camera::main_camera();
				if (main_cam && main_cam >= 0x10000) {
					auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
					if (cam_transform && (uintptr_t)cam_transform >= 0x10000) {
						Vector3 cam_pos = cam_transform->position();
						Vector3 head_pos = entity->GetBoneByID(head);
						
						if (!head_pos.is_empty()) {
							bool is_visible = LineOfSight(cam_pos, head_pos, true);
							
							if (!entity->IsOutside()) {
								
								if (is_visible) {
									CurFlag = _(L"Visible"); 
								} else {
									CurFlag = _(L"InBase"); 
								}
							}
							else {
								
								CurFlag = _(L"Outside");
							}
						}
					}
				}
			}
			
			u_render::text(footPos, CurFlag, vars::esp::flagscolor, true, 11, vars::esp::outline);
			
			if (false) { 
			}
		}

		if (false) { 
		}
		
		auto eyes_final = entity->eyes();
		if (eyes_final && (uintptr_t)eyes_final >= 0x10000) {
			Vector3 headPos = entity->GetBoneByID(head);
			if (!headPos.is_empty()) {
				body_forward = other::WorldToScreen(headPos + (eyes_final->bodyforward()));
				player_head_pos = other::WorldToScreen(headPos);
				if (vars::esp::looking_direction)
				{
					u_render::drawline({ player_head_pos.x,player_head_pos.y }, { body_forward.x,body_forward.y }, vars::esp::looking_directioncolor, 0.5f);
				}
				
				if (false) { 
				}
			} else {
				if (false) { 
				}
			}
		} else {
			if (false) { 
			}
		}
	}
	
	if (false) { 
	}
}