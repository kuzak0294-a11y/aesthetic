bool menuinitilizated, mouse_state, old_mouse_state, menu_opened, colorboxdraw;
Vector2 menu_position, nexttabpos, old_mouse_pos, mouse_pos, next_item_pos, colorpicker_mouse;
float menu_alfa = 255.f, tab_menu_alfa = 255.f, other_menu_alfa = 255.f, colorbox_animation;
float combobox_items_aniamtion[20], combobox_aniamtion[20], beginchild_scroll_value_previev[11];
float writebox_a_aniamtion[20], combobox_a_aniamtion[20], slider_a_aniamtion[50];
EventType event_type; KeyCode active_key;
Color colorpickercolor_1, colorpickercolor_2;
static int active_tab = 0;
float elements_a_aniamtion[5];
static int language = 0;
namespace u_elements {
	inline const wchar_t* getkey(KeyCode iKey)
	{
		switch (iKey)
		{
		case 0:
			return _(L"-");
		case 8:
			return _(L"Backspace");
		case 127:
			return _(L"Delete");
		case 9:
			return _(L"Tab");
		case 12:
			return _(L"Clear");
		case 13:
			return _(L"Return");
		case 19:
			return _(L"Pause");
		case 27:
			return _(L"Escape");
		case 32:
			return _(L"Space");
		case 256:
			return _(L"Keypad0");
		case 257:
			return _(L"Keypad1");
		case 258:
			return _(L"Keypad2");
		case 259:
			return _(L"Keypad3");
		case 260:
			return _(L"Keypad4");
		case 261:
			return _(L"Keypad5");
		case 262:
			return _(L"Keypad6");
		case 263:
			return _(L"Keypad7");
		case 264:
			return _(L"Keypad8");
		case 265:
			return _(L"Keypad9");
		case 266:
			return _(L"KeypadPeriod");
		case 267:
			return _(L"KeypadDivide");
		case 268:
			return _(L"KeypadMultiply");
		case 269:
			return _(L"KeypadMinus");
		case 270:
			return _(L"KeypadPlus");
		case 271:
			return _(L"KeypadEnter");
		case 272:
			return _(L"KeypadEquals");
		case 273:
			return _(L"UpArrow");
		case 274:
			return _(L"DownArrow");
		case 275:
			return _(L"RightArrow");
		case 276:
			return _(L"LeftArrow");
		case 277:
			return _(L"Insert");
		case 278:
			return _(L"Home");
		case 279:
			return _(L"End");
		case 280:
			return _(L"PageUp");
		case 281:
			return _(L"PageDown");
		case 282:
			return _(L"F1");
		case 283:
			return _(L"F2");
		case 284:
			return _(L"F3");
		case 285:
			return _(L"F4");
		case 286:
			return _(L"F5");
		case 287:
			return _(L"F6");
		case 288:
			return _(L"F7");
		case 289:
			return _(L"F8");
		case 290:
			return _(L"F9");
		case 291:
			return _(L"F10");
		case 292:
			return _(L"F11");
		case 293:
			return _(L"F12");
		case 294:
			return _(L"F13");
		case 295:
			return _(L"F14");
		case 296:
			return _(L"F15");
		case 48:
			return _(L"0");
		case 49:
			return _(L"1");
		case 50:
			return _(L"2");
		case 51:
			return _(L"3");
		case 52:
			return _(L"4");
		case 53:
			return _(L"5");
		case 54:
			return _(L"6");
		case 55:
			return _(L"7");
		case 56:
			return _(L"8");
		case 57:
			return _(L"9");
		case 33:
			return _(L"Exclaim");
		case 34:
			return _(L"DoubleQuote");
		case 35:
			return _(L"Hash");
		case 36:
			return _(L"Dollar");
		case 37:
			return _(L"Percent");
		case 38:
			return _(L"Ampersand");
		case 39:
			return _(L"Quote");
		case 40:
			return _(L"LeftParen");
		case 41:
			return _(L"RightParen");
		case 42:
			return _(L"Asterisk");
		case 43:
			return _(L"Plus");
		case 44:
			return _(L"Comma");
		case 45:
			return _(L"Minus");
		case 46:
			return _(L"Period");
		case 47:
			return _(L"Slash");
		case 58:
			return _(L"Colon");
		case 59:
			return _(L"Semicolon");
		case 60:
			return _(L"Less");
		case 61:
			return _(L"Equals");
		case 62:
			return _(L"Greater");
		case 63:
			return _(L"Question");
		case 64:
			return _(L"At");
		case 91:
			return _(L"LeftBracket");
		case 92:
			return _(L"Backslash");
		case 93:
			return _(L"RightBracket");
		case 94:
			return _(L"Caret");
		case 95:
			return _(L"Underscore");
		case 96:
			return _(L"BackQuote");
		case 97:
			return _(L"A");
		case 98:
			return _(L"B");
		case 99:
			return _(L"C");
		case 100:
			return _(L"D");
		case 101:
			return _(L"E");
		case 102:
			return _(L"F");
		case 103:
			return _(L"G");
		case 104:
			return _(L"H");
		case 105:
			return _(L"I");
		case 106:
			return _(L"J");
		case 107:
			return _(L"K");
		case 108:
			return _(L"L");
		case 109:
			return _(L"M");
		case 110:
			return _(L"N");
		case 111:
			return _(L"O");
		case 112:
			return _(L"P");
		case 113:
			return _(L"Q");
		case 114:
			return _(L"R");
		case 115:
			return _(L"S");
		case 116:
			return _(L"T");
		case 117:
			return _(L"U");
		case 118:
			return _(L"V");
		case 119:
			return _(L"W");
		case 120:
			return _(L"X");
		case 121:
			return _(L"Y");
		case 122:
			return _(L"Z");
		case 123:
			return _(L"LeftCurlyBracket");
		case 124:
			return _(L"Pipe");
		case 125:
			return _(L"RightCurlyBracket");
		case 126:
			return _(L"Tilde");
		case 300:
			return _(L"Numlock");
		case 301:
			return _(L"CapsLock");
		case 302:
			return _(L"ScrollLock");
		case 303:
			return _(L"RightShift");
		case 304:
			return _(L"LeftShift");
		case 305:
			return _(L"RightControl");
		case 306:
			return _(L"LeftControl");
		case 307:
			return _(L"RightAlt");
		case 308:
			return _(L"LeftAlt");
		case 309:
			return _(L"Left Windows");
		case 310:
			return _(L"Right Windows");
		case 311:
			return _(L"LeftWindows");
		case 312:
			return _(L"RightWindows");
		case 313:
			return _(L"AltGr");
		case 315:
			return _(L"Help");
		case 316:
			return _(L"Print");
		case 317:
			return _(L"SysReq");
		case 318:
			return _(L"Break");
		case 319:
			return _(L"Menu");
		case 323:
			return _(L"Mouse0");
		case 324:
			return _(L"Mouse1");
		case 325:
			return _(L"Mouse2");
		case 326:
			return _(L"Mouse3");
		case 327:
			return _(L"Mouse4");
		case 328:
			return _(L"Mouse5");
		case 329:
			return _(L"Mouse6");
		}
		char szValue[64];
		wchar_t wszValue[64];
		itoass(static_cast<float>(iKey), szValue, 10);
		AnsiToUnicode(szValue, wszValue);

		return wszValue;
	}
	void init() {
		u_render::InitializeAADrawing();
		
		if (label && skin) {
			return;
		}
		
		defoultcolorpickercolor = { -1, -1, -1, -1 };
		
		skin = GUI::skin();
		if (!skin) {
			crash_logger::log_error("u_elements::init: GUI::skin() returned NULL");
			return;
		}
		
		label = u_mem::read<uintptr_t>(skin + 0x38);
		
		if (!label || label < 0x10000) {
			crash_logger::log_error("u_elements::init: Invalid label pointer: 0x%p", (void*)label);
			return;
		}

		// Используем стандартный шрифт Unity
		GUIStyle::alignment(label, 0);
		GUIStyle::fontsize(label, 10);
		GUI::color({ 1, 1, 1, 1 });
	}
	
	void showanimation(bool active) {
		{
			u_render::text({ 10, 5 }, (_(L"Aesthetic.")), { 255,255,255,255 }, false, 14);
			u_render::text({ 10 + 66, 5 }, (_(L"Recode")), { 97, 97, 189,255 }, false, 14);
		}
		// Анимация альфа-канала меню
		if (active) {
			if (other_menu_alfa < 253) {
				menu_alfa = Mathf::Lerp(menu_alfa, 255, 15.f * Time::deltaTime());
				if (menu_alfa > 245) {
					tab_menu_alfa = Mathf::Lerp(tab_menu_alfa, 255, 15.f * Time::deltaTime());
					if (tab_menu_alfa > 245)
						other_menu_alfa = Mathf::Lerp(other_menu_alfa, 255, 15.f * Time::deltaTime());
				}
			}
			else if (other_menu_alfa != 255) menu_alfa = 255;
		}
		else {
			if (menu_alfa > 2) {
				other_menu_alfa = Mathf::Lerp(other_menu_alfa, 0, 15.f * Time::deltaTime());
				if (other_menu_alfa < 5) {
					tab_menu_alfa = Mathf::Lerp(tab_menu_alfa, 0, 15.f * Time::deltaTime());
					if (tab_menu_alfa < 5)
						menu_alfa = Mathf::Lerp(menu_alfa, 0, 15.f * Time::deltaTime());
				}
			}
			else if (menu_alfa != 0) menu_alfa = 0;
		}

		if (vars::antihack::speedhackindicator) {
			if (menu_alfa < 222 && vars::antihack::speedhack_cur > 0) {
				const auto percentage = min(vars::antihack::speedhack_cur, 1.f);
				u_render::texturebox({ vars::antihack::speedhack_pos.x - 100.f,vars::antihack::speedhack_pos.y - 5.f }, { 200, 10 }, { 0.f, 0.f, 0.f, 255 }, 0, 3);
				u_render::texturebox({ vars::antihack::speedhack_pos.x - 100.f,vars::antihack::speedhack_pos.y - 4.f }, { 200 * percentage, 8 }, { 0, 200, 0, 255 }, 0, 3);
			}
			if (menu_alfa >= 3) {
				u_render::texturebox({ vars::antihack::speedhack_pos.x - 100.f,vars::antihack::speedhack_pos.y - 5.f }, { 200, 10 }, { 0.f, 0.f, 0.f, 255 }, 0, 3);
				u_render::text({ vars::antihack::speedhack_pos.x,vars::antihack::speedhack_pos.y + 15 }, (_(L"SpeedHack Indicator")), { 255,255,255,menu_alfa }, true, 13);
				u_render::text({ vars::antihack::speedhack_pos.x,vars::antihack::speedhack_pos.y - 20 }, (_(L"Click Middle Mouse for set to center")), { 255,255,255,menu_alfa * (elements_a_aniamtion[3] / 255) }, true, 12);
			}
		}
		auto baseprojectile = local_player->active_entity<BaseProjectile>();
		if (vars::weapon::autoreloadindicator) {
			if (baseprojectile) {
				if (menu_alfa < 222 && did_reload == false && time_since_last_shot <= (baseprojectile->reloadTime() - (baseprojectile->reloadTime() / 10)) && time_since_last_shot > 0)
				{
					const auto percentage = min(time_since_last_shot / (baseprojectile->reloadTime() - (baseprojectile->reloadTime() / 10)), 1.f);
					u_render::texturebox({ vars::weapon::autoreload_pos.x - 50.f,vars::weapon::autoreload_pos.y - 5.f }, { 100, 10 }, { 0.f, 0.f, 0.f, 255 }, 0, 3);
					u_render::texturebox({ vars::weapon::autoreload_pos.x - 50.f,vars::weapon::autoreload_pos.y - 4.f }, { 100 * percentage, 8 }, { 0, 200, 0, 255 }, 0, 3);
				}
			}

			if (menu_alfa >= 3) {
				u_render::texturebox({ vars::weapon::autoreload_pos.x - 50.f,vars::weapon::autoreload_pos.y - 5.f }, { 100, 10 }, { 0.f, 0.f, 0.f, menu_alfa }, 0, 3);
				u_render::text({ vars::weapon::autoreload_pos.x,vars::weapon::autoreload_pos.y + 15 }, (_(L"Reload Indicator")), { 255,255,255,menu_alfa }, true, 13);
				u_render::text({ vars::weapon::autoreload_pos.x,vars::weapon::autoreload_pos.y - 20 }, (_(L"Click Middle Mouse for set to center")), { 255,255,255,menu_alfa * (elements_a_aniamtion[2] / 255) }, true, 12);
			}
		}
		if (!baseprojectile) vars::psilent::tarer_fov = vars::psilent::setter_fov;
		if (vars::antihack::flyhackindicator) {
			if (menu_alfa < 222 && (vars::antihack::verticalflyhack > 0.02 || vars::antihack::horisontalflyhack > 0.02))
			{
				const auto horizontal_percentage = min(vars::antihack::horisontalflyhack / vars::antihack::maxhorisontalflyhack, 1.f);
				const auto vertical_percentage = min(vars::antihack::verticalflyhack / vars::antihack::maxverticalflyhack, 1.f);

				u_render::texturebox({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y - 10.5f }, { 248, 10 }, Color(0.f, 0.f, 0.f, 255.f), 0, 3.f);
				u_render::texturebox({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y - 9.5f }, { 248 * vertical_percentage, 8 }, Color(0, 200, 0, 255), 0, 3.f);

				u_render::texturebox({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y + 0.5f }, { 248, 10 }, Color(0.f, 0.f, 0.f, 255.f), 0, 3.f);
				u_render::texturebox({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y + 1.5f }, { 248 * horizontal_percentage, 8 }, Color(0, 200, 0, 255), 0, 3.f);
			}
			if (menu_alfa >= 3) {
				u_render::texturebox({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y - 10.5f }, { 248, 10 }, Color(0.f, 0.f, 0.f, menu_alfa), 0, 3.f);
				u_render::texturebox({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y + 0.5f }, { 248, 10 }, Color(0.f, 0.f, 0.f, menu_alfa), 0, 3.f);
				u_render::text({ vars::antihack::flyhack_ind_pos.x, vars::antihack::flyhack_ind_pos.y }, (_(L"FlyHack Indicator")), { 255,255,255,menu_alfa }, true, 13);
				u_render::text({ vars::antihack::flyhack_ind_pos.x, vars::antihack::flyhack_ind_pos.y - 20 }, (_(L"Click Middle Mouse for set to center")), { 255,255,255,menu_alfa * (elements_a_aniamtion[0] / 255) }, true, 12);
			}
		}
		if (vars::psilent::show_fov) {
			u_render::circle({ screen_center.x, screen_center.y }, vars::psilent::tarer_fov, vars::psilent::fov_color);
		}
		if (vars::manipulator::manipulator && vars::manipulator::manipulatorind) {
			const auto vertical_percentage = min(vars::manipulator::desync, 1.f);
			u_render::texturebox({ vars::manipulator::manipulatorind_pos.x - 5.f,vars::manipulator::manipulatorind_pos.y - 50.f }, { 10, 100 }, { 0.f, 0.f, 0.f, 255 }, 0, 3);
			u_render::texturebox({ vars::manipulator::manipulatorind_pos.x - 4.f,vars::manipulator::manipulatorind_pos.y + 49.f }, { 8, vertical_percentage * (-98) }, { 0, 200, 0, 255 }, 0, 3);
		}
		if (vars::weapon::stw_enabled && vars::weapon::stw_indicator) {
			if (Input::GetKey(vars::weapon::stw_key) && target_player) {
				u_render::text({ vars::weapon::stw_indicator_pos.x, vars::weapon::stw_indicator_pos.y }, 
					language == 0 ? (_(L"STW ACTIVE")) : (language == 1 ? (_(L"STW АКТИВЕН")) : (_(L"STW激活"))), 
					{ 255, 0, 0, 255 }, true, 16);
			}
		}
		if (vars::esp::radar) {
			u_render::circle({ vars::esp::radar_pos.x + vars::esp::radar_size,vars::esp::radar_pos.y + vars::esp::radar_size }, vars::esp::radar_size, { 21, 21, 21, 170 }, 0);
			if (menu_alfa < 222) u_render::circle({ vars::esp::radar_pos.x + vars::esp::radar_size,vars::esp::radar_pos.y + vars::esp::radar_size }, 2, { 255.f, 255.f, 255.f, 255.f }, 0);
			if (menu_alfa >= 3) u_render::text({ vars::esp::radar_pos.x + vars::esp::radar_size,vars::esp::radar_pos.y + vars::esp::radar_size }, (_(L"Radar")), { 255, 255, 255, menu_alfa }, true, min(17, vars::esp::radar_size / 3.3));
		}
		if (vars::psilent::target_belt && menu_alfa >= 3)
		{
			// Показываем текст "Target Belt" когда меню открыто
			u_render::text({ vars::psilent::belt_pos.x + vars::psilent::belt_size.x / 2, vars::psilent::belt_pos.y - 20 }, (_(L"Target Belt")), { 255,255,255,menu_alfa }, true, 13);
			
			// Рисуем пустые слоты
			float slot_size = vars::psilent::target_belt_size;
			float slot_spacing = slot_size + 5;
			float Pos = 5;
			for (int i = 0; i < 6; i++)
			{
				u_render::texturebox({ vars::psilent::belt_pos.x + Pos, vars::psilent::belt_pos.y }, { slot_size, slot_size }, {30, 30, 30, menu_alfa}, 0, 10);
				Pos += slot_spacing;
			}
		}
	}
	bool is_mouse_in_box(const Vector2& pos1, const Vector2& pos2) {
		if (old_mouse_pos.x < pos1.x || old_mouse_pos.y < pos1.y || old_mouse_pos.x > pos2.x || old_mouse_pos.y > pos2.y) return false;
		return true;
	}
	void elementanim() {
		if (u_elements::is_mouse_in_box({ menu_position.x, menu_position.y }, { menu_position.x + 790, menu_position.y + 40 })) {
			if (mouse_state && menu_opened) {
				menu_position.x += mouse_pos.x - old_mouse_pos.x;
				menu_position.y += mouse_pos.y - old_mouse_pos.y;
			}
		}
		else if (vars::psilent::target_belt && u_elements::is_mouse_in_box({ vars::psilent::belt_pos.x, vars::psilent::belt_pos.y },
			{ vars::psilent::belt_pos.x + vars::psilent::belt_size.x, vars::psilent::belt_pos.y + vars::psilent::target_belt_size })) {
			if (mouse_state && menu_opened) {
				vars::psilent::belt_pos.x += mouse_pos.x - old_mouse_pos.x;
				vars::psilent::belt_pos.y += mouse_pos.y - old_mouse_pos.y;
			}
			elements_a_aniamtion[1] = math::lerp(elements_a_aniamtion[1], 255, 4.f * Time::deltaTime());
			if (Input::GetMouseButton(2)) {
				vars::psilent::belt_pos.x = Screen::get_width() / 2 - vars::psilent::belt_size.x / 2;
			}
		}
		else if (vars::esp::radar && u_elements::is_mouse_in_box({ vars::esp::radar_pos.x, vars::esp::radar_pos.y },
			{ vars::esp::radar_pos.x + vars::esp::radar_size * 2, vars::esp::radar_pos.y + vars::esp::radar_size * 2 }) && mouse_state && menu_opened) {
			vars::esp::radar_pos.x += mouse_pos.x - old_mouse_pos.x;
			vars::esp::radar_pos.y += mouse_pos.y - old_mouse_pos.y;
		}
		else if (vars::antihack::flyhackindicator && u_elements::is_mouse_in_box({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y - 10.5f },
			{ vars::antihack::flyhack_ind_pos.x + 124, vars::antihack::flyhack_ind_pos.y + 10.5f }))
		{
			if (mouse_state && menu_opened) {
				vars::antihack::flyhack_ind_pos.x += mouse_pos.x - old_mouse_pos.x;
				vars::antihack::flyhack_ind_pos.y += mouse_pos.y - old_mouse_pos.y;
			}
			elements_a_aniamtion[0] = math::lerp(elements_a_aniamtion[0], 255, 4.f * Time::deltaTime());
			if (Input::GetMouseButton(2)) {
				vars::antihack::flyhack_ind_pos.x = Screen::get_width() / 2;
			}
		}
		else if (vars::weapon::autoreloadindicator && u_elements::is_mouse_in_box({ vars::weapon::autoreload_pos.x - 50.f, vars::weapon::autoreload_pos.y - 5.f },
			{ vars::weapon::autoreload_pos.x + 50.f, vars::weapon::autoreload_pos.y + 5.f }))
		{
			if (mouse_state && menu_opened) {
				vars::weapon::autoreload_pos.x += mouse_pos.x - old_mouse_pos.x;
				vars::weapon::autoreload_pos.y += mouse_pos.y - old_mouse_pos.y;
			}
			elements_a_aniamtion[2] = math::lerp(elements_a_aniamtion[2], 255, 4.f * Time::deltaTime());
			if (Input::GetMouseButton(2)) {
				vars::weapon::autoreload_pos.x = Screen::get_width() / 2;
			}
		}
		else if (vars::manipulator::manipulator && vars::manipulator::manipulatorind && u_elements::is_mouse_in_box({ vars::manipulator::manipulatorind_pos.x - 5.f, vars::manipulator::manipulatorind_pos.y - 50.f },
			{ vars::manipulator::manipulatorind_pos.x + 5.f, vars::manipulator::manipulatorind_pos.y + 50.f })) {
			if (mouse_state && menu_opened) {
				vars::manipulator::manipulatorind_pos.x += mouse_pos.x - old_mouse_pos.x;
				vars::manipulator::manipulatorind_pos.y += mouse_pos.y - old_mouse_pos.y;
			}
		}
		else if (vars::weapon::stw_enabled && vars::weapon::stw_indicator && u_elements::is_mouse_in_box({ vars::weapon::stw_indicator_pos.x - 50.f, vars::weapon::stw_indicator_pos.y - 10.f },
			{ vars::weapon::stw_indicator_pos.x + 50.f, vars::weapon::stw_indicator_pos.y + 10.f })) {
			if (mouse_state && menu_opened) {
				vars::weapon::stw_indicator_pos.x += mouse_pos.x - old_mouse_pos.x;
				vars::weapon::stw_indicator_pos.y += mouse_pos.y - old_mouse_pos.y;
			}
		}
		else if (vars::antihack::speedhackindicator && u_elements::is_mouse_in_box({ vars::antihack::speedhack_pos.x - 100.f, vars::antihack::speedhack_pos.y - 10.f },
			{ vars::antihack::speedhack_pos.x + 100.f, vars::antihack::speedhack_pos.y + 10.f })) {
			if (mouse_state && menu_opened) {
				vars::antihack::speedhack_pos.x += mouse_pos.x - old_mouse_pos.x;
				vars::antihack::speedhack_pos.y += mouse_pos.y - old_mouse_pos.y;
			}
			elements_a_aniamtion[3] = math::lerp(elements_a_aniamtion[3], 255, 4.f * Time::deltaTime());
			if (Input::GetMouseButton(2)) {
				vars::antihack::speedhack_pos.x = Screen::get_width() / 2;
			}
		}

		if (!u_elements::is_mouse_in_box({ vars::antihack::flyhack_ind_pos.x - 124, vars::antihack::flyhack_ind_pos.y - 10.5f },
			{ vars::antihack::flyhack_ind_pos.x + 124, vars::antihack::flyhack_ind_pos.y + 21 })) {
			elements_a_aniamtion[0] = math::lerp(elements_a_aniamtion[0], 0, 4.f * Time::deltaTime());
		}
		if (!u_elements::is_mouse_in_box({ vars::psilent::belt_pos.x, vars::psilent::belt_pos.y },
			{ vars::psilent::belt_pos.x + vars::psilent::belt_size.x, vars::psilent::belt_pos.y + 25 })) {
			elements_a_aniamtion[1] = math::lerp(elements_a_aniamtion[1], 0, 4.f * Time::deltaTime());
		}
		if (!u_elements::is_mouse_in_box({ vars::weapon::autoreload_pos.x - 50.f, vars::weapon::autoreload_pos.y - 5.f },
			{ vars::weapon::autoreload_pos.x + 50.f, vars::weapon::autoreload_pos.y + 5.f }))
		{
			elements_a_aniamtion[2] = math::lerp(elements_a_aniamtion[2], 0, 4.f * Time::deltaTime());
		}
		if (!u_elements::is_mouse_in_box({ vars::antihack::speedhack_pos.x - 100.f, vars::antihack::speedhack_pos.y - 10.f },
			{ vars::antihack::speedhack_pos.x + 100.f, vars::antihack::speedhack_pos.y + 10.f }))
		{
			elements_a_aniamtion[3] = math::lerp(elements_a_aniamtion[3], 0, 4.f * Time::deltaTime());
		}
	}
	void DrawColorPicker()
	{
		if (defoultcolorpickercolor != Color(-1, -1, -1, -1) && !colorboxdraw)
		{
			colorpickercolor_1 = defoultcolorpickercolor;
			colorpickercolor_2 = defoultcolorpickercolor;
			colorboxdraw = true;
		}
		if (defoultcolorpickercolor == Color(-1, -1, -1, -1))
		{
			if (colorboxdraw) colorboxdraw = false;
			colorbox_animation = 0;
			return;
		}
		Vector2 renderpos = { menu_position.x + 795, menu_position.y + 495 - 180 };
		u_render::texturebox({ renderpos.x, renderpos.y }, { 180, 180 }, { 12, 12, 12, menu_alfa }, 0, 5);

		u_render::gradient_box({ renderpos.x + 160 , renderpos.y + 5 }, { 15 , 25 }, { 255, 0, 0, menu_alfa }, { 255, 255, 0, menu_alfa });
		u_render::gradient_box({ renderpos.x + 160 , renderpos.y + 30 }, { 15 , 25 }, { 255, 255, 0, menu_alfa }, { 0, 255, 0, menu_alfa });
		u_render::gradient_box({ renderpos.x + 160 , renderpos.y + 55 }, { 15 , 25 }, { 0, 255, 0, menu_alfa }, { 0, 255, 255, menu_alfa });
		u_render::gradient_box({ renderpos.x + 160 , renderpos.y + 80 }, { 15 , 25 }, { 0, 255, 255, menu_alfa }, { 0, 0, 255, menu_alfa });
		u_render::gradient_box({ renderpos.x + 160 , renderpos.y + 105 }, { 15 , 25 }, { 0, 0, 255, menu_alfa }, { 255, 0, 255, menu_alfa });
		u_render::gradient_box({ renderpos.x + 160 , renderpos.y + 130 }, { 15 , 25 }, { 255, 0, 255, menu_alfa }, { 255, 0, 0, menu_alfa });

		for (int i = 0; i < 75; i++) {
			u_render::gradient_box({ renderpos.x + 5, renderpos.y + 5 + (2 * i) }, { 150 , 2 }, Color(i * 8.5, i * 8.5, i * 8.5, menu_alfa), { colorpickercolor_1.r + i * 3, colorpickercolor_1.g + i * 3, colorpickercolor_1.b + i * 3, colorpickercolor_1.a * (menu_alfa / 255) }, false);
		}

		u_render::gradient_box({ renderpos.x + 5 , renderpos.y + 160 }, { 170 , 15 }, { colorpickercolor_2.r, colorpickercolor_2.g, colorpickercolor_2.b, 0 }, { colorpickercolor_2.r, colorpickercolor_2.g, colorpickercolor_2.b, menu_alfa }, false);

		u_render::texturebox({ renderpos.x, renderpos.y }, { 180, 180 }, { 30, 30, 30, menu_alfa }, 1, 5);
		u_render::texturebox({ renderpos.x + 160 , renderpos.y + 5 }, { 15, 150 }, { 30, 30, 30, menu_alfa }, 1);
		u_render::texturebox({ renderpos.x + 5, renderpos.y + 5 }, { 150, 150 }, { 30, 30, 30, menu_alfa }, 1);
		u_render::texturebox({ renderpos.x + 5, renderpos.y + 160 }, { 170, 15 }, { 30, 30, 30, menu_alfa }, 1);

		if (u_elements::is_mouse_in_box({ renderpos.x + 160, renderpos.y + 6 }, { renderpos.x + 175, renderpos.y + 155 }) && mouse_state)
		{
			float r = 0; float g = 0; float b = 0;
			float i = mouse_pos.y - (renderpos.y + 5);
			i *= 10.2;

			if (i <= 255)
			{
				r = 255;
				g = i;
				b = 0;
			}
			if (i > 255 && i <= 510)
			{
				r = 255 - (i - 255);
				g = 255;
				b = 0;
			}
			if (i > 510 && i <= 765)
			{
				r = 0;
				g = 255;
				b = (i - 510);
			}
			if (i > 765 && i <= 1020)
			{
				r = 0;
				g = 255 - (i - 765);
				b = 255;
			}
			if (i > 1020 && i <= 1275)
			{
				r = (i - 1020);
				g = 0;
				b = 255;
			}
			if (i > 1275 && i <= 1530)
			{
				r = 255;
				g = 0;
				b = 255 - (i - 1275);
			}
			colorpickercolor_1 = { r, g, b, 255 };
		}
		else if (u_elements::is_mouse_in_box({ renderpos.x + 5, renderpos.y + 6 }, { renderpos.x + 154, renderpos.y + 154 }) && mouse_state)
		{
			float r = 0; float g = 0; float b = 0;
			float i = mouse_pos.x - (renderpos.x + 5);

			int div = 150;
			int phase = i / div;
			float t = ((int)i % div) / (float)div;

			r = colorpickercolor_1.r * t;
			g = colorpickercolor_1.g * t;
			b = colorpickercolor_1.b * t;

			float k = mouse_pos.y - (renderpos.y + 5);

			float sat = k / 150;
			float _r = r + sat * (255 - r);
			float _g = g + sat * (255 - g);
			float _b = b + sat * (255 - b);
			colorpickercolor_2 = { _r, _g, _b, 255 };
		}
		else if (u_elements::is_mouse_in_box({ renderpos.x + 5 , renderpos.y + 160 }, { renderpos.x + 175 , renderpos.y + 175 }) && mouse_state)
		{
			float a = 255;
			float i = mouse_pos.x - (renderpos.x + 5);
			i *= 1.5;

			a = i;
			colorpickercolor_2 = { colorpickercolor_2.r, colorpickercolor_2.g, colorpickercolor_2.b, a };
		}
		defoultcolorpickercolor = colorpickercolor_2;
	}
	bool window(wchar_t* title, const Vector2& pos, const Vector2& window_size)
	{
		if (!menuinitilizated) {
			menu_position = pos;
			menuinitilizated = true;
		}
		DrawColorPicker();
		mouse_state = Input::GetMouseButton(0);
		mouse_pos.x = Input::get_mousePosition().x;
		mouse_pos.y = Screen::get_height() - Input::get_mousePosition().y;
		
		GUI::DrawTexture(Rect(menu_position.x, menu_position.y + 13, window_size.x, window_size.y - 13), (uintptr_t)Texture2D::whiteTexture(), 0, true, 0, Color(12, 12, 12, menu_alfa).ToUnity(), Vector4(0, 0, 0, 0), Vector4(5, 0, 5, 5), true);
		GUI::DrawTexture(Rect(menu_position.x, menu_position.y + 13, window_size.x, window_size.y - 13), (uintptr_t)Texture2D::whiteTexture(), 0, true, 0, Color(57, 57, 57, menu_alfa).ToUnity(), Vector4(1, 1, 1, 1), Vector4(5, 0, 5, 5), true);
		u_render::texturebox({ menu_position.x + 10, menu_position.y + 23 }, { window_size.x - 20, window_size.y - 32 }, { 21, 21, 21, menu_alfa }, 0, 5);
		u_render::texturebox({ menu_position.x + 10, menu_position.y + 23 }, { window_size.x - 20, window_size.y - 32 }, { 57, 57, 57, menu_alfa }, 1, 5);
		GUI::DrawTexture(Rect(menu_position.x + window_size.x - 292, menu_position.y, 292, 14), (uintptr_t)Texture2D::whiteTexture(), 0, true, 0, Color(12, 12, 12, menu_alfa).ToUnity(), Vector4(0, 0, 0, 0), Vector4(5, 5, 5, 5), true);
		GUI::DrawTexture(Rect(menu_position.x + window_size.x - 292, menu_position.y, 292, 14), (uintptr_t)Texture2D::whiteTexture(), 0, true, 0, Color(57, 57, 57, menu_alfa).ToUnity(), Vector4(1, 1, 1, 0), Vector4(5, 5, 0, 0), true);
		u_render::texturebox({ menu_position.x + window_size.x - 291, menu_position.y + 10 }, { 5, 6 }, { 12, 12, 12, menu_alfa }, 0, 0);
		u_render::texturebox({ menu_position.x + window_size.x - 6, menu_position.y + 10 }, { 5, 6 }, { 12, 12, 12, menu_alfa }, 0, 0);
		u_render::text({ menu_position.x + 10.f, menu_position.y + 4, }, title, { 255, 255, 255, menu_alfa }, false, 13);
		nexttabpos = menu_position + Vector2(window_size.x - 282, 0);
		return true;
	}
	void end_window() {
		old_mouse_pos = mouse_pos;
		old_mouse_state = mouse_state;
	}
	void tab(const wchar_t* name, int id, Vector2 tab_size = { 40.f, 20.f }) {
		if (is_mouse_in_box({ nexttabpos.x, nexttabpos.y }, { nexttabpos.x + tab_size.x, nexttabpos.y + tab_size.y }) && mouse_state && !old_mouse_state && active_tab != id)
		{
			active_tab = id;
			defoultcolorpickercolor = { -1, -1, -1, -1 };
			other_menu_alfa = 0.f;
			tab_menu_alfa = 0.f;
			for (int i = 0; i < 12; i++) beginchild_scroll_value_previev[i] = 0;
		}
		Color tab_color = id == active_tab ? Color(97, 97, 189, menu_alfa) : Color(97, 97, 189, menu_alfa - 55);
		u_render::text({ nexttabpos.x + tab_size.x / 2, nexttabpos.y + tab_size.y / 2 }, name, tab_color, true, 10);
		nexttabpos.x += tab_size.x + 10;
	}
	void beginchild(const wchar_t* title, const Vector2& pos, const Vector2& size, int index)
	{
		u_render::texturebox({ menu_position.x + pos.x,  menu_position.y + pos.y }, { size.x, size.y }, { 17, 17, 17, tab_menu_alfa }, 0, 5);
		next_item_pos = { menu_position.x + pos.x + 15 - 6, menu_position.y + pos.y + 34 - beginchild_scroll_value_previev[index] };
	}
	void endchild(const wchar_t* title, const Vector2& pos, const Vector2& size, int index)
	{
		u_render::texturebox({ menu_position.x + pos.x, menu_position.y + pos.y + size.y }, { size.x, 13 }, { 12, 12, 12, menu_alfa });
		u_render::texturebox({ menu_position.x + pos.x, menu_position.y + pos.y + size.y + 4 }, { size.x, 1 }, { 57, 57, 57, menu_alfa });
		u_render::texturebox({ menu_position.x + pos.x, menu_position.y + pos.y + size.y }, { size.x, 4 }, { 21, 21, 21, menu_alfa });

		u_render::texturebox({ menu_position.x + pos.x,  menu_position.y + pos.y }, { size.x, 24 }, { 25, 25, 25, tab_menu_alfa });
		u_render::texturebox({ menu_position.x + pos.x, menu_position.y + pos.y }, { size.x, size.y }, { 57, 57, 57, tab_menu_alfa }, 1, 5);
		u_render::text({ menu_position.x + pos.x + size.x / 2, menu_position.y + pos.y + 12 }, title, { 255, 255, 255, tab_menu_alfa }, true, 10);

		float nextmousecrtoll = beginchild_scroll_value_previev[index] + Input::GetAxis(_(L"Mouse ScrollWheel")) * -1.f;
		if (is_mouse_in_box({ menu_position.x + pos.x,  menu_position.y + pos.y }, { menu_position.x + pos.x + size.x,  menu_position.y + pos.y + size.y })) {
			if ((nextmousecrtoll > -5 && Input::GetAxis(_(L"Mouse ScrollWheel")) * -1.f < 0) ||
				Input::GetAxis(_(L"Mouse ScrollWheel")) * -1.f > 0 && menu_position.y + pos.y + size.y - 10 <= next_item_pos.y - Input::GetAxis(_(L"Mouse ScrollWheel")) * -1.f)
			{
				beginchild_scroll_value_previev[index] += Input::GetAxis(_(L"Mouse ScrollWheel")) * -1.f;
			}
		}
	}

	Color defoultcol = { -1, -1, -1, -1 };
	KeyCode disable = KeyCode::Joystick8Button19;
	
	void checkbox(const wchar_t* title, bool& value, KeyCode& iKey = disable, Color& colorvalue = defoultcol, int index = -1) {
		int size_ = 10; if (language == 0 || language == 1) size_ = 10; else size_ = 11.0;
		if (event_type == EventType::Repaint)
		{
			if (next_item_pos.y - menu_position.y <= 31 || next_item_pos.y - menu_position.y >= 480) { next_item_pos.y += 20; return; }
			if (is_mouse_in_box({ next_item_pos.x, next_item_pos.y }, { next_item_pos.x + 15, next_item_pos.y + 15 }) && mouse_state && !old_mouse_state)
				value = !value;
			Color text_color = { 255, 255, 255, other_menu_alfa };

			u_render::texturebox({ next_item_pos.x, next_item_pos.y }, { 15, 15 }, { 25, 25, 25, other_menu_alfa });
			if (value)
				u_render::texturebox({ next_item_pos.x , next_item_pos.y }, { 15, 15 }, { 97, 97, 189, other_menu_alfa });
			u_render::texturebox({ next_item_pos.x , next_item_pos.y }, { 15, 15 }, { 57, 57, 57, other_menu_alfa }, 1);
			u_render::text({ next_item_pos.x + 20.f, next_item_pos.y }, title, text_color, false, (float)size_);
		}
		static int active_index = -1;
		if (iKey != disable)
		{
			if (iKey == KeyCode::Escape_) iKey = KeyCode::None;
			if (iKey == KeyCode::Joystick8Button18)
			{
				if (Input::GetMouseButton(1)) iKey = KeyCode::Mouse1;
				else if (Input::GetMouseButton(3))iKey = KeyCode::Mouse3;
				else if (Input::GetMouseButton(4)) iKey = KeyCode::Mouse4;
				if (event_type == EventType::KeyUp) iKey = (KeyCode)active_key;
			}
			if (event_type == EventType::Repaint)
			{
				if (is_mouse_in_box({ next_item_pos.x + 172, next_item_pos.y }, { next_item_pos.x + 232, next_item_pos.y + 15 }) && mouse_state && !old_mouse_state)
					iKey = KeyCode::Joystick8Button18;

				u_render::texturebox({ next_item_pos.x + 172, next_item_pos.y }, { 60, 15 }, { 21, 21, 21, other_menu_alfa });
				u_render::texturebox({ next_item_pos.x + 172, next_item_pos.y }, { 60, 15 }, { 57, 57, 57, other_menu_alfa }, 1);
				u_render::text({ next_item_pos.x + 202, next_item_pos.y + 8 }, iKey == KeyCode::Joystick8Button18 ? _(L"...") : getkey((KeyCode)iKey), { 255, 255, 255, other_menu_alfa }, true, 10);


				if (colorvalue != defoultcol) {
					if (active_index == -1) defoultcolorpickercolor = { -1, -1, -1, -1 };
					if (is_mouse_in_box({ next_item_pos.x + 147, next_item_pos.y }, { next_item_pos.x + 162, next_item_pos.y + 15 }) && mouse_state && !old_mouse_state)
					{
						if (active_index == index) active_index = -1;
						else { active_index = index; defoultcolorpickercolor = colorvalue; colorboxdraw = false; };
					}
					else if (active_index == index)
					{
						if (is_mouse_in_box({ menu_position.x + 795, menu_position.y + 495 - 180 }, { menu_position.x + 795 + 180, menu_position.y + 495 }))
						{
							if (mouse_state)
							{
								colorbox_animation = Mathf::Lerp(colorbox_animation, 5, 15.0f * Time::deltaTime());
								colorpicker_mouse = mouse_pos;
							}
							else colorbox_animation = Mathf::Lerp(colorbox_animation, 0, 15.0f * Time::deltaTime());
							u_render::circle(colorpicker_mouse, colorbox_animation, { 255, 255, 255, menu_alfa });
						}
						else if (mouse_state && !old_mouse_state)
						{
							// Сохраняем цвет перед закрытием colorpicker
							colorvalue = defoultcolorpickercolor;
							active_index = -1;
						}
					}
					Color text_color = { 255, 255, 255, other_menu_alfa };
					if (event_type == EventType::Repaint)
					{
						if (active_index == index) colorvalue = defoultcolorpickercolor;
						u_render::texturebox({ next_item_pos.x + 147, next_item_pos.y }, { 15, 15 }, { colorvalue.r,colorvalue.g,colorvalue.b, colorvalue.a * (other_menu_alfa / 255) }, 0, 15);
						u_render::text({ next_item_pos.x + 20.f, next_item_pos.y }, title, text_color, false, size_);
					}
				}
			}
		}
		else if (colorvalue != defoultcol) {
			if (event_type == EventType::Repaint)
			{
				if (active_index == -1) defoultcolorpickercolor = { -1, -1, -1, -1 };
				if (is_mouse_in_box({ next_item_pos.x + 215, next_item_pos.y }, { next_item_pos.x + 230, next_item_pos.y + 15 }) && mouse_state && !old_mouse_state)
				{
					if (active_index == index) active_index = -1;
					else { active_index = index; defoultcolorpickercolor = colorvalue; colorboxdraw = false; };
				}
				else if (active_index == index)
				{
					if (is_mouse_in_box({ menu_position.x + 795, menu_position.y + 495 - 180 }, { menu_position.x + 795 + 180, menu_position.y + 495 }))
					{
						if (mouse_state)
						{
							colorbox_animation = Mathf::Lerp(colorbox_animation, 5, 15.0f * Time::deltaTime());
							colorpicker_mouse = mouse_pos;
						}
						else colorbox_animation = Mathf::Lerp(colorbox_animation, 0, 15.0f * Time::deltaTime());
						u_render::circle(colorpicker_mouse, colorbox_animation, { 255, 255, 255, menu_alfa });
					}
					else if (mouse_state && !old_mouse_state)
					{
						// Сохраняем цвет перед закрытием colorpicker
						colorvalue = defoultcolorpickercolor;
						active_index = -1;
					}
				}
				Color text_color = { 255, 255, 255, other_menu_alfa };
				if (active_index == index) colorvalue = defoultcolorpickercolor;
				u_render::texturebox({ next_item_pos.x + 215, next_item_pos.y }, { 15, 15 }, { colorvalue.r,colorvalue.g,colorvalue.b, colorvalue.a * (other_menu_alfa / 255) }, 0, 15);
				u_render::text({ next_item_pos.x + 20.f, next_item_pos.y }, title, text_color, false, size_);
			}
		}
		next_item_pos.y += 20;
	}
	float startanim_box;
	void writebox(const wchar_t* title, int index, wchar_t(&writebox_text)[256]) {
		float size_ = 10.f; if (language == 0 || language == 1) size_ = 10.f; else size_ = 11.f;
		if (next_item_pos.y - menu_position.y <= 30 || next_item_pos.y - menu_position.y >= 480) { next_item_pos.y += 42; return; }
		static int active_index = -1;
		if (event_type == EventType::Repaint)
		{
			float downdist = min(18, 479 - (next_item_pos.y - menu_position.y));
			if (mouse_state && !old_mouse_state) {
				if (is_mouse_in_box({ next_item_pos.x, next_item_pos.y + 16 }, { next_item_pos.x + 232, next_item_pos.y + downdist + 16 }))
				{
					if (active_index == index) active_index = -1;
					else active_index = index;
				}
				else active_index = -1;
			}

			float cols = max(57, writebox_a_aniamtion[index]);
			u_render::texturebox({ next_item_pos.x, next_item_pos.y + 16 }, { 232, downdist }, { 21,21,21, other_menu_alfa }, 0, 3);
			u_render::texturebox({ next_item_pos.x, next_item_pos.y + 16 }, { 232, downdist }, { cols,cols,cols, other_menu_alfa }, 1, 3);
		}
		wchar_t output_text_1[256];
		const wchar_t* output_text_2 = _(L"");
		if (active_index == index)
		{
			size_t current_len = u_crt::wcslen(writebox_text);
			if (current_len < 254) { // Оставляем место для нового символа и null-terminator
				//if (shiftactive) {
				if ((((KeyCode)active_key >= 97 && (KeyCode)active_key <= 122) || ((KeyCode)active_key >= 48 && (KeyCode)active_key <= 57)) && event_type == EventType::KeyUp) {
					const wchar_t* str1 = getkey((KeyCode)active_key);
					if (str1 && current_len + u_crt::wcslen(str1) < 255) {
						u_crt::wcscpy(writebox_text + current_len, str1);
					}
				}
				/*}
				else {
					if ((((KeyCode)active_key >= 97 && (KeyCode)active_key <= 122) || ((KeyCode)active_key >= 48 && (KeyCode)active_key <= 57)) && event_type == EventType::KeyUp) {
						const wchar_t* str1 = little_getkey((KeyCode)active_key);
						u_helper::wcscpy(writebox_text + u_helper::wcslen(writebox_text), str1);
					}
				}*/
				if ((KeyCode)active_key == 32 && event_type == EventType::KeyUp) {
					if (current_len < 255) {
						writebox_text[current_len] = L' ';
						writebox_text[current_len + 1] = L'\0';
					}
				}
			}

			if ((KeyCode)active_key == 8 && event_type == EventType::KeyDown) {
				u_crt::deleteLastCharacter(writebox_text);
			}
		}
		if (event_type == EventType::Repaint)
		{
			if (active_index == index) writebox_a_aniamtion[index] = Mathf::Lerp(writebox_a_aniamtion[index], 150, 5.f * Time::deltaTime());
			else writebox_a_aniamtion[index] = Mathf::Lerp(writebox_a_aniamtion[index], 0, 17.f * Time::deltaTime());

			output_text_2 = writebox_text;
			u_crt::wcscpy(output_text_1, output_text_2);
			if (Time::fixedTime() > startanim_box + 1.0f && active_index == index) {
				u_crt::wcscpy(output_text_1 + u_crt::wcslen(output_text_1), _(L"|"));
				if (Time::fixedTime() > startanim_box + 2.0f) {
					startanim_box = Time::fixedTime();
				}
			}
			u_render::text({ next_item_pos.x + 7, next_item_pos.y + 17 }, output_text_1, { 255, 255, 255, other_menu_alfa }, false, size_);
		}

		u_render::text({ next_item_pos.x, next_item_pos.y }, title, { 189.f, 189.f, 189.f, other_menu_alfa }, false, size_);
		next_item_pos.y += 42;
	}
	void combobox(const wchar_t* szTitle, int& iSelected, String aNames[], int iElementsAmount, int index)
	{
		float size_ = 10.f; if (language == 0 || language == 1) size_ = 10.f; else size_ = 11.f;
		if (event_type == EventType::Repaint)
		{
			if (next_item_pos.y - menu_position.y <= 30 || next_item_pos.y - menu_position.y >= 480) { next_item_pos.y += 46; return; }
			static int active_index = -1;
			if (is_mouse_in_box({ next_item_pos.x, next_item_pos.y + 16 }, { next_item_pos.x + 232, next_item_pos.y + 38 }) && mouse_state && !old_mouse_state) {
				if (active_index == index) active_index = -1;
				else active_index = index;
			}
			if (active_index == index) combobox_aniamtion[index] = Mathf::Lerp(combobox_aniamtion[index], 20 * iElementsAmount, 2.5f * Time::deltaTime());
			else combobox_aniamtion[index] = Mathf::Lerp(combobox_aniamtion[index], 0, 17.f * Time::deltaTime());

			if (active_index == index) combobox_a_aniamtion[index] = Mathf::Lerp(combobox_a_aniamtion[index], 150, 5.f * Time::deltaTime());
			else combobox_a_aniamtion[index] = Mathf::Lerp(combobox_a_aniamtion[index], 0, 17.f * Time::deltaTime());

			Vector2 vecNewBarPosition = { next_item_pos.x, next_item_pos.y + 16 + 2 };
			Vector2 lastitempos = { next_item_pos.x, next_item_pos.y };

			if (combobox_aniamtion[index] > 0.1)
			{
				for (int iElement = 0; iElement < iElementsAmount; iElement++)
				{
					float downdist = min(20, 455 - (next_item_pos.y - menu_position.y));

					if (next_item_pos.y - menu_position.y >= 455) continue;
					if (active_index == index)
					{
						next_item_pos.y += min(combobox_aniamtion[index] / (iElement), 20);
						vecNewBarPosition.y += min(combobox_aniamtion[index] / (iElement), 20);
						if (is_mouse_in_box(vecNewBarPosition, { vecNewBarPosition.x + 232, vecNewBarPosition.y + 19 }) && mouse_state && !old_mouse_state) {
							iSelected = iElement;
							active_index = -1;
						}
						auto sElement = aNames[iElement];
						u_render::texturebox({ vecNewBarPosition.x, vecNewBarPosition.y }, { 232, downdist }, { 21, 21, 21, other_menu_alfa });
						if (iElement == iSelected)
						{
							combobox_items_aniamtion[iElement] = 0;
							if (464 - (next_item_pos.y - menu_position.y) > 0)
							{
								u_render::texturebox({ vecNewBarPosition.x + 6, vecNewBarPosition.y + 5 }, { 5, 5 }, { 97, 97, 189, other_menu_alfa }, 0, 360);
								u_render::text({ vecNewBarPosition.x + 15, vecNewBarPosition.y }, sElement, { 97, 97, 189, other_menu_alfa }, false, size_);
							}
						}
						else if (is_mouse_in_box(vecNewBarPosition, { vecNewBarPosition.x + 232, vecNewBarPosition.y + 19 }))
						{
							combobox_items_aniamtion[iElement] = Mathf::Lerp(combobox_items_aniamtion[iElement], 9, 7.f * Time::deltaTime());
							if (464 - (next_item_pos.y - menu_position.y) > 0)
							{
								u_render::text({ vecNewBarPosition.x + 6 + combobox_items_aniamtion[iElement], vecNewBarPosition.y }, sElement, { 97, 97, 189, other_menu_alfa }, false, size_);
								if (combobox_items_aniamtion[iElement] > 8)
									u_render::texturebox({ vecNewBarPosition.x + 6, vecNewBarPosition.y + 5 }, { 5, 5 }, { 97, 97, 189, other_menu_alfa }, 1, 360);
							}
						}
						else
						{
							combobox_items_aniamtion[iElement] = 0;
							if (464 - (next_item_pos.y - menu_position.y) > 0)
								u_render::text({ vecNewBarPosition.x + 6, vecNewBarPosition.y }, sElement, { 255.f, 255.f, 255.f, other_menu_alfa }, false, size_);
						}
					}
					else
					{
						next_item_pos.y += min(combobox_aniamtion[index] / (iElement + 1), 20);
						vecNewBarPosition.y += min(combobox_aniamtion[index] / (iElement + 1), 20);
						auto sElement = aNames[iElement];
						u_render::texturebox({ vecNewBarPosition.x, vecNewBarPosition.y }, { 232, downdist }, { 21, 21, 21, other_menu_alfa });
						if (iElement == iSelected)
						{
							if (464 - (next_item_pos.y - menu_position.y) > 0)
							{
								u_render::texturebox({ vecNewBarPosition.x + 6, vecNewBarPosition.y + 5 }, { 5, 5 }, { 97, 97, 189, other_menu_alfa }, 0, 360);
								u_render::text({ vecNewBarPosition.x + 15, vecNewBarPosition.y }, sElement, { 97, 97, 189, other_menu_alfa }, false, size_);
							}
						}
						else if (464 - (next_item_pos.y - menu_position.y) > 0)
							u_render::text({ vecNewBarPosition.x + 6, vecNewBarPosition.y }, sElement, { 255.f, 255.f, 255.f, other_menu_alfa }, false, size_);
					}
				}
				if ((!is_mouse_in_box({ lastitempos.x, lastitempos.y + 16 }, { lastitempos.x + 232, vecNewBarPosition.y + 20 }) && mouse_state && !old_mouse_state)/* || u_sdk::GetAxis(_(L"Mouse ScrollWheel")) * -1.f != 0*/)
					active_index = -1;
			}
			float downdist = min(22, 479 - (lastitempos.y - menu_position.y));
			u_render::text({ lastitempos.x, lastitempos.y }, szTitle, { 189.f, 189.f, 189.f, other_menu_alfa }, false, size_);
			float cols = max(57, combobox_a_aniamtion[index]);
			u_render::texturebox({ lastitempos.x, lastitempos.y + 16 }, { 232, downdist }, { 21, 21, 21, other_menu_alfa }, 0, 3);
			u_render::texturebox({ lastitempos.x, lastitempos.y + 16 }, { 232, downdist }, { cols, cols, cols, other_menu_alfa }, 1, 3);
			if (461 - (lastitempos.y - menu_position.y) > 0)
				u_render::text({ lastitempos.x + 6, lastitempos.y + 19 }, aNames[iSelected], { 255.f, 255.f, 255.f, other_menu_alfa }, false, size_);
		}
		next_item_pos.y += 46;
	}
	void multicombobox(const wchar_t* szTitle, bool(&multicomboboxactive)[12], String aNames[], int iElementsAmount, int index)
	{
		float size_ = 10.f; if (language == 0 || language == 1) size_ = 10.f; else size_ = 11.f;
		if (event_type == EventType::Repaint)
		{
			if (next_item_pos.y - menu_position.y <= 30 || next_item_pos.y - menu_position.y >= 480) { next_item_pos.y += 46; return; }
			static int active_index = -1;
			if (is_mouse_in_box({ next_item_pos.x, next_item_pos.y + 16 }, { next_item_pos.x + 232, next_item_pos.y + 38 }) && mouse_state && !old_mouse_state) {
				if (active_index == index) active_index = -1;
				else active_index = index;
			}
			if (active_index == index) combobox_aniamtion[index] = Mathf::Lerp(combobox_aniamtion[index], 20 * iElementsAmount, 2.5f * Time::deltaTime());
			else combobox_aniamtion[index] = Mathf::Lerp(combobox_aniamtion[index], 0, 17.f * Time::deltaTime());

			if (active_index == index) combobox_a_aniamtion[index] = Mathf::Lerp(combobox_a_aniamtion[index], 150, 5.f * Time::deltaTime());
			else combobox_a_aniamtion[index] = Mathf::Lerp(combobox_a_aniamtion[index], 0, 17.f * Time::deltaTime());

			Vector2 vecNewBarPosition = { next_item_pos.x, next_item_pos.y + 16 + 2 };
			Vector2 lastitempos = { next_item_pos.x, next_item_pos.y };
			if (combobox_aniamtion[index] > 0.1)
			{
				for (int iElement = 0; iElement < iElementsAmount; iElement++)
				{
					float downdist = min(20, 455 - (next_item_pos.y - menu_position.y));
					if (next_item_pos.y - menu_position.y >= 455) continue;

					if (active_index == index)
					{
						next_item_pos.y += min(combobox_aniamtion[index] / (iElement), 20);
						vecNewBarPosition.y += min(combobox_aniamtion[index] / (iElement), 20);
						if (is_mouse_in_box(vecNewBarPosition, { vecNewBarPosition.x + 232, vecNewBarPosition.y + 19 }) && mouse_state && !old_mouse_state) {
							if (multicomboboxactive[iElement]) multicomboboxactive[iElement] = false;
							else multicomboboxactive[iElement] = true;
						}
						auto sElement = aNames[iElement];
						u_render::texturebox({ vecNewBarPosition.x, vecNewBarPosition.y }, { 232, downdist }, { 21, 21, 21, other_menu_alfa });
						if (multicomboboxactive[iElement])
						{
							if (464 - (next_item_pos.y - menu_position.y) > 0)
							{
								u_render::texturebox({ vecNewBarPosition.x + 6, vecNewBarPosition.y + 5 }, { 5, 5 }, { 97, 97, 189, other_menu_alfa }, 0, 360);
								u_render::text({ vecNewBarPosition.x + 15, vecNewBarPosition.y }, sElement, { 97, 97, 189, other_menu_alfa }, false, size_);
							}
						}
						else if (is_mouse_in_box(vecNewBarPosition, { vecNewBarPosition.x + 232, vecNewBarPosition.y + 19 }))
						{
							combobox_items_aniamtion[iElement] = Mathf::Lerp(combobox_items_aniamtion[iElement], 9, 7.f * Time::deltaTime());
							if (464 - (next_item_pos.y - menu_position.y) > 0)
							{
								u_render::text({ vecNewBarPosition.x + 6 + combobox_items_aniamtion[iElement], vecNewBarPosition.y }, sElement, { 97, 97, 189, other_menu_alfa }, false, size_);
								if (combobox_items_aniamtion[iElement] > 8)
									u_render::texturebox({ vecNewBarPosition.x + 6, vecNewBarPosition.y + 5 }, { 5, 5 }, { 97, 97, 189, other_menu_alfa }, 1, 360);
							}
						}
						else
						{
							combobox_items_aniamtion[iElement] = 0;
							if (464 - (next_item_pos.y - menu_position.y) > 0)
								u_render::text({ vecNewBarPosition.x + 6, vecNewBarPosition.y }, sElement, { 255.f, 255.f, 255.f, other_menu_alfa }, false, size_);
						}
					}
					else
					{
						next_item_pos.y += min(combobox_aniamtion[index] / (iElement + 1), 20);
						vecNewBarPosition.y += min(combobox_aniamtion[index] / (iElement + 1), 20);
						auto sElement = aNames[iElement];
						u_render::texturebox({ vecNewBarPosition.x, vecNewBarPosition.y }, { 232, downdist }, { 21, 21, 21, other_menu_alfa });
						if (multicomboboxactive[iElement])
						{
							if (464 - (next_item_pos.y - menu_position.y) > 0)
							{
								u_render::texturebox({ vecNewBarPosition.x + 6, vecNewBarPosition.y + 5 }, { 5, 5 }, { 97, 97, 189, other_menu_alfa }, 0, 360);
								u_render::text({ vecNewBarPosition.x + 15, vecNewBarPosition.y }, sElement, { 97, 97, 189, other_menu_alfa }, false, size_);
							}
						}
						else if (464 - (next_item_pos.y - menu_position.y) > 0)
							u_render::text({ vecNewBarPosition.x + 6, vecNewBarPosition.y }, sElement, { 255.f, 255.f, 255.f, other_menu_alfa }, false, size_);
					}
				}
				if ((!is_mouse_in_box({ lastitempos.x, lastitempos.y + 16 }, { lastitempos.x + 232, vecNewBarPosition.y + 20 }) && mouse_state && !old_mouse_state)/* || u_sdk::GetAxis(_(L"Mouse ScrollWheel")) * -1.f != 0*/)
					active_index = -1;
			}
			float downdist = min(22, 479 - (lastitempos.y - menu_position.y));
			u_render::text({ lastitempos.x, lastitempos.y }, szTitle, { 189.f, 189.f, 189.f, other_menu_alfa }, false, size_);
			float cols = max(57, combobox_a_aniamtion[index]);
			u_render::texturebox({ lastitempos.x, lastitempos.y + 16 }, { 232, downdist }, { 21, 21, 21, other_menu_alfa }, 0, 3);
			u_render::texturebox({ lastitempos.x, lastitempos.y + 16 }, { 232, downdist }, { cols, cols, cols, other_menu_alfa }, 1, 3);
			int allactive = 0;
			for (int i = 0; i < 12; ++i) {
				if (multicomboboxactive[i])
					allactive += 1;
			}
			wchar_t output[256];
			il2cpp::methods::f_swprint(output, language == 0 ? _(L"Active elements: %d") : (language == 1 ? _(L"Активных элементов: %d") : _(L"活动元素: %d")), allactive);
			if (461 - (lastitempos.y - menu_position.y) > 0)
				u_render::text({ lastitempos.x + 6, lastitempos.y + 19 }, output, { 255.f, 255.f, 255.f, other_menu_alfa }, false, size_);
		}
		next_item_pos.y += 46;
	}
	void slider(const wchar_t* title, float* value, float min, float max, int index, bool showint = false)
	{
		int size_ = 10; if (language == 0 || language == 1) size_ = 10; else size_ = 11.0;
		if (event_type == EventType::Repaint)
		{
			if (next_item_pos.y - menu_position.y <= 30 || next_item_pos.y - menu_position.y >= 480) { next_item_pos.y += 35; return; }
			static int active_index = -1;
			bool is_hovered = is_mouse_in_box({ next_item_pos.x, next_item_pos.y + 16 }, { next_item_pos.x + 232, next_item_pos.y + 27 });
			if (active_index == index) {
				if (mouse_state) {
					float new_value = min + (mouse_pos.x - next_item_pos.x) * (max - min) / 232;
					*value = Mathf::Lerp(*value, Mathf::Clamp(new_value, min, max), 15.f * Time::deltaTime());
				}
				else {
					active_index = -1;
				}
			}
			else if (is_hovered && mouse_state) {
				active_index = index;
			}

			if (active_index == index) slider_a_aniamtion[index] = Mathf::Lerp(slider_a_aniamtion[index], 150, 5.f * Time::deltaTime());
			else slider_a_aniamtion[index] = Mathf::Lerp(slider_a_aniamtion[index], 0, 17.f * Time::deltaTime());

			char m_szValue[64];
			wchar_t m_wszValue[64];
			if (*value < 100 && !showint)
				itoass_float(static_cast<float>(*value), m_szValue, 10, 4);
			else
				itoass(static_cast<int>(*value), m_szValue, 10);
			AnsiToUnicode(m_szValue, m_wszValue);

			u_render::text({ next_item_pos.x + 1, next_item_pos.y - 2 }, title, { 189, 189, 189, other_menu_alfa }, false, 10, size_);

			float downdist = min(11, 479 - (next_item_pos.y - menu_position.y));
			u_render::texturebox({ next_item_pos.x, next_item_pos.y + 16 }, { 232, downdist }, { 21, 21, 21, other_menu_alfa });
			u_render::texturebox({ next_item_pos.x, next_item_pos.y + 16 }, { (*value - min) * 232 / (max - min), downdist }, { 97, 97, 189, other_menu_alfa });
			float cols = max(57, slider_a_aniamtion[index]);
			u_render::texturebox({ next_item_pos.x, next_item_pos.y + 16 }, { 232, downdist }, { cols, cols, cols, other_menu_alfa }, 1);
			u_render::text({ next_item_pos.x + 216, next_item_pos.y - 2 }, m_wszValue, { 189, 189, 189, other_menu_alfa }, false, 10, size_);
		}
		next_item_pos.y += 35;
	}
}