#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

HL_UT_TEST_CLASS(Matrix3)
{
	HL_UT_TEST_FUNCTION(assignment);
	HL_UT_TEST_FUNCTION(setZero);
	HL_UT_TEST_FUNCTION(setIdentity);
	HL_UT_TEST_FUNCTION(setTranslation);
	HL_UT_TEST_FUNCTION(setScale);
	HL_UT_TEST_FUNCTION(setScale3D);
	HL_UT_TEST_FUNCTION(setRotation);
	HL_UT_TEST_FUNCTION(setRotation3D);
	HL_UT_TEST_FUNCTION(setRotation3DX);
	HL_UT_TEST_FUNCTION(setRotation3DY);
	HL_UT_TEST_FUNCTION(setRotation3DZ);
	HL_UT_TEST_FUNCTION(det);
	HL_UT_TEST_FUNCTION(translate);
	HL_UT_TEST_FUNCTION(scale);
	HL_UT_TEST_FUNCTION(scale3D);
	HL_UT_TEST_FUNCTION(rotate);
	HL_UT_TEST_FUNCTION(rotate3D);
	HL_UT_TEST_FUNCTION(rotate3DX);
	HL_UT_TEST_FUNCTION(rotate3DY);
	HL_UT_TEST_FUNCTION(rotate3DZ);
	HL_UT_TEST_FUNCTION(transpose);
	HL_UT_TEST_FUNCTION(transposed);
	HL_UT_TEST_FUNCTION(inverse);
	HL_UT_TEST_FUNCTION(inversed);
	HL_UT_TEST_FUNCTION(inverseRotation);
	HL_UT_TEST_FUNCTION(inversedRotation);
	HL_UT_TEST_FUNCTION(inverseRotation3D);
	HL_UT_TEST_FUNCTION(inversedRotation3D);
	HL_UT_TEST_FUNCTION(orthoNormalize);
	HL_UT_TEST_FUNCTION(orthoNormalized);
	HL_UT_TEST_FUNCTION(multiplication);
	HL_UT_TEST_FUNCTION(addition);
	HL_UT_TEST_FUNCTION(substraction);
	HL_UT_TEST_FUNCTION(multiplicationAssign);
	HL_UT_TEST_FUNCTION(additionAssign);
	HL_UT_TEST_FUNCTION(substractionAssign);
}

HL_UT_RUN_CLASS_BEGIN(Matrix3)
	HL_UT_RUN_METHOD(Matrix3, assignment)
	HL_UT_RUN_METHOD(Matrix3, setZero)
	HL_UT_RUN_METHOD(Matrix3, setIdentity)
	HL_UT_RUN_METHOD(Matrix3, setTranslation)
	HL_UT_RUN_METHOD(Matrix3, setScale)
	HL_UT_RUN_METHOD(Matrix3, setScale3D)
	HL_UT_RUN_METHOD(Matrix3, setRotation)
	HL_UT_RUN_METHOD(Matrix3, setRotation3D)
	HL_UT_RUN_METHOD(Matrix3, setRotation3DX)
	HL_UT_RUN_METHOD(Matrix3, setRotation3DY)
	HL_UT_RUN_METHOD(Matrix3, setRotation3DZ)
	HL_UT_RUN_METHOD(Matrix3, det)
	HL_UT_RUN_METHOD(Matrix3, translate)
	HL_UT_RUN_METHOD(Matrix3, scale)
	HL_UT_RUN_METHOD(Matrix3, scale3D)
	HL_UT_RUN_METHOD(Matrix3, rotate)
	HL_UT_RUN_METHOD(Matrix3, rotate3D)
	HL_UT_RUN_METHOD(Matrix3, rotate3DX)
	HL_UT_RUN_METHOD(Matrix3, rotate3DY)
	HL_UT_RUN_METHOD(Matrix3, rotate3DZ)
	HL_UT_RUN_METHOD(Matrix3, transpose)
	HL_UT_RUN_METHOD(Matrix3, transposed)
	HL_UT_RUN_METHOD(Matrix3, inverse)
	HL_UT_RUN_METHOD(Matrix3, inversed)
	HL_UT_RUN_METHOD(Matrix3, inverseRotation)
	HL_UT_RUN_METHOD(Matrix3, inversedRotation)
	HL_UT_RUN_METHOD(Matrix3, inverseRotation3D)
	HL_UT_RUN_METHOD(Matrix3, inversedRotation3D)
	HL_UT_RUN_METHOD(Matrix3, orthoNormalize)
	HL_UT_RUN_METHOD(Matrix3, orthoNormalized)
	HL_UT_RUN_METHOD(Matrix3, multiplication)
	HL_UT_RUN_METHOD(Matrix3, addition)
	HL_UT_RUN_METHOD(Matrix3, substraction)
	HL_UT_RUN_METHOD(Matrix3, multiplicationAssign)
	HL_UT_RUN_METHOD(Matrix3, additionAssign)
	HL_UT_RUN_METHOD(Matrix3, substractionAssign)
HL_UT_RUN_CLASS_END
