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
/// Represents a 4x4 matrix.

#ifndef GTYPES_MATRIX_4_H
#define GTYPES_MATRIX_4_H

#include <math.h>
#include <string.h>

#include "gtypesExport.h"
#include "gtypesUtil.h"
#include "Matrix3.h"
#include "Quaternion.h"
#include "Rectangle.h"
#include "Vector3.h"

namespace gtypes
{
	class Matrix3;

	/// @brief Represents a 4x4 matrix.
	class gtypesExport Matrix4
	{
	public:
		/// @brief The Matrix data.
		float data[16];

		/// @brief Basic constructor.
		inline Matrix4()
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
		/// @param[in] m9 Matrix value 9.
		/// @param[in] m10 Matrix value 10.
		/// @param[in] m11 Matrix value 11.
		/// @param[in] m12 Matrix value 12.
		/// @param[in] m13 Matrix value 13.
		/// @param[in] m14 Matrix value 14.
		/// @param[in] m15 Matrix value 15.
		inline Matrix4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
		{
			this->set(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15);
		}
		/// @brief Constructor.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 16 or larger.
		inline Matrix4(const float m[])
		{
			this->set(m);
		}
		/// @brief Constructor.
		/// @param[in] mat3 The Matrix3 to construct this Matrix4 from.
		inline Matrix4(const Matrix3& mat3)
		{
			this->set(mat3);
		}
		/// @brief Constructor from rotation.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] angle Rotation angle.
		inline Matrix4(float x, float y, float z, float angle)
		{
			this->setRotation(x, y, z, (float)DEG_TO_RAD(angle));
		}
		/// @brief Constructor from rotation.
		/// @param[in] axis Rotation axis.
		/// @param[in] angle Rotation angle.
		inline Matrix4(const Vector3<float>& axis, float angle)
		{
			this->setRotation(axis.x, axis.y, axis.z, (float)DEG_TO_RAD(angle));
		}

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
		inline void set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15)
		{
			this->data[0] = m0;		this->data[1] = m1;		this->data[2] = m2;		this->data[3] = m3;
			this->data[4] = m4;		this->data[5] = m5;		this->data[6] = m6;		this->data[7] = m7;
			this->data[8] = m8;		this->data[9] = m9;		this->data[10] = m10;	this->data[11] = m11;
			this->data[12] = m12;	this->data[13] = m13;	this->data[14] = m14;	this->data[15] = m15;
		}
		/// @brief Sets the Matrix4 values.
		/// @param[in] m Array of values.
		/// @note m HAS TO be of size 16 or larger.
		inline void set(const float m[])
		{
			memcpy(this->data, m, sizeof(this->data));
		}

		/// @brief Sets the Matrix4 values.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] angle Rotation angle.
		inline void set(float x, float y, float z, float angle)
		{
			this->setRotation(x, y, z, (float)DEG_TO_RAD(angle));
		}
		/// @brief Sets the Matrix4 values.
		/// @param[in] axis Rotation axis.
		/// @param[in] angle Rotation angle.
		inline void set(const Vector3<float>& axis, float angle)
		{
			this->setRotation(axis.x, axis.y, axis.z, (float)DEG_TO_RAD(angle));
		}
		/// @brief Sets the Matrix4 values.
		/// @param[in] other The other Matrix4.
		inline void set(const Matrix4& other)
		{
			memcpy(this->data, other.data, sizeof(this->data));
		}
		/// @brief Sets the Matrix4 values.
		/// @param[in] mat3 The Matrix3 to construct this Matrix4 from.
		inline void set(const Matrix3& mat3)
		{
			this->setIdentity();
			static int rowSize = sizeof(float) * 3;
			memcpy(this->data, mat3.data, rowSize);
			memcpy(&this->data[4], &mat3.data[3], rowSize);
			memcpy(&this->data[8], &mat3.data[6], rowSize);
		}

		/// @brief Sets all values of the Matrix4 to zero.
		inline void setZero()
		{
			memset(this->data, 0, sizeof(this->data));
		}
		/// @brief Sets the Matrix4 to identity.
		inline void setIdentity()
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[5] = this->data[10] = this->data[15] = 1.0f;
		}
		/// @brief Gets rotation as Matrix4.
		/// @return Rotation as Matrix4.
		inline Matrix4 getRotation() const
		{
			return Matrix4(this->data[0], this->data[1], this->data[2], 0.0f,
				this->data[4], this->data[5], this->data[6], 0.0f,
				this->data[8], this->data[9], this->data[10], 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		/// @brief Sets the translation of the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void setTranslation(float x, float y, float z)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[5] = this->data[10] = this->data[15] = 1.0f;
			this->data[12] = x;
			this->data[13] = y;
			this->data[14] = z;
		}
		/// @brief Sets the translation of the Matrix4.
		/// @param[in] vector The Vector3 of the translation.
		inline void setTranslation(const Vector3<float>& vector)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = this->data[5] = this->data[10] = this->data[15] = 1.0f;
			this->data[12] = vector.x;
			this->data[13] = vector.y;
			this->data[14] = vector.z;
		}
		/// @brief Sets the scale of the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void setScale(float x, float y, float z)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[15] = 1.0f;
			this->data[0] = x;
			this->data[5] = y;
			this->data[10] = z;
		}
		/// @brief Sets the scale of the Matrix4.
		/// @param[in] factor The scale factor.
		inline void setScale(float factor)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[15] = 1.0f;
			this->data[0] = this->data[5] = this->data[10] = factor;
		}
		/// @brief Sets the scale of the Matrix4.
		/// @param[in] vector The Vector3 of the scale.
		inline void setScale(const Vector3<float>& vector)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[15] = 1.0f;
			this->data[0] = vector.x;
			this->data[5] = vector.y;
			this->data[10] = vector.z;
		}
		/// @brief Sets the rotation of the Matrix4.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		inline void setRotation(float x, float y, float z, float angle)
		{
			this->setRotation(Vector3<float>(x, y, z), angle);
		}
		/// @brief Sets the rotation of the Matrix4.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		inline void setRotation(const Vector3<float>& axis, float angle)
		{
			memset(this->data, 0, sizeof(this->data));
			double rad = DEG_TO_RAD(angle);
			float c = (float)cos(rad);
			float s = (float)sin(rad);
			Vector3<float> v = axis.normalized();
			float c1 = 1.0f - c;
			float xyc1 = v.x * v.y * c1;
			float yzc1 = v.y * v.z * c1;
			float zxc1 = v.z * v.x * c1;
			float xs = v.x * s;
			float ys = v.y * s;
			float zs = v.z * s;
			this->data[0] = v.x * v.x * c1 + c;	this->data[1] = xyc1 + zs;			this->data[2] = zxc1 - ys;
			this->data[4] = xyc1 - zs;			this->data[5] = v.y * v.y * c1 + c;	this->data[6] = yzc1 + xs;
			this->data[8] = zxc1 + ys;			this->data[9] = yzc1 - xs;			this->data[10] = v.z * v.z * c1 + c;
			this->data[15] = 1.0f;
		}
		/// @brief Sets the X rotation of the Matrix4.
		/// @param[in] angle The rotation angle.
		inline void setRotationX(float angle)
		{
			memset(this->data, 0, sizeof(this->data));
			double rad = DEG_TO_RAD(angle);
			this->data[0] = this->data[15] = 1.0f;
			this->data[5] = this->data[10] = (float)cos(rad);
			this->data[6] = (float)sin(rad);
			this->data[9] = -this->data[6];
		}
		/// @brief Sets the Y rotation of the Matrix4.
		/// @param[in] angle The rotation angle.
		inline void setRotationY(float angle)
		{
			memset(this->data, 0, sizeof(this->data));
			double rad = DEG_TO_RAD(angle);
			this->data[5] = this->data[15] = 1.0f;
			this->data[0] = this->data[10] = (float)cos(rad);
			this->data[8] = (float)sin(rad);
			this->data[2] = -this->data[8];
		}
		/// @brief Sets the Z rotation of the Matrix4.
		/// @param[in] angle The rotation angle.
		inline void setRotationZ(float angle)
		{
			memset(this->data, 0, sizeof(this->data));
			double rad = DEG_TO_RAD(angle);
			this->data[10] = this->data[15] = 1.0f;
			this->data[0] = this->data[5] = (float)cos(rad);
			this->data[1] = (float)sin(rad);
			this->data[4] = -this->data[1];
		}
		/// @brief Sets the reflection of the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] w W coordinate.
		inline void setReflection(float x, float y, float z, float w)
		{
			memset(this->data, 0, sizeof(this->data));
			float x2 = x * 2.0f;
			float y2 = y * 2.0f;
			float z2 = z * 2.0f;
			this->data[0] = 1.0f - x * x2;	this->data[1] = -x * y2;		this->data[2] = -x * z2;
			this->data[4] = -y * x2;		this->data[5] = 1.0f - y * y2;	this->data[6] = -y * z2;
			this->data[8] = -z * x2;		this->data[9] = -z * y2;		this->data[10] = 1.0f - z * z2;
			this->data[12] = -w * x2;		this->data[13] = -w * y2;		this->data[14] = -w * z2;		this->data[15] = 1.0f;
		}
		/// @brief Sets the reflection of the Matrix4.
		/// @param[in] quaternion The Quaternion.
		inline void setReflection(const Quaternion& quaternion)
		{
			this->setReflection(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
		}

		/// @brief Creates an ortho-projection from a Rectangle.
		/// @param[in] rect The Rectangle.
		inline void setOrthoProjection(const Rectangle<float>& rect)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = 2.0f / rect.w;
			this->data[5] = -2.0f / rect.h;
			this->data[10] = -2.0f;
			this->data[12] = -1.0f + rect.x * 2.0f / rect.w;
			this->data[13] = 1.0f - rect.y * 2.0f / rect.h;
			this->data[15] = 1.0f;
		}
		/// @brief Creates an ortho-projection from a Rectangle.
		/// @param[in] rect The Rectangle.
		/// @param[in] nearZ The near plane.
		/// @param[in] farZ The far plane.
		inline void setOrthoProjection(const Rectangle<float>& rect, float nearZ, float farZ)
		{
			memset(this->data, 0, sizeof(this->data));
			this->data[0] = 2.0f / rect.w;
			this->data[5] = -2.0f / rect.h;
			this->data[10] = -2.0f / (farZ - nearZ);
			this->data[12] = -1.0f + rect.x * 2.0f / rect.w;
			this->data[13] = 1.0f - rect.y * 2.0f / rect.h;
			this->data[14] = (farZ + nearZ) / (farZ - nearZ);
			this->data[15] = 1.0f;
		}
		/// @brief Sets the perspective in a Matrix4.
		/// @param[in] fov The field-of-view.
		/// @param[in] aspect The aspect ratio of the view.
		/// @param[in] nearZ The near plane.
		/// @param[in] farZ The far plane.
		inline void setPerspective(float fov, float aspect, float nearZ, float farZ)
		{
			memset(this->data, 0, sizeof(this->data));
			float iy = 1.0f / ((float)tan(DEG_TO_RAD(fov * 0.5f)));
			float zDiff = farZ - nearZ;
			this->data[0] = iy * aspect;
			this->data[5] = iy;
			this->data[10] = -(farZ + nearZ) / zDiff;
			this->data[11] = -1.0f;
			this->data[14] = -(2.0f * farZ * nearZ) / zDiff;
		}

		/// @brief Calculates the determinant of the Matrix4.
		/// @return The determinant of the Matrix4.
		inline float determinant() const
		{
			return ((this->data[0] * this->data[5] * this->data[10]) +
				(this->data[4] * this->data[9] * this->data[2]) +
				(this->data[8] * this->data[1] * this->data[6]) -
				(this->data[8] * this->data[5] * this->data[2]) -
				(this->data[4] * this->data[1] * this->data[10]) -
				(this->data[0] * this->data[9] * this->data[6]));
		}
		/// @brief Translates the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void translate(float x, float y, float z)
		{
			Matrix4 mat;
			mat.setTranslation(x, y, z);
			this->operator*=(mat);
		}
		/// @brief Translates the Matrix4.
		/// @param[in] vector The Vector3 to use for the translation.
		inline void translate(const Vector3<float>& vector)
		{
			Matrix4 mat;
			mat.setTranslation(vector);
			this->operator*=(mat);
		}
		/// @brief Scales the Matrix4.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		inline void scale(float x, float y, float z)
		{
			Matrix4 mat;
			mat.setScale(x, y, z);
			this->operator*=(mat);
		}
		/// @brief Scales the Matrix4.
		/// @param[in] factor Scaling factor.
		inline void scale(float factor)
		{
			Matrix4 mat;
			mat.setScale(factor);
			this->operator*=(mat);
		}
		/// @brief Scales the Matrix4.
		/// @param[in] vector The Vector3 to use for the scaling.
		inline void scale(const Vector3<float>& vector)
		{
			Matrix4 mat;
			mat.setScale(vector);
			this->operator*=(mat);
		}
		/// @brief Rotates the Matrix4.
		/// @param[in] x X coordinate of the rotation axis.
		/// @param[in] y Y coordinate of the rotation axis.
		/// @param[in] z Z coordinate of the rotation axis.
		/// @param[in] angle The rotation angle.
		inline void rotate(float x, float y, float z, float angle)
		{
			Matrix4 mat;
			mat.setRotation(x, y, z, angle);
			this->operator*=(mat);
		}
		/// @brief Rotates the Matrix4.
		/// @param[in] axis The rotation axis.
		/// @param[in] angle The rotation angle.
		inline void rotate(const Vector3<float>& axis, float angle)
		{
			Matrix4 mat;
			mat.setRotation(axis, angle);
			this->operator*=(mat);
		}
		/// @brief Rotates the X of Matrix4.
		/// @param[in] angle The rotation angle.
		inline void rotateX(float angle)
		{
			Matrix4 mat;
			mat.setRotationX(angle);
			this->operator*=(mat);
		}
		/// @brief Rotates the Y of Matrix4.
		/// @param[in] angle The rotation angle.
		inline void rotateY(float angle)
		{
			Matrix4 mat;
			mat.setRotationY(angle);
			this->operator*=(mat);
		}
		/// @brief Rotates the Z of Matrix4.
		/// @param[in] angle The rotation angle.
		inline void rotateZ(float angle)
		{
			Matrix4 mat;
			mat.setRotationZ(angle);
			this->operator*=(mat);
		}
		/// @brief Reflects the Matrix4 around a quaternion.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] z Z coordinate.
		/// @param[in] w W coordinate.
		inline void reflect(float x, float y, float z, float w)
		{
			Matrix4 mat;
			mat.setReflection(x, y, z, w);
			this->operator*=(mat);
		}
		/// @brief Reflects the Matrix4 around a quaternion.
		/// @param[in] quaternion The Quaternion.
		inline void reflect(const Quaternion& quaternion)
		{
			Matrix4 mat;
			mat.setReflection(quaternion);
			this->operator*=(mat);
		}

		/// @brief Changes the Matrix4 to reflect a look-at defined Vector3s defining the look eye's position, the target's position and the up-vector.
		/// @param[in] eye The eye position.
		/// @param[in] target The target position.
		/// @param[in] up The up-vector.
		// so that you can see the Matrix, Neo
		inline void lookAt(const Vector3<float>& eye, const Vector3<float>& target, const Vector3<float>& up)
		{
			Vector3<float> bz = (eye - target).normalized();
			Vector3<float> bx = up.cross(bz).normalized();
			Vector3<float> by = bz.cross(bx).normalized();
			this->set(bx.x, by.x, bz.x, 0.0f, bx.y, by.y, bz.y, 0.0f, bx.z, by.z, bz.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
			Matrix4 b;
			b.setTranslation(-eye);
			this->operator*=(b);
		}

		/// @brief Transposes the Matrix4.
		inline void transpose()
		{
			this->set(this->data[0], this->data[4], this->data[8], this->data[12],
				this->data[1], this->data[5], this->data[9], this->data[13],
				this->data[2], this->data[6], this->data[10], this->data[14],
				this->data[3], this->data[7], this->data[11], this->data[15]);
		}
		/// @brief Creates a transposed Matrix4 from this one.
		/// @return The transposed Matrix4 from this one.
		inline Matrix4 transposed() const
		{
			Matrix4 result(*this);
			result.transpose();
			return result;
		}
		/// @brief Inverses the Matrix4.
		/// @note This will NOT inverse the rotation!
		inline void inverse()
		{
			float m[16] = { 0.0f }; // required, because m[0-10] are used for m[12-14]
			float invDet = 1.0f / this->determinant();
			m[0] = (this->data[5] * this->data[10] - this->data[9] * this->data[6]) * invDet;
			m[1] = -(this->data[1] * this->data[10] - this->data[9] * this->data[2]) * invDet;
			m[2] = (this->data[1] * this->data[6] - this->data[5] * this->data[2]) * invDet;
			m[4] = -(this->data[4] * this->data[10] - this->data[8] * this->data[6]) * invDet;
			m[5] = (this->data[0] * this->data[10] - this->data[8] * this->data[2]) * invDet;
			m[6] = -(this->data[0] * this->data[6] - this->data[4] * this->data[2]) * invDet;
			m[8] = (this->data[4] * this->data[9] - this->data[8] * this->data[5]) * invDet;
			m[9] = -(this->data[0] * this->data[9] - this->data[8] * this->data[1]) * invDet;
			m[10] = (this->data[0] * this->data[5] - this->data[4] * this->data[1]) * invDet;
			m[12] = -(this->data[12] * m[0] + this->data[13] * m[4] + this->data[14] * m[8]);
			m[13] = -(this->data[12] * m[1] + this->data[13] * m[5] + this->data[14] * m[9]);
			m[14] = -(this->data[12] * m[2] + this->data[13] * m[6] + this->data[14] * m[10]);
			m[15] = 1.0f;
			this->set(m);
		}
		/// @brief Creates an inversed Matrix4 from this one.
		/// @return The inversed Matrix4 from this one.
		/// @note This will NOT inverse the rotation!
		inline Matrix4 inversed() const
		{
			Matrix4 result(*this);
			result.inverse();
			return result;
		}
		/// @brief Inverses the rotation of the Matrix4.
		inline void inverseRotation()
		{
			this->set(this->data[0], this->data[4], this->data[8], this->data[3],
				this->data[1], this->data[5], this->data[9], this->data[7],
				this->data[2], this->data[6], this->data[10], this->data[11],
				this->data[12], this->data[13], this->data[14], this->data[15]);
		}
		/// @brief Creates a rotation-inversed Matrix4 from this one.
		/// @return The rotation-inversed Matrix4 from this one.
		inline Matrix4 inversedRotation() const
		{
			Matrix4 result(*this);
			result.inverseRotation();
			return result;
		}
		
		/// @brief Multiplies two Matrix4s.
		/// @param[in] other The other Matrix4.
		/// @return The resulting Matrix4.
		inline Matrix4 operator*(const Matrix4& other) const
		{
			return Matrix4(this->data[0] * other[0] + this->data[4] * other[1] + this->data[8] * other[2] + this->data[12] * other[3],
				this->data[1] * other[0] + this->data[5] * other[1] + this->data[9] * other[2] + this->data[13] * other[3],
				this->data[2] * other[0] + this->data[6] * other[1] + this->data[10] * other[2] + this->data[14] * other[3],
				this->data[3] * other[0] + this->data[7] * other[1] + this->data[11] * other[2] + this->data[15] * other[3],
				this->data[0] * other[4] + this->data[4] * other[5] + this->data[8] * other[6] + this->data[12] * other[7],
				this->data[1] * other[4] + this->data[5] * other[5] + this->data[9] * other[6] + this->data[13] * other[7],
				this->data[2] * other[4] + this->data[6] * other[5] + this->data[10] * other[6] + this->data[14] * other[7],
				this->data[3] * other[4] + this->data[7] * other[5] + this->data[11] * other[6] + this->data[15] * other[7],
				this->data[0] * other[8] + this->data[4] * other[9] + this->data[8] * other[10] + this->data[12] * other[11],
				this->data[1] * other[8] + this->data[5] * other[9] + this->data[9] * other[10] + this->data[13] * other[11],
				this->data[2] * other[8] + this->data[6] * other[9] + this->data[10] * other[10] + this->data[14] * other[11],
				this->data[3] * other[8] + this->data[7] * other[9] + this->data[11] * other[10] + this->data[15] * other[11],
				this->data[0] * other[12] + this->data[4] * other[13] + this->data[8] * other[14] + this->data[12] * other[15],
				this->data[1] * other[12] + this->data[5] * other[13] + this->data[9] * other[14] + this->data[13] * other[15],
				this->data[2] * other[12] + this->data[6] * other[13] + this->data[10] * other[14] + this->data[14] * other[15],
				this->data[3] * other[12] + this->data[7] * other[13] + this->data[11] * other[14] + this->data[15] * other[15]);
		}
		/// @brief Multiplies each value of a Matrix4 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return The resulting Matrix4.
		inline Matrix4 operator*(float factor) const
		{
			return Matrix4(this->data[0] * factor, this->data[1] * factor, this->data[2] * factor, this->data[3] * factor,
				this->data[4] * factor, this->data[5] * factor, this->data[6] * factor, this->data[7] * factor,
				this->data[8] * factor, this->data[9] * factor, this->data[10] * factor, this->data[11] * factor,
				this->data[12] * factor, this->data[13] * factor, this->data[14] * factor, this->data[15] * factor);
		}
		/// @brief Multiplies a Matrix4 with a Vector3.
		/// @param[in] vector The Vector3.
		/// @return The resulting Vector3.
		inline Vector3<float> operator*(const Vector3<float>& vector) const
		{
			return Vector3<float>(this->data[0] * vector.x + this->data[4] * vector.y + this->data[8] * vector.z + this->data[12],
				this->data[1] * vector.x + this->data[5] * vector.y + this->data[9] * vector.z + this->data[13],
				this->data[2] * vector.x + this->data[6] * vector.y + this->data[10] * vector.z + this->data[14]);
		}
		/// @brief Multiplies a Matrix4 with a Quaternion.
		/// @param[in] quaternion The Quaternion.
		/// @return The resulting Quaternion.
		inline Quaternion operator*(const Quaternion& quaternion) const
		{
			return Quaternion(this->data[0] * quaternion.x + this->data[4] * quaternion.y + this->data[8] * quaternion.z + this->data[12] * quaternion.w,
				this->data[1] * quaternion.x + this->data[5] * quaternion.y + this->data[9] * quaternion.z + this->data[13] * quaternion.w,
				this->data[2] * quaternion.x + this->data[6] * quaternion.y + this->data[10] * quaternion.z + this->data[14] * quaternion.w,
				this->data[3] * quaternion.x + this->data[7] * quaternion.y + this->data[11] * quaternion.z + this->data[15] * quaternion.w);
		}
		/// @brief Adds two Matrix4s.
		/// @param[in] other The other Matrix4.
		/// @return The resulting Matrix4.
		inline Matrix4 operator+(const Matrix4& other) const
		{
			return Matrix4(this->data[0] + other[0], this->data[1] + other[1], this->data[2] + other[2], this->data[3] + other[3],
				this->data[4] + other[4], this->data[5] + other[5], this->data[6] + other[6], this->data[7] + other[7],
				this->data[8] + other[8], this->data[9] + other[9], this->data[10] + other[10], this->data[11] + other[11],
				this->data[12] + other[12], this->data[13] + other[13], this->data[14] + other[14], this->data[15] + other[15]);
		}
		/// @brief Subtracts two Matrix4s.
		/// @param[in] other The other Matrix4.
		/// @return The resulting Matrix4.
		inline Matrix4 operator-(const Matrix4& other) const
		{
			return Matrix4(this->data[0] - other[0], this->data[1] - other[1], this->data[2] - other[2], this->data[3] - other[3],
				this->data[4] - other[4], this->data[5] - other[5], this->data[6] - other[6], this->data[7] - other[7],
				this->data[8] - other[8], this->data[9] - other[9], this->data[10] - other[10], this->data[11] - other[11],
				this->data[12] - other[12], this->data[13] - other[13], this->data[14] - other[14], this->data[15] - other[15]);
		}

		/// @brief Sets this Matrix4 to another one.
		/// @param[in] other The other Matrix4.
		/// @return This Matrix4.
		inline Matrix4 operator=(const Matrix4& other)
		{
			memcpy(this->data, other.data, 16 * sizeof(float));
			return (*this);
		}
		/// @brief Sums up this Matrix4 with another one.
		/// @param[in] other The other Matrix4.
		/// @return This modified Matrix4.
		inline Matrix4 operator+=(const Matrix4& other)
		{
			*this = *this + other;
			return (*this);
		}
		/// @brief Subtracts a Matrix4 from this one.
		/// @param[in] other The other Matrix4.
		/// @return This modified Matrix4.
		inline Matrix4 operator-=(const Matrix4& other)
		{
			*this = *this - other;
			return (*this);
		}
		/// @brief Multiplies this Matrix4 with another one.
		/// @param[in] other The other Matrix4.
		/// @return This modified Matrix4.
		inline Matrix4 operator*=(const Matrix4& other)
		{
			*this = *this * other;
			return (*this);
		}
		/// @brief Multiplies each value of this Matrix4 with a factor.
		/// @param[in] factor The multiplication factor.
		/// @return This modified Matrix4.
		Matrix4 operator*=(float factor)
		{
			*this = *this * factor;
			return (*this);
		}

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

/// @brief Alias for simpler code.
typedef gtypes::Matrix4 gmat4;
/// @brief Alias for simpler code.
typedef const gtypes::Matrix4& cgmat4;

#endif
