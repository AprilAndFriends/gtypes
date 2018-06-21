#define __HTEST_LIB_NAME gtypes
#include "htest.h"

HTEST_CLASS(Rectangle)
{
	HTEST_FUNCTION(assignment);
	HTEST_FUNCTION(getPosition);
	HTEST_FUNCTION(setPosition);
	HTEST_FUNCTION(getSize);
	HTEST_FUNCTION(setSize);
	HTEST_FUNCTION(getCenter);
	HTEST_FUNCTION(getAspect);
	HTEST_FUNCTION(getTopLeft);
	HTEST_FUNCTION(getTopRight);
	HTEST_FUNCTION(getBottomLeft);
	HTEST_FUNCTION(getBottomRight);
	HTEST_FUNCTION(leftRightTopBottom);
	HTEST_FUNCTION(clipped);
	HTEST_FUNCTION(clip);
	HTEST_FUNCTION(intersection);
	HTEST_FUNCTION(contains);
	HTEST_FUNCTION(pointInside);
	HTEST_FUNCTION(addition);
	HTEST_FUNCTION(substraction);
	HTEST_FUNCTION(multiplication);
	HTEST_FUNCTION(division);
	HTEST_FUNCTION(additionAssign);
	HTEST_FUNCTION(substractionAssign);
	HTEST_FUNCTION(multiplicationAssign);
	HTEST_FUNCTION(divisionAssign);
	HTEST_FUNCTION(equal);
	HTEST_FUNCTION(notEqual);
}

HTEST_RUN_CLASS_BEGIN(Rectangle)
	HTEST_RUN_METHOD(Rectangle, assignment)
	HTEST_RUN_METHOD(Rectangle, getPosition)
	HTEST_RUN_METHOD(Rectangle, setPosition)
	HTEST_RUN_METHOD(Rectangle, getSize)
	HTEST_RUN_METHOD(Rectangle, setSize)
	HTEST_RUN_METHOD(Rectangle, getCenter)
	HTEST_RUN_METHOD(Rectangle, getAspect)
	HTEST_RUN_METHOD(Rectangle, getTopLeft)
	HTEST_RUN_METHOD(Rectangle, getTopRight)
	HTEST_RUN_METHOD(Rectangle, getBottomLeft)
	HTEST_RUN_METHOD(Rectangle, getBottomRight)
	HTEST_RUN_METHOD(Rectangle, leftRightTopBottom)
	HTEST_RUN_METHOD(Rectangle, clipped)
	HTEST_RUN_METHOD(Rectangle, clip)
	HTEST_RUN_METHOD(Rectangle, intersection)
	HTEST_RUN_METHOD(Rectangle, contains)
	HTEST_RUN_METHOD(Rectangle, pointInside)
	HTEST_RUN_METHOD(Rectangle, addition)
	HTEST_RUN_METHOD(Rectangle, substraction)
	HTEST_RUN_METHOD(Rectangle, multiplication)
	HTEST_RUN_METHOD(Rectangle, division)
	HTEST_RUN_METHOD(Rectangle, additionAssign)
	HTEST_RUN_METHOD(Rectangle, substractionAssign)
	HTEST_RUN_METHOD(Rectangle, multiplicationAssign)
	HTEST_RUN_METHOD(Rectangle, divisionAssign)
	HTEST_RUN_METHOD(Rectangle, equal)
	HTEST_RUN_METHOD(Rectangle, notEqual)
HTEST_RUN_CLASS_END
