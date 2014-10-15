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
/// Represents a quaternion.

#ifndef GTYPES_QUATERNION_H
#define GTYPES_QUATERNION_H

#include "gtypesExport.h"

namespace gtypes
{
	class Matrix3;
	class Matrix4;
	class Vector3;

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
		Quaternion();
		/// @brief Constructor.
		/// @param[in] x X value.
		/// @param[in] y Y value.
		/// @param[in] z Z value.
		/// @param[in] w W value.
		Quaternion(float x, float y, float z, float w);
		/// @brief Constructor.
		/// @param[in] v Vector3.
		/// @param[in] w W value.
		Quaternion(const Vector3& v, float w);
		/// @brief Destructor.
		~Quaternion();
		/// @brief Sets the values of the Quaternion.
		/// @param[in] x X value.
		/// @param[in] y Y value.
		/// @param[in] z Z value.
		/// @param[in] w W value.
		void set(float x, float y, float z, float w);
		/// @brief Sets the values of the Quaternion.
		/// @param[in] v Vector3.
		/// @param[in] w W value.
		void set(const Vector3& v, float w);
		
		/// @return Calculates the length of the Quaternion.
		float length() const;
		/// @return Calculates the squared length of the Quaternion.
		/// @note Use this if you don't need the actual length as it's faster than length().
		/// @see length()
		float squaredLength() const;
		
		/// @brief Normalizes the current Quaternion.
		void normalize();
		/// @brief Creates a normalized Quaternion from this Quaternion.
		/// @return The normalized Quaternion.
		Quaternion normalized() const;
		/// @brief Inverses the current Quaternion.
		void inverse();
		/// @brief Creates an inversed Quaternion from this Quaternion.
		/// @return The inversed Quaternion.
		Quaternion inversed() const;
		/// @brief Conjugates the current Quaternion.
		void conjugate();
		/// @brief Creates a conjugated Quaternion from this Quaternion.
		/// @return The conjugated Quaternion.
		Quaternion conjugated() const;
		/// @brief Calculates the dot-product between this and another Quaternion.
		/// @param[in] other The other Quaternion.
		/// @return The dot-product.
		float dot(const Quaternion& other) const;

		/// @brief Creates a Matrix3 from this Quaternion
		/// @return The Matrix3.
		Matrix3 mat3() const;
		/// @brief Creates a Matrix4 from this Quaternion
		/// @return The Matrix4.
		Matrix4 mat4() const;
		/// @brief Creates a Matrix4 from this Quaternion
		/// @param[in] position The Vector3 position in the Matrix4.
		/// @return The Matrix4.
		Matrix4 mat4(const Vector3& position) const;
		
		/// @brief Creates an negated Quaternion.
		/// @return Negated Quaternion.
		/// @note Not the same as inversed!
		/// @see inversed()
		Quaternion operator-() const;
		/// @brief Adds two Quaternions.
		/// @param[in] other The other Quaternion.
		/// @return The resulting Quaternion.
		Quaternion operator+(const Quaternion& other) const;
		/// @brief Subtracts two Quaternions.
		/// @param[in] other The other Quaternion.
		/// @return The resulting Quaternion.
		Quaternion operator-(const Quaternion& other) const;
		/// @brief Multiplies two Quaternions.
		/// @param[in] other The other Quaternion.
		/// @return The resulting Quaternion.
		Quaternion operator*(const Quaternion& other) const;
		/// @brief Multiplies Quaternion with a factor.
		/// @param[in] factor The factor.
		/// @return The resulting Quaternion.
		Quaternion operator*(const float factor) const;
		/// @brief Adds another Quaternion to this one.
		/// @param[in] other The other Quaternion.
		/// @return A copy of this Quaternion.
		Quaternion operator+=(const Quaternion& other);
		/// @brief Subtracts another Quaternion to this one.
		/// @param[in] other The other Quaternion.
		/// @return A copy of this Quaternion.
		Quaternion operator-=(const Quaternion& other);
		/// @brief Multiplies this Quaternion with another one.
		/// @param[in] other The other Quaternion.
		/// @return A copy of this Quaternion.
		Quaternion operator*=(const Quaternion& other);
		/// @brief Divides this Quaternion with another one.
		/// @param[in] other The other Quaternion.
		/// @return A copy of this Quaternion.
		Quaternion operator/=(const Quaternion& other);
		/// @brief Multiplies this Quaternion with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Quaternion.
		Quaternion operator*=(const float factor);
		/// @brief Divides this Quaternion with a factor.
		/// @param[in] factor The factor.
		/// @return A copy of this Quaternion.
		Quaternion operator/=(const float factor);
		/// @brief Checks if two Quaternions are equal.
		/// @param[in] other The other Quaternion.
		/// @return True if the two Quaternions are equal.
		/// @note Beware of floating point errors.
		bool operator==(const Quaternion& other) const;
		/// @brief Checks if two Quaternions are not equal.
		/// @param[in] other The other Quaternion.
		/// @return True if the two Quaternions are not equal.
		/// @note Beware of floating point errors.
		bool operator!=(const Quaternion& other) const;

		/// @brief Creates a Quaternion as s Spherical Linear intERPolation between two other Quaternions.
		/// @param[in] a First Quaternion.
		/// @param[in] b Second Quaternion.
		/// @param[in] factor The slerp factor.
		/// @return The slerped Quaternion.
		static Quaternion slerp(const Quaternion& a, const Quaternion& b, float factor);
		/// @brief Creates a Quaternion from a rotation around an axis.
		/// @param[in] ax X coordinate of the axis.
		/// @param[in] ay Y coordinate of the axis.
		/// @param[in] az Z coordinate of the axis.
		/// @param[in] angle The angle.
		/// @return The Quaternion.
		static Quaternion fromAxisAngle(float ax, float ay, float az, float angle);
		/// @brief Creates a Quaternion from a rotation around an axis.
		/// @param[in] axis The Vector3 axis.
		/// @param[in] angle The angle.
		/// @return The Quaternion.
		static Quaternion fromAxisAngle(const Vector3& axis, float angle);
		/// @brief Creates a Quaternion from Euler angles.
		/// @param[in] yaw The "yaw" angle.
		/// @param[in] pitch The "pitch" angle.
		/// @param[in] roll The "roll" angle.
		/// @return The Quaternion.
		static Quaternion fromEulerAngles(float yaw, float pitch, float roll);

	};

}

typedef gtypes::Quaternion gquat;

#endif
