workspace "Sauropod"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SauropodEngine"
  location "SauropodEngine"
  kind "SharedLib"
  language "C++"

  -- TODO: for some reason I wasn't able to use %{prj.location}

  targetdir ("bin/" .. outputdir .. "/SauropodEngine") 
  objdir ("bin-intermediate/" .. outputdir .. "/SauropodEngine") 

  files
  {
    "SauropodEngine/src/**.h",
    "SauropodEngine/src/**.cpp"
  }

  includedirs
  {
    "SauropodEngine/vendor/spdlog/include"
  }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "latest"

  defines 
  {
    "HZ_PLATFORM_WINDOWS",
    "HZ_BUILD_DLL",
    "_WINDLL"
  }
  
  postbuildcommands
  {
    "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
  }

  filter "configurations:Debug"
    defines "HZ_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "HZ_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "HZ_DIST"
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
    staticruntime "On"
    systemversion "latest"

  defines 
  {
    "HZ_PLATFORM_WINDOWS",
    "_WINDLL"
  }

  filter "configurations:Debug"
    defines "HZ_DEBUG"
    symbols "On"

  filter "configurations:Release"
    defines "HZ_RELEASE"
    optimize "On"

  filter "configurations:Dist"
    defines "HZ_DIST"
    optimize "On"
