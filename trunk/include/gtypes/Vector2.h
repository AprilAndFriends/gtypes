/// @file
/// @version 1.6
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

#include "gtypesExport.h"

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
		Vector2();
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		Vector2(float x, float y);
		/// @brief Destructor.
		~Vector2();
		/// @brief Sets the values of the Vector2.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		void set(float x, float y);

		/// @brief Checks if this is a zero-length vector.
		/// @return True if this is a zero-length vector.
		bool isNull();

		/// @return Calculates the length of the Vector2.
		float length() const;
		/// @return Calculates the squared length of the Vector2.
		/// @note Use this if you don't need the actual length as it's faster than length().
		/// @see length()
		float squaredLength() const;
		/// @return Calculates the angle of the Vector2
		/// @note An angle of 0° means x = 1 and y = 0. The angle increases in a counterclockwise direction.
		float angle() const;
		/// @brief Calculates the dot-product between this and another Vector2.
		/// @param[in] other The other Vector2.
		/// @return The dot-product.
		bool isInCircle(float center_x, float center_y, float radius);

		/// @brief Normalizes the current Vector2.
		void normalize();
		/// @brief Creates a normalized Vector2 from this Vector2.
		/// @return The normalized Vector2.
		Vector2 normalized() const;
		/// @brief Rotates the current Vector2 by an angle.
		/// @param[in] angle The angle.
		void rotate(float angle);
		/// @brief Creates a rotated Vector2 from this Vector2.
		/// @param[in] angle The angle.
		/// @return The rotated Vector2.
		Vector2 rotated(float angle) const;
		/// @brief Calculates the dot-product between this and another Vector2.
		/// @param[in] other The other Vector2.
		/// @return The dot-product.
		float dot(const Vector2& other) const;

		/// @brief Creates an inverted Vector2.
		/// @return Inverted Vector2.
		Vector2 operator-() const;
		/// @brief Adds two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		Vector2 operator+(const Vector2& other) const;
		/// @brief Subtracts two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		Vector2 operator-(const Vector2& other) const;
		/// @brief Multiplies two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		Vector2 operator*(const Vector2& other) const;
		/// @brief Divides two Vector2s.
		/// @param[in] other The other Vector2.
		/// @return The resulting Vector2.
		Vector2 operator/(const Vector2& other) const;
		/// @brief Multiplies Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector2.
		Vector2 operator*(const float factor) const;
		/// @brief Divides Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector2.
		Vector2 operator/(const float factor) const;
		/// @brief Adds another Vector2 to this one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		Vector2 operator+=(const Vector2& other);
		/// @brief Subtracts another Vector2 to this one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		Vector2 operator-=(const Vector2& other);
		/// @brief Multiplies this Vector2 with another one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		Vector2 operator*=(const Vector2& other);
		/// @brief Divides this Vector2 with another one.
		/// @param[in] other The other Vector2.
		/// @return A copy of this Vector2.
		Vector2 operator/=(const Vector2& other);
		/// @brief Multiplies this Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector2.
		Vector2 operator*=(const float factor);
		/// @brief Divides this Vector2 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector2.
		Vector2 operator/=(const float factor);
		/// @brief Checks if two Vector2s are equal.
		/// @param[in] other The other Vector2.
		/// @return True if the two Vector2s are equal.
		/// @note Beware of floating point errors.
		bool operator==(const Vector2& other) const;
		/// @brief Checks if two Vector2s are not equal.
		/// @param[in] other The other Vector2.
		/// @return True if the two Vector2s are not equal.
		/// @note Beware of floating point errors.
		bool operator!=(const Vector2& other) const;

	};
}

typedef gtypes::Vector2 gvec2;

#endif
