workspace "Sauropod"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sauropod_Engine"
  location "sauropod_game_engine"
  kind "SharedLib"
  language "C++"

  -- TODO: for some reason I wasn't able to use %{prj.location}

  targetdir ("bin/" .. outputdir .. "/sauropod_game_engine") 
  objdir ("bin-intermediate/" .. outputdir .. "/sauropod_game_engine") 

  files
  {
    "sauropod_game_engine/src/**.h",
    "sauropod_game_engine/src/**.cpp"
  }

  includedirs
  {
    "sauropod_game_engine/vendor/spdlog/include"
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
    "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox"
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
  location "sandbox"
  kind "ConsoleApp"
  language "C++"

  targetdir ("bin/" .. outputdir .. "/sandbox") 
  objdir ("bin-intermediate/" .. outputdir .. "/sandbox") 

  files
  {
    "sandbox/src/**.h",
    "sandbox/src/**.cpp"
  }

  includedirs
  {
    "sauropod_game_engine/vendor/spdlog/include",
    "sauropod_game_engine/src"
  }

  links
  {
    "Sauropod_Engine"
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
