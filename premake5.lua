workspace "Nodel"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

INCLUDEDIR = {}
INCLUDEDIR['glfw'] = 'Nodel/vendor/glfw/include'
INCLUDEDIR['glad'] = 'Nodel/vendor/glad/include'
INCLUDEDIR['imgui'] = 'Nodel/vendor/imgui'

group "Depandency"
	include "Nodel/vendor/glfw"
	include "Nodel/vendor/glad"
	include "Nodel/vendor/imgui"

group ""
project "Nodel"
	location "Nodel"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ndpch.h"
	pchsource "%{prj.name}/src/ndpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{INCLUDEDIR.glfw}",
		"%{INCLUDEDIR.glad}",
		"%{INCLUDEDIR.imgui}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"ND_PLATFORM_WINDOWS",
			"ND_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "ND_DEBUG;ND_ENABLE_ASSERTS"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ND_Release"
		runtime "Release"
		symbols "on"
    
	filter "configurations:Dist"
		defines "ND_DIST"
		runtime "Release"
		symbols "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"Nodel/src",
		"Nodel/vendor/spdlog/include"
	}

	links
	{
		"Nodel"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ND_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ND_Release"
		runtime "Release"
		symbols "on"
    
	filter "configurations:Dist"
		defines "ND_DIST"
		runtime "Release"
		symbols "on"