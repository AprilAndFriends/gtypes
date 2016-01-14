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
	void Matrix4::set(const Matrix3& mat3)
	{
		this->data[0] = mat3[0];	this->data[1] = mat3[1];	this->data[2] = mat3[2];	this->data[3] = 0.0f;
		this->data[4] = mat3[4];	this->data[5] = mat3[5];	this->data[6] = mat3[6];	this->data[7] = 0.0f;
		this->data[8] = mat3[8];	this->data[9] = mat3[9];	this->data[10] = mat3[10];	this->data[11] = 0.0f;
		this->data[12] = 0.0f;		this->data[13] = 0.0f;		this->data[14] = 0.0f;		this->data[15] = 1.0f;
	}
}
