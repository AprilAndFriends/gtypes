/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

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
	
	Vector3::~Vector3()
	{
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
		Vector3 result(this->x, this->y, this->z);
		result.normalize();
		return result;
	}
	
	float Vector3::dot(const Vector3& other) const
	{
		return (this->x * other.x + this->y * other.y + this->z * other.z);
	}

	Vector3 Vector3::cross(const Vector3& other) const
	{
		return Vector3(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
	}

	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}
	
	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}
	
	Vector3 Vector3::operator*(const Vector3& other) const
	{
		return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
	}
	
	Vector3 Vector3::operator/(const Vector3& other) const
	{
		return Vector3(this->x / other.x, this->y / other.y, this->z / other.z);
	}
	
	Vector3 Vector3::operator*(const float factor) const
	{
		return Vector3(this->x * factor, this->y * factor, this->z * factor);
	}
	
	Vector3 Vector3::operator/(const float factor) const
	{
		float invFactor = 1.0f / factor;
		return Vector3(this->x * invFactor, this->y * invFactor, this->z * invFactor);
	}
	
	Vector3 Vector3::operator-() const
	{
		return Vector3(-this->x, -this->y, -this->z);
	}

	Vector3 Vector3::operator+=(const Vector3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return (*this);
	}

	Vector3 Vector3::operator-=(const Vector3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return (*this);
	}

	Vector3 Vector3::operator*=(const Vector3& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		return (*this);
	}

	Vector3 Vector3::operator/=(const Vector3& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		return (*this);
	}

	Vector3 Vector3::operator*=(const float factor)
	{
		this->x *= factor;
		this->y *= factor;
		this->z *= factor;
		return (*this);
	}
	
	Vector3 Vector3::operator/=(const float factor)
	{
		float invFactor = 1.0f / factor;
		this->x *= invFactor;
		this->y *= invFactor;
		this->z *= invFactor;
		return (*this);
	}
	
	bool Vector3::operator==(const Vector3& other) const
	{
		return (this->x == other.x && this->y == other.y && this->z == other.z);
	}
	
	bool Vector3::operator!=(const Vector3& other) const
	{
		return !(*this == other);
	}

}

