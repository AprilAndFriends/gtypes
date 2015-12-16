#define __HL_TEST_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

#include "Rectangle.h"
#include "Vector2.h"

HL_TEST_NAMESPACE(Rectangle)
{	
	static const float tolerance = 0.1f;

	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance)
	{
		return (habs(a - b) < tolerance);
	}

	static bool rectangleEqf(grect r1, grect r2)
	{
		return (heqf(r1.x, r2.x, tolerance) && heqf(r1.y, r2.y, tolerance) &&
			heqf(r1.w, r2.w, tolerance) && heqf(r1.h, r2.h, tolerance));
	}

    void assignment()
    {
		grect r(1, 2, 3, 4);
		assertTrue(r.x == 1 && r.y == 2 && r.w == 3 && r.h == 4, "grect::assignment - constructor assignment");
        r.set(2, 3, 4, 5);
		assertTrue(r.x == 2 && r.y == 3 && r.w == 4 && r.h == 5, "grect::assignment - set()");
    }

	void getPosition()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getPosition().x == 1 && r.getPosition().y == 2, "grect::getPosition - getPosition()");
	}

	void setPosition()
	{
		grect r(1, 2, 3, 4);
		r.setPosition(5, 6);
		assertTrue(r.getPosition().x == 5 && r.getPosition().y == 6, "grect::setPosition - setPosition()");
		r.setPosition(gvec2(7, 8));
		assertTrue(r.getPosition().x == 7 && r.getPosition().y == 8, "grect::setPosition - setPosition()");
	}

	void getSize()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getSize().x == 3 && r.getSize().y == 4, "grect::setSize - getSize()");
	}

	void setSize()
	{
		grect r(1, 2, 3, 4);
		r.setSize(5, 6);
		assertTrue(r.getSize().x == 5 && r.getSize().y == 6, "grect::setSize - setSize()");
		r.setSize(gvec2(7, 8));
		assertTrue(r.getSize().x == 7 && r.getSize().y == 8, "grect::setSize - setSize()");
	}

	void getCenter()
	{
		grect r(2, 2, 2, 2);
		assertTrue(r.getCenter().x == 3 && r.getCenter().y == 3, "grect::getCenter - getCenter()");
	}

	void getAspect()
	{
		grect r(0, 0, 4, 2);
		assertTrue(r.getAspect() == 2, "grect::getAspect - getAspect()");
	}

	void getTopLeft()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getTopLeft().x == 1 && r.getTopLeft().y == 2, "grect::getTopLeft - getTopLeft()");
	}

	void getTopRight()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getTopRight().x == 4 && r.getTopRight().y == 2, "grect::getTopRight - getTopRight()");
	}

	void getBottomLeft()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getBottomLeft().x == 1 && r.getBottomLeft().y == 6, "grect::getBottomLeft - getBottomLeft()");
	}

	void getBottomRight()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getBottomRight().x == 4 && r.getBottomRight().y == 6, "grect::getBottomRight - getBottomRight()");
	}

	void leftRightTopBottom()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.left() == 1, "grect::leftRightTopBottom - left()");
		assertTrue(r.right() == 4, "grect::leftRightTopBottom - right()");
		assertTrue(r.top() == 2, "grect::leftRightTopBottom - top()");
		assertTrue(r.bottom() == 6, "grect::leftRightTopBottom - bottom()");
	}

	void center()
	{
		grect r(0, 2, 4, 6);
		assertTrue(heqf(r.getCenter().x, 2, tolerance), "grect::center - getCenterX()");
		assertTrue(heqf(r.getCenter().y, 5, tolerance), "grect::center - getCenterY()");
	}

	void clipped()
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 4, 4);
		r2 = r2.clipped(r1);
		assertTrue(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "grect::clipped - clipped()");
	}

	void clip()
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 4, 4);
		r2.clip(r1);
		assertTrue(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "grect::clip - clip()");
	}

	void intersection()
	{
		grect r1(0, 0, 4, 4);
		grect r2(3, 3, 2, 2);
		assertTrue(r2.intersects(r1) == true, "grect::intersection - intersects()");
	}

	void contains()
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 2, 2);
		assertTrue(r1.contains(r2) == true, "grect::clip - clip()");
	}

	void pointInside()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		assertTrue(r.isPointInside(v) == true, "grect::pointInside - isPointInside()");
		assertTrue(r.isPointInside(v.x, v.y) == true, "grect::pointInside - isPointInside()");
	}

	void addition()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		grect r1 = r + v;
		assertTrue(r1.x == 1 && r1.y == 2, "grect::addition - operator+(vector)");
	}

	void substraction()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		grect r1 = r - v;
		assertTrue(r1.x == -1 && r1.y == -2, "grect::substraction - operator-(vector)");
	}

	void multiplication()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		grect r1 = r * v;
		assertTrue(r1.w == 8 && r1.h == 16, "grect::multiplication - operator*(vector)");
		r1 = r * 2;
		assertTrue(r1.w == 8 && r1.h == 8, "grect::multiplication - operator*(float)");
	}

	void division()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		grect r1 = r / v;
		assertTrue(r1.w == 2 && r1.h == 1, "grect::division - operator/(vector)");
		r1 = r / 2;
		assertTrue(r1.w == 2 && r1.h == 2, "grect::division - operator/(float)");
	}

	void additionAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		r += v;
		assertTrue(r.x == 1 && r.y == 2, "grect::additionAssign - operator+=(vector)");
	}

	void substractionAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		r -= v;
		assertTrue(r.x == -1 && r.y == -2, "grect::substractionAssign - operator-=(vector)");
	}

	void multiplicationAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		r *= v;
		assertTrue(r.w == 8 && r.h == 16, "grect::multiplicationAssign - operator*=(vector)");
		r = grect(0, 0, 4, 4);
		r *= 2;
		assertTrue(r.w == 8 && r.h == 8, "grect::multiplicationAssign - operator*=(float)");
	}

	void divisionAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		r /= v;
		assertTrue(r.w == 2 && r.h == 1, "grect::divisionAssign - operator/=(vector)");
		r = grect(0, 0, 4, 4);
		r /= 2;
		assertTrue(r.w == 2 && r.h == 2, "grect::divisionAssign - operator/=(float)");
	}
	
	void equal()
	{
		grect r1(0, 0, 4, 4);
		grect r2(0, 0, 4, 4);
		assertTrue(r1 == r2, "grect::equal - operator==()");
	}

	void notEqual()
	{
		grect r1(0, 0, 4, 4);
		grect r2(0, 0, 4, 3);
		assertTrue(r1 != r2, "grect::notEqual - operator!=()");
	}

}
