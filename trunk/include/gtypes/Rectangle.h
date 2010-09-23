/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_RECTANGLE_H
#define GTYPES_RECTANGLE_H

#include "Vector2.h"
#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport Rectangle
	{
	public:
		float x, y, w, h;
	
		Rectangle();
		Rectangle(float _x, float _y, float _w, float _h);
		
		bool intersects(Rectangle& other);
		void operator+=(Vector2& vector);
		void operator-=(Vector2& vector);
		Rectangle operator+(Vector2 vector);
		Rectangle operator-(Vector2 vector);

	};
}

typedef gtypes::Rectangle grect;

#endif // GTYPES_RECTANGLE_H
