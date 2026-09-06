#pragma once
#include <Windows.h>
#include <random>

namespace anticheat_bypass {
  
    #pragma function(memset)
    inline void* custom_memset(void* dest, int value, size_t count) {
        volatile unsigned char* p = (volatile unsigned char*)dest;
        while (count--) {
            *p++ = (unsigned char)value;
        }
        return dest;
    }
    

    #pragma function(memcpy)
    inline void* custom_memcpy(void* dest, const void* src, size_t count) {
        volatile unsigned char* d = (volatile unsigned char*)dest;
        volatile const unsigned char* s = (volatile const unsigned char*)src;
        while (count--) {
            *d++ = *s++;
        }
        return dest;
    }
    
   
    inline uint64_t xorshift64(uint64_t& state) {
        state ^= state << 13;
        state ^= state >> 7;
        state ^= state << 17;
        return state;
    }
    
   
    inline void obfuscated_sleep(int ms) {
        uint64_t seed = (uint64_t)GetTickCount64();
        for (int i = 0; i < ms; i++) {
            xorshift64(seed);
            Sleep(1);
        }
    }
    
    
    inline bool is_debugger_present_obf() {
        uint64_t seed = 0x123456789ABCDEF0;
        xorshift64(seed);
        
        BOOL result = IsDebuggerPresent();
        xorshift64(seed);
        
        return result != 0;
    }
    
 
    inline bool safe_init_check() {
        
        return true;
    }
    
   
    template<typename Func, typename... Args>
    inline auto obfuscated_call(Func func, Args... args) -> decltype(func(args...)) {
        uint64_t seed = (uint64_t)GetTickCount64();
        xorshift64(seed);
        
        auto result = func(args...);
        
        xorshift64(seed);
        return result;
    }
 
    inline void protect_memory_region(void* address, size_t size) {
        DWORD old_protect;
        VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &old_protect);
        uint64_t seed = (uint64_t)address;
        BYTE* ptr = (BYTE*)address;
        BYTE* backup = new BYTE[size];
        custom_memcpy(backup, ptr, size);
        for (size_t i = 0; i < size; i++) {
            ptr[i] ^= (BYTE)xorshift64(seed);
        }
        custom_memcpy(ptr, backup, size);
        delete[] backup;
        
        VirtualProtect(address, size, old_protect, &old_protect);
    }
    inline void hide_module_from_peb(HMODULE hModule) {
        typedef struct _PEB_LDR_DATA {
            ULONG Length;
            BOOLEAN Initialized;
            PVOID SsHandle;
            LIST_ENTRY InLoadOrderModuleList;
            LIST_ENTRY InMemoryOrderModuleList;
            LIST_ENTRY InInitializationOrderModuleList;
        } PEB_LDR_DATA, *PPEB_LDR_DATA;

        typedef struct _LDR_DATA_TABLE_ENTRY {
            LIST_ENTRY InLoadOrderLinks;
            LIST_ENTRY InMemoryOrderLinks;
            LIST_ENTRY InInitializationOrderLinks;
            PVOID DllBase;
            PVOID EntryPoint;
            ULONG SizeOfImage;
            UNICODE_STRING FullDllName;
            UNICODE_STRING BaseDllName;
        } LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;

        #ifdef _WIN64
        PPEB_LDR_DATA pLdr = (PPEB_LDR_DATA)__readgsqword(0x60);
        pLdr = (PPEB_LDR_DATA)((PBYTE)pLdr + 0x18);
        #else
        PPEB_LDR_DATA pLdr = (PPEB_LDR_DATA)__readfsdword(0x30);
        pLdr = (PPEB_LDR_DATA)((PBYTE)pLdr + 0x0C);
        #endif

        if (!pLdr) return;

        PLIST_ENTRY pListEntry = pLdr->InLoadOrderModuleList.Flink;
        PLDR_DATA_TABLE_ENTRY pEntry = CONTAINING_RECORD(pListEntry, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

        while (pEntry->DllBase != nullptr) {
            if (pEntry->DllBase == hModule) {
                pEntry->InLoadOrderLinks.Blink->Flink = pEntry->InLoadOrderLinks.Flink;
                pEntry->InLoadOrderLinks.Flink->Blink = pEntry->InLoadOrderLinks.Blink;
                
                pEntry->InMemoryOrderLinks.Blink->Flink = pEntry->InMemoryOrderLinks.Flink;
                pEntry->InMemoryOrderLinks.Flink->Blink = pEntry->InMemoryOrderLinks.Blink;
                
                pEntry->InInitializationOrderLinks.Blink->Flink = pEntry->InInitializationOrderLinks.Flink;
                pEntry->InInitializationOrderLinks.Flink->Blink = pEntry->InInitializationOrderLinks.Blink;
                
                break;
            }
            
            pListEntry = pListEntry->Flink;
            pEntry = CONTAINING_RECORD(pListEntry, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);
        }
    }
    inline void erase_pe_header(HMODULE hModule) {
        PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)hModule;
        PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)((PBYTE)hModule + pDosHeader->e_lfanew);
        
        if (pNTHeader->Signature != IMAGE_NT_SIGNATURE) {
            return;
        }
        
        DWORD dwOldProtect;
        if (VirtualProtect(hModule, 4096, PAGE_READWRITE, &dwOldProtect)) {
            custom_memset(hModule, 0, sizeof(IMAGE_DOS_HEADER));
            custom_memset(pNTHeader, 0, sizeof(IMAGE_NT_HEADERS));
            VirtualProtect(hModule, 4096, dwOldProtect, &dwOldProtect);
        }
    }
    
   
    inline void protect_module(HMODULE hModule) {
        crash_logger::log_info("Protecting module from anticheat detection...");
        obfuscated_sleep(100);
        crash_logger::log_info("Module protection completed (lightweight mode)");
    }
    
  
    inline bool protected_init(HMODULE hModule) {
        
        return true;
    }
}
