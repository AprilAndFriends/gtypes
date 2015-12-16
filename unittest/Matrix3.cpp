#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector2.h"
#include "Vector3.h"

#define E_TOLRANCE 0.0001f

HL_UT_TEST_CLASS(Matrix3)
{
	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance = E_TOLRANCE)
	{
		return (habs(a - b) < tolerance);
	}

	bool gmat3eqf(gmat3 m1, gmat3 m2)
	{
		for (int i = 0; i < 9; i++)
		{
			if (!heqf(m1[i], m2[i]))
			{
				return false;
			}
		}
		return true;
	}

	static bool vec3eqf(gvec3 v1, gvec3 v2)
	{
		return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y) && heqf(v1.z, v2.z));
	}

	HL_UT_TEST_FUNCTION(assignment)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setIdentity();
		HL_UT_ASSERT(gmat3eqf(m1, m2), "constructor assignment");
		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		m2.set(0, 1, 2, 3, 4, 5, 6, 7, 8);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "set()");
		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		float values[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		m2 = gmat3(values);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "set(array)");
		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat4 m4(
			0, 1, 2, 0,
			3, 4, 5, 0,
			6, 7, 8, 0,
			0, 0, 0, 0
		);
		m2 = gmat3(m4);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "set(mat4)");
		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		m2 = gmat3(m1);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "set(mat3)");
	}

	HL_UT_TEST_FUNCTION(setZero)
	{
		gmat3 m1;
		m1.setZero();
		gmat3 m2(0, 0, 0, 0, 0, 0, 0, 0, 0);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(setIdentity)
	{
		gmat3 m1;
		m1.setIdentity();
		gmat3 m2(1, 0, 0, 0, 1, 0, 0, 0, 1);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(setTranslation)
	{
		gmat3 m1;
		gmat3 m2(1, 0, 0, 0, 1, 0, 3, 4, 1);
		m1.setTranslation(gvec2(3, 4));
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setTranslation(vec2)");
		m1.setTranslation(3, 4);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setTranslation(float, float)");
	}

	HL_UT_TEST_FUNCTION(setScale)
	{
		gmat3 m1;
		gmat3 m2(3, 0, 0, 0, 4, 0, 0, 0, 1);
		m1.setScale(gvec2(3, 4));
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setScale(vec2)");
		m1.setScale(3, 4);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setScale(float, float)");
		m1.setScale(3);
		m2 = gmat3(3, 0, 0, 0, 3, 0, 0, 0, 1);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setScale(float)");
	}

	HL_UT_TEST_FUNCTION(setScale3D)
	{
		gmat3 m1;
		gmat3 m2(3, 0, 0, 0, 4, 0, 0, 0, 5);
		m1.setScale3D(gvec3(3, 4, 5));
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setScale3D(vec3)");
		m1.setScale3D(3, 4, 5);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setScale3D(float, float, float)");
		m1.setScale3D(3);
		m2 = gmat3(3, 0, 0, 0, 3, 0, 0, 0, 3);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setScale3D(float)");
	}

	HL_UT_TEST_FUNCTION(setRotation)
	{
		gmat3 m1;
		gmat3 m2(0, -1, 0, 1, 0, 0, 0, 0, 1);
		m1.setRotation(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setRotation()");
	}

	HL_UT_TEST_FUNCTION(setRotation3D)
	{
		gmat3 m1;
		gmat3 m2;
		m1.setRotation3D(gvec3(0, 0, -1), 90);
		m2.setRotation3DZ(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "setScale3D(vec3)");
	}

	HL_UT_TEST_FUNCTION(setRotation3DX)
	{
		gmat3 m1;
		gmat3 m2(1, 0, 0, 0, 0, 1, 0, -1, 0);
		m1.setRotation3DX(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(setRotation3DY)
	{
		gmat3 m1;
		gmat3 m2(0, 0, -1, 0, 1, 0, 1, 0, 0);
		m1.setRotation3DY(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(setRotation3DZ)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation(90);
		m1.setRotation3DZ(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(det)
	{
		gmat3 m1;
		HL_UT_ASSERT(m1.det() == 1, "");
	}

	HL_UT_TEST_FUNCTION(translate)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setTranslation(3, 4);
		m1.translate(3, 4);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "translate(vec2)");
		m1.setIdentity();
		m1.translate(3, 4);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "translate(float, float)");
	}

	HL_UT_TEST_FUNCTION(scale)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setScale(3, 4);
		m1.scale(gvec2(3, 4));
		HL_UT_ASSERT(gmat3eqf(m1, m2), "scale(vec2)");
		m1.setIdentity();
		m1.scale(3, 4);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "scale(float, float)");
		m1.setIdentity();
		m1.scale(3);
		m2.setScale(3);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "scale(float)");
	}

	HL_UT_TEST_FUNCTION(scale3D)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setScale3D(3, 4, 5);
		m1.scale3D(gvec3(3, 4, 5));
		HL_UT_ASSERT(gmat3eqf(m1, m2), "scale3D(vec3)");
		m1.setIdentity();
		m1.scale3D(3, 4, 5);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "scale3D(float, float, float)");
		m1.setIdentity();
		m1.scale3D(3);
		m2.setScale3D(3);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "scale3D(float)");
	}

	HL_UT_TEST_FUNCTION(rotate)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation(90);
		m1.rotate(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(rotate3D)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3D(gvec3(0, 1, 0), 90);
		m1.rotate3D(gvec3(0, 1, 0), 90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "rotate3D(vec3)");
		m1.setIdentity();
		m1.rotate3D(0, 1, 0, 90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "rotate3D(float, float, float, float)");
	}

	HL_UT_TEST_FUNCTION(rotate3DX)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DX(90);
		m1.rotate3DX(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(rotate3DY)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DY(90);
		m1.rotate3DY(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(rotate3DZ)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DZ(90);
		m1.rotate3DZ(90);
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(transpose)
	{
		gmat3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
		gmat3 m2(1, 4, 7, 2, 5, 8, 3, 6, 9);
		m1.transpose();
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(transposed)
	{
		gmat3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
		gmat3 m2(1, 4, 7, 2, 5, 8, 3, 6, 9);
		HL_UT_ASSERT(gmat3eqf(m1.transposed(), m2), "");
	}

	HL_UT_TEST_FUNCTION(inverse)
	{
		gmat3 m1;
		gmat3 m2;
		m1.inverse();
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(inversed)
	{
		gmat3 m1;
		gmat3 m2;
		HL_UT_ASSERT(gmat3eqf(m1.inversed(), m2), "");
	}

	HL_UT_TEST_FUNCTION(inverseRotation)
	{
		gmat3 m1;
		gmat3 m2;
		m1.inverseRotation();
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(inversedRotation)
	{
		gmat3 m1;
		gmat3 m2;
		HL_UT_ASSERT(gmat3eqf(m1.inversedRotation(), m2), "");
	}

	HL_UT_TEST_FUNCTION(inverseRotation3D)
	{
		gmat3 m1;
		gmat3 m2;
		m1.inverseRotation3D();
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(inversedRotation3D)
	{
		gmat3 m1;
		gmat3 m2;
		HL_UT_ASSERT(gmat3eqf(m1.inversedRotation3D(), m2), "");
	}

	HL_UT_TEST_FUNCTION(orthoNormalize)
	{
		gmat3 m1;
		gmat3 m2;
		m1.orthoNormalize();
		HL_UT_ASSERT(gmat3eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(orthoNormalized)
	{
		gmat3 m1;
		gmat3 m2;
		HL_UT_ASSERT(gmat3eqf(m1.orthoNormalized(), m2), "");
	}

	HL_UT_TEST_FUNCTION(multiplication)
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2;
		HL_UT_ASSERT(gmat3eqf(m1 * m2, m1), "operator*(mat3)");
		m2 = gmat3(0, 2, 4, 6, 8, 10, 12, 14, 16);
		HL_UT_ASSERT(gmat3eqf(m1 * 2, m2), "operator*(float)");
		gvec3 v(1, 2, 3);
		m2.setIdentity();
		HL_UT_ASSERT(vec3eqf(v, m2 * v), "operator*(vec3)");
	}

	HL_UT_TEST_FUNCTION(addition)
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(1, 2, 3, 4, 5, 6, 7, 8, 9);
		HL_UT_ASSERT(gmat3eqf(m1 + m2, m3), "");
	}

	HL_UT_TEST_FUNCTION(substraction)
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(-1, 0, 1, 2, 3, 4, 5, 6, 7);
		HL_UT_ASSERT(gmat3eqf(m1 - m2, m3), "");
	}

	HL_UT_TEST_FUNCTION(multiplicationAssign)
	{
		gmat3 m0(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m1;
		gmat3 m2;
		m1.set(m0);
		m1 *= m2;
		HL_UT_ASSERT(gmat3eqf(m1, m0), "operator*=(mat3)");
		m1.set(m0);
		m2 = gmat3(0, 2, 4, 6, 8, 10, 12, 14, 16);
		m1 *= 2;
		HL_UT_ASSERT(gmat3eqf(m1, m2), "operator*=(float)");
	}

	HL_UT_TEST_FUNCTION(additionAssign)
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(1, 2, 3, 4, 5, 6, 7, 8, 9);
		m1 += m2;
		HL_UT_ASSERT(gmat3eqf(m1, m3), "");
	}

	HL_UT_TEST_FUNCTION(substractionAssign)
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(-1, 0, 1, 2, 3, 4, 5, 6, 7);
		m1 -= m2;
		HL_UT_ASSERT(gmat3eqf(m1, m3), "");
	}

}
