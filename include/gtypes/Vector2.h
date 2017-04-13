/// @file
/// @version 2.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Represents a 2D vector.

#ifndef GTYPES_VECTOR_2_H
#define GTYPES_VECTOR_2_H

#include <math.h>

#include "gtypesExport.h"
#include "gtypesUtil.h"

namespace gtypes
{
	/// @brief Represents a 2D vector.
	class gtypesExport Vector2
	{
	public:
		/// @brief X coordinate.
		float x;
		/// @brief Y coordinate.
		float y;

		/// @brief Basic constructor.
		inline Vector2() : x(0.0f), y(0.0f)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline Vector2(float x, float y) : x(x), y(y)
		{
		}
		/// @brief Sets the values of the Vector2.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline void set(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		/// @brief Checks if this is a zero-length vector.
		/// @return True if this is a zero-length vector.
		inline bool isNull() const
		{
			return (this->x == 0.0f && this->y == 0.0f);
		}

		/// @return Calculates the length of the Vector2.
		inline float length() const
		{
			return (float)sqrt(this->x * this->x + this->y * this->y);
		}
		/// @return Calculates the squared length of the Vector2.
		/// @note Use this if you don't need the actual length as it's faster than length().
		/// @see length
		inline float squaredLength() const
		{
			return (this->x * this->x + this->y * this->y);
		}
		/// @return Calculates the angle of the Vector2.
		/// @note An angle of 0° means x = 1 and y = 0. The angle increases in a counterclockwise direction.
		inline float angle() const
		{
			return (float)RAD_TO_DEG(atan2(-this->y, this->x));
		}
		/// @brief Checks if the Vector2 is located within a circle defined by a center and a radius.
		/// @param[in] centerX Center X coordinate of the circle.
		/// @param[in] centerY Center Y coordinate of the circle.
		/// @param[in] radius Radius of the circle.
		/// @return True if this Vector2 is located within the circle.
		inline bool isInCircle(float centerX, float centerY, float radius) const
		{
			float dx = this->x - centerX;
			float dy = this->y - centerY;
			return (dx * dx + dy * dy <= radius * radius);
		}
		/// @brief Checks if the Vector2 is located within a circle defined by a center and a radius.
		/// @param[in] center Center coordinate of the circle as Vector2.
		/// @param[in] radius Radius of the circle.
		/// @return True if this Vector2 is located within the circle.
		inline bool isInCircle(const Vector2& center, float radius) const
		{
			float dx = this->x - center.x;
			float dy = this->y - center.y;
			return (dx * dx + dy * dy <= radius * radius);
		}

		/// @brief Normalizes the current Vector2.
		inline void normalize()
		{
			float length = this->length();
			if (length != 0.0f)
			{
				length = 1.0f / length;
				this->x *= length;
				this->y *= length;
			}
		}
		/// @brief Creates a normalized Vector2 from this Vector2.
		/// @return The normalized Vector2.
		inline Vector2 normalized() const
		{
			Vector2 result(this->x, this->y);
			result.normalize();
			return result;
		}
		/// @brief Rotates the current Vector2 by an angle.
		/// @param[in] angle The angle.
		inline void rotate(float angle)
		{
			float old_x = this->x;
			float old_y = this->y;
			double a = DEG_TO_RAD(angle);
			double sina = sin(a);
			double cosa = cos(a);
			this->x = (float)(cosa * old_x - sina * old_y);
			this->y = (float)(sina * old_x + cosa * old_y);
		}
		/// @brief Creates a rotated Vector2 from this Vector2.
		/// @param[in] angle The angle.
		/// @return The rotated Vector2.
		inline Vector2 rotated(float angle) const
		{
			Vector2 result(this->x, this->y);
			result.rotate(angle);
			return result;
		}
		/// @brief Calculates the dot-product between this and another Vector2.
		/// @param[in] other The other Vector2.
		/// @return The dot-product.
		inline float dot(const Vector2& other) const
		{
			return (this->x * other.x + this->y * other.y);
		}

		/// @brief Creates an inverted Vector2.
		/// @return Inverted Vector2.
		inline Vector2 operator-() const
		{
			return Vector2(-this->x, -this->y);
		}
		/// @brief Adds two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		inline Vector2 operator+(const Vector2& other) const
		{
			return Vector2(this->x + other.x, this->y + other.y);
		}
		/// @brief Subtracts two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		inline Vector2 operator-(const Vector2& other) const
		{
			return Vector2(this->x - other.x, this->y - other.y);
		}
		/// @brief Multiplies two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		inline Vector2 operator*(const Vector2& other) const
		{
			return Vector2(this->x * other.x, this->y * other.y);
		}
		/// @brief Divides two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		inline Vector2 operator/(const Vector2& other) const
		{
			return Vector2(this->x / other.x, this->y / other.y);
		}
		/// @brief Multiplies Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector2.
		inline Vector2 operator*(float factor) const
		{
			return Vector2(this->x * factor, this->y * factor);
		}
		/// @brief Divides Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector2.
		inline Vector2 operator/(float factor) const
		{
			float invScale = 1.0f / factor;
			return Vector2(this->x * invScale, this->y * invScale);
		}
		/// @brief Sets this Vector2 to another one.
		/// @param[in] other The other Vector2.
		/// @return This Vector2.
		inline Vector2 operator=(const Vector2& other)
		{
			this->x = other.x;
			this->y = other.y;
			return (*this);
		}
		/// @brief Adds another Vector2 to this one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		inline Vector2 operator+=(const Vector2& other)
		{
			this->x += other.x;
			this->y += other.y;
			return (*this);
		}
		/// @brief Subtracts another Vector2 to this one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		inline Vector2 operator-=(const Vector2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return (*this);
		}
		/// @brief Multiplies this Vector2 with another one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		inline Vector2 operator*=(const Vector2& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			return (*this);
		}
		/// @brief Divides this Vector2 with another one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		inline Vector2 operator/=(const Vector2& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			return (*this);
		}
		/// @brief Multiplies this Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector2.
		inline Vector2 operator*=(float factor)
		{
			this->x *= factor;
			this->y *= factor;
			return (*this);
		}
		/// @brief Divides this Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector2.
		inline Vector2 operator/=(float factor)
		{
			float invScale = 1.0f / factor;
			this->x *= invScale;
			this->y *= invScale;
			return (*this);
		}
		/// @brief Checks if two Vector2s are equal.
		/// @param[in] other The other Vector2.
		/// @return True if the two Vector2s are equal.
		/// @note Beware of floating point errors.
		inline bool operator==(const Vector2& other) const
		{
			return (x == other.x && y == other.y);
		}
		/// @brief Checks if two Vector2s are not equal.
		/// @param[in] other The other Vector2.
		/// @return True if the two Vector2s are not equal.
		/// @note Beware of floating point errors.
		inline bool operator!=(const Vector2& other) const
		{
			return !(*this == other);
		}
	};
}

/// @brief Alias for simpler code.
typedef gtypes::Vector2 gvec2;
/// @brief Alias for simpler code.
typedef const gtypes::Vector2& cgvec2;

#endif
