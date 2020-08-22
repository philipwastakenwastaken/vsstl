#include "vsstlpch.h"
#include "log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace vsstl {

    std::shared_ptr<spdlog::logger> Log::logger;
    std::shared_ptr<spdlog::logger> Log::core_logger;

    void Log::init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        logger = spdlog::stdout_color_mt("HOST");
        logger->set_level(spdlog::level::trace);

        core_logger = spdlog::stdout_color_mt("CORE");
        core_logger->set_level(spdlog::level::trace);
    }
}