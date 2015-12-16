/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include <math.h>

#include "gtypesUtil.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Quaternion.h"
#include "Vector3.h"

namespace gtypes
{
	Quaternion::Quaternion()
	{
		this->x = 1.0f;
		this->y = 1.0f;
		this->z = 1.0f;
		this->w = 1.0f;
	}

	Quaternion::Quaternion(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	
	Quaternion::Quaternion(const Vector3& v, float w)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = w;
	}

	void Quaternion::set(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	void Quaternion::set(const Vector3& v, float w)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = w;
	}
	
	float Quaternion::length() const
	{
		return (float)sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
	}
	
	float Quaternion::squaredLength() const
	{
		return (this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
	}

	void Quaternion::normalize()
	{
		float length = this->length();
		if (length != 0.0f)
		{
			length = 1.0f / length;
			this->x *= length;
			this->y *= length;
			this->z *= length;
			this->w *= length;
		}
	}

	Quaternion Quaternion::normalized() const
	{
		Quaternion result(*this);
		result.normalize();
		return result;
	}

	void Quaternion::inverse()
	{
		float squaredLength = 1.0f / this->squaredLength();
		this->set(-this->x * squaredLength, -this->y * squaredLength, -this->z * squaredLength, this->w * squaredLength);
	}

	Quaternion Quaternion::inversed() const
	{
		Quaternion result(*this);
		result.inverse();
		return result;
	}

	void Quaternion::conjugate()
	{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;
	}
	
	Quaternion Quaternion::conjugated() const
	{
		Quaternion result(*this);
		result.conjugate();
		return result;
	}
	
	float Quaternion::dot(const Quaternion& other) const
	{
		return (this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w);
	}

	Matrix3 Quaternion::mat3() const
	{
		float xx = this->x * this->x;
		float yy = this->y * this->y;
		float zz = this->z * this->z;
		float xy = this->x * this->y;
		float xz = this->x * this->z;
		float yz = this->y * this->z;
		float wx = this->w * this->x;
		float wy = this->w * this->y;
		float wz = this->w * this->z;
		return Matrix3(1.0f - 2.0f * (yy + zz),	2.0f * (xy - wz),			2.0f * (xz + wy),
					   2.0f * (xy + wz),		1.0f - 2.0f * (xx + zz),	2.0f * (yz - wx),
					   2.0f * (xz - wy),		2.0f * (yz + wx),			1.0f - 2.0f * (xx + yy));
	}

	Matrix4 Quaternion::mat4() const
	{
		return this->mat4(Vector3());
	}

	Matrix4 Quaternion::mat4(const Vector3& position) const
	{
		float xx = this->x * this->x;
		float yy = this->y * this->y;
		float zz = this->z * this->z;
		float xy = this->x * this->y;
		float xz = this->x * this->z;
		float yz = this->y * this->z;
		float wx = this->w * this->x;
		float wy = this->w * this->y;
		float wz = this->w * this->z;
		return Matrix4(1.0f - 2.0f * (yy + zz),	2.0f * (xy - wz),			2.0f * (xz + wy),			0.0f,
					   2.0f * (xy + wz),		1.0f - 2.0f * (xx + zz),	2.0f * (yz - wx),			0.0f,
					   2.0f * (xz - wy),		2.0f * (yz + wx),			1.0f - 2.0f * (xx + yy),	0.0f,
					   position.x,				position.y,					position.z,					1.0f);
	}
	
	Quaternion Quaternion::operator-() const
	{
		return Quaternion(-this->x, -this->y, -this->z, -this->w);
	}

	Quaternion Quaternion::operator+(const Quaternion& other) const
	{
		return Quaternion(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
	}

	Quaternion Quaternion::operator-(const Quaternion& other) const
	{
		return Quaternion(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
	}
	
	Quaternion Quaternion::operator*(const Quaternion& other) const
	{
		return Quaternion(this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
						  this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x,
						  this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w,
						  this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z);
	}
	
	Quaternion Quaternion::operator*(float factor) const
	{
		return Quaternion(this->x * factor, this->y * factor, this->z * factor, this->w * factor);
	}
	
	Quaternion Quaternion::operator+=(const Quaternion& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
		return (*this);
	}

	Quaternion Quaternion::operator-=(const Quaternion& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
		return (*this);
	}

	Quaternion Quaternion::operator*=(const Quaternion& other)
	{
		float x = this->x;
		float y = this->y;
		float z = this->z;
		float w = this->w;
		this->x = w * other.x + x * other.w + y * other.z - z * other.y;
		this->y = w * other.y - x * other.z + y * other.w + z * other.x;
		this->z = w * other.z + x * other.y - y * other.x + z * other.w;
		this->w = w * other.w - x * other.x - y * other.y - z * other.z;
		return (*this);
	}

	Quaternion Quaternion::operator*=(const float factor)
	{
		this->x *= factor;
		this->y *= factor;
		this->z *= factor;
		this->w *= factor;
		return (*this);
	}

	bool Quaternion::operator==(const Quaternion& other) const
	{
		return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
	}
	
	bool Quaternion::operator!=(const Quaternion& other) const
	{
		return !(*this == other);
	}

	Quaternion Quaternion::slerp(const Quaternion& a, const Quaternion& b, float factor)
	{
		float theta = (float)acos(a.dot(b));
		float sinTheta = (float)sin(theta);
		float w1 = 1.0f - factor;
		float w2 = factor;
		if (sinTheta > G_E_TOLERANCE)
		{
			w1 = (float)(sin(1.0f - factor) * theta) / sinTheta;
			w2 = (float)(sin(factor) * theta) / sinTheta;
		}
		return Quaternion(a * w1 + b * w2);
	}
	
	Quaternion Quaternion::fromAxisAngle(float ax, float ay, float az, float angle)
	{
		return Quaternion::fromAxisAngle(Vector3(ax, ay, az), angle);
	}
	
	Quaternion Quaternion::fromAxisAngle(const Vector3& axis, float angle)
	{
		float theta = (float)DEG_TO_RAD(angle) * 0.5f;
		return Quaternion(axis.normalized() * (float)sin(theta), (float)cos(theta));
	}

	Quaternion Quaternion::fromEulerAngles(float yaw, float pitch, float roll)
	{
		Quaternion y(0.0f, -(float)sin(yaw * 0.5f), 0.0f, (float)cos(yaw * 0.5f));
		Quaternion p(-(float)sin(pitch * 0.5f), 0.0f, 0.0f, (float)cos(pitch * 0.5f));
		Quaternion r(0.0f, 0.0f, -(float)sin(roll * 0.5), (float)cos(roll * 0.5f));
		return (y * p * r);
	}
	
}
