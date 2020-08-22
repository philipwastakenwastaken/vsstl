#pragma once

// controls parameters related to building in different modes

#ifdef VSSTL_DEBUG
    #define VSSTL_ENABLE_ASSERT
    #define VSSTL_ENABLE_LOGGING
#elif VSSTL_RELEASE
    #define VSSTL_ENABLE_ASSERT
    #define VSSTL_ENABLE_LOGGING
#endif

#ifdef VSSTL_PLATFORM_WINDOWS
    #define VSSTL_ABORT __debugbreak()
#elif VSSTL_PLATFORM_MACOSX
    #define VSSTL_ABORT __builtin_trap()
#elif VSSTL_PLATFORM_LINUX
    #define VSSTL_ABORT __builtin_trap()
#endif

#ifdef VSSTL_ENABLE_ASSERT
    #define VSSTL_ASSERT(x, ...) {if (!(x)) {VSSTL_ERROR("Assertion failed: {0}", __VA_ARGS__); VSSTL_ABORT;}}
    #define VSSTL_STATIC_ASSERT(x, ...) {static_assert(x, __VA_ARGS__);}
#else
    #define VSSTL_ASSERT(x, ...)
    #define VSSTL_STATIC_ASSERT(x, ...)
#endif

