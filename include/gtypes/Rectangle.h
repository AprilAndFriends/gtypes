/// @file
/// @version 2.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Represents a rectangle.

#ifndef GTYPES_RECTANGLE_H
#define GTYPES_RECTANGLE_H

#include "gtypesExport.h"
#include "Vector2.h"

namespace gtypes
{
	/// @brief Represents a rectangle.
	class gtypesExport Rectangle
	{
	public:
		/// @brief X coordinate.
		float x;
		/// @brief Y coordinate.
		float y;
		/// @brief Width.
		float w;
		/// @brief Height.
		float h;
	
		/// @brief Basic constructor.
		inline Rectangle() : x(0.0f), y(0.0f), w(0.0f), h(0.0f)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline Rectangle(float x, float y, float w, float h) : x(x), y(y), w(w), h(h)
		{
		}
		/// @brief Constructor.
		/// @param[in] position Position.
		/// @param[in] size Size.
		inline Rectangle(const Vector2& position, const Vector2& size) : x(position.x), y(position.y), w(size.x), h(size.y)
		{
		}
		/// @brief Constructor.
		/// @param[in] position Position.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline Rectangle(const Vector2& position, float w, float h) : x(position.x), y(position.y), w(w), h(h)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] size Size.
		inline Rectangle(float x, float y, const Vector2& size) : x(x), y(y), w(size.x), h(size.y)
		{
		}
		/// @brief Sets the values of the Rectangle.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline void set(float x, float y, float w, float h)
		{
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}
		/// @brief Sets the values of the Rectangle.
		/// @param[in] position Position.
		/// @param[in] size Size.
		inline void set(const Vector2& position, const Vector2& size)
		{
			this->x = position.x;
			this->y = position.y;
			this->w = size.x;
			this->h = size.y;
		}
		/// @brief Sets the values of the Rectangle.
		/// @param[in] position Position.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline void set(const Vector2& position, float w, float h)
		{
			this->x = position.x;
			this->y = position.y;
			this->w = w;
			this->h = h;
		}
		/// @brief Sets the values of the Rectangle.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] size Size.
		inline void set(float x, float y, const Vector2& size)
		{
			this->x = x;
			this->y = y;
			this->w = size.x;
			this->h = size.y;
		}
		
		/// @brief Gets the position.
		inline Vector2 getPosition() const
		{
			return Vector2(this->x, this->y);
		}
		/// @brief Sets the position.
		/// @param[in] position Position.
		inline void setPosition(const Vector2& position)
		{
			this->x = position.x;
			this->y = position.y;
		}
		/// @brief Sets the position.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline void setPosition(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
		/// @brief Gets the size.
		inline Vector2 getSize() const
		{
			return Vector2(this->w, this->h);
		}
		/// @brief Sets the size.
		/// @param[in] size Size.
		inline void setSize(const Vector2& size)
		{
			this->w = size.x;
			this->h = size.y;
		}
		/// @brief Sets the size.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline void setSize(float w, float h)
		{
			this->w = w;
			this->h = h;
		}
		/// @brief Gets the coordinate located in the center of the Rectangle.
		inline Vector2 getCenter() const
		{
			return Vector2(this->x + this->w * 0.5f, this->y + this->h * 0.5f);
		}
		/// @brief Gets the width-to-height aspect ratio.
		inline float getAspect() const
		{
			return (this->w / this->h);
		}
		/// @brief Gets the coordinate of the top-left corner of the Rectangle.
		inline Vector2 getTopLeft() const
		{
			return Vector2(this->x, this->y);
		}
		/// @brief Gets the coordinate of the top-right corner of the Rectangle.
		inline Vector2 getTopRight() const
		{
			return Vector2(this->x + this->w, this->y);
		}
		/// @brief Gets the coordinate of the bottom-left corner of the Rectangle.
		inline Vector2 getBottomLeft() const
		{
			return Vector2(this->x, this->y + this->h);
		}
		/// @brief Gets the coordinate of the bottom-right corner of the Rectangle.
		inline Vector2 getBottomRight() const
		{
			return Vector2(this->x + this->w, this->y + this->h);
		}

		/// @brief Gets the left-most coordinate.
		/// @see x
		inline float left() const
		{
			return this->x;
		}
		/// @brief Gets the right-most coordinate.
		/// @see x + w
		inline float right() const
		{
			return (this->x + this->w);
		}
		/// @brief Gets the top-most coordinate.
		/// @see y
		inline float top() const
		{
			return this->y;
		}
		/// @brief Gets the bottom-most coordinate.
		/// @see y + h
		inline float bottom() const
		{
			return (this->y + this->h);
		}
		/// @brief Gets the X coordinate of the point in the center of the Rectangle.
		inline float centerX() const
		{
			return (this->x + this->w * 0.5f);
		}
		/// @brief Gets the Y coordinate of the point in the center of the Rectangle.
		inline float centerY() const
		{
			return (this->y + this->h * 0.5f);
		}

		/// @brief Creates a new Rectangle that is clipped with another one.
		/// @param[in] clipper The Rectangle used to clip the new one.
		inline Rectangle clipped(const Rectangle& clipper) const
		{
			Rectangle result(*this);
			result.clip(clipper);
			return result;
		}
		/// @brief Clips this Rectangle with another one.
		/// @param[in] clipper The Rectangle used to clip this one.
		/// @see clipped
		inline void clip(const Rectangle& clipper)
		{
			float left = this->x - clipper.x;
			if (left < 0.0f)
			{
				this->w += left;
				this->x = clipper.x;
			}
			float top = this->y - clipper.y;
			if (top < 0.0f)
			{
				this->h += top;
				this->y = clipper.y;
			}
			float right = this->right() - clipper.right();
			if (right > 0.0f)
			{
				this->w -= right;
			}
			float bottom = this->bottom() - clipper.bottom();
			if (bottom > 0.0f)
			{
				this->h -= bottom;
			}
		}

		/// @brief Checks if two Rectangles intersect.
		/// @param[in] other The other Rectangle.
		/// @return True if the Rectangles intersect.
		/// @note This returns false if the Rectangles are only touching, i.e. their borders lie on the same line.
		inline bool intersects(const Rectangle& other) const
		{
			return (this->x + this->w > other.x && this->x < other.x + other.w &&
				this->y + this->h > other.y && this->y < other.y + other.h);
		}
		/// @brief Checks if two Rectangles contain portions of each other.
		/// @param[in] other The other Rectangle.
		/// @return True if the Rectangles contain each other.
		/// @note This returns true if the Rectangles are only touching, i.e. their borders lie on the same line.
		/// @see intersects
		inline bool contains(const Rectangle& other) const
		{
			return (this->x <= other.x && this->x + this->w >= other.x + other.w &&
				this->y <= other.y && this->y + this->h >= other.y + other.h);
		}
		/// @brief Checks a point is inside the Rectangle.
		/// @param[in] position The point's position.
		/// @return True if the points is inside the Rectangle.
		/// @note This returns true if the point lies on the left or upper border, but false if it lies on the right or bottom order.
		inline bool isPointInside(const Vector2& position) const
		{
			return (position.x >= this->x && position.y >= this->y && position.x < this->x + this->w && position.y < this->y + this->h);
		}
		/// @brief Checks a point is inside the Rectangle.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @return True if the points is inside the Rectangle.
		/// @note This returns true if the point lies on the left or upper border, but false if it lies on the right or bottom order.
		inline bool isPointInside(float x, float y) const
		{
			return (x >= this->x && y >= this->y && x < this->x + this->w && y < this->y + this->h);
		}

		/// @brief Creates a new Rectangle that was moved along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return A new Rectangle that was moved along a vector.
		inline Rectangle operator+(const Vector2& vector) const
		{
			Rectangle result(*this);
			result.x += vector.x;
			result.y += vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was moved along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return A new Rectangle that was moved along a vector.
		inline Rectangle operator-(const Vector2& vector) const
		{
			Rectangle result(*this);
			result.x -= vector.x;
			result.y -= vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a vector.
		inline Rectangle operator*(const Vector2& vector) const
		{
			Rectangle result(*this);
			result.w *= vector.x;
			result.h *= vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a vector.
		inline Rectangle operator/(const Vector2& vector) const
		{
			Rectangle result(*this);
			result.w /= vector.x;
			result.h /= vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle operator*(float scale) const
		{
			Rectangle result(*this);
			result.w *= scale;
			result.h *= scale;
			return result;
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle operator/(float scale) const
		{
			Rectangle result(*this);
			result.w /= scale;
			result.h /= scale;
			return result;
		}
		/// @brief Moves this Rectangle along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return This Rectangle.
		inline Rectangle operator+=(const Vector2& vector)
		{
			this->x += vector.x;
			this->y += vector.y;
			return (*this);
		}
		/// @brief Moves this Rectangle along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return This Rectangle.
		inline Rectangle operator-=(const Vector2& vector)
		{
			this->x -= vector.x;
			this->y -= vector.y;
			return (*this);
		}
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle operator*=(const Vector2& vector)
		{
			this->w *= vector.x;
			this->h *= vector.y;
			return (*this);
		}
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle operator/=(const Vector2& vector)
		{
			this->w /= vector.x;
			this->h /= vector.y;
			return (*this);
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle operator*=(float scale)
		{
			this->w *= scale;
			this->h *= scale;
			return (*this);
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle operator/=(float scale)
		{
			this->w /= scale;
			this->h /= scale;
			return (*this);
		}
		/// @brief Checks if two Rectangles are equal.
		/// @param[in] other The other Rectangle.
		/// @return True if the two Rectangles are equal.
		/// @note Beware of floating point errors.
		inline bool operator==(const Rectangle& other) const
		{
			return (this->x == other.x && this->y == other.y && this->w == other.w && this->h == other.h);
		}
		/// @brief Checks if two Rectangles are not equal.
		/// @param[in] other The other Rectangle.
		/// @return True if the two Rectangles are not equal.
		/// @note Beware of floating point errors.
		inline bool operator!=(const Rectangle& other) const
		{
			return !(*this == other);
		}	

	};
}

typedef gtypes::Rectangle grect;

#endif
