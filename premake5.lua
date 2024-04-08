workspace "Sovereign"
	architecture "x64"
	startproject "Sandbox"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sovereign"
	location "Sovereign"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
	defines {

		"SVG_PLATFORM_WINDOWS",
		"SVG_BUILD_DLL",
	}
	
	postbuildcommands{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "SVG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SVG_RELEASE"
		optimize "On"

	filter "configurations:DIST"
		defines "SVG_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Sovereign/vendor/spdlog/include",
		"Sovereign/src"
	}

	links{

		"Sovereign"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	defines {

		"SVG_PLATFORM_WINDOWS",
	}
	
	filter "configurations:Debug"
		defines "SVG_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SVG_RELEASE"
		optimize "On"

	filter "configurations:DIST"
		defines "SVG_RELEASE"
		optimize "On"
