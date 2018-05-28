/// @file
/// @version 3.0
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
	template <typename T>
	class Rectangle
	{
	public:
		/// @brief X coordinate.
		T x;
		/// @brief Y coordinate.
		T y;
		/// @brief Width.
		T w;
		/// @brief Height.
		T h;
	
		/// @brief Basic constructor.
		inline Rectangle() : x(0), y(0), w(0), h(0)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline Rectangle(T x, T y, T w, T h) : x(x), y(y), w(w), h(h)
		{
		}
		/// @brief Constructor.
		/// @param[in] position Position.
		/// @param[in] size Size.
		inline Rectangle(const Vector2<T>& position, const Vector2<T>& size) : x(position.x), y(position.y), w(size.x), h(size.y)
		{
		}
		/// @brief Constructor.
		/// @param[in] position Position.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline Rectangle(const Vector2<T>& position, T w, T h) : x(position.x), y(position.y), w(w), h(h)
		{
		}
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] size Size.
		inline Rectangle(T x, T y, const Vector2<T>& size) : x(x), y(y), w(size.x), h(size.y)
		{
		}
		/// @brief Sets the values of the Rectangle.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline void set(T x, T y, T w, T h)
		{
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}
		/// @brief Sets the values of the Rectangle.
		/// @param[in] position Position.
		/// @param[in] size Size.
		inline void set(const Vector2<T>& position, const Vector2<T>& size)
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
		inline void set(const Vector2<T>& position, T w, T h)
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
		inline void set(T x, T y, const Vector2<T>& size)
		{
			this->x = x;
			this->y = y;
			this->w = size.x;
			this->h = size.y;
		}
		
		/// @brief Gets the position.
		inline Vector2<T> getPosition() const
		{
			return Vector2<T>(this->x, this->y);
		}
		/// @brief Sets the position.
		/// @param[in] position Position.
		inline void setPosition(const Vector2<T>& position)
		{
			this->x = position.x;
			this->y = position.y;
		}
		/// @brief Sets the position.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		inline void setPosition(T x, T y)
		{
			this->x = x;
			this->y = y;
		}
		/// @brief Gets the size.
		inline Vector2<T> getSize() const
		{
			return Vector2<T>(this->w, this->h);
		}
		/// @brief Sets the size.
		/// @param[in] size Size.
		inline void setSize(const Vector2<T>& size)
		{
			this->w = size.x;
			this->h = size.y;
		}
		/// @brief Sets the size.
		/// @param[in] w Width.
		/// @param[in] h Height.
		inline void setSize(T w, T h)
		{
			this->w = w;
			this->h = h;
		}
		/// @brief Gets the coordinate located in the center of the Rectangle.
		/// @note Careful when using this with int as template type!
		inline Vector2<T> getCenter() const
		{
			return Vector2<T>(this->x + this->w / 2, this->y + this->h / 2);
		}
		/// @brief Gets the width-to-height aspect ratio.
		inline float getAspect() const
		{
			return ((float)this->w / this->h);
		}
		/// @brief Gets the coordinate of the top-left corner of the Rectangle.
		inline Vector2<T> getTopLeft() const
		{
			return Vector2<T>(this->x, this->y);
		}
		/// @brief Gets the coordinate of the top-right corner of the Rectangle.
		inline Vector2<T> getTopRight() const
		{
			return Vector2<T>(this->x + this->w, this->y);
		}
		/// @brief Gets the coordinate of the bottom-left corner of the Rectangle.
		inline Vector2<T> getBottomLeft() const
		{
			return Vector2<T>(this->x, this->y + this->h);
		}
		/// @brief Gets the coordinate of the bottom-right corner of the Rectangle.
		inline Vector2<T> getBottomRight() const
		{
			return Vector2<T>(this->x + this->w, this->y + this->h);
		}
		/// @brief Gets the area of the Rectangle.
		inline T getArea() const
		{
			return (this->w * this->h);
		}
		/// @brief Gets the circumference of the Rectangle.
		inline T getCircumference() const
		{
			return (this->w + this->h) * 2;
		}

		/// @brief Gets the left-most coordinate.
		/// @see x
		inline T left() const
		{
			return this->x;
		}
		/// @brief Gets the right-most coordinate.
		/// @see x + w
		inline T right() const
		{
			return (this->x + this->w);
		}
		/// @brief Gets the top-most coordinate.
		/// @see y
		inline T top() const
		{
			return this->y;
		}
		/// @brief Gets the bottom-most coordinate.
		/// @see y + h
		inline T bottom() const
		{
			return (this->y + this->h);
		}
		/// @brief Gets the X coordinate of the point in the center of the Rectangle.
		/// @note Careful when using this with int as template type!
		inline T centerX() const
		{
			return (this->x + this->w / 2);
		}
		/// @brief Gets the Y coordinate of the point in the center of the Rectangle.
		/// @note Careful when using this with int as template type!
		inline T centerY() const
		{
			return (this->y + this->h / 2);
		}

		/// @brief Creates a new Rectangle that is clipped with another one.
		/// @param[in] clipper The Rectangle used to clip the new one.
		inline Rectangle clipped(const Rectangle<T>& clipper) const
		{
			Rectangle<T> result(*this);
			result.clip(clipper);
			return result;
		}
		/// @brief Clips this Rectangle with another one.
		/// @param[in] clipper The Rectangle used to clip this one.
		/// @see clipped
		inline void clip(const Rectangle<T>& clipper)
		{
			T left = this->x - clipper.x;
			if (left < 0)
			{
				this->w += left;
				this->x = clipper.x;
			}
			T top = this->y - clipper.y;
			if (top < 0)
			{
				this->h += top;
				this->y = clipper.y;
			}
			T right = this->right() - clipper.right();
			if (right > 0)
			{
				this->w -= right;
			}
			T bottom = this->bottom() - clipper.bottom();
			if (bottom > 0)
			{
				this->h -= bottom;
			}
		}

		/// @brief Checks if two Rectangles intersect.
		/// @param[in] other The other Rectangle.
		/// @return True if the Rectangles intersect.
		/// @note This returns false if the Rectangles are only touching, i.e. their borders lie on the same line.
		inline bool intersects(const Rectangle<T>& other) const
		{
			return (this->x + this->w > other.x && this->x < other.x + other.w &&
				this->y + this->h > other.y && this->y < other.y + other.h);
		}
		/// @brief Checks if two Rectangles contain portions of each other.
		/// @param[in] other The other Rectangle.
		/// @return True if the Rectangles contain each other.
		/// @note This returns true if the Rectangles are only touching, i.e. their borders lie on the same line.
		/// @see intersects
		inline bool contains(const Rectangle<T>& other) const
		{
			return (this->x <= other.x && this->x + this->w >= other.x + other.w &&
				this->y <= other.y && this->y + this->h >= other.y + other.h);
		}
		/// @brief Checks a point is inside the Rectangle.
		/// @param[in] position The point's position.
		/// @return True if the points is inside the Rectangle.
		/// @note This returns true if the point lies on the left or upper border, but false if it lies on the right or bottom order.
		inline bool isPointInside(const Vector2<T>& position) const
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
			return (x >= (float)this->x && y >= (float)this->y && x < (float)this->x + (float)this->w && y < (float)this->y + (float)this->h);
		}

		/// @brief Creates a new Rectangle that was moved along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return A new Rectangle that was moved along a vector.
		inline Rectangle<T> operator+(const Vector2<T>& vector) const
		{
			Rectangle<T> result(*this);
			result.x += vector.x;
			result.y += vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was moved along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return A new Rectangle that was moved along a vector.
		inline Rectangle<T> operator-(const Vector2<T>& vector) const
		{
			Rectangle<T> result(*this);
			result.x -= vector.x;
			result.y -= vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a vector.
		inline Rectangle<T> operator*(const Vector2<T>& vector) const
		{
			Rectangle<T> result(*this);
			result.w *= vector.x;
			result.h *= vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a vector.
		inline Rectangle<T> operator/(const Vector2<T>& vector) const
		{
			Rectangle<T> result(*this);
			result.w /= vector.x;
			result.h /= vector.y;
			return result;
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle<T> operator*(int scale) const
		{
			return Rectangle<T>(this->x, this->y, this->w * scale, this->h * scale);
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle<T> operator*(float scale) const
		{
			return Rectangle<T>(this->x, this->y, (T)(this->w * scale), (T)(this->h * scale));
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle<T> operator*(double scale) const
		{
			return Rectangle<T>(this->x, this->y, (T)(this->w * scale), (T)(this->h * scale));
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle<T> operator/(int scale) const
		{
			return Rectangle<T>(this->x, this->y, this->w / scale, this->h / scale);
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle<T> operator/(float scale) const
		{
			return Rectangle<T>(this->x, this->y, (T)(this->w / scale), (T)(this->h / scale));
		}
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		inline Rectangle<T> operator/(double scale) const
		{
			return Rectangle<T>(this->x, this->y, (T)(this->w / scale), (T)(this->h / scale));
		}
		/// @brief Sets this Rectangle to another one.
		/// @param[in] other The other Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator=(const Rectangle<T>& other)
		{
			this->x = other.x;
			this->y = other.y;
			this->w = other.w;
			this->h = other.h;
			return (*this);
		}
		/// @brief Moves this Rectangle along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator+=(const Vector2<T>& vector)
		{
			this->x += vector.x;
			this->y += vector.y;
			return (*this);
		}
		/// @brief Moves this Rectangle along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator-=(const Vector2<T>& vector)
		{
			this->x -= vector.x;
			this->y -= vector.y;
			return (*this);
		}
		/// @brief Scales this Rectangle with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator*=(const Vector2<T>& vector)
		{
			this->w *= vector.x;
			this->h *= vector.y;
			return (*this);
		}
		/// @brief Scales this Rectangle with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator/=(const Vector2<T>& vector)
		{
			this->w /= vector.x;
			this->h /= vector.y;
			return (*this);
		}
		/// @brief Scales this Rectangle with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator*=(int scale)
		{
			this->w *= scale;
			this->h *= scale;
			return (*this);
		}
		/// @brief Scales this Rectangle with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator*=(float scale)
		{
			this->w = (T)(this->w * scale);
			this->h = (T)(this->h * scale);
			return (*this);
		}
		/// @brief Scales this Rectangle with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator*=(double scale)
		{
			this->w = (T)(this->w * scale);
			this->h = (T)(this->h * scale);
			return (*this);
		}
		/// @brief Scales this Rectangle with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator/=(int scale)
		{
			this->w /= scale;
			this->h /= scale;
			return (*this);
		}
		/// @brief Scales this Rectangle with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator/=(float scale)
		{
			this->w = (T)(this->w / scale);
			this->h = (T)(this->h / scale);
			return (*this);
		}
		/// @brief Scales this Rectangle with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		inline Rectangle<T> operator/=(double scale)
		{
			this->w = (T)(this->w / scale);
			this->h = (T)(this->h / scale);
			return (*this);
		}
		/// @brief Checks if two Rectangles are equal.
		/// @param[in] other The other Rectangle.
		/// @return True if the two Rectangles are equal.
		/// @note Beware of floating point errors.
		inline bool operator==(const Rectangle<T>& other) const
		{
			return (this->x == other.x && this->y == other.y && this->w == other.w && this->h == other.h);
		}
		/// @brief Checks if two Rectangles are not equal.
		/// @param[in] other The other Rectangle.
		/// @return True if the two Rectangles are not equal.
		/// @note Beware of floating point errors.
		inline bool operator!=(const Rectangle<T>& other) const
		{
			return !(*this == other);
		}	
		/// @brief Checks if one Rectangle is bigger than the other or the same size.
		/// @param[in] other The other Rectangle.
		/// @return True if the the first Rectangle is bigger than the other or the same size.
		/// @note Beware of floating point errors.
		inline bool operator>=(const Rectangle<T>& other) const
		{
			return (this->w * this->h >= other.w * other.h);
		}
		/// @brief Checks if one Rectangle is bigger than the other.
		/// @param[in] other The other Rectangle.
		/// @return True if the the first Rectangle is bigger than the other.
		/// @note Beware of floating point errors.
		inline bool operator>(const Rectangle<T>& other) const
		{
			return (this->w * this->h > other.w * other.h);
		}
		/// @brief Checks if one Rectangle is smaller than the other or the same size.
		/// @param[in] other The other Rectangle.
		/// @return True if the the first Rectangle is smaller than the other or the same size.
		/// @note Beware of floating point errors.
		inline bool operator<=(const Rectangle<T>& other) const
		{
			return (this->w * this->h <= other.w * other.h);
		}
		/// @brief Checks if one Rectangle is smaller than the other.
		/// @param[in] other The other Rectangle.
		/// @return True if the the first Rectangle is smaller than the other.
		/// @note Beware of floating point errors.
		inline bool operator<(const Rectangle<T>& other) const
		{
			return (this->w * this->h < other.w * other.h);
		}

	};
}

/// @brief Typedef for simpler code.
typedef gtypes::Rectangle<int> grecti;
/// @brief Typedef for simpler code.
typedef const gtypes::Rectangle<int>& cgrecti;
/// @brief Typedef for simpler code.
typedef gtypes::Rectangle<float> grectf;
/// @brief Typedef for simpler code.
typedef const gtypes::Rectangle<float>& cgrectf;
/// @brief Typedef for simpler code.
typedef gtypes::Rectangle<double> grectd;
/// @brief Typedef for simpler code.
typedef const gtypes::Rectangle<double>& cgrectd;

/// @brief Temporary compatibility alias.
#define grect grectf
/// @brief Temporary compatibility alias.
#define cgrect cgrectf
// TODO - enable this later and remove above emporary compatibility alias
/*
/// @brief Alias for simpler code.
#define grect gtypes::Rectangle
/// @brief Alias for simpler code.
#define cgrect const gtypes::Rectangle&
*/

#endif
