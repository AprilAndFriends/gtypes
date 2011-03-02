/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include "Vector4.h"

namespace gtypes
{
	Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}

	Vector4::Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4::Vector4(const float v[])
	{
		this->x = v[0];
		this->y = v[1];
		this->z = v[2];
		this->w = v[3];
	}

	void Vector4::set(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

}

