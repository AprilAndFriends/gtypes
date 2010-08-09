/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "Vector2.h"
#include <math.h>

namespace gtypes
{
	Vector2::Vector2()
	{
		x=y=0;
	}

	Vector2::Vector2(float _x,float _y)
	{
		this->x=_x; this->y=_y;
	}

	void Vector2::set(float _x,float _y)
	{
		this->x=_x; this->y=_y;
	}

	float Vector2::length()
	{
		return sqrt(this->x*this->x + this->y*this->y);
	}

	float Vector2::squaredLength()
	{
		return	this->x*this->x + this->y*this->y;
	}

	void Vector2::normalise()
	{
		float len=length();
		this->x/=len; this->y/=len;
	}

	Vector2 Vector2::normalised()
	{
		Vector2 v(x,y);
		v.normalise();
		return v;
	}

	bool Vector2::isInCircle(float center_x,float center_y,float radius)
	{
		float a=x-center_x,b=y-center_y;
		return (a*a+b*b <= radius*radius);
	}
	
	bool Vector2::isInRectangle(float rect_x,float rect_y,float rect_w,float rect_h)
	{
		return (x >= rect_x && y >= rect_y && x <= rect_x+rect_w && y <= rect_y+rect_h);
	}

	Vector2 Vector2::operator +(const Vector2& v)
	{
		return Vector2(this->x+v.x,this->y+v.y);
	}

	Vector2 Vector2::operator -(const Vector2& v)
	{
		return Vector2(this->x-v.x,this->y-v.y);
	}
    
    Vector2 Vector2::operator -()
	{
		return Vector2(-this->x, -this->y);
	}

	Vector2 Vector2::operator *(const float f)
	{
		return Vector2(this->x*f,this->y*f);
	}
    
    Vector2 Vector2::operator /(const float f)
	{
		return Vector2(this->x/f,this->y/f);
	}

	void Vector2::operator +=(const Vector2& v)
	{
		this->x+=v.x; this->y+=v.y;
	}

	void Vector2::operator -=(const Vector2& v)
	{
		this->x-=v.x; this->y-=v.y;
	}

	void Vector2::operator *=(const float f)
	{
		this->x*=f; this->y*=f;
	}
    
    void Vector2::operator /=(const float f)
	{
		this->x/=f; this->y/=f;
	}
    
    bool Vector2::operator ==(const Vector2& v)
    {
        if((x == v.x) && (y == v.y))
        {
            return true;
        }
        return false;
    }
    
    bool Vector2::operator !=(const Vector2& v)
    {
        return !(*this == v);
    }
	
	float Vector2::dotProduct(Vector2 v)
	{
		return this->x*v.x+this->y*v.y;
	}
}

