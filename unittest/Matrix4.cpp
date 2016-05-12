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

HL_UT_TEST_CLASS(Matrix4)
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

	static bool vec3eqf(const gvec3& v1, const gvec3& v2)
	{
		return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y) && heqf(v1.z, v2.z));
	}

	HL_UT_TEST_FUNCTION(assignment)
	{
		gmat4 m1;
		gmat4 m2;
		m2.setIdentity();
		HL_UT_ASSERT(gmat4eqf(m1, m2), "constructor assignment");

		m1 = gmat4(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		m2.set(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "set()");

		m1 = gmat4(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f);
		float values[16] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f };
		m2 = gmat4(values);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "set(array)");
		
		m1 = gmat4(0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f,
			10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f);
		m2 = gmat4(m1);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "set(mat4)");
	}

	HL_UT_TEST_FUNCTION(setZero)
	{
		gmat4 m1;
		m1.setZero();
		gmat4 m2(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(setIdentity)
	{
		gmat4 m1;
		m1.setIdentity();
		gmat4 m2(1.0f, 0.0f, 0.0f, 0.0f, 
				 0.0f, 1.0f, 0.0f, 0.0f,
				 0.0f, 0.0f, 1.0f, 0.0f,
				 0.0f, 0.0f, 0.0f, 1.0f
				 );
		HL_UT_ASSERT(gmat4eqf(m1, m2), "");
	}

	HL_UT_TEST_FUNCTION(setTranslation)
	{
		gmat4 m1;
		m1.setIdentity();
		gmat4 m2(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			3.0f, 4.0f, 1.0f, 1.0f
			);
		m1.setTranslation(gvec3(3.0f, 4.0f, 1.0f));
		HL_UT_ASSERT(gmat4eqf(m1, m2), "setTranslation(vec2)");
		m1.setTranslation(3.0f, 4.0f, 1.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "setTranslation(float, float)");
	}

	HL_UT_TEST_FUNCTION(setScale)
	{
		gmat4 m1;
		gmat4 m2(3.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 4.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);
		m1.setScale(gvec3(3.0f, 4.0f, 1.0f));
		HL_UT_ASSERT(gmat4eqf(m1, m2), "setScale(vec3)");

		m1.setScale(3.0f, 4.0f, 1.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "setScale(float, float, float)");

		m1.setScale(3.0f);
		m2 = gmat4(3.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 3.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 3.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "setScale(float)");
	}

	HL_UT_TEST_FUNCTION(setRotation)
	{
		HL_UT_ASSERT(true, "setRotation()"); //todo
	}

	HL_UT_TEST_FUNCTION(det)
	{
		gmat4 m1;
		HL_UT_ASSERT(m1.det() == 1, "");
	}

	HL_UT_TEST_FUNCTION(translate)
	{
		gmat4 m1;
		gmat4 m2;
		m2.setTranslation(3.0f, 4.0f, 1.0f);
		m1.translate(3.0f, 4.0f, 1.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "translate(vec3)");
		m1.setIdentity();
		m1.translate(3.0f, 4.0f, 1.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "translate(float, float, float)");
	}

	HL_UT_TEST_FUNCTION(scale)
	{
		gmat4 m1;
		gmat4 m2;
		m2.setScale(3.0f, 4.0f, 1.0f);
		m1.scale(gvec3(3.0f, 4.0f, 1.0f));
		HL_UT_ASSERT(gmat4eqf(m1, m2), "scale(vec3)");
		m1.setIdentity();
		m1.scale(3.0f, 4.0f, 1.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "scale(float, float, float)");
		m1.setIdentity();
		m1.scale(3.0f);
		m2.setScale(3.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "scale(float)");
	}

	HL_UT_TEST_FUNCTION(rotate)
	{
		gmat4 m1;
		gmat4 m2;
		m2.setRotation(gvec3(0.0f, 1.0f, 0.0f), 90.0f);
		m1.rotate(gvec3(0.0f, 1.0f, 0.0f), 90.0f);
		HL_UT_ASSERT(gmat4eqf(m1, m2), "");
	}
}
