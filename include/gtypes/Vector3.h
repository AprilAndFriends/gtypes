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
/// Represents a 3D vector.

#ifndef GTYPES_VECTOR_3_H
#define GTYPES_VECTOR_3_H

#include <math.h>

#include "gtypesExport.h"
#include "Vector2.h"

namespace gtypes
{
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
		inline Vector3() : x(0.0f), y(0.0f), z(0.0f)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline Vector3(float x, float y, float z) : x(x), y(y), z(z)
		{
		}
		/// @brief Constructor.
		/// @param[in] v Vector2.
		/// @param[in] z Z coordinate.
		inline Vector3(const Vector2& v, float z) : x(v.x), y(v.y), z(z)
		{
		}
		/// @brief Sets the values of the Vector3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void set(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		/// @brief Sets the values of the Vector3.
		/// @param[in] v Vector2.
		/// @param[in] z Z coordinate.
		inline void set(const Vector2& v, float z)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = z;
		}

		/// @brief Checks if this is a zero-length vector.
		/// @return True if this is a zero-length vector.
		inline bool isNull() const
		{
			return (this->x == 0.0f && this->y == 0.0f && this->z == 0.0f);
		}
		
		/// @return Calculates the length of the Vector3.
		inline float length() const
		{
			return (float)sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}
		/// @return Calculates the squared length of the Vector3.
		/// @note Use this if you don't need the actual length as it's faster than length().
		/// @see length
		inline float squaredLength() const
		{
			return (this->x * this->x + this->y * this->y + this->z * this->z);
		}

		/// @brief Normalizes the current Vector3.
		inline void normalize()
		{
			float length = this->length();
			if (length != 0.0f)
			{
				length = 1.0f / length;
				this->x *= length;
				this->y *= length;
				this->z *= length;
			}
		}
		/// @brief Creates a normalized Vector3 from this Vector3.
		/// @return The normalized Vector3.
		inline Vector3 normalized() const
		{
			Vector3 result(this->x, this->y, this->z);
			result.normalize();
			return result;
		}
		/// @brief Calculates the dot-product between this and another Vector3.
		/// @param[in] other The other Vector3.
		/// @return The dot-product.
		inline float dot(const Vector3& other) const
		{
			return (this->x * other.x + this->y * other.y + this->z * other.z);
		}
		/// @brief Calculates the cross-product between this and another Vector3.
		/// @param[in] other The other Vector3.
		/// @return The cross-product.
		inline Vector3 cross(const Vector3& other) const
		{
			return Vector3(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
		}

		/// @brief Creates an inverted Vector3.
		/// @return Inverted Vector3.
		inline Vector3 operator-() const
		{
			return Vector3(-this->x, -this->y, -this->z);
		}
		/// @brief Adds two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		inline Vector3 operator+(const Vector3& other) const
		{
			return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
		}
		/// @brief Subtracts two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		inline Vector3 operator-(const Vector3& other) const
		{
			return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
		}
		/// @brief Multiplies two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		inline Vector3 operator*(const Vector3& other) const
		{
			return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
		}
		/// @brief Divides two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		inline Vector3 operator/(const Vector3& other) const
		{
			return Vector3(this->x / other.x, this->y / other.y, this->z / other.z);
		}
		/// @brief Multiplies Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		inline Vector3 operator*(float factor) const
		{
			return Vector3(this->x * factor, this->y * factor, this->z * factor);
		}
		/// @brief Divides Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		inline Vector3 operator/(float factor) const
		{
			float invFactor = 1.0f / factor;
			return Vector3(this->x * invFactor, this->y * invFactor, this->z * invFactor);
		}
		/// @brief Sets this Vector3 to another one.
		/// @param[in] other The other Vector3.
		/// @return This Vector3.
		inline Vector3 operator=(const Vector3& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return (*this);
		}
		/// @brief Adds another Vector3 to this one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		inline Vector3 operator+=(const Vector3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return (*this);
		}
		/// @brief Subtracts another Vector3 to this one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		inline Vector3 operator-=(const Vector3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return (*this);
		}
		/// @brief Multiplies this Vector3 with another one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		inline Vector3 operator*=(const Vector3& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			return (*this);
		}
		/// @brief Divides this Vector3 with another one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		inline Vector3 operator/=(const Vector3& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			return (*this);
		}
		/// @brief Multiplies this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3 operator*=(float factor)
		{
			this->x *= factor;
			this->y *= factor;
			this->z *= factor;
			return (*this);
		}
		/// @brief Divides this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3 operator/=(float factor)
		{
			float invFactor = 1.0f / factor;
			this->x *= invFactor;
			this->y *= invFactor;
			this->z *= invFactor;
			return (*this);
		}
		/// @brief Checks if two Vector3s are equal.
		/// @param[in] other The other Vector3.
		/// @return True if the two Vector3s are equal.
		/// @note Beware of floating point errors.
		inline bool operator==(const Vector3& other) const
		{
			return (this->x == other.x && this->y == other.y && this->z == other.z);
		}
		/// @brief Checks if two Vector3s are not equal.
		/// @param[in] other The other Vector3.
		/// @return True if the two Vector3s are not equal.
		/// @note Beware of floating point errors.
		inline bool operator!=(const Vector3& other) const
		{
			return !(*this == other);
		}
		
	};
}

/// @brief Alias for simpler code.
typedef gtypes::Vector3 gvec3;
/// @brief Alias for simpler code.
typedef const gtypes::Vector3& cgvec3;

#endif
