#define _HTEST_LIB gtypes
#define _HTEST_CLASS Vector3
#include "htest.h"

#include "Vector3.h"

#define E_TOLRANCE 0.0001f


static bool vec3eqf(const gvec3f& v1, const gvec3f& v2)
{
	return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y) && heqf(v1.z, v2.z));
}

HTEST_SUITE_BEGIN

HTEST_CASE(assignment)
{
	gvec3f v(1.0f, 2.0f, 3.0f);
	HTEST_ASSERT(v.x == 1.0f && v.y == 2.0f && v.z == 3.0f, "constructor assignment");
	v.set(2.0f, 3.0f, 4.0f);
	HTEST_ASSERT(v.x == 2.0f && v.y == 3.0f && v.z == 4.0f, "set()");
}

HTEST_CASE(addition)
{
	gvec3f v1(1.0f, 2.0f, 3.0f), v2(2.0f, 3.0f, 4.0f);
	gvec3f v3 = v1 + v2;
	HTEST_ASSERT(v3.x == 3.0f && v3.y == 5.0f && v3.z == 7.0f, "");
}

HTEST_CASE(zeroLength)
{
	gvec3f v(0.0f, 0.0f, 0.0f);
	HTEST_ASSERT(v.isNull(), "");
}

HTEST_CASE(length)
{
	gvec3f v(2.0f, 0.0f, 0.0f);
	HTEST_ASSERT(v.length() == 2.0f, "");
}

HTEST_CASE(squaredLength)
{
	gvec3f v(2.0f, 2.0f, 0.0f);
	HTEST_ASSERT(v.squaredLength() == 8.0f, "");
}

HTEST_CASE(normalize)
{
	gvec3f v1(2.0f, 0.0f, 0.0f);
	gvec3f v2(1.0f, 0.0f, 0.0f);
	v1.normalize();
	HTEST_ASSERT(v1 == v2, "");
}

HTEST_CASE(normalized)
{
	gvec3f v1(1.0f, -1.0f, 0.0f);
	gvec3f v2(0.707107f, -0.707107f, 0.0f);
	HTEST_ASSERT(vec3eqf(v1.normalized(), v2), "");
}

HTEST_CASE(dot)
{
	gvec3f v1(1.0f, 0.0f, 0.0f);
	gvec3f v2(0.5f, 0.5f, 0.5f);
	float dot = v2.dot(v1);
	HTEST_ASSERT(heqf(dot, v1.x * v2.x + v1.y * v2.y + v1.z * v2.z), "");
}

HTEST_CASE(cross)
{
	gvec3f v1(1.0f, 0.0f, 0.0f);
	gvec3f v2(0.0f, 0.0f, 1.0f);
	gvec3f v3(0.0f, -1.0f, 0.0f);
	HTEST_ASSERT(vec3eqf(v1.cross(v2), v3), "");
}

HTEST_CASE(negation)
{
	gvec3f v1(3.0f, 4.0f, 5.0f);
	gvec3f v2(-3.0f, -4.0f, -5.0f);
	v1 = -v1;
	HTEST_ASSERT(vec3eqf(v1, v2), "");
}

HTEST_CASE(substraction)
{
	gvec3f v1(3.0f, 4.0f, 5.0f);
	gvec3f v2(1.0f, 2.0f, 3.0f);
	gvec3f v = v1 - v2;
	HTEST_ASSERT(v.x == 2.0f && v.y == 2.0f && v.z == 2.0f, "");
}

HTEST_CASE(multiplicationVector)
{
	gvec3f v1(1.0f, 2.0f, 3.0f);
	gvec3f v2(2.0f, 4.0f, 5.0f);
	gvec3f v = v1 * v2;
	HTEST_ASSERT(v.x == 2 && v.y == 8 && v.z == 15, "");
}

HTEST_CASE(divisionVector)
{
	gvec3f v1(4.0f, 6.0f, 8.0f);
	gvec3f v2(2.0f, 3.0f, 4.0f);
	gvec3f v = v1 / v2;
	HTEST_ASSERT(v.x == 2 && v.y == 2 && v.z == 2, "");
}

HTEST_CASE(multiplication)
{
	gvec3f v(1, 2, 3);
	v = v * 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
}

HTEST_CASE(division)
{
	gvec3f v(4, 8, 12);
	v = v / 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
}

HTEST_CASE(additionAssign)
{
	gvec3f v1(1, 2, 3), v2(2, 3, 4);
	v1 += v2;
	HTEST_ASSERT(v1.x == 3 && v1.y == 5 && v1.z == 7, "");
}

HTEST_CASE(substractionAssign)
{
	gvec3f v1(3, 4, 5);
	gvec3f v2(1, 2, 3);
	v1 -= v2;
	HTEST_ASSERT(v1.x == 2 && v1.y == 2 && v1.z == 2, "");
}

HTEST_CASE(multiplicationVectorAssign)
{
	gvec3f v1(1, 2, 3);
	gvec3f v2(2, 4, 5);
	v1 *= v2;
	HTEST_ASSERT(v1.x == 2 && v1.y == 8 && v1.z == 15, "");
}

HTEST_CASE(divisionVectorAssign)
{
	gvec3f v1(4, 6, 8);
	gvec3f v2(2, 3, 4);
	v1 /= v2;
	HTEST_ASSERT(v1.x == 2 && v1.y == 2 && v1.z == 2, "");
}

HTEST_CASE(multiplicationAssign)
{
	gvec3f v(1, 2, 3);
	v *= 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
}

HTEST_CASE(divisionAssign)
{
	gvec3f v(4, 8, 12);
	v /= 2;
	HTEST_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
}

HTEST_CASE(equal)
{
	gvec3f v1(4, 6, 8);
	gvec3f v2(4, 6, 8);
	HTEST_ASSERT(v1 == v2, "");
}

HTEST_CASE(notEqual)
{
	gvec3f v1(4, 6, 8);
	gvec3f v2(2, 3, 4);
	HTEST_ASSERT(v1 != v2, "");
}

HTEST_SUITE_END
