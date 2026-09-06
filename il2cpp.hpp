template <typename T>
constexpr uint32_t static_crc32(const T& data)
{
	constexpr uint32_t table[256] = {
		// ����� ������ ���� ������� CRC32
	};

	uint32_t crc = 0xFFFFFFFF;
	for (size_t i = 0; i < sizeof(data); ++i) {
		crc = table[(crc ^ rc<const uint8_t*>(&data)[i]) & 0xFF] ^ (crc >> 8);
	}
	return crc ^ 0xFFFFFFFF;
}
namespace il2cpp {
	namespace methods {
		__forceinline PVOID GetExport(PBYTE hDll, const char* Name)
		{
			//process image data
			PIMAGE_NT_HEADERS NT_Head = (PIMAGE_NT_HEADERS)(hDll + ((PIMAGE_DOS_HEADER)hDll)->e_lfanew);
			PIMAGE_EXPORT_DIRECTORY ExportDir = (PIMAGE_EXPORT_DIRECTORY)(hDll + NT_Head->OptionalHeader.DataDirectory[0].VirtualAddress);

			//process list
			for (DWORD i = 0; i < ExportDir->NumberOfNames; i++)
			{
				//get ordinal & name
				USHORT Ordinal = ((USHORT*)(hDll + ExportDir->AddressOfNameOrdinals))[i];
				const char* ExpName = (const char*)hDll + ((DWORD*)(hDll + ExportDir->AddressOfNames))[i];
				if (u_crt::StrCmp(Name, ExpName, true))
					return (PVOID)(hDll + ((DWORD*)(hDll + ExportDir->AddressOfFunctions))[Ordinal]);
			} return nullptr;
		}

		__declspec(noinline) PBYTE GetModuleBase(const char* ModuleName)
		{
		    PPEB_LDR_DATA Ldr = ((PTEB)__readgsqword(FIELD_OFFSET(NT_TIB, Self)))->ProcessEnvironmentBlock->Ldr; void* ModBase = nullptr;
		    for (PLIST_ENTRY CurEnt = Ldr->InMemoryOrderModuleList.Flink; CurEnt != &Ldr->InMemoryOrderModuleList; CurEnt = CurEnt->Flink) {
		        LDR_DATA_TABLE_ENTRY* pEntry = CONTAINING_RECORD(CurEnt, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
		        PUNICODE_STRING BaseDllName = (PUNICODE_STRING)&pEntry->Reserved4[0];
		        if (!ModuleName || u_crt::StrCmp(ModuleName, BaseDllName->Buffer, false))
		            return (PBYTE)pEntry->DllBase;
		    }
	
		    return nullptr;
		}
		PBYTE FindPattern(const char* Pattern, const char* Module = nullptr)
		{
			//find pattern utils
#define InRange(x, a, b) (x >= a && x <= b) 
#define GetBits(x) (InRange(x, '0', '9') ? (x - '0') : ((x - 'A') + 0xA))
#define GetByte(x) ((BYTE)(GetBits(x[0]) << 4 | GetBits(x[1])))

//get module range
			PBYTE ModuleStart = (PBYTE)GetModuleBase(Module); if (!ModuleStart) return nullptr;
			PIMAGE_NT_HEADERS NtHeader = ((PIMAGE_NT_HEADERS)(ModuleStart + ((PIMAGE_DOS_HEADER)ModuleStart)->e_lfanew));
			PBYTE ModuleEnd = (PBYTE)(ModuleStart + NtHeader->OptionalHeader.SizeOfImage - 0x1000); ModuleStart += 0x1000;

			//scan pattern main
			PBYTE FirstMatch = nullptr;
			const char* CurPatt = Pattern;
			for (; ModuleStart < ModuleEnd; ++ModuleStart)
			{
				bool SkipByte = (CurPatt[0] == '?');
				if (SkipByte || *ModuleStart == GetByte(CurPatt)) {
					if (!FirstMatch)
						FirstMatch = ModuleStart;

					CurPatt += 3;

					if (CurPatt[-1] == 0)
						return FirstMatch;
				}

				else if (FirstMatch) {
					ModuleStart = FirstMatch;
					FirstMatch = nullptr;
					CurPatt = Pattern;
				}
			}

			return nullptr;
		}
		typedef int(__stdcall* GPC)(DWORD64);
		typedef DWORD64(__stdcall* AGI)(DWORD64);
		typedef DWORD64(__stdcall* Dm)();
		typedef DWORD64(__stdcall* CFN)(DWORD64, const char*, const char*);
		typedef DWORD64(__stdcall* Call)(DWORD64, DWORD64);
		typedef DWORD64(*resolve)(const char*);
		typedef DWORD64(__stdcall* Ptr)(DWORD64, DWORD64*);	
		typedef DWORD64* (__cdecl* DGA)(void* domain, DWORD64* size);
		typedef DWORD64(__stdcall* iCall)(const char*);
		typedef const char* (__stdcall* Ngp)(DWORD64, DWORD64 index);
		typedef const char* (__stdcall* Mgp)(DWORD64);
		//typedef uintptr_t(__stdcall* newstr)(uintptr_t);
		//newstr il2cpp_string_new = 0;
		typedef int(__stdcall* t_sprintf)(wchar_t* buffer, const wchar_t* format, ...);
		t_sprintf f_swprint = nullptr;
		Ngp method_get_param_name = 0;
		Mgp method_get_name = 0;
		Ptr class_get_methods = 0;
		Ptr class_get_fields = 0;
		Dm domain_get = 0;
		DGA domain_get_assemblies = 0;
		AGI assembly_get_image = 0;
		CFN class_from_name = 0;
		AGI field_get_offset = 0;
		AGI runtime_class_init = 0;
		Ptr field_static_get_value = 0;
		GPC method_get_param_count = 0;
		Call array_new = 0;
		AGI object_new = 0;
		iCall resolve_icall = 0;
		AGI type_get_object = 0;
		AGI class_get_type = 0;
		resolve new_string = 0;
	}

	inline void init() {
		//methods::il2cpp_string_new = (methods::newstr)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_string_new")));
		methods::f_swprint = (methods::t_sprintf)(methods::GetExport(methods::GetModuleBase(_("msvcrt.dll")), _("_swprintf")));
		methods::runtime_class_init = (methods::AGI)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_runtime_class_init")));
		methods::method_get_param_name = (methods::Ngp)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_method_get_param_name")));
		methods::method_get_name = (methods::Mgp)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_method_get_name")));
		methods::method_get_param_count = (methods::GPC)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_method_get_param_count")));
		methods::field_static_get_value = (methods::Ptr)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_field_static_get_value")));
		methods::field_get_offset = (methods::AGI)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_field_get_offset")));
		methods::class_from_name = (methods::CFN)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_class_from_name")));
		methods::assembly_get_image = (methods::AGI)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_assembly_get_image")));
		methods::domain_get_assemblies = (methods::DGA)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_domain_get_assemblies")));
		methods::domain_get = (methods::Dm)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_domain_get")));
		methods::class_get_fields = (methods::Ptr)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_class_get_fields")));
		methods::class_get_methods = (methods::Ptr)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_class_get_methods")));
		methods::array_new = (methods::Call)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_array_new")));
		methods::object_new = (methods::AGI)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_object_new")));
		methods::resolve_icall = (methods::iCall)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_resolve_icall")));
		methods::type_get_object = (methods::AGI)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_type_get_object")));
		methods::class_get_type = (methods::AGI)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_class_get_type")));
		methods::new_string = (methods::resolve)(methods::GetExport(methods::GetModuleBase(_("GameAssembly.dll")), _("il2cpp_string_new")));
	}

	uintptr_t init_class(const char* name, const char* name_space = _("")) {

		uintptr_t domain = methods::domain_get();

		uintptr_t nrofassemblies = 0;
		uintptr_t* assemblies;
		assemblies = methods::domain_get_assemblies((void*)domain, &nrofassemblies);

		for (int i = 0; i < nrofassemblies; i++) {
			uintptr_t img = methods::assembly_get_image(assemblies[i]);

			uintptr_t kl = methods::class_from_name(img, name_space, name);
			if (!kl) continue;

			return kl;
		}
		return 0;
	}

	uintptr_t type_object(const char* name_space, const char* name)
	{
		auto klass = init_class(name, name_space);
		return methods::type_get_object(methods::class_get_type(klass));
	}

	uintptr_t method(const char* kl, const char* name, int argument_number = -1, char* arg_name = _(""), const char* name_space = _(""), int selected_argument = -1) {
		uintptr_t iter = 0;
		uintptr_t f;
		auto klass = init_class(kl, name_space);
		
		if (!klass) {
			crash_logger::log_error("method: Failed to init_class for %s::%s", name_space, kl);
			return 0;
		}

		while (f = methods::class_get_methods(klass, &iter)) {

			const char* st = methods::method_get_name(f);

			if (u_crt::strcmp(st, (char*)name)) {
				if (selected_argument >= 0 && arg_name) {
					int method_count = methods::method_get_param_count(f);
					if (selected_argument > method_count || (argument_number >= 0 && method_count != argument_number)) continue;

					const char* argname;
					if (method_count > 0) {
						argname = methods::method_get_param_name(f, selected_argument - 1);
					}
					else
						argname = (char*)_("-");

					if (!argname || !u_crt::strcmp(argname, arg_name)) continue;
				}

				return f;
			}
		}
		
		crash_logger::log_error("method: Method not found %s::%s::%s", name_space, kl, name);
		return 0;
	}
	uintptr_t hook(void* our_func, const char* function_to_hook, const char* class_to_hook, const char* name_space = _(""), int argument_number = -1, char* argument_name = _("")) {
		auto il2cpp_method = method(class_to_hook, function_to_hook, argument_number, argument_name, name_space);

		*rc<void**>(il2cpp_method) = our_func;
		return il2cpp_method;
	}

	uintptr_t field(uintptr_t klass, char* field_name, bool get_offset = true) {
		uintptr_t out = 0;
		uintptr_t il2cpp_field;

		while (il2cpp_field = methods::class_get_fields(klass, &out)) {

			char* name = (char*)*rc<uintptr_t*>(il2cpp_field);
			if (!name)
				break;

			if (!u_crt::m_strcmp(name, field_name)) {
				continue;
			}
			if (!get_offset)
				return il2cpp_field;

			uintptr_t offset = methods::field_get_offset(il2cpp_field);
			return offset;
		}
		return 0;
	}

	uintptr_t value(const char* kl, char* name, bool get_offset = true) {

		auto klass = init_class(kl);

		if (get_offset) {
			auto field_offset = field(klass, name);
			return field_offset;
		}
		else
		{
			auto _field = field(klass, name, false);

			uintptr_t ret;
			methods::field_static_get_value(_field, &ret);
			return ret;
		}
		return 0;
	}
	uintptr_t hook_virtual_function(const char* classname, const char* function_to_hook, void* our_func, const char* name_space = _("")) {
		uintptr_t search = *rc<uintptr_t*>(il2cpp::method(classname, function_to_hook, -1, _(""), name_space));
		uintptr_t table = il2cpp::init_class(classname, name_space);

		if (search == (uintptr_t)our_func)
			return (uintptr_t)our_func;

		for (uintptr_t i = table; i <= table + 0x1500; i += 0x1) {
			uintptr_t addr = *rc<uintptr_t*>(i);
			if (addr == search) {
				*rc<uintptr_t*>(i) = (uintptr_t)our_func;
				return addr;
			}
		}
		return (uintptr_t)our_func;
	}
}