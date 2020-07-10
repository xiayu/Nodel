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

project "Nodel"
	location "Nodel"
	kind "StaticLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	links
	{
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"ND_BUILD_DLL"
		}

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
		"Nodel/src"
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