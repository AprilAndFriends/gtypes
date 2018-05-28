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
/// Represents a 3x3 matrix.

#ifndef GTYPES_MATRIX_3_H
#define GTYPES_MATRIX_3_H

#include <math.h>
#include <string.h>

#include "gtypesExport.h"
#include "gtypesUtil.h"
#include "Vector2.h"
#include "Vector3.h"

namespace gtypes
{
	class Matrix4;

	/// @brief Represents a 3x3 matrix.
	class gtypesExport Matrix3
	{
	public:
		/// @brief The Matrix data.
		float data[9];
	
		/// @brief Basic constructor.
		inline Matrix3()
		{
			this->setIdentity();
		}
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
		inline Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
		{
			this->set(m0, m1, m2, m3, m4, m5, m6, m7, m8);
		}
		/// @brief Constructor.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 9 or larger.
		inline Matrix3(const float m[])
		{
			this->set(m);
		}
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
		inline void set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
		{
			this->data[0] = m0;	this->data[1] = m1;	this->data[2] = m2;
			this->data[3] = m3;	this->data[4] = m4;	this->data[5] = m5;
			this->data[6] = m6;	this->data[7] = m7;	this->data[8] = m8;
		}
		/// @brief Sets the Matrix3 values.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 9 or larger.
		inline void set(const float m[])
		{
			memcpy(this->data, m, sizeof(this->data));
		}
		/// @brief Sets the Matrix3 values.
		/// @param[in] mat4 The Matrix4 to construct this Matrix3 from.
		void set(const Matrix4& mat4);
		/// @brief Sets the Matrix3 values.
		/// @param[in] other The other Matrix3.
		inline void set(const Matrix3& other)
		{
			memcpy(this->data, other.data, sizeof(this->data));
		}

		/// @brief Sets all values of the Matrix3 to zero.
		inline void setZero()
		{
			memset(this->data, 0, sizeof(this->data));
		}
		/// @brief Sets the Matrix3 to identity.
		inline void setIdentity()
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[4] = this->data[8] = 1.0f;
		}

		/// @brief Sets the translation of the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline void setTranslation(float x, float y)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[4] = this->data[8] = 1.0f;
			this->data[6] = x;
			this->data[7] = y;
		}
		/// @brief Sets the translation of the Matrix3.
		/// @param[in] vector The Vector2 of the translation.
		inline void setTranslation(const Vector2& vector)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[4] = this->data[8] = 1.0f;
			this->data[6] = vector.x;
			this->data[7] = vector.y;
		}
		/// @brief Sets the scale of the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline void setScale(float x, float y)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = x;
			this->data[4] = y;
			this->data[8] = 1.0f;
		}
		/// @brief Sets the scale of the Matrix3.
		/// @param[in] factor The scale factor.
		inline void setScale(float factor)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[4] = factor;
			this->data[8] = 1.0f;
		}
		/// @brief Sets the scale of the Matrix3.
		/// @param[in] vector The Vector3 of the scale.
		inline void setScale(const Vector2& vector)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = vector.x;
			this->data[4] = vector.y;
			this->data[8] = 1.0f;
		}
		/// @brief Sets the 3D scale of the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void setScale3D(float x, float y, float z)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = x;
			this->data[4] = y;
			this->data[8] = z;
		}
		/// @brief Sets the 3D scale of the Matrix3.
		/// @param[in] factor The scale factor.
		inline void setScale3D(float factor)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[4] = this->data[8] = factor;
		}
		/// @brief Sets the 3D scale of the Matrix3.
		/// @param[in] vector The Vector3 of the scale.
		inline void setScale3D(const Vector3& vector)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = vector.x;
			this->data[4] = vector.y;
			this->data[8] = vector.z;
		}
		/// @brief Sets the rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		inline void setRotation(float angle)
		{
			memset(this->data, 0, sizeof(this->data));
			double rad = DEG_TO_RAD(angle);
			float c = (float)cos(rad);
			float s = (float)sin(rad);
			this->data[0] = this->data[4] = c;
			this->data[1] = -s;
			this->data[3] = s;
			this->data[8] = 1.0f;
		}
		/// @brief Sets the 3D rotation of the Matrix3.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		inline void setRotation3D(float x, float y, float z, float angle)
		{
			this->setRotation3D(Vector3(x, y, z), angle);
		}
		/// @brief Sets the 3D rotation of the Matrix3.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		inline void setRotation3D(const Vector3& axis, float angle)
		{
			double rad = DEG_TO_RAD(angle);
			float c = (float)cos(rad);
			float s = (float)sin(rad);
			Vector3 v = axis.normalized();
			float c1 = 1.0f - c;
			float xyc1 = v.x * v.y * c1;
			float yzc1 = v.y * v.z * c1;
			float zxc1 = v.z * v.x * c1;
			float xs = v.x * s;
			float ys = v.y * s;
			float zs = v.z * s;
			this->data[0] = v.x * v.x * c1 + c;	this->data[1] = xyc1 + zs;			this->data[2] = zxc1 - ys;
			this->data[3] = xyc1 - zs;			this->data[4] = v.y * v.y * c1 + c;	this->data[5] = yzc1 + xs;
			this->data[6] = zxc1 + ys;			this->data[7] = yzc1 - xs;			this->data[8] = v.z * v.z * c1 + c;
		}
		/// @brief Sets the 3D X rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		inline void setRotation3DX(float angle)
		{
			memset(this->data, 0, sizeof(this->data));
			double rad = DEG_TO_RAD(angle);
			this->data[0] = 1.0f;
			this->data[4] = this->data[8] = (float)cos(rad);
			this->data[5] = (float)sin(rad);
			this->data[7] = -this->data[5];
		}
		/// @brief Sets the 3D Y rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		inline void setRotation3DY(float angle)
		{
			memset(this->data, 0, sizeof(this->data));
			double rad = DEG_TO_RAD(angle);
			this->data[0] = this->data[8] = (float)cos(rad);
			this->data[6] = (float)sin(rad);
			this->data[4] = 1.0f;
			this->data[2] = -this->data[6];
		}
		/// @brief Sets the 3D Z rotation of the Matrix3.
		/// @param[in] angle The rotation angle.
		inline void setRotation3DZ(float angle)
		{
			this->setRotation(angle); // the Z-axis is the default rotation axis
		}

		/// @brief Calculates the determinant of the Matrix3.
		/// @return The determinant of the Matrix3.
		inline float determinant() const
		{
			return (this->data[0] * this->data[4] * this->data[8] +
				this->data[3] * this->data[7] * this->data[2] +
				this->data[6] * this->data[1] * this->data[5] -
				this->data[6] * this->data[4] * this->data[2] -
				this->data[3] * this->data[1] * this->data[8] -
				this->data[0] * this->data[7] * this->data[5]);
		}
		/// @brief Translates the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline void translate(float x, float y)
		{
			Matrix3 mat;
			mat.setTranslation(x, y);
			this->operator*=(mat);
		}
		/// @brief Translates the Matrix3.
		/// @param[in] vector The Vector2 to use for the translation.
		inline void translate(const Vector2& vector)
		{
			Matrix3 mat;
			mat.setTranslation(vector);
			this->operator*=(mat);
		}
		/// @brief Scales the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline void scale(float x, float y)
		{
			Matrix3 mat;
			mat.setScale(x, y);
			this->operator*=(mat);
		}
		/// @brief Scales the Matrix3.
		/// @param[in] factor Scaling factor.
		inline void scale(float factor)
		{
			Matrix3 mat;
			mat.setScale(factor);
			this->operator*=(mat);
		}
		/// @brief Scales the Matrix3.
		/// @param[in] vector The Vector2 to use for the scaling.
		inline void scale(const Vector2& vector)
		{
			Matrix3 mat;
			mat.setScale(vector);
			this->operator*=(mat);
		}
		/// @brief 3D-Scales the Matrix3.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void scale3D(float x, float y, float z)
		{
			Matrix3 mat;
			mat.setScale3D(x, y, z);
			this->operator*=(mat);
		}
		/// @brief 3D-Scales the Matrix3.
		/// @param[in] factor Scaling factor.
		inline void scale3D(float factor)
		{
			Matrix3 mat;
			mat.setScale3D(factor);
			this->operator*=(mat);
		}
		/// @brief 3D-Scales the Matrix3.
		/// @param[in] vector The Vector3 to use for the scaling.
		inline void scale3D(const Vector3& vector)
		{
			Matrix3 mat;
			mat.setScale3D(vector);
			this->operator*=(mat);
		}
		/// @brief Rotates the Matrix3.
		/// @param[in] angle The rotation angle.
		inline void rotate(float angle)
		{
			Matrix3 mat;
			mat.setRotation(angle);
			this->operator*=(mat);
		}
		/// @brief 3D-rotates the Matrix3.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		inline void rotate3D(float x, float y, float z, float angle)
		{
			Matrix3 mat;
			mat.setRotation3D(x, y, z, angle);
			this->operator*=(mat);
		}
		/// @brief 3D-rotates the Matrix3.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		inline void rotate3D(const Vector3 &axis, float angle)
		{
			Matrix3 mat;
			mat.setRotation3D(axis, angle);
			this->operator*=(mat);
		}
		/// @brief 3D-rotates the X of Matrix3.
		/// @param[in] angle The rotation angle.
		inline void rotate3DX(float angle)
		{
			Matrix3 mat;
			mat.setRotation3DX(angle);
			this->operator*=(mat);
		}
		/// @brief 3D-rotates the Y of Matrix3.
		/// @param[in] angle The rotation angle.
		inline void rotate3DY(float angle)
		{
			Matrix3 mat;
			mat.setRotation3DY(angle);
			this->operator*=(mat);
		}
		/// @brief 3D-rotates the Z of Matrix3.
		/// @param[in] angle The rotation angle.
		inline void rotate3DZ(float angle)
		{
			Matrix3 mat;
			mat.setRotation3DZ(angle);
			this->operator*=(mat);
		}

		/// @brief Transposes the Matrix3.
		inline void transpose()
		{
			this->set(this->data[0], this->data[3], this->data[6],
				this->data[1], this->data[4], this->data[7],
				this->data[2], this->data[5], this->data[8]);
		}
		/// @brief Creates a transposed Matrix3 from this one.
		/// @return The transposed Matrix3 from this one.
		inline Matrix3 transposed() const
		{
			Matrix3 result(*this);
			result.transpose();
			return result;
		}
		/// @brief Inverses the Matrix3.
		inline void inverse()
		{
			float invDet = 1.0f / this->determinant();
			this->set((this->data[4] * this->data[8] - this->data[7] * this->data[5]) * invDet,
				-(this->data[1] * this->data[8] - this->data[7] * this->data[2]) * invDet,
				(this->data[1] * this->data[5] - this->data[4] * this->data[2]) * invDet,
				-(this->data[3] * this->data[8] - this->data[6] * this->data[5]) * invDet,
				(this->data[0] * this->data[8] - this->data[6] * this->data[2]) * invDet,
				-(this->data[0] * this->data[5] - this->data[3] * this->data[2]) * invDet,
				(this->data[3] * this->data[7] - this->data[6] * this->data[4]) * invDet,
				-(this->data[0] * this->data[7] - this->data[6] * this->data[1]) * invDet,
				(this->data[0] * this->data[4] - this->data[3] * this->data[1]) * invDet);
		}
		/// @brief Creates an inversed Matrix3 from this one.
		/// @return The inversed Matrix3 from this one.
		inline Matrix3 inversed() const
		{
			Matrix3 result(*this);
			result.inverse();
			return result;
		}
		/// @brief Inverse-rotates the Matrix3.
		inline void inverseRotation()
		{
			this->set(this->data[0], this->data[3], this->data[2],
				this->data[1], this->data[4], this->data[5],
				this->data[6], this->data[7], this->data[8]);
		}
		/// @brief Creates a rotation-inversed Matrix3 from this one.
		/// @return The rotation-inversed Matrix3 from this one.
		inline Matrix3 inversedRotation() const
		{
			Matrix3 result(*this);
			result.inverseRotation();
			return result;
		}
		/// @brief Inverse-rotates the Matrix3.
		inline void inverseRotation3D()
		{
			this->transpose();
		}
		/// @brief Creates a rotation-inversed Matrix3 from this one.
		/// @return The rotation-inversed Matrix3 from this one.
		inline Matrix3 inversedRotation3D() const
		{
			Matrix3 result(*this);
			result.inverseRotation3D();
			return result;
		}
		/// @brief Ortho-normalizes the Matrix.
		inline void orthoNormalize()
		{
			Vector3 x(data[0], data[1], data[2]);
			Vector3 y(data[3], data[4], data[5]);
			Vector3 z;
			x.normalize();
			z = x.cross(y);
			z.normalize();
			y = z.cross(x);
			y.normalize();
			this->data[0] = x.x;	this->data[1] = x.y;	this->data[2] = x.z;
			this->data[3] = y.x;	this->data[4] = y.y;	this->data[5] = y.z;
			this->data[6] = z.x;	this->data[7] = z.y;	this->data[8] = z.z;
		}
		/// @brief Creates an ortho-normalized the Matrix.
		/// @return The ortho-normalized Matrix3 from this one.
		inline Matrix3 orthoNormalized() const
		{
			Matrix3 result(*this);
			result.orthoNormalize();
			return result;
		}

		/// @brief Multiplies two Matrix3s.
		/// @param[in] other The other Matrix3.
		/// @return The resulting Matrix3.
		inline Matrix3 operator*(const Matrix3& other) const
		{
			return Matrix3(this->data[0] * other[0] + this->data[3] * other[1] + this->data[6] * other[2],
				this->data[1] * other[0] + this->data[4] * other[1] + this->data[7] * other[2],
				this->data[2] * other[0] + this->data[5] * other[1] + this->data[8] * other[2],
				this->data[0] * other[3] + this->data[3] * other[4] + this->data[6] * other[5],
				this->data[1] * other[3] + this->data[4] * other[4] + this->data[7] * other[5],
				this->data[2] * other[3] + this->data[5] * other[4] + this->data[8] * other[5],
				this->data[0] * other[6] + this->data[3] * other[7] + this->data[6] * other[8],
				this->data[1] * other[6] + this->data[4] * other[7] + this->data[7] * other[8],
				this->data[2] * other[6] + this->data[5] * other[7] + this->data[8] * other[8]);
		}
		/// @brief Multiplies each value of a Matrix3 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return The resulting Matrix3.
		inline Matrix3 operator*(float factor) const
		{
			return Matrix3(this->data[0] * factor, this->data[1] * factor, this->data[2] * factor,
				this->data[3] * factor, this->data[4] * factor, this->data[5] * factor,
				this->data[6] * factor, this->data[7] * factor, this->data[8] * factor);
		}
		/// @brief Multiplies a Matrix3 with a Vector3.
		/// @param[in] vector The Vector3.
		/// @return The resulting Vector3.
		inline Vector3 operator*(const Vector3& vector) const
		{
			return Vector3(this->data[0] * vector.x + this->data[3] * vector.y + this->data[6] * vector.z,
				this->data[1] * vector.x + this->data[4] * vector.y + this->data[7] * vector.z,
				this->data[2] * vector.x + this->data[5] * vector.y + this->data[8] * vector.z);
		}
		/// @brief Adds two Matrix3s.
		/// @param[in] other The other Matrix3.
		/// @return The resulting Matrix3.
		inline Matrix3 operator+(const Matrix3& other) const
		{
			return Matrix3(this->data[0] + other[0], this->data[1] + other[1], this->data[2] + other[2],
				this->data[3] + other[3], this->data[4] + other[4], this->data[5] + other[5],
				this->data[6] + other[6], this->data[7] + other[7], this->data[8] + other[8]);
		}
		/// @brief Subtracts two Matrix3s.
		/// @param[in] other The other Matrix3.
		/// @return The resulting Matrix3.
		inline Matrix3 operator-(const Matrix3& other) const
		{
			return Matrix3(this->data[0] - other[0], this->data[1] - other[1], this->data[2] - other[2],
				this->data[3] - other[3], this->data[4] - other[4], this->data[5] - other[5],
				this->data[6] - other[6], this->data[7] - other[7], this->data[8] - other[8]);
		}

		/// @brief Sets this Matrix3 to another one.
		/// @param[in] other The other Matrix3.
		/// @return This Matrix3.
		inline Matrix3 operator=(const Matrix3& other)
		{
			memcpy(this->data, other.data, 9 * sizeof(float));
			return (*this);
		}
		/// @brief Sums up this Matrix3 with another one.
		/// @param[in] other The other Matrix3.
		/// @return This modified Matrix3.
		inline Matrix3 operator+=(const Matrix3& other)
		{
			*this = *this + other;
			return (*this);
		}
		/// @brief Subtracts a Matrix3 from this one.
		/// @param[in] other The other Matrix3.
		/// @return This modified Matrix3.
		inline Matrix3 operator-=(const Matrix3& other)
		{
			*this = *this - other;
			return (*this);
		}
		/// @brief Multiplies this Matrix3 with another one.
		/// @param[in] other The other Matrix3.
		/// @return This modified Matrix3.
		inline Matrix3 operator*=(const Matrix3& other)
		{
			*this = *this * other;
			return (*this);
		}
		/// @brief Multiplies each value of this Matrix3 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return This modified Matrix3.
		inline Matrix3 operator*=(float factor)
		{
			*this = *this * factor;
			return (*this);
		}

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

/// @brief Alias for simpler code.
typedef gtypes::Matrix3 gmat3;
/// @brief Alias for simpler code.
typedef const gtypes::Matrix3& cgmat3;

#endif
