/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_VECTOR3_H
#define GTYPES_VECTOR3_H

#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport Vector3
	{
	public:
		float x;
		float y;
		float z;
	
		Vector3();
		Vector3(float _x, float _y, float _z);
		Vector3(const float *v);
		void set(float _x, float _y, float _z);
		
		float length();
		float squaredLength();
		void normalise();
		Vector3 normalised();
		
		Vector3 operator +(const Vector3& v);
		Vector3 operator -(const Vector3& v);
		Vector3 operator *(const float f);
        Vector3 operator /(const float f);
		Vector3 operator -();
		void operator +=(const Vector3& v);
		void operator -=(const Vector3& v);
		void operator *=(const float f);
        void operator /=(const float f);
        bool operator ==(const Vector3& v);
        bool operator !=(const Vector3& v);
		
		float dot(const Vector3& v) const;
		
		Vector3 cross(const Vector3& v2) const;
		
	};
}

typedef gtypes::Vector3 gvec3;

#endif // GTYPES_VECTOR3_H
