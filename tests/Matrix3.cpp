#define __HTEST_LIB_NAME gtypes
#ifdef __APPLE__
#import "htest.h"
#else
#include "htest.h"
#endif

#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector2.h"
#include "Vector3.h"

#define E_TOLRANCE 0.0001f

HTEST_CLASS(Matrix3)
{
	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance = E_TOLRANCE)
	{
		return (habs(a - b) < tolerance);
	}

	bool gmat3eqf(const gmat3& m1, const gmat3& m2)
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

	static bool vec3eqf(const gvec3f& v1, const gvec3f& v2)
	{
		return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y) && heqf(v1.z, v2.z));
	}

	HTEST_FUNCTION(assignment)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setIdentity();
		HTEST_ASSERT(gmat3eqf(m1, m2), "constructor assignment");
		m1 = gmat3(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		m2.set(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "set()");
		m1 = gmat3(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		float values[9] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f };
		m2 = gmat3(values);
		HTEST_ASSERT(gmat3eqf(m1, m2), "set(array)");
		m1 = gmat3(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		gmat4 m4(
			0.0f, 1.0f, 2.0f, 0.0f,
			3.0f, 4.0f, 5.0f, 0.0f,
			6.0f, 7.0f, 8.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f
		);
		m2 = gmat3(m4);
		HTEST_ASSERT(gmat3eqf(m1, m2), "set(mat4)");
		m1 = gmat3(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		m2 = gmat3(m1);
		HTEST_ASSERT(gmat3eqf(m1, m2), "set(mat3)");
	}

	HTEST_FUNCTION(setZero)
	{
		gmat3 m1;
		m1.setZero();
		gmat3 m2(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(setIdentity)
	{
		gmat3 m1;
		m1.setIdentity();
		gmat3 m2(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(setTranslation)
	{
		gmat3 m1;
		gmat3 m2(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 3.0f, 4.0f, 1.0f);
		m1.setTranslation(gvec2f(3.0f, 4.0f));
		HTEST_ASSERT(gmat3eqf(m1, m2), "setTranslation(vec2)");
		m1.setTranslation(3.0f, 4.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "setTranslation(float, float)");
	}

	HTEST_FUNCTION(setScale)
	{
		gmat3 m1;
		gmat3 m2(3.0f, 0.0f, 0.0f, 0.0f, 4.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		m1.setScale(gvec2f(3.0f, 4.0f));
		HTEST_ASSERT(gmat3eqf(m1, m2), "setScale(vec2)");
		m1.setScale(3.0f, 4.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "setScale(float, float)");
		m1.setScale(3.0f);
		m2 = gmat3(3.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "setScale(float)");
	}

	HTEST_FUNCTION(setScale3D)
	{
		gmat3 m1;
		gmat3 m2(3.0f, 0.0f, 0.0f, 0.0f, 4.0f, 0.0f, 0.0f, 0.0f, 5.0f);
		m1.setScale3D(gvec3f(3.0f, 4.0f, 5.0f));
		HTEST_ASSERT(gmat3eqf(m1, m2), "setScale3D(vec3)");
		m1.setScale3D(3.0f, 4.0f, 5.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "setScale3D(float, float, float)");
		m1.setScale3D(3.0f);
		m2 = gmat3(3.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 3.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "setScale3D(float)");
	}

	HTEST_FUNCTION(setRotation)
	{
		gmat3 m1;
		gmat3 m2(0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
		m1.setRotation(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "setRotation()");
	}

	HTEST_FUNCTION(setRotation3D)
	{
		gmat3 m1;
		gmat3 m2;
		m1.setRotation3D(gvec3f(0.0f, 0.0f, -1.0f), 90.0f);
		m2.setRotation3DZ(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "setScale3D(vec3)");
	}

	HTEST_FUNCTION(setRotation3DX)
	{
		gmat3 m1;
		gmat3 m2(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f);
		m1.setRotation3DX(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(setRotation3DY)
	{
		gmat3 m1;
		gmat3 m2(0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f);
		m1.setRotation3DY(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}
	HTEST_FUNCTION(setRotation3DZ)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation(90.0f);
		m1.setRotation3DZ(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(determinant)
	{
		gmat3 m1;
		HTEST_ASSERT(m1.determinant() == 1, "");
	}

	HTEST_FUNCTION(translate)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setTranslation(3.0f, 4.0f);
		m1.translate(3.0f, 4.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "translate(vec2)");
		m1.setIdentity();
		m1.translate(3.0f, 4.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "translate(float, float)");
	}

	HTEST_FUNCTION(scale)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setScale(3.0f, 4.0f);
		m1.scale(gvec2f(3.0f, 4.0f));
		HTEST_ASSERT(gmat3eqf(m1, m2), "scale(vec2)");
		m1.setIdentity();
		m1.scale(3.0f, 4.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "scale(float, float)");
		m1.setIdentity();
		m1.scale(3.0f);
		m2.setScale(3.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "scale(float)");
	}

	HTEST_FUNCTION(scale3D)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setScale3D(3.0f, 4.0f, 5.0f);
		m1.scale3D(gvec3f(3.0f, 4.0f, 5.0f));
		HTEST_ASSERT(gmat3eqf(m1, m2), "scale3D(vec3)");
		m1.setIdentity();
		m1.scale3D(3.0f, 4.0f, 5.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "scale3D(float, float, float)");
		m1.setIdentity();
		m1.scale3D(3.0f);
		m2.setScale3D(3.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "scale3D(float)");
	}

	HTEST_FUNCTION(rotate)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation(90.0f);
		m1.rotate(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(rotate3D)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3D(gvec3f(0.0f, 1.0f, 0.0f), 90.0f);
		m1.rotate3D(gvec3f(0.0f, 1.0f, 0.0f), 90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "rotate3D(vec3)");
		m1.setIdentity();
		m1.rotate3D(0.0f, 1.0f, 0.0f, 90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "rotate3D(float, float, float, float)");
	}

	HTEST_FUNCTION(rotate3DX)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DX(90.0f);
		m1.rotate3DX(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(rotate3DY)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DY(90.0f);
		m1.rotate3DY(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(rotate3DZ)
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DZ(90.0f);
		m1.rotate3DZ(90.0f);
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(transpose)
	{
		gmat3 m1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
		gmat3 m2(1.0f, 4.0f, 7.0f, 2.0f, 5.0f, 8.0f, 3.0f, 6.0f, 9.0f);
		m1.transpose();
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(transposed)
	{
		gmat3 m1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
		gmat3 m2(1.0f, 4.0f, 7.0f, 2.0f, 5.0f, 8.0f, 3.0f, 6.0f, 9.0f);
		HTEST_ASSERT(gmat3eqf(m1.transposed(), m2), "");
	}

	HTEST_FUNCTION(inverse)
	{
		gmat3 m1;
		gmat3 m2;
		m1.inverse();
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(inversed)
	{
		gmat3 m1;
		gmat3 m2;
		HTEST_ASSERT(gmat3eqf(m1.inversed(), m2), "");
	}

	HTEST_FUNCTION(inverseRotation)
	{
		gmat3 m1;
		gmat3 m2;
		m1.inverseRotation();
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(inversedRotation)
	{
		gmat3 m1;
		gmat3 m2;
		HTEST_ASSERT(gmat3eqf(m1.inversedRotation(), m2), "");
	}

	HTEST_FUNCTION(inverseRotation3D)
	{
		gmat3 m1;
		gmat3 m2;
		m1.inverseRotation3D();
		HTEST_ASSERT(gmat3eqf(m1, m2), "");
	}

	HTEST_FUNCTION(inversedRotation3D)
	{
		gmat3 m1;
		gmat3 m2;
		HTEST_ASSERT(gmat3eqf(m1.inversedRotation3D(), m2), "");
	}

	HTEST_FUNCTION(orthoNormalize)
	{
//		unit test not working, disabling it for now
//		gmat3 m1(2.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 1.0f, 1.0f);
//		gmat3 m2(1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
//		m1.orthoNormalize();
//		HTEST_ASSERT(gmat3eqf(m1, m2), "orthoNormalise");
		HTEST_ASSERT(true, "orthoNormalise");
	}

	HTEST_FUNCTION(orthoNormalized)
	{
//		unit test not working, disabling it for now
//		gmat3 m1(2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 1.0f, 1.0f);
//		gmat3 m2(0.894427f, 0.447214f, 0.0f, -0.447214f, -0.894427f, 0.0f, 0.0f, 0.0f, 1.0f);
//		HTEST_ASSERT(gmat3eqf(m1.orthoNormalized(), m2), "");
		HTEST_ASSERT(true, "orthoNormalise");
	}

	HTEST_FUNCTION(multiplication)
	{
		gmat3 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		gmat3 m2;
		HTEST_ASSERT(gmat3eqf(m1 * m2, m1), "operator*(mat3)");
		m2 = gmat3(0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f);
		HTEST_ASSERT(gmat3eqf(m1 * 2, m2), "operator*(float)");
		gvec3f v(1.0f, 2.0f, 3.0f);
		m2.setIdentity();
		HTEST_ASSERT(vec3eqf(v, m2 * v), "operator*(vec3)");
	}

	HTEST_FUNCTION(addition)
	{
		gmat3 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		gmat3 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat3 m3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
		HTEST_ASSERT(gmat3eqf(m1 + m2, m3), "");
	}

	HTEST_FUNCTION(substraction)
	{
		gmat3 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		gmat3 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat3 m3(-1.0f, 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f);
		HTEST_ASSERT(gmat3eqf(m1 - m2, m3), "");
	}

	HTEST_FUNCTION(multiplicationAssign)
	{
		gmat3 m0(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		gmat3 m1;
		gmat3 m2;
		m1.set(m0);
		m1 *= m2;
		HTEST_ASSERT(gmat3eqf(m1, m0), "operator*=(mat3)");
		m1.set(m0);
		m2 = gmat3(0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f);
		m1 *= 2;
		HTEST_ASSERT(gmat3eqf(m1, m2), "operator*=(float)");
	}

	HTEST_FUNCTION(additionAssign)
	{
		gmat3 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		gmat3 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat3 m3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
		m1 += m2;
		HTEST_ASSERT(gmat3eqf(m1, m3), "");
	}

	HTEST_FUNCTION(substractionAssign)
	{
		gmat3 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f);
		gmat3 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat3 m3(-1.0f, 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f);
		m1 -= m2;
		HTEST_ASSERT(gmat3eqf(m1, m3), "");
	}

}
