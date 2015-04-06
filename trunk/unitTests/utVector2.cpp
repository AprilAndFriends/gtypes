#include "generated/aprilUT.h"
#include "Vector2.h"

namespace testVector2
{
    void testAssignment()
    {
        gvec2 v(1, 2);
        assertTrue(v.x == 1 && v.y == 2, "gvec2::testAssignment - constructor assignment");
        v.set(2, 3);
        assertTrue(v.x == 2 && v.y == 3, "gvec2::testAssignment - set()");
    }

    void testAddition()
    {
        gvec2 v1(1, 2), v2(2, 3);
        gvec2 v3 = v1 + v2;
        assertTrue(v3.x == 3 && v3.y == 5, "gvec2::testAddition - set()");
    }
}
