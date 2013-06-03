/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.46
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include <math.h>

#include "gtypesUtil.h"
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

	float Vector2::length() const
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}

	float Vector2::squaredLength() const
	{
		return (this->x * this->x + this->y * this->y);
	}
	
	void Vector2::rotate(float angle)
	{
		float old_x = this->x;
		float old_y = this->y;
		double a = DEG_TO_RAD(angle);
		this->x = (float)(cos(a) * old_x - sin(a) * old_y);
		this->y = (float)(sin(a) * old_x + cos(a) * old_y);
	}
	
	Vector2 Vector2::rotated(float angle) const
	{
		gvec2 v(this->x, this->y);
		v.rotate(angle);
		return v;
	}

	float Vector2::angle() const
	{
		return (float)RAD_TO_DEG(atan2(-this->y, this->x));
	}
	
	void Vector2::normalize()
	{
		float length = this->length();
		if (length != 0.0f)
		{
			length = 1.0f / length;
			this->x *= length;
			this->y *= length;
		}
	}

	Vector2 Vector2::normalized() const
	{
		Vector2 v(this->x, this->y);
		v.normalize();
		return v;
	}

	bool Vector2::isInCircle(float center_x, float center_y, float radius)
	{
		float dx = this->x - center_x;
		float dy = this->y - center_y;
		return (dx * dx + dy * dy <= radius * radius);
	}
	
	bool Vector2::isNull()
	{
		return (this->x == 0.0f && this->y == 0.0f);
	}
	
	Vector2 Vector2::operator+(const Vector2& v) const
	{
		return Vector2(this->x + v.x, this->y + v.y);
	}

	Vector2 Vector2::operator-(const Vector2& v) const
	{
		return Vector2(this->x - v.x, this->y - v.y);
	}
	
	Vector2 Vector2::operator*(const Vector2& v) const
	{
		return Vector2(this->x * v.x, this->y * v.y);
	}

	Vector2 Vector2::operator/(const Vector2& v) const
	{
		return Vector2(this->x / v.x, this->y / v.y);
	}
	
	Vector2 Vector2::operator*(const float f) const
	{
		return Vector2(this->x * f, this->y * f);
	}
	
	Vector2 Vector2::operator/(const float f) const
	{
		return Vector2(this->x / f, this->y / f);
	}

	Vector2 Vector2::operator-() const
	{
		return Vector2(-this->x, -this->y);
	}

	Vector2 Vector2::operator+=(const Vector2& v)
	{
		this->x += v.x;
		this->y += v.y;
		return (*this);
	}

	Vector2 Vector2::operator-=(const Vector2& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		return (*this);
	}

	Vector2 Vector2::operator*=(const Vector2& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		return (*this);
	}

	Vector2 Vector2::operator/=(const Vector2& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		return (*this);
	}

	Vector2 Vector2::operator*=(const float f)
	{
		this->x *= f;
		this->y *= f;
		return (*this);
	}
	
	Vector2 Vector2::operator/=(const float f)
	{
		this->x /= f;
		this->y /= f;
		return (*this);
	}
	
	bool Vector2::operator==(const Vector2& v) const
	{
		return (x == v.x && y == v.y);
	}
	
	bool Vector2::operator!=(const Vector2& v) const
	{
		return !(*this == v);
	}
	
	float Vector2::dot(Vector2 v) const
	{
		return (this->x * v.x + this->y * v.y);
	}
	
}

