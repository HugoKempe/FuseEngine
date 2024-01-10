project "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

	-- Addons relative to this
	Addons = {}
	Addons["TextEditor"] = "imgui-addons/ImGuiColorTextEdit/src/**"

	files
	{
		"imconfig.h",
		"imgui.h",
		"imgui.cpp",
		"imgui_draw.cpp",
		"imgui_internal.h",
		"imgui_widgets.cpp",
		"imstb_rectpack.h",
		"imstb_textedit.h",
		"imstb_truetype.h",
		"imgui_demo.cpp",
		-- "examples/imgui_impl_glfw.h",
		-- "examples/imgui_impl_glfw.cpp",
		-- "examples/imgui_impl_opengl3.h",
		-- "examples/imgui_impl_opengl3.cpp"

		-- addons
		"%{Addons.TextEditor}",
		--"addons/ImGuiColorTextEdit/TextEditor.cpp",
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

	filter "system:linux"
		pic "On"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "On"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        runtime "Release"
        optimize "On"
        symbols "Off"
