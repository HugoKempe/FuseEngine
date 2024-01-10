project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    files {
        -- Sandbox source files
        "src/**.h", "src/**.cpp"
    }

    includedirs
    {
        -- Include FuseEngine
		"../FuseEngine/src",

        -- Include FuseEngine Dependencies
        "../FuseEngine/vendor/spdlog/include",
		"../FuseEngine/vendor",
		"../FuseEngine/%{IncludeDir.glm}",
        "../FuseEngine/%{IncludeDir.entt}",
		"../FuseEngine/%{IncludeDir.Glad}",
		"../FuseEngine/%{IncludeDir.ImGui}",
		"../FuseEngine/%{IncludeDir.Assimp}",
    }

    links
    {
        "FuseEngine"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "FE_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines { "FUSE_ENGINE_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "FUSE_ENGINE_RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "FUSE_ENGINE_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"