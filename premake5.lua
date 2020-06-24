workspace "Imugi"
	startproject "Editor"
	language "C++"
	architecture "x86_64"

	configurations { "Debug", "Release" }

	filter "configurations:Debug"
		defines "IMUGI_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMUGI_RELEASE"
		optimize "On"

outputdir = "%{cfg.buildcfg} (%{cfg.architecture})"

project "Imugi"
	location "Imugi"
	kind "SharedLib"
	defines "IMUGI_DLL_EXPORT"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	postbuildcommands ("{COPY} \"%{cfg.buildtarget.relpath}\" \"../bin/" .. outputdir .. "/Editor/\"")

	files { "%{prj.location}/Source/Include/**.h", "%{prj.location}/Source/Src/**.cpp" }
	includedirs "%{prj.location}/Source/Include/"

project "Editor"
	location "Editor"
	kind "ConsoleApp"
	links "Imugi"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { "%{prj.location}/Source/Include/**.h", "%{prj.location}/Source/Src/**.cpp" }
	includedirs { "%{prj.location}/Source/Include/", "Imugi/Source/Include/" }
