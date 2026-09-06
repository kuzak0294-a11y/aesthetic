#pragma once
#include <Windows.h>
#include <DbgHelp.h>
#include <time.h>

#pragma comment(lib, "dbghelp.lib")

namespace crash_logger {
    static HANDLE log_file = INVALID_HANDLE_VALUE;
    static char log_path[MAX_PATH];

   
    inline void write_log(const char* format, ...) {
        if (log_file == INVALID_HANDLE_VALUE) return;

        char buffer[2048];
        va_list args;
        va_start(args, format);
        int len = wvsprintfA(buffer, format, args);
        va_end(args);

        if (len > 0) {
            DWORD written;
            WriteFile(log_file, buffer, len, &written, nullptr);
            WriteFile(log_file, "\r\n", 2, &written, nullptr);
            FlushFileBuffers(log_file);
        }
    }
    inline void get_timestamp(char* buffer, size_t size) {
        SYSTEMTIME st;
        GetLocalTime(&st);
        wsprintfA(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
            st.wYear, st.wMonth, st.wDay,
            st.wHour, st.wMinute, st.wSecond);
    }
    inline void create_minidump(EXCEPTION_POINTERS* exception_info) {
        char dump_path[MAX_PATH];
        char timestamp[64];
        get_timestamp(timestamp, sizeof(timestamp));
        for (int i = 0; timestamp[i]; i++) {
            if (timestamp[i] == ' ' || timestamp[i] == ':') {
                timestamp[i] = '_';
            }
        }
        char temp_path[MAX_PATH];
        GetTempPathA(MAX_PATH, temp_path);
        wsprintfA(dump_path, "%scrash_dump_%s.dmp", temp_path, timestamp);

        HANDLE dump_file = CreateFileA(dump_path, GENERIC_WRITE, 0, nullptr,
            CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

        if (dump_file != INVALID_HANDLE_VALUE) {
            MINIDUMP_EXCEPTION_INFORMATION dump_info;
            dump_info.ThreadId = GetCurrentThreadId();
            dump_info.ExceptionPointers = exception_info;
            dump_info.ClientPointers = FALSE;

            MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
                dump_file, MiniDumpNormal, &dump_info, nullptr, nullptr);

            CloseHandle(dump_file);
            write_log("[MINIDUMP] Created: %s", dump_path);
        }
    }

    // Обработчик исключений
    inline LONG WINAPI exception_handler(EXCEPTION_POINTERS* exception_info) {
        char timestamp[64];
        get_timestamp(timestamp, sizeof(timestamp));

        // Вывод в консоль
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole != INVALID_HANDLE_VALUE) {
            DWORD written;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            const char* header = "\n========================================\n[CRASH DETECTED]\n========================================\n";
            WriteConsoleA(hConsole, header, lstrlenA(header), &written, NULL);
            
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            
            char buffer[512];
            wsprintfA(buffer, "Time: %s\n", timestamp);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            wsprintfA(buffer, "Exception Code: 0x%08X\n", exception_info->ExceptionRecord->ExceptionCode);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            wsprintfA(buffer, "Exception Address: 0x%p\n", exception_info->ExceptionRecord->ExceptionAddress);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            wsprintfA(buffer, "Exception Flags: 0x%08X\n", exception_info->ExceptionRecord->ExceptionFlags);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
        }

        write_log("========================================");
        write_log("[CRASH] Time: %s", timestamp);
        write_log("[CRASH] Exception Code: 0x%08X", exception_info->ExceptionRecord->ExceptionCode);
        write_log("[CRASH] Exception Address: 0x%p", exception_info->ExceptionRecord->ExceptionAddress);
        write_log("[CRASH] Exception Flags: 0x%08X", exception_info->ExceptionRecord->ExceptionFlags);

        // Дополнительная информация об исключении
        switch (exception_info->ExceptionRecord->ExceptionCode) {
        case EXCEPTION_ACCESS_VIOLATION:
            if (hConsole != INVALID_HANDLE_VALUE) {
                DWORD written;
                const char* msg = "Type: Access Violation\n";
                WriteConsoleA(hConsole, msg, lstrlenA(msg), &written, NULL);
            }
            write_log("[CRASH] Type: Access Violation");
            if (exception_info->ExceptionRecord->NumberParameters >= 2) {
                if (hConsole != INVALID_HANDLE_VALUE) {
                    DWORD written;
                    char buffer[256];
                    wsprintfA(buffer, "Operation: %s at address 0x%p\n",
                        exception_info->ExceptionRecord->ExceptionInformation[0] ? "Write" : "Read",
                        (void*)exception_info->ExceptionRecord->ExceptionInformation[1]);
                    WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
                }
                write_log("[CRASH] Operation: %s at address 0x%p",
                    exception_info->ExceptionRecord->ExceptionInformation[0] ? "Write" : "Read",
                    (void*)exception_info->ExceptionRecord->ExceptionInformation[1]);
            }
            break;
        case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
            if (hConsole != INVALID_HANDLE_VALUE) {
                DWORD written;
                const char* msg = "Type: Array Bounds Exceeded\n";
                WriteConsoleA(hConsole, msg, lstrlenA(msg), &written, NULL);
            }
            write_log("[CRASH] Type: Array Bounds Exceeded");
            break;
        case EXCEPTION_STACK_OVERFLOW:
            if (hConsole != INVALID_HANDLE_VALUE) {
                DWORD written;
                const char* msg = "Type: Stack Overflow\n";
                WriteConsoleA(hConsole, msg, lstrlenA(msg), &written, NULL);
            }
            write_log("[CRASH] Type: Stack Overflow");
            break;
        case EXCEPTION_ILLEGAL_INSTRUCTION:
            if (hConsole != INVALID_HANDLE_VALUE) {
                DWORD written;
                const char* msg = "Type: Illegal Instruction\n";
                WriteConsoleA(hConsole, msg, lstrlenA(msg), &written, NULL);
            }
            write_log("[CRASH] Type: Illegal Instruction");
            break;
        default:
            if (hConsole != INVALID_HANDLE_VALUE) {
                DWORD written;
                const char* msg = "Type: Unknown Exception\n";
                WriteConsoleA(hConsole, msg, lstrlenA(msg), &written, NULL);
            }
            write_log("[CRASH] Type: Unknown Exception");
            break;
        }
        
        if (hConsole != INVALID_HANDLE_VALUE) {
            DWORD written;
            char buffer[512];
            const char* regs = "\n[REGISTERS]\n";
            WriteConsoleA(hConsole, regs, lstrlenA(regs), &written, NULL);
            
            wsprintfA(buffer, "  RAX: 0x%016llX  RBX: 0x%016llX\n", 
                exception_info->ContextRecord->Rax, exception_info->ContextRecord->Rbx);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            wsprintfA(buffer, "  RCX: 0x%016llX  RDX: 0x%016llX\n",
                exception_info->ContextRecord->Rcx, exception_info->ContextRecord->Rdx);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            wsprintfA(buffer, "  RSI: 0x%016llX  RDI: 0x%016llX\n",
                exception_info->ContextRecord->Rsi, exception_info->ContextRecord->Rdi);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            wsprintfA(buffer, "  RBP: 0x%016llX  RSP: 0x%016llX\n",
                exception_info->ContextRecord->Rbp, exception_info->ContextRecord->Rsp);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            wsprintfA(buffer, "  RIP: 0x%016llX\n", exception_info->ContextRecord->Rip);
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            
            const char* footer = "========================================\n\n";
            WriteConsoleA(hConsole, footer, lstrlenA(footer), &written, NULL);
        }
        
        write_log("[REGISTERS]");
        write_log("  RAX: 0x%016llX  RBX: 0x%016llX", 
            exception_info->ContextRecord->Rax, exception_info->ContextRecord->Rbx);
        write_log("  RCX: 0x%016llX  RDX: 0x%016llX",
            exception_info->ContextRecord->Rcx, exception_info->ContextRecord->Rdx);
        write_log("  RSI: 0x%016llX  RDI: 0x%016llX",
            exception_info->ContextRecord->Rsi, exception_info->ContextRecord->Rdi);
        write_log("  RBP: 0x%016llX  RSP: 0x%016llX",
            exception_info->ContextRecord->Rbp, exception_info->ContextRecord->Rsp);
        write_log("  RIP: 0x%016llX", exception_info->ContextRecord->Rip);
        create_minidump(exception_info);
        MessageBoxA(nullptr, "Application crashed! Check console and crash_log.txt for details.",
            "Crash Detected", MB_OK | MB_ICONERROR);

        return EXCEPTION_EXECUTE_HANDLER;
    }

    
    inline bool init() {
        // Логирование отключено - файл не создается
        log_file = INVALID_HANDLE_VALUE;
        SetUnhandledExceptionFilter(exception_handler);
        return true;
    }
    inline void shutdown() {
        if (log_file != INVALID_HANDLE_VALUE) {
            char timestamp[64];
            get_timestamp(timestamp, sizeof(timestamp));

            write_log("========================================");
            write_log("[SHUTDOWN] Time: %s", timestamp);
            write_log("========================================");

            CloseHandle(log_file);
            log_file = INVALID_HANDLE_VALUE;
        }
    }
    inline void log_info(const char* format, ...) {
        char timestamp[64];
        get_timestamp(timestamp, sizeof(timestamp));

        char buffer[2048];
        wsprintfA(buffer, "[%s] [INFO] ", timestamp);

        char msg[1024];
        va_list args;
        va_start(args, format);
        wvsprintfA(msg, format, args);
        va_end(args);

        lstrcatA(buffer, msg);

        // Вывод в консоль
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole != INVALID_HANDLE_VALUE) {
            DWORD written;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Cyan
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            WriteConsoleA(hConsole, "\n", 1, &written, NULL);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset
        }

        // Запись в файл (если включено)
        if (log_file != INVALID_HANDLE_VALUE) {
            DWORD written;
            WriteFile(log_file, buffer, lstrlenA(buffer), &written, nullptr);
            WriteFile(log_file, "\r\n", 2, &written, nullptr);
            FlushFileBuffers(log_file);
        }
    }
    inline void log_error(const char* format, ...) {
        char timestamp[64];
        get_timestamp(timestamp, sizeof(timestamp));

        char buffer[2048];
        wsprintfA(buffer, "[%s] [ERROR] ", timestamp);

        char msg[1024];
        va_list args;
        va_start(args, format);
        wvsprintfA(msg, format, args);
        va_end(args);

        lstrcatA(buffer, msg);

        // Вывод в консоль
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole != INVALID_HANDLE_VALUE) {
            DWORD written;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Red
            WriteConsoleA(hConsole, buffer, lstrlenA(buffer), &written, NULL);
            WriteConsoleA(hConsole, "\n", 1, &written, NULL);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset
        }

        // Запись в файл (если включено)
        if (log_file != INVALID_HANDLE_VALUE) {
            DWORD written;
            WriteFile(log_file, buffer, lstrlenA(buffer), &written, nullptr);
            WriteFile(log_file, "\r\n", 2, &written, nullptr);
            FlushFileBuffers(log_file);
        }
    }
}
