#pragma once
#include <memory>

#define FMT_DEPRECATED
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace vsstl {

    class Log {

    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger>& get_logger() {return logger;}
        inline static std::shared_ptr<spdlog::logger>& get_core_logger() {return core_logger;}

    private:
        static std::shared_ptr<spdlog::logger> logger;
        static std::shared_ptr<spdlog::logger> core_logger;
    };

}

#ifdef VSSTL_ENABLE_LOGGING
    #define VSSTL_ERROR(...)           ::vsstl::Log::get_logger()->error(__VA_ARGS__)
    #define VSSTL_WARN(...)            ::vsstl::Log::get_logger()->warn(__VA_ARGS__)
    #define VSSTL_INFO(...)            ::vsstl::Log::get_logger()->info(__VA_ARGS__)
    #define VSSTL_TRACE(...)           ::vsstl::Log::get_logger()->trace(__VA_ARGS__)
    #define VSSTL_CRITICAL(...)        ::vsstl::Log::get_logger()->critical(__VA_ARGS__)

    #define VSSTL_CORE_ERROR(...)           ::vsstl::Log::get_core_logger()->error(__VA_ARGS__)
    #define VSSTL_CORE_WARN(...)            ::vsstl::Log::get_core_logger()->warn(__VA_ARGS__)
    #define VSSTL_CORE_INFO(...)            ::vsstl::Log::get_core_logger()->info(__VA_ARGS__)
    #define VSSTL_CORE_TRACE(...)           ::vsstl::Log::get_core_logger()->trace(__VA_ARGS__)
    #define VSSTL_CORE_CRITICAL(...)        ::vsstl::Log::get_core_logger()->critical(__VA_ARGS__)
#else
    #define VSSTL_ERROR(...)
    #define VSSTL_WARN(...)
    #define VSSTL_INFO(...)
    #define VSSTL_TRACE(...)
    #define VSSTL_CRITICAL(...)

    #define VSSTL_CORE_ERROR(...)
    #define VSSTL_CORE_WARN(...)
    #define VSSTL_CORE_INFO(...)
    #define VSSTL_CORE_TRACE(...)
    #define VSSTL_CORE_CRITICAL(...)
#endif