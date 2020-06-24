#pragma once

// -----------------------------------------
// Solution platform

#ifdef _WIN64										// Windows x64
	#define IMUGI_PLATFORM_WINDOWS
#elif defined(_WIN32)								// Windows x86
	#error "x86 Builds are not supported!"
#elif defined(__ANDROID__)							// Android (implies Linux, so it must come first)
	#define IMUGI_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)							// Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
	#define IMUGI_PLATFORM_LINUX
	#error "Linux is not supported!"
#elif defined(__APPLE__) || defined(__MACH__)		// Apple OSX or iOS (Darwin)
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR						// Apple iOS
		#define IMUGI_PLATFORM_TARGET_IOS_SIMULATOR
		#error "iOS simulator is not supported!"
	#elif TARGET_OS_IPHONE							// Apple iOS
		#define IMUGI_PLATFORM_TARGET_IOS
		#error "iOS is not supported!"
	#elif TARGET_OS_MAC								// Apple OSX
		#define IMUGI_PLATFORM_TARGET_MACOS
		#error "MacOS is not supported!"
	#else											// Unknown Apple platform
		#error "Unknown Apple platform!"
	#endif
#else												// Unknown platform
	#error "Unknown platform!"
#endif


// -----------------------------------------
// Debug - Breakpoints

#ifdef IMUGI_DEBUG
	#if defined(IMUGI_PLATFORM_WINDOWS)				// Windows breakpoint
		#define IMUGI_BREAKPOINT() __debugbreak()
	#elif defined(IMUGI_PLATFORM_LINUX)				// Linux breakpoint
		#include <csignal>
		#define IMUGI_BREAKPOINT() _STD raise(SIGTRAP)
	#else
		#error "Platform doesn't support breakpoint yet!"
	#endif
#else
	#define IMUGI_BREAKPOINT()
#endif


// -----------------------------------------
// Debug - Assertion

#ifdef IMUGI_DEBUG
	#define IMUGI_ASSERT(x, ...) { if(!(x)) { IMUGI_BREAKPOINT(); } }
#else
	#define IMUGI_ASSERT(x, ...)
#endif


// -----------------------------------------
// DLL export / import

#ifdef IMUGI_PLATFORM_WINDOWS
	#ifdef IMUGI_DLL_EXPORT
		#define IMUGI_API __declspec(dllexport)
	#else
		#define IMUGI_API __declspec(dllimport)
	#endif
#else
	#error "Imugi only supports Windows!"
#endif


// -----------------------------------------
// Namespace

#define IMUGI Imugi
#define IMUGI_BEGIN namespace IMUGI {
#define IMUGI_END }
