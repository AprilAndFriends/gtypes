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
		float x,y,z;
	
		Vector3();
		Vector3(float _x,float _y,float _z);
		Vector3(const float *v);
		void set(float _x,float _y,float _z);
		
		
		float length();
		float squaredLength();
		void normalise();
		Vector3 normalised();
		
		Vector3 operator +(const Vector3& v);
		Vector3 operator -(const Vector3& v);
		const Vector3 operator-() const;
		Vector3 operator *(const float f);
		void operator +=(const Vector3& v);
		void operator -=(const Vector3& v);
		void operator *=(const float f);
		
		float dotProduct(Vector3 v);
		
		void cross(const Vector3 &v1,const Vector3 &v2);
		void cross(const Vector3 &v2);
	};
}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::Vector3 vec3;
}

#endif // GTYPES_ABREV

#endif // GTYPES_VECTOR3_H
