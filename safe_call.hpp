#pragma once
#include "crash_logger.hpp"

// Макрос для проверки указателей
#define CHECK_PTR(ptr, ret_val) \
    if (!(ptr)) { \
        crash_logger::log_error("Null pointer check failed: %s at %s:%d", #ptr, __FILE__, __LINE__); \
        return ret_val; \
    }

// Макрос для проверки указателей без возврата
#define CHECK_PTR_VOID(ptr) \
    if (!(ptr)) { \
        crash_logger::log_error("Null pointer check failed: %s at %s:%d", #ptr, __FILE__, __LINE__); \
        return; \
    }

// Макрос для логирования входа в функцию
#define LOG_FUNC_ENTRY() \
    crash_logger::log_info("Entering function: %s at %s:%d", __FUNCTION__, __FILE__, __LINE__)

// Макрос для логирования выхода из функции
#define LOG_FUNC_EXIT() \
    crash_logger::log_info("Exiting function: %s at %s:%d", __FUNCTION__, __FILE__, __LINE__)

// Упрощенное логирование функций
#define LOG_FUNCTION_SCOPE() \
    crash_logger::log_info("-> Entering: %s (%s:%d)", __FUNCTION__, __FILE__, __LINE__)
