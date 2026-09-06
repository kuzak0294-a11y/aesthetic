#include <windows.h>
#include <iostream>
#include "entity_loop.h"

// ГЛАВНЫЙ ПОТОК СОФТА
DWORD WINAPI MainThread(LPVOID lpParam) {
    // Консоль для проверки (появится черное окошко с логами)
    #ifdef _DEBUG
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    std::cout << "[+] RUST RECODE INJECTED SUCCESSFULLY!" << std::endl;
    #endif

    // ОСНОВНОЙ ЦИКЛ РАБОТЫ (КРУТИТСЯ ПОКА ТЫ НЕ НАЖМЕШЬ [END])
    while (!(GetAsyncKeyState(VK_END) & 1)) {
        
        // ЗДЕСЬ БУДЕТ ВЫЗОВ ОБНОВЛЕНИЯ ДАННЫХ ИЗ ИГРЫ:
        // g_EntitySystem.UpdateMemory();

        Sleep(5); // Разгружаем процессор
    }

    // ВЫГРУЗКА И ОЧИСТКА
    #ifdef _DEBUG
    if (f) fclose(f);
    FreeConsole();
    #endif

    FreeLibraryAndExitThread((HMODULE)lpParam, 0);
    return TRUE;
}

// ТОЧКА ВХОДА ПРИ ИНЖЕКТЕ ДЛЛ
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}