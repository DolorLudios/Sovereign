#pragma once

#ifdef SVG_PLATFORM_WINDOWS
	#ifdef SVG_BUILD_DLL
		#define SVG_API __declspec(dllexport)
	#else
		#define SVG_API __declspec(dllimport)
	#endif
#else
	#error SVG ONLY SUPPORT WINDOWS!
#endif

#define BIT(x) (1 << x)