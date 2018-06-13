#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

#include "Rectangle.h"
#include "Vector2.h"

#define E_TOLRANCE 0.0001f

HL_UT_TEST_CLASS(Rectangle)
{	
	HL_UT_TEST_FUNCTION(assignment)
    {
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.x == 1 && r.y == 2 && r.w == 3 && r.h == 4, "constructor assignment");
        r.set(2, 3, 4, 5);
		HL_UT_ASSERT(r.x == 2 && r.y == 3 && r.w == 4 && r.h == 5, "set()");
    }

	HL_UT_TEST_FUNCTION(getPosition)
	{
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getPosition().x == 1 && r.getPosition().y == 2, "");
	}

	HL_UT_TEST_FUNCTION(setPosition)
	{
		grectf r(1, 2, 3, 4);
		r.setPosition(5, 6);
		HL_UT_ASSERT(r.getPosition().x == 5 && r.getPosition().y == 6, "setPosition(float, float)");
		r.setPosition(gvec2f(7, 8));
		HL_UT_ASSERT(r.getPosition().x == 7 && r.getPosition().y == 8, "setPosition(gvec2f)");
	}

	HL_UT_TEST_FUNCTION(getSize)
	{
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getSize().x == 3 && r.getSize().y == 4, "");
	}

	HL_UT_TEST_FUNCTION(setSize)
	{
		grectf r(1, 2, 3, 4);
		r.setSize(5, 6);
		HL_UT_ASSERT(r.getSize().x == 5 && r.getSize().y == 6, "setSize(float, float)");
		r.setSize(gvec2f(7, 8));
		HL_UT_ASSERT(r.getSize().x == 7 && r.getSize().y == 8, "setSize(gvec2f)");
	}

	HL_UT_TEST_FUNCTION(getCenter)
	{
		grectf r(2, 2, 2, 2);
		HL_UT_ASSERT(r.getCenter().x == 3 && r.getCenter().y == 3, "");
	}

	HL_UT_TEST_FUNCTION(getAspect)
	{
		grectf r(0, 0, 4, 2);
		HL_UT_ASSERT(r.getAspect() == 2, "");
	}

	HL_UT_TEST_FUNCTION(getTopLeft)
	{
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getTopLeft().x == 1 && r.getTopLeft().y == 2, "");
	}

	HL_UT_TEST_FUNCTION(getTopRight)
	{
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getTopRight().x == 4 && r.getTopRight().y == 2, "");
	}

	HL_UT_TEST_FUNCTION(getBottomLeft)
	{
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getBottomLeft().x == 1 && r.getBottomLeft().y == 6, "");
	}

	HL_UT_TEST_FUNCTION(getBottomRight)
	{
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.getBottomRight().x == 4 && r.getBottomRight().y == 6, "");
	}

	HL_UT_TEST_FUNCTION(leftRightTopBottom)
	{
		grectf r(1, 2, 3, 4);
		HL_UT_ASSERT(r.left() == 1, "left()");
		HL_UT_ASSERT(r.right() == 4, "right()");
		HL_UT_ASSERT(r.top() == 2, "top()");
		HL_UT_ASSERT(r.bottom() == 6, "bottom()");
	}

	HL_UT_TEST_FUNCTION(clipped)
	{
		grectf r1(0, 0, 4, 4);
		grectf r2(1, 1, 4, 4);
		r2 = r2.clipped(r1);
		HL_UT_ASSERT(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "");
	}

	HL_UT_TEST_FUNCTION(clip)
	{
		grectf r1(0, 0, 4, 4);
		grectf r2(1, 1, 4, 4);
		r2.clip(r1);
		HL_UT_ASSERT(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "");
	}

	HL_UT_TEST_FUNCTION(intersection)
	{
		grectf r1(0, 0, 4, 4);
		grectf r2(3, 3, 2, 2);
		HL_UT_ASSERT(r2.intersects(r1), "");
	}

	HL_UT_TEST_FUNCTION(contains)
	{
		grectf r1(0, 0, 4, 4);
		grectf r2(1, 1, 2, 2);
		HL_UT_ASSERT(r1.contains(r2), "");
	}

	HL_UT_TEST_FUNCTION(pointInside)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(1, 2);
		HL_UT_ASSERT(r.isPointInside(v), "isPointInside(gvec2f)");
		HL_UT_ASSERT(r.isPointInside(v.x, v.y), "isPointInside(float, float)");
	}

	HL_UT_TEST_FUNCTION(addition)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(1, 2);
		grectf r1 = r + v;
		HL_UT_ASSERT(r1.x == 1 && r1.y == 2, "");
	}

	HL_UT_TEST_FUNCTION(substraction)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(1, 2);
		grectf r1 = r - v;
		HL_UT_ASSERT(r1.x == -1 && r1.y == -2, "");
	}

	HL_UT_TEST_FUNCTION(multiplication)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(2, 4);
		grectf r1 = r * v;
		HL_UT_ASSERT(r1.w == 8 && r1.h == 16, "operator*(vector)");
		r1 = r * 2;
		HL_UT_ASSERT(r1.w == 8 && r1.h == 8, "operator*(float)");
	}

	HL_UT_TEST_FUNCTION(division)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(2, 4);
		grectf r1 = r / v;
		HL_UT_ASSERT(r1.w == 2 && r1.h == 1, "operator/(vector)");
		r1 = r / 2;
		HL_UT_ASSERT(r1.w == 2 && r1.h == 2, "operator/(float)");
	}

	HL_UT_TEST_FUNCTION(additionAssign)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(1, 2);
		r += v;
		HL_UT_ASSERT(r.x == 1 && r.y == 2, "");
	}

	HL_UT_TEST_FUNCTION(substractionAssign)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(1, 2);
		r -= v;
		HL_UT_ASSERT(r.x == -1 && r.y == -2, "");
	}

	HL_UT_TEST_FUNCTION(multiplicationAssign)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(2, 4);
		r *= v;
		HL_UT_ASSERT(r.w == 8 && r.h == 16, "operator*=(vector)");
		r = grectf(0, 0, 4, 4);
		r *= 2;
		HL_UT_ASSERT(r.w == 8 && r.h == 8, "operator*=(float)");
	}

	HL_UT_TEST_FUNCTION(divisionAssign)
	{
		grectf r(0, 0, 4, 4);
		gvec2f v(2, 4);
		r /= v;
		HL_UT_ASSERT(r.w == 2 && r.h == 1, "operator/=(vector)");
		r = grectf(0, 0, 4, 4);
		r /= 2;
		HL_UT_ASSERT(r.w == 2 && r.h == 2, "operator/=(float)");
	}
	
	HL_UT_TEST_FUNCTION(equal)
	{
		grectf r1(0, 0, 4, 4);
		grectf r2(0, 0, 4, 4);
		HL_UT_ASSERT(r1 == r2, "");
	}

	HL_UT_TEST_FUNCTION(notEqual)
	{
		grectf r1(0, 0, 4, 4);
		grectf r2(0, 0, 4, 3);
		HL_UT_ASSERT(r1 != r2, "");
	}

}
