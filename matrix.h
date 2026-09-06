namespace other {
    inline bool world_to_screen(const Vector3& EntityPos, Vector2& ScreenPos)
    {
        auto main_cam = Camera::main_camera();
        if (!main_cam || main_cam < 0x10000) return false;
        auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
        if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return false;
        Vector3 local = cam_transform->InverseTransformPoint(EntityPos);
        if (local.z <= 0.1f) return false;
        float fov = Camera::get_fov(main_cam);
        float aspect = Camera::get_aspect(main_cam);
        float fov_rad = fov * 0.0174532925f; // PI/180
        float tan_half_fov = math::tan(fov_rad * 0.5f);
        float f = 1.0f / tan_half_fov;
        float x = (local.x / local.z) * f / aspect;
        float y = (local.y / local.z) * f;
        float width = (float)Screen::get_width();
        float height = (float)Screen::get_height();
        ScreenPos.x = (width * 0.5f) * (1.0f + x);
        ScreenPos.y = (height * 0.5f) * (1.0f - y);

        return true;
    }
    Vector3 WorldToScreen(Vector3 position)
    {
        Vector2 to_return;
        if (world_to_screen(position, to_return))
        {
            return Vector3(to_return.x, to_return.y, 0);
        }
        return Vector3(0, 0, 0);
    }
    void DrawObject(BasePlayer* entity, bool show_distance, float max_draw_distance, const wchar_t* entity_text, Color entity_color, bool showico, const wchar_t* item_name = _(L""), bool show_health = false,
        Vector3 pos = Vector3::Zero()) {
        if (!entity && pos == Vector3::Zero()) return;
        Vector3 position;
        if (pos == Vector3::Zero())
            position = entity->transform()->position();
        else
            position = pos;

        auto main_cam = Camera::main_camera();
        if (!main_cam || main_cam < 0x10000) return;

        auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
        if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;

        float distantion = cam_transform->position().Distance(position);
        if (position == Vector3::Zero()) return;
        Vector2 screen_pos;
        if (!world_to_screen(position, screen_pos)) return;
        if (distantion > max_draw_distance) return;
        if (showico) {
            if (show_distance) {
                wchar_t outputText[512];
                il2cpp::methods::f_swprint(outputText, _(L"[%.1fm]"), distantion);
                u_render::text({ screen_pos.x, screen_pos.y - 20 }, outputText, entity_color, true, 11, vars::esp::outline);
            }
            Texture2D* texture = nullptr;
            if (!texture) texture = (Texture2D*)AssetBundle::LoadAsset_Internal(cheat_bundle, item_name, il2cpp::type_object(_("UnityEngine"), _("Texture")));
            GUI::DrawTexture(Rect(screen_pos.x - 15, screen_pos.y - 15, 30, 30), (uintptr_t)texture, 0, true, 0, Color(255, 255, 255, 255).ToUnity(), Vector4(0, 0, 0, 0), Vector4(0, 0, 0, 0), true);
        }
        else {
            wchar_t outputText[512];
            if (!show_distance)
            {
                il2cpp::methods::f_swprint(outputText, _(L"%s"), entity_text);
                u_render::text({ screen_pos.x, screen_pos.y }, outputText, entity_color, true, 11, vars::esp::outline);
            }
            else if (show_distance) {
                il2cpp::methods::f_swprint(outputText, _(L"%s [%.1fm]"), entity_text, distantion);
                u_render::text({ screen_pos.x, screen_pos.y }, outputText, entity_color, true, 11, vars::esp::outline);
            }
            if (show_health)
            {
                auto cur_helth = entity->health();
                const auto max_health = entity->maxHealth();
                float health_pc = min(cur_helth / max_health, 1);

                u_render::texturebox({ screen_pos.x - 14.f, screen_pos.y + 13 }, { 26, 4 }, { 0, 0, 0, 255 });
                u_render::texturebox({ screen_pos.x - 13.f, screen_pos.y + 13 }, { 25 * health_pc, 3 }, { 0, 255, 0, 255 });
                u_render::texturebox({ screen_pos.x - 14.f, screen_pos.y + 13 }, { 26, 4 }, { 0, 0, 0, 255 }, 1);
            }
           
        }
    }
    void DrawDebug(BasePlayer* entity, const wchar_t* entity_text, const wchar_t* entity_text_2, int prefabid, Color entity_color) {
        if (!entity) return;
        const Vector3 position = entity->transform()->position();

        auto main_cam = Camera::main_camera();
        if (!main_cam || main_cam < 0x10000) return;

        auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
        if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;

        float distantion = cam_transform->position().Distance(position);
        if (position == Vector3::Zero()) return;
        Vector2 screen_pos;
        if (!world_to_screen(position, screen_pos)) return;
        wchar_t outputText[512];
        il2cpp::methods::f_swprint(outputText, _(L"%s"), entity_text);
        wchar_t outputText_2[512];
        il2cpp::methods::f_swprint(outputText_2, _(L"%s | %d"), entity_text_2, prefabid);
        //il2cpp::methods::f_swprint(outputText, _(L"%s [%.1fm]"), entity_text, distantion);
        u_render::text({ screen_pos.x, screen_pos.y }, outputText, entity_color, true, 11, vars::esp::outline);
        u_render::text({ screen_pos.x, screen_pos.y + 15 }, outputText_2, entity_color, true, 11, vars::esp::outline);
    }
    void DrawStash(BasePlayer* entity, bool show_distance, float max_draw_distance) {
        if (!entity) return;
        const Vector3 position = entity->transform()->position();

        auto main_cam = Camera::main_camera();
        if (!main_cam || main_cam < 0x10000) return;

        auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
        if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;

        float distantion = cam_transform->position().Distance(position);
        if (position == Vector3::Zero()) return;
        Vector2 screen_pos;
        if (!world_to_screen(position, screen_pos)) return;
        if (distantion > max_draw_distance) return;
        const wchar_t* entity_text;
        Color entity_color;
        if (entity->HasFlag(baseent_Flags::Reserved5)) {
            entity_text = _(L"Stash [Hidden]");
            entity_color = { 128, 80, 38, 255 };
        }
        else {
            entity_text = _(L"Stash [Open]");
            entity_color = { 186, 116, 55, 255 };
        }
        wchar_t outputText[512];
        if (!show_distance)
        {
            il2cpp::methods::f_swprint(outputText, _(L"%s"), entity_text);
            u_render::text({ screen_pos.x, screen_pos.y }, outputText, entity_color, true, 11, vars::esp::outline);
        }
        else if (show_distance) {
            il2cpp::methods::f_swprint(outputText, _(L"%s [%.1fm]"), entity_text, distantion);
            u_render::text({ screen_pos.x, screen_pos.y }, outputText, entity_color, true, 11, vars::esp::outline);
        }
    }
    void DrawToolCupboard(BasePlayer* entity, bool show_distance, float max_draw_distance) {
        if (!entity) return;
        const Vector3 position = entity->transform()->position();

        auto main_cam = Camera::main_camera();
        if (!main_cam || main_cam < 0x10000) return;

        auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
        if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;

        float distantion = cam_transform->position().Distance(position);
        if (position == Vector3::Zero()) return;
        Vector2 screen_pos;
        if (!world_to_screen(position, screen_pos)) return;
        if (distantion > max_draw_distance) return;
        Color entity_color = { 255, 0, 0, 255 };

        wchar_t outputText[512];
        if (!show_distance)
        {
            il2cpp::methods::f_swprint(outputText, _(L"%s"), _(L"Tool Cupboard"));
            u_render::text({ screen_pos.x, screen_pos.y }, outputText, entity_color, true, 11, vars::esp::outline);
        }
        else if (show_distance) {
            il2cpp::methods::f_swprint(outputText, _(L"%s [%.1fm]"), _(L"Tool Cupboard"), distantion);
            u_render::text({ screen_pos.x, screen_pos.y }, outputText, entity_color, true, 11, vars::esp::outline);
        }

    }
    void HackableCrate(BasePlayer* entity, bool show_distance, float max_draw_distance) {
        if (!entity) return;
        const Vector3 position = entity->transform()->position();

        auto main_cam = Camera::main_camera();
        if (!main_cam || main_cam < 0x10000) return;

        auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
        if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;

        float distantion = cam_transform->position().Distance(position);
        if (position == Vector3::Zero()) return;
        Vector2 screen_pos;
        if (!world_to_screen(position, screen_pos)) return;
        if (distantion > max_draw_distance) return;
        wchar_t outputText[512];
        wchar_t outputText2[512];
        DWORD64 timerText = u_mem::read<DWORD64>((DWORD64)entity + values::HackableLockedCrate::timerText); //0x548
        auto* m_Text = rc<pUncStr>(u_mem::read<DWORD64>(timerText + 0xD8));
        il2cpp::methods::f_swprint(outputText2, _(L"Time : [%s]"), m_Text->str);
        u_render::text({ screen_pos.x, screen_pos.y }, outputText2, { 245 , 115 ,0,255 }, true, 11, vars::esp::outline);
        if (!show_distance)
        {
            il2cpp::methods::f_swprint(outputText, _(L"%s"), _(L"Chinook Crate"));
            u_render::text({ screen_pos.x, screen_pos.y - 10 }, outputText, { 245 , 115 ,0,255 }, true, 11, vars::esp::outline);
        }
        else if (show_distance) {
            il2cpp::methods::f_swprint(outputText, _(L"%s [%.1fm]"), _(L"Chinook Crate"), distantion);
            u_render::text({ screen_pos.x, screen_pos.y - 10 }, outputText, { 245 , 115 ,0,255 }, true, 11, vars::esp::outline);
        }
    }
    void draw_weapon_icon(Item* item, BasePlayer* entity, float max_draw_distance) {
        if (!item || !isvalid((uintptr_t)item)) return;
        
        auto sprite = item->get_iconSprite();
        if (!sprite || sprite < 0x10000) return;
        
        auto texture = Sprite::get_texture(sprite);
        if (!texture || (uintptr_t)texture < 0x10000) return;

        if (!entity || !isvalid((uintptr_t)entity)) return;
        
        auto transform = entity->transform();
        if (!transform || !isvalid((uintptr_t)transform)) return;
        
        Vector3 position = transform->position();
        if (position == Vector3::Zero()) return;

        auto main_cam = Camera::main_camera();
        if (!main_cam || main_cam < 0x10000) return;

        auto cam_transform = (Transform*)auto_co_ofsets::Component::get_transform(main_cam);
        if (!cam_transform || (uintptr_t)cam_transform < 0x10000) return;

        float distantion = cam_transform->position().Distance(position);
        if (distantion > max_draw_distance) return;
        
        Vector2 screen_pos;
        if (!world_to_screen(position, screen_pos)) return;
        
     
        GUI::DrawTexture(Rect(screen_pos.x - 15, screen_pos.y - 15, 30, 30), (uintptr_t)texture, 0, true, 0, { 1, 1, 1, 1 }, Vector4(0, 0, 0, 0), Vector4(0, 0, 0, 0), true);
        
        
        if (vars::object::show_mainobjects_distance) {
            wchar_t distanceText[64];
            il2cpp::methods::f_swprint(distanceText, _(L"[%.1fm]"), distantion);
            u_render::text({ screen_pos.x, screen_pos.y - 20 }, distanceText, { 255, 255, 255, 255 }, true, 11, vars::esp::outline);
        }
    }
    void DroppedItems(BasePlayer* entity, bool show_distance, float max_draw_distance, bool showicon) {
        if (!entity) return;
        
      
        UINT64 Object = u_mem::read<UINT64>((UINT64)entity + 0x10);
        if (!Object || Object < 0x10000) return;
        
        DWORD64 Ent = u_mem::read<UINT64>(Object + 0x28);
        if (!Ent || Ent < 0x10000) return;
        auto ItemPtr = u_mem::read<DWORD64>(Ent + values::WorldItem::item);
        if (!ItemPtr || ItemPtr < 0x10000) return;

        auto item = rc<Item*>(ItemPtr);
        if (item && isvalid((uintptr_t)item))
        {
            auto item_name = item->weapon_name();
            if (item_name && u_crt::wcslen(item_name) > 0) {
                if (showicon)
                    draw_weapon_icon(item, entity, max_draw_distance);
                else
                    DrawObject(entity, show_distance, max_draw_distance, item_name, { 232, 232, 232, 255 }, false, _(L""));
            }
        }
    }
}
#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)
float get_2d_dist(const Vector2& Src, const Vector3& Dst) {
    return math::sqrt(powFFFFFFFFFFFFFFFFFFFFFF(Src.x - Dst.x) + powFFFFFFFFFFFFFFFFFFFFFF(Src.y - Dst.y));
}
float get_fov_by_pos(Vector3 Pos) {
    Vector3 ScreenPos = other::WorldToScreen(Pos);
    if (ScreenPos.is_empty())
        return 1000;
    return get_2d_dist(Vector2(Screen::get_width() / 2, Screen::get_width() / 2), ScreenPos);
}