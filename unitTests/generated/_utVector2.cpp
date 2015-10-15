namespace testVector2
{
    void testAssignment();
    void testAddition();
	void testZeroLength();
	void testLength();
	void testSquaredLength();
	void testAngle();
	void testNormalization();
	void testNormalized();
	void testRotation();
	void testRotated();
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

		TEST_METHOD(testZeroLength)
		{
			testVector2::testZeroLength();
		}
		
		TEST_METHOD(testLength)
		{
			testVector2::testLength();
		}

		TEST_METHOD(testSquaredLength)
		{
			testVector2::testSquaredLength();
		}

		TEST_METHOD(testAngle)
		{
			testVector2::testAngle();
		}

		TEST_METHOD(testNormalization)
		{
			testVector2::testNormalization();
		}

		TEST_METHOD(testNormalized)
		{
			testVector2::testNormalization();
		}

		TEST_METHOD(testRotation)
		{
			testVector2::testRotation();
		}

		TEST_METHOD(testRotated)
		{
			testVector2::testRotated();
		}

		TEST_METHOD(testDot)
		{
			testVector2::testDot();
		}

		TEST_METHOD(testNegation)
		{
			testVector2::testNegation();
		}

		TEST_METHOD(testSubstraction)
		{
			testVector2::testSubstraction();
		}

		TEST_METHOD(testMultiplicationVector)
		{
			testVector2::testMultiplicationVector();
		}

		TEST_METHOD(testDivisionVector)
		{
			testVector2::testDivisionVector();
		}

		TEST_METHOD(testMultiplication)
		{
			testVector2::testMultiplication();
		}

		TEST_METHOD(testDivision)
		{
			testVector2::testDivision();
		}

		TEST_METHOD(testAdditionAssign)
		{
			testVector2::testAdditionAssign();
		}

		TEST_METHOD(testSubstractionAssign)
		{
			testVector2::testSubstractionAssign();
		}

		TEST_METHOD(testMultiplicationVectorAssign)
		{
			testVector2::testMultiplicationVectorAssign();
		}

		TEST_METHOD(testDivisionVectorAssign)
		{
			testVector2::testDivisionVectorAssign();
		}

		TEST_METHOD(testMultiplicationAssign)
		{
			testVector2::testMultiplicationAssign();
		}

		TEST_METHOD(testDivisionAssign)
		{
			testVector2::testDivisionAssign();
		}

		TEST_METHOD(testEqual)
		{
			testVector2::testEqual();
		}

		TEST_METHOD(testNotEqual)
		{
			testVector2::testNotEqual();
		}
	};
}
#endif
