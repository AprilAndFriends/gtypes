/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.46
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include <math.h>

#include "Quaternion.h"
#include "Vector3.h"

namespace gtypes
{
	Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
	{
	}

	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	Vector3::Vector3(const float v[])
	{
		this->x = v[0];
		this->y = v[1];
		this->z = v[2];
	}
	
	Vector3::Vector3(Quaternion q)
	{
		this->x = q.x;
		this->y = q.y;
		this->z = q.z;
	}

	void Vector3::set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;	
	}

	bool Vector3::isNull()
	{
		return (this->x == 0.0f && this->y == 0.0f && this->z == 0.0f);
	}
	
	float Vector3::length() const
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float Vector3::squaredLength() const
	{
		return (this->x * this->x + this->y * this->y + this->z * this->z);
	}

	void Vector3::normalize()
	{
		float length = this->length();
		if (length != 0.0f)
		{
			length = 1.0f / length;
			this->x *= length;
			this->y *= length;
			this->z *= length;
		}
	}

	Vector3 Vector3::normalized() const
	{
		Vector3 v(this->x, this->y, this->z);
		v.normalize();
		return v;
	}
	
	Vector3 Vector3::operator+(const Vector3& v) const
	{
		return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
	}
	
	Vector3 Vector3::operator-(const Vector3& v) const
	{
		return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
	}
	
	Vector3 Vector3::operator*(const Vector3& v) const
	{
		return Vector3(this->x * v.x, this->y * v.y, this->z * v.z);
	}
	
	Vector3 Vector3::operator/(const Vector3& v) const
	{
		return Vector3(this->x / v.x, this->y / v.y, this->z / v.z);
	}
	
	Vector3 Vector3::operator*(const float f) const
	{
		return Vector3(this->x * f, this->y * f, this->z * f);
	}
	
	Vector3 Vector3::operator/(const float f) const
	{
		return Vector3(this->x / f, this->y / f, this->z / f);
	}
	
	Vector3 Vector3::operator-() const
	{
		return Vector3(-this->x, -this->y, -this->z);
	}

	Vector3 Vector3::operator+=(const Vector3& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		return (*this);
	}

	Vector3 Vector3::operator-=(const Vector3& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		return (*this);
	}

	Vector3 Vector3::operator*=(const Vector3& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
		return (*this);
	}

	Vector3 Vector3::operator/=(const Vector3& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
		return (*this);
	}

	Vector3 Vector3::operator*=(const float f)
	{
		this->x *= f;
		this->y *= f;
		this->z *= f;
		return (*this);
	}
	
	Vector3 Vector3::operator/=(const float f)
	{
		this->x /= f;
		this->y /= f;
		this->z /= f;
		return (*this);
	}
	
	bool Vector3::operator==(const Vector3& v) const
	{
		return (this->x == v.x && this->y == v.y && this->z == v.z);
	}
	
	bool Vector3::operator!=(const Vector3& v) const
	{
		return !(*this == v);
	}

	float Vector3::dot(const Vector3& v) const
	{
		return (this->x * v.x + this->y * v.y + this->z * v.z);
	}
	
	Vector3 Vector3::cross(const Vector3& v) const
	{
		return Vector3(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
	}

}

