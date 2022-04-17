#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define SAUROPOD_API __declspec(dllexport)
	#else
		#define SAUROPOD_API __declspec(dllimport)
	#endif
#else
	#error Sauropod only supports Windows!
#endif