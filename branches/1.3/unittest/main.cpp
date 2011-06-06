/// @file
/// @author  Kresimir Spes
/// @version 1.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#ifdef _WIN32
#include <UnitTest++.h>
#else
#include <unittest++/UnitTest++.h>	
#endif
#include "gtypes/Vector3.h"
#include <math.h> 

#include <vector>
#include <iostream>

#include <stdio.h>

TEST(SimpleVectorTest)
{
    
	gvec3 v(1,2,3);
	CHECK(fabs(v.length() - sqrt(1*1+2*2+3*3)) < 0.001);
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
