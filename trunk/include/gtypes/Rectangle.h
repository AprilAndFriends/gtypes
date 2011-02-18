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

#include "gtypesExport.h"

namespace gtypes
{
	class Vector2;
	
	class gtypesExport Rectangle
	{
	public:
		float x, y, w, h;
	
		Rectangle();
		Rectangle(float _x, float _y, float _w, float _h);
		Rectangle(Vector2 position, Vector2 size);
		Rectangle(Vector2 position, float _w, float _h);
		Rectangle(float _x, float _y, Vector2 size);
		
		void set(float _x, float _y, float _w, float _h);
		void set(Vector2 position, Vector2 size);
		void set(Vector2 position, float _w, float _h);
		void set(float _x, float _y, Vector2 size);
		
		Vector2 getPosition();
		void setPosition(Vector2 position);
		Vector2 getSize();
		void setSize(Vector2 size);
		float getAspect();

		bool intersects(Rectangle& other) const;
		bool isPointInside(Vector2& vector) const;
		bool isPointInside(float x, float y) const;
		
		Rectangle operator+(Vector2 vector);
		Rectangle operator-(Vector2 vector);
		Rectangle operator*(float scale);
		Rectangle operator/(float scale);
		void operator+=(Vector2& vector);
		void operator-=(Vector2& vector);
		void operator*=(float scale);
		void operator/=(float scale);
        bool operator==(const Rectangle& other);
        bool operator!=(const Rectangle& other);
		
	};
}

typedef gtypes::Rectangle grect;

#endif // GTYPES_RECTANGLE_H
