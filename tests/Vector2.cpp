#define _HTEST_LIB gtypes
#define _HTEST_CLASS Vector2
#include <htest/htest.h>

#include "Vector2.h"

#define E_TOLRANCE 0.0001f

//static float _habs(float value)
//{
//	return value >= 0.0f ? value : -value;
//}
//
//static bool _heqf(float a, float b, float tolerance = E_TOLRANCE)
//{
//	return (habs(a - b) < tolerance);
//}

static bool vec2eqf(const gvec2f& v1, const gvec2f& v2)
{
	return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y));
}

HTEST_SUITE_BEGIN

HTEST_CASE(assignment)
{
	gvec2f v(1, 2);
	HTEST_ASSERT(v.x == 1 && v.y == 2, "constructor assignment");
	v.set(2, 3);
	HTEST_ASSERT(v.x == 2 && v.y == 3, "set()");
}

HTEST_CASE(addition)
{
	gvec2f v1(1, 2), v2(2, 3);
	gvec2f v3 = v1 + v2;
	HTEST_ASSERT(v3.x == 3 && v3.y == 5, "");
}

HTEST_CASE(zeroLength)
{
	gvec2f v(0, 0);
	HTEST_ASSERT(v.isNull(), "");
}

HTEST_CASE(length)
{
	gvec2f v(2, 0);
	HTEST_ASSERT(v.length() == 2, "");
}

HTEST_CASE(squaredLength)
{
	gvec2f v(2, 2);
	HTEST_ASSERT(v.squaredLength() == 8, "");
}

HTEST_CASE(angle)
{
	gvec2f v(1, 0);
	HTEST_ASSERT(v.angle() == 0, "");
}

HTEST_CASE(normalize)
{
	gvec2f v1(2, 0);
	gvec2f v2(1, 0);
	v1.normalize();
	HTEST_ASSERT(v1 == v2, "");
}

HTEST_CASE(normalized)
{
	gvec2f v1(2, 0);
	gvec2f v2(1, 0);
	HTEST_ASSERT(v1.normalized() == v2, "");
}

HTEST_CASE(rotate)
{
	gvec2f v1(1, 0);
	gvec2f v2(0, 1);
	v1.rotate(90);
	HTEST_ASSERT(vec2eqf(v1, v2), "");
}

HTEST_CASE(rotated)
{
	gvec2f v1(1, 0);
	gvec2f v2(0, 1);
	HTEST_ASSERT(vec2eqf(v1.rotated(90), v2), "");
}

HTEST_CASE(dot)
{
	gvec2f v1(1, 0);
	gvec2f v2(0.5, 0.5);
	float dot = v2.dot(v1);
	HTEST_ASSERT(heqf(dot, v1.x * v2.x + v1.y * v2.y), "");
}

HTEST_CASE(negation)
{
	gvec2f v(3, 4);
	v = -v;
	HTEST_ASSERT(v.x == -3 && v.y == -4, "");
}

HTEST_CASE(substraction)
{
	gvec2f v1(3, 4);
	gvec2f v2(1, 2);
	gvec2f v = v1 - v2;
	HTEST_ASSERT(v.x == 2 && v.y == 2, "");
}

HTEST_CASE(multiplicationVector)
{
	gvec2f v1(1, 2);
	gvec2f v2(2, 4);
	gvec2f v = v1*v2;
	HTEST_ASSERT(v.x == 2 && v.y == 8, "");
}

HTEST_CASE(divisionVector)
{
	gvec2f v1(4, 6);
	gvec2f v2(2, 3);
	gvec2f v = v1 / v2;
	HTEST_ASSERT(v.x == 2 && v.y == 2, "");
}

HTEST_CASE(multiplication)
{
	gvec2f v(1, 2);
	v = v * 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4, "");
}

HTEST_CASE(division)
{
	gvec2f v(4, 8);
	v = v / 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4, "");
}

HTEST_CASE(additionAssign)
{
	gvec2f v1(1, 2), v2(2, 3);
	v1 += v2;
	HTEST_ASSERT(v1.x == 3 && v1.y == 5, "");
}

HTEST_CASE(substractionAssign)
{
	gvec2f v1(3, 4);
	gvec2f v2(1, 2);
	v1 -= v2;
	HTEST_ASSERT(v1.x == 2 && v1.y == 2, "");
}

HTEST_CASE(multiplicationVectorAssign)
{
	gvec2f v1(1, 2);
	gvec2f v2(2, 4);
	v1 *= v2;
	HTEST_ASSERT(v1.x == 2 && v1.y == 8, "");
}

HTEST_CASE(divisionVectorAssign)
{
	gvec2f v1(4, 6);
	gvec2f v2(2, 3);
	v1 /= v2;
	HTEST_ASSERT(v1.x == 2 && v1.y == 2, "");
}

HTEST_CASE(multiplicationAssign)
{
	gvec2f v(1, 2);
	v *= 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4, "");
}

HTEST_CASE(divisionAssign)
{
	gvec2f v(4, 8);
	v /= 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4, "");
}

HTEST_CASE(equal)
{
	gvec2f v1(4, 6);
	gvec2f v2(4, 6);
	HTEST_ASSERT(v1 == v2, "");
}

HTEST_CASE(notEqual)
{
	gvec2f v1(4, 6);
	gvec2f v2(2, 3);
	HTEST_ASSERT(v1 != v2, "");
}

HTEST_SUITE_END
