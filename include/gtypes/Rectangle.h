/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Represents a logical rectangle.

#ifndef GTYPES_RECTANGLE_H
#define GTYPES_RECTANGLE_H

#include "gtypesExport.h"
#include "Vector2.h"

namespace gtypes
{
	/// @brief Represents a logical rectangle.
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
		Rectangle();
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] w Width.
		/// @param[in] h Height.
		Rectangle(float x, float y, float w, float h);
		/// @brief Constructor.
		/// @param[in] position Position.
		/// @param[in] size Size.
		Rectangle(Vector2 position, Vector2 size);
		/// @brief Constructor.
		/// @param[in] position Position.
		/// @param[in] w Width.
		/// @param[in] h Height.
		Rectangle(Vector2 position, float w, float h);
		/// @brief Constructor.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] size Size.
		Rectangle(float x, float y, Vector2 size);
		/// @brief Destructor.
		~Rectangle();
		/// @brief Sets the values of the Rectangle.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] w Width.
		/// @param[in] h Height.
		void set(float x, float y, float w, float h);
		/// @brief Sets the values of the Rectangle.
		/// @param[in] position Position.
		/// @param[in] size Size.
		void set(Vector2 position, Vector2 size);
		/// @brief Sets the values of the Rectangle.
		/// @param[in] position Position.
		/// @param[in] w Width.
		/// @param[in] h Height.
		void set(Vector2 position, float w, float h);
		/// @brief Sets the values of the Rectangle.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @param[in] size Size.
		void set(float x, float y, Vector2 size);
		
		/// @brief Gets the position.
		Vector2 getPosition();
		/// @brief Sets the position.
		/// @param[in] position Position.
		void setPosition(Vector2 position);
		/// @brief Sets the position.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		void setPosition(float x, float y);
		/// @brief Gets the size.
		Vector2 getSize();
		/// @brief Sets the size.
		/// @param[in] size Size.
		void setSize(Vector2 size);
		/// @brief Sets the size.
		/// @param[in] w Width.
		/// @param[in] h Height.
		void setSize(float w, float h);
		/// @brief Gets the coordinate located in the center of the Rectangle.
		Vector2 getCenter() const;
		/// @brief Gets the width-to-height aspect ratio.
		float getAspect() const;
		/// @brief Gets the coordinate of the top-left corner of the Rectangle.
		Vector2 getTopLeft() const;
		/// @brief Gets the coordinate of the top-right corner of the Rectangle.
		Vector2 getTopRight() const;
		/// @brief Gets the coordinate of the bottom-left corner of the Rectangle.
		Vector2 getBottomLeft() const;
		/// @brief Gets the coordinate of the bottom-right corner of the Rectangle.
		Vector2 getBottomRight() const;

		/// @brief Gets the left-most coordinate.
		/// @see x
		float left() const;
		/// @brief Gets the right-most coordinate.
		/// @see x + w
		float right() const;
		/// @brief Gets the top-most coordinate.
		/// @see y
		float top() const;
		/// @brief Gets the bottom-most coordinate.
		/// @see y + h
		float bottom() const;
		/// @brief Gets the X coordinate of the point in the center of the Rectangle.
		float centerX() const;
		/// @brief Gets the Y coordinate of the point in the center of the Rectangle.
		float centerY() const;

		/// @brief Creates a new Rectangle that is clipped with another one.
		/// @param[in] clipper The Rectangle used to clip the new one.
		Rectangle clipped(const Rectangle& clipper) const;
		/// @brief Clips this Rectangle with another one.
		/// @param[in] clipper The Rectangle used to clip this one.
		/// @see clipped
		void clip(const Rectangle& clipper);

		/// @brief Checks if two Rectangles intersect.
		/// @param[in] other The other Rectangle.
		/// @return True if the Rectangles intersect.
		/// @note This returns false if the Rectangles are only touching, i.e. their borders lie on the same line.
		bool intersects(const Rectangle& other) const;
		/// @brief Checks if two Rectangles contain portions of each other.
		/// @param[in] other The other Rectangle.
		/// @return True if the Rectangles contain each other.
		/// @note This returns true if the Rectangles are only touching, i.e. their borders lie on the same line.
		/// @see intersects
		bool contains(const Rectangle& other) const;
		/// @brief Checks a point is inside the Rectangle.
		/// @param[in] position The point's position.
		/// @return True if the points is inside the Rectangle.
		/// @note This returns true if the point lies on the left or upper border, but false if it lies on the right or bottom order.
		bool isPointInside(const Vector2& position) const;
		/// @brief Checks a point is inside the Rectangle.
		/// @param[in] x X coordinate.
		/// @param[in] y Y coordinate.
		/// @return True if the points is inside the Rectangle.
		/// @note This returns true if the point lies on the left or upper border, but false if it lies on the right or bottom order.
		bool isPointInside(float x, float y) const;

		/// @brief Creates a new Rectangle that was moved along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return A new Rectangle that was moved along a vector.
		Rectangle operator+(Vector2 vector) const;
		/// @brief Creates a new Rectangle that was moved along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return A new Rectangle that was moved along a vector.
		Rectangle operator-(Vector2 vector) const;
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a vector.
		Rectangle operator*(Vector2 vector) const;
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a vector.
		Rectangle operator/(Vector2 vector) const;
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		Rectangle operator*(float scale) const;
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return A new Rectangle that was scaled with a factor.
		Rectangle operator/(float scale) const;
		/// @brief Moves this Rectangle along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return This Rectangle.
		Rectangle operator+=(const Vector2& vector);
		/// @brief Moves this Rectangle along a vector.
		/// @param[in] vector Vector by which to move the Rectangle.
		/// @return This Rectangle.
		Rectangle operator-=(const Vector2& vector);
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return This Rectangle.
		Rectangle operator*=(const Vector2& vector);
		/// @brief Creates a new Rectangle that was scaled with a vector.
		/// @param[in] vector Vector with which to scale the Rectangle.
		/// @return This Rectangle.
		Rectangle operator/=(const Vector2& vector);
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		Rectangle operator*=(float scale);
		/// @brief Creates a new Rectangle that was scaled with a factor.
		/// @param[in] scale Factor with which to scale the Rectangle.
		/// @return This Rectangle.
		Rectangle operator/=(float scale);
		/// @brief Checks if two Rectangles are equal.
		/// @param[in] other The other Rectangle.
		/// @return True if the two Rectangles are equal.
		/// @note Beware of floating point errors.
		bool operator==(const Rectangle& other) const;
		/// @brief Checks if two Rectangles are not equal.
		/// @param[in] other The other Rectangle.
		/// @return True if the two Rectangles are not equal.
		/// @note Beware of floating point errors.
		bool operator!=(const Rectangle& other) const;
		
	};
}

typedef gtypes::Rectangle grect;

#endif
