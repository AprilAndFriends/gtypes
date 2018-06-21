#define __HTEST_LIB_NAME gtypes
#ifdef __APPLE__
#import "htest.h"
#else
#include "htest.h"
#endif

#include "Vector2.h"

#define E_TOLRANCE 0.0001f

HTEST_CLASS(Vector2)
{
	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance = E_TOLRANCE)
	{
		return (habs(a - b) < tolerance);
	}

	static bool vec2eqf(const gvec2f& v1, const gvec2f& v2)
	{
		return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y));
	}

	HTEST_FUNCTION(assignment)
	{
		gvec2f v(1, 2);
		HTEST_ASSERT(v.x == 1 && v.y == 2, "constructor assignment");
		v.set(2, 3);
		HTEST_ASSERT(v.x == 2 && v.y == 3, "set()");
	}

	HTEST_FUNCTION(addition)
	{
		gvec2f v1(1, 2), v2(2, 3);
		gvec2f v3 = v1 + v2;
		HTEST_ASSERT(v3.x == 3 && v3.y == 5, "");
	}

	HTEST_FUNCTION(zeroLength)
	{
		gvec2f v(0, 0);
		HTEST_ASSERT(v.isNull(), "");
	}

	HTEST_FUNCTION(length)
	{
		gvec2f v(2, 0);
		HTEST_ASSERT(v.length() == 2, "");
	}

	HTEST_FUNCTION(squaredLength)
	{
		gvec2f v(2, 2);
		HTEST_ASSERT(v.squaredLength() == 8, "");
	}

	HTEST_FUNCTION(angle)
	{
		gvec2f v(1, 0);
		HTEST_ASSERT(v.angle() == 0, "");
	}

	HTEST_FUNCTION(normalize)
	{
		gvec2f v1(2, 0);
		gvec2f v2(1, 0);
		v1.normalize();
		HTEST_ASSERT(v1 == v2, "");
	}

	HTEST_FUNCTION(normalized)
	{
		gvec2f v1(2, 0);
		gvec2f v2(1, 0);
		HTEST_ASSERT(v1.normalized() == v2, "");
	}

	HTEST_FUNCTION(rotate)
	{
		gvec2f v1(1, 0);
		gvec2f v2(0, 1);
		v1.rotate(90);
		HTEST_ASSERT(vec2eqf(v1, v2), "");
	}

	HTEST_FUNCTION(rotated)
	{
		gvec2f v1(1, 0);
		gvec2f v2(0, 1);
		HTEST_ASSERT(vec2eqf(v1.rotated(90), v2), "");
	}

	HTEST_FUNCTION(dot)
	{
		gvec2f v1(1, 0);
		gvec2f v2(0.5, 0.5);
		float dot = v2.dot(v1);
		HTEST_ASSERT(heqf(dot, v1.x * v2.x + v1.y * v2.y), "");
	}

	HTEST_FUNCTION(negation)
	{
		gvec2f v(3, 4);
		v = -v;
		HTEST_ASSERT(v.x == -3 && v.y == -4, "");
	}

	HTEST_FUNCTION(substraction)
	{
		gvec2f v1(3, 4);
		gvec2f v2(1, 2);
		gvec2f v = v1 - v2;
		HTEST_ASSERT(v.x == 2 && v.y == 2, "");
	}

	HTEST_FUNCTION(multiplicationVector)
	{
		gvec2f v1(1, 2);
		gvec2f v2(2, 4);
		gvec2f v = v1*v2;
		HTEST_ASSERT(v.x == 2 && v.y == 8, "");
	}

	HTEST_FUNCTION(divisionVector)
	{
		gvec2f v1(4, 6);
		gvec2f v2(2, 3);
		gvec2f v = v1 / v2;
		HTEST_ASSERT(v.x == 2 && v.y == 2, "");
	}

	HTEST_FUNCTION(multiplication)
	{
		gvec2f v(1, 2);
		v = v * 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HTEST_FUNCTION(division)
	{
		gvec2f v(4, 8);
		v = v / 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HTEST_FUNCTION(additionAssign)
	{
		gvec2f v1(1, 2), v2(2, 3);
		v1 += v2;
		HTEST_ASSERT(v1.x == 3 && v1.y == 5, "");
	}

	HTEST_FUNCTION(substractionAssign)
	{
		gvec2f v1(3, 4);
		gvec2f v2(1, 2);
		v1 -= v2;
		HTEST_ASSERT(v1.x == 2 && v1.y == 2, "");
	}

	HTEST_FUNCTION(multiplicationVectorAssign)
	{
		gvec2f v1(1, 2);
		gvec2f v2(2, 4);
		v1 *= v2;
		HTEST_ASSERT(v1.x == 2 && v1.y == 8, "");
	}

	HTEST_FUNCTION(divisionVectorAssign)
	{
		gvec2f v1(4, 6);
		gvec2f v2(2, 3);
		v1 /= v2;
		HTEST_ASSERT(v1.x == 2 && v1.y == 2, "");
	}

	HTEST_FUNCTION(multiplicationAssign)
	{
		gvec2f v(1, 2);
		v *= 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HTEST_FUNCTION(divisionAssign)
	{
		gvec2f v(4, 8);
		v /= 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4, "");
	}

	HTEST_FUNCTION(equal)
	{
		gvec2f v1(4, 6);
		gvec2f v2(4, 6);
		HTEST_ASSERT(v1 == v2, "");
	}

	HTEST_FUNCTION(notEqual)
	{
		gvec2f v1(4, 6);
		gvec2f v2(2, 3);
		HTEST_ASSERT(v1 != v2, "");
	}

}
