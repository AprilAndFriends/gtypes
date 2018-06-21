#define __HTEST_LIB_NAME gtypes
#include "htest.h"

HTEST_CLASS(Matrix4)
{
	HTEST_FUNCTION(assignment);
	HTEST_FUNCTION(setZero);
	HTEST_FUNCTION(setIdentity);
	HTEST_FUNCTION(setTranslation);
	HTEST_FUNCTION(setScale);
	HTEST_FUNCTION(setRotation);
	HTEST_FUNCTION(det);
	HTEST_FUNCTION(transpose);
	HTEST_FUNCTION(translate);
	HTEST_FUNCTION(scale);
	HTEST_FUNCTION(rotate);
	HTEST_FUNCTION(inverse);
	HTEST_FUNCTION(inversed);
	HTEST_FUNCTION(inverseRotation);
	HTEST_FUNCTION(inversedRotation);
	HTEST_FUNCTION(multiplication);
	HTEST_FUNCTION(addition);
	HTEST_FUNCTION(substraction);
	HTEST_FUNCTION(multiplicationAssign);
	HTEST_FUNCTION(additionAssign);
	HTEST_FUNCTION(substractionAssign);
}

HTEST_RUN_CLASS_BEGIN(Matrix4)
	HTEST_RUN_METHOD(Matrix4, assignment)
	HTEST_RUN_METHOD(Matrix4, setZero)
	HTEST_RUN_METHOD(Matrix4, setIdentity)
	HTEST_RUN_METHOD(Matrix4, setTranslation)
	HTEST_RUN_METHOD(Matrix4, setScale)
	HTEST_RUN_METHOD(Matrix4, setRotation)
	HTEST_RUN_METHOD(Matrix4, det)
	HTEST_RUN_METHOD(Matrix4, transpose)
	HTEST_RUN_METHOD(Matrix4, translate)
	HTEST_RUN_METHOD(Matrix4, scale)
	HTEST_RUN_METHOD(Matrix4, rotate)
	HTEST_RUN_METHOD(Matrix4, inverse)
	HTEST_RUN_METHOD(Matrix4, inversed)
	HTEST_RUN_METHOD(Matrix4, inverseRotation)
	HTEST_RUN_METHOD(Matrix4, inversedRotation)
	HTEST_RUN_METHOD(Matrix4, multiplication)
	HTEST_RUN_METHOD(Matrix4, addition)
	HTEST_RUN_METHOD(Matrix4, substraction)
	HTEST_RUN_METHOD(Matrix4, multiplicationAssign)
	HTEST_RUN_METHOD(Matrix4, additionAssign)
	HTEST_RUN_METHOD(Matrix4, substractionAssign)
HTEST_RUN_CLASS_END
