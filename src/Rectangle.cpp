/// @file
/// @author  Boris Mikic
/// @version 1.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include "Rectangle.h"
#include "Vector2.h"

namespace gtypes
{
	Rectangle::Rectangle() : x(0.0f), y(0.0f), w(0.0f), h(0.0f)
	{
	}

	Rectangle::Rectangle(float x, float y, float w, float h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	
	Rectangle::Rectangle(Vector2 position, Vector2 size)
	{
		this->x = position.x;
		this->y = position.y;
		this->w = size.x;
		this->h = size.y;
	}
	
	Rectangle::Rectangle(Vector2 position, float w, float h)
	{
		this->x = position.x;
		this->y = position.y;
		this->w = w;
		this->h = h;
	}
	
	Rectangle::Rectangle(float x, float y, Vector2 size)
	{
		this->x = x;
		this->y = y;
		this->w = size.x;
		this->h = size.y;
	}
	
	void Rectangle::set(float x, float y, float w, float h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	
	void Rectangle::set(Vector2 position, Vector2 size)
	{
		this->x = position.x;
		this->y = position.y;
		this->w = size.x;
		this->h = size.y;
	}
	
	void Rectangle::set(Vector2 position, float w, float h)
	{
		this->x = position.x;
		this->y = position.y;
		this->w = w;
		this->h = h;
	}
	
	void Rectangle::set(float x, float y, Vector2 size)
	{
		this->x = x;
		this->y = y;
		this->w = size.x;
		this->h = size.y;
	}
	
	Vector2 Rectangle::getPosition()
	{
		return Vector2(this->x, this->y);
	}
	
	void Rectangle::setPosition(Vector2 position)
	{
		this->x = position.x;
		this->y = position.y;
	}
	
	Vector2 Rectangle::getSize()
	{
		return Vector2(this->w, this->h);
	}
	
	void Rectangle::setSize(Vector2 size)
	{
		this->w = size.x;
		this->h = size.y;
	}
	
	float Rectangle::getAspect()
	{
		return (this->w / this->h);
	}
	
	bool Rectangle::intersects(Rectangle& other) const
	{
		return (this->x + this->w > other.x && this->x < other.x + other.w &&
				this->y + this->h > other.y && this->y < other.y + other.h);
	}
	
	bool Rectangle::isPointInside(Vector2& vector) const
	{
		return (vector.x >= this->x && vector.y >= this->y && vector.x <= this->x + this->w && vector.y <= this->y + this->h);
	}

	bool Rectangle::isPointInside(float x, float y) const
	{
		return (x >= this->x && y >= this->y && x <= this->x + this->w && y <= this->y + this->h);
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
	
	Rectangle Rectangle::operator/(float scale)
	{
		Rectangle result(*this);
		result /= scale;
		return result;
	}
	
	Rectangle Rectangle::operator+=(Vector2& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return (*this);
	}
	
	Rectangle Rectangle::operator-=(Vector2& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		return (*this);
	}
	
	Rectangle Rectangle::operator*=(float scale)
	{
		this->w *= scale;
		this->h *= scale;
		return (*this);
	}
	
	Rectangle Rectangle::operator/=(float scale)
	{
		this->w /= scale;
		this->h /= scale;
		return (*this);
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

