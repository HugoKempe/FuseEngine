project "FuseEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    -- Pre Compiled Headers
    pchheader "fepch.h"
    pchsource "src/fepch.cpp"

    files {
        -- FuseBox source files
        "src/**.h", "src/**.cpp",

        -- Dependency source files
        "Vendor/stb_image/**.h",
        "Vendor/stb_image/**.cpp",
        "Vendor/glm/glm/**.hpp",
        "Vendor/glm/glm/**.inl",
        "Vendor/nlohmann_json/single_include/nlohmann/json.hpp",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "FUSE_ENGINE_BUILD"
    }

    includedirs
    {
        -- Include source
        "src",
        -- Include dependencies
        "Vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.msdfgen}",
		"%{IncludeDir.msdf_atlas_gen}",
        "%{IncludeDir.stb_image}",
        "%{IncludeDir.entt}",
        "%{IncludeDir.nlohmann_json}",
        --"%{IncludeDir.FreeType}",
        "%{IncludeDir.Assimp}",
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui-Docking",
        "msdf-atlas-gen",
        "FreeType",
        "Assimp",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        defines { "GLFW_INCLUDE_NONE", "FE_PLATFORM_WINDOWS" }

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