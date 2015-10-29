#include "generated/aprilUT.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector2.h"
#include "Vector3.h"

namespace testMatrix3
{
	float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	bool heqf(float a, float b, float tolerance)
	{
		return (habs(a - b) < tolerance);
	}

	const float tolerance = 0.1f;

	bool gmat3EQ(gmat3 m1, gmat3 m2)
	{
		bool equal = true;
		for (int i = 0; i < 9; i++)
		{
			if (!heqf(m1[i],m2[i], tolerance))
			{
				equal = false;
				return false;
			}
		}
		return true;
	}

	bool vec3eqf(gvec3 v1, gvec3 v2)
	{
		if (heqf(v1.x, v2.x, tolerance) && heqf(v1.y, v2.y, tolerance) && heqf(v1.z, v2.z, tolerance))
			return true;
		return false;
	}

	void testAssignment()
	{
		gmat3 m1;
		gmat3 m2; 
		m2.setIdentity();

		assertTrue(gmat3EQ(m1, m2), "gmat3::testAssignment - constructor assignment");		

		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		m2.set(0, 1, 2, 3, 4, 5, 6, 7, 8);

		assertTrue(gmat3EQ(m1, m2), "gmat3::testAssignment - set()");

		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		float values[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		m2 = gmat3(values);

		assertTrue(gmat3EQ(m1, m2), "gmat3::testAssignment - set(array)");

		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat4 m4(0, 1, 2, 0,
				 3, 4, 5, 0,
				 6, 7, 8, 0,
				 0, 0, 0, 0);
		m2 = gmat3(m4);

		assertTrue(gmat3EQ(m1, m2), "gmat3::testAssignment - set(mat4)");

		m1 = gmat3(0, 1, 2, 3, 4, 5, 6, 7, 8);
		m2 = gmat3(m1);

		assertTrue(gmat3EQ(m1, m2), "gmat3::testAssignment - set(mat3)");
	}
	void testSetZero()
	{
		gmat3 m1;
		m1.setZero();

		gmat3 m2(0, 0, 0, 0, 0, 0, 0, 0, 0);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setZero()");
	}
	void testSetIdentity()
	{
		gmat3 m1;
		m1.setIdentity();

		gmat3 m2(1, 0, 0, 0, 1, 0, 0, 0, 1);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setIdentity()");
	}
	void testSetTranslation()
	{
		gmat3 m1;
		gmat3 m2(1, 0, 0, 0, 1, 0, 3, 4, 1);

		m1.setTranslation(gvec2(3, 4));		
		assertTrue(gmat3EQ(m1, m2), "gmat3::setTranslation(vec2)");

		m1.setTranslation(3,4);		
		assertTrue(gmat3EQ(m1, m2), "gmat3::setTranslation(float, float)");
	}
	void testSetScale()
	{
		gmat3 m1;
		gmat3 m2(3, 0, 0, 0, 4, 0, 0, 0, 1);

		m1.setScale(gvec2(3, 4));		
		assertTrue(gmat3EQ(m1, m2), "gmat3::setScale(vec2)");

		m1.setScale(3, 4);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setScale(float, float)");

		m1.setScale(3);		
		m2 = gmat3(3, 0, 0, 0, 3, 0, 0, 0, 1);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setScale(float)");
	}
	void testSetScale3D()
	{
		gmat3 m1;
		gmat3 m2(3, 0, 0, 0, 4, 0, 0, 0, 5);
		
		m1.setScale3D(gvec3(3, 4, 5));		
		assertTrue(gmat3EQ(m1, m2), "gmat3::setScale3D(vec3)");

		m1.setScale3D(3, 4, 5);	
		assertTrue(gmat3EQ(m1, m2), "gmat3::setScale3D(float, float, float)");

		m1.setScale3D(3);
		m2 = gmat3(3, 0, 0, 0, 3, 0, 0, 0, 3);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setScale3D(float)");
	}
	void testSetRotation()
	{
		gmat3 m1;
		gmat3 m2(0, -1, 0, 1, 0, 0, 0, 0, 1);

		m1.setRotation(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setRotation()");
	}
	void testSetRotation3D()
	{
		gmat3 m1;
		gmat3 m2;

		m1.setRotation3D(gvec3(0, 0, -1), 90);
		m2.setRotation3DZ(90);

		assertTrue(gmat3EQ(m1, m2), "gmat3::setScale3D(vec3)");
	}
	void testSetRotation3DX()
	{
		gmat3 m1;
		gmat3 m2(1, 0, 0, 0, 0, 1, 0, -1, 0);

		m1.setRotation3DX(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setRotation3DX()");
	}
	void testSetRotation3DY()
	{
		gmat3 m1;
		gmat3 m2(0, 0, -1, 0, 1, 0, 1, 0, 0);

		m1.setRotation3DY(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setRotation3DY()");
	}
	void testSetRotation3DZ()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation(90);

		m1.setRotation3DZ(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::setRotation3DZ()");
	}
	void testDet()
	{
		gmat3 m1;
		
		assertTrue(m1.det() == 1, "gmat3::setRotation3DZ()");
	}
	void testTranslate()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setTranslation(3, 4);

		m1.translate(3, 4);
		assertTrue(gmat3EQ(m1, m2), "gmat3::translate(vec2)");

		m1.setIdentity();
		m1.translate(3, 4);
		assertTrue(gmat3EQ(m1, m2), "gmat3::translate(float, float)");
	}
	void testScale()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setScale(3, 4);

		m1.scale(gvec2(3, 4));
		assertTrue(gmat3EQ(m1, m2), "gmat3::scale(vec2)");

		m1.setIdentity();
		m1.scale(3, 4);
		assertTrue(gmat3EQ(m1, m2), "gmat3::scale(float, float)");

		m1.setIdentity();
		m1.scale(3);
		m2.setScale(3);
		assertTrue(gmat3EQ(m1, m2), "gmat3::scale(float)");
	}
	void testScale3D()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setScale3D(3, 4, 5);

		m1.scale3D(gvec3(3, 4, 5));
		assertTrue(gmat3EQ(m1, m2), "gmat3::scale3D(vec3)");

		m1.setIdentity();
		m1.scale3D(3, 4, 5);
		assertTrue(gmat3EQ(m1, m2), "gmat3::scale3D(float, float, float)");

		m1.setIdentity();
		m1.scale3D(3);
		m2.setScale3D(3);
		assertTrue(gmat3EQ(m1, m2), "gmat3::scale3D(float)");
	}
	void testRotate()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation(90);

		m1.rotate(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::rotate()");
	}
	void testRotate3D()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3D(gvec3(0, 1, 0), 90);

		m1.rotate3D(gvec3(0, 1, 0), 90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::rotate3D(vec3)");

		m1.setIdentity();
		m1.rotate3D(0, 1, 0, 90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::rotate3D(float, float, float, float)");
	}
	void testRotate3DX()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DX(90);

		m1.rotate3DX(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::rotate3DX()");
	}
	void testRotate3DY()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DY(90);

		m1.rotate3DY(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::rotate3DY()");
	}
	void testRotate3DZ()
	{
		gmat3 m1;
		gmat3 m2;
		m2.setRotation3DZ(90);

		m1.rotate3DZ(90);
		assertTrue(gmat3EQ(m1, m2), "gmat3::rotate3DZ()");
	}
	void testTranspose()
	{
		gmat3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
		gmat3 m2(1, 4, 7, 2, 5, 8, 3, 6, 9);

		m1.transpose();
		assertTrue(gmat3EQ(m1, m2), "gmat3::transpose()");
	}
	void testTransposed()
	{
		gmat3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
		gmat3 m2(1, 4, 7, 2, 5, 8, 3, 6, 9);
		
		assertTrue(gmat3EQ(m1.transposed(), m2), "gmat3::transpose()");
	}
	void testInverse()
	{
		gmat3 m1;
		gmat3 m2;

		m1.inverse();
		assertTrue(gmat3EQ(m1, m2), "gmat3::inverse()");
	}
	void testInversed()
	{
		gmat3 m1;
		gmat3 m2;

		assertTrue(gmat3EQ(m1.inversed(), m2), "gmat3::inversed()");
	}
	void testInverseRotation()
	{
		gmat3 m1;
		gmat3 m2;

		m1.inverseRotation();
		assertTrue(gmat3EQ(m1, m2), "gmat3::inverseRotation()");
	}
	void testInversedRotation()
	{
		gmat3 m1;
		gmat3 m2;

		assertTrue(gmat3EQ(m1.inversedRotation(), m2), "gmat3::inversedRotation()");
	}
	void testInverseRotation3D()
	{
		gmat3 m1;
		gmat3 m2;

		m1.inverseRotation3D();
		assertTrue(gmat3EQ(m1, m2), "gmat3::inverseRotation3D()");
	}
	void testInversedRotation3D()
	{
		gmat3 m1;
		gmat3 m2;

		assertTrue(gmat3EQ(m1.inversedRotation3D(), m2), "gmat3::inversedRotation3D()");
	}
	void testOrthoNormalize()
	{
		gmat3 m1;
		gmat3 m2;

		m1.orthoNormalize();
		assertTrue(gmat3EQ(m1, m2), "gmat3::orthoNormalize()");
	}
	void testOrthoNormalized()
	{		
		gmat3 m1;
		gmat3 m2;

		assertTrue(gmat3EQ(m1.orthoNormalized(), m2), "gmat3::orthoNormalized()");
	}
	void testMultiplication()
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2;

		assertTrue(gmat3EQ(m1*m2, m1), "gmat3::operator*(mat3)");

		m2 = gmat3(0, 2, 4, 6, 8, 10, 12, 14, 16);
		assertTrue(gmat3EQ(m1*2, m2), "gmat3::operator*(float)");

		gvec3 v(1, 2, 3);
		m2.setIdentity();
		assertTrue(vec3eqf(v, m2*v), "gmat3::operator*(vec3)");
	}
	void testAddition()
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(1, 2, 3, 4, 5, 6, 7, 8, 9);

		assertTrue(gmat3EQ(m1+m2, m3), "gmat3::operator+()");
	}
	void testSubstraction()
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(-1, 0, 1, 2, 3, 4, 5, 6, 7);

		assertTrue(gmat3EQ(m1 - m2, m3), "gmat3::operator-()");
	}
	void testMultiplicationAssign()
	{
		gmat3 m0(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m1;
		gmat3 m2;

		m1.set(m0);

		m1 *= m2;

		assertTrue(gmat3EQ(m1, m0), "gmat3::operator*=(mat3)");

		m1.set(m0);
		m2 = gmat3(0, 2, 4, 6, 8, 10, 12, 14, 16);
		m1 *= 2;
		assertTrue(gmat3EQ(m1, m2), "gmat3::operator*=(float)");
	}
	void testAdditionAssign()
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(1, 2, 3, 4, 5, 6, 7, 8, 9);

		m1 += m2;
		assertTrue(gmat3EQ(m1, m3), "gmat3::operator+=()");
	}
	void testSubstractionAssign()
	{
		gmat3 m1(0, 1, 2, 3, 4, 5, 6, 7, 8);
		gmat3 m2(1, 1, 1, 1, 1, 1, 1, 1, 1);
		gmat3 m3(-1, 0, 1, 2, 3, 4, 5, 6, 7);

		m1 -= m2;
		assertTrue(gmat3EQ(m1, m3), "gmat3::operator-()");
	}
}
