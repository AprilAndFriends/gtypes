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
	};
}
#endif
