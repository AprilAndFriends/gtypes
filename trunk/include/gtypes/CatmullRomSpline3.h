/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_SPLINE3_H
#define GTYPES_SPLINE3_H

#include "gtypesExport.h"

namespace gtypes
{

	class gtypesExport CatmullRomSpline3
	{
	public:
		CatmullRomSpline3();
		~CatmullRomSpline3();

	};

}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::CatmullRomSpline3 crs3;
}
#endif

#endif // GTYPES_SPLINE3_H