namespace testRectangle
{
	void testAssignment();
	void testGetPosition();
	void testSetPosition();
	void testGetSize();
	void testSetSize();
	void testGetCenter();
	void testGetAspect();
	void testGetTopLeft();
	void testGetTopRight();
	void testGetBottomLeft();
	void testGetBottomRight();
	void testLeftRightTopBottom();
	void testCenter();
	void testClipped();
	void testClip();
	void testIntersection();
	void testContains();
	void testPointInside();
	void testAddition();
	void testSubstraction();
	void testMultiplication();
	void testDivision();
	void testAdditionAssign();
	void testSubstractionAssign();
	void testMultiplicationAssign();
	void testDivisionAssign();
	void testEqual();
	void testNotEqual();
}

#ifdef __APPLE__
#import "aprilUT.h"

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
    testRectangle::testAssignment();
}

- (void)testAddition
{
    testRectangle::testAddition();
}

@end

#else
#include "aprilUT.h"

namespace test_libgtypes
{		
	TEST_CLASS(_testRectangle)
	{
	public:
		
		TEST_METHOD(testAssignment)
		{
			testRectangle::testAssignment();
		}
		TEST_METHOD(testGetPosition)
		{
			testRectangle::testGetPosition();
		}
		TEST_METHOD(testSetPosition)
		{
			testRectangle::testSetPosition();
		}
		TEST_METHOD(testGetSize)
		{
			testRectangle::testGetSize();
		}
		TEST_METHOD(testSetSize)
		{
			testRectangle::testSetSize();
		}
		TEST_METHOD(testGetCenter)
		{
			testRectangle::testGetCenter();
		}
		TEST_METHOD(testGetTopLeft)
		{
			testRectangle::testGetTopLeft();
		}
		TEST_METHOD(testGetTopRight)
		{
			testRectangle::testGetTopRight();
		}
		TEST_METHOD(testGetBottomLeft)
		{
			testRectangle::testGetBottomLeft();
		}
		TEST_METHOD(testGetBottomRight)
		{
			testRectangle::testGetBottomRight();
		}
		TEST_METHOD(testLeftRightTopBottom)
		{
			testRectangle::testLeftRightTopBottom();
		}
		TEST_METHOD(testCenter)
		{
			testRectangle::testCenter();
		}		
		TEST_METHOD(testClipped)
		{
			testRectangle::testClipped();
		}
		TEST_METHOD(testClip)
		{
			testRectangle::testClip();
		}
		TEST_METHOD(testIntersection)
		{
			testRectangle::testIntersection();
		}
		TEST_METHOD(testContains)
		{
			testRectangle::testContains();
		}
		TEST_METHOD(testPointInside)
		{
			testRectangle::testPointInside();
		}
		TEST_METHOD(testAddition)
		{
			testRectangle::testAddition();
		}
		TEST_METHOD(testSubstraction)
		{
			testRectangle::testSubstraction();
		}
		TEST_METHOD(testMultiplication)
		{
			testRectangle::testMultiplication();
		}
		TEST_METHOD(testDivision)
		{
			testRectangle::testDivision();
		}
		TEST_METHOD(testAdditionAssign)
		{
			testRectangle::testAdditionAssign();
		}
		TEST_METHOD(testSubstractionAssign)
		{
			testRectangle::testSubstractionAssign();
		}
		TEST_METHOD(testMultiplicationAssign)
		{
			testRectangle::testMultiplicationAssign();
		}
		TEST_METHOD(testDivisionAssign)
		{
			testRectangle::testDivisionAssign();
		}
		TEST_METHOD(testEqual)
		{
			testRectangle::testEqual();
		}
		TEST_METHOD(testNotEqual)
		{
			testRectangle::testNotEqual();
		}		
	};
}
#endif
