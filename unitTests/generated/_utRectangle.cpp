#define __HL_TEST_LIB_NAME gtypes

#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

HL_TEST_NAMESPACE(Rectangle)
{
	void testRectangleAssignment();
	void testRectangleGetPosition();
	void testRectangleSetPosition();
	void testRectangleGetSize();
	void testRectangleSetSize();
	void testRectangleGetCenter();
	void testRectangleGetAspect();
	void testRectangleGetTopLeft();
	void testRectangleGetTopRight();
	void testRectangleGetBottomLeft();
	void testRectangleGetBottomRight();
	void testRectangleLeftRightTopBottom();
	void testRectangleCenter();
	void testRectangleClipped();
	void testRectangleClip();
	void testRectangleIntersection();
	void testRectangleContains();
	void testRectanglePointInside();
	void testRectangleAddition();
	void testRectangleSubstraction();
	void testRectangleMultiplication();
	void testRectangleDivision();
	void testRectangleAdditionAssign();
	void testRectangleSubstractionAssign();
	void testRectangleMultiplicationAssign();
	void testRectangleDivisionAssign();
	void testRectangleEqual();
	void testRectangleNotEqual();
}



#ifdef __APPLE__

@interface _testRectangle : XCTestCase

@end

@implementation _testRectangle

- (void)setUp
{
    [super setUp];
    testInstance = self;
}

- (void)tearDown
{
    [super tearDown];
}

- (void)testAssignment
{
    gtypes_unittest::testRectangleAssignment();
}

- (void)testAddition
{
    gtypes_unittest::testRectangleAddition();
}

@end

#else

HL_TEST_CLASS_BEGIN(Rectangle)
HL_TEST_CLASS_END
namespace test_libgtypes
{		
	{
	public:
		
		TEST_METHOD(testAssignment)
		{
			gtypes_unittest_Rectangle::testRectangleAssignment();
		}
		TEST_METHOD(testGetPosition)
		{
			gtypes_unittest::testRectangleGetPosition();
		}
		TEST_METHOD(testSetPosition)
		{
			gtypes_unittest::testRectangleSetPosition();
		}
		TEST_METHOD(testGetSize)
		{
			gtypes_unittest::testRectangleGetSize();
		}
		TEST_METHOD(testSetSize)
		{
			gtypes_unittest::testRectangleSetSize();
		}
		TEST_METHOD(testGetCenter)
		{
			gtypes_unittest::testRectangleGetCenter();
		}
		TEST_METHOD(testGetTopLeft)
		{
			gtypes_unittest::testRectangleGetTopLeft();
		}
		TEST_METHOD(testGetTopRight)
		{
			gtypes_unittest::testRectangleGetTopRight();
		}
		TEST_METHOD(testGetBottomLeft)
		{
			gtypes_unittest::testRectangleGetBottomLeft();
		}
		TEST_METHOD(testGetBottomRight)
		{
			gtypes_unittest::testRectangleGetBottomRight();
		}
		TEST_METHOD(testLeftRightTopBottom)
		{
			gtypes_unittest::testRectangleLeftRightTopBottom();
		}
		TEST_METHOD(testCenter)
		{
			gtypes_unittest::testRectangleCenter();
		}		
		TEST_METHOD(testClipped)
		{
			gtypes_unittest::testRectangleClipped();
		}
		TEST_METHOD(testClip)
		{
			gtypes_unittest::testRectangleClip();
		}
		TEST_METHOD(testIntersection)
		{
			gtypes_unittest::testRectangleIntersection();
		}
		TEST_METHOD(testContains)
		{
			gtypes_unittest::testRectangleContains();
		}
		TEST_METHOD(testPointInside)
		{
			gtypes_unittest::testRectanglePointInside();
		}
		TEST_METHOD(testAddition)
		{
			gtypes_unittest::testRectangleAddition();
		}
		TEST_METHOD(testSubstraction)
		{
			gtypes_unittest::testRectangleSubstraction();
		}
		TEST_METHOD(testMultiplication)
		{
			gtypes_unittest::testRectangleMultiplication();
		}
		TEST_METHOD(testDivision)
		{
			gtypes_unittest::testRectangleDivision();
		}
		TEST_METHOD(testAdditionAssign)
		{
			gtypes_unittest::testRectangleAdditionAssign();
		}
		TEST_METHOD(testSubstractionAssign)
		{
			gtypes_unittest::testRectangleSubstractionAssign();
		}
		TEST_METHOD(testMultiplicationAssign)
		{
			gtypes_unittest::testRectangleMultiplicationAssign();
		}
		TEST_METHOD(testDivisionAssign)
		{
			gtypes_unittest::testRectangleDivisionAssign();
		}
		TEST_METHOD(testEqual)
		{
			gtypes_unittest::testRectangleEqual();
		}
		TEST_METHOD(testNotEqual)
		{
			gtypes_unittest::testRectangleNotEqual();
		}		
	};
}
#endif
