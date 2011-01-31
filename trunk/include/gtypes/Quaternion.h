/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
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
		void set(float _x,float _y,float _z,float _w);
		
		Matrix3 mat3() const;
		Matrix4 mat4() const;
		Matrix4 mat4(const Vector3& position) const;
		
		static Quaternion fromAxisAngle(float ax,float ay,float az,float angle);
		
		Quaternion operator +(const Quaternion& q);
		Quaternion operator -(const Quaternion& q);
		Quaternion operator *(const Quaternion& q);
		Quaternion operator *(const float f);
		
		Quaternion getInverse();
		
		float dot(const Quaternion& q);
		void normalize();
		void slerp(Quaternion& a, Quaternion& b, float t);
	};
}

typedef gtypes::Quaternion gquat;

#endif // GTYPES_QUATERNION_H
