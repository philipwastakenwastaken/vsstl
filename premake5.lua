workspace "vsstl"
    architecture "x64"
    startproject "sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist",
        "Test"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "vsstl"
    location "vsstl"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    staticruntime "on"
    rtti ("off")
    exceptionhandling ("off")

    defines "SPDLOG_NO_EXCEPTIONS" -- required when exception are disabled for spdlog
    pchheader "vsstlpch.h"
    pchsource "vsstl/src/vsstlpch.cpp"
    warnings "extra"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/",
        "%{prj.name}/src/",
    }

    filter "system:windows"
        systemversion "latest"
        toolset "msc"
        defines {
            "VSSTL_PLATFORM_WINDOWS"
        }

    filter "system:macosx"
        systemversion "latest"
        toolset "clang"
        buildoptions {"-march=native"}
        defines {
            "VSSTL_PLATFORM_MACOSX"
        }

    filter "system:linux"
        systemversion "latest"
        toolset "gcc"
        buildoptions {"-march=native"}
        defines {
            "VSSTL_PLATFORM_LINUX"
        }

    filter "configurations:Debug"
        defines "VSSTL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Test"
        defines "VSSTL_DEBUG"
        runtime "Debug"
        symbols "on"
        optimize "full"
        flags {"LinkTimeOptimization"}

    filter "configurations:Release"
        defines "VSSTL_RELEASE"
        runtime "Release"
        flags {"LinkTimeOptimization"}
        optimize "full"
        symbols "on"

    filter "configurations:Dist"
        defines "VSSTL_DIST"
        runtime "Release"
        flags {"LinkTimeOptimization"}
        optimize "full"

project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    staticruntime "on"
    rtti ("off")
    exceptionhandling ("off")

    defines "SPDLOG_NO_EXCEPTIONS" -- required when exception are disabled for spdlog
    warnings "extra"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/*.h",
        "%{prj.name}/src/*.cpp",
        "tests/*.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "vsstl/src",
        "vsstl/",
        "tests/"
    }

    links {
        "vsstl"
    }

    filter "system:windows"
        systemversion "latest"
        toolset "msc"

    filter "system:macosx"
        systemversion "latest"
        toolset "clang"
        buildoptions {"-march=native"}

    filter "system:linux"
        systemversion "latest"
        toolset "gcc"
        buildoptions {"-march=native"}

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Test"
        runtime "Debug"
        symbols "on"
        optimize "full"
        flags {"LinkTimeOptimization"}

    filter "configurations:Release"
        runtime "Release"
        flags {"LinkTimeOptimization"}
        optimize "full"
        symbols "on"

    filter "configurations:Dist"
        runtime "Release"
        flags {"LinkTimeOptimization"}
        optimize "full"