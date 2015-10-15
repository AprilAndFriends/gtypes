#include "generated/aprilUT.h"
#include "Rectangle.h"

namespace testRectangle
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

    void testAssignment()
    {
		grect r(1, 2, 3, 4);
		assertTrue(r.x == 1 && r.y == 2 && r.w == 3 && r.h == 4, "grect::testAssignment - constructor assignment");
        r.set(2, 3, 4, 5);
		assertTrue(r.x == 2 && r.y == 3 && r.w == 4 && r.h == 5, "grect::testAssignment - set()");
    }

	void testGetPosition()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getPosition().x == 1 && r.getPosition().y == 2, "grect::testGetPosition - getPosition()");
	}

	void testSetPosition()
	{
		grect r(1, 2, 3, 4);
		r.setPosition(5, 6);
		assertTrue(r.getPosition().x == 5 && r.getPosition().y == 6, "grect::testSetPosition - setPosition()");
		r.setPosition(gvec2(7, 8));
		assertTrue(r.getPosition().x == 7 && r.getPosition().y == 8, "grect::testSetPosition - setPosition()");
	}

	void testGetSize()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getSize().x == 3 && r.getSize().y == 4, "grect::testGetSize - getSize()");
	}

	void testSetSize()
	{
		grect r(1, 2, 3, 4);
		r.setSize(5, 6);
		assertTrue(r.getSize().x == 5 && r.getSize().y == 6, "grect::testSetSize - setSize()");
		r.setSize(gvec2(7, 8));
		assertTrue(r.getSize().x == 7 && r.getSize().y == 8, "grect::testSetSize - setSize()");
	}

	void testGetCenter()
	{
		grect r(2, 2, 2, 2);
		assertTrue(r.getCenter().x == 3 && r.getCenter().y == 3, "grect::testGetCenter - getCenter()");
	}

	void testGetAspect()
	{
		grect r(0, 0, 4, 2);
		assertTrue(r.getAspect() == 2, "grect::testGetAspect - getAspect()");
	}

	void testGetTopLeft()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getTopLeft().x == 1 && r.getTopLeft().y == 2, "grect::testGetTopLeft - getTopLeft()");
	}

	void testGetTopRight()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getTopRight().x == 4 && r.getTopRight().y == 2, "grect::testGetTopRight - getTopRight()");
	}

	void testGetBottomLeft()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getBottomLeft().x == 1 && r.getBottomLeft().y == 6, "grect::testGetBottomLeft - getBottomLeft()");
	}

	void testGetBottomRight()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.getBottomRight().x == 4 && r.getBottomRight().y == 6, "grect::testGetBottomRight - getBottomRight()");
	}

	void testLeftRightTopBottom()
	{
		grect r(1, 2, 3, 4);
		assertTrue(r.left() == 1, "grect::testLeftRightTopBottom - left()");
		assertTrue(r.right() == 4, "grect::testLeftRightTopBottom - right()");
		assertTrue(r.top() == 2, "grect::testLeftRightTopBottom - top()");
		assertTrue(r.bottom() == 6, "grect::testLeftRightTopBottom - bottom()");
	}

	void testCenter()
	{
		grect r(0, 2, 4, 6);
		assertTrue(heqf(r.getCenter().x, 2, tolerance), "grect::testCenter - getCenterX()");
		assertTrue(heqf(r.getCenter().y, 5, tolerance), "grect::testCenter - getCenterY()");
	}
}
