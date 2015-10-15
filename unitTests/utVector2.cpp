#include "generated/aprilUT.h"
#include "Vector2.h"

namespace testVector2
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

	bool vec2eqf(gvec2 v1, gvec2 v2)
	{
		if (heqf(v1.x, v2.x, tolerance) && heqf(v1.y, v2.y, tolerance))
			return true;
		return false;
	}
    void testAssignment()
    {
        gvec2 v(1, 2);
        assertTrue(v.x == 1 && v.y == 2, "gvec2::testAssignment - constructor assignment");
        v.set(2, 3);
        assertTrue(v.x == 2 && v.y == 3, "gvec2::testAssignment - set()");
    }

    void testAddition()
    {
        gvec2 v1(1, 2), v2(2, 3);
        gvec2 v3 = v1 + v2;
        assertTrue(v3.x == 3 && v3.y == 5, "gvec2::testAddition - set()");
    }

	void testZeroLength()
	{
		gvec2 v(0, 0);
		assertTrue(v.isNull(), "gvec2::testZeroLength - isNull()");
	}

	void testLength()
	{
		gvec2 v(2, 0);
		assertTrue(v.length() == 2, "gvec2::testLength - length()");
	}

	void testSquaredLength()
	{
		gvec2 v(2, 2);
		assertTrue(v.squaredLength() == 8, "gvec2::testSquaredLength - squaredLength()");
	}

	void testAngle()
	{
		gvec2 v(1, 0);
		assertTrue(v.angle() == 0, "gvec2::testAngle - angle()");
	}

	void testNormalization()
	{
		gvec2 v1(2, 0);
		gvec2 v2(1, 0);
		v1.normalize();
		assertTrue(v1 == v2, "gvec2::testNormalization - normalize()");
	}

	void testNormalized()
	{
		gvec2 v1(2, 0);
		gvec2 v2(1, 0);
		assertTrue(v1.normalized() == v2, "gvec2::testNormalized - normalized()");
	}

	void testRotation()
	{
		gvec2 v1(1, 0);
		gvec2 v2(0, 1);
		v1.rotate(90);		
		assertTrue(vec2eqf(v1, v2), "gvec2::testRotation - rotate()");
	}

	void testRotated()
	{
		gvec2 v1(1, 0);
		gvec2 v2(0, 1);		
		assertTrue(vec2eqf(v1.rotated(90), v2), "gvec2::testRotation - rotate()");
	}

	void testDot()
	{
		gvec2 v1(1, 0);
		gvec2 v2(0.5, 0.5);
		float dot = v2.dot(v1);
		assertTrue(heqf(dot, v1.x*v2.x + v1.y*v2.y, tolerance), "gvec2::testDot - dot()");
	}

	void testNegation()
	{
		gvec2 v(3, 4);
		v = -v;
		assertTrue(v.x == -3 && v.y == -4, "gvec2::testNegation - set()");
	}

	void testSubstraction()
	{
		gvec2 v1(3, 4);
		gvec2 v2(1, 2);

		gvec2 v = v1 - v2;

		assertTrue(v.x == 2 && v.y == 2, "gvec2::testSubstraction - set()");
	}

	void testMultiplicationVector()
	{
		gvec2 v1(1, 2);
		gvec2 v2(2, 4);

		gvec2 v = v1*v2;
		assertTrue(v.x == 2 && v.y == 8, "gvec2::testMultiplicationVector - set()");
	}

	void testDivisionVector()
	{
		gvec2 v1(4, 6);
		gvec2 v2(2, 3);

		gvec2 v = v1/v2;
		assertTrue(v.x == 2 && v.y == 2, "gvec2::testDivisionVector - set()");
	}

	void testMultiplication()
	{
		gvec2 v(1, 2);		

		v = v * 2;
		assertTrue(v.x == 2 && v.y == 4, "gvec2::testMultiplication - set()");
	}

	void testDivision()
	{
		gvec2 v(4, 8);

		v = v / 2;
		assertTrue(v.x == 2 && v.y == 4, "gvec2::testDivision - set()");
	}
	
	void testAdditionAssign()
	{
		gvec2 v1(1, 2), v2(2, 3);
		v1 += v2;
		assertTrue(v1.x == 3 && v1.y == 5, "gvec2::testAdditionAssign - set()");
	}

	void testSubstractionAssign()
	{
		gvec2 v1(3, 4);
		gvec2 v2(1, 2);

		v1 -= v2;

		assertTrue(v1.x == 2 && v1.y == 2, "gvec2::testSubstractionAssign - set()");
	}

	void testMultiplicationVectorAssign()
	{
		gvec2 v1(1, 2);
		gvec2 v2(2, 4);

		v1 *= v2;

		assertTrue(v1.x == 2 && v1.y == 8, "gvec2::testMultiplicationVectorAssign - set()");
	}

	void testDivisionVectorAssign()
	{
		gvec2 v1(4, 6);
		gvec2 v2(2, 3);

		v1 /= v2;

		assertTrue(v1.x == 2 && v1.y == 2, "gvec2::testDivisionVectorAssign - set()");
	}

	void testMultiplicationAssign()
	{
		gvec2 v(1, 2);

		v *= 2;

		assertTrue(v.x == 2 && v.y == 4, "gvec2::testMultiplicationAssign - set()");
	}

	void testDivisionAssign()
	{
		gvec2 v(4, 8);

		v /= 2;

		assertTrue(v.x == 2 && v.y == 4, "gvec2::testDivisionAssign - set()");
	}

	void testEqual()
	{
		gvec2 v1(4, 6);
		gvec2 v2(4, 6);

		assertTrue(v1 == v2, "gvec2::testEqual - set()");
	}

	void testNotEqual()
	{
		gvec2 v1(4, 6);
		gvec2 v2(2, 3);

		assertTrue(v1 != v2, "gvec2::testNotEqual - set()");
	}
}
