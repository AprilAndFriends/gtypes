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

#ifndef GTYPES_QUATERNION_H
#define GTYPES_QUATERNION_H

#include <math.h>
#include "gtypesExport.h"

namespace gtypes
{
	class Matrix3;
	class Matrix4;
	class Vector3;

	class gtypesExport Quaternion
	{
	public:
		float x;
		float y;
		float z;
		float w;
	
		Quaternion();
		Quaternion(float _x,float _y,float _z,float _w);
		Quaternion(const float *v);
		Quaternion(const Quaternion& quat);
		Quaternion(const Vector3& v, float w);
		void set(float _x,float _y,float _z,float _w);
		
		Matrix3 mat3() const;
		Matrix4 mat4() const;
		Matrix4 mat4(const Vector3& position) const;
		
		static Quaternion fromAxisAngle(float ax,float ay,float az,float angle);
		static Quaternion fromEulerAngles(float yaw, float pitch, float roll);
		
		Quaternion operator +(const Quaternion& q);
		Quaternion operator -(const Quaternion& q);
		Quaternion operator *(const Quaternion& q);
		Quaternion operator *(const float f);
		
		Quaternion getInverse();
		Quaternion getConjugate();
		
		float dot(const Quaternion& q);
		void normalize();
		static Quaternion slerp(Quaternion& a, Quaternion& b, float t);
	};
}

typedef gtypes::Quaternion gquat;

#endif // GTYPES_QUATERNION_H
