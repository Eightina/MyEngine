workspace "MyEngine"
    architecture "x64"
    startproject "Sandbox"
    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- debug-windows-x64

project "MyEngine"
    location "MyEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ME_PLATFORM_WINDOWS",
            "ME_BUILD_DLL",
            -- "_WINDLL",
            -- "_UNICODE",
            -- "UNICODE"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
            -- ("{COPY} %{cfg.buildtarget.relpath} "../bin/" .. outputdir .. "/Sandbox/\"")
        }
        -- copy dll to be with exe, remember the slash in the end as it's a dir
        -- wrong xcopy /Q /E /Y /I ..\bin\Debug-windows-x86_64\MyEngine\MyEngine.dll ..\bin\Debug-windows-x86_64\Sandbox
        -- right xcopy /Q /E /Y /I ..\bin\Debug-windows-x86_64\MyEngine\MyEngine.dll "..\bin\Debug-windows-x86_64\Sandbox\

        filter "configurations:Debug"
            defines "HZ_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "HZ_RELEASE"
            symbols "On"

        filter "configurations:Dist"
            defines "HZ_DIST"
            symbols "On"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "MyEngine/vendor/spdlog/include",
        "MyEngine/src"
    }

    links {
        "MyEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ME_PLATFORM_WINDOWS"
            -- "_WINDLL",
            -- "_UNICODE",
            -- "UNICODE"
        }

        filter "configurations:Debug"
            defines "HZ_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "HZ_RELEASE"
            symbols "On"

        filter "configurations:Dist"
            defines "HZ_DIST"
            symbols "On"