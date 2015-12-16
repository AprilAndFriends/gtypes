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
/// Represents a 3D vector.

#ifndef GTYPES_VECTOR_3_H
#define GTYPES_VECTOR_3_H

#include "gtypesExport.h"

namespace gtypes
{
	class Quaternion;
	
	/// @brief Represents a 3D vector.
	class gtypesExport Vector3
	{
	public:
		/// @brief X coordinate.
		float x;
		/// @brief Y coordinate.
		float y;
		/// @brief Z coordinate.
		float z;
	
		/// @brief Basic constructor.
		Vector3();
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		Vector3(float x, float y, float z);
		/// @brief Sets the values of the Vector3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		void set(float x, float y, float z);

		/// @brief Checks if this is a zero-length vector.
		/// @return True if this is a zero-length vector.
		bool isNull();
		
		/// @return Calculates the length of the Vector3.
		float length() const;
		/// @return Calculates the squared length of the Vector3.
		/// @note Use this if you don't need the actual length as it's faster than length().
		/// @see length()
		float squaredLength() const;

		/// @brief Normalizes the current Vector3.
		void normalize();
		/// @brief Creates a normalized Vector3 from this Vector3.
		/// @return The normalized Vector3.
		Vector3 normalized() const;
		/// @brief Calculates the dot-product between this and another Vector3.
		/// @param[in] other The other Vector3.
		/// @return The dot-product.
		float dot(const Vector3& other) const;
		/// @brief Calculates the cross-product between this and another Vector3.
		/// @param[in] other The other Vector3.
		/// @return The cross-product.
		Vector3 cross(const Vector3& v) const;

		/// @brief Creates an inverted Vector3.
		/// @return Inverted Vector3.
		Vector3 operator-() const;
		/// @brief Adds two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		Vector3 operator+(const Vector3& other) const;
		/// @brief Subtracts two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		Vector3 operator-(const Vector3& other) const;
		/// @brief Multiplies two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		Vector3 operator*(const Vector3& other) const;
		/// @brief Divides two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		Vector3 operator/(const Vector3& other) const;
		/// @brief Multiplies Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		Vector3 operator*(const float factor) const;
		/// @brief Divides Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		Vector3 operator/(const float factor) const;
		/// @brief Adds another Vector3 to this one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		Vector3 operator+=(const Vector3& other);
		/// @brief Subtracts another Vector3 to this one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		Vector3 operator-=(const Vector3& other);
		/// @brief Multiplies this Vector3 with another one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		Vector3 operator*=(const Vector3& other);
		/// @brief Divides this Vector3 with another one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		Vector3 operator/=(const Vector3& other);
		/// @brief Multiplies this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		Vector3 operator*=(const float factor);
		/// @brief Divides this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		Vector3 operator/=(const float factor);
		/// @brief Checks if two Vector3s are equal.
		/// @param[in] other The other Vector3.
		/// @return True if the two Vector3s are equal.
		/// @note Beware of floating point errors.
		bool operator==(const Vector3& other) const;
		/// @brief Checks if two Vector3s are not equal.
		/// @param[in] other The other Vector3.
		/// @return True if the two Vector3s are not equal.
		/// @note Beware of floating point errors.
		bool operator!=(const Vector3& other) const;
		
	};
}

typedef gtypes::Vector3 gvec3;

#endif
