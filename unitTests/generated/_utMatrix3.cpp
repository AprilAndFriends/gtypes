namespace testMatrix3
{
	void testAssignment();
	void testSetZero();
	void testSetIdentity();
	void testSetTranslation();
	void testSetScale();
	void testSetScale3D();
	void testSetRotation();
	void testSetRotation3D();
	void testSetRotation3DX();
	void testSetRotation3DY();
	void testSetRotation3DZ();
	void testTranslate();
	void testScale();
	void testScale3D();
	void testRotate();
	void testRotate3D();
	void testRotate3DX();
	void testRotate3DY();
	void testRotate3DZ();
	void testTranspose();
	void testInverse();
	void testInversed();
	void testInverseRotation();
	void testInversedRotation();
	void testInverseRotation3D();
	void testInversedRotation3D();
	void testOrthoNormalize();
	void testOrthoNormalized();
	void testMultiplication();
	void testAddition();
	void testSubstraction();
	void testMultiplicationAssign();
	void testAdditionAssign();
	void testSubstractionAssign();
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
		TEST_METHOD(testSetZero)
		{
			testMatrix3::testSetZero();
		}
		TEST_METHOD(testSetIdentity)
		{
			testMatrix3::testSetIdentity();
		}
		TEST_METHOD(testSetTranslation)
		{
			testMatrix3::testSetTranslation();
		}
		TEST_METHOD(testSetScale)
		{
			testMatrix3::testSetScale();
		}
		TEST_METHOD(testSetScale3D)
		{
			testMatrix3::testSetScale3D();
		}
		TEST_METHOD(testSetRotation)
		{
			testMatrix3::testSetRotation();
		}
		TEST_METHOD(testSetRotation3D)
		{
			testMatrix3::testSetRotation3D();
		}
		TEST_METHOD(testSetRotation3DX)
		{
			testMatrix3::testSetRotation3DX();
		}
		TEST_METHOD(testSetRotation3DY)
		{
			testMatrix3::testSetRotation3DY();
		}
		TEST_METHOD(testSetRotation3DZ)
		{
			testMatrix3::testSetRotation3DZ();
		}
		TEST_METHOD(testTranslate)
		{
			testMatrix3::testTranslate();
		}
		TEST_METHOD(testScale)
		{
			testMatrix3::testScale();
		}
		TEST_METHOD(testScale3D)
		{
			testMatrix3::testScale3D();
		}
		TEST_METHOD(testRotate)
		{
			testMatrix3::testRotate();
		}
		TEST_METHOD(testRotate3D)
		{
			testMatrix3::testRotate3D();
		}
		TEST_METHOD(testRotate3DX)
		{
			testMatrix3::testRotate3DX();
		}
		TEST_METHOD(testRotate3DY)
		{
			testMatrix3::testRotate3DY();
		}
		TEST_METHOD(testRotate3DZ)
		{
			testMatrix3::testRotate3DZ();
		}
		TEST_METHOD(testTranspose)
		{
			testMatrix3::testTranspose();
		}
		TEST_METHOD(testInverse)
		{
			testMatrix3::testInverse();
		}
		TEST_METHOD(testInversed)
		{
			testMatrix3::testInversed();
		}
		TEST_METHOD(testInverseRotation)
		{
			testMatrix3::testInverseRotation();
		}
		TEST_METHOD(testInversedRotation)
		{
			testMatrix3::testInversedRotation();
		}
		TEST_METHOD(testInverseRotation3D)
		{
			testMatrix3::testInverseRotation3D();
		}
		TEST_METHOD(testInversedRotation3D)
		{
			testMatrix3::testInversedRotation3D();
		}
		TEST_METHOD(testOrthoNormalize)
		{
			testMatrix3::testOrthoNormalize();
		}
		TEST_METHOD(testOrthoNormalized)
		{
			testMatrix3::testOrthoNormalized();
		}
		TEST_METHOD(testMultiplication)
		{
			testMatrix3::testMultiplication();
		}
		TEST_METHOD(testAddition)
		{
			testMatrix3::testAddition();
		}
		TEST_METHOD(testSubstraction)
		{
			testMatrix3::testSubstraction();
		}
		TEST_METHOD(testMultiplicationAssign)
		{
			testMatrix3::testMultiplicationAssign();
		}
		TEST_METHOD(testAdditionAssign)
		{
			testMatrix3::testAdditionAssign();
		}
		TEST_METHOD(testSubstractionAssign)
		{
			testMatrix3::testSubstractionAssign();
		}
	};
}
#endif
