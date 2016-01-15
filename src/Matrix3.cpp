/// @file
/// @version 2.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include "CatmullRomSpline2.h" // has to be here, otherwise the optimizer strips away this class
#include "CatmullRomSpline3.h" // has to be here, otherwise the optimizer strips away this class
#include "Matrix3.h"
#include "Matrix4.h"

namespace gtypes
{
	Matrix3::Matrix3(const Matrix4& mat)
	{
		this->set(mat);
	}

	void Matrix3::set(const Matrix4& mat4)
	{
		static int rowSize = sizeof(float) * 3;
		memcpy(this->data, mat4.data, rowSize);
		memcpy(&this->data[3], &mat4.data[4], rowSize);
		memcpy(&this->data[6], &mat4.data[8], rowSize);
	}

}

