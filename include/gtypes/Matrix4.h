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
/// Represents a 4x4 matrix.

#ifndef GTYPES_MATRIX_4_H
#define GTYPES_MATRIX_4_H

#include "gtypesExport.h"

namespace gtypes
{
	class Matrix3;
	class Rectangle;
	class Vector3;
	class Quaternion;

	/// @brief Represents a 4x4 matrix.
	class gtypesExport Matrix4
	{
	public:
		/// @brief The Matrix data.
		float data[16];

		/// @brief Basic constructor.
		Matrix4();
		/// @brief Constructor.
		/// @param[in] m0 Matrix value 0.
		/// @param[in] m1 Matrix value 1.
		/// @param[in] m2 Matrix value 2.
		/// @param[in] m3 Matrix value 3.
		/// @param[in] m4 Matrix value 4.
		/// @param[in] m5 Matrix value 5.
		/// @param[in] m6 Matrix value 6.
		/// @param[in] m7 Matrix value 7.
		/// @param[in] m8 Matrix value 8.
		/// @param[in] m9 Matrix value 9.
		/// @param[in] m10 Matrix value 10.
		/// @param[in] m11 Matrix value 11.
		/// @param[in] m12 Matrix value 12.
		/// @param[in] m13 Matrix value 13.
		/// @param[in] m14 Matrix value 14.
		/// @param[in] m15 Matrix value 15.
		Matrix4(float m0, float m1, float m2, float m3,
				float m4, float m5, float m6, float m7,
				float m8, float m9, float m10, float m11,
				float m12, float m13, float m14, float m15);
		/// @brief Constructor.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 16 or larger.
		Matrix4(const float m[]);
		/// @brief Constructor.
		/// @param[in] mat3 The Matrix3 to construct this Matrix4 from.
		Matrix4(const Matrix3& mat3);
		/// @brief Constructor from rotation.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] angle Rotation angle.
		Matrix4(float x, float y, float z, float angle);
		/// @brief Constructor from rotation.
		/// @param[in] axis Rotation axis.
		/// @param[in] angle Rotation angle.
		Matrix4(const Vector3& axis, float angle);
		
		/// @brief Sets the Matrix4 values.
		/// @param[in] m0 Matrix value 0.
		/// @param[in] m1 Matrix value 1.
		/// @param[in] m2 Matrix value 2.
		/// @param[in] m3 Matrix value 3.
		/// @param[in] m4 Matrix value 4.
		/// @param[in] m5 Matrix value 5.
		/// @param[in] m6 Matrix value 6.
		/// @param[in] m7 Matrix value 7.
		/// @param[in] m8 Matrix value 8.
		/// @param[in] m9 Matrix value 9.
		/// @param[in] m10 Matrix value 10.
		/// @param[in] m11 Matrix value 11.
		/// @param[in] m12 Matrix value 12.
		/// @param[in] m13 Matrix value 13.
		/// @param[in] m14 Matrix value 14.
		/// @param[in] m15 Matrix value 15.
		void set(float m0, float m1, float m2, float m3,
				 float m4, float m5, float m6, float m7,
				 float m8, float m9, float m10, float m11,
				 float m12, float m13, float m14, float m15);
		/// @brief Sets the Matrix4 values.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 16 or larger.
		void set(const float m[]);
		/// @brief Sets the Matrix4 values.
		/// @param[in] mat3 The Matrix3 to construct this Matrix4 from.
		void set(const Matrix3& mat3);
		/// @brief Sets the Matrix4 values.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] angle Rotation angle.
		void set(float x, float y, float z, float angle);
		/// @brief Sets the Matrix4 values.
		/// @param[in] axis Rotation axis.
		/// @param[in] angle Rotation angle.
		void set(const Vector3& axis, float angle);
		/// @brief Sets the Matrix4 values.
		/// @param[in] other The other Matrix4.
		void set(const Matrix4& other);
		
		/// @brief Sets all values of the Matrix4 to zero.
		void setZero();
		/// @brief Sets the Matrix4 to identity.
		void setIdentity();
		/// @brief Gets rotation as Matrix4.
		/// @return Rotation as Matrix4.
		Matrix4 getRotation() const;

		/// @brief Sets the translation of the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		void setTranslation(float x, float y, float z);
		/// @brief Sets the translation of the Matrix4.
		/// @param[in] vector The Vector3 of the translation.
		void setTranslation(const Vector3& vector);
		/// @brief Sets the scale of the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @brief Sets the scale of the Matrix4.
		void setScale(float x, float y, float z);
		/// @param[in] factor The scale factor.
		void setScale(float factor);
		/// @brief Sets the scale of the Matrix4.
		/// @param[in] vector The Vector3 of the scale.
		void setScale(const Vector3& vector);
		/// @brief Sets the rotation of the Matrix4.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		void setRotation(float x, float y, float z, float angle);
		/// @brief Sets the rotation of the Matrix4.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		void setRotation(const Vector3& axis, float angle);
		/// @brief Sets the X rotation of the Matrix4.
		/// @param[in] angle The rotation angle.
		void setRotationX(float angle);
		/// @brief Sets the Y rotation of the Matrix4.
		/// @param[in] angle The rotation angle.
		void setRotationY(float angle);
		/// @brief Sets the Z rotation of the Matrix4.
		/// @param[in] angle The rotation angle.
		void setRotationZ(float angle);
		/// @brief Sets the reflection of the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] w W coordinate.
		void setReflection(float x, float y, float z, float w);
		/// @brief Sets the reflection of the Matrix4.
		/// @param[in] quaternion The Quaternion.
		void setReflection(const Quaternion& quaternion);

		/// @brief Calculates the determinant of the Matrix4.
		/// @return The determinant of the Matrix4.
		float det() const;
		/// @brief Translates the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		void translate(float x, float y, float z);
		/// @brief Translates the Matrix4.
		/// @param[in] vector The Vector3 to use for the translation.
		void translate(const Vector3& vector);
		void scale(float x, float y, float z);
		void scale(float factor);
		void scale(const Vector3& vector);
		void rotate(float x, float y, float z, float angle);
		void rotate(const Vector3& axis, float angle);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		void reflect(float x, float y, float z, float w);
		void reflect(const Quaternion& quaternion);

		void lookAt(const float* eye, const float* target, const float* up);
		void lookAt(const Vector3& eye, const Vector3& target, const Vector3& up);
		void perspective(float fov, float aspect, float near, float far);
		void ortho(const Rectangle& rect);

		void transpose();
		Matrix4 transposed() const;
		void inverse();
		Matrix4 inversed() const;
		void inverseRotation();
		Matrix4 inversedRotation() const;
		
		Matrix4 operator*(const Matrix4& other) const;
		Matrix4 operator*(float factor) const;
		Vector3 operator*(const Vector3& vector) const;
		Quaternion operator*(const Quaternion& quaternion) const;
		Matrix4 operator+(const Matrix4& other) const;
		Matrix4 operator-(const Matrix4& other) const;

		Matrix4 operator*=(float factor);
		Matrix4 operator*=(const Matrix4& other);
		Matrix4 operator+=(const Matrix4& other);
		Matrix4 operator-=(const Matrix4& other);

		inline operator float*() { return this->data; }
		inline operator const float*() const { return this->data; }

		inline float& operator[](int i) { return this->data[i]; }
		inline const float operator[](int i) const { return this->data[i]; }

	};
}

typedef gtypes::Matrix4 gmat4;

#endif
