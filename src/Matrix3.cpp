/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include <math.h>

#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector3.h"
#include "util.h"

namespace gtypes
{

	Matrix3::Matrix3()
	{
		this->mat[0] = 1.0; this->mat[3] = 0.0; this->mat[6] = 0.0;
		this->mat[1] = 0.0; this->mat[4] = 1.0; this->mat[7] = 0.0;
		this->mat[2] = 0.0; this->mat[5] = 0.0; this->mat[8] = 1.0;
	}
	
	Matrix3::Matrix3(const Matrix3& m)
	{
                this->mat[0] = m.mat[0]; this->mat[3] = m.mat[3]; this->mat[6] = m.mat[6];
                this->mat[1] = m.mat[1]; this->mat[4] = m.mat[4]; this->mat[7] = m.mat[7];
                this->mat[2] = m.mat[2]; this->mat[5] = m.mat[5]; this->mat[8] = m.mat[8];
	}

        Matrix3::Matrix3(const Matrix4 &m)
        {
            this->mat[0] = m.mat[0]; this->mat[3] = m.mat[4]; this->mat[6] = m.mat[8];
            this->mat[1] = m.mat[1]; this->mat[4] = m.mat[5]; this->mat[7] = m.mat[9];
            this->mat[2] = m.mat[2]; this->mat[5] = m.mat[6]; this->mat[8] = m.mat[10];
        }
	
	Matrix3::Matrix3(float* m)
	{
		this->mat[0] = m[0]; this->mat[3] = m[3]; this->mat[6] = m[6];
		this->mat[1] = m[1]; this->mat[4] = m[4]; this->mat[7] = m[7];
		this->mat[2] = m[2]; this->mat[5] = m[5]; this->mat[8] = m[8];
	}
	
	Matrix3::Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8)
	{
		this->mat[0] = m0; this->mat[3] = m3; this->mat[6] = m6;
		this->mat[1] = m1; this->mat[4] = m4; this->mat[7] = m7;
		this->mat[2] = m2; this->mat[5] = m5; this->mat[8] = m8;
	}
	
	float Matrix3::det() const
	{
		return ((mat[0] * mat[4] * mat[8]) +
				(mat[3] * mat[7] * mat[2]) +
				(mat[6] * mat[1] * mat[5]) -
				(mat[6] * mat[4] * mat[2]) -
				(mat[3] * mat[1] * mat[8]) -
				(mat[0] * mat[7] * mat[5]));
	}
	
	Matrix3 Matrix3::inverse() const
	{
		float idet = 1.0f / det();
		return Matrix3((this->mat[4] * this->mat[8] - this->mat[7] * this->mat[5]) * idet,
					  -(this->mat[1] * this->mat[8] - this->mat[7] * this->mat[2]) * idet,
					   (this->mat[1] * this->mat[5] - this->mat[4] * this->mat[2]) * idet,
					  -(this->mat[3] * this->mat[8] - this->mat[6] * this->mat[5]) * idet,
					   (this->mat[0] * this->mat[8] - this->mat[6] * this->mat[2]) * idet,
					  -(this->mat[0] * this->mat[5] - this->mat[3] * this->mat[2]) * idet,
					   (this->mat[3] * this->mat[7] - this->mat[6] * this->mat[4]) * idet,
					  -(this->mat[0] * this->mat[7] - this->mat[6] * this->mat[1]) * idet,
					   (this->mat[0] * this->mat[4] - this->mat[3] * this->mat[1]) * idet);
	}
	
	Matrix3 Matrix3::transpose() const
	{
		return Matrix3(mat[0], mat[3], mat[6],
					   mat[1], mat[4], mat[7],
					   mat[2], mat[5], mat[8]);
	}
	
	Matrix3 Matrix3::rotationInverse2D() const
	{
		return Matrix3(this->mat[0], this->mat[3], 		0.0,
					   this->mat[1], this->mat[4], 		0.0,
								0.0, 		  0.0, 		1.0);
	}
	
	Matrix3 Matrix3::rotationInverse3D() const
	{
		return transpose();
	}
	
	void Matrix3::orthoNormalize()
	{
		gtypes::Vector3 x(mat[0],mat[1],mat[2]);
		gtypes::Vector3 y(mat[3],mat[4],mat[5]);
		gtypes::Vector3 z;
		x.normalise();
		z=x.cross(y);
		z.normalise();
		y=z.cross(x);
		y.normalise();
		mat[0] = x.x; mat[3] = y.x; mat[6] = z.x;
		mat[1] = x.y; mat[4] = y.y; mat[7] = z.y;
		mat[2] = x.z; mat[5] = y.z; mat[8] = z.z;
	}
	
	void Matrix3::setIdentity()
	{
		this->mat[0] = 1.0; this->mat[3] = 0.0; this->mat[6] = 0.0;
		this->mat[1] = 0.0; this->mat[4] = 1.0; this->mat[7] = 0.0;
		this->mat[2] = 0.0; this->mat[5] = 0.0; this->mat[8] = 1.0;
	}

	void Matrix3::setZero()
	{
		this->mat[0] = 0.0; this->mat[3] = 0.0; this->mat[6] = 0.0;
		this->mat[1] = 0.0; this->mat[4] = 0.0; this->mat[7] = 0.0;
		this->mat[2] = 0.0; this->mat[5] = 0.0; this->mat[8] = 0.0;
	}
	
	Matrix3 Matrix3::operator *(const Matrix3& m) const
	{
		return Matrix3(mat[0] * m[0] + mat[3] * m[1] + mat[6] * m[2],
					   mat[1] * m[0] + mat[4] * m[1] + mat[7] * m[2],
					   mat[2] * m[0] + mat[5] * m[1] + mat[8] * m[2],
					   mat[0] * m[3] + mat[3] * m[4] + mat[6] * m[5],
					   mat[1] * m[3] + mat[4] * m[4] + mat[7] * m[5],
					   mat[2] * m[3] + mat[5] * m[4] + mat[8] * m[5],
					   mat[0] * m[6] + mat[3] * m[7] + mat[6] * m[8],
					   mat[1] * m[6] + mat[4] * m[7] + mat[7] * m[8],
					   mat[2] * m[6] + mat[5] * m[7] + mat[8] * m[8]);
	}
	
	Matrix3 Matrix3::operator +(const Matrix3& m) const
	{
		return Matrix3(mat[0] + m[0], mat[1] + m[1], mat[2] + m[2],
					   mat[3] + m[3], mat[4] + m[4], mat[5] + m[5],
					   mat[6] + m[6], mat[7] + m[7], mat[8] + m[8]);
	}
	
	gtypes::Vector3 Matrix3::operator *(const gtypes::Vector3& v) const
	{
		return gtypes::Vector3(mat[0] * v.x + mat[3] * v.y + mat[6] * v.z,
							   mat[1] * v.x + mat[4] * v.y + mat[7] * v.z,
							   mat[2] * v.x + mat[5] * v.y + mat[8] * v.z);
	}
	
	Matrix3 Matrix3::operator*(float f) const
	{
		return Matrix3(mat[0] * f, mat[1] * f, mat[2] * f,
					   mat[3] * f, mat[4] * f, mat[5] * f,
					   mat[6] * f, mat[7] * f, mat[8] * f);
	}
	
	Matrix3 Matrix3::operator -(const Matrix3& m) const
	{
		return Matrix3(mat[0] - m[0], mat[1] - m[1], mat[2] - m[2],
					   mat[3] - m[3], mat[4] - m[4], mat[5] - m[5],
					   mat[6] - m[6], mat[7] - m[7], mat[8] - m[8]);
	}
	
	void Matrix3::setTranslation2D(float x, float y)
	{
		mat[2] = x;
		mat[5] = y;
	}
	
	void Matrix3::translate2D(float x, float y)
	{
		Matrix3 mat; mat.setTranslation2D(x,y);
		this->operator*=(mat);
	}
	
	void Matrix3::setRotation2D(float angle)
	{
		float rad = deg_to_rad(angle);
		mat[0] = cosf(rad); mat[1] = -sinf(rad);
		mat[3] = sinf(rad); mat[4] =  cosf(rad);
	}
	
	void Matrix3::rotate2D(float angle)
	{
		Matrix3 mat; mat.setRotation2D(angle);
		this->operator*=(mat);
	}
	
	void Matrix3::setRotation3D(float x, float y, float z, float angle)
	{
		float rad = deg_to_rad(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		float l = sqrtf(x * x + y * y + z * z);
		if(l < 0.000001f) l = 1.0f;
		else l = 1.0f / l;
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
		mat[0] = c1 * x * x + c;	mat[3] = c1 * xy - zs;		mat[6] = c1 * zx + ys;
		mat[1] = c1 * xy + zs;		mat[4] = c1 * y * y + c;	mat[7] = c1 * yz - xs;
		mat[2] = c1 * zx - ys;		mat[5] = c1 * yz + xs;		mat[8] = c1 * z * z + c;
	}
	
	void Matrix3::setRotation3D(gtypes::Vector3& v, float angle)
	{
		float rad = deg_to_rad(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		float l = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
		if(l < 0.000001f) l = 1.0f;
		else l = 1.0f / l;
		v.x *= l;
		v.y *= l;
		v.z *= l;
		float xy = v.x * v.y;
		float yz = v.y * v.z;
		float zx = v.z * v.x;
		float xs = v.x * s;
		float ys = v.y * s;
		float zs = v.z * s;
		float c1 = 1.0f - c;
		mat[0] = c1 * v.x * v.x + c;	mat[3] = c1 * xy - zs;			mat[6] = c1 * zx + ys;
		mat[1] = c1 * xy + zs;			mat[4] = c1 * v.y * v.y + c;	mat[7] = c1 * yz - xs;
		mat[2] = c1 * zx - ys;			mat[5] = c1 * yz + xs;			mat[8] = c1 * v.z * v.z + c;
	}
	
	void Matrix3::rotate3D(float x, float y, float z, float angle)
	{
		Matrix3 mat; mat.setRotation3D(x,y,z,angle);
		this->operator*=(mat);
	}
	
	void Matrix3::rotate3D(gtypes::Vector3 &v, float angle)
	{
		Matrix3 mat; mat.setRotation3D(v,angle);
		this->operator*=(mat);
	}

	void Matrix3::setRotationX(float angle)
	{
		float rad = deg_to_rad(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		mat[0] = 1.0; mat[3] = 0.0; mat[6] = 0.0;
		mat[1] = 0.0; mat[4] = c; mat[7] = -s;
		mat[2] = 0.0; mat[5] = s; mat[8] = c;
	}

	void Matrix3::setRotationY(float angle)
	{
		float rad = deg_to_rad(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		mat[0] = c; mat[3] = 0.0; mat[6] = s;
		mat[1] = 0.0; mat[4] = 1.0; mat[7] = 0.0;
		mat[2] = -s; mat[5] = 0.0; mat[8] = c;
	}

	void Matrix3::setRotationZ(float angle)
	{
		float rad = deg_to_rad(angle);
		float c = (float)cos(rad);
		float s = (float)sin(rad);
		mat[0] = c; mat[3] = -s; mat[6] = 0.0;
		mat[1] = s; mat[4] = c; mat[7] = 0.0;
		mat[2] = 0.0; mat[5] = 0.0; mat[8] = 1.0;
	}

	void Matrix3::rotateX(float angle)
	{
		Matrix3 mat; mat.setRotationX(angle);
		this->operator*=(mat);
	}
	
	void Matrix3::rotateY(float angle)
	{
		Matrix3 mat; mat.setRotationY(angle);
		this->operator*=(mat);
	}
	
	void Matrix3::rotateZ(float angle)
	{
		Matrix3 mat; mat.setRotationZ(angle);
		this->operator*=(mat);
	}

	void Matrix3::setScale(float factor)
	{
		setScale(factor, factor, factor);
	}

	void Matrix3::setScale(float x, float y, float z)
	{
		mat[0] = x; mat[3] = 0; mat[6] = 0;
		mat[1] = 0; mat[4] = y; mat[7] = 0;
		mat[2] = 0; mat[5] = 0; mat[8] = z;
	}

	void Matrix3::setScale(gtypes::Vector3& v)
	{
		setScale(v.x,v.y,v.z);
	}
	
	void Matrix3::scale(float factor)
	{
		Matrix3 mat; mat.setScale(factor);
		this->operator*=(mat);
	}
	
	void Matrix3::scale(float x, float y, float z)
	{
		Matrix3 mat; mat.setScale(x,y,z);
		this->operator*=(mat);
	}
	
	void Matrix3::scale(gtypes::Vector3 &v)
	{
		Matrix3 mat; mat.setScale(v);
		this->operator*=(mat);
	}

	void Matrix3::operator*=(float f)          { *this = *this *f; }
	void Matrix3::operator*=(const Matrix3 &m) { *this = *this * m; }
	void Matrix3::operator+=(const Matrix3 &m) { *this = *this + m; }
	void Matrix3::operator-=(const Matrix3 &m) { *this = *this - m; }

}

