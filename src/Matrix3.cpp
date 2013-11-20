/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.49
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include <math.h>

#include "gtypesUtil.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector3.h"

namespace gtypes
{
	Matrix3::Matrix3()
	{
		this->setIdentity();
	}
	
	Matrix3::Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		this->data[0] = m0; this->data[1] = m1; this->data[2] = m2;
		this->data[3] = m3; this->data[4] = m4; this->data[5] = m5;
		this->data[6] = m6; this->data[7] = m7; this->data[8] = m8;
	}
	
	Matrix3::Matrix3(float m[])
	{
		this->data[0] = m[0]; this->data[1] = m[1]; this->data[2] = m[2];
		this->data[3] = m[3]; this->data[4] = m[4]; this->data[5] = m[5];
		this->data[6] = m[6]; this->data[7] = m[7]; this->data[8] = m[8];
	}
	
	Matrix3::Matrix3(const Matrix3& m)
	{
		this->data[0] = m.data[0]; this->data[1] = m.data[1]; this->data[2] = m.data[2];
		this->data[3] = m.data[3]; this->data[4] = m.data[4]; this->data[5] = m.data[5];
		this->data[6] = m.data[6]; this->data[7] = m.data[7]; this->data[8] = m.data[8];
	}

	Matrix3::Matrix3(const Matrix4& m)
	{
		this->data[0] = m.data[0]; this->data[1] = m.data[1]; this->data[2] = m.data[2];
		this->data[3] = m.data[4]; this->data[4] = m.data[5]; this->data[5] = m.data[6];
		this->data[6] = m.data[8]; this->data[7] = m.data[9]; this->data[8] = m.data[10];
	}
	
	void Matrix3::set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		this->data[0] = m0; this->data[1] = m1; this->data[2] = m2;
		this->data[3] = m3; this->data[4] = m4; this->data[5] = m5;
		this->data[6] = m6; this->data[7] = m7; this->data[8] = m8;
	}
	
	void Matrix3::set(float m[])
	{
		this->data[0] = m[0]; this->data[1] = m[1]; this->data[2] = m[2];
		this->data[3] = m[3]; this->data[4] = m[4]; this->data[5] = m[5];
		this->data[6] = m[6]; this->data[7] = m[7]; this->data[8] = m[8];
	}
	
	void Matrix3::set(const Matrix3& m)
	{
		this->data[0] = m.data[0]; this->data[1] = m.data[1]; this->data[2] = m.data[2];
		this->data[3] = m.data[3]; this->data[4] = m.data[4]; this->data[5] = m.data[5];
		this->data[6] = m.data[6]; this->data[7] = m.data[7]; this->data[8] = m.data[8];
	}

	void Matrix3::set(const Matrix4& m)
	{
		this->data[0] = m.data[0]; this->data[1] = m.data[1]; this->data[2] = m.data[2];
		this->data[3] = m.data[4]; this->data[4] = m.data[5]; this->data[5] = m.data[6];
		this->data[6] = m.data[8]; this->data[7] = m.data[9]; this->data[8] = m.data[10];
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
	
	void Matrix3::inverse()
	{
		float idet = 1.0f / this->det();
		this->set((this->data[4] * this->data[8] - this->data[7] * this->data[5]) * idet,
				 -(this->data[1] * this->data[8] - this->data[7] * this->data[2]) * idet,
				  (this->data[1] * this->data[5] - this->data[4] * this->data[2]) * idet,
				 -(this->data[3] * this->data[8] - this->data[6] * this->data[5]) * idet,
				  (this->data[0] * this->data[8] - this->data[6] * this->data[2]) * idet,
				 -(this->data[0] * this->data[5] - this->data[3] * this->data[2]) * idet,
				  (this->data[3] * this->data[7] - this->data[6] * this->data[4]) * idet,
				 -(this->data[0] * this->data[7] - this->data[6] * this->data[1]) * idet,
				  (this->data[0] * this->data[4] - this->data[3] * this->data[1]) * idet);
	}
	
	Matrix3 Matrix3::inversed() const
	{
		Matrix3 mat(*this);
		mat.inverse();
		return mat;
	}
	
	void Matrix3::transpose()
	{
		this->set(this->data[0], this->data[3], this->data[6],
				  this->data[1], this->data[4], this->data[7],
				  this->data[2], this->data[5], this->data[8]);
	}
	
	Matrix3 Matrix3::transposed() const
	{
		Matrix3 mat(*this);
		mat.transpose();
		return mat;
	}
	
	Matrix3 Matrix3::rotationInverse2D() const
	{
		return Matrix3(this->data[0], this->data[3], 		0.0f,
					   this->data[1], this->data[4], 		0.0f,
								0.0f, 		   0.0f,		1.0f);
	}
	
	Matrix3 Matrix3::rotationInverse3D() const
	{
		return this->transposed();
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
		this->data[0] = x.x; this->data[1] = x.y; this->data[2] = x.z;
		this->data[3] = y.x; this->data[4] = y.y; this->data[5] = y.z;
		this->data[6] = z.x; this->data[7] = z.y; this->data[8] = z.z;
	}
	
	void Matrix3::setIdentity()
	{
		this->data[0] = 1.0f; this->data[1] = 0.0f; this->data[2] = 0.0f;
		this->data[3] = 0.0f; this->data[4] = 1.0f; this->data[5] = 0.0f;
		this->data[6] = 0.0f; this->data[7] = 0.0f; this->data[8] = 1.0f;
	}

	void Matrix3::setZero()
	{
		this->data[0] = 0.0f; this->data[1] = 0.0f; this->data[2] = 0.0f;
		this->data[3] = 0.0f; this->data[4] = 0.0f; this->data[5] = 0.0f;
		this->data[6] = 0.0f; this->data[7] = 0.0f; this->data[8] = 0.0f;
	}
	
	Matrix3 Matrix3::operator*(const Matrix3& m) const
	{
		return Matrix3(this->data[0] * m[0] + this->data[3] * m[1] + this->data[6] * m[2],
					   this->data[1] * m[0] + this->data[4] * m[1] + this->data[7] * m[2],
					   this->data[2] * m[0] + this->data[5] * m[1] + this->data[8] * m[2],
					   this->data[0] * m[3] + this->data[3] * m[4] + this->data[6] * m[5],
					   this->data[1] * m[3] + this->data[4] * m[4] + this->data[7] * m[5],
					   this->data[2] * m[3] + this->data[5] * m[4] + this->data[8] * m[5],
					   this->data[0] * m[6] + this->data[3] * m[7] + this->data[6] * m[8],
					   this->data[1] * m[6] + this->data[4] * m[7] + this->data[7] * m[8],
					   this->data[2] * m[6] + this->data[5] * m[7] + this->data[8] * m[8]);
	}
	
	Matrix3 Matrix3::operator+(const Matrix3& m) const
	{
		return Matrix3(this->data[0] + m[0], this->data[1] + m[1], this->data[2] + m[2],
					   this->data[3] + m[3], this->data[4] + m[4], this->data[5] + m[5],
					   this->data[6] + m[6], this->data[7] + m[7], this->data[8] + m[8]);
	}
	
	Vector3 Matrix3::operator*(const Vector3& v) const
	{
		return Vector3(this->data[0] * v.x + this->data[3] * v.y + this->data[6] * v.z,
					   this->data[1] * v.x + this->data[4] * v.y + this->data[7] * v.z,
					   this->data[2] * v.x + this->data[5] * v.y + this->data[8] * v.z);
	}
	
	Matrix3 Matrix3::operator*(float f) const
	{
		return Matrix3(this->data[0] * f, this->data[1] * f, this->data[2] * f,
					   this->data[3] * f, this->data[4] * f, this->data[5] * f,
					   this->data[6] * f, this->data[7] * f, this->data[8] * f);
	}
	
	Matrix3 Matrix3::operator-(const Matrix3& m) const
	{
		return Matrix3(this->data[0] - m[0], this->data[1] - m[1], this->data[2] - m[2],
					   this->data[3] - m[3], this->data[4] - m[4], this->data[5] - m[5],
					   this->data[6] - m[6], this->data[7] - m[7], this->data[8] - m[8]);
	}
	
	void Matrix3::setTranslation2D(float x, float y)
	{
		this->data[2] = x;
		this->data[5] = y;
	}
	
	void Matrix3::translate2D(float x, float y)
	{
		Matrix3 mat;
		mat.setTranslation2D(x, y);
		this->operator*=(mat);
	}
	
	void Matrix3::setRotation2D(float angle)
	{
		float rad = (float)DEG_TO_RAD(angle);
		this->data[0] = cos(rad); this->data[1] = -sin(rad);
		this->data[3] = sin(rad); this->data[4] =  cos(rad);
	}
	
	void Matrix3::rotate2D(float angle)
	{
		Matrix3 mat;
		mat.setRotation2D(angle);
		this->operator*=(mat);
	}
	
	void Matrix3::setRotation3D(float x, float y, float z, float angle)
	{
		float rad = (float)DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		float l = sqrt(x * x + y * y + z * z);
		if (l < G_E_TOLERANCE)
		{
			l = 1.0f;
		}
		else
		{
			l = 1.0f / l;
		}
		x *= l;
		y *= l;
		z *= l;
		float xy = x * y;
		float yz = y * z;
		float zx = z * x;
		float xs = x * s;
		float ys = y * s;
		float zs = z * s;
		float c1 = 1.0f - c;
		this->data[0] = c1 * x * x + c;	this->data[1] = c1 * xy + zs;	this->data[2] = c1 * zx - ys;
		this->data[3] = c1 * xy - zs;	this->data[4] = c1 * y * y + c;	this->data[5] = c1 * yz + xs;
		this->data[6] = c1 * zx + ys;	this->data[7] = c1 * yz - xs;	this->data[8] = c1 * z * z + c;
	}
	
	void Matrix3::setRotation3D(const Vector3& v, float angle)
	{
		return this->setRotation3D(v.x, v.y, v.z, angle);
	}
	
	void Matrix3::rotate3D(float x, float y, float z, float angle)
	{
		Matrix3 mat;
		mat.setRotation3D(x, y, z, angle);
		this->operator*=(mat);
	}
	
	void Matrix3::rotate3D(const Vector3& v, float angle)
	{
		Matrix3 mat;
		mat.setRotation3D(v, angle);
		this->operator*=(mat);
	}

	void Matrix3::setRotationX(float angle)
	{
		float rad = (float)DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0] = 1.0f;	this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = c;		this->data[5] = s;
		this->data[6] = 0.0f;	this->data[7] = -s;		this->data[8] = c;
	}

	void Matrix3::setRotationY(float angle)
	{
		float rad = (float)DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0] = c;		this->data[1] = 0.0f;	this->data[2] = -s;
		this->data[3] = 0.0f;	this->data[4] = 1.0f;	this->data[5] = 0.0f;
		this->data[6] = s;		this->data[7] = 0.0f;	this->data[8] = c;
	}

	void Matrix3::setRotationZ(float angle)
	{
		float rad = (float)DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0] = c;		this->data[1] = s;		this->data[2] = 0.0f;
		this->data[3] = -s;		this->data[4] = c;		this->data[5] = 0.0f;
		this->data[6] = 0.0f;	this->data[7] = 0.0f;	this->data[8] = 1.0f;
	}

	void Matrix3::rotateX(float angle)
	{
		Matrix3 mat;
		mat.setRotationX(angle);
		this->operator*=(mat);
	}
	
	void Matrix3::rotateY(float angle)
	{
		Matrix3 mat;
		mat.setRotationY(angle);
		this->operator*=(mat);
	}
	
	void Matrix3::rotateZ(float angle)
	{
		Matrix3 mat;
		mat.setRotationZ(angle);
		this->operator*=(mat);
	}

	void Matrix3::setScale(float factor)
	{
		this->setScale(factor, factor, factor);
	}

	void Matrix3::setScale(float x, float y, float z)
	{
		this->data[0] = x;		this->data[1] = 0.0f;	this->data[2] = 0.0f;
		this->data[3] = 0.0f;	this->data[4] = y;		this->data[5] = 0.0f;
		this->data[6] = 0.0f;	this->data[7] = 0.0f;	this->data[8] = z;
	}

	void Matrix3::setScale(const Vector3& v)
	{
		this->setScale(v.x, v.y, v.z);
	}
	
	void Matrix3::scale(float factor)
	{
		Matrix3 mat;
		mat.setScale(factor);
		this->operator*=(mat);
	}
	
	void Matrix3::scale(float x, float y, float z)
	{
		Matrix3 mat;
		mat.setScale(x, y, z);
		this->operator*=(mat);
	}
	
	void Matrix3::scale(const Vector3& v)
	{
		Matrix3 mat;
		mat.setScale(v);
		this->operator*=(mat);
	}

	Matrix3 Matrix3::operator*=(float f)
	{
		*this = *this * f;
		return (*this);
	}

	Matrix3 Matrix3::operator*=(const Matrix3& m)
	{
		*this = *this * m;
		return (*this);
	}

	Matrix3 Matrix3::operator+=(const Matrix3& m)
	{
		*this = *this + m;
		return (*this);
	}

	Matrix3 Matrix3::operator-=(const Matrix3& m)
	{
		*this = *this - m;
		return (*this);
	}

}

