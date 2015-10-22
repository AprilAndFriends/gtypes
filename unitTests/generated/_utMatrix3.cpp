namespace testMatrix3
{
	void testAssignment();
}

#ifdef __APPLE__
#import "aprilUT.h"

@interface _testMatrix3 : XCTestCase

@end

@implementation _testMatrix3

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
    testMatrix3::testAssignment();
}

- (void)testAddition
{
    testMatrix3::testAddition();
}

@end

#else
#include "aprilUT.h"

namespace test_libgtypes
{		
	TEST_CLASS(_testMatrix3)
	{
	public:
		
		TEST_METHOD(testAssignment)
		{
			testMatrix3::testAssignment();
		}			
	};
}
#endif
