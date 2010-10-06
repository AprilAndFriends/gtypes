/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include <math.h>

#include "Vector3.h"

namespace gtypes
{
	Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
	{
	}

	Vector3::Vector3(float _x, float _y, float _z)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}
	
	Vector3::Vector3(const float *v)
	{
		this->x = v[0];
		this->y = v[1];
		this->z = v[2];
	}

	void Vector3::set(float _x, float _y, float _z)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;	
	}

	float Vector3::length()
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float Vector3::squaredLength()
	{
		return (this->x * this->x + this->y * this->y + this->z * this->z);
	}

	void Vector3::normalise()
	{
		float len = length();
		this->x /= len;
		this->y /= len;
		this->z /= len;
	}

	Vector3 Vector3::normalised()
	{
		Vector3 v(this->x, this->y, this->z);
		v.normalise();
		return v;
	}
	
	Vector3 Vector3::operator +(const Vector3& v) const
	{
		return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
	}
	
	Vector3 Vector3::operator -(const Vector3& v) const
	{
		return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
	}
	
	Vector3 Vector3::operator *(const float f) const
	{
		return Vector3(this->x * f, this->y * f, this->z * f);
	}
    
	Vector3 Vector3::operator /(const float f) const
	{
		return Vector3(this->x / f, this->y / f, this->z / f);
	}
    
	Vector3 Vector3::operator -() const
	{
		return Vector3(-this->x, -this->y, -this->z);
	}

    bool Vector3::operator ==(const Vector3& v)
    {
        return (this->x == v.x && this->y == v.y && this->z == v.z);
    }
    
    bool Vector3::operator !=(const Vector3& v)
    {
        return !(*this == v);
    }

	void Vector3::operator +=(const Vector3& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
	}

	void Vector3::operator -=(const Vector3& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
	}

	void Vector3::operator *=(const float f)
	{
		this->x *= f;
		this->y *= f;
		this->z *= f;
	}
    
    void Vector3::operator /=(const float f)
	{
		this->x /= f;
		this->y /= f;
		this->z /= f;
	}
	
	float Vector3::dot(const Vector3& v) const
	{
		return (this->x * v.x + this->y * v.y + this->z * v.z);
	}
    
	Vector3 Vector3::cross(const Vector3& v2) const
	{
		Vector3 v;
		v.x = this->y * v2.z - this->z * v2.y;
		v.y = this->z * v2.x - this->x * v2.z;
		v.z = this->x * v2.y - this->y * v2.x;
		return v;
	}

}

