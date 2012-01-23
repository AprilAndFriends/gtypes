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

#ifndef GTYPES_MATRIX3_H
#define GTYPES_MATRIX3_H

#include "gtypesExport.h"

namespace gtypes
{
	class Vector3;
	class Matrix4;

	class gtypesExport Matrix3
	{
	public:
		float data[9];
	
		Matrix3();
		Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
		Matrix3(float m[]);
		Matrix3(const Matrix3& m);
		Matrix3(const Matrix4& m);
		
		void set(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8);
		void set(float m[]);
		void set(const Matrix3& m);
		void set(const Matrix4& m);

		Matrix3 operator+(const Matrix3 &m) const;
		Matrix3 operator-(const Matrix3 &m) const;
		Matrix3 operator*(const Matrix3 &m) const;
		
		operator float*() { return this->data; }
		operator const float*() const { return this->data; }

		float &operator[](int i) { return this->data[i]; }
		const float operator[](int i) const { return this->data[i]; }
		
		Matrix3 operator*=(float f);
		Matrix3 operator*=(const Matrix3& m);
		Matrix3 operator+=(const Matrix3& m);
		Matrix3 operator-=(const Matrix3& m);
		
		Vector3 operator*(const Vector3 &v) const;
		Matrix3 operator*(float f) const;
		
		void inverse();
		Matrix3 inversed() const;
		void transpose();
		Matrix3 transposed() const;
		
		float det() const;
		
		void setIdentity();
		void setZero();
		
		Matrix3 rotationInverse2D() const;
		Matrix3 rotationInverse3D() const;
		
		void setRotation2D(float angle);
		void rotate2D(float angle);

		void setRotation3D(float x, float y, float z, float angle);
		void setRotation3D(const Vector3& v, float angle);
		void rotate3D(float x, float y, float z, float angle);
		void rotate3D(const Vector3& v, float angle);
		
		void setRotationX(float angle);
		void setRotationY(float angle);
		void setRotationZ(float angle);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);
		
		void setScale(float factor);
		void setScale(float x, float y, float z);
		void setScale(const Vector3& v);
		void scale(float factor);
		void scale(float x, float y, float z);
		void scale(const Vector3& v);
		
		void setTranslation2D(float x, float y);
		void translate2D(float x, float y);
		
		void orthoNormalize();

	};
}

typedef gtypes::Matrix3 gmat3;

#endif // GTYPES_MATRIX3
