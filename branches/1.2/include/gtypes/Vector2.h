/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// DOCUMENT ME

#ifndef GTYPES_VECTOR2_H
#define GTYPES_VECTOR2_H

#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport Vector2
	{
	public:
		float x;
		float y;
	
		Vector2();
		Vector2(float x, float y);
		void set(float x, float y);
		
		bool isInCircle(float center_x, float center_y, float radius);
		
		float length() const;
		float squaredLength() const;
		void normalize();
		Vector2 normalized() const;
		void normalise() DEPRECATED_ATTRIBUTE { this->normalize(); }
		Vector2 normalised() const DEPRECATED_ATTRIBUTE { return this->normalized(); }
		
		Vector2 operator+(const Vector2& v);
		Vector2 operator-(const Vector2& v);
		Vector2 operator*(const Vector2& v);
		Vector2 operator/(const Vector2& v);
		Vector2 operator*(const float f);
		Vector2 operator/(const float f);
		Vector2 operator-() const;
		Vector2 operator+=(const Vector2& v);
		Vector2 operator-=(const Vector2& v);
		Vector2 operator*=(const Vector2& v);
		Vector2 operator/=(const Vector2& v);
		Vector2 operator*=(const float f);
		Vector2 operator/=(const float f);
		bool operator==(const Vector2& v);
		bool operator!=(const Vector2& v);
		
		float dot(Vector2 v) const;

	};
}

typedef gtypes::Vector2 gvec2;

#endif // GTYPES_VECTOR2_H