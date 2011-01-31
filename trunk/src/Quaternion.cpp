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
#include "Quaternion.h"
#include "Vector3.h"
#include "util.h"

namespace gtypes
{
	Quaternion::Quaternion()
	{
		this->x = 1.0f;
		this->y = 1.0f;
		this->z = 1.0f;
		this->w = 1.0f;
	}

	Quaternion::Quaternion(const Quaternion& quat)
	{
		this->x = quat.x;
		this->y = quat.y;
		this->z = quat.z;
		this->w = quat.w;
	}

	Quaternion::Quaternion(const float* v)
	{
		this->x = v[0];
		this->y = v[1];
		this->z = v[2];
		this->w = v[3];
	}

	Quaternion::Quaternion(float _x, float _y, float _z, float _w)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
		this->w = _w;
	}
	
	void Quaternion::set(float _x, float _y, float _z, float _w)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
		this->w = _w;
	}

	Matrix3 Quaternion::mat3() const
	{
		float x2 = this->x * this->x;
		float y2 = this->y * this->y;
		float z2 = this->z * this->z;
		float xy = this->x * this->y;
		float xz = this->x * this->z;
		float yz = this->y * this->z;
		float wx = this->w * this->x;
		float wy = this->w * this->y;
		float wz = this->w * this->z;
	 
		return Matrix3( 1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz)       , 2.0f * (xz + wy),
				        2.0f * (xy + wz)       , 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx),
				        2.0f * (xz - wy)       , 2.0f * (yz + wx)       , 1.0f - 2.0f * (x2 + y2));
	}

	Matrix4 Quaternion::mat4() const
	{
		return mat4(Vector3(0, 0, 0));
	}

	Matrix4 Quaternion::mat4(const Vector3& position) const
	{
		float x2 = this->x * this->x;
		float y2 = this->y * this->y;
		float z2 = this->z * this->z;
		float xy = this->x * this->y;
		float xz = this->x * this->z;
		float yz = this->y * this->z;
		float wx = this->w * this->x;
		float wy = this->w * this->y;
		float wz = this->w * this->z;
	 
		return Matrix4( 1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0.0f,
				        2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0.0f,
				        2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0.0f,
						position.x      , position.y      , position.z             , 1.0f);
	}
	
	Quaternion Quaternion::fromAxisAngle(float ax, float ay, float az, float angle)
	{
		float x, y, z, w;
		float theta = deg_to_rad(angle) * 0.5f;
		float s = sqrt(ax*ax + ay*ay + az*az);
		w = cos(theta);
		x = (ax / s) * sin(theta);
		y = (ay / s) * sin(theta);
		z = (az / s) * sin(theta);
		
		return Quaternion(x, y, z, w);
	}
	
	Quaternion Quaternion::operator +(const Quaternion& q)
	{
		return Quaternion( x + q.x,
				       y + q.y,
				       z + q.z,
				       w + q.w );
	}

	Quaternion Quaternion::operator -(const Quaternion& q)
	{
		return Quaternion( x - q.x,
				       y - q.y,
				       z - q.z,
				       w - q.w );
	}
	
	Quaternion Quaternion::operator *(const Quaternion& q)
	{
		return Quaternion( w*q.x + x*q.w + y*q.z - z*q.y, 
					   w*q.y - x*q.z + y*q.w + z*q.x, 
					   w*q.z + x*q.y - y*q.x + z*q.w,
					   w*q.w - x*q.x - y*q.y - z*q.z );
	}
	
	Quaternion Quaternion::operator *(float f)
	{
		return Quaternion(x*f, y*f, z*f, w*f);
	}
	
	float Quaternion::dot(const Quaternion& q)
	{
		return w*q.w + x*q.x + y*q.y + z*q.z;
	}
	
	void Quaternion::slerp(Quaternion& a, Quaternion& b, float t)
	{
		float w1, w2;
		
		float theta = acos(a.dot(b));
		float sinTheta = sin(theta);
		
		if(sinTheta > 0.001)
		{
			w1 = (sin(1.0 - t) * theta) / sinTheta;
			w2 = (sin(t * theta)) / sinTheta;
		} else {
			w1 = 1.0 - t;
			w2 = t;
		}
		
		*this = a * w1 + b * w2;
	}
	
	Quaternion Quaternion::getInverse()
	{
		float sqNorm = x*x + y*y + z*z + w*w;
		return Quaternion(-x / sqNorm, -y / sqNorm, -z / sqNorm, w / sqNorm);
	}
	
	void Quaternion::normalize()
	{
		float sqnorm = x*x + y*y + z*z + w*w;
		/*if(sqnorm == 0.0)  throw exception*/
		if(sqnorm != 1.0)
		{
			float s = (1.0 / sqrt(sqnorm));
			x *= s;
			y *= s;
			z *= s;
			w *= s;
		}
	}

}
