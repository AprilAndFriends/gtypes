#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

#include "Vector2.h"

#define E_TOLRANCE 0.0001f

HL_UT_TEST_CLASS(Vector2)
{
	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance = E_TOLRANCE)
	{
		return (habs(a - b) < tolerance);
	}

	static bool vec2eqf(const gvec2& v1, const gvec2& v2)
	{
		return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y));
	}

	HL_UT_TEST_FUNCTION(assignment)
	{
		gvec2 v(1, 2);
		HL_UT_ASSERT(v.x == 1 && v.y == 2, "constructor assignment");
		v.set(2, 3);
		HL_UT_ASSERT(v.x == 2 && v.y == 3, "set()");
	}

	HL_UT_TEST_FUNCTION(addition)
	{
		gvec2 v1(1, 2), v2(2, 3);
		gvec2 v3 = v1 + v2;
		HL_UT_ASSERT(v3.x == 3 && v3.y == 5, "");
	}

	HL_UT_TEST_FUNCTION(zeroLength)
	{
		gvec2 v(0, 0);
		HL_UT_ASSERT(v.isNull(), "");
	}

	HL_UT_TEST_FUNCTION(length)
	{
		gvec2 v(2, 0);
		HL_UT_ASSERT(v.length() == 2, "");
	}

	HL_UT_TEST_FUNCTION(squaredLength)
	{
		gvec2 v(2, 2);
		HL_UT_ASSERT(v.squaredLength() == 8, "");
	}

	HL_UT_TEST_FUNCTION(angle)
	{
		gvec2 v(1, 0);
		HL_UT_ASSERT(v.angle() == 0, "");
	}

	HL_UT_TEST_FUNCTION(normalize)
	{
		gvec2 v1(2, 0);
		gvec2 v2(1, 0);
		v1.normalize();
		HL_UT_ASSERT(v1 == v2, "");
	}

	HL_UT_TEST_FUNCTION(normalized)
	{
		gvec2 v1(2, 0);
		gvec2 v2(1, 0);
		HL_UT_ASSERT(v1.normalized() == v2, "");
	}

	HL_UT_TEST_FUNCTION(rotate)
	{
		gvec2 v1(1, 0);
		gvec2 v2(0, 1);
		v1.rotate(90);
		HL_UT_ASSERT(vec2eqf(v1, v2), "");
	}

	HL_UT_TEST_FUNCTION(rotated)
	{
		gvec2 v1(1, 0);
		gvec2 v2(0, 1);
		HL_UT_ASSERT(vec2eqf(v1.rotated(90), v2), "");
	}

	HL_UT_TEST_FUNCTION(dot)
	{
		gvec2 v1(1, 0);
		gvec2 v2(0.5, 0.5);
		float dot = v2.dot(v1);
		HL_UT_ASSERT(heqf(dot, v1.x * v2.x + v1.y * v2.y), "");
	}

	HL_UT_TEST_FUNCTION(negation)
	{
		gvec2 v(3, 4);
		v = -v;
		HL_UT_ASSERT(v.x == -3 && v.y == -4, "");
	}

	HL_UT_TEST_FUNCTION(substraction)
	{
		gvec2 v1(3, 4);
		gvec2 v2(1, 2);
		gvec2 v = v1 - v2;
		HL_UT_ASSERT(v.x == 2 && v.y == 2, "");
	}

	HL_UT_TEST_FUNCTION(multiplicationVector)
	{
		gvec2 v1(1, 2);
		gvec2 v2(2, 4);
		gvec2 v = v1*v2;
		HL_UT_ASSERT(v.x == 2 && v.y == 8, "");
	}

	HL_UT_TEST_FUNCTION(divisionVector)
	{
		gvec2 v1(4, 6);
		gvec2 v2(2, 3);
		gvec2 v = v1 / v2;
		HL_UT_ASSERT(v.x == 2 && v.y == 2, "");
	}

	HL_UT_TEST_FUNCTION(multiplication)
	{
		gvec2 v(1, 2);
		v = v * 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HL_UT_TEST_FUNCTION(division)
	{
		gvec2 v(4, 8);
		v = v / 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HL_UT_TEST_FUNCTION(additionAssign)
	{
		gvec2 v1(1, 2), v2(2, 3);
		v1 += v2;
		HL_UT_ASSERT(v1.x == 3 && v1.y == 5, "");
	}

	HL_UT_TEST_FUNCTION(substractionAssign)
	{
		gvec2 v1(3, 4);
		gvec2 v2(1, 2);
		v1 -= v2;
		HL_UT_ASSERT(v1.x == 2 && v1.y == 2, "");
	}

	HL_UT_TEST_FUNCTION(multiplicationVectorAssign)
	{
		gvec2 v1(1, 2);
		gvec2 v2(2, 4);
		v1 *= v2;
		HL_UT_ASSERT(v1.x == 2 && v1.y == 8, "");
	}

	HL_UT_TEST_FUNCTION(divisionVectorAssign)
	{
		gvec2 v1(4, 6);
		gvec2 v2(2, 3);
		v1 /= v2;
		HL_UT_ASSERT(v1.x == 2 && v1.y == 2, "");
	}

	HL_UT_TEST_FUNCTION(multiplicationAssign)
	{
		gvec2 v(1, 2);
		v *= 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HL_UT_TEST_FUNCTION(divisionAssign)
	{
		gvec2 v(4, 8);
		v /= 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HL_UT_TEST_FUNCTION(equal)
	{
		gvec2 v1(4, 6);
		gvec2 v2(4, 6);
		HL_UT_ASSERT(v1 == v2, "");
	}

	HL_UT_TEST_FUNCTION(notEqual)
	{
		gvec2 v1(4, 6);
		gvec2 v2(2, 3);
		HL_UT_ASSERT(v1 != v2, "");
	}

}
