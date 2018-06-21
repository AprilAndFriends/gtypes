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

HTEST_CLASS(Matrix4)
{
	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance = E_TOLRANCE)
	{
		return (habs(a - b) < tolerance);
	}

	bool gmat4eqf(const gmat4& m1, const gmat4& m2)
	{
		for (int i = 0; i < 16; i++)
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
		gmat4 m1;
		gmat4 m2;
		m2.setIdentity();
		HTEST_ASSERT(gmat4eqf(m1, m2), "constructor assignment");

		m1 = gmat4(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		m2.set(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "set()");

		m1 = gmat4(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		float values[16] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f };
		m2 = gmat4(values);
		HTEST_ASSERT(gmat4eqf(m1, m2), "set(array)");
		
		m1 = gmat4(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f,
			10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		m2 = gmat4(m1);
		HTEST_ASSERT(gmat4eqf(m1, m2), "set(mat4)");
	}

	HTEST_FUNCTION(setZero)
	{
		gmat4 m1;
		m1.setZero();
		gmat4 m2(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "");
	}

	HTEST_FUNCTION(setIdentity)
	{
		gmat4 m1;
		m1.setIdentity();
		gmat4 m2(1.0f, 0.0f, 0.0f, 0.0f, 
				 0.0f, 1.0f, 0.0f, 0.0f,
				 0.0f, 0.0f, 1.0f, 0.0f,
				 0.0f, 0.0f, 0.0f, 1.0f
				 );
		HTEST_ASSERT(gmat4eqf(m1, m2), "");
	}

	HTEST_FUNCTION(setTranslation)
	{
		gmat4 m1;
		m1.setIdentity();
		gmat4 m2(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			3.0f, 4.0f, 1.0f, 1.0f
			);
		m1.setTranslation(gvec3f(3.0f, 4.0f, 1.0f));
		HTEST_ASSERT(gmat4eqf(m1, m2), "setTranslation(vec2)");
		m1.setTranslation(3.0f, 4.0f, 1.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "setTranslation(float, float)");
	}

	HTEST_FUNCTION(setScale)
	{
		gmat4 m1;
		gmat4 m2(3.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 4.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);
		m1.setScale(gvec3f(3.0f, 4.0f, 1.0f));
		HTEST_ASSERT(gmat4eqf(m1, m2), "setScale(vec3)");

		m1.setScale(3.0f, 4.0f, 1.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "setScale(float, float, float)");

		m1.setScale(3.0f);
		m2 = gmat4(3.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 3.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 3.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);
		HTEST_ASSERT(gmat4eqf(m1, m2), "setScale(float)");
	}

	HTEST_FUNCTION(setRotation)
	{
		HTEST_ASSERT(true, "setRotation()"); //todo
	}

	HTEST_FUNCTION(det)
	{
		gmat4 m1;
		HTEST_ASSERT(m1.determinant() == 1, "");
	}

	HTEST_FUNCTION(transpose)
	{
		gmat4 m1(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
		gmat4 m2(1.0f, 5.0f, 9.0f, 13.0f, 2.0f, 6.0f, 10.0f, 14.0f, 3.0f, 7.0f, 11.0f, 15.0f, 4.0f, 8.0f, 12.0f, 16.0f);
		m1.transpose();
		HTEST_ASSERT(gmat4eqf(m1, m2), "");
	}

	HTEST_FUNCTION(translate)
	{
		gmat4 m1;
		gmat4 m2;
		m2.setTranslation(3.0f, 4.0f, 1.0f);
		m1.translate(3.0f, 4.0f, 1.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "translate(vec3)");
		m1.setIdentity();
		m1.translate(3.0f, 4.0f, 1.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "translate(float, float, float)");
	}

	HTEST_FUNCTION(scale)
	{
		gmat4 m1;
		gmat4 m2;
		m2.setScale(3.0f, 4.0f, 1.0f);
		m1.scale(gvec3f(3.0f, 4.0f, 1.0f));
		HTEST_ASSERT(gmat4eqf(m1, m2), "scale(vec3)");
		m1.setIdentity();
		m1.scale(3.0f, 4.0f, 1.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "scale(float, float, float)");
		m1.setIdentity();
		m1.scale(3.0f);
		m2.setScale(3.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "scale(float)");
	}

	HTEST_FUNCTION(rotate)
	{
		gmat4 m1;
		gmat4 m2;
		m2.setRotation(gvec3f(0.0f, 1.0f, 0.0f), 90.0f);
		m1.rotate(gvec3f(0.0f, 1.0f, 0.0f), 90.0f);
		HTEST_ASSERT(gmat4eqf(m1, m2), "");
	}

	HTEST_FUNCTION(inverse)
	{
		gmat4 m1;
		gmat4 m2;
		m1.inverse();
		HTEST_ASSERT(gmat4eqf(m1, m2), "");
	}

	HTEST_FUNCTION(inversed)
	{
		gmat4 m1;
		gmat4 m2;
		HTEST_ASSERT(gmat4eqf(m1.inversed(), m2), "");
	}

	HTEST_FUNCTION(inverseRotation)
	{
		gmat4 m1;
		gmat4 m2;
		m1.inverseRotation();
		HTEST_ASSERT(gmat4eqf(m1, m2), "");
	}

	HTEST_FUNCTION(inversedRotation)
	{
		gmat4 m1;
		gmat4 m2;
		HTEST_ASSERT(gmat4eqf(m1.inversedRotation(), m2), "");
	}

	HTEST_FUNCTION(multiplication)
	{
		gmat4 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		gmat4 m2;
		HTEST_ASSERT(gmat4eqf(m1 * m2, m1), "operator*(mat4)");
		m2 = gmat4(0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f, 18.0f, 20.0f, 22.0f, 24.0f, 26.0f, 28.0f, 30.0f);
		HTEST_ASSERT(gmat4eqf(m1 * 2, m2), "operator*(float)");
		gvec3f v(1.0f, 2.0f, 3.0f);
		m2.setIdentity();
		HTEST_ASSERT(vec3eqf(v, m2 * v), "operator*(vec3)");
	}

	HTEST_FUNCTION(addition)
	{
		gmat4 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		gmat4 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat4 m3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
		HTEST_ASSERT(gmat4eqf(m1 + m2, m3), "");
	}

	HTEST_FUNCTION(substraction)
	{
		gmat4 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		gmat4 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat4 m3(-1.0f, 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f);
		HTEST_ASSERT(gmat4eqf(m1 - m2, m3), "");
	}

	HTEST_FUNCTION(multiplicationAssign)
	{
		gmat4 m0(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		gmat4 m1;
		gmat4 m2;
		m1.set(m0);
		m1 *= m2;
		HTEST_ASSERT(gmat4eqf(m1, m0), "operator*=(mat4)");
		m1.set(m0);
		m2 = gmat4(0.0f, 2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f, 18.0f, 20.0f, 22.0f, 24.0f, 26.0f, 28.0f, 30.0f);
		m1 *= 2;
		HTEST_ASSERT(gmat4eqf(m1, m2), "operator*=(float)");
	}

	HTEST_FUNCTION(additionAssign)
	{
		gmat4 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		gmat4 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat4 m3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
		m1 += m2;
		HTEST_ASSERT(gmat4eqf(m1, m3), "");
	}

	HTEST_FUNCTION(substractionAssign)
	{
		gmat4 m1(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		gmat4 m2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		gmat4 m3(-1.0f, 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f);
		m1 -= m2;
		HTEST_ASSERT(gmat4eqf(m1, m3), "");
	}
}
