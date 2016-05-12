#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

HL_UT_TEST_CLASS(Vector2)
{
	HL_UT_TEST_FUNCTION(assignment);
	HL_UT_TEST_FUNCTION(addition);
	HL_UT_TEST_FUNCTION(zeroLength);
	HL_UT_TEST_FUNCTION(length);
	HL_UT_TEST_FUNCTION(squaredLength);
	HL_UT_TEST_FUNCTION(angle);
	HL_UT_TEST_FUNCTION(normalize);
	HL_UT_TEST_FUNCTION(normalized);
	HL_UT_TEST_FUNCTION(rotate);
	HL_UT_TEST_FUNCTION(rotated);
	HL_UT_TEST_FUNCTION(dot);
	HL_UT_TEST_FUNCTION(negation);
	HL_UT_TEST_FUNCTION(substraction);
	HL_UT_TEST_FUNCTION(multiplicationVector);
	HL_UT_TEST_FUNCTION(divisionVector);
	HL_UT_TEST_FUNCTION(multiplication);
	HL_UT_TEST_FUNCTION(division);
	HL_UT_TEST_FUNCTION(additionAssign);
	HL_UT_TEST_FUNCTION(substractionAssign);
	HL_UT_TEST_FUNCTION(multiplicationVectorAssign);
	HL_UT_TEST_FUNCTION(divisionVectorAssign);
	HL_UT_TEST_FUNCTION(multiplicationAssign);
	HL_UT_TEST_FUNCTION(divisionAssign);
	HL_UT_TEST_FUNCTION(equal);
	HL_UT_TEST_FUNCTION(notEqual);
}

HL_UT_RUN_CLASS_BEGIN(Vector2)
	HL_UT_RUN_METHOD(Vector2, assignment)
	HL_UT_RUN_METHOD(Vector2, addition)
	HL_UT_RUN_METHOD(Vector2, zeroLength)
	HL_UT_RUN_METHOD(Vector2, length)
	HL_UT_RUN_METHOD(Vector2, squaredLength)
	HL_UT_RUN_METHOD(Vector2, angle)
	HL_UT_RUN_METHOD(Vector2, normalize)
	HL_UT_RUN_METHOD(Vector2, normalized)
	HL_UT_RUN_METHOD(Vector2, rotate)
	HL_UT_RUN_METHOD(Vector2, rotated)
	HL_UT_RUN_METHOD(Vector2, dot)
	HL_UT_RUN_METHOD(Vector2, negation)
	HL_UT_RUN_METHOD(Vector2, substraction)
	HL_UT_RUN_METHOD(Vector2, multiplicationVector)
	HL_UT_RUN_METHOD(Vector2, divisionVector)
	HL_UT_RUN_METHOD(Vector2, multiplication)
	HL_UT_RUN_METHOD(Vector2, division)
	HL_UT_RUN_METHOD(Vector2, additionAssign)
	HL_UT_RUN_METHOD(Vector2, substractionAssign)
	HL_UT_RUN_METHOD(Vector2, multiplicationVectorAssign)
	HL_UT_RUN_METHOD(Vector2, divisionVectorAssign)
	HL_UT_RUN_METHOD(Vector2, multiplicationAssign)
	HL_UT_RUN_METHOD(Vector2, divisionAssign)
	HL_UT_RUN_METHOD(Vector2, equal)
	HL_UT_RUN_METHOD(Vector2, notEqual)
HL_UT_RUN_CLASS_END
