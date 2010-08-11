/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_MATRIX4
#define GTYPES_MATRIX4

#include <math.h>
#include "Vector4.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "gtypesExport.h"

namespace gtypes
{

	class gtypesExport Matrix4
	{
	public:
	
		float mat[16];

		Matrix4();
		Matrix4(float  m0, float  m1, float  m2, float  m3,
				float  m4, float  m5, float  m6, float  m7,
				float  m8, float  m9, float m10, float m11,
				float m12, float m13, float m14, float m15);
		Matrix4(float *m);
		Matrix4(const Matrix3 &m);
		Matrix4(const Matrix4 &m);
		Matrix4(const gtypes::Vector3 &axis, float angle);
		Matrix4(float x, float y, float z, float angle);
		
		void set(float  m0, float  m1, float  m2, float  m3,
			float  m4, float  m5, float  m6, float  m7,
			float  m8, float  m9, float m10, float m11,
			float m12, float m13, float m14, float m15);
		void set(float *m);
		void set(const Matrix3& m);
		void set(const Matrix4& m);
		
		gtypes::Vector3 operator *(const gtypes::Vector3 &v) const;
		gtypes::Vector4 operator *(const gtypes::Vector4 &v) const;
		
		void operator*=(float f);
		void operator*=(const Matrix4 &m);
		void operator+=(const Matrix4 &m);
		void operator-=(const Matrix4 &m);

		operator float*() { return this->mat; }
		operator const float*() const { return this->mat; }

		float &operator[](int i) { return this->mat[i]; }
		const float operator[](int i) const { return this->mat[i]; }
		
		Matrix4 operator*(const Matrix4 &m) const;
		Matrix4 operator*(float f) const;
		Matrix4 operator+(const Matrix4 &m) const;
		Matrix4 operator-(const Matrix4 &m) const;
		
		Matrix4 getRotation() const;
		Matrix4 transpose() const;
		float det() const;
		Matrix4 inversed() const;
		Matrix4 inversedRotation() const;
	
		void inverse();
		void inverseRotation();
		
		void setZero();
		void setIdentity();
		
		void setRotation(const gtypes::Vector3 &axis, float angle);
		void setRotation(float x, float y, float z, float angle);
		void setRotationX(float angle);
		void setRotationY(float angle);
		void setRotationZ(float angle);
		void rotate(const gtypes::Vector3 &axis, float angle);
		void rotate(float x, float y, float z, float angle);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		
		void setScale(float factor);
		void setScale(float x, float y, float z);
		void setScale(const gtypes::Vector3 &v);
		void scale(float factor);
		void scale(float x, float y, float z);
		void scale(const gtypes::Vector3 &v);
		
		void setTranslation(const gtypes::Vector3 &v);
		void setTranslation(float x, float y, float z);
		void translate(const gtypes::Vector3 &v);
		void translate(float x, float y, float z);
		
		void setReflection(const gtypes::Vector4 &plane);
		void setReflection(float x, float y, float z, float w);
		void reflect(const gtypes::Vector4 &plane);
		void reflect(float x, float y, float z, float w);
		
		void perspective(float fov, float aspect, float near, float far);
		void ortho(float w,float h,float x_offset=0,float y_offset=0);
		
		void lookAt(const gtypes::Vector3 &eye, const gtypes::Vector3 &target, const gtypes::Vector3 &up);
		void lookAt(const float *eye, const float *target, const float *up);
		
	};

}

#ifdef GTYPES_ABREV

typedef gtypes::Matrix4 gmat4;

#endif // GTYPES_ABREV

#endif // GTYPES_MATRIX4
