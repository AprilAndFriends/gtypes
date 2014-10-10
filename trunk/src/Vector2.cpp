/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

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

	Vector2::~Vector2()
	{
	}

	void Vector2::set(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	bool Vector2::isNull()
	{
		return (this->x == 0.0f && this->y == 0.0f);
	}

	float Vector2::length() const
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}

	float Vector2::squaredLength() const
	{
		return (this->x * this->x + this->y * this->y);
	}
	
	float Vector2::angle() const
	{
		return (float)RAD_TO_DEG(atan2(-this->y, this->x));
	}

	bool Vector2::isInCircle(float center_x, float center_y, float radius)
	{
		float dx = this->x - center_x;
		float dy = this->y - center_y;
		return (dx * dx + dy * dy <= radius * radius);
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
		Vector2 result(this->x, this->y);
		result.normalize();
		return result;
	}

	void Vector2::rotate(float angle)
	{
		float old_x = this->x;
		float old_y = this->y;
		double a = DEG_TO_RAD(angle);
		double sina = sin(a);
		double cosa = cos(a);
		this->x = (float)(cosa * old_x - sina * old_y);
		this->y = (float)(sina * old_x + cosa * old_y);
	}

	Vector2 Vector2::rotated(float angle) const
	{
		Vector2 result(this->x, this->y);
		result.rotate(angle);
		return result;
	}

	float Vector2::dot(const Vector2& other) const
	{
		return (this->x * other.x + this->y * other.y);
	}

	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}

	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(this->x - other.x, this->y - other.y);
	}
	
	Vector2 Vector2::operator*(const Vector2& other) const
	{
		return Vector2(this->x * other.x, this->y * other.y);
	}

	Vector2 Vector2::operator/(const Vector2& other) const
	{
		return Vector2(this->x / other.x, this->y / other.y);
	}
	
	Vector2 Vector2::operator*(const float scale) const
	{
		return Vector2(this->x * scale, this->y * scale);
	}
	
	Vector2 Vector2::operator/(const float scale) const
	{
		float invScale = 1.0f / scale;
		return Vector2(this->x * invScale, this->y * invScale);
	}

	Vector2 Vector2::operator-() const
	{
		return Vector2(-this->x, -this->y);
	}

	Vector2 Vector2::operator+=(const Vector2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return (*this);
	}

	Vector2 Vector2::operator-=(const Vector2& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return (*this);
	}

	Vector2 Vector2::operator*=(const Vector2& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return (*this);
	}

	Vector2 Vector2::operator/=(const Vector2& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return (*this);
	}

	Vector2 Vector2::operator*=(const float scale)
	{
		this->x *= scale;
		this->y *= scale;
		return (*this);
	}
	
	Vector2 Vector2::operator/=(const float scale)
	{
		float invScale = 1.0f / scale;
		this->x *= invScale;
		this->y *= invScale;
		return (*this);
	}
	
	bool Vector2::operator==(const Vector2& other) const
	{
		return (x == other.x && y == other.y);
	}
	
	bool Vector2::operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}
	
}

