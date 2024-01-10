workspace "FuseEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags { "MultiProcessorCompile" }

    startproject "Sandbox"

    -- Workspace-wide build options for MSVC
    filter "system:windows"
        buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"
-- OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to FuseEngine
IncludeDir = {}
IncludeDir["GLFW"] = "Vendor/GLFW/include"
IncludeDir["Glad"] = "Vendor/Glad/include"
IncludeDir["ImGui"] = "Vendor/imgui-docking"
IncludeDir["glm"] = "Vendor/glm"
IncludeDir["entt"] = "Vendor/entt/include"
IncludeDir["stb_image"] = "Vendor/stb_image"
IncludeDir["nlohmann_json"] = "Vendor/nlohmann_json/single_include"
--IncludeDir["FreeType"] = "Vendor/FreeType/include"
IncludeDir["Assimp"] = "Vendor/assimp-master/include"
IncludeDir["msdfgen"] = "Vendor/msdf-atlas-gen/msdfgen"
IncludeDir["msdf_atlas_gen"] = "Vendor/msdf-atlas-gen/msdf-atlas-gen"

BuildCfgDefines = {}
BuildCfgDefines["Debug"] = "FUSE_ENGINE_DEBUG"

-- Dependency projects
group "Dependencies"
	include "FuseEngine/Vendor/GLFW/Build-GLFW.lua"
	include "FuseEngine/Vendor/Glad/Build-Glad.lua"
    include "FuseEngine/Vendor/msdf-atlas-gen/Build-msdf.lua"
	include "FuseEngine/Vendor/imgui-docking/Build-ImGui.lua"
	--include "FuseEngine/Vendor/FreeType"
	include "FuseEngine/Vendor/assimp-master/Build-Assimp.lua"
group ""

-- Main projects
include "FuseEngine/Build-FuseEngine.lua"
include "Sandbox/Build-Sandbox.lua"

-- Removes all generated files
newaction {
    trigger = "clean",
    description = "Remove all binaries and intermediate binaries, and vs files",
    execute = function ()
        print("Removing binaries")
        os.rmdir("./Binaries" .. OutputDir)
        print("Removing intermediate binaries")
        os.rmdir("./Binaries/Intermediates/" .. OutputDir)
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done.")
    end
}