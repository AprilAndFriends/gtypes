/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include "Matrix3.h"
#include "Matrix4.h"

namespace gtypes
{
	Matrix3::Matrix3()
	{
		this->setIdentity();
	}
	
	Matrix3::Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		this->set(m0, m1, m2, m3, m4, m5, m6, m7, m8);
	}
	
	Matrix3::Matrix3(const float m[])
	{
		this->set(m);
	}
	
	Matrix3::Matrix3(const Matrix4& mat)
	{
		this->set(mat);
	}
}

