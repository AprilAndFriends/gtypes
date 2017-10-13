/// @file
/// @version 2.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Defines macros for DLL exports/imports.

#ifndef GTYPES_EXPORT_H
#define GTYPES_EXPORT_H

	/// @def gtypesExport
	/// @brief Macro for DLL exports/imports.
	/// @def gtypesFnExport
	/// @brief Macro for function DLL exports/imports.
	#ifdef _LIB
		#define gtypesExport
		#define gtypesFnExport
	#else
		#ifdef _WIN32
			#ifdef GTYPES_EXPORTS
				#define gtypesExport __declspec(dllexport)
				#define gtypesFnExport __declspec(dllexport)
			#else
				#define gtypesExport __declspec(dllimport)
				#define gtypesFnExport __declspec(dllimport)
			#endif
		#else
			#define gtypesExport __attribute__ ((visibility("default")))
			#define gtypesFnExport __attribute__ ((visibility("default")))
		#endif
	#endif
	// taken from hltypes for compatibility
	#ifndef HL_DEPRECATED
		#if defined(_MSC_VER) && !defined(_ANDROID)
			#define HL_DEPRECATED(message) __declspec(deprecated(message))
		#else
			#define HL_DEPRECATED(message) __attribute__((deprecated(message)))
		#endif
	#endif

#endif

