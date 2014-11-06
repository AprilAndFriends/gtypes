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
		void setScale(float x, float y, float z);
		/// @brief Sets the scale of the Matrix4.
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

		/// @brief Creates an ortho-projection from a Rectangle.
		/// @param[in] rect The Rectangle.
		void setOrthoProjection(const Rectangle& rect);
		/// @brief Creates an ortho-projection from a Rectangle.
		/// @param[in] rect The Rectangle.
		/// @param[in] near The near plane.
		/// @param[in] near The far plane.
		void setOrthoProjection(const Rectangle& rect, float near, float far);
		/// @brief Sets the perspective in a Matrix4.
		/// @param[in] fov The field-of-view.
		/// @param[in] aspect The aspect ratio of the view.
		/// @param[in] near The near plane.
		/// @param[in] near The far plane.
		void setPerspective(float fov, float aspect, float near, float far);

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
		/// @brief Scales the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		void scale(float x, float y, float z);
		/// @brief Scales the Matrix4.
		/// @param[in] factor Scaling factor.
		void scale(float factor);
		/// @brief Scales the Matrix4.
		/// @param[in] vector The Vector3 to use for the scaling.
		void scale(const Vector3& vector);
		/// @brief Rotates the Matrix4.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		void rotate(float x, float y, float z, float angle);
		/// @brief Rotates the Matrix4.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		void rotate(const Vector3& axis, float angle);
		/// @brief Rotates the X of Matrix4.
		/// @param[in] angle The rotation angle.
		void rotateX(float angle);
		/// @brief Rotates the Y of Matrix4.
		/// @param[in] angle The rotation angle.
		void rotateY(float angle);
		/// @brief Rotates the Z of Matrix4.
		/// @param[in] angle The rotation angle.
		void rotateZ(float angle);
		/// @brief Reflects the Matrix4 around a quaternion.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] w W coordinate.
		void reflect(float x, float y, float z, float w);
		/// @brief Reflects the Matrix4 around a quaternion.
		/// @param[in] quaternion The Quaternion.
		void reflect(const Quaternion& quaternion);

		/// @brief Changes the Matrix4 to reflect a look-at defined Vector3s defining the look eye's position, the target's position and the up-vector.
		/// @param[in] eye The eye position.
		/// @param[in] target The target position.
		/// @param[in] up The up-vector.
		void lookAt(const Vector3& eye, const Vector3& target, const Vector3& up);

		/// @brief Transposes the Matrix4.
		void transpose();
		/// @brief Creates a transposed Matrix4 from this one.
		/// @return The transposed Matrix4 from this one.
		Matrix4 transposed() const;
		/// @brief Inverses the Matrix4.
		/// @note This will NOT inverse the rotation!
		void inverse();
		/// @brief Creates an inversed Matrix4 from this one.
		/// @return The inversed Matrix4 from this one.
		/// @note This will NOT inverse the rotation!
		Matrix4 inversed() const;
		/// @brief Inverses the rotation of the Matrix4.
		void inverseRotation();
		/// @brief Creates a rotation-inversed Matrix4 from this one.
		/// @return The rotation-inversed Matrix4 from this one.
		Matrix4 inversedRotation() const;
		
		/// @brief Multiplies two Matrix4s.
		/// @param[in] other The other Matrix4.
		/// @return The resulting Matrix4.
		Matrix4 operator*(const Matrix4& other) const;
		/// @brief Multiplies each value of a Matrix4 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return The resulting Matrix4.
		Matrix4 operator*(float factor) const;
		/// @brief Multiplies a Matrix4 with a Vector3.
		/// @param[in] vector The Vector3.
		/// @return The resulting Vector3.
		Vector3 operator*(const Vector3& vector) const;
		/// @brief Multiplies a Matrix4 with a Quaternion.
		/// @param[in] quaternion The Quaternion.
		/// @return The resulting Quaternion.
		Quaternion operator*(const Quaternion& quaternion) const;
		/// @brief Adds two Matrix4s.
		/// @param[in] other The other Matrix4.
		/// @return The resulting Matrix4.
		Matrix4 operator+(const Matrix4& other) const;
		/// @brief Subtracts two Matrix4s.
		/// @param[in] other The other Matrix4.
		/// @return The resulting Matrix4.
		Matrix4 operator-(const Matrix4& other) const;

		/// @brief Multiplies this Matrix4 with another one.
		/// @param[in] other The other Matrix4.
		/// @return This modified Matrix4.
		Matrix4 operator*=(const Matrix4& other);
		/// @brief Multiplies each value of this Matrix4 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return This modified Matrix4.
		Matrix4 operator*=(float factor);
		/// @brief Sums up this Matrix4 with another one.
		/// @param[in] other The other Matrix4.
		/// @return This modified Matrix4.
		Matrix4 operator+=(const Matrix4& other);
		/// @brief Subtracts a Matrix4 from this one.
		/// @param[in] other The other Matrix4.
		/// @return This modified Matrix4.
		Matrix4 operator-=(const Matrix4& other);

		/// @brief Casts this Matrix4 into a raw float array.
		/// @return The raw float data of the Matrix4.
		/// @note As this is a 4x4 matrix, the size of the array is always 16.
		inline operator float*() { return this->data; }
		/// @brief Casts this Matrix4 into a raw float array.
		/// @return The raw float data of the Matrix4.
		/// @note As this is a 4x4 matrix, the size of the array is always 16.
		inline operator const float*() const { return this->data; }

		/// @brief Accesses a value of the Matrix4.
		/// @param[in] index The value's index.
		/// @return The Matrix4's value.
		inline float& operator[](int index) { return this->data[index]; }
		/// @brief Accesses a value of the Matrix4.
		/// @param[in] index The value's index.
		/// @return The Matrix4's value.
		inline const float operator[](int index) const { return this->data[index]; }

	};
}

typedef gtypes::Matrix4 gmat4;

#endif
