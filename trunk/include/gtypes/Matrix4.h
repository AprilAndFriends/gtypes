/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.4
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// DOCUMENT ME

#ifndef GTYPES_MATRIX4_H
#define GTYPES_MATRIX4_H

#include "gtypesExport.h"

namespace gtypes
{
	class Matrix3;
	class Rectangle;
	class Vector3;
	class Quaternion;

	class gtypesExport Matrix4
	{
	public:
		float data[16];

		Matrix4();
		Matrix4(float  m0, float  m1, float  m2, float  m3,
				float  m4, float  m5, float  m6, float  m7,
				float  m8, float  m9, float m10, float m11,
				float m12, float m13, float m14, float m15);
		Matrix4(float m[]);
		Matrix4(const Matrix3& m);
		Matrix4(const Matrix4& m);
		Matrix4(float x, float y, float z, float angle);
		Matrix4(const Vector3& axis, float angle);
		
		void set(float  m0, float  m1, float  m2, float  m3,
				 float  m4, float  m5, float  m6, float  m7,
				 float  m8, float  m9, float m10, float m11,
				 float m12, float m13, float m14, float m15);
		void set(float m[]);
		void set(const Matrix3& m);
		void set(const Matrix4& m);
		
		Vector3 operator*(const Vector3& v) const;
		Quaternion operator*(const Quaternion& v) const;
		
		Matrix4 operator*=(float f);
		Matrix4 operator*=(const Matrix4& m);
		Matrix4 operator+=(const Matrix4& m);
		Matrix4 operator-=(const Matrix4& m);

		operator float*() { return this->data; }
		operator const float*() const { return this->data; }

		float &operator[](int i) { return this->data[i]; }
		const float operator[](int i) const { return this->data[i]; }
		
		Matrix4 operator*(const Matrix4& m) const;
		Matrix4 operator*(float f) const;
		Matrix4 operator+(const Matrix4& m) const;
		Matrix4 operator-(const Matrix4& m) const;
		
		Matrix4 getRotation() const;
		void transpose();
		Matrix4 transposed() const;
		float det() const;
		void inverse();
		Matrix4 inversed() const;
		void inverseRotation();
		Matrix4 inversedRotation() const;
		
		void setZero();
		void setIdentity();
		
		void setRotation(float x, float y, float z, float angle);
		void setRotation(const Vector3& axis, float angle);
		void setRotationX(float angle);
		void setRotationY(float angle);
		void setRotationZ(float angle);
		void rotate(float x, float y, float z, float angle);
		void rotate(const Vector3& axis, float angle);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		
		void setScale(float x, float y, float z);
		void setScale(float factor);
		void setScale(const Vector3& v);
		void scale(float x, float y, float z);
		void scale(float factor);
		void scale(const Vector3& v);
		
		void setTranslation(float x, float y, float z);
		void setTranslation(const Vector3& v);
		void translate(float x, float y, float z);
		void translate(const Vector3& v);
		
		void setReflection(float x, float y, float z, float w);
		void reflect(float x, float y, float z, float w);
		
		void perspective(float fov, float aspect, float near, float far);
		void ortho(const Rectangle& rect);
		
		// so that you can see the Matrix, Neo
		void lookAt(const float *eye, const float *target, const float *up);
		void lookAt(const Vector3& eye, const Vector3& target, const Vector3& up);
		
	};
}

typedef gtypes::Matrix4 gmat4;

#endif // GTYPES_MATRIX4
