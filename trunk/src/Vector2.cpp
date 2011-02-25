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

#include <math.h>

#include "Vector2.h"

namespace gtypes
{
	Vector2::Vector2() : x(0.0f), y(0.0f)
	{
	}

	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	void Vector2::set(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	float Vector2::length()
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}

	float Vector2::squaredLength()
	{
		return (this->x * this->x + this->y * this->y);
	}

	void Vector2::normalise()
	{
		float len = length();
		this->x /= len;
		this->y /= len;
	}

	Vector2 Vector2::normalised()
	{
		Vector2 v(this->x, this->y);
		v.normalise();
		return v;
	}

	bool Vector2::isInCircle(float center_x, float center_y, float radius)
	{
		float dx = this->x - center_x;
		float dy = this->y - center_y;
		return (dx * dx + dy * dy <= radius * radius);
	}
	
	bool Vector2::isInRectangle(float rect_x, float rect_y, float rect_w, float rect_h)
	{
		return (this->x >= rect_x && this->y >= rect_y && this->x <= rect_x + rect_w && this->y <= rect_y + rect_h);
	}

	Vector2 Vector2::operator +(const Vector2& v)
	{
		return Vector2(this->x + v.x, this->y + v.y);
	}

	Vector2 Vector2::operator -(const Vector2& v)
	{
		return Vector2(this->x - v.x, this->y - v.y);
	}
	
	Vector2 Vector2::operator *(const float f)
	{
		return Vector2(this->x * f, this->y * f);
	}
	
	Vector2 Vector2::operator /(const float f)
	{
		return Vector2(this->x / f, this->y / f);
	}

	Vector2 Vector2::operator -() const
	{
		return Vector2(-this->x, -this->y);
	}

	void Vector2::operator +=(const Vector2& v)
	{
		this->x += v.x;
		this->y += v.y;
	}

	void Vector2::operator -=(const Vector2& v)
	{
		this->x -= v.x;
		this->y -= v.y;
	}

	void Vector2::operator *=(const float f)
	{
		this->x *= f;
		this->y *= f;
	}
	
	void Vector2::operator /=(const float f)
	{
		this->x /= f;
		this->y /= f;
	}
	
	bool Vector2::operator ==(const Vector2& v)
	{
		return (x == v.x && y == v.y);
	}
	
	bool Vector2::operator !=(const Vector2& v)
	{
		return !(*this == v);
	}
	
	float Vector2::dot(Vector2 v) const
	{
		return (this->x * v.x + this->y * v.y);
	}
	
}

