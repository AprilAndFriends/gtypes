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
/// Represents a 3x3 matrix.

#ifndef GTYPES_MATRIX_3_H
#define GTYPES_MATRIX_3_H

#include "gtypesExport.h"

namespace gtypes
{
	class Matrix4;
	class Vector2;
	class Vector3;

	/// @brief Represents a 3x3 matrix.
	class gtypesExport Matrix3
	{
	public:
		/// @brief The Matrix data.
		float data[9];
	
		/// @brief Basic constructor.
		Matrix3();
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
		Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
		/// @brief Constructor.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 9 or larger.
		Matrix3(const float m[]);
		/// @brief Constructor.
		/// @param[in] mat4 The Matrix4 to construct this Matrix3 from.
		Matrix3(const Matrix4& mat4);
		
		/// @brief Sets the Matrix3 values.
		/// @param[in] m0 Matrix value 0.
		/// @param[in] m1 Matrix value 1.
		/// @param[in] m2 Matrix value 2.
		/// @param[in] m3 Matrix value 3.
		/// @param[in] m4 Matrix value 4.
		/// @param[in] m5 Matrix value 5.
		/// @param[in] m6 Matrix value 6.
		/// @param[in] m7 Matrix value 7.
		/// @param[in] m8 Matrix value 8.
		void set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
		/// @brief Sets the Matrix3 values.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 16 or larger.
		void set(const float m[]);
		/// @brief Sets the Matrix3 values.
		/// @param[in] mat4 The Matrix4 to construct this Matrix3 from.
		void set(const Matrix4& mat4);
		/// @brief Sets the Matrix3 values.
		/// @param[in] other The other Matrix3.
		void set(const Matrix3& other);

		/// @brief Sets all values of the Matrix3 to zero.
		void setZero();
		/// @brief Sets the Matrix3 to identity.
		void setIdentity();

		/// @brief Sets the translation of the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		void setTranslation(float x, float y);
		/// @brief Sets the translation of the Matrix3.
		/// @param[in] vector The Vector2 of the translation.
		void setTranslation(const Vector2& vector);
		/// @brief Sets the scale of the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		void setScale(float x, float y);
		/// @brief Sets the scale of the Matrix3.
		/// @param[in] factor The scale factor.
		void setScale(float factor);
		/// @brief Sets the scale of the Matrix3.
		/// @param[in] vector The Vector3 of the scale.
		void setScale(const Vector2& vector);
		/// @brief Sets the 3D scale of the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		void setScale3D(float x, float y, float z);
		/// @brief Sets the 3D scale of the Matrix3.
		/// @param[in] factor The scale factor.
		void setScale3D(float factor);
		/// @brief Sets the 3D scale of the Matrix3.
		/// @param[in] vector The Vector3 of the scale.
		void setScale3D(const Vector3& vector);
		/// @brief Sets the rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		void setRotation(float angle);
		/// @brief Sets the 3D rotation of the Matrix3.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		void setRotation3D(float x, float y, float z, float angle);
		/// @brief Sets the 3D rotation of the Matrix3.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		void setRotation3D(const Vector3& axis, float angle);
		/// @brief Sets the 3D X rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		void setRotation3DX(float angle);
		/// @brief Sets the 3D Y rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		void setRotation3DY(float angle);
		/// @brief Sets the 3D Z rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		void setRotation3DZ(float angle);

		/// @brief Calculates the determinant of the Matrix3.
		/// @return The determinant of the Matrix3.
		float det() const;
		/// @brief Translates the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		void translate(float x, float y);
		/// @brief Translates the Matrix3.
		/// @param[in] vector The Vector2 to use for the translation.
		void translate(const Vector2& vector);
		/// @brief Scales the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		void scale(float x, float y);
		/// @brief Scales the Matrix3.
		/// @param[in] factor Scaling factor.
		void scale(float factor);
		/// @brief Scales the Matrix3.
		/// @param[in] vector The Vector2 to use for the scaling.
		void scale(const Vector2& vector);
		/// @brief 3D-Scales the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		void scale3D(float x, float y, float z);
		/// @brief 3D-Scales the Matrix3.
		/// @param[in] factor Scaling factor.
		void scale3D(float factor);
		/// @brief 3D-Scales the Matrix3.
		/// @param[in] vector The Vector3 to use for the scaling.
		void scale3D(const Vector3& vector);
		/// @brief Rotates the Matrix3.
		/// @param[in] angle The rotation angle.
		void rotate(float angle);
		/// @brief 3D-rotates the Matrix3.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		void rotate3D(float x, float y, float z, float angle);
		/// @brief 3D-rotates the Matrix3.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		void rotate3D(const Vector3& axis, float angle);
		/// @brief 3D-rotates the X of Matrix3.
		/// @param[in] angle The rotation angle.
		void rotate3DX(float angle);
		/// @brief 3D-rotates the Y of Matrix3.
		/// @param[in] angle The rotation angle.
		void rotate3DY(float angle);
		/// @brief 3D-rotates the Z of Matrix3.
		/// @param[in] angle The rotation angle.
		void rotate3DZ(float angle);

		/// @brief Transposes the Matrix3.
		void transpose();
		/// @brief Creates a transposed Matrix3 from this one.
		/// @return The transposed Matrix3 from this one.
		Matrix3 transposed() const;
		/// @brief Inverses the Matrix3.
		void inverse();
		/// @brief Creates an inversed Matrix3 from this one.
		/// @return The inversed Matrix3 from this one.
		Matrix3 inversed() const;
		/// @brief Inverse-rotates the Matrix3.
		void inverseRotation();
		/// @brief Creates a rotation-inversed Matrix3 from this one.
		/// @return The rotation-inversed Matrix3 from this one.
		Matrix3 inversedRotation() const;
		/// @brief Inverse-rotates the Matrix3.
		void inverseRotation3D();
		/// @brief Creates a rotation-inversed Matrix3 from this one.
		/// @return The rotation-inversed Matrix3 from this one.
		Matrix3 inversedRotation3D() const;
		/// @brief Ortho-normalizes the Matrix.
		/// @param[in] angle The rotation angle.
		void orthoNormalize();
		/// @brief Creates an ortho-normalized the Matrix.
		/// @return The ortho-normalized Matrix3 from this one.
		Matrix3 orthoNormalized() const;

		/// @brief Multiplies two Matrix3s.
		/// @param[in] other The other Matrix3.
		/// @return The resulting Matrix3.
		Matrix3 operator*(const Matrix3& other) const;
		/// @brief Multiplies each value of a Matrix3 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return The resulting Matrix3.
		Matrix3 operator*(float factor) const;
		/// @brief Multiplies a Matrix3 with a Vector3.
		/// @param[in] vector The Vector3.
		/// @return The resulting Vector3.
		Vector3 operator*(const Vector3& vector) const;
		/// @brief Adds two Matrix3s.
		/// @param[in] other The other Matrix3.
		/// @return The resulting Matrix3.
		Matrix3 operator+(const Matrix3& other) const;
		/// @brief Subtracts two Matrix3s.
		/// @param[in] other The other Matrix3.
		/// @return The resulting Matrix3.
		Matrix3 operator-(const Matrix3& other) const;

		/// @brief Multiplies this Matrix3 with another one.
		/// @param[in] other The other Matrix3.
		/// @return This modified Matrix3.
		Matrix3 operator*=(const Matrix3& other);
		/// @brief Multiplies each value of this Matrix3 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return This modified Matrix3.
		Matrix3 operator*=(float factor);
		/// @brief Sums up this Matrix3 with another one.
		/// @param[in] other The other Matrix3.
		/// @return This modified Matrix3.
		Matrix3 operator+=(const Matrix3& other);
		/// @brief Subtracts a Matrix3 from this one.
		/// @param[in] other The other Matrix3.
		/// @return This modified Matrix3.
		Matrix3 operator-=(const Matrix3& other);

		/// @brief Casts this Matrix3 into a raw float array.
		/// @return The raw float data of the Matrix3.
		/// @note As this is a 3x3 matrix, the size of the array is always 9.
		inline operator float*() { return this->data; }
		/// @brief Casts this Matrix3 into a raw float array.
		/// @return The raw float data of the Matrix3.
		/// @note As this is a 3x3 matrix, the size of the array is always 9.
		inline operator const float*() const { return this->data; }

		/// @brief Accesses a value of the Matrix3.
		/// @param[in] index The value's index.
		/// @return The Matrix3's value.
		inline float& operator[](int index) { return this->data[index]; }
		/// @brief Accesses a value of the Matrix3.
		/// @param[in] index The value's index.
		/// @return The Matrix3's value.
		inline const float operator[](int index) const { return this->data[index]; }

	};
}

typedef gtypes::Matrix3 gmat3;

#endif
