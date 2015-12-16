#include "hunittest.h"
#include "Rectangle.h"

namespace gtypes_unittest
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

	bool rectangleEqf(grect r1, grect r2)
	{
		if (heqf(r1.x, r2.x, tolerance) && heqf(r1.y, r2.y, tolerance) && heqf(r1.w, r2.w, tolerance)
			&& heqf(r1.h, r2.h, tolerance))
			return true;
		return false;
	}

    void testRectangleAssignment()
    {
		grect r(1, 2, 3, 4);
		assertTrue(r.x == 1 && r.y == 2 && r.w == 3 && r.h == 4, "grect::testAssignment - constructor assignment");
        r.set(2, 3, 4, 5);
		assertTrue(r.x == 2 && r.y == 3 && r.w == 4 && r.h == 5, "grect::testAssignment - set()");
    }

	void testRectangleGetPosition()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getPosition().x == 1 && r.getPosition().y == 2, "grect::testGetPosition - getPosition()");
	}

	void testRectangleSetPosition()
	{
		grect r(1, 2, 3, 4);
		r.setPosition(5, 6);
		assertTrue(r.getPosition().x == 5 && r.getPosition().y == 6, "grect::testSetPosition - setPosition()");
		r.setPosition(gvec2(7, 8));
		assertTrue(r.getPosition().x == 7 && r.getPosition().y == 8, "grect::testSetPosition - setPosition()");
	}

	void testRectangleGetSize()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getSize().x == 3 && r.getSize().y == 4, "grect::testGetSize - getSize()");
	}

	void testRectangleSetSize()
	{
		grect r(1, 2, 3, 4);
		r.setSize(5, 6);
		assertTrue(r.getSize().x == 5 && r.getSize().y == 6, "grect::testSetSize - setSize()");
		r.setSize(gvec2(7, 8));
		assertTrue(r.getSize().x == 7 && r.getSize().y == 8, "grect::testSetSize - setSize()");
	}

	void testRectangleGetCenter()
	{
		grect r(2, 2, 2, 2);
		assertTrue(r.getCenter().x == 3 && r.getCenter().y == 3, "grect::testGetCenter - getCenter()");
	}

	void testRectangleGetAspect()
	{
		grect r(0, 0, 4, 2);
		assertTrue(r.getAspect() == 2, "grect::testGetAspect - getAspect()");
	}

	void testRectangleGetTopLeft()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getTopLeft().x == 1 && r.getTopLeft().y == 2, "grect::testGetTopLeft - getTopLeft()");
	}

	void testRectangleGetTopRight()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getTopRight().x == 4 && r.getTopRight().y == 2, "grect::testGetTopRight - getTopRight()");
	}

	void testRectangleGetBottomLeft()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getBottomLeft().x == 1 && r.getBottomLeft().y == 6, "grect::testGetBottomLeft - getBottomLeft()");
	}

	void testRectangleGetBottomRight()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getBottomRight().x == 4 && r.getBottomRight().y == 6, "grect::testGetBottomRight - getBottomRight()");
	}

	void testRectangleLeftRightTopBottom()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.left() == 1, "grect::testLeftRightTopBottom - left()");
		assertTrue(r.right() == 4, "grect::testLeftRightTopBottom - right()");
		assertTrue(r.top() == 2, "grect::testLeftRightTopBottom - top()");
		assertTrue(r.bottom() == 6, "grect::testLeftRightTopBottom - bottom()");
	}

	void testRectangleCenter()
	{
		grect r(0, 2, 4, 6);
		assertTrue(heqf(r.getCenter().x, 2, tolerance), "grect::testCenter - getCenterX()");
		assertTrue(heqf(r.getCenter().y, 5, tolerance), "grect::testCenter - getCenterY()");
	}

	void testRectangleClipped()
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 4, 4);
		r2 = r2.clipped(r1);
		assertTrue(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "grect:testClipped - clipped()");
	}

	void testRectangleClip()
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 4, 4);
		r2.clip(r1);
		assertTrue(r2.x >= r1.x && r2.x + r2.w <= r1.x + r1.w &&
			r2.y >= r1.y && r2.y + r2.h <= r1.y + r1.h, "grect:testClip - clip()");
	}

	void testRectangleIntersection()
	{
		grect r1(0, 0, 4, 4);
		grect r2(3, 3, 2, 2);
		
		assertTrue(r2.intersects(r1) == true, "grect:testIntersection - intersects()");
	}

	void testRectangleContains()
	{
		grect r1(0, 0, 4, 4);
		grect r2(1, 1, 2, 2);
		
		assertTrue(r1.contains(r2) == true, "grect:testClip - clip()");
	}

	void testRectanglePointInside()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);

		assertTrue(r.isPointInside(v) == true, "grect::testPointInside - isPointInside()");
		assertTrue(r.isPointInside(v.x, v.y) == true, "grect::testPointInside - isPointInside()");
	}

	void testRectangleAddition()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);

		grect r1 = r + v;
		assertTrue(r1.x == 1 && r1.y == 2, "grect::testAddition - operator+(vector)");
	}

	void testRectangleSubstraction()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);

		grect r1 = r - v;
		assertTrue(r1.x == -1 && r1.y == -2, "grect::testSubstraction - operator-(vector)");
	}

	void testRectangleMultiplication()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);
		
		grect r1 = r * v;
		assertTrue(r1.w == 8 && r1.h == 16, "grect::testMultiplication - operator*(vector)");

		r1 = r * 2;
		assertTrue(r1.w == 8 && r1.h == 8, "grect::testMultiplication - operator*(float)");
	}

	void testRectangleDivision()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);

		grect r1 = r / v;
		assertTrue(r1.w == 2 && r1.h == 1, "grect::testDivision - operator/(vector)");

		r1 = r / 2;
		assertTrue(r1.w == 2 && r1.h == 2, "grect::testDivision - operator/(float)");
	}

	void testRectangleAdditionAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);

		r += v;
		assertTrue(r.x == 1 && r.y == 2, "grect::testAdditionAssign - operator+=(vector)");
	}

	void testRectangleSubstractionAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(1, 2);

		r -= v;
		assertTrue(r.x == -1 && r.y == -2, "grect::testSubstractionAssign - operator-=(vector)");
	}

	void testRectangleMultiplicationAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);

		r *= v;
		assertTrue(r.w == 8 && r.h == 16, "grect::testMultiplicationAssign - operator*=(vector)");

		r = grect(0, 0, 4, 4);
		r *= 2;
		assertTrue(r.w == 8 && r.h == 8, "grect::testMultiplicationAssign - operator*=(float)");
	}

	void testRectangleDivisionAssign()
	{
		grect r(0, 0, 4, 4);
		gvec2 v(2, 4);

		r /= v;
		assertTrue(r.w == 2 && r.h == 1, "grect::testDivisionAssign - operator/=(vector)");

		r = grect(0, 0, 4, 4);
		r /= 2;
		assertTrue(r.w == 2 && r.h == 2, "grect::testDivisionAssign - operator/=(float)");
	}
	
	void testRectangleEqual()
	{
		grect r1(0, 0, 4, 4);
		grect r2(0, 0, 4, 4);

		assertTrue(r1 == r2, "grect::testEqual - operator==()");
	}

	void testRectangleNotEqual()
	{
		grect r1(0, 0, 4, 4);
		grect r2(0, 0, 4, 3);

		assertTrue(r1 != r2, "grect::testNotEqual - operator!=()");
	}
}
