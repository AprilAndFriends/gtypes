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
	Quaternion::Quaternion(const Vector3& v, float w)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = w;
	}	

	void Quaternion::set(const Vector3& v, float w)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = w;
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

	Quaternion Quaternion::fromAxisAngle(float ax, float ay, float az, float angle)
	{
		return Quaternion::fromAxisAngle(Vector3(ax, ay, az), angle);
	}
	
	Quaternion Quaternion::fromAxisAngle(const Vector3& axis, float angle)
	{
		float theta = (float)DEG_TO_RAD(angle) * 0.5f;
		return Quaternion(axis.normalized() * (float)sin(theta), (float)cos(theta));
	}
}
