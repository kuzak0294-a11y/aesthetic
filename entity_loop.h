int time_last_upd;
void entity_loop() {
	auto client_entities = il2cpp::value(_("BaseNetworkable"), _("clientEntities"), false);
	auto client_entities_list = u_mem::read<uintptr_t>(client_entities + 0x10);
	auto client_entities_value = u_mem::read<uintptr_t>(client_entities_list + 0x28);
	auto client_entities_count = u_mem::read<int>(client_entities_value + 0x10);
	auto client_entities_buffer = u_mem::read<uintptr_t>(client_entities_value + 0x18);
	if (local_player == nullptr || !client_entities_list || client_entities_count <= 1) {
		big_target_player = nullptr;
		target_player = nullptr;
		stopcamera = true;
		chams1 = nullptr;
		chams2 = nullptr;
		chams3 = nullptr;
		chams4 = nullptr;
		chams6 = nullptr;
		chams7 = nullptr;
		chams8 = nullptr;
		chams9 = nullptr;
		chams10 = nullptr;
		chams11 = nullptr;
		chams12 = nullptr;
		chams13 = nullptr;
		chams14 = nullptr;
		chams16 = nullptr;
		
		chams15 = nullptr;
		player_chams_material = nullptr;
		player_chams_shader = nullptr;
		player_chams_shader_flat = nullptr;
		return;
	}
	else {
		stopcamera = false;
	}
		
	if (target_player != nullptr && get_fov(target_player) > vars::psilent::tarer_fov) {
		target_player = nullptr;
	}

	//ENTITYLOOP:
	if (memory_client_entities_count != client_entities_count) {
		objects::closest_turret_see = false;
		objects::closest_recycler_see = false;
		objects::closest_OreResourceEntity_see = false;
		objects::closest_OreHotSpot_see = false;
		objects::closest_TreeEntity_see = false;
		objects::closest_TreeMarker_see = false;
		objects::closest_BuildingBlock_see = false;
		objects::closest_CollectibleEntity_see = false;
		objects::closest_Door_see = false;
		objects::closest_Stash_see = false;
		objects::target_heli_see = false;

		objects::closest_recycler_dist = 999;
		objects::closest_OreResourceEntity_dist = 999;
		objects::closest_OreHotSpot_dist = 999;
		objects::closest_TreeEntity_dist = 999;
		objects::closest_TreeMarker_dist = 999;
		objects::closest_BuildingBlock_dist = 999;
		objects::closest_CollectibleEntity_dist = 999;
		objects::closest_Door_dist = 999;
		objects::closest_turret_dist = 999;
		objects::closest_Stash_dist = 999;

		addedindx = 0;
		for (int i = 1; i < client_entities_count; i++) {
			auto entity = u_mem::read<uintptr_t>(client_entities_buffer + 0x20 + (i * 0x8)); if (entity <= 100000 || !isvalid(entity)) continue;
			find_cash_object(entity);
		}
		if (addedindx < 1) {
			memory_client_entities_count = 0;
			return;
		}
		wchar_t time_[256];
		float last_time = Time::time() - time_last_upd;
		il2cpp::methods::f_swprint(time_, _(L"ENTITY LOOP UPDATE | Time Since The Last Update - %.3f Sec | Total Entity - %d"), last_time, client_entities_count);

		local_player->ConsoleMessage(time_);
		time_last_upd = Time::time();

		memory_client_entities_count = client_entities_count;
	}
	
	for (int i = 0; i < addedindx; i++) {
		{
			auto entity = rustentity[i]; if (!isvalid(entity)) continue;
			auto object = u_mem::read<uintptr_t>(entity + 0x10); if (object <= 100000) continue;
			auto object_class = u_mem::read<uintptr_t>(object + 0x30); if (object_class <= 100000) continue;
			//pUncStr name = u_mem::read<pUncStr>(object_class + 0x60); if (!name) continue;
			//char* buff = name->stub;
			auto classname = (char*)u_mem::read<DWORD64>(u_mem::read<DWORD64>(u_mem::read<DWORD64>(object + 0x28)) + 0x10);
			items_loop((BasePlayer*)entity, classname);
			auto tag = u_mem::read<WORD>(object_class + 0x54);
			if (tag == 6 && (BasePlayer*)entity != local_player) {
				auto player = (BasePlayer*)entity;
				
				
				kill_effect::update_health_tracker(player);
				
				if (player->GetBoneByID(head).x == 0 || player->GetBoneByID(head).y == 0 || player->GetBoneByID(head).z == 0) continue;
				if (client_entities_count < 1) continue;
				
				esp_loop(player);
				if ((player->is_wounded() && vars::psilent::ignorepeople[0]) ||
					(player->playerModel()->isNpc() && vars::psilent::ignorepeople[1]) ||
					(player->InSafeZone() && vars::psilent::ignorepeople[2]) ||
					(local_player->is_teammate(player) && vars::psilent::ignorepeople[3]) ||
					(player->is_sleeping() && vars::psilent::ignorepeople[4]) ||
					(local_player->eyes() && LineOfSight(local_player->eyes()->position(), player->GetBoneByID(head)) && vars::psilent::ignorepeople[5])) continue;
				if (get_fov(player) < vars::psilent::tarer_fov) {
					if (target_player == nullptr)
						target_player = player;
					else
						if (get_fov(target_player) > get_fov(player))
							target_player = player;
				}
				if (big_target_player == nullptr)
					big_target_player = player;
				else
					if (get_fov(big_target_player) > get_fov(player))
						big_target_player = player;
			}
		}
	}
	
	{
		auto entity = (uintptr_t)target_player;
		auto object = u_mem::read<uintptr_t>(entity + 0x10);
		auto object_class = u_mem::read<uintptr_t>(object + 0x30);
		auto tag = u_mem::read<WORD>(object_class + 0x54);
		if (tag != 6) target_player = nullptr;
	}
	{
		auto entity = (uintptr_t)big_target_player;
		auto object = u_mem::read<uintptr_t>(entity + 0x10);
		auto object_class = u_mem::read<uintptr_t>(object + 0x30);
		auto tag = u_mem::read<WORD>(object_class + 0x54);
		if (tag != 6) big_target_player = nullptr;
	}
	draw_targetbelt();
	

	ChatSpammer();
	

	if (vars::misc::fakelag && vars::misc::fakelag_indicator) {
		fakelag::draw_indicator();
	}
	
	if (target_player != nullptr)
	{
		if ((target_player->is_wounded() && vars::psilent::ignorepeople[0]) ||
			(target_player->playerModel()->isNpc() && vars::psilent::ignorepeople[1]) ||
			(target_player->InSafeZone() && vars::psilent::ignorepeople[2]) ||
			(local_player->is_teammate(target_player) && vars::psilent::ignorepeople[3]) ||
			(target_player->is_sleeping() && vars::psilent::ignorepeople[4]) ||
			(local_player->eyes() && LineOfSight(local_player->eyes()->position(), target_player->GetBoneByID(head)) && vars::psilent::ignorepeople[5])
			|| (target_player->is_dead())) {
			target_player = nullptr;
		}
		else
		{
			if (vars::psilent::target_line)
			{
				Vector3 player_head_pos;
				player_head_pos = other::WorldToScreen(target_player->GetBoneByID(head));
				u_render::drawline({ player_head_pos.x,player_head_pos.y }, screen_center, { vars::psilent::target_line_color.r, vars::psilent::target_line_color.g, vars::psilent::target_line_color.b, vars::psilent::target_line_color.a }, 0.7);
			}
		}
	}
	if (big_target_player != nullptr)
	{
		if ((big_target_player->is_wounded() && vars::psilent::ignorepeople[0]) ||
			(big_target_player->playerModel()->isNpc() && vars::psilent::ignorepeople[1]) ||
			(big_target_player->InSafeZone() && vars::psilent::ignorepeople[2]) ||
			(local_player->is_teammate(big_target_player) && vars::psilent::ignorepeople[3]) ||
			(big_target_player->is_sleeping() && vars::psilent::ignorepeople[4]) ||
			(local_player->eyes() && LineOfSight(local_player->eyes()->position(), big_target_player->GetBoneByID(head)) && vars::psilent::ignorepeople[5])
			|| (big_target_player->is_dead())) {
			big_target_player = nullptr;
		}
	}
}