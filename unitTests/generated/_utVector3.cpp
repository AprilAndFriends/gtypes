namespace testVector3
{
    void testAssignment();
    void testAddition();
	void testZeroLength();
	void testLength();
	void testSquaredLength();	
	void testNormalization();
	void testNormalized();	
	void testDot();
	void testNegation();
	void testSubstraction();
	void testMultiplicationVector();
	void testDivisionVector();
	void testMultiplication();
	void testDivision();	
	void testAdditionAssign();
	void testSubstractionAssign();
	void testMultiplicationVectorAssign();
	void testDivisionVectorAssign();
	void testMultiplicationAssign();
	void testDivisionAssign();
	void testEqual();
	void testNotEqual();
}

#ifdef __APPLE__
#import "hunittest.h"

@interface _testVector3 : XCTestCase

@end

@implementation _testVector3

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
    testVector3::testAssignment();
}

- (void)testAddition
{
    testVector3::testAddition();
}

@end

#else
#include "hunittest.h"

namespace test_libgtypes
{		
	TEST_CLASS(_testVector3)
	{
	public:
		
		TEST_METHOD(testAssignment)
		{
			testVector3::testAssignment();
		}

		TEST_METHOD(testAddition)
		{
			testVector3::testAddition();
		}

		TEST_METHOD(testZeroLength)
		{
			testVector3::testZeroLength();
		}
		
		TEST_METHOD(testLength)
		{
			testVector3::testLength();
		}

		TEST_METHOD(testSquaredLength)
		{
			testVector3::testSquaredLength();
		}		

		TEST_METHOD(testNormalization)
		{
			testVector3::testNormalization();
		}

		TEST_METHOD(testNormalized)
		{
			testVector3::testNormalization();
		}

		TEST_METHOD(testDot)
		{
			testVector3::testDot();
		}

		TEST_METHOD(testNegation)
		{
			testVector3::testNegation();
		}

		TEST_METHOD(testSubstraction)
		{
			testVector3::testSubstraction();
		}

		TEST_METHOD(testMultiplicationVector)
		{
			testVector3::testMultiplicationVector();
		}

		TEST_METHOD(testDivisionVector)
		{
			testVector3::testDivisionVector();
		}

		TEST_METHOD(testMultiplication)
		{
			testVector3::testMultiplication();
		}

		TEST_METHOD(testDivision)
		{
			testVector3::testDivision();
		}

		TEST_METHOD(testAdditionAssign)
		{
			testVector3::testAdditionAssign();
		}

		TEST_METHOD(testSubstractionAssign)
		{
			testVector3::testSubstractionAssign();
		}

		TEST_METHOD(testMultiplicationVectorAssign)
		{
			testVector3::testMultiplicationVectorAssign();
		}

		TEST_METHOD(testDivisionVectorAssign)
		{
			testVector3::testDivisionVectorAssign();
		}

		TEST_METHOD(testMultiplicationAssign)
		{
			testVector3::testMultiplicationAssign();
		}

		TEST_METHOD(testDivisionAssign)
		{
			testVector3::testDivisionAssign();
		}

		TEST_METHOD(testEqual)
		{
			testVector3::testEqual();
		}

		TEST_METHOD(testNotEqual)
		{
			testVector3::testNotEqual();
		}
	};
}
#endif
