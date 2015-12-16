#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

#include "Rectangle.h"
#include "Vector2.h"

HL_UT_TEST_CLASS(Rectangle)
{	
	static const float tolerance = 0.0001f;

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

	HL_UT_TEST_FUNCTION(assignment)
    {
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.x == 1 && r.y == 2 && r.w == 3 && r.h == 4, "grect::assignment - constructor assignment");
        r.set(2, 3, 4, 5);
		HL_UT_ASSERT(r.x == 2 && r.y == 3 && r.w == 4 && r.h == 5, "grect::assignment - set()");
    }

	HL_UT_TEST_FUNCTION(getPosition)
	{
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getPosition().x == 1 && r.getPosition().y == 2, "grect::getPosition - getPosition()");
	}

	HL_UT_TEST_FUNCTION(setPosition)
	{
		grect r(1, 2, 3, 4);
		r.setPosition(5, 6);
		HL_UT_ASSERT(r.getPosition().x == 5 && r.getPosition().y == 6, "grect::setPosition - setPosition()");
		r.setPosition(gvec2(7, 8));
		HL_UT_ASSERT(r.getPosition().x == 7 && r.getPosition().y == 8, "grect::setPosition - setPosition()");
	}

	HL_UT_TEST_FUNCTION(getSize)
	{
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getSize().x == 3 && r.getSize().y == 4, "grect::setSize - getSize()");
	}

	HL_UT_TEST_FUNCTION(setSize)
	{
		grect r(1, 2, 3, 4);
		r.setSize(5, 6);
		HL_UT_ASSERT(r.getSize().x == 5 && r.getSize().y == 6, "grect::setSize - setSize()");
		r.setSize(gvec2(7, 8));
		HL_UT_ASSERT(r.getSize().x == 7 && r.getSize().y == 8, "grect::setSize - setSize()");
	}

	HL_UT_TEST_FUNCTION(getCenter)
	{
		grect r(2, 2, 2, 2);
		HL_UT_ASSERT(r.getCenter().x == 3 && r.getCenter().y == 3, "grect::getCenter - getCenter()");
	}

	HL_UT_TEST_FUNCTION(getAspect)
	{
		grect r(0, 0, 4, 2);
		HL_UT_ASSERT(r.getAspect() == 2, "grect::getAspect - getAspect()");
	}

	HL_UT_TEST_FUNCTION(getTopLeft)
	{
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getTopLeft().x == 1 && r.getTopLeft().y == 2, "grect::getTopLeft - getTopLeft()");
	}

	HL_UT_TEST_FUNCTION(getTopRight)
	{
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getTopRight().x == 4 && r.getTopRight().y == 2, "grect::getTopRight - getTopRight()");
	}

	HL_UT_TEST_FUNCTION(getBottomLeft)
	{
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getBottomLeft().x == 1 && r.getBottomLeft().y == 6, "grect::getBottomLeft - getBottomLeft()");
	}

	HL_UT_TEST_FUNCTION(getBottomRight)
	{
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getBottomRight().x == 4 && r.getBottomRight().y == 6, "grect::getBottomRight - getBottomRight()");
	}

	HL_UT_TEST_FUNCTION(leftRightTopBottom)
	{
		grect r(1, 2, 3, 4);
		HL_UT_ASSERT(r.left() == 1, "grect::leftRightTopBottom - left()");
		HL_UT_ASSERT(r.right() == 4, "grect::leftRightTopBottom - right()");
		HL_UT_ASSERT(r.top() == 2, "grect::leftRightTopBottom - top()");
		HL_UT_ASSERT(r.bottom() == 6, "grect::leftRightTopBottom - bottom()");
	}

	HL_UT_TEST_FUNCTION(center)
	{
		grect r(0, 2, 4, 6);
		HL_UT_ASSERT(heqf(r.getCenter().x, 2, tolerance), "grect::center - getCenterX()");
		HL_UT_ASSERT(heqf(r.getCenter().y, 5, tolerance), "grect::center - getCenterY()");
	}

	HL_UT_TEST_FUNCTION(clipped)
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 4, 4);
		r2 = r2.clipped(r1);
		HL_UT_ASSERT(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "grect::clipped - clipped()");
	}

	HL_UT_TEST_FUNCTION(clip)
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 4, 4);
		r2.clip(r1);
		HL_UT_ASSERT(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "grect::clip - clip()");
	}

	HL_UT_TEST_FUNCTION(intersection)
	{
		grect r1(0, 0, 4, 4);
		grect r2(3, 3, 2, 2);
		HL_UT_ASSERT(r2.intersects(r1) == true, "grect::intersection - intersects()");
	}

	HL_UT_TEST_FUNCTION(contains)
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 2, 2);
		HL_UT_ASSERT(r1.contains(r2) == true, "grect::clip - clip()");
	}

	HL_UT_TEST_FUNCTION(pointInside)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		HL_UT_ASSERT(r.isPointInside(v) == true, "grect::pointInside - isPointInside()");
		HL_UT_ASSERT(r.isPointInside(v.x, v.y) == true, "grect::pointInside - isPointInside()");
	}

	HL_UT_TEST_FUNCTION(addition)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		grect r1 = r + v;
		HL_UT_ASSERT(r1.x == 1 && r1.y == 2, "grect::addition - operator+(vector)");
	}

	HL_UT_TEST_FUNCTION(substraction)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		grect r1 = r - v;
		HL_UT_ASSERT(r1.x == -1 && r1.y == -2, "grect::substraction - operator-(vector)");
	}

	HL_UT_TEST_FUNCTION(multiplication)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		grect r1 = r * v;
		HL_UT_ASSERT(r1.w == 8 && r1.h == 16, "grect::multiplication - operator*(vector)");
		r1 = r * 2;
		HL_UT_ASSERT(r1.w == 8 && r1.h == 8, "grect::multiplication - operator*(float)");
	}

	HL_UT_TEST_FUNCTION(division)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		grect r1 = r / v;
		HL_UT_ASSERT(r1.w == 2 && r1.h == 1, "grect::division - operator/(vector)");
		r1 = r / 2;
		HL_UT_ASSERT(r1.w == 2 && r1.h == 2, "grect::division - operator/(float)");
	}

	HL_UT_TEST_FUNCTION(additionAssign)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		r += v;
		HL_UT_ASSERT(r.x == 1 && r.y == 2, "grect::additionAssign - operator+=(vector)");
	}

	HL_UT_TEST_FUNCTION(substractionAssign)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);
		r -= v;
		HL_UT_ASSERT(r.x == -1 && r.y == -2, "grect::substractionAssign - operator-=(vector)");
	}

	HL_UT_TEST_FUNCTION(multiplicationAssign)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		r *= v;
		HL_UT_ASSERT(r.w == 8 && r.h == 16, "grect::multiplicationAssign - operator*=(vector)");
		r = grect(0, 0, 4, 4);
		r *= 2;
		HL_UT_ASSERT(r.w == 8 && r.h == 8, "grect::multiplicationAssign - operator*=(float)");
	}

	HL_UT_TEST_FUNCTION(divisionAssign)
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		r /= v;
		HL_UT_ASSERT(r.w == 2 && r.h == 1, "grect::divisionAssign - operator/=(vector)");
		r = grect(0, 0, 4, 4);
		r /= 2;
		HL_UT_ASSERT(r.w == 2 && r.h == 2, "grect::divisionAssign - operator/=(float)");
	}
	
	HL_UT_TEST_FUNCTION(equal)
	{
		grect r1(0, 0, 4, 4);
		grect r2(0, 0, 4, 4);
		HL_UT_ASSERT(r1 == r2, "grect::equal - operator==()");
	}

	HL_UT_TEST_FUNCTION(notEqual)
	{
		grect r1(0, 0, 4, 4);
		grect r2(0, 0, 4, 3);
		HL_UT_ASSERT(r1 != r2, "grect::notEqual - operator!=()");
	}

}
