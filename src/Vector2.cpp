/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include "Vector2.h"

namespace gtypes
{
	Vector2::Vector2() : x(0.0f), y(0.0f)
	{
	}

	Vector2::Vector2(float x, float y)
	{
		this->set(x, y);
	}
}

