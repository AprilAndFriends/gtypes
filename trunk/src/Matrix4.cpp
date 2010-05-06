/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "Matrix4.h"

#ifndef M_PI // msvc++ doesn't have this defined
#define M_PI           3.14159265358979323846
#endif

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
		this->mat[0] = m0; this->mat[4] = m4; this->mat[8]  = m8;  this->mat[12] = m12;
		this->mat[1] = m1; this->mat[5] = m5; this->mat[9]  = m9;  this->mat[13] = m13;
		this->mat[2] = m2; this->mat[6] = m6; this->mat[10] = m10; this->mat[14] = m14;
		this->mat[3] = m3; this->mat[7] = m7; this->mat[11] = m11; this->mat[15] = m15;
	}

	Matrix4::Matrix4(const Matrix3& m)
	{
		this->mat[0] = m[0]; this->mat[4] = m[3]; this->mat[8]  = m[6]; this->mat[12] = 0.0;
		this->mat[1] = m[1]; this->mat[5] = m[4]; this->mat[9]  = m[7]; this->mat[13] = 0.0;
		this->mat[2] = m[2]; this->mat[6] = m[5]; this->mat[10] = m[8]; this->mat[14] = 0.0;
		this->mat[3] = 0.0;  this->mat[7] = 0.0;  this->mat[11] = 0.0;  this->mat[15] = 1.0;
	}

	Matrix4::Matrix4(const Matrix4& m)
	{
		this->mat[0] = m[0]; this->mat[4] = m[4]; this->mat[8]  = m[8];  this->mat[12] = m[12];
		this->mat[1] = m[1]; this->mat[5] = m[5]; this->mat[9]  = m[9];  this->mat[13] = m[13];
		this->mat[2] = m[2]; this->mat[6] = m[6]; this->mat[10] = m[10]; this->mat[14] = m[14];
		this->mat[3] = m[3]; this->mat[7] = m[7]; this->mat[11] = m[11]; this->mat[15] = m[15];
	}

	Matrix4::Matrix4(float* m)
	{
		this->mat[0] = m[0]; this->mat[4] = m[4]; this->mat[8]  = m[8];  this->mat[12] = m[12];
		this->mat[1] = m[1]; this->mat[5] = m[5]; this->mat[9]  = m[9];  this->mat[13] = m[13];
		this->mat[2] = m[2]; this->mat[6] = m[6]; this->mat[10] = m[10]; this->mat[14] = m[14];
		this->mat[3] = m[3]; this->mat[7] = m[7]; this->mat[11] = m[11]; this->mat[15] = m[15];
	}

	void Matrix4::set(float  m0, float  m1, float  m2, float  m3,
		float  m4, float  m5, float  m6, float  m7,
		float  m8, float  m9, float m10, float m11,
		float m12, float m13, float m14, float m15)
	{
		*this=Matrix4(m0 ,m1 ,m2 ,m3,
					  m4 ,m5 ,m6 ,m7,
					  m8 ,m9 ,m10,m11,
					  m12,m13,m14,m15);
	}
	
	void Matrix4::set(float *m)
	{
		*this=Matrix4(m);
	}
	
	void Matrix4::set(const Matrix3& m)
	{
		*this=Matrix4(m);
	}
	
	void Matrix4::set(const Matrix4& m)
	{
		*this=m;
	}

	Matrix4::Matrix4(const gtypes::Vector3& axis, float angle)
	{
		float rad = angle*57.295779513082320876798154814105f;
		rotate(axis, rad);
	}

	Matrix4::Matrix4(float x, float y, float z, float angle)
	{
		float rad = angle*57.295779513082320876798154814105f;
		rotate(gtypes::Vector3(x,y,z), rad);
	}

	float Matrix4::det() const
	{
		return ((this->mat[0] * this->mat[5] * this->mat[10]) +
				(this->mat[4] * this->mat[9] * this->mat[2])  +
				(this->mat[8] * this->mat[1] * this->mat[6])  -
				(this->mat[8] * this->mat[5] * this->mat[2])  -
				(this->mat[4] * this->mat[1] * this->mat[10]) -
				(this->mat[0] * this->mat[9] * this->mat[6]));
	}

	Matrix4 Matrix4::getRotation() const
	{
		return Matrix4(this->mat[0], this->mat[1],  this->mat[2], 0,
					   this->mat[4], this->mat[5],  this->mat[6], 0,
					   this->mat[8], this->mat[9], this->mat[10], 0,
								  0, 			0, 			   0, 1);
	}

	void Matrix4::inverse()
	{
		float m[16];
		float idet = 1.0f / det();
		m[0]  =  (this->mat[5] * this->mat[10] - this->mat[9] * this->mat[6]) * idet;
		m[1]  = -(this->mat[1] * this->mat[10] - this->mat[9] * this->mat[2]) * idet;
		m[2]  =  (this->mat[1] * this->mat[6]  - this->mat[5] * this->mat[2]) * idet;
		m[3]  = 0.0;
		m[4]  = -(this->mat[4] * this->mat[10] - this->mat[8] * this->mat[6]) * idet;
		m[5]  =  (this->mat[0] * this->mat[10] - this->mat[8] * this->mat[2]) * idet;
		m[6]  = -(this->mat[0] * this->mat[6]  - this->mat[4] * this->mat[2]) * idet;
		m[7]  = 0.0;
		m[8]  =  (this->mat[4] * this->mat[9] - this->mat[8] * this->mat[5]) * idet;
		m[9]  = -(this->mat[0] * this->mat[9] - this->mat[8] * this->mat[1]) * idet;
		m[10] =  (this->mat[0] * this->mat[5] - this->mat[4] * this->mat[1]) * idet;
		m[11] = 0.0;
		m[12] = -(this->mat[12] * (m)[0] + this->mat[13] * (m)[4] + this->mat[14] * (m)[8]);
		m[13] = -(this->mat[12] * (m)[1] + this->mat[13] * (m)[5] + this->mat[14] * (m)[9]);
		m[14] = -(this->mat[12] * (m)[2] + this->mat[13] * (m)[6] + this->mat[14] * (m)[10]);
		m[15] = 1.0;
		
		set(m);
	}
	
	
	void Matrix4::inverseRotation()
	{
		set(this->mat[0],  this->mat[4],  this->mat[8],  this->mat[3],
			this->mat[1],  this->mat[5],  this->mat[9],  this->mat[7],
			this->mat[2],  this->mat[6],  this->mat[10], this->mat[11],
			this->mat[12], this->mat[13], this->mat[14], this->mat[15]);
	}
	
	Matrix4 Matrix4::inversed() const
	{
		Matrix4 mat(*this);
		mat.inverse();
		return mat;
	}
	
	Matrix4 Matrix4::inversedRotation() const
	{
		Matrix4 mat(*this);
		mat.inverseRotation();
		return mat;
	}
	
	void Matrix4::setZero()
	{
		this->mat[0] = 0.0; this->mat[4] = 0.0; this->mat[8] = 0.0; this->mat[12] = 0.0;
		this->mat[1] = 0.0; this->mat[5] = 0.0; this->mat[9] = 0.0; this->mat[13] = 0.0;
		this->mat[2] = 0.0; this->mat[6] = 0.0; this->mat[10] = 0.0; this->mat[14] = 0.0;
		this->mat[3] = 0.0; this->mat[7] = 0.0; this->mat[11] = 0.0; this->mat[15] = 0.0;
	}
	
	void Matrix4::setIdentity()
	{
		this->mat[0] = 1.0; this->mat[4] = 0.0; this->mat[8]  = 0.0; this->mat[12] = 0.0;
		this->mat[1] = 0.0; this->mat[5] = 1.0; this->mat[9]  = 0.0; this->mat[13] = 0.0;
		this->mat[2] = 0.0; this->mat[6] = 0.0; this->mat[10] = 1.0; this->mat[14] = 0.0;
		this->mat[3] = 0.0; this->mat[7] = 0.0; this->mat[11] = 0.0; this->mat[15] = 1.0;
	}

	
	void Matrix4::lookAt(const float* eye, const float* direction, const float* up)
	{
		lookAt(gtypes::Vector3(eye), gtypes::Vector3(direction), gtypes::Vector3(up));
	}
	
	void Matrix4::lookAt(const gtypes::Vector3 &eye, const gtypes::Vector3 &direction, const gtypes::Vector3 &up)
	{
		gtypes::Vector3 bx,by,bz;
		Matrix4 a,b;
		bz += eye;
		bz -= direction;
		bz.normalise();
		bx.cross(up,bz);
		bx.normalise();
		by.cross(bz,bx);
		by.normalise();
		a[0] = bx.x; a[4] = bx.y;  a[8] = bx.z; a[12] = 0.0;
		a[1] = by.x; a[5] = by.y;  a[9] = by.z; a[13] = 0.0;
		a[2] = bz.x; a[6] = bz.y; a[10] = bz.z; a[14] = 0.0;
		a[3] =  0.0; a[7] =  0.0; a[11] =  0.0; a[15] = 1.0;
		b.translate(-eye);
		*this = a * b;
	}
	
	Matrix4 Matrix4::operator *(const Matrix4& m) const
	{
		return Matrix4(this->mat[0] * m[0]  + this->mat[4] * m[1]  + this->mat[8]  * m[2]  + this->mat[12] * m[3],
					   this->mat[1] * m[0]  + this->mat[5] * m[1]  + this->mat[9]  * m[2]  + this->mat[13] * m[3],
					   this->mat[2] * m[0]  + this->mat[6] * m[1]  + this->mat[10] * m[2]  + this->mat[14] * m[3],
					   this->mat[3] * m[0]  + this->mat[7] * m[1]  + this->mat[11] * m[2]  + this->mat[15] * m[3],
					   this->mat[0] * m[4]  + this->mat[4] * m[5]  + this->mat[8]  * m[6]  + this->mat[12] * m[7],
					   this->mat[1] * m[4]  + this->mat[5] * m[5]  + this->mat[9]  * m[6]  + this->mat[13] * m[7],
					   this->mat[2] * m[4]  + this->mat[6] * m[5]  + this->mat[10] * m[6]  + this->mat[14] * m[7],
					   this->mat[3] * m[4]  + this->mat[7] * m[5]  + this->mat[11] * m[6]  + this->mat[15] * m[7],
					   this->mat[0] * m[8]  + this->mat[4] * m[9]  + this->mat[8]  * m[10] + this->mat[12] * m[11],
					   this->mat[1] * m[8]  + this->mat[5] * m[9]  + this->mat[9]  * m[10] + this->mat[13] * m[11],
					   this->mat[2] * m[8]  + this->mat[6] * m[9]  + this->mat[10] * m[10] + this->mat[14] * m[11],
					   this->mat[3] * m[8]  + this->mat[7] * m[9]  + this->mat[11] * m[10] + this->mat[15] * m[11],
					   this->mat[0] * m[12] + this->mat[4] * m[13] + this->mat[8]  * m[14] + this->mat[12] * m[15],
					   this->mat[1] * m[12] + this->mat[5] * m[13] + this->mat[9]  * m[14] + this->mat[13] * m[15],
					   this->mat[2] * m[12] + this->mat[6] * m[13] + this->mat[10] * m[14] + this->mat[14] * m[15],
					   this->mat[3] * m[12] + this->mat[7] * m[13] + this->mat[11] * m[14] + this->mat[15] * m[15]);
	}
	
	gtypes::Vector3 Matrix4::operator *(const gtypes::Vector3& v) const
	{
		return Vector3(this->mat[0] * v.x + this->mat[4] * v.y + this->mat[8]  * v.z + this->mat[12],
					   this->mat[1] * v.x + this->mat[5] * v.y + this->mat[9]  * v.z + this->mat[13],
					   this->mat[2] * v.x + this->mat[6] * v.y + this->mat[10] * v.z + this->mat[14]);
	}

	gtypes::Vector4 Matrix4::operator *(const gtypes::Vector4& v) const
	{
		return Vector4(this->mat[0] * v.x + this->mat[4] * v.y + this->mat[8]  * v.z + this->mat[12] * v.w,
					   this->mat[1] * v.x + this->mat[5] * v.y + this->mat[9]  * v.z + this->mat[13] * v.w,
					   this->mat[2] * v.x + this->mat[6] * v.y + this->mat[10] * v.z + this->mat[14] * v.w,
					   this->mat[3] * v.x + this->mat[7] * v.y + this->mat[11] * v.z + this->mat[15] * v.w);
	}
	
	Matrix4 Matrix4::operator *(float f) const
	{
		return Matrix4(this->mat[0]  * f, this->mat[1]  * f, this->mat[2]  * f, this->mat[3]  * f,
					   this->mat[4]  * f, this->mat[5]  * f, this->mat[6]  * f, this->mat[7]  * f,
					   this->mat[8]  * f, this->mat[9]  * f, this->mat[10] * f, this->mat[11] * f,
					   this->mat[12] * f, this->mat[13] * f, this->mat[14] * f, this->mat[15] * f);
	}
	
	Matrix4 Matrix4::operator +(const Matrix4& m) const
	{
		return Matrix4(this->mat[0]  + m[0],  this->mat[1]  + m[1],  this->mat[2]  + m[2],  this->mat[3]  + m[3],
					   this->mat[4]  + m[4],  this->mat[5]  + m[5],  this->mat[6]  + m[6],  this->mat[7]  + m[7],
					   this->mat[8]  + m[8],  this->mat[9]  + m[9],  this->mat[10] + m[10], this->mat[11] + m[11],
					   this->mat[12] + m[12], this->mat[13] + m[13], this->mat[14] + m[14], this->mat[15] + m[15]);
	}

	Matrix4 Matrix4::operator -(const Matrix4& m) const
	{
		return Matrix4(this->mat[0]  - m[0],  this->mat[1]  - m[1],  this->mat[2]  - m[2],  this->mat[3]  - m[3],
					   this->mat[4]  - m[4],  this->mat[5]  - m[5],  this->mat[6]  - m[6],  this->mat[7]  - m[7],
					   this->mat[8]  - m[8],  this->mat[9]  - m[9],  this->mat[10] - m[10], this->mat[11] - m[11],
					   this->mat[12] - m[12], this->mat[13] - m[13], this->mat[14] - m[14], this->mat[15] - m[15]);
	}

	Matrix4 gtypes::Matrix4::transpose() const
	{
		return Matrix4(this->mat[0], this->mat[4], this->mat[8],  this->mat[12],
					   this->mat[1], this->mat[5], this->mat[9],  this->mat[13],
					   this->mat[2], this->mat[6], this->mat[10], this->mat[14],
					   this->mat[3], this->mat[7], this->mat[11], this->mat[15]);
	}
	
	void Matrix4::translate(const gtypes::Vector3& v)
	{
		this->mat[0] = 1.0; this->mat[4] = 0.0; this->mat[8]  = 0.0; this->mat[12] = v.x;
		this->mat[1] = 0.0; this->mat[5] = 1.0; this->mat[9]  = 0.0; this->mat[13] = v.y;
		this->mat[2] = 0.0; this->mat[6] = 0.0; this->mat[10] = 1.0; this->mat[14] = v.z;
		this->mat[3] = 0.0; this->mat[7] = 0.0; this->mat[11] = 0.0; this->mat[15] = 1.0;
	}

	void Matrix4::translate(float x, float y, float z)
	{
		translate(gtypes::Vector3(x,y,z));
	}
	
	void Matrix4::scale(const gtypes::Vector3& v)
	{
		scale(v.x, v.y, v.z);
	}

	void Matrix4::scale(float factor)
	{
		*this = *this * factor;
	}

	void Matrix4::scale(float x, float y, float z)
	{
		this->mat[0] =   x; this->mat[4] = 0.0; this->mat[8]  = 0.0; this->mat[12] = 0.0;
		this->mat[1] = 0.0; this->mat[5] =   y; this->mat[9]  = 0.0; this->mat[13] = 0.0;
		this->mat[2] = 0.0; this->mat[6] = 0.0; this->mat[10] =   z; this->mat[14] = 0.0;
		this->mat[3] = 0.0; this->mat[7] = 0.0; this->mat[11] = 0.0; this->mat[15] = 1.0;
	}
	
	void Matrix4::perspective(float fov, float aspect, float near, float far)
	{
		float y = (float)tan(fov * M_PI / 360.0f);
		float x = y * aspect;
		this->mat[0] = 1.0f / x; this->mat[4] = 0.0;      this->mat[8] = 0.0;                               this->mat[12] = 0.0;
		this->mat[1] = 0.0;      this->mat[5] = 1.0f / y; this->mat[9] = 0.0;                               this->mat[13] = 0.0;
		this->mat[2] = 0.0;      this->mat[6] = 0.0;      this->mat[10] = -(far + near) / (far - near);   this->mat[14] = -(2.0f * far * near) / (far - near);
		this->mat[3] = 0.0;      this->mat[7] = 0.0;      this->mat[11] = -1.0;                             this->mat[15] = 0.0;
	}

	void gtypes::Matrix4::reflect(const gtypes::Vector4& plane)
	{
		float x = plane.x;
		float y = plane.y;
		float z = plane.z;
		float x2 = x * 2.0f;
		float y2 = y * 2.0f;
		float z2 = z * 2.0f;
		this->mat[0] = 1.0f - x * x2; this->mat[4] = -y * x2;       this->mat[8] = -z * x2;        this->mat[12] = -plane.w * x2;
		this->mat[1] = -x * y2;       this->mat[5] = 1.0f - y * y2; this->mat[9] = -z * y2;        this->mat[13] = -plane.w * y2;
		this->mat[2] = -x * z2;       this->mat[6] = -y * z2;       this->mat[10] = 1.0f - z * z2; this->mat[14] = -plane.w * z2;
		this->mat[3] = 0.0;           this->mat[7] = 0.0;           this->mat[11] = 0.0;           this->mat[15] = 1.0;
	}

	void gtypes::Matrix4::reflect(float x, float y, float z, float w)
	{
		reflect(gtypes::Vector4(x,y,z,w));
	}
	
	void gtypes::Matrix4::rotate(const gtypes::Vector3& axis, float angle)
	{
		float rad = angle*57.295779513082320876798154814105f;
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		Vector3 v = axis;
		v.normalise();
		float xx = v.x * v.x;
		float yy = v.y * v.y;
		float zz = v.z * v.z;
		float xy = v.x * v.y;
		float yz = v.y * v.z;
		float zx = v.z * v.x;
		float xs = v.x * s;
		float ys = v.y * s;
		float zs = v.z * s;
		this->mat[0] = (1.0f - c) * xx + c;  this->mat[4] = (1.0f - c) * xy - zs; this->mat[8] = (1.0f - c) * zx + ys; this->mat[12] = 0.0;
		this->mat[1] = (1.0f - c) * xy + zs; this->mat[5] = (1.0f - c) * yy + c;  this->mat[9] = (1.0f - c) * yz - xs; this->mat[13] = 0.0;
		this->mat[2] = (1.0f - c) * zx - ys; this->mat[6] = (1.0f - c) * yz + xs; this->mat[10] = (1.0f - c) * zz + c; this->mat[14] = 0.0;
		this->mat[3] = 0.0;                  this->mat[7] = 0.0;                  this->mat[11] = 0.0;                 this->mat[15] = 1.0;
	}

	void gtypes::Matrix4::rotate(float x, float y, float z, float angle)
	{
		rotate(gtypes::Vector3(x,y,z), angle);
	}

	void gtypes::Matrix4::rotateX(float angle)
	{
		float rad = angle*57.295779513082320876798154814105f;
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->mat[0] = 1.0; this->mat[4] = 0.0; this->mat[8]  = 0.0; this->mat[12] = 0.0;
		this->mat[1] = 0.0; this->mat[5] =  c;  this->mat[9]  = -s;  this->mat[13] = 0.0;
		this->mat[2] = 0.0; this->mat[6] =  s;  this->mat[10] =  c;  this->mat[14] = 0.0;
		this->mat[3] = 0.0; this->mat[7] = 0.0; this->mat[11] = 0.0; this->mat[15] = 1.0;
	}

	void gtypes::Matrix4::rotateY(float angle)
	{
		float rad = angle*57.295779513082320876798154814105f;
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->mat[0] =  c;  this->mat[4] = 0.0; this->mat[8]  =  s;  this->mat[12] = 0.0;
		this->mat[1] = 0.0; this->mat[5] = 1.0; this->mat[9]  = 0.0; this->mat[13] = 0.0;
		this->mat[2] = -s;  this->mat[6] = 0.0; this->mat[10] =  c;  this->mat[14] = 0.0;
		this->mat[3] = 0.0; this->mat[7] = 0.0; this->mat[11] = 0.0; this->mat[15] = 1.0;
	}

	void gtypes::Matrix4::rotateZ(float angle)
	{
		float rad = angle*57.295779513082320876798154814105f;
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		this->mat[0] =  c;  this->mat[4] = -s;  this->mat[8]  = 0.0; this->mat[12] = 0.0;
		this->mat[1] =  s;  this->mat[5] =  c;  this->mat[9]  = 0.0; this->mat[13] = 0.0;
		this->mat[2] = 0.0; this->mat[6] = 0.0; this->mat[10] = 1.0; this->mat[14] = 0.0;
		this->mat[3] = 0.0; this->mat[7] = 0.0; this->mat[11] = 0.0; this->mat[15] = 1.0;
	}

}
