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

#ifndef GTYPES_VECTOR3_H
#define GTYPES_VECTOR3_H

#include "gtypesExport.h"

namespace gtypes
{
	class Quaternion;
	
	class gtypesExport Vector3
	{
	public:
		float x;
		float y;
		float z;
	
		Vector3();
		Vector3(float x, float y, float z);
		Vector3(const float v[]);
		Vector3(Quaternion q);
		void set(float x, float y, float z);
		
		float length() const;
		float squaredLength() const;
		void normalize();
		Vector3 normalized() const;
		void normalise() DEPRECATED_ATTRIBUTE { this->normalize(); }
		Vector3 normalised() const DEPRECATED_ATTRIBUTE { return this->normalized(); }
		
		Vector3 operator+(const Vector3& v);
		Vector3 operator-(const Vector3& v);
		Vector3 operator*(const float f);
		Vector3 operator/(const float f);
		Vector3 operator-() const;
		Vector3 operator+=(const Vector3& v);
		Vector3 operator-=(const Vector3& v);
		Vector3 operator*=(const float f);
		Vector3 operator/=(const float f);
		bool operator==(const Vector3& v);
		bool operator!=(const Vector3& v);
		
		float dot(const Vector3& v) const;
		
		Vector3 cross(const Vector3& v) const;
		
	};
}

typedef gtypes::Vector3 gvec3;

#endif // GTYPES_VECTOR3_H
