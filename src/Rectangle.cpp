/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include "Rectangle.h"

namespace gtypes
{
	Rectangle::Rectangle() : x(0.0f), y(0.0f), w(0.0f), h(0.0f)
	{
	}

	Rectangle::Rectangle(float x, float y, float w, float h)
	{
		this->set(x, y, w, h);
	}
	
	Rectangle::Rectangle(Vector2 position, Vector2 size)
	{
		this->set(position, size);
	}
	
	Rectangle::Rectangle(Vector2 position, float w, float h)
	{
		this->set(position, w, h);
	}
	
	Rectangle::Rectangle(float x, float y, Vector2 size)
	{
		this->set(x, y, size);
	}	
}

