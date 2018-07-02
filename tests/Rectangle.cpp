#define _HTEST_LIB gtypes
#define _HTEST_CLASS Rectangle
#include "htest.h"

#include "Rectangle.h"
#include "Vector2.h"

#define E_TOLRANCE 0.0001f

HTEST_SUITE_BEGIN

HTEST_CASE(assignment)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.x == 1 && r.y == 2 && r.w == 3 && r.h == 4, "constructor assignment");
	r.set(2, 3, 4, 5);
	HTEST_ASSERT(r.x == 2 && r.y == 3 && r.w == 4 && r.h == 5, "set()");
}

HTEST_CASE(getPosition)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.getPosition().x == 1 && r.getPosition().y == 2, "");
}

HTEST_CASE(setPosition)
{
	grectf r(1, 2, 3, 4);
	r.setPosition(5, 6);
	HTEST_ASSERT(r.getPosition().x == 5 && r.getPosition().y == 6, "setPosition(float, float)");
	r.setPosition(gvec2f(7, 8));
	HTEST_ASSERT(r.getPosition().x == 7 && r.getPosition().y == 8, "setPosition(gvec2f)");
}

HTEST_CASE(getSize)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.getSize().x == 3 && r.getSize().y == 4, "");
}

HTEST_CASE(setSize)
{
	grectf r(1, 2, 3, 4);
	r.setSize(5, 6);
	HTEST_ASSERT(r.getSize().x == 5 && r.getSize().y == 6, "setSize(float, float)");
	r.setSize(gvec2f(7, 8));
	HTEST_ASSERT(r.getSize().x == 7 && r.getSize().y == 8, "setSize(gvec2f)");
}

HTEST_CASE(getCenter)
{
	grectf r(2, 2, 2, 2);
	HTEST_ASSERT(r.getCenter().x == 3 && r.getCenter().y == 3, "");
}

HTEST_CASE(getAspect)
{
	grectf r(0, 0, 4, 2);
	HTEST_ASSERT(r.getAspect() == 2, "");
}

HTEST_CASE(getTopLeft)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.getTopLeft().x == 1 && r.getTopLeft().y == 2, "");
}

HTEST_CASE(getTopRight)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.getTopRight().x == 4 && r.getTopRight().y == 2, "");
}

HTEST_CASE(getBottomLeft)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.getBottomLeft().x == 1 && r.getBottomLeft().y == 6, "");
}

HTEST_CASE(getBottomRight)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.getBottomRight().x == 4 && r.getBottomRight().y == 6, "");
}

HTEST_CASE(leftRightTopBottom)
{
	grectf r(1, 2, 3, 4);
	HTEST_ASSERT(r.left() == 1, "left()");
	HTEST_ASSERT(r.right() == 4, "right()");
	HTEST_ASSERT(r.top() == 2, "top()");
	HTEST_ASSERT(r.bottom() == 6, "bottom()");
}

HTEST_CASE(clipped)
{
	grectf r1(0, 0, 4, 4);
	grectf r2(1, 1, 4, 4);
	r2 = r2.clipped(r1);
	HTEST_ASSERT(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
		r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "");
}

HTEST_CASE(clip)
{
	grectf r1(0, 0, 4, 4);
	grectf r2(1, 1, 4, 4);
	r2.clip(r1);
	HTEST_ASSERT(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
		r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "");
}

HTEST_CASE(intersection)
{
	grectf r1(0, 0, 4, 4);
	grectf r2(3, 3, 2, 2);
	HTEST_ASSERT(r2.intersects(r1), "");
}

HTEST_CASE(contains)
{
	grectf r1(0, 0, 4, 4);
	grectf r2(1, 1, 2, 2);
	HTEST_ASSERT(r1.contains(r2), "");
}

HTEST_CASE(pointInside)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(1, 2);
	HTEST_ASSERT(r.isPointInside(v), "isPointInside(gvec2f)");
	HTEST_ASSERT(r.isPointInside(v.x, v.y), "isPointInside(float, float)");
}

HTEST_CASE(addition)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(1, 2);
	grectf r1 = r + v;
	HTEST_ASSERT(r1.x == 1 && r1.y == 2, "");
}

HTEST_CASE(substraction)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(1, 2);
	grectf r1 = r - v;
	HTEST_ASSERT(r1.x == -1 && r1.y == -2, "");
}

HTEST_CASE(multiplication)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(2, 4);
	grectf r1 = r * v;
	HTEST_ASSERT(r1.w == 8 && r1.h == 16, "operator*(vector)");
	r1 = r * 2;
	HTEST_ASSERT(r1.w == 8 && r1.h == 8, "operator*(float)");
}

HTEST_CASE(division)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(2, 4);
	grectf r1 = r / v;
	HTEST_ASSERT(r1.w == 2 && r1.h == 1, "operator/(vector)");
	r1 = r / 2;
	HTEST_ASSERT(r1.w == 2 && r1.h == 2, "operator/(float)");
}

HTEST_CASE(additionAssign)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(1, 2);
	r += v;
	HTEST_ASSERT(r.x == 1 && r.y == 2, "");
}

HTEST_CASE(substractionAssign)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(1, 2);
	r -= v;
	HTEST_ASSERT(r.x == -1 && r.y == -2, "");
}

HTEST_CASE(multiplicationAssign)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(2, 4);
	r *= v;
	HTEST_ASSERT(r.w == 8 && r.h == 16, "operator*=(vector)");
	r = grectf(0, 0, 4, 4);
	r *= 2;
	HTEST_ASSERT(r.w == 8 && r.h == 8, "operator*=(float)");
}

HTEST_CASE(divisionAssign)
{
	grectf r(0, 0, 4, 4);
	gvec2f v(2, 4);
	r /= v;
	HTEST_ASSERT(r.w == 2 && r.h == 1, "operator/=(vector)");
	r = grectf(0, 0, 4, 4);
	r /= 2;
	HTEST_ASSERT(r.w == 2 && r.h == 2, "operator/=(float)");
}

HTEST_CASE(equal)
{
	grectf r1(0, 0, 4, 4);
	grectf r2(0, 0, 4, 4);
	HTEST_ASSERT(r1 == r2, "");
}

HTEST_CASE(notEqual)
{
	grectf r1(0, 0, 4, 4);
	grectf r2(0, 0, 4, 3);
	HTEST_ASSERT(r1 != r2, "");
}

HTEST_SUITE_END
