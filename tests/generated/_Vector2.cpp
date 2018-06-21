#define __HTEST_LIB_NAME gtypes
#include "htest.h"

HTEST_CLASS(Vector2)
{
	HTEST_FUNCTION(assignment);
	HTEST_FUNCTION(addition);
	HTEST_FUNCTION(zeroLength);
	HTEST_FUNCTION(length);
	HTEST_FUNCTION(squaredLength);
	HTEST_FUNCTION(angle);
	HTEST_FUNCTION(normalize);
	HTEST_FUNCTION(normalized);
	HTEST_FUNCTION(rotate);
	HTEST_FUNCTION(rotated);
	HTEST_FUNCTION(dot);
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

HTEST_RUN_CLASS_BEGIN(Vector2)
	HTEST_RUN_METHOD(Vector2, assignment)
	HTEST_RUN_METHOD(Vector2, addition)
	HTEST_RUN_METHOD(Vector2, zeroLength)
	HTEST_RUN_METHOD(Vector2, length)
	HTEST_RUN_METHOD(Vector2, squaredLength)
	HTEST_RUN_METHOD(Vector2, angle)
	HTEST_RUN_METHOD(Vector2, normalize)
	HTEST_RUN_METHOD(Vector2, normalized)
	HTEST_RUN_METHOD(Vector2, rotate)
	HTEST_RUN_METHOD(Vector2, rotated)
	HTEST_RUN_METHOD(Vector2, dot)
	HTEST_RUN_METHOD(Vector2, negation)
	HTEST_RUN_METHOD(Vector2, substraction)
	HTEST_RUN_METHOD(Vector2, multiplicationVector)
	HTEST_RUN_METHOD(Vector2, divisionVector)
	HTEST_RUN_METHOD(Vector2, multiplication)
	HTEST_RUN_METHOD(Vector2, division)
	HTEST_RUN_METHOD(Vector2, additionAssign)
	HTEST_RUN_METHOD(Vector2, substractionAssign)
	HTEST_RUN_METHOD(Vector2, multiplicationVectorAssign)
	HTEST_RUN_METHOD(Vector2, divisionVectorAssign)
	HTEST_RUN_METHOD(Vector2, multiplicationAssign)
	HTEST_RUN_METHOD(Vector2, divisionAssign)
	HTEST_RUN_METHOD(Vector2, equal)
	HTEST_RUN_METHOD(Vector2, notEqual)
HTEST_RUN_CLASS_END
