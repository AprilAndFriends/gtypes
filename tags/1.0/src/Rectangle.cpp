/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "Rectangle.h"
#include "Vector2.h"

namespace gtypes
{
	Rectangle::Rectangle() : x(0.0f), y(0.0f), w(0.0f), h(0.0f)
	{
	}

	Rectangle::Rectangle(float _x, float _y, float _w, float _h)
	{
		this->x = _x;
		this->y = _y;
		this->w = _w;
		this->h = _h;
	}
	
	bool Rectangle::intersects(Rectangle &other)
	{
		return (this->x + this->w > other.x && this->x < other.x + other.w &&
				this->y + this->h > other.y && this->y < other.y + other.h);
	}
	
	bool Rectangle::isVector2In(Vector2& vector)
	{
		return (vector.x >= this->x && vector.y >= this->y && vector.x <= this->x + this->w && vector.y <= this->y + this->h);
	}

	Rectangle Rectangle::operator+(Vector2 vector)
	{
		Rectangle result(*this);
		result += vector;
		return result;
	}
	
	Rectangle Rectangle::operator-(Vector2 vector)
	{
		Rectangle result(*this);
		result -= vector;
		return result;
	}
	
	Rectangle Rectangle::operator*(float scale)
	{
		Rectangle result(*this);
		result *= scale;
		return result;
	}
	
	void Rectangle::operator+=(Vector2& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
	}
	
	void Rectangle::operator-=(Vector2& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
	}
	
	void Rectangle::operator*=(float scale)
	{
		this->w *= scale;
		this->h *= scale;
	}
	
    bool Rectangle::operator==(const Rectangle& other)
    {
		return (this->x == other.x && this->y == other.y && this->w == other.w && this->h == other.h);
    }
    
    bool Rectangle::operator!=(const Rectangle& other)
    {
        return !(*this == other);
    }
	
}
