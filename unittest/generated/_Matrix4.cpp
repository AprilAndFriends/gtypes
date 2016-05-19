#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

HL_UT_TEST_CLASS(Matrix4)
{
	HL_UT_TEST_FUNCTION(assignment);
	HL_UT_TEST_FUNCTION(setZero);
	HL_UT_TEST_FUNCTION(setIdentity);
	HL_UT_TEST_FUNCTION(setTranslation);
	HL_UT_TEST_FUNCTION(setScale);
	HL_UT_TEST_FUNCTION(setRotation);
	HL_UT_TEST_FUNCTION(det);
	HL_UT_TEST_FUNCTION(transpose);
	HL_UT_TEST_FUNCTION(translate);
	HL_UT_TEST_FUNCTION(scale);
	HL_UT_TEST_FUNCTION(rotate);
	HL_UT_TEST_FUNCTION(inverse);
	HL_UT_TEST_FUNCTION(inversed);
	HL_UT_TEST_FUNCTION(inverseRotation);
	HL_UT_TEST_FUNCTION(inversedRotation);
	HL_UT_TEST_FUNCTION(multiplication);
	HL_UT_TEST_FUNCTION(addition);
	HL_UT_TEST_FUNCTION(substraction);
	HL_UT_TEST_FUNCTION(multiplicationAssign);
	HL_UT_TEST_FUNCTION(additionAssign);
	HL_UT_TEST_FUNCTION(substractionAssign);
}

HL_UT_RUN_CLASS_BEGIN(Matrix4)
	HL_UT_RUN_METHOD(Matrix4, assignment)
	HL_UT_RUN_METHOD(Matrix4, setZero)
	HL_UT_RUN_METHOD(Matrix4, setIdentity)
	HL_UT_RUN_METHOD(Matrix4, setTranslation)
	HL_UT_RUN_METHOD(Matrix4, setScale)
	HL_UT_RUN_METHOD(Matrix4, setRotation)
	HL_UT_RUN_METHOD(Matrix4, det)
	HL_UT_RUN_METHOD(Matrix4, transpose)
	HL_UT_RUN_METHOD(Matrix4, translate)
	HL_UT_RUN_METHOD(Matrix4, scale)
	HL_UT_RUN_METHOD(Matrix4, rotate)
	HL_UT_RUN_METHOD(Matrix4, inverse)
	HL_UT_RUN_METHOD(Matrix4, inversed)
	HL_UT_RUN_METHOD(Matrix4, inverseRotation)
	HL_UT_RUN_METHOD(Matrix4, inversedRotation)
	HL_UT_RUN_METHOD(Matrix4, multiplication)
	HL_UT_RUN_METHOD(Matrix4, addition)
	HL_UT_RUN_METHOD(Matrix4, substraction)
	HL_UT_RUN_METHOD(Matrix4, multiplicationAssign)
	HL_UT_RUN_METHOD(Matrix4, additionAssign)
	HL_UT_RUN_METHOD(Matrix4, substractionAssign)
HL_UT_RUN_CLASS_END
