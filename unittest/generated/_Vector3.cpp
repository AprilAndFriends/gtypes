#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

HL_UT_TEST_CLASS(Vector3)
{
	HL_UT_TEST_FUNCTION(assignment);
	HL_UT_TEST_FUNCTION(addition);
	HL_UT_TEST_FUNCTION(zeroLength);
	HL_UT_TEST_FUNCTION(length);
	HL_UT_TEST_FUNCTION(squaredLength);
	HL_UT_TEST_FUNCTION(normalize);
	HL_UT_TEST_FUNCTION(normalized);
	HL_UT_TEST_FUNCTION(dot);
	HL_UT_TEST_FUNCTION(cross);
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

HL_UT_RUN_CLASS_BEGIN(Vector3)
	HL_UT_RUN_METHOD(Vector3, assignment)
	HL_UT_RUN_METHOD(Vector3, addition)
	HL_UT_RUN_METHOD(Vector3, zeroLength)
	HL_UT_RUN_METHOD(Vector3, length)
	HL_UT_RUN_METHOD(Vector3, squaredLength)
	HL_UT_RUN_METHOD(Vector3, normalize)
	HL_UT_RUN_METHOD(Vector3, normalized)
	HL_UT_RUN_METHOD(Vector3, dot)
	HL_UT_RUN_METHOD(Vector3, cross)
	HL_UT_RUN_METHOD(Vector3, negation)
	HL_UT_RUN_METHOD(Vector3, substraction)
	HL_UT_RUN_METHOD(Vector3, multiplicationVector)
	HL_UT_RUN_METHOD(Vector3, divisionVector)
	HL_UT_RUN_METHOD(Vector3, multiplication)
	HL_UT_RUN_METHOD(Vector3, division)
	HL_UT_RUN_METHOD(Vector3, additionAssign)
	HL_UT_RUN_METHOD(Vector3, substractionAssign)
	HL_UT_RUN_METHOD(Vector3, multiplicationVectorAssign)
	HL_UT_RUN_METHOD(Vector3, divisionVectorAssign)
	HL_UT_RUN_METHOD(Vector3, multiplicationAssign)
	HL_UT_RUN_METHOD(Vector3, divisionAssign)
	HL_UT_RUN_METHOD(Vector3, equal)
	HL_UT_RUN_METHOD(Vector3, notEqual)
HL_UT_RUN_CLASS_END
