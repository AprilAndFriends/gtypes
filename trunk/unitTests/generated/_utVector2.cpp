namespace testVector2
{
    void testAssignment();
    void testAddition();
}

#ifdef __APPLE__
#import "aprilUT.h"

@interface _testVector2 : XCTestCase

@end

@implementation _testVector2

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
    testVector2::testAssignment();
}

- (void)testAddition
{
    testVector2::testAddition();
}

@end

#else
#include "aprilUT.h"

namespace test_libgtypes
{		
	TEST_CLASS(_testVector2)
	{
	public:
		
		TEST_METHOD(testAssignment)
		{
			testVector2::testAssignment();
		}

		TEST_METHOD(testAddition)
		{
			testVector2::testAddition();
		}
	};
}
#endif
