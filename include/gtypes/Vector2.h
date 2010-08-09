/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_VECTOR2_H
#define GTYPES_VECTOR2_H

#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport Vector2
	{
	public:
		float x,y;
	
		Vector2();
		Vector2(float _x,float _y);
		void set(float _x,float _y);
		
		bool isInCircle(float center_x,float center_y,float radius);
		bool isInRectangle(float rect_x,float rect_y,float rect_w,float rect_h);
		
		float length();
		float squaredLength();
		void normalise();
		Vector2 normalised();
		
		Vector2 operator +(const Vector2& v);
		Vector2 operator -(const Vector2& v);
        Vector2 operator -();
		Vector2 operator *(const float f);
        Vector2 operator /(const float f);
		void operator +=(const Vector2& v);
		void operator -=(const Vector2& v);
		void operator *=(const float f);
        void operator /=(const float f);
        bool operator ==(const Vector2& v);
        bool operator !=(const Vector2& v);
		
		float dotProduct(Vector2 v);

	};
}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::Vector2 vec2;
}

#endif // GTYPES_ABREV

#endif // GTYPES_VECTOR2_H
