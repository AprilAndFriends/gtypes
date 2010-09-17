/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "Rectangle.h"

namespace gtypes
{
	Rectangle::Rectangle() : x(0.0f), y(0.0f), w(0.0f), h(0.0f)
	{
	}

	Rectangle::Rectangle(float _x, float _y, float _w, float _h)
	{
		this->x = _x;
		this->y = _y;
		this->w = _w;
		this->h = _h;
	}

}

