/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.47
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

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
	
	Quaternion::Quaternion(const float v[])
	{
		this->x = v[0];
		this->y = v[1];
		this->z = v[2];
		this->w = v[3];
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

	void Quaternion::set(const float v[])
	{
		this->x = v[0];
		this->y = v[1];
		this->z = v[2];
		this->w = v[3];
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
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
	}
	
	float Quaternion::squaredLength() const
	{
		return (this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
	}

	float Quaternion::dot(const Quaternion& q) const
	{
		return (this->w * q.w + this->x * q.x + this->y * q.y + this->z * q.z);
	}
	
	void Quaternion::inverse()
	{
		float sqNorm = this->squaredLength();
		this->set(-this->x / sqNorm, -this->y / sqNorm, -this->z / sqNorm, this->w / sqNorm);
	}
	
	Quaternion Quaternion::inversed() const
	{
		Quaternion q(*this);
		q.inverse();
		return q;
	}
	
	void Quaternion::conjugate()
	{
		this->x = -this->x;
		this->y = -this->y;
		this->z = -this->z;
	}
	
	Quaternion Quaternion::conjugated() const
	{
		Quaternion q(*this);
		q.conjugate();
		return q;
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
		Quaternion q(*this);
		q.normalize();
		return q;
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
					   2.0f * (xy + wz),		1.0f - 2.0f * (xx + zz),		2.0f * (yz - wx),
					   2.0f * (xz - wy),			2.0f * (yz + wx),			1.0f - 2.0f * (xx + yy));
	}

	Matrix4 Quaternion::mat4() const
	{
		return mat4(Vector3());
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
					   2.0f * (xy + wz),		1.0f - 2.0f * (xx + zz),		2.0f * (yz - wx),			0.0f,
					   2.0f * (xz - wy),			2.0f * (yz + wx),			1.0f - 2.0f * (xx + yy),		0.0f,
					   position.x,				position.y,					position.z,					1.0f);
	}
	
	Quaternion Quaternion::operator+(const Quaternion& q) const
	{
		return Quaternion(x + q.x, y + q.y, z + q.z, w + q.w );
	}

	Quaternion Quaternion::operator-(const Quaternion& q) const
	{
		return Quaternion(x - q.x, y - q.y, z - q.z, w - q.w);
	}
	
	Quaternion Quaternion::operator*(const Quaternion& q) const
	{
		return Quaternion(this->w * q.x + this->x * q.w + this->y * q.z - this->z * q.y, 
						  this->w * q.y - this->x * q.z + this->y * q.w + this->z * q.x, 
						  this->w * q.z + this->x * q.y - this->y * q.x + this->z * q.w,
						  this->w * q.w - this->x * q.x - this->y * q.y - this->z * q.z);
	}
	
	Quaternion Quaternion::operator*(float f) const
	{
		return Quaternion(this->x * f, this->y * f, this->z * f, this->w * f);
	}
	
	bool Quaternion::operator==(const Quaternion& q) const
	{
		return (this->x == q.x && this->y == q.y && this->z == q.z && this->w == q.w);
	}
	
	bool Quaternion::operator!=(const Quaternion& q) const
	{
		return !(*this == q);
	}

	Quaternion Quaternion::slerp(const Quaternion& a, const Quaternion& b, float t)
	{
		float w1;
		float w2;
		float theta = acos(a.dot(b));
		float sinTheta = sin(theta);
		if (sinTheta > G_E_TOLERANCE)
		{
			w1 = (float)(sin(1.0f - t) * theta) / sinTheta;
			w2 = (float)(sin(t) * theta) / sinTheta;
		}
		else
		{
			w1 = 1.0f - t;
			w2 = t;
		}
		return Quaternion(a * w1 + b * w2);
	}
	
	Quaternion Quaternion::fromAxisAngle(const Vector3& a, float angle)
	{
		gvec3 n = a.normalized();
		float theta = (float)DEG_TO_RAD(angle) * 0.5f;
		float s = sin(theta);
		float c = cos(theta);
		return Quaternion(n.x * s, n.y * s, n.z * s, c);
	}
	
	Quaternion Quaternion::fromAxisAngle(float ax, float ay, float az, float angle)
	{
		return fromAxisAngle(Vector3(ax, ay, az), angle);
	}
	
	Quaternion Quaternion::fromEulerAngles(float yaw, float pitch, float roll)
	{
		Quaternion y(0.0f, -(float)sin(yaw * 0.5f), 0.0f, (float)cos(yaw * 0.5f));
		Quaternion p(-(float)sin(pitch * 0.5f), 0.0f, 0.0f, (float)cos(pitch * 0.5f));
		Quaternion r(0.0f, 0.0f, -(float)sin(roll * 0.5), (float)cos(roll * 0.5f));
		return (y * p * r);
	}
	
}
