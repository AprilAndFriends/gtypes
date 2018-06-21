#define __HTEST_LIB_NAME gtypes
#include "htest.h"

HTEST_CLASS(Vector3)
{
	HTEST_FUNCTION(assignment);
	HTEST_FUNCTION(addition);
	HTEST_FUNCTION(zeroLength);
	HTEST_FUNCTION(length);
	HTEST_FUNCTION(squaredLength);
	HTEST_FUNCTION(normalize);
	HTEST_FUNCTION(normalized);
	HTEST_FUNCTION(dot);
	HTEST_FUNCTION(cross);
	HTEST_FUNCTION(negation);
	HTEST_FUNCTION(substraction);
	HTEST_FUNCTION(multiplicationVector);
	HTEST_FUNCTION(divisionVector);
	HTEST_FUNCTION(multiplication);
	HTEST_FUNCTION(division);
	HTEST_FUNCTION(additionAssign);
	HTEST_FUNCTION(substractionAssign);
	HTEST_FUNCTION(multiplicationVectorAssign);
	HTEST_FUNCTION(divisionVectorAssign);
	HTEST_FUNCTION(multiplicationAssign);
	HTEST_FUNCTION(divisionAssign);
	HTEST_FUNCTION(equal);
	HTEST_FUNCTION(notEqual);
}

HTEST_RUN_CLASS_BEGIN(Vector3)
	HTEST_RUN_METHOD(Vector3, assignment)
	HTEST_RUN_METHOD(Vector3, addition)
	HTEST_RUN_METHOD(Vector3, zeroLength)
	HTEST_RUN_METHOD(Vector3, length)
	HTEST_RUN_METHOD(Vector3, squaredLength)
	HTEST_RUN_METHOD(Vector3, normalize)
	HTEST_RUN_METHOD(Vector3, normalized)
	HTEST_RUN_METHOD(Vector3, dot)
	HTEST_RUN_METHOD(Vector3, cross)
	HTEST_RUN_METHOD(Vector3, negation)
	HTEST_RUN_METHOD(Vector3, substraction)
	HTEST_RUN_METHOD(Vector3, multiplicationVector)
	HTEST_RUN_METHOD(Vector3, divisionVector)
	HTEST_RUN_METHOD(Vector3, multiplication)
	HTEST_RUN_METHOD(Vector3, division)
	HTEST_RUN_METHOD(Vector3, additionAssign)
	HTEST_RUN_METHOD(Vector3, substractionAssign)
	HTEST_RUN_METHOD(Vector3, multiplicationVectorAssign)
	HTEST_RUN_METHOD(Vector3, divisionVectorAssign)
	HTEST_RUN_METHOD(Vector3, multiplicationAssign)
	HTEST_RUN_METHOD(Vector3, divisionAssign)
	HTEST_RUN_METHOD(Vector3, equal)
	HTEST_RUN_METHOD(Vector3, notEqual)
HTEST_RUN_CLASS_END
