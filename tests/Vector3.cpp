#define __HTEST_LIB_NAME gtypes
#ifdef __APPLE__
#import "htest.h"
#else
#include "htest.h"
#endif

#include "Vector3.h"

#define E_TOLRANCE 0.0001f

HTEST_CLASS(Vector3)
{
	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance = E_TOLRANCE)
	{
		return (habs(a - b) < tolerance);
	}

	static bool vec3eqf(const gvec3f& v1, const gvec3f& v2)
	{
		return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y) && heqf(v1.z, v2.z));
	}

	HTEST_FUNCTION(assignment)
	{
		gvec3f v(1.0f, 2.0f, 3.0f);
		HTEST_ASSERT(v.x == 1.0f && v.y == 2.0f && v.z == 3.0f, "constructor assignment");
		v.set(2.0f, 3.0f, 4.0f);
		HTEST_ASSERT(v.x == 2.0f && v.y == 3.0f && v.z == 4.0f, "set()");
	}

	HTEST_FUNCTION(addition)
	{
		gvec3f v1(1.0f, 2.0f, 3.0f), v2(2.0f, 3.0f, 4.0f);
		gvec3f v3 = v1 + v2;
		HTEST_ASSERT(v3.x == 3.0f && v3.y == 5.0f && v3.z == 7.0f, "");
	}

	HTEST_FUNCTION(zeroLength)
	{
		gvec3f v(0.0f, 0.0f, 0.0f);
		HTEST_ASSERT(v.isNull(), "");
	}

	HTEST_FUNCTION(length)
	{
		gvec3f v(2.0f, 0.0f, 0.0f);
		HTEST_ASSERT(v.length() == 2.0f, "");
	}

	HTEST_FUNCTION(squaredLength)
	{
		gvec3f v(2.0f, 2.0f, 0.0f);
		HTEST_ASSERT(v.squaredLength() == 8.0f, "");
	}

	HTEST_FUNCTION(normalize)
	{
		gvec3f v1(2.0f, 0.0f, 0.0f);
		gvec3f v2(1.0f, 0.0f, 0.0f);
		v1.normalize();
		HTEST_ASSERT(v1 == v2, "");
	}

	HTEST_FUNCTION(normalized)
	{
		gvec3f v1(1.0f, -1.0f, 0.0f);
		gvec3f v2(0.707107f, -0.707107f, 0.0f);
		HTEST_ASSERT(vec3eqf(v1.normalized(), v2), "");
	}

	HTEST_FUNCTION(dot)
	{
		gvec3f v1(1.0f, 0.0f, 0.0f);
		gvec3f v2(0.5f, 0.5f, 0.5f);
		float dot = v2.dot(v1);
		HTEST_ASSERT(heqf(dot, v1.x * v2.x + v1.y * v2.y + v1.z * v2.z), "");
	}

	HTEST_FUNCTION(cross)
	{
		gvec3f v1(1.0f, 0.0f, 0.0f);
		gvec3f v2(0.0f, 0.0f, 1.0f);
		gvec3f v3(0.0f, -1.0f, 0.0f);
		HTEST_ASSERT(vec3eqf(v1.cross(v2), v3), "");
	}

	HTEST_FUNCTION(negation)
	{
		gvec3f v1(3.0f, 4.0f, 5.0f);
		gvec3f v2(-3.0f, -4.0f, -5.0f);
		v1 = -v1;
		HTEST_ASSERT(vec3eqf(v1, v2), "");
	}

	HTEST_FUNCTION(substraction)
	{
		gvec3f v1(3.0f, 4.0f, 5.0f);
		gvec3f v2(1.0f, 2.0f, 3.0f);
		gvec3f v = v1 - v2;
		HTEST_ASSERT(v.x == 2.0f && v.y == 2.0f && v.z == 2.0f, "");
	}

	HTEST_FUNCTION(multiplicationVector)
	{
		gvec3f v1(1.0f, 2.0f, 3.0f);
		gvec3f v2(2.0f, 4.0f, 5.0f);
		gvec3f v = v1 * v2;
		HTEST_ASSERT(v.x == 2 && v.y == 8 && v.z == 15, "");
	}

	HTEST_FUNCTION(divisionVector)
	{
		gvec3f v1(4.0f, 6.0f, 8.0f);
		gvec3f v2(2.0f, 3.0f, 4.0f);
		gvec3f v = v1 / v2;
		HTEST_ASSERT(v.x == 2 && v.y == 2 && v.z == 2, "");
	}

	HTEST_FUNCTION(multiplication)
	{
		gvec3f v(1, 2, 3);
		v = v * 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HTEST_FUNCTION(division)
	{
		gvec3f v(4, 8, 12);
		v = v / 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HTEST_FUNCTION(additionAssign)
	{
		gvec3f v1(1, 2, 3), v2(2, 3, 4);
		v1 += v2;
		HTEST_ASSERT(v1.x == 3 && v1.y == 5 && v1.z == 7, "");
	}

	HTEST_FUNCTION(substractionAssign)
	{
		gvec3f v1(3, 4, 5);
		gvec3f v2(1, 2, 3);
		v1 -= v2;
		HTEST_ASSERT(v1.x == 2 && v1.y == 2 && v1.z == 2, "");
	}

	HTEST_FUNCTION(multiplicationVectorAssign)
	{
		gvec3f v1(1, 2, 3);
		gvec3f v2(2, 4, 5);
		v1 *= v2;
		HTEST_ASSERT(v1.x == 2 && v1.y == 8 && v1.z == 15, "");
	}

	HTEST_FUNCTION(divisionVectorAssign)
	{
		gvec3f v1(4, 6, 8);
		gvec3f v2(2, 3, 4);
		v1 /= v2;
		HTEST_ASSERT(v1.x == 2 && v1.y == 2 && v1.z == 2, "");
	}

	HTEST_FUNCTION(multiplicationAssign)
	{
		gvec3f v(1, 2, 3);
		v *= 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HTEST_FUNCTION(divisionAssign)
	{
		gvec3f v(4, 8, 12);
		v /= 2;
		HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HTEST_FUNCTION(equal)
	{
		gvec3f v1(4, 6, 8);
		gvec3f v2(4, 6, 8);
		HTEST_ASSERT(v1 == v2, "");
	}

	HTEST_FUNCTION(notEqual)
	{
		gvec3f v1(4, 6, 8);
		gvec3f v2(2, 3, 4);
		HTEST_ASSERT(v1 != v2, "");
	}

}
