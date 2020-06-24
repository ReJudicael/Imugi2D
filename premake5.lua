workspace "Imugi"
	architecture "x64"
	configurations { "Debug", "Release", }

	filter "configurations:Debug"
		defines "IMUGI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMUGI_RELEASE"
		optimize "On"

	filter "system:windows"
		defines "IMUGI_PLATFORM_WINDOWS"
		cppdialect "C++17"
		systemversion "latest"

outputdir = "%{cfg.buildcfg} (%{cfg.architecture})"

project "Imugi"
	location "Imugi"
	kind "SharedLib"
	language "C++"
	defines "IMUGI_DLL_EXPORT"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	postbuildcommands ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")

	files { "%{prj.name}/Source/Include/**.h", "%{prj.name}/Source/Src/**.cpp" }

project "Editor"
	location "Editor"
	kind "ConsoleApp"
	language "C++"
	links "Imugi"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { "%{prj.name}/Source/Include/**.h", "%{prj.name}/Source/Src/**.cpp" }
