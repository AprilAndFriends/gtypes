#define __HL_TEST_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

HL_TEST_NAMESPACE(Rectangle)
{
	void assignment();
	void getPosition();
	void setPosition();
	void getSize();
	void setSize();
	void getCenter();
	void getAspect();
	void getTopLeft();
	void getTopRight();
	void getBottomLeft();
	void getBottomRight();
	void leftRightTopBottom();
	void center();
	void clipped();
	void clip();
	void intersection();
	void contains();
	void pointInside();
	void addition();
	void substraction();
	void multiplication();
	void division();
	void additionAssign();
	void substractionAssign();
	void multiplicationAssign();
	void divisionAssign();
	void equal();
	void notEqual();
}

HL_TEST_CLASS_BEGIN(Rectangle)

HL_TEST_METHOD(Rectangle, assignment)
HL_TEST_METHOD(Rectangle, getPosition)
HL_TEST_METHOD(Rectangle, setPosition)
HL_TEST_METHOD(Rectangle, getSize)
HL_TEST_METHOD(Rectangle, setSize)
HL_TEST_METHOD(Rectangle, getCenter)
HL_TEST_METHOD(Rectangle, getTopLeft)
HL_TEST_METHOD(Rectangle, getTopRight)
HL_TEST_METHOD(Rectangle, getBottomLeft)
HL_TEST_METHOD(Rectangle, getBottomRight)
HL_TEST_METHOD(Rectangle, leftRightTopBottom)
HL_TEST_METHOD(Rectangle, center)
HL_TEST_METHOD(Rectangle, clipped)
HL_TEST_METHOD(Rectangle, clip)
HL_TEST_METHOD(Rectangle, intersection)
HL_TEST_METHOD(Rectangle, contains)
HL_TEST_METHOD(Rectangle, pointInside)
HL_TEST_METHOD(Rectangle, addition)
HL_TEST_METHOD(Rectangle, substraction)
HL_TEST_METHOD(Rectangle, multiplication)
HL_TEST_METHOD(Rectangle, division)
HL_TEST_METHOD(Rectangle, additionAssign)
HL_TEST_METHOD(Rectangle, substractionAssign)
HL_TEST_METHOD(Rectangle, multiplicationAssign)
HL_TEST_METHOD(Rectangle, divisionAssign)
HL_TEST_METHOD(Rectangle, equal)
HL_TEST_METHOD(Rectangle, notEqual)

HL_TEST_CLASS_END
