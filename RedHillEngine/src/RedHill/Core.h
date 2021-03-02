#pragma once

#ifdef RHE_PLATFORM_WINDOWS
	#ifdef RHE_BUILD_DLL
		#define RHE_API __declspec(dllexport)
	#else 
		#define RHE_API __declspec(dllimport)
	#endif
#else
	#error Red Hill Engine only supports Windows
#endif