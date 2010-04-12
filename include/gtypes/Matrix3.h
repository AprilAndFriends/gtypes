/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_MATRIX3
#define GTYPES_MATRIX3

#include "Vector3.h"


namespace gtypes
{
	class Matrix4;

	class Matrix3
	{
		
	public:
	
		float mat[9];
	
		Matrix3();
		Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
		Matrix3(float *m);
		Matrix3(const Matrix3 &m);
		Matrix3(const gtypes::Matrix4 &m);
		
		Matrix3 operator +(const Matrix3 &m) const;
		Matrix3 operator -(const Matrix3 &m) const;
		Matrix3 operator *(const Matrix3 &m) const;
		
		operator float*() { return mat; }
		operator const float*() const { return mat; }

		float &operator[](int i) { return mat[i]; }
		const float operator[](int i) const { return mat[i]; }
		
		Matrix3 &operator*=(float f) { return *this = *this *f; }
		Matrix3 &operator*=(const Matrix3 &m) { return *this = *this * m; }
		Matrix3 &operator+=(const Matrix3 &m) { return *this = *this + m; }
		Matrix3 &operator-=(const Matrix3 &m) { return *this = *this - m; }
		
		gtypes::Vector3 operator *(const gtypes::Vector3 &v) const;
		Matrix3 operator *(float f) const;
		
		Matrix3 transpose() const;
		Matrix3 inverse() const;
		
		float det() const;
		
		void setIdentity();
		void setZero();
		
		Matrix3 rotationInverse2D() const;
		Matrix3 rotationInverse3D() const;
		
		void rotate2D(float angle);
		void rotate3D(float x, float y, float z, float angle);
		void rotate3D(gtypes::Vector3 &v, float angle);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		
		void scale(float factor);
		void scale(float x, float y, float z);
		void scale(gtypes::Vector3 &v);
		
		void translate2D(float x, float y);
		
		void orthoNormalize();

	};

}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::Matrix3 mat3;
}

#endif // GTYPES_ABREV

#endif // GTYPES_MATRIX3
