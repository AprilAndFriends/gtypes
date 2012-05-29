/// @file
/// @author  Boris Mikic
/// @version 1.43
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
	
	void Rectangle::setPosition(float x, float y)
	{
		this->x = x;
		this->y = y;
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
	
	void Rectangle::setSize(float w, float h)
	{
		this->w = w;
		this->h = h;
	}
	
	Vector2 Rectangle::getCenter()
	{
		return Vector2(this->x + this->w * 0.5f, this->y + this->h * 0.5f);
	}
	
	float Rectangle::getAspect()
	{
		return (this->w / this->h);
	}

	Vector2 Rectangle::getTopLeft()
	{
		return Vector2(this->x, this->y);
	}
	
	Vector2 Rectangle::getTopRight()
	{
		return Vector2(this->x + this->w, this->y);
	}
	
	Vector2 Rectangle::getBottomLeft()
	{
		return Vector2(this->x, this->y + this->h);
	}
	
	Vector2 Rectangle::getBottomRight()
	{
		return Vector2(this->x + this->w, this->y + this->h);
	}
	
	float Rectangle::left()
	{
		return this->x;
	}
	
	float Rectangle::right()
	{
		return (this->x + this->w);
	}
	
	float Rectangle::top()
	{
		return this->y;
	}
	
	float Rectangle::bottom()
	{
		return (this->y + this->h);
	}
	
	bool Rectangle::intersects(const Rectangle& other) const
	{
		return (this->x + this->w > other.x && this->x < other.x + other.w &&
				this->y + this->h > other.y && this->y < other.y + other.h);
	}
	
	bool Rectangle::isPointInside(const Vector2& vector) const
	{
		return (vector.x >= this->x && vector.y >= this->y && vector.x <= this->x + this->w - 1 && vector.y <= this->y + this->h - 1);
	}

	bool Rectangle::isPointInside(float x, float y) const
	{
		return (x >= this->x && y >= this->y && x <= this->x + this->w - 1 && y <= this->y + this->h - 1);
	}

	Rectangle Rectangle::operator+(Vector2 vector) const
	{
		Rectangle result(*this);
		result += vector;
		return result;
	}
	
	Rectangle Rectangle::operator-(Vector2 vector) const
	{
		Rectangle result(*this);
		result -= vector;
		return result;
	}
	
	Rectangle Rectangle::operator*(Vector2 vector) const
	{
		Rectangle result(*this);
		result *= vector;
		return result;
	}
	
	Rectangle Rectangle::operator/(Vector2 vector) const
	{
		Rectangle result(*this);
		result /= vector;
		return result;
	}
	
	Rectangle Rectangle::operator*(float scale) const
	{
		Rectangle result(*this);
		result *= scale;
		return result;
	}
	
	Rectangle Rectangle::operator/(float scale) const
	{
		Rectangle result(*this);
		result /= scale;
		return result;
	}
	
	Rectangle Rectangle::operator+=(const Vector2& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		return (*this);
	}
	
	Rectangle Rectangle::operator-=(const Vector2& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		return (*this);
	}
	
	Rectangle Rectangle::operator*=(const Vector2& vector)
	{
		this->x *= vector.x;
		this->y *= vector.y;
		return (*this);
	}
	
	Rectangle Rectangle::operator/=(const Vector2& vector)
	{
		this->x /= vector.x;
		this->y /= vector.y;
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
	
	bool Rectangle::operator==(const Rectangle& other) const
	{
		return (this->x == other.x && this->y == other.y && this->w == other.w && this->h == other.h);
	}
	
	bool Rectangle::operator!=(const Rectangle& other) const
	{
		return !(*this == other);
	}
	
}

