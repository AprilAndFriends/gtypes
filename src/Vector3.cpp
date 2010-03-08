/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "Vector3.h"
#include <math.h>

namespace gtypes
{

	Vector3::Vector3()
	{
		x=y=z=0;
	}

	Vector3::Vector3(float _x,float _y,float _z)
	{
		x=_x; y=_y; z=_z;
	}

	void Vector3::set(float _x,float _y,float _z)
	{
		x=_x; y=_y; z=_z;	
	}

	float Vector3::length()
	{
		return sqrt(x*x+y*y+z*z);
	}

	float Vector3::squaredLength()
	{
		return	x*x+y*y+z*z;
	}

	void Vector3::normalise()
	{
		float len=length();
		x/=len; y/=len; z/=len;
	}

	Vector3 Vector3::normalised()
	{
		Vector3 v(x,y,z);
		v.normalise();
		return v;
	}


	Vector3 Vector3::operator +(const Vector3& v)
	{
		return Vector3(x+v.x,y+v.y,z+v.z);
	}

	Vector3 Vector3::operator -(const Vector3& v)
	{
		return Vector3(x-v.x,y-v.y,z-v.z);
	}

	Vector3 Vector3::operator *(const float f)
	{
		return Vector3(x*f,y*f,z*f);
	}

	void Vector3::operator +=(const Vector3& v)
	{
		x+=v.x; y+=v.y; z+=v.z;
	}

	void Vector3::operator -=(const Vector3& v)
	{
		x-=v.x; y-=v.y; z-=v.z;
	}

	void Vector3::operator *=(const float f)
	{
		x*=f; y*=f; z*=f;
	}
	
	float Vector3::dotProduct(Vector3 v)
	{
		return x*v.x+y*v.y+z*v.z;
	}

}

