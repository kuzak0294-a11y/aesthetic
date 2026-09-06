#pragma warning(disable : 4530)
#pragma warning(disable : 4244)
#pragma warning(disable : 5040)
#pragma comment(linker,"/MERGE:.pdata=.text")
#pragma comment(linker, "/merge:.CRT=.rdata" )
#pragma comment(linker, "/merge:.pdata=.rdata" )
#pragma comment(linker, "/merge:.rdata=.text" )
#pragma comment(linker, "/merge:_RDATA=.text" )
#pragma comment(linker, "/MERGE:.rdata=INIT")
#pragma comment(linker, "/MERGE:.pdata=INIT")
#pragma comment(linker,"/MERGE:.CRT=INIT")

#include <ShlObj.h>
#include "includes.hpp"
#include "anticheat_bypass.hpp"
#define SETUP(x,y) x = *(decltype(x)*)(y);

bool g_initialized = false;
FILE* console_output = nullptr;

// Инициализация консоли
inline void init_console() {
	AllocConsole();
	
	// Перенаправляем stdout и stderr на консоль
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetStdHandle(STD_OUTPUT_HANDLE, hConsole);
	SetStdHandle(STD_ERROR_HANDLE, hConsole);
	
	SetConsoleTitleA("Aesthetic Dev - Debug Console");
	
	// Устанавливаем цвета консоли
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	const char* msg1 = "[+] Console initialized\n";
	const char* msg2 = "[+] Aesthetic Dev loaded\n";
	const char* msg3 = "========================================\n";
	
	DWORD written;
	WriteConsoleA(hConsole, msg1, lstrlenA(msg1), &written, NULL);
	WriteConsoleA(hConsole, msg2, lstrlenA(msg2), &written, NULL);
	WriteConsoleA(hConsole, msg3, lstrlenA(msg3), &written, NULL);
}

// Функция для логирования в консоль
inline void log_console(const char* format, ...) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	const char* prefix = "[INFO] ";
	DWORD written;
	WriteConsoleA(hConsole, prefix, lstrlenA(prefix), &written, NULL);
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
	char buffer[1024];
	va_list args;
	va_start(args, format);
	wvsprintfA(buffer, format, args);
	va_end(args);
	
	WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
	WriteConsoleA(hConsole, "\n", 1, &written, NULL);
}

inline void log_error(const char* format, ...) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	
	const char* prefix = "[ERROR] ";
	DWORD written;
	WriteConsoleA(hConsole, prefix, lstrlenA(prefix), &written, NULL);
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
	char buffer[1024];
	va_list args;
	va_start(args, format);
	wvsprintfA(buffer, format, args);
	va_end(args);
	
	WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
	WriteConsoleA(hConsole, "\n", 1, &written, NULL);
}

inline void log_success(const char* format, ...) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	const char* prefix = "[SUCCESS] ";
	DWORD written;
	WriteConsoleA(hConsole, prefix, lstrlenA(prefix), &written, NULL);
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
	char buffer[1024];
	va_list args;
	va_start(args, format);
	wvsprintfA(buffer, format, args);
	va_end(args);
	
	WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
	WriteConsoleA(hConsole, "\n", 1, &written, NULL);
}

inline bool get_temp_bundle_path(const wchar_t* bundle_name, wchar_t* out_path, size_t buffer_size) {
	if (!out_path || buffer_size < MAX_PATH) return false;
	
	wchar_t temp_path[MAX_PATH];
	for (int i = 0; i < MAX_PATH; i++) temp_path[i] = 0;
	
	DWORD result = GetTempPathW(MAX_PATH, temp_path);
	
	if (result == 0 || result > MAX_PATH) {
		log_error("Failed to get temp path. Error code: %d", GetLastError());
		return false;
	}
	
	u_crt::wcscpy(out_path, temp_path);
	u_crt::wcscat(out_path, bundle_name);
	
	DWORD attrib = GetFileAttributesW(out_path);
	if (attrib == INVALID_FILE_ATTRIBUTES || (attrib & FILE_ATTRIBUTE_DIRECTORY)) {
		log_error("Bundle file not found in temp: %S (Error: %d)", out_path, GetLastError());
		
		
		wchar_t local_app_data[MAX_PATH];
		for (int i = 0; i < MAX_PATH; i++) local_app_data[i] = 0;
		
		if (SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, local_app_data) == S_OK) {
			u_crt::wcscpy(out_path, local_app_data);
			u_crt::wcscat(out_path, L"\\Temp\\");
			u_crt::wcscat(out_path, bundle_name);
			
			attrib = GetFileAttributesW(out_path);
			if (attrib != INVALID_FILE_ATTRIBUTES && !(attrib & FILE_ATTRIBUTE_DIRECTORY)) {
				log_success("Found bundle in AppData\\Local\\Temp: %S", bundle_name);
				return true;
			}
		}
		
		return false;
	}
	
	log_success("Found bundle: %S", bundle_name);
	return true;
}

inline void init_all() {
	log_console("Initializing IL2CPP...");
	il2cpp::init();
	
	log_console("Initializing SDK...");
	u_sdk::init_sdk();
	
	log_console("Initializing classes...");
	init_classes();
	_init_classes();
	initallfuncs();
	
	log_console("Initializing hooks...");
	u_hooks::init_hooks();
	
	log_console("Loading bundles...");
	wchar_t bundle_path[MAX_PATH];
	

	if (get_temp_bundle_path(_(L"invis_bundles"), bundle_path, MAX_PATH)) {
		cheat_bundle = (uintptr_t)AssetBundle::LoadFromFile(bundle_path);
		if (cheat_bundle) log_success("Loaded: invis_bundles");
		else log_error("Failed to load: invis_bundles");
	}
	
	if (get_temp_bundle_path(_(L"fire_a"), bundle_path, MAX_PATH)) {
		fire_a = (uintptr_t)AssetBundle::LoadFromFile(bundle_path);
		if (fire_a) log_success("Loaded: fire_a");
		else log_error("Failed to load: fire_a");
	}
	
	if (get_temp_bundle_path(_(L"crystal.bundle"), bundle_path, MAX_PATH)) {
		ghkghjggh = (uintptr_t)AssetBundle::LoadFromFile(bundle_path);
		if (ghkghjggh) log_success("Loaded: crystal.bundle");
		else log_error("Failed to load: crystal.bundle");
	}
	
	if (get_temp_bundle_path(_(L"Geometric_Dissolve.unity3d"), bundle_path, MAX_PATH)) {
		cheat_bundle222 = (uintptr_t)AssetBundle::LoadFromFile(bundle_path);
		if (cheat_bundle222) log_success("Loaded: Geometric_Dissolve.unity3d");
		else log_error("Failed to load: Geometric_Dissolve.unity3d");
	}
	
	if (get_temp_bundle_path(_(L"ghost_hit_effect.air"), bundle_path, MAX_PATH)) {
		ghost_effect_bundle = (uintptr_t)AssetBundle::LoadFromFile(bundle_path);
		if (ghost_effect_bundle) log_success("Loaded: ghost_hit_effect.air");
		else log_error("Failed to load: ghost_hit_effect.air");
	}
	
	if (get_temp_bundle_path(_(L"world.assets12"), bundle_path, MAX_PATH)) {
		ghost_effect_bundle1 = (uintptr_t)AssetBundle::LoadFromFile(bundle_path);
		if (ghost_effect_bundle1) log_success("Loaded: world.assets12");
		else log_error("Failed to load: world.assets12");
	}
	
	if (get_temp_bundle_path(_(L"pidorassasasa"), bundle_path, MAX_PATH)) {
		offlinetray_bundle = (uintptr_t)AssetBundle::LoadFromFile(bundle_path);
		if (offlinetray_bundle) log_success("Loaded: pidorassasasa");
		else log_error("Failed to load: pidorassasasa");
	}
	
	log_success("All initialization complete!");
}
void init_hooks() {
	SETUP(ProjectileShoot::WriteToStream_, il2cpp::method(_("ProjectileShoot"), _("WriteToStream"), 1, _(""), _("ProtoBuf")));
	il2cpp::hook(&hkPerformanceUI, _("Update"), _("PerformanceUI"), _("Facepunch"), 0);
	il2cpp::hook(&CursorManagerUpdate_hk, _("Update"), _("CursorManager"), _(""), 0);
	il2cpp::hook(&menu, _("OnGUI"), _("DevControls"), _(""), 0);
	il2cpp::hook(&hkProjectileUpdate, _("Update"), _("Projectile"), _(""), 0);
	il2cpp::hook_virtual_function(_("BasePlayer"), _("ClientInput"), &hkBasePlayerClientInput);
}
DWORD WINAPI OpenYouTubeThread1(LPVOID lpParam) {
	Sleep(1000);
	WinExec("cmd.exe /c start https://t.me/AESTHETIC_WTF", SW_HIDE);
	return 0;
}

DWORD WINAPI OpenYouTubeThread(LPVOID lpParam) {
	Sleep(1000);
	WinExec("cmd.exe /c start https://www.youtube.com/@sasati42", SW_HIDE);
	return 0;
}

bool DllMain(uintptr_t hmodule) {
	
	if (!g_initialized) {
		
		init_console();
		
		log_console("Starting crash logger initialization...");
		if (!crash_logger::init()) {
			log_error("Failed to initialize crash logger!");
			MessageBoxA(nullptr, "Failed to initialize crash logger!\nCheck console for details", "Error", MB_OK | MB_ICONERROR);
			return false;
		}
		log_success("Crash logger initialized");
		
		log_console("Starting anticheat bypass...");
		if (!anticheat_bypass::protected_init((HMODULE)hmodule)) {
			log_error("Failed to initialize anticheat bypass!");
			return false;
		}
		log_success("Anticheat bypass initialized");
		
		menu_opened = true;
		
		log_console("Getting GameAssembly.dll base address...");
		g_base = (uintptr_t)il2cpp::methods::GetModuleBase(_("GameAssembly.dll"));	
		if (!g_base) {
			log_error("Failed to get GameAssembly.dll");
			MessageBoxA(nullptr, "Failed to get GameAssembly.dll\nCheck console for details", "Error", MB_OK | MB_ICONERROR);
			return false;
		}
		log_success("GameAssembly.dll base: 0x%llX", g_base);
		
		init_all();
		init_hooks();
		
		log_console("Loading config...");
		config::load_config(L"default");
		log_success("Config loaded");
		g_initialized = true;
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD written;
		const char* sep = "\n========================================\n";
		WriteConsoleA(hConsole, sep, lstrlenA(sep), &written, NULL);
		log_success("Aesthetic Dev fully loaded!");
		const char* sep2 = "========================================\n\n";
		WriteConsoleA(hConsole, sep2, lstrlenA(sep2), &written, NULL);
	}
	return true;
}