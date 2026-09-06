#pragma once

// Безопасная выгрузка чита без краша игры

namespace unload_manager {
    static bool is_unloading = false;
    static HMODULE dll_module = nullptr;

    // Функция очистки хуков и ресурсов
    void cleanup() {
        crash_logger::log_info("Starting cleanup process...");
        
        // Восстанавливаем оригинальные функции
        try {
            // Восстанавливаем хуки IL2CPP
            if (u_hooks::orig::hk_PerfomanceUiUpdate) {
                il2cpp::unhook(_("Update"), _("PerformanceUI"), _("Facepunch"), 0);
            }
            
            if (u_hooks::orig::hk_ProjectileUpdate) {
                il2cpp::unhook(_("Update"), _("Projectile"), _(""), 0);
            }
            
            if (u_hooks::orig::hk_BasePlayer_ClientInput) {
                il2cpp::unhook_virtual_function(_("BasePlayer"), _("ClientInput"));
            }
            
            crash_logger::log_info("Hooks restored successfully");
        }
        catch (...) {
            crash_logger::log_error("Error while restoring hooks");
        }
        
        // Очищаем глобальные переменные
        local_player = nullptr;
        target_player = nullptr;
        big_target_player = nullptr;
        target_heli = nullptr;
        
        crash_logger::log_info("Global variables cleared");
        
        // Даем время на завершение всех операций
        Sleep(100);
        
        crash_logger::log_info("Cleanup completed successfully");
    }

    // Поток для безопасной выгрузки
    DWORD WINAPI unload_thread(LPVOID param) {
        crash_logger::log_info("Unload thread started");
        
        // Ждем немного чтобы выйти из контекста меню
        Sleep(500);
        
        // Выполняем очистку
        cleanup();
        
        // Даем время на завершение
        Sleep(200);
        
        crash_logger::log_info("Unloading DLL module...");
        
        // Выгружаем DLL
        if (dll_module) {
            FreeLibraryAndExitThread(dll_module, 0);
        }
        
        return 0;
    }

    // Запуск процесса выгрузки
    void start_unload(HMODULE module) {
        if (is_unloading) {
            crash_logger::log_warning("Unload already in progress");
            return;
        }
        
        is_unloading = true;
        dll_module = module;
        
        crash_logger::log_info("Starting unload process...");
        
        // Создаем отдельный поток для выгрузки
        HANDLE thread = CreateThread(
            nullptr,
            0,
            unload_thread,
            nullptr,
            0,
            nullptr
        );
        
        if (thread) {
            CloseHandle(thread);
            crash_logger::log_info("Unload thread created successfully");
        } else {
            crash_logger::log_error("Failed to create unload thread");
            is_unloading = false;
        }
    }
}
