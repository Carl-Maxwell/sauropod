workspace "Sauropod"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SauropodEngine/vendor/glfw/include"
IncludeDir["Glad"] = "SauropodEngine/vendor/Glad/include"

include "SauropodEngine/vendor/glfw"
include "SauropodEngine/vendor/Glad"

project "SauropodEngine"
	location "SauropodEngine"
	kind "SharedLib"
	language "C++"

	-- TODO: for some reason I wasn't able to use %{prj.location}

	targetdir ("bin/" .. outputdir .. "/SauropodEngine") 
	objdir ("bin-intermediate/" .. outputdir .. "/SauropodEngine") 

	pchheader "hzpch.h"
	pchsource "SauropodEngine/src/hzpch.cpp"

	files
	{
		"SauropodEngine/src/**.h",
		"SauropodEngine/src/**.cpp"
	}

	includedirs
	{
		"SauropodEngine/src",
		"SauropodEngine/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
	}
	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		-- staticruntime "Off"
		systemversion "latest"

		defines 
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		buildoptions "/MDd" -- runtime library: multi-threaded debug DLL
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		buildoptions "/MD" -- runtime library: multi-threaded DLL
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		buildoptions "/MD" -- runtime library: multi-threaded DLL
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/Sandbox") 
	objdir ("bin-intermediate/" .. outputdir .. "/Sandbox") 

	files
	{
		"Sandbox/src/**.h",
		"Sandbox/src/**.cpp"
	}

	includedirs
	{
		"SauropodEngine/vendor/spdlog/include",
		"SauropodEngine/src"
	}

	links
	{
		"SauropodEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		-- staticruntime "On"
		systemversion "latest"

	defines 
	{
		"HZ_PLATFORM_WINDOWS",
		"_WINDLL"
	}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		buildoptions "/MDd" -- runtime library: multi-threaded debug DLL
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		buildoptions "/MD" -- runtime library: multi-threaded DLL
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		buildoptions "/MD" -- runtime library: multi-threaded DLL
		optimize "On"
