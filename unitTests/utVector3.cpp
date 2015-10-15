#include "generated/aprilUT.h"
#include "Vector3.h"

namespace testVector3
{	
	float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	bool heqf(float a, float b, float tolerance)
	{
		return (habs(a - b) < tolerance);
	}

	const float tolerance = 0.1f;

	bool vec3eqf(gvec3 v1, gvec3 v2)
	{
		if (heqf(v1.x, v2.x, tolerance) && heqf(v1.y, v2.y, tolerance) && heqf(v1.z, v2.z, tolerance))
			return true;
		return false;
	}

    void testAssignment()
    {
        gvec3 v(1, 2, 3);
		assertTrue(v.x == 1 && v.y == 2 && v.z == 3, "gvec3::testAssignment - constructor assignment");
        v.set(2, 3, 4);
		assertTrue(v.x == 2 && v.y == 3 && v.z == 4, "gvec3::testAssignment - set()");
    }

    void testAddition()
    {
        gvec3 v1(1, 2, 3), v2(2, 3, 4);
        gvec3 v3 = v1 + v2;
        assertTrue(v3.x == 3 && v3.y == 5 && v3.z == 7, "gvec3::testAddition - set()");
    }

	void testZeroLength()
	{
		gvec3 v(0, 0, 0);
		assertTrue(v.isNull(), "gvec3::testZeroLength - isNull()");
	}

	void testLength()
	{
		gvec3 v(2, 0, 0);
		assertTrue(v.length() == 2, "gvec3::testLength - length()");
	}

	void testSquaredLength()
	{
		gvec3 v(2, 2, 0);
		assertTrue(v.squaredLength() == 8, "gvec3::testSquaredLength - squaredLength()");
	}

	void testNormalization()
	{
		gvec3 v1(2, 0, 0);
		gvec3 v2(1, 0, 0);
		v1.normalize();
		assertTrue(v1 == v2, "gvec3::testNormalization - normalize()");
	}

	void testNormalized()
	{
		gvec3 v1(2, 0, 0);
		gvec3 v2(1, 0, 0);
		assertTrue(v1.normalized() == v2, "gvec3::testNormalized - normalized()");
	}

	void testDot()
	{
		gvec3 v1(1, 0, 0);
		gvec3 v2(0.5, 0.5, 0.5);
		float dot = v2.dot(v1);
		assertTrue(heqf(dot, v1.x*v2.x + v1.y*v2.y + v1.z*v2.z, tolerance), "gvec3::testDot - dot()");
	}

	void testCross()
	{
		gvec3 v1(1, 0, 0);
		gvec3 v2(0, 0, 1);
		gvec3 v3(0, 1, 0);

		assertTrue(v1.cross(v2) == v3, "gvec3::testCross - cross()");
	}

	void testNegation()
	{
		gvec3 v(3, 4, 5);
		v = -v;
		assertTrue(v.x == -3 && v.y == -4 && v.z == -5, "gvec3::testNegation - set()");
	}

	void testSubstraction()
	{
		gvec3 v1(3, 4, 5);
		gvec3 v2(1, 2, 3);

		gvec3 v = v1 - v2;

		assertTrue(v.x == 2 && v.y == 2 && v.z == 2, "gvec3::testSubstraction - set()");
	}

	void testMultiplicationVector()
	{
		gvec3 v1(1, 2, 3);
		gvec3 v2(2, 4, 5);

		gvec3 v = v1*v2;
		assertTrue(v.x == 2 && v.y == 8 && v.z == 15, "gvec3::testMultiplicationVector - set()");
	}

	void testDivisionVector()
	{
		gvec3 v1(4, 6, 8);
		gvec3 v2(2, 3, 4);

		gvec3 v = v1/v2;
		assertTrue(v.x == 2 && v.y == 2 && v.z == 2, "gvec3::testDivisionVector - set()");
	}

	void testMultiplication()
	{
		gvec3 v(1, 2, 3);		

		v = v * 2;
		assertTrue(v.x == 2 && v.y == 4 && v.z == 6, "gvec3::testMultiplication - set()");
	}

	void testDivision()
	{
		gvec3 v(4, 8, 12);

		v = v / 2;
		assertTrue(v.x == 2 && v.y == 4 && v.z == 6, "gvec3::testDivision - set()");
	}
	
	void testAdditionAssign()
	{
		gvec3 v1(1, 2, 3), v2(2, 3, 4);
		v1 += v2;
		assertTrue(v1.x == 3 && v1.y == 5 && v1.z == 7, "gvec3::testAdditionAssign - set()");
	}

	void testSubstractionAssign()
	{
		gvec3 v1(3, 4, 5);
		gvec3 v2(1, 2, 3);

		v1 -= v2;

		assertTrue(v1.x == 2 && v1.y == 2 && v1.z == 2, "gvec3::testSubstractionAssign - set()");
	}

	void testMultiplicationVectorAssign()
	{
		gvec3 v1(1, 2, 3);
		gvec3 v2(2, 4, 5);

		v1 *= v2;

		assertTrue(v1.x == 2 && v1.y == 8 && v1.z == 15, "gvec3::testMultiplicationVectorAssign - set()");
	}

	void testDivisionVectorAssign()
	{
		gvec3 v1(4, 6, 8);
		gvec3 v2(2, 3, 4);

		v1 /= v2;

		assertTrue(v1.x == 2 && v1.y == 2 && v1.z == 2, "gvec3::testDivisionVectorAssign - set()");
	}

	void testMultiplicationAssign()
	{
		gvec3 v(1, 2, 3);

		v *= 2;

		assertTrue(v.x == 2 && v.y == 4 && v.z == 6, "gvec3::testMultiplicationAssign - set()");
	}

	void testDivisionAssign()
	{
		gvec3 v(4, 8, 12);

		v /= 2;

		assertTrue(v.x == 2 && v.y == 4 && v.z == 6, "gvec3::testDivisionAssign - set()");
	}

	void testEqual()
	{
		gvec3 v1(4, 6, 8);
		gvec3 v2(4, 6, 8);

		assertTrue(v1 == v2, "gvec3::testEqual - set()");
	}

	void testNotEqual()
	{
		gvec3 v1(4, 6, 8);
		gvec3 v2(2, 3, 4);

		assertTrue(v1 != v2, "gvec3::testNotEqual - set()");
	}
}
