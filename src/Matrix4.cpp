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
#include "Quaternion.h"
#include "Rectangle.h"
#include "Vector3.h"

namespace gtypes
{
	Matrix4::Matrix4()
	{
		this->setIdentity();
	}

	Matrix4::Matrix4(float  m0, float  m1, float  m2, float  m3,
					 float  m4, float  m5, float  m6, float  m7,
					 float  m8, float  m9, float m10, float m11,
					 float m12, float m13, float m14, float m15)
	{
		this->data[0]  =  m0;	this->data[1]  =  m1;	this->data[2]  =  m2;	this->data[3]  = m3;
		this->data[4]  =  m4;	this->data[5]  =  m5;	this->data[6]  =  m6;	this->data[7]  = m7;
		this->data[8]  =  m8;	this->data[9]  =  m9;	this->data[10] = m10;	this->data[11] = m11;
		this->data[12] = m12;	this->data[13] = m13;	this->data[14] = m14;	this->data[15] = m15;
	}

	Matrix4::Matrix4(float m[])
	{
		this->data[0]  = m[0];	this->data[1]  = m[1];	this->data[2]  = m[2];	this->data[3]  = m[3];
		this->data[4]  = m[4];	this->data[5]  = m[5];	this->data[6]  = m[6];	this->data[7]  = m[7];
		this->data[8]  = m[8];	this->data[9]  = m[9];	this->data[10] = m[10];	this->data[11] = m[11];
		this->data[12] = m[12];	this->data[13] = m[13];	this->data[14] = m[14];	this->data[15] = m[15];
	}

	Matrix4::Matrix4(const Matrix3& m)
	{
		this->data[0]  = m[0];	this->data[1]  = m[1];	this->data[2]  = m[2];	this->data[3]  = 0.0f;
		this->data[4]  = m[4];	this->data[5]  = m[5];	this->data[6]  = m[6];	this->data[7]  = 0.0f;
		this->data[8]  = m[8];	this->data[9]  = m[9];	this->data[10] = m[10];	this->data[11] = 0.0f;
		this->data[12] = 0.0f;	this->data[13] = 0.0f;	this->data[14] = 0.0f;	this->data[15] = 1.0f;
	}

	Matrix4::Matrix4(const Matrix4& m)
	{
		this->data[0]  = m[0];	this->data[1]  = m[1];	this->data[2]  = m[2];	this->data[3]  = m[3];
		this->data[4]  = m[4];	this->data[5]  = m[5];	this->data[6]  = m[6];	this->data[7]  = m[7];
		this->data[8]  = m[8];	this->data[9]  = m[9];	this->data[10] = m[10];	this->data[11] = m[11];
		this->data[12] = m[12];	this->data[13] = m[13];	this->data[14] = m[14];	this->data[15] = m[15];
	}

	void Matrix4::set(float  m0, float  m1, float  m2, float  m3,
					  float  m4, float  m5, float  m6, float  m7,
					  float  m8, float  m9, float m10, float m11,
					  float m12, float m13, float m14, float m15)
	{
		this->data[0]  =  m0;	this->data[1]  =  m1;	this->data[2]  =  m2;	this->data[3]  = m3;
		this->data[4]  =  m4;	this->data[5]  =  m5;	this->data[6]  =  m6;	this->data[7]  = m7;
		this->data[8]  =  m8;	this->data[9]  =  m9;	this->data[10] = m10;	this->data[11] = m11;
		this->data[12] = m12;	this->data[13] = m13;	this->data[14] = m14;	this->data[15] = m15;
	}
	
	void Matrix4::set(float m[])
	{
		this->data[0]  = m[0];	this->data[1]  = m[1];	this->data[2]  = m[2];	this->data[3]  = m[3];
		this->data[4]  = m[4];	this->data[5]  = m[5];	this->data[6]  = m[6];	this->data[7]  = m[7];
		this->data[8]  = m[8];	this->data[9]  = m[9];	this->data[10] = m[10];	this->data[11] = m[11];
		this->data[12] = m[12];	this->data[13] = m[13];	this->data[14] = m[14];	this->data[15] = m[15];
	}
	
	void Matrix4::set(const Matrix3& m)
	{
		this->data[0]  = m[0];	this->data[1]  = m[1];	this->data[2]  = m[2];	this->data[3]  = 0.0f;
		this->data[4]  = m[4];	this->data[5]  = m[5];	this->data[6]  = m[6];	this->data[7]  = 0.0f;
		this->data[8]  = m[8];	this->data[9]  = m[9];	this->data[10] = m[10];	this->data[11] = 0.0f;
		this->data[12] = 0.0f;	this->data[13] = 0.0f;	this->data[14] = 0.0f;	this->data[15] = 1.0f;
	}
	
	void Matrix4::set(const Matrix4& m)
	{
		this->data[0]  = m[0];	this->data[1]  = m[1];	this->data[2]  = m[2];	this->data[3]  = m[3];
		this->data[4]  = m[4];	this->data[5]  = m[5];	this->data[6]  = m[6];	this->data[7]  = m[7];
		this->data[8]  = m[8];	this->data[9]  = m[9];	this->data[10] = m[10];	this->data[11] = m[11];
		this->data[12] = m[12];	this->data[13] = m[13];	this->data[14] = m[14];	this->data[15] = m[15];
	}

	Matrix4::Matrix4(const Vector3& axis, float angle)
	{
		this->setRotation(axis.x, axis.y, axis.z, (float)DEG_TO_RAD(angle));
	}

	Matrix4::Matrix4(float x, float y, float z, float angle)
	{
		this->setRotation(x, y, z, (float)DEG_TO_RAD(angle));
	}

	float Matrix4::det() const
	{
		return ((this->data[0] * this->data[5] * this->data[10]) +
				(this->data[4] * this->data[9] * this->data[2])  +
				(this->data[8] * this->data[1] * this->data[6])  -
				(this->data[8] * this->data[5] * this->data[2])  -
				(this->data[4] * this->data[1] * this->data[10]) -
				(this->data[0] * this->data[9] * this->data[6]));
	}

	Matrix4 Matrix4::getRotation() const
	{
		return Matrix4(this->data[0],	this->data[1],	this->data[2],	0.0f,
					   this->data[4],	this->data[5],	this->data[6],	0.0f,
					   this->data[8],	this->data[9],	this->data[10],	0.0f,
								0.0f,			 0.0f,			  0.0f,	1.0f);
	}

	void Matrix4::inverse()
	{
		float m[16] = {0};
		float idet = 1.0f / det();
		m[0]  =  (this->data[5] * this->data[10] - this->data[9] * this->data[6]) * idet;
		m[1]  = -(this->data[1] * this->data[10] - this->data[9] * this->data[2]) * idet;
		m[2]  =  (this->data[1] * this->data[6]  - this->data[5] * this->data[2]) * idet;
		m[3]  = 0.0f;
		m[4]  = -(this->data[4] * this->data[10] - this->data[8] * this->data[6]) * idet;
		m[5]  =  (this->data[0] * this->data[10] - this->data[8] * this->data[2]) * idet;
		m[6]  = -(this->data[0] * this->data[6]  - this->data[4] * this->data[2]) * idet;
		m[7]  = 0.0f;
		m[8]  =  (this->data[4] * this->data[9] - this->data[8] * this->data[5]) * idet;
		m[9]  = -(this->data[0] * this->data[9] - this->data[8] * this->data[1]) * idet;
		m[10] =  (this->data[0] * this->data[5] - this->data[4] * this->data[1]) * idet;
		m[11] = 0.0f;
		m[12] = -(this->data[12] * m[0] + this->data[13] * m[4] + this->data[14] * m[8]);
		m[13] = -(this->data[12] * m[1] + this->data[13] * m[5] + this->data[14] * m[9]);
		m[14] = -(this->data[12] * m[2] + this->data[13] * m[6] + this->data[14] * m[10]);
		m[15] = 1.0f;
		this->set(m);
	}
	
	Matrix4 Matrix4::inversed() const
	{
		Matrix4 mat(*this);
		mat.inverse();
		return mat;
	}
	
	void Matrix4::transpose()
	{
		this->set(this->data[0], this->data[4], this->data[8],  this->data[12],
				  this->data[1], this->data[5], this->data[9],  this->data[13],
				  this->data[2], this->data[6], this->data[10], this->data[14],
				  this->data[3], this->data[7], this->data[11], this->data[15]);
	}
	
	Matrix4 Matrix4::transposed() const
	{
		Matrix4 mat(*this);
		mat.transpose();
		return mat;
	}
	
	void Matrix4::inverseRotation()
	{
		this->set(this->data[0],  this->data[4],  this->data[8],  this->data[3],
				  this->data[1],  this->data[5],  this->data[9],  this->data[7],
				  this->data[2],  this->data[6],  this->data[10], this->data[11],
				  this->data[12], this->data[13], this->data[14], this->data[15]);
	}
	
	Matrix4 Matrix4::inversedRotation() const
	{
		Matrix4 mat(*this);
		mat.inverseRotation();
		return mat;
	}
	
	void Matrix4::setZero()
	{
		this->data[0]  = 0.0f; this->data[1]  = 0.0f; this->data[2]  = 0.0f; this->data[3]  = 0.0f;
		this->data[4]  = 0.0f; this->data[5]  = 0.0f; this->data[6]  = 0.0f; this->data[7]  = 0.0f;
		this->data[8]  = 0.0f; this->data[9]  = 0.0f; this->data[10] = 0.0f; this->data[11] = 0.0f;
		this->data[12] = 0.0f; this->data[13] = 0.0f; this->data[14] = 0.0f; this->data[15] = 0.0f;
	}
	
	void Matrix4::setIdentity()
	{
		this->data[0]  = 1.0f; this->data[1]  = 0.0f; this->data[2]  = 0.0f; this->data[3]  = 0.0f;
		this->data[4]  = 0.0f; this->data[5]  = 1.0f; this->data[6]  = 0.0f; this->data[7]  = 0.0f;
		this->data[8]  = 0.0f; this->data[9]  = 0.0f; this->data[10] = 1.0f; this->data[11] = 0.0f;
		this->data[12] = 0.0f; this->data[13] = 0.0f; this->data[14] = 0.0f; this->data[15] = 1.0f;
	}

	
	void Matrix4::lookAt(const float* eye, const float* target, const float* up)
	{
		this->lookAt(Vector3(eye), Vector3(target), Vector3(up));
	}
	
	void Matrix4::lookAt(const Vector3& eye, const Vector3& target, const Vector3& up)
	{
		Vector3 bz = (eye - target).normalized();
		Vector3 bx = up.cross(bz).normalized();
		Vector3 by = bz.cross(bx).normalized();
		Matrix4 a;
		a[0]  = bx.x; a[1]  = by.x; a[2]  = bz.x; a[3]  = 0.0f;
		a[4]  = bx.y; a[5]  = by.y; a[6]  = bz.y; a[7]  = 0.0f;
		a[8]  = bx.z; a[9]  = by.z; a[10] = bz.z; a[11] = 0.0f;
		a[12] = 0.0f; a[13] = 0.0f; a[14] = 0.0f; a[15] = 1.0f;
		Matrix4 b;
		b.setTranslation(-eye);
		*this = a * b;
	}
	
	Matrix4 Matrix4::operator*(const Matrix4& m) const
	{
		return Matrix4(this->data[0] * m[0]  + this->data[4] * m[1]  + this->data[8]  * m[2]  + this->data[12] * m[3],
					   this->data[1] * m[0]  + this->data[5] * m[1]  + this->data[9]  * m[2]  + this->data[13] * m[3],
					   this->data[2] * m[0]  + this->data[6] * m[1]  + this->data[10] * m[2]  + this->data[14] * m[3],
					   this->data[3] * m[0]  + this->data[7] * m[1]  + this->data[11] * m[2]  + this->data[15] * m[3],
					   this->data[0] * m[4]  + this->data[4] * m[5]  + this->data[8]  * m[6]  + this->data[12] * m[7],
					   this->data[1] * m[4]  + this->data[5] * m[5]  + this->data[9]  * m[6]  + this->data[13] * m[7],
					   this->data[2] * m[4]  + this->data[6] * m[5]  + this->data[10] * m[6]  + this->data[14] * m[7],
					   this->data[3] * m[4]  + this->data[7] * m[5]  + this->data[11] * m[6]  + this->data[15] * m[7],
					   this->data[0] * m[8]  + this->data[4] * m[9]  + this->data[8]  * m[10] + this->data[12] * m[11],
					   this->data[1] * m[8]  + this->data[5] * m[9]  + this->data[9]  * m[10] + this->data[13] * m[11],
					   this->data[2] * m[8]  + this->data[6] * m[9]  + this->data[10] * m[10] + this->data[14] * m[11],
					   this->data[3] * m[8]  + this->data[7] * m[9]  + this->data[11] * m[10] + this->data[15] * m[11],
					   this->data[0] * m[12] + this->data[4] * m[13] + this->data[8]  * m[14] + this->data[12] * m[15],
					   this->data[1] * m[12] + this->data[5] * m[13] + this->data[9]  * m[14] + this->data[13] * m[15],
					   this->data[2] * m[12] + this->data[6] * m[13] + this->data[10] * m[14] + this->data[14] * m[15],
					   this->data[3] * m[12] + this->data[7] * m[13] + this->data[11] * m[14] + this->data[15] * m[15]);
	}
	
	Vector3 Matrix4::operator*(const Vector3& v) const
	{
		return Vector3(this->data[0] * v.x + this->data[4] * v.y + this->data[8]  * v.z + this->data[12],
					   this->data[1] * v.x + this->data[5] * v.y + this->data[9]  * v.z + this->data[13],
					   this->data[2] * v.x + this->data[6] * v.y + this->data[10] * v.z + this->data[14]);
	}

	Quaternion Matrix4::operator*(const Quaternion& v) const
	{
		return Quaternion(this->data[0] * v.x + this->data[4] * v.y + this->data[8]  * v.z + this->data[12] * v.w,
						  this->data[1] * v.x + this->data[5] * v.y + this->data[9]  * v.z + this->data[13] * v.w,
						  this->data[2] * v.x + this->data[6] * v.y + this->data[10] * v.z + this->data[14] * v.w,
						  this->data[3] * v.x + this->data[7] * v.y + this->data[11] * v.z + this->data[15] * v.w);
	}
	
	Matrix4 Matrix4::operator*(float f) const
	{
		return Matrix4(this->data[0]  * f, this->data[1]  * f, this->data[2]  * f, this->data[3]  * f,
					   this->data[4]  * f, this->data[5]  * f, this->data[6]  * f, this->data[7]  * f,
					   this->data[8]  * f, this->data[9]  * f, this->data[10] * f, this->data[11] * f,
					   this->data[12] * f, this->data[13] * f, this->data[14] * f, this->data[15] * f);
	}
	
	Matrix4 Matrix4::operator+(const Matrix4& m) const
	{
		return Matrix4(this->data[0]  + m[0],  this->data[1]  + m[1],  this->data[2]  + m[2],  this->data[3]  + m[3],
					   this->data[4]  + m[4],  this->data[5]  + m[5],  this->data[6]  + m[6],  this->data[7]  + m[7],
					   this->data[8]  + m[8],  this->data[9]  + m[9],  this->data[10] + m[10], this->data[11] + m[11],
					   this->data[12] + m[12], this->data[13] + m[13], this->data[14] + m[14], this->data[15] + m[15]);
	}

	Matrix4 Matrix4::operator-(const Matrix4& m) const
	{
		return Matrix4(this->data[0]  - m[0],  this->data[1]  - m[1],  this->data[2]  - m[2],  this->data[3]  - m[3],
					   this->data[4]  - m[4],  this->data[5]  - m[5],  this->data[6]  - m[6],  this->data[7]  - m[7],
					   this->data[8]  - m[8],  this->data[9]  - m[9],  this->data[10] - m[10], this->data[11] - m[11],
					   this->data[12] - m[12], this->data[13] - m[13], this->data[14] - m[14], this->data[15] - m[15]);
	}

	void Matrix4::setTranslation(float x, float y, float z)
	{
		this->data[0]  = 1.0f;	this->data[1]  = 0.0f;	this->data[2]  = 0.0f;	this->data[3]  = 0.0f;
		this->data[4]  = 0.0f;	this->data[5]  = 1.0f;	this->data[6]  = 0.0f;	this->data[7]  = 0.0f;
		this->data[8]  = 0.0f;	this->data[9]  = 0.0f;	this->data[10] = 1.0f;	this->data[11] = 0.0f;
		this->data[12] = x;		this->data[13] = y;		this->data[14] = z;		this->data[15] = 1.0f;
	}

	void Matrix4::setTranslation(const Vector3& v)
	{
		this->data[0]  = 1.0f;	this->data[1]  = 0.0f;	this->data[2]  = 0.0f;	this->data[3]  = 0.0f;
		this->data[4]  = 0.0f;	this->data[5]  = 1.0f;	this->data[6]  = 0.0f;	this->data[7]  = 0.0f;
		this->data[8]  = 0.0f;	this->data[9]  = 0.0f;	this->data[10] = 1.0f;	this->data[11] = 0.0f;
		this->data[12] = v.x;	this->data[13] = v.y;	this->data[14] = v.z;	this->data[15] = 1.0f;
	}
	
	void Matrix4::translate(const Vector3& v)
	{
		Matrix4 mat;
		mat.setTranslation(v);
		this->operator*=(mat);
	}

	void Matrix4::translate(float x, float y, float z)
	{
		Matrix4 mat;
		mat.setTranslation(x, y, z);
		this->operator*=(mat);
	}
	
	void Matrix4::setScale(float x, float y, float z)
	{
		this->data[0]  =	x; this->data[1]  = 0.0f; this->data[2]  = 0.0f; this->data[3]  = 0.0f;
		this->data[4]  = 0.0f; this->data[5]  =	y; this->data[6]  = 0.0f; this->data[7]  = 0.0f;
		this->data[8]  = 0.0f; this->data[9]  = 0.0f; this->data[10] =	z; this->data[11] = 0.0f;
		this->data[12] = 0.0f; this->data[13] = 0.0f; this->data[14] = 0.0f; this->data[15] = 1.0f;
	}
	
	void Matrix4::setScale(float factor)
	{
		this->setScale(factor, factor, factor);
	}

	void Matrix4::setScale(const Vector3& v)
	{
		this->setScale(v.x, v.y, v.z);
	}

	void Matrix4::scale(float factor)
	{
		Matrix4 mat;
		mat.setScale(factor);
		this->operator*=(mat);
	}
	
	void Matrix4::scale(float x, float y, float z)
	{
		Matrix4 mat;
		mat.setScale(x, y, z);
		this->operator*=(mat);
	}
	
	void Matrix4::scale(const Vector3& v)
	{
		Matrix4 mat;
		mat.setScale(v);
		this->operator*=(mat);
	}

	void Matrix4::perspective(float fov, float aspect, float near, float far)
	{
		float iy = 1.0f / ((float)tan(DEG_TO_RAD(fov * 0.5f)));
		float ix = iy * aspect;
		this->data[0]  = 1.0f * ix;	this->data[1]  = 0.0f;		this->data[2]  = 0.0f;									this->data[3]  = 0.0f;
		this->data[4]  = 0.0f;		this->data[5]  = 1.0f * iy;	this->data[6]  = 0.0f;									this->data[7]  = 0.0f;
		this->data[8]  = 0.0f;		this->data[9]  = 0.0f;		this->data[10] = -(far + near) / (far - near);			this->data[11] = -1.0f;
		this->data[12] = 0.0f;		this->data[13] = 0.0f;		this->data[14] = -(2.0f * far * near) / (far - near);	this->data[15] = 0.0f;
	}
	
	void Matrix4::ortho(const Rectangle& rect)
	{
		this->setIdentity();
		this->data[0] = 2 / rect.w;
		this->data[5] = -2 / rect.h;
		this->data[10] = -2;
		this->data[12] = -1 + rect.x * 2 / rect.w;
		this->data[13] = 1 - rect.y * 2 / rect.h;
	}

	void Matrix4::setReflection(float x, float y, float z, float w)
	{
		float x2 = x * 2.0f;
		float y2 = y * 2.0f;
		float z2 = z * 2.0f;
		this->data[0]  = 1.0f - x * x2;	this->data[1]  = -x * y2;		this->data[2]  = -x * z2;		this->data[3] = 0.0f;
		this->data[4]  = -y * x2;		this->data[5]  = 1.0f - y * y2;	this->data[6]  = -y * z2;		this->data[7] = 0.0f;
		this->data[8]  = -z * x2;		this->data[9]  = -z * y2;		this->data[10] = 1.0f - z * z2;	this->data[11] = 0.0f;
		this->data[12] = -w * x2;		this->data[13] = -w * y2;		this->data[14] = -w * z2;		this->data[15] = 1.0f;
	}

	void Matrix4::reflect(float x, float y, float z, float w)
	{
		Matrix4 mat;
		mat.setReflection(x, y, z, w);
		this->operator*=(mat);
	}

	void Matrix4::setRotation(float x, float y, float z, float angle)
	{
		this->setRotation(Vector3(x, y, z), angle);
	}

	void Matrix4::setRotation(const Vector3& axis, float angle)
	{
		double rad = DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		Vector3 v = axis.normalized();
		float xx = v.x * v.x;
		float yy = v.y * v.y;
		float zz = v.z * v.z;
		float xy = v.x * v.y;
		float yz = v.y * v.z;
		float zx = v.z * v.x;
		float xs = v.x * s;
		float ys = v.y * s;
		float zs = v.z * s;
		this->data[0] = (1.0f - c) * xx + c;  this->data[4] = (1.0f - c) * xy - zs; this->data[8] = (1.0f - c) * zx + ys; this->data[12] = 0.0;
		this->data[1] = (1.0f - c) * xy + zs; this->data[5] = (1.0f - c) * yy + c;  this->data[9] = (1.0f - c) * yz - xs; this->data[13] = 0.0;
		this->data[2] = (1.0f - c) * zx - ys; this->data[6] = (1.0f - c) * yz + xs; this->data[10] = (1.0f - c) * zz + c; this->data[14] = 0.0;
		this->data[3] = 0.0;                  this->data[7] = 0.0;                  this->data[11] = 0.0;                 this->data[15] = 1.0;
	}

	void Matrix4::setRotationX(float angle)
	{
		double rad = DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0]  = 1.0f; this->data[1]  = 0.0f; this->data[2]  = 0.0f; this->data[3]  = 0.0f;
		this->data[4]  = 0.0f; this->data[5]  =	   c; this->data[6]  =    s; this->data[7]  = 0.0f;
		this->data[8]  = 0.0f; this->data[9]  =   -s; this->data[10] =    c; this->data[11] = 0.0f;
		this->data[12] = 0.0f; this->data[13] = 0.0f; this->data[14] = 0.0f; this->data[15] = 1.0f;
	}

	void Matrix4::setRotationY(float angle)
	{
		double rad = DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0]  =    c; this->data[1]  = 0.0f; this->data[2]  =   -s; this->data[3]  = 0.0f;
		this->data[4]  = 0.0f; this->data[5]  = 1.0f; this->data[6]  = 0.0f; this->data[7]  = 0.0f;
		this->data[8]  =    s; this->data[9]  = 0.0f; this->data[10] =    c; this->data[11] = 0.0f;
		this->data[12] = 0.0f; this->data[13] = 0.0f; this->data[14] = 0.0f; this->data[15] = 1.0f;
	}

	void Matrix4::setRotationZ(float angle)
	{
		double rad = DEG_TO_RAD(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->data[0]  =    c; this->data[1]  =    s; this->data[2]  = 0.0f; this->data[3]  = 0.0f;
		this->data[4]  =   -s; this->data[5]  =    c; this->data[6]  = 0.0f; this->data[7]  = 0.0f;
		this->data[8]  = 0.0f; this->data[9]  = 0.0f; this->data[10] = 1.0f; this->data[11] = 0.0f;
		this->data[12] = 0.0f; this->data[13] = 0.0f; this->data[14] = 0.0f; this->data[15] = 1.0f;
	}
	
	void Matrix4::rotate(const Vector3 &axis, float angle)
	{
		Matrix4 mat;
		mat.setRotation(axis,angle);
		this->operator*=(mat);
	}

	void Matrix4::rotate(float x, float y, float z, float angle)
	{
		Matrix4 mat;
		mat.setRotation(x, y, z, angle);
		this->operator*=(mat);
	}

	void Matrix4::rotateX(float angle)
	{
		Matrix4 mat;
		mat.setRotationX(angle);
		this->operator*=(mat);
	}

	void Matrix4::rotateY(float angle)
	{
		Matrix4 mat;
		mat.setRotationY(angle);
		this->operator*=(mat);		
	}

	void Matrix4::rotateZ(float angle)
	{
		Matrix4 mat;
		mat.setRotationZ(angle);
		this->operator*=(mat);
	}
	
	Matrix4 Matrix4::operator*=(float f)
	{
		*this = *this * f;
		return (*this);
	}

	Matrix4 Matrix4::operator*=(const Matrix4& m)
	{
		*this = *this * m;
		return (*this);
	}

	Matrix4 Matrix4::operator+=(const Matrix4& m)
	{
		*this = *this + m;
		return (*this);
	}

	Matrix4 Matrix4::operator-=(const Matrix4& m)
	{
		*this = *this - m;
		return (*this);
	}

}
