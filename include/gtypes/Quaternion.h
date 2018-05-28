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
/// Represents a quaternion.

#ifndef GTYPES_QUATERNION_H
#define GTYPES_QUATERNION_H

#include "gtypesExport.h"
#include "gtypesUtil.h"
#include "Matrix3.h"
#include "Vector3.h"

namespace gtypes
{
	class Matrix4;

	/// @brief Represents a quaternion.
	class gtypesExport Quaternion
	{
	public:
		/// @brief X value.
		float x;
		/// @brief Y value.
		float y;
		/// @brief Z value.
		float z;
		/// @brief W value.
		float w;
		
		/// @brief Basic constructor.
		inline Quaternion() : x(1.0f), y(1.0f), z(1.0f), w(1.0f)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X value.
		/// @param[in] y Y value.
		/// @param[in] z Z value.
		/// @param[in] w W value.
		inline Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
		{
		}
		/// @brief Constructor.
		/// @param[in] v Vector3.
		/// @param[in] w W value.
		inline Quaternion(const Vector3<float>& v, float w) : x(v.x), y(v.y), z(v.z), w(w)
		{
		}
		/// @brief Sets the values of the Quaternion.
		/// @param[in] x X value.
		/// @param[in] y Y value.
		/// @param[in] z Z value.
		/// @param[in] w W value.
		inline void set(float x, float y, float z, float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}
		/// @brief Sets the values of the Quaternion.
		/// @param[in] v Vector3.
		/// @param[in] w W value.
		inline void set(const Vector3<float>& v, float w)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			this->w = w;
		}

		/// @return Calculates the length of the Quaternion.
		inline float length() const
		{
			return (float)sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
		}
		/// @return Calculates the squared length of the Quaternion.
		/// @note Use this if you don't need the actual length as it's faster than length().
		/// @see length()
		inline float squaredLength() const
		{
			return (this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
		}
		
		/// @brief Normalizes the current Quaternion.
		inline void normalize()
		{
			float length = this->length();
			if (length != 0.0f)
			{
				length = 1.0f / length;
				this->x *= length;
				this->y *= length;
				this->z *= length;
				this->w *= length;
			}
		}
		/// @brief Creates a normalized Quaternion from this Quaternion.
		/// @return The normalized Quaternion.
		inline Quaternion normalized() const
		{
			Quaternion result(*this);
			result.normalize();
			return result;
		}
		/// @brief Inverses the current Quaternion.
		inline void inverse()
		{
			float squaredLength = 1.0f / this->squaredLength();
			this->set(-this->x * squaredLength, -this->y * squaredLength, -this->z * squaredLength, this->w * squaredLength);
		}
		/// @brief Creates an inversed Quaternion from this Quaternion.
		/// @return The inversed Quaternion.
		inline Quaternion inversed() const
		{
			Quaternion result(*this);
			result.inverse();
			return result;
		}
		/// @brief Conjugates the current Quaternion.
		inline void conjugate()
		{
			this->x = -this->x;
			this->y = -this->y;
			this->z = -this->z;
		}
		/// @brief Creates a conjugated Quaternion from this Quaternion.
		/// @return The conjugated Quaternion.
		inline Quaternion conjugated() const
		{
			Quaternion result(*this);
			result.conjugate();
			return result;
		}
		/// @brief Calculates the dot-product between this and another Quaternion.
		/// @param[in] other The other Quaternion.
		/// @return The dot-product.
		inline float dot(const Quaternion& other) const
		{
			return (this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w);
		}

		/// @brief Creates a Matrix3 from this Quaternion
		/// @return The Matrix3.
		inline Matrix3 mat3() const
		{
			float xx = this->x * this->x;
			float yy = this->y * this->y;
			float zz = this->z * this->z;
			float xy = this->x * this->y;
			float xz = this->x * this->z;
			float yz = this->y * this->z;
			float wx = this->w * this->x;
			float wy = this->w * this->y;
			float wz = this->w * this->z;
			return Matrix3(1.0f - 2.0f * (yy + zz),	2.0f * (xy - wz),			2.0f * (xz + wy),
						   2.0f * (xy + wz),		1.0f - 2.0f * (xx + zz),	2.0f * (yz - wx),
						   2.0f * (xz - wy),		2.0f * (yz + wx),			1.0f - 2.0f * (xx + yy));
		}
		/// @brief Creates a Matrix4 from this Quaternion
		/// @return The Matrix4.
		Matrix4 mat4() const;
		/// @brief Creates a Matrix4 from this Quaternion
		/// @param[in] position The Vector3 position in the Matrix4.
		/// @return The Matrix4.
		Matrix4 mat4(const Vector3<float>& position) const;
		
		/// @brief Creates an negated Quaternion.
		/// @return Negated Quaternion.
		/// @note Not the same as inversed!
		/// @see inversed()
		inline Quaternion operator-() const
		{
			return Quaternion(-this->x, -this->y, -this->z, -this->w);
		}
		/// @brief Adds two Quaternions.
		/// @param[in] other The other Quaternion.
		/// @return The resulting Quaternion.
		inline Quaternion operator+(const Quaternion& other) const
		{
			return Quaternion(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
		}
		/// @brief Subtracts two Quaternions.
		/// @param[in] other The other Quaternion.
		/// @return The resulting Quaternion.
		inline Quaternion operator-(const Quaternion& other) const
		{
			return Quaternion(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
		}
		/// @brief Multiplies two Quaternions.
		/// @param[in] other The other Quaternion.
		/// @return The resulting Quaternion.
		inline Quaternion operator*(const Quaternion& other) const
		{
			return Quaternion(this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
				this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x,
				this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w,
				this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z);
		}
		/// @brief Multiplies Quaternion with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Quaternion.
		inline Quaternion operator*(float factor) const
		{
			return Quaternion(this->x * factor, this->y * factor, this->z * factor, this->w * factor);
		}
		/// @brief Sets this Quaternion to another one.
		/// @param[in] other The other Quaternion.
		/// @return This Quaternion.
		inline Quaternion operator=(const Quaternion& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
			return (*this);
		}
		/// @brief Adds another Quaternion to this one.
		/// @param[in] other The other Quaternion.
		/// @return A copy of this Quaternion.
		inline Quaternion operator+=(const Quaternion& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
			return (*this);
		}
		/// @brief Subtracts another Quaternion to this one.
		/// @param[in] other The other Quaternion.
		/// @return A copy of this Quaternion.
		inline Quaternion operator-=(const Quaternion& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
			return (*this);
		}
		/// @brief Multiplies this Quaternion with another one.
		/// @param[in] other The other Quaternion.
		/// @return A copy of this Quaternion.
		inline Quaternion operator*=(const Quaternion& other)
		{
			float x = this->x;
			float y = this->y;
			float z = this->z;
			float w = this->w;
			this->x = w * other.x + x * other.w + y * other.z - z * other.y;
			this->y = w * other.y - x * other.z + y * other.w + z * other.x;
			this->z = w * other.z + x * other.y - y * other.x + z * other.w;
			this->w = w * other.w - x * other.x - y * other.y - z * other.z;
			return (*this);
		}
		/// @brief Multiplies this Quaternion with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Quaternion.
		inline Quaternion operator*=(float factor)
		{
			this->x *= factor;
			this->y *= factor;
			this->z *= factor;
			this->w *= factor;
			return (*this);
		}
		/// @brief Divides this Quaternion with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Quaternion.
		inline Quaternion operator/=(float factor)
		{
			this->x /= factor;
			this->y /= factor;
			this->z /= factor;
			this->w /= factor;
			return (*this);
		}
		/// @brief Checks if two Quaternions are equal.
		/// @param[in] other The other Quaternion.
		/// @return True if the two Quaternions are equal.
		/// @note Beware of floating point errors.
		inline bool operator==(const Quaternion& other) const
		{
			return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
		}
		/// @brief Checks if two Quaternions are not equal.
		/// @param[in] other The other Quaternion.
		/// @return True if the two Quaternions are not equal.
		/// @note Beware of floating point errors.
		inline bool operator!=(const Quaternion& other) const
		{
			return !(*this == other);
		}

		/// @brief Creates a Quaternion as s Spherical Linear intERPolation between two other Quaternions.
		/// @param[in] a First Quaternion.
		/// @param[in] b Second Quaternion.
		/// @param[in] factor The slerp factor.
		/// @return The slerped Quaternion.
		inline static Quaternion slerp(const Quaternion& a, const Quaternion& b, float factor)
		{
			float theta = (float)acos(a.dot(b));
			float sinTheta = (float)sin(theta);
			float w1 = 1.0f - factor;
			float w2 = factor;
			if (sinTheta > G_E_TOLERANCE)
			{
				w1 = (float)(sin(1.0f - factor) * theta) / sinTheta;
				w2 = (float)(sin(factor) * theta) / sinTheta;
			}
			return Quaternion(a * w1 + b * w2);
		}
		/// @brief Creates a Quaternion from a rotation around an axis.
		/// @param[in] ax X coordinate of the axis.
		/// @param[in] ay Y coordinate of the axis.
		/// @param[in] az Z coordinate of the axis.
		/// @param[in] angle The angle.
		/// @return The Quaternion.
		inline static Quaternion fromAxisAngle(float ax, float ay, float az, float angle)
		{
			return Quaternion::fromAxisAngle(Vector3<float>(ax, ay, az), angle);
		}
		/// @brief Creates a Quaternion from a rotation around an axis.
		/// @param[in] axis The Vector3 axis.
		/// @param[in] angle The angle.
		/// @return The Quaternion.
		inline static Quaternion fromAxisAngle(const Vector3<float>& axis, float angle)
		{
			float theta = (float)DEG_TO_RAD(angle) * 0.5f;
			return Quaternion(axis.normalized() * (float)sin(theta), (float)cos(theta));
		}
		/// @brief Creates a Quaternion from Euler angles.
		/// @param[in] yaw The "yaw" angle.
		/// @param[in] pitch The "pitch" angle.
		/// @param[in] roll The "roll" angle.
		/// @return The Quaternion.
		inline static Quaternion fromEulerAngles(float yaw, float pitch, float roll)
		{
			Quaternion y(0.0f, -(float)sin(yaw * 0.5f), 0.0f, (float)cos(yaw * 0.5f));
			Quaternion p(-(float)sin(pitch * 0.5f), 0.0f, 0.0f, (float)cos(pitch * 0.5f));
			Quaternion r(0.0f, 0.0f, -(float)sin(roll * 0.5), (float)cos(roll * 0.5f));
			return (y * p * r);
		}

	};

}

/// @brief Alias for simpler code.
typedef gtypes::Quaternion gquat;
/// @brief Alias for simpler code.
typedef const gtypes::Quaternion& cgquat;

#endif
