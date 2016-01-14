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
#include "Rectangle.h"
#include "Vector3.h"

namespace gtypes
{
	Matrix4::Matrix4()
	{
		this->setIdentity();
	}

	Matrix4::Matrix4(float m0, float m1, float m2, float m3,
					 float m4, float m5, float m6, float m7,
					 float m8, float m9, float m10, float m11,
					 float m12, float m13, float m14, float m15)
	{
		this->set(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15);
	}
	
	Matrix4::Matrix4(const float m[])
	{
		this->set(m);
	}
	
	Matrix4::Matrix4(const Matrix3& mat3)
	{
		this->set(mat3);
	}

	Matrix4::Matrix4(const Vector3& axis, float angle)
	{
		this->setRotation(axis.x, axis.y, axis.z, (float)DEG_TO_RAD(angle));
	}

	Matrix4::Matrix4(float x, float y, float z, float angle)
	{
		this->setRotation(x, y, z, (float)DEG_TO_RAD(angle));
	}
	
	void Matrix4::set(const Matrix3& mat3)
	{
		this->data[0] = mat3[0];	this->data[1] = mat3[1];	this->data[2] = mat3[2];	this->data[3] = 0.0f;
		this->data[4] = mat3[4];	this->data[5] = mat3[5];	this->data[6] = mat3[6];	this->data[7] = 0.0f;
		this->data[8] = mat3[8];	this->data[9] = mat3[9];	this->data[10] = mat3[10];	this->data[11] = 0.0f;
		this->data[12] = 0.0f;		this->data[13] = 0.0f;		this->data[14] = 0.0f;		this->data[15] = 1.0f;
	}
}
