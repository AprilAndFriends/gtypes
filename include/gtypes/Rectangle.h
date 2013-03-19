/// @file
/// @author  Boris Mikic
/// @version 1.43
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// DOCUMENT ME

#ifndef GTYPES_RECTANGLE_H
#define GTYPES_RECTANGLE_H

#include "gtypesExport.h"

namespace gtypes
{
	class Vector2;
	
	class gtypesExport Rectangle
	{
	public:
		float x, y, w, h;
	
		Rectangle();
		Rectangle(float x, float y, float w, float h);
		Rectangle(Vector2 position, Vector2 size);
		Rectangle(Vector2 position, float w, float h);
		Rectangle(float x, float y, Vector2 size);
		
		void set(float x, float y, float w, float h);
		void set(Vector2 position, Vector2 size);
		void set(Vector2 position, float w, float h);
		void set(float x, float y, Vector2 size);
		
		Vector2 getPosition();
		void setPosition(Vector2 position);
		void setPosition(float x, float y);
		Vector2 getSize();
		void setSize(Vector2 size);
		void setSize(float w, float h);
		Vector2 getCenter() const;
		float getAspect() const;
		Vector2 getTopLeft() const;
		Vector2 getTopRight() const;
		Vector2 getBottomLeft() const;
		Vector2 getBottomRight() const;

		float left() const;
		float right() const;
		float top() const;
		float bottom() const;
		float centerX() const;
		float centerY() const;

		bool intersects(const Rectangle& other) const;
		bool contains(const Rectangle& other) const;
		bool isPointInside(const Vector2& vector) const;
		bool isPointInside(float x, float y) const;

		Rectangle operator+(Vector2 vector) const;
		Rectangle operator-(Vector2 vector) const;
		Rectangle operator*(Vector2 vector) const;
		Rectangle operator/(Vector2 vector) const;
		Rectangle operator*(float scale) const;
		Rectangle operator/(float scale) const;
		Rectangle operator+=(const Vector2& vector);
		Rectangle operator-=(const Vector2& vector);
		Rectangle operator*=(const Vector2& vector);
		Rectangle operator/=(const Vector2& vector);
		Rectangle operator*=(float scale);
		Rectangle operator/=(float scale);
		bool operator==(const Rectangle& other) const;
		bool operator!=(const Rectangle& other) const;
		
	};
}

typedef gtypes::Rectangle grect;

#endif // GTYPES_RECTANGLE_H
