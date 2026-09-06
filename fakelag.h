#pragma once

namespace fakelag {
    inline bool enabled = false;
    inline KeyCode key = KeyCode::None;
    inline float ticks = 14.f; // Количество тиков задержки (1-14)
    inline bool indicator = false;
    inline Vector2 indicator_pos = Vector2(0, 0);
    
    // Внутренние переменные
    inline int current_tick = 0;
    inline bool is_lagging = false;
    inline Vector3 stored_position = Vector3::Zero();
    inline Vector3 stored_velocity = Vector3::Zero();
    
    // Функция для активации фейк лага
    void process(PlayerWalkMovement* movement) {
        if (!enabled || !movement || !local_player) return;
        
        bool key_pressed = (key != KeyCode::None) ? Input::GetKey(key) : true;
        
        if (key_pressed) {
            if (current_tick < (int)ticks) {
                // Сохраняем оригинальную позицию при первом тике
                if (current_tick == 0) {
                    stored_position = local_player->transform()->position();
                    stored_velocity = movement->body()->velocity();
                    is_lagging = true;
                }
                
                // Замораживаем позицию на сервере
                local_player->lastSentTick()->position(stored_position);
                
                current_tick++;
            } else {
                // Сбрасываем после достижения максимума тиков
                current_tick = 0;
                is_lagging = false;
            }
        } else {
            // Сброс при отпускании клавиши
            current_tick = 0;
            is_lagging = false;
        }
    }
    
    // Индикатор фейк лага
    void draw_indicator() {
        if (!enabled || !indicator || !is_lagging) return;
        
        // Вычисляем процент заполнения
        float progress = (float)current_tick / (float)ticks;
        
        // Позиция индикатора
        Vector2 pos = indicator_pos;
        if (pos.x == 0 && pos.y == 0) {
            pos = Vector2(screen_center.x - 100, screen_center.y + 200);
        }
        
        // Рисуем фон
        u_render::texturebox(pos, Vector2(200, 20), Color(0, 0, 0, 150));
        
        // Рисуем прогресс бар
        Color bar_color = Color(255, 0, 0, 255);
        if (progress < 0.5f) {
            bar_color = Color(0, 255, 0, 255);
        } else if (progress < 0.8f) {
            bar_color = Color(255, 255, 0, 255);
        }
        
        u_render::texturebox(pos, Vector2(200 * progress, 20), bar_color);
        
        // Рисуем обводку
        u_render::drawline(pos, Vector2(pos.x + 200, pos.y), Color(255, 255, 255, 255), 1.f);
        u_render::drawline(Vector2(pos.x + 200, pos.y), Vector2(pos.x + 200, pos.y + 20), Color(255, 255, 255, 255), 1.f);
        u_render::drawline(Vector2(pos.x + 200, pos.y + 20), Vector2(pos.x, pos.y + 20), Color(255, 255, 255, 255), 1.f);
        u_render::drawline(Vector2(pos.x, pos.y + 20), pos, Color(255, 255, 255, 255), 1.f);
        
        // Текст
        wchar_t text[64];
        il2cpp::methods::f_swprint(text, _(L"Fake Lag: %d/%d"), current_tick, (int)ticks);
        u_render::text(Vector2(pos.x + 100, pos.y + 10), text, Color(255, 255, 255, 255), true, 12);
    }
}
