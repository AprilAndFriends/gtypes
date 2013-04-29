/// @file
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.4
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
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
	#ifndef DEPRECATED_ATTRIBUTE
		#ifdef _MSC_VER
			#define DEPRECATED_ATTRIBUTE __declspec(deprecated("function is deprecated"))
		#else
			#define DEPRECATED_ATTRIBUTE __attribute__((deprecated))
		#endif
	#endif

#endif

