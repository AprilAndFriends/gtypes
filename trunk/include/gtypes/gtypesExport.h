/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_EXPORT_H
#define GTYPES_EXPORT_H

	#ifdef _STATICLIB
		#define gtypesExport
	#else
		#ifdef _WIN32
			#ifdef GTYPES_EXPORTS
				#define gtypesExport __declspec(dllexport)
			#else
				#define gtypesExport __declspec(dllimport)
			#endif
		#else
			#define gtypesExport __attribute__ ((visibility("default")))
		#endif
	#endif

#endif

