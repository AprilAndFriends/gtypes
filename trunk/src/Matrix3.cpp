/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include <math.h>

#include "gtypesUtil.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector2.h"
#include "Vector3.h"

namespace gtypes
{
	Matrix3::Matrix3()
	{
		this->setIdentity();
	}
	
	Matrix3::Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		this->set(m0, m1, m2, m3, m4, m5, m6, m7, m8);
	}
	
	Matrix3::Matrix3(const float m[])
	{
		this->set(m);
	}
	
	Matrix3::Matrix3(const Matrix4& mat)
	{
		this->set(mat);
	}
	
	void Matrix3::set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		this->data[0] = m0;	this->data[1] = m1;	this->data[2] = m2;
		this->data[3] = m3;	this->data[4] = m4;	this->data[5] = m5;
		this->data[6] = m6;	this->data[7] = m7;	this->data[8] = m8;
	}
	
	void Matrix3::set(const float m[])
	{
		this->data[0] = m[0];	this->data[1] = m[1];	this->data[2] = m[2];
		this->data[3] = m[3];	this->data[4] = m[4];	this->data[5] = m[5];
		this->data[6] = m[6];	this->data[7] = m[7];	this->data[8] = m[8];
	}
	
	void Matrix3::set(const Matrix4& mat)
	{
		this->data[0] = mat.data[0];	this->data[1] = mat.data[1];	this->data[2] = mat.data[2];
		this->data[3] = mat.data[4];	this->data[4] = mat.data[5];	this->data[5] = mat.data[6];
		this->data[6] = mat.data[8];	this->data[7] = mat.data[9];	this->data[8] = mat.data[10];
	}
	
	void Matrix3::set(const Matrix3& other)
	{
		this->data[0] = other.data[0];	this->data[1] = other.data[1];	this->data[2] = other.data[2];
		this->data[3] = other.data[3];	this->data[4] = other.data[4];	this->data[5] = other.data[5];
		this->data[6] = other.data[6];	this->data[7] = other.data[7];	this->data[8] = other.data[8];
	}

	void Matrix3::setZero()
	{
		this->data[0] = 0.0f;	this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = 0.0f;	this->data[5] = 0.0f;
		this->data[6] = 0.0f;	this->data[7] = 0.0f;	this->data[8] = 0.0f;
	}

	void Matrix3::setIdentity()
	{
		this->data[0] = 1.0f;	this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = 1.0f;	this->data[5] = 0.0f;
		this->data[6] = 0.0f;	this->data[7] = 0.0f;	this->data[8] = 1.0f;
	}

	void Matrix3::setTranslation(float x, float y)
	{
		this->data[0] = 1.0f;	this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = 1.0f;	this->data[5] = 0.0f;
		this->data[6] = x;		this->data[7] = y;		this->data[8] = 1.0f;
	}

	void Matrix3::setTranslation(const Vector2& vector)
	{
		this->data[0] = 1.0f;		this->data[1] = 0.0f;		this->data[2] = 0.0f;
		this->data[3] = 0.0f;		this->data[4] = 1.0f;		this->data[5] = 0.0f;
		this->data[6] = vector.x;	this->data[7] = vector.y;	this->data[8] = 1.0f;
	}

	void Matrix3::setScale(float x, float y)
	{
		this->data[0] = x;		this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = y;		this->data[5] = 0.0f;
		this->data[6] = 0.0f;	this->data[7] = 0.0f;	this->data[8] = 1.0f;
	}

	void Matrix3::setScale(float factor)
	{
		this->setScale(factor, factor);
	}

	void Matrix3::setScale(const Vector2& vector)
	{
		this->setScale(vector.x, vector.y);
	}

	void Matrix3::setScale3D(float x, float y, float z)
	{
		this->data[0] = x;		this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = y;		this->data[5] = 0.0f;
		this->data[6] = 0.0f;	this->data[7] = 0.0f;	this->data[8] = z;
	}

	void Matrix3::setScale3D(float factor)
	{
		this->setScale3D(factor, factor, factor);
	}

	void Matrix3::setScale3D(const Vector3& vector)
	{
		this->setScale3D(vector.x, vector.y, vector.z);
	}

	void Matrix3::setRotation(float angle)
	{
		double rad = DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0] = c;		this->data[1] = -s;		this->data[2] = 0.0f;
		this->data[3] = s;		this->data[4] = c;		this->data[5] = 0.0f;
		this->data[6] = 0.0f;	this->data[7] = 0.0f;	this->data[8] = 1.0f;
	}

	void Matrix3::setRotation3D(float x, float y, float z, float angle)
	{
		this->setRotation3D(Vector3(x, y, z), angle);
	}

	void Matrix3::setRotation3D(const Vector3& axis, float angle)
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

	void Matrix3::setRotation3DX(float angle)
	{
		double rad = DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0] = 1.0f;	this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = c;		this->data[5] = s;
		this->data[6] = 0.0f;	this->data[7] = -s;		this->data[8] = c;
	}

	void Matrix3::setRotation3DY(float angle)
	{
		double rad = DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0] = c;		this->data[1] = 0.0f;	this->data[2] = -s;
		this->data[3] = 0.0f;	this->data[4] = 1.0f;	this->data[5] = 0.0f;
		this->data[6] = s;		this->data[7] = 0.0f;	this->data[8] = c;
	}

	void Matrix3::setRotation3DZ(float angle)
	{
		this->setRotation(angle); // the Z-axis is the default rotation axis
	}

	float Matrix3::det() const
	{
		return (this->data[0] * this->data[4] * this->data[8] +
				this->data[3] * this->data[7] * this->data[2] +
				this->data[6] * this->data[1] * this->data[5] -
				this->data[6] * this->data[4] * this->data[2] -
				this->data[3] * this->data[1] * this->data[8] -
				this->data[0] * this->data[7] * this->data[5]);
	}

	void Matrix3::translate(float x, float y)
	{
		Matrix3 mat;
		mat.setTranslation(x, y);
		this->operator*=(mat);
	}

	void Matrix3::translate(const Vector2& vector)
	{
		Matrix3 mat;
		mat.setTranslation(vector);
		this->operator*=(mat);
	}

	void Matrix3::scale(float x, float y)
	{
		Matrix3 mat;
		mat.setScale(x, y);
		this->operator*=(mat);
	}

	void Matrix3::scale(float factor)
	{
		Matrix3 mat;
		mat.setScale(factor);
		this->operator*=(mat);
	}

	void Matrix3::scale(const Vector2& vector)
	{
		Matrix3 mat;
		mat.setScale(vector);
		this->operator*=(mat);
	}

	void Matrix3::scale3D(float x, float y, float z)
	{
		Matrix3 mat;
		mat.setScale3D(x, y, z);
		this->operator*=(mat);
	}

	void Matrix3::scale3D(float factor)
	{
		Matrix3 mat;
		mat.setScale3D(factor);
		this->operator*=(mat);
	}

	void Matrix3::scale3D(const Vector3& vector)
	{
		Matrix3 mat;
		mat.setScale3D(vector);
		this->operator*=(mat);
	}

	void Matrix3::rotate(float angle)
	{
		Matrix3 mat;
		mat.setRotation(angle);
		this->operator*=(mat);
	}

	void Matrix3::rotate3D(float x, float y, float z, float angle)
	{
		Matrix3 mat;
		mat.setRotation3D(x, y, z, angle);
		this->operator*=(mat);
	}

	void Matrix3::rotate3D(const Vector3 &axis, float angle)
	{
		Matrix3 mat;
		mat.setRotation3D(axis, angle);
		this->operator*=(mat);
	}

	void Matrix3::rotate3DX(float angle)
	{
		Matrix3 mat;
		mat.setRotation3DX(angle);
		this->operator*=(mat);
	}

	void Matrix3::rotate3DY(float angle)
	{
		Matrix3 mat;
		mat.setRotation3DY(angle);
		this->operator*=(mat);
	}

	void Matrix3::rotate3DZ(float angle)
	{
		Matrix3 mat;
		mat.setRotation3DZ(angle);
		this->operator*=(mat);
	}

	void Matrix3::transpose()
	{
		this->set(this->data[0], this->data[3], this->data[6],
				  this->data[1], this->data[4], this->data[7],
				  this->data[2], this->data[5], this->data[8]);
	}

	Matrix3 Matrix3::transposed() const
	{
		Matrix3 result(*this);
		result.transpose();
		return result;
	}

	void Matrix3::inverse()
	{
		float invDet = 1.0f / this->det();
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

	Matrix3 Matrix3::inversed() const
	{
		Matrix3 result(*this);
		result.inverse();
		return result;
	}

	void Matrix3::inverseRotation()
	{
		this->set(this->data[0], this->data[3], this->data[2],
				  this->data[1], this->data[4], this->data[5],
				  this->data[6], this->data[7], this->data[8]);
	}

	Matrix3 Matrix3::inversedRotation() const
	{
		Matrix3 result(*this);
		result.inverseRotation();
		return result;
	}

	void Matrix3::inverseRotation3D()
	{
		this->transpose();
	}

	Matrix3 Matrix3::inversedRotation3D() const
	{
		Matrix3 result(*this);
		result.inverseRotation3D();
		return result;
	}

	void Matrix3::orthoNormalize()
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
	
	Matrix3 Matrix3::orthoNormalized() const
	{
		Matrix3 result(*this);
		result.orthoNormalize();
		return result;
	}

	Matrix3 Matrix3::operator*(const Matrix3& other) const
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
	
	Matrix3 Matrix3::operator*(float factor) const
	{
		return Matrix3(this->data[0] * factor, this->data[1] * factor, this->data[2] * factor,
					   this->data[3] * factor, this->data[4] * factor, this->data[5] * factor,
					   this->data[6] * factor, this->data[7] * factor, this->data[8] * factor);
	}

	Vector3 Matrix3::operator*(const Vector3& vector) const
	{
		return Vector3(this->data[0] * vector.x + this->data[3] * vector.y + this->data[6] * vector.z,
					   this->data[1] * vector.x + this->data[4] * vector.y + this->data[7] * vector.z,
					   this->data[2] * vector.x + this->data[5] * vector.y + this->data[8] * vector.z);
	}

	Matrix3 Matrix3::operator+(const Matrix3& other) const
	{
		return Matrix3(this->data[0] + other[0], this->data[1] + other[1], this->data[2] + other[2],
					   this->data[3] + other[3], this->data[4] + other[4], this->data[5] + other[5],
					   this->data[6] + other[6], this->data[7] + other[7], this->data[8] + other[8]);
	}
	
	Matrix3 Matrix3::operator-(const Matrix3& other) const
	{
		return Matrix3(this->data[0] - other[0], this->data[1] - other[1], this->data[2] - other[2],
					   this->data[3] - other[3], this->data[4] - other[4], this->data[5] - other[5],
					   this->data[6] - other[6], this->data[7] - other[7], this->data[8] - other[8]);
	}
	

	Matrix3 Matrix3::operator*=(const Matrix3& other)
	{
		*this = *this * other;
		return (*this);
	}

	Matrix3 Matrix3::operator*=(float factor)
	{
		*this = *this * factor;
		return (*this);
	}

	Matrix3 Matrix3::operator+=(const Matrix3& other)
	{
		*this = *this + other;
		return (*this);
	}

	Matrix3 Matrix3::operator-=(const Matrix3& other)
	{
		*this = *this - other;
		return (*this);
	}

}

