/// @file
/// @version 3.0
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
	template <typename T>
	class Vector3
	{
	public:
		/// @brief X coordinate.
		T x;
		/// @brief Y coordinate.
		T y;
		/// @brief Z coordinate.
		T z;
	
		/// @brief Basic constructor.
		inline Vector3() : x(0), y(0), z(0)
		{
		}
		/// @brief Advanced copy constructor.
		template <typename S>
		inline Vector3(const Vector3<S>& other) : x((T)other.x), y((T)other.y)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline Vector3(T x, T y, T z) : x(x), y(y), z(z)
		{
		}
		/// @brief Constructor.
		/// @param[in] v Vector2.
		/// @param[in] z Z coordinate.
		inline Vector3(const Vector2<T>& v, T z) : x(v.x), y(v.y), z(z)
		{
		}
		/// @brief Sets the values of the Vector3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void set(T x, T y, T z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		/// @brief Sets the values of the Vector3.
		/// @param[in] v Vector2.
		/// @param[in] z Z coordinate.
		inline void set(const Vector2<T>& v, T z)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = z;
		}

		/// @brief Checks if this is a zero-length vector.
		/// @return True if this is a zero-length vector.
		inline bool isNull() const
		{
			return (this->x == 0 && this->y == 0 && this->z == 0);
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
				this->x = (T)(this->x * length);
				this->y = (T)(this->y * length);
				this->z = (T)(this->z * length);
			}
		}
		/// @brief Creates a normalized Vector3<T> from this Vector3.
		/// @return The normalized Vector3.
		inline Vector3<T> normalized() const
		{
			Vector3<T> result(this->x, this->y, this->z);
			result.normalize();
			return result;
		}
		/// @brief Calculates the dot-product between this and another Vector3.
		/// @param[in] other The other Vector3.
		/// @return The dot-product.
		inline T dot(const Vector3<T>& other) const
		{
			return (this->x * other.x + this->y * other.y + this->z * other.z);
		}
		/// @brief Calculates the cross-product between this and another Vector3.
		/// @param[in] other The other Vector3.
		/// @return The cross-product.
		inline Vector3<T> cross(const Vector3<T>& other) const
		{
			return Vector3<T>(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
		}

		/// @brief Creates an inverted Vector3.
		/// @return Inverted Vector3.
		inline Vector3<T> operator-() const
		{
			return Vector3<T>(-this->x, -this->y, -this->z);
		}
		/// @brief Adds two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		template <typename S>
		inline Vector3<T> operator+(const Vector3<S>& other) const
		{
			return Vector3<T>((T)(this->x + other.x), (T)(this->y + other.y), (T)(this->z + other.z));
		}
		/// @brief Subtracts two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		template <typename S>
		inline Vector3<T> operator-(const Vector3<S>& other) const
		{
			return Vector3<T>((T)(this->x - other.x), (T)(this->y - other.y), (T)(this->z - other.z));
		}
		/// @brief Multiplies two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		template <typename S>
		inline Vector3<T> operator*(const Vector3<S>& other) const
		{
			return Vector3<T>((T)(this->x * other.x), (T)(this->y * other.y), (T)(this->z * other.z));
		}
		/// @brief Divides two Vector3s.
		/// @param[in] other The other Vector3.
		/// @return The resulting Vector3.
		template <typename S>
		inline Vector3<T> operator/(const Vector3<S>& other) const
		{
			return Vector3<T>((T)(this->x / other.x), (T)(this->y / other.y), (T)(this->z / other.z));
		}
		/// @brief Multiplies Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		template <typename S>
		inline Vector3<T> operator*(S factor) const
		{
			return Vector3<T>((T)(this->x * factor), (T)(this->y * factor), (T)(this->z * factor));
		}
		/// @brief Divides Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		inline Vector3<T> operator/(int factor) const
		{
			return Vector3<T>(this->x / factor, this->y / factor, this->z / factor);
		}
		/// @brief Divides Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		inline Vector3<T> operator/(float factor) const
		{
			float invertedFactor = 1.0f / factor;
			return Vector3<T>((T)(this->x * invertedFactor), (T)(this->y * invertedFactor), (T)(this->z * invertedFactor));
		}
		/// @brief Divides Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Vector3.
		inline Vector3<T> operator/(double factor) const
		{
			double invertedFactor = 1.0 / factor;
			return Vector3<T>((T)(this->x * invertedFactor), (T)(this->y * invertedFactor), (T)(this->z * invertedFactor));
		}
		/// @brief Sets this Vector3 to another one.
		/// @param[in] other The other Vector3.
		/// @return This Vector3.
		template <typename S>
		inline Vector3<T> operator=(const Vector3<S>& other)
		{
			this->x = (T)other.x;
			this->y = (T)other.y;
			this->z = (T)other.z;
			return (*this);
		}
		/// @brief Adds another Vector3 to this one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		template <typename S>
		inline Vector3<T> operator+=(const Vector3<S>& other)
		{
			this->x = (T)(this->x + other.x);
			this->y = (T)(this->y + other.y);
			this->z = (T)(this->z + other.z);
			return (*this);
		}
		/// @brief Subtracts another Vector3 to this one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		template <typename S>
		inline Vector3<T> operator-=(const Vector3<S>& other)
		{
			this->x = (T)(this->x - other.x);
			this->y = (T)(this->y - other.y);
			this->z = (T)(this->z - other.z);
			return (*this);
		}
		/// @brief Multiplies this Vector3 with another one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		template <typename S>
		inline Vector3<T> operator*=(const Vector3<S>& other)
		{
			this->x = (T)(this->x * other.x);
			this->y = (T)(this->y * other.y);
			this->z = (T)(this->z * other.z);
			return (*this);
		}
		/// @brief Divides this Vector3 with another one.
		/// @param[in] other The other Vector3.
		/// @return A copy of this Vector3.
		template <typename S>
		inline Vector3<T> operator/=(const Vector3<S>& other)
		{
			this->x = (T)(this->x / other.x);
			this->y = (T)(this->y / other.y);
			this->z = (T)(this->z / other.z);
			return (*this);
		}
		/// @brief Multiplies this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3<T> operator*=(int factor)
		{
			this->x *= factor;
			this->y *= factor;
			this->z *= factor;
			return (*this);
		}
		/// @brief Multiplies this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3<T> operator*=(float factor)
		{
			this->x = (T)(this->x * factor);
			this->y = (T)(this->y * factor);
			this->z = (T)(this->z * factor);
			return (*this);
		}
		/// @brief Multiplies this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3<T> operator*=(double factor)
		{
			this->x = (T)(this->x * factor);
			this->y = (T)(this->y * factor);
			this->z = (T)(this->z * factor);
			return (*this);
		}
		/// @brief Divides this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3<T> operator/=(int factor)
		{
			this->x /= factor;
			this->y /= factor;
			this->z /= factor;
			return (*this);
		}
		/// @brief Divides this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3<T> operator/=(float factor)
		{
			float invertedFactor = 1.0f / factor;
			this->x = (T)(this->x * invertedFactor);
			this->y = (T)(this->y * invertedFactor);
			this->z = (T)(this->z * invertedFactor);
			return (*this);
		}
		/// @brief Divides this Vector3 with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Vector3.
		inline Vector3<T> operator/=(double factor)
		{
			double invertedFactor = 1.0 / factor;
			this->x = (T)(this->x * invertedFactor);
			this->y = (T)(this->y * invertedFactor);
			this->z = (T)(this->z * invertedFactor);
			return (*this);
		}
		/// @brief Checks if two Vector3s are equal.
		/// @param[in] other The other Vector3.
		/// @return True if the two Vector3s are equal.
		/// @note Beware of floating point errors.
		inline bool operator==(const Vector3<T>& other) const
		{
			return (this->x == other.x && this->y == other.y && this->z == other.z);
		}
		/// @brief Checks if two Vector3s are not equal.
		/// @param[in] other The other Vector3.
		/// @return True if the two Vector3s are not equal.
		/// @note Beware of floating point errors.
		inline bool operator!=(const Vector3<T>& other) const
		{
			return !(*this == other);
		}
		
	};

}

/// @brief Typedef for simpler code.
typedef gtypes::Vector3<int> gvec3i;
/// @brief Typedef for simpler code.
typedef const gtypes::Vector3<int>& cgvec3i;
/// @brief Typedef for simpler code.
typedef gtypes::Vector3<float> gvec3f;
/// @brief Typedef for simpler code.
typedef const gtypes::Vector3<float>& cgvec3f;
/// @brief Typedef for simpler code.
typedef gtypes::Vector3<double> gvec3d;
/// @brief Typedef for simpler code.
typedef const gtypes::Vector3<double>& cgvec3d;

/// @brief Temporary compatibility alias.
#define gvec3 gvec3f
/// @brief Temporary compatibility alias.
#define cgvec3 cgvec3f
// TODO - enable this later and remove above emporary compatibility alias
/*
/// @brief Alias for simpler code.
#define gvec3 gtypes::Vector3<T>
/// @brief Alias for simpler code.
#define cgvec3 const gtypes::Vector3<T>&
*/

#endif
