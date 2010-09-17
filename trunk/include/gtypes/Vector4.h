/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_VECTOR4_H
#define GTYPES_VECTOR4_H

#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport Vector4
	{
	public:
		float x,y,z,w;
	
		Vector4();
		Vector4(float _x, float _y, float _z, float _w);

	};

}

typedef gtypes::Vector4 gvec4;

#endif // GTYPES_VECTOR4_H
