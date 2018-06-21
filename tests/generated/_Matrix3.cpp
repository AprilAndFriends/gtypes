#define __HTEST_LIB_NAME gtypes
#include "htest.h"

HTEST_CLASS(Matrix3)
{
	HTEST_FUNCTION(assignment);
	HTEST_FUNCTION(setZero);
	HTEST_FUNCTION(setIdentity);
	HTEST_FUNCTION(setTranslation);
	HTEST_FUNCTION(setScale);
	HTEST_FUNCTION(setScale3D);
	HTEST_FUNCTION(setRotation);
	HTEST_FUNCTION(setRotation3D);
	HTEST_FUNCTION(setRotation3DX);
	HTEST_FUNCTION(setRotation3DY);
	HTEST_FUNCTION(setRotation3DZ);
	HTEST_FUNCTION(determinant);
	HTEST_FUNCTION(translate);
	HTEST_FUNCTION(scale);
	HTEST_FUNCTION(scale3D);
	HTEST_FUNCTION(rotate);
	HTEST_FUNCTION(rotate3D);
	HTEST_FUNCTION(rotate3DX);
	HTEST_FUNCTION(rotate3DY);
	HTEST_FUNCTION(rotate3DZ);
	HTEST_FUNCTION(transpose);
	HTEST_FUNCTION(transposed);
	HTEST_FUNCTION(inverse);
	HTEST_FUNCTION(inversed);
	HTEST_FUNCTION(inverseRotation);
	HTEST_FUNCTION(inversedRotation);
	HTEST_FUNCTION(inverseRotation3D);
	HTEST_FUNCTION(inversedRotation3D);
	HTEST_FUNCTION(orthoNormalize);
	HTEST_FUNCTION(orthoNormalized);
	HTEST_FUNCTION(multiplication);
	HTEST_FUNCTION(addition);
	HTEST_FUNCTION(substraction);
	HTEST_FUNCTION(multiplicationAssign);
	HTEST_FUNCTION(additionAssign);
	HTEST_FUNCTION(substractionAssign);
}

HTEST_RUN_CLASS_BEGIN(Matrix3)
	HTEST_RUN_METHOD(Matrix3, assignment)
	HTEST_RUN_METHOD(Matrix3, setZero)
	HTEST_RUN_METHOD(Matrix3, setIdentity)
	HTEST_RUN_METHOD(Matrix3, setTranslation)
	HTEST_RUN_METHOD(Matrix3, setScale)
	HTEST_RUN_METHOD(Matrix3, setScale3D)
	HTEST_RUN_METHOD(Matrix3, setRotation)
	HTEST_RUN_METHOD(Matrix3, setRotation3D)
	HTEST_RUN_METHOD(Matrix3, setRotation3DX)
	HTEST_RUN_METHOD(Matrix3, setRotation3DY)
	HTEST_RUN_METHOD(Matrix3, setRotation3DZ)
	HTEST_RUN_METHOD(Matrix3, determinant)
	HTEST_RUN_METHOD(Matrix3, translate)
	HTEST_RUN_METHOD(Matrix3, scale)
	HTEST_RUN_METHOD(Matrix3, scale3D)
	HTEST_RUN_METHOD(Matrix3, rotate)
	HTEST_RUN_METHOD(Matrix3, rotate3D)
	HTEST_RUN_METHOD(Matrix3, rotate3DX)
	HTEST_RUN_METHOD(Matrix3, rotate3DY)
	HTEST_RUN_METHOD(Matrix3, rotate3DZ)
	HTEST_RUN_METHOD(Matrix3, transpose)
	HTEST_RUN_METHOD(Matrix3, transposed)
	HTEST_RUN_METHOD(Matrix3, inverse)
	HTEST_RUN_METHOD(Matrix3, inversed)
	HTEST_RUN_METHOD(Matrix3, inverseRotation)
	HTEST_RUN_METHOD(Matrix3, inversedRotation)
	HTEST_RUN_METHOD(Matrix3, inverseRotation3D)
	HTEST_RUN_METHOD(Matrix3, inversedRotation3D)
	HTEST_RUN_METHOD(Matrix3, orthoNormalize)
	HTEST_RUN_METHOD(Matrix3, orthoNormalized)
	HTEST_RUN_METHOD(Matrix3, multiplication)
	HTEST_RUN_METHOD(Matrix3, addition)
	HTEST_RUN_METHOD(Matrix3, substraction)
	HTEST_RUN_METHOD(Matrix3, multiplicationAssign)
	HTEST_RUN_METHOD(Matrix3, additionAssign)
	HTEST_RUN_METHOD(Matrix3, substractionAssign)
HTEST_RUN_CLASS_END
