/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "Quaternion.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Matrix4.h"

namespace gtypes
{
	Quaternion::Quaternion()
	{
		this->w=1;
		this->x=this->z=this->w=1;
	}

	Quaternion::Quaternion(const Quaternion& quat)
	{
		this->x=quat.x; this->y=quat.y; this->z=quat.z; this->w=quat.w;
	}

	Quaternion::Quaternion(const float* v)
	{
		this->x=v[0]; this->y=v[1]; this->z=v[2]; this->w=v[3];
	}

	Quaternion::Quaternion(float _x, float _y, float _z, float _w)
	{
		this->x=_x; this->y=_y; this->z=_z; this->w=_w;
	}
	
	void Quaternion::set(float _x, float _y, float _z, float _w)
	{
		this->x=_x; this->y=_y; this->z=_z; this->w=_w;
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
		return mat4(Vector3(0,0,0));
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
	
	Quaternion Quaternion::fromAxisAngle(float ax,float ay,float az,float angle)
	{
		float x,y,z,w;
		float theta=angle/(2*57.295779513082323f);
		w =      cos(theta);
		x = ax * sin(theta);
		y = ay * sin(theta);
		z = az * sin(theta);
		
		return Quaternion(x,y,z,w);
	}
}
