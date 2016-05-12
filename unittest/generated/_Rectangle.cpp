#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

HL_UT_TEST_CLASS(Rectangle)
{
	HL_UT_TEST_FUNCTION(assignment);
	HL_UT_TEST_FUNCTION(getPosition);
	HL_UT_TEST_FUNCTION(setPosition);
	HL_UT_TEST_FUNCTION(getSize);
	HL_UT_TEST_FUNCTION(setSize);
	HL_UT_TEST_FUNCTION(getCenter);
	HL_UT_TEST_FUNCTION(getAspect);
	HL_UT_TEST_FUNCTION(getTopLeft);
	HL_UT_TEST_FUNCTION(getTopRight);
	HL_UT_TEST_FUNCTION(getBottomLeft);
	HL_UT_TEST_FUNCTION(getBottomRight);
	HL_UT_TEST_FUNCTION(leftRightTopBottom);
	HL_UT_TEST_FUNCTION(clipped);
	HL_UT_TEST_FUNCTION(clip);
	HL_UT_TEST_FUNCTION(intersection);
	HL_UT_TEST_FUNCTION(contains);
	HL_UT_TEST_FUNCTION(pointInside);
	HL_UT_TEST_FUNCTION(addition);
	HL_UT_TEST_FUNCTION(substraction);
	HL_UT_TEST_FUNCTION(multiplication);
	HL_UT_TEST_FUNCTION(division);
	HL_UT_TEST_FUNCTION(additionAssign);
	HL_UT_TEST_FUNCTION(substractionAssign);
	HL_UT_TEST_FUNCTION(multiplicationAssign);
	HL_UT_TEST_FUNCTION(divisionAssign);
	HL_UT_TEST_FUNCTION(equal);
	HL_UT_TEST_FUNCTION(notEqual);
}

HL_UT_RUN_CLASS_BEGIN(Rectangle)
	HL_UT_RUN_METHOD(Rectangle, assignment)
	HL_UT_RUN_METHOD(Rectangle, getPosition)
	HL_UT_RUN_METHOD(Rectangle, setPosition)
	HL_UT_RUN_METHOD(Rectangle, getSize)
	HL_UT_RUN_METHOD(Rectangle, setSize)
	HL_UT_RUN_METHOD(Rectangle, getCenter)
	HL_UT_RUN_METHOD(Rectangle, getAspect)
	HL_UT_RUN_METHOD(Rectangle, getTopLeft)
	HL_UT_RUN_METHOD(Rectangle, getTopRight)
	HL_UT_RUN_METHOD(Rectangle, getBottomLeft)
	HL_UT_RUN_METHOD(Rectangle, getBottomRight)
	HL_UT_RUN_METHOD(Rectangle, leftRightTopBottom)
	HL_UT_RUN_METHOD(Rectangle, clipped)
	HL_UT_RUN_METHOD(Rectangle, clip)
	HL_UT_RUN_METHOD(Rectangle, intersection)
	HL_UT_RUN_METHOD(Rectangle, contains)
	HL_UT_RUN_METHOD(Rectangle, pointInside)
	HL_UT_RUN_METHOD(Rectangle, addition)
	HL_UT_RUN_METHOD(Rectangle, substraction)
	HL_UT_RUN_METHOD(Rectangle, multiplication)
	HL_UT_RUN_METHOD(Rectangle, division)
	HL_UT_RUN_METHOD(Rectangle, additionAssign)
	HL_UT_RUN_METHOD(Rectangle, substractionAssign)
	HL_UT_RUN_METHOD(Rectangle, multiplicationAssign)
	HL_UT_RUN_METHOD(Rectangle, divisionAssign)
	HL_UT_RUN_METHOD(Rectangle, equal)
	HL_UT_RUN_METHOD(Rectangle, notEqual)
HL_UT_RUN_CLASS_END
