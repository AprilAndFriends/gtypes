/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
/*#ifdef _WIN32
#include <UnitTest++.h>
#else
#include <unittest++/UnitTest++.h>	
#endif
#include "gtypes/Vector3.h"
#include <math.h> */

#include <vector>
#include <iostream>

#include <stdio.h>

#include "gtypes/Spline2.h"

/*TEST(SimpleVectorTest)
{
	gt::vec3 v(1,2,3);
	CHECK(fabs(v.length() - sqrt(1*1+2*2+3*3)) < 0.001);
}*/

int main(int argc, char **argv)
{

    gtypes::Spline2 splajn;
    splajn.setOrigin(0.0, 0.0);
    std::cerr << splajn.lenght() << std::endl;
    splajn.addSegment(1.0, 2.0);
    std::cerr << splajn.lenght() << std::endl;
    splajn.addSegment(3.7, -6.2);
    std::cerr << splajn.lenght() << std::endl;
    splajn.addSegment(10.0, 3.17);
    std::cerr << splajn.lenght() << std::endl;
    
    std::cerr << splajn._numSegments << std::endl;
    
   for(int i = 0; i < 100; i++)
   {
       std::cout << "x_" << splajn.getPosition((float)i * 0.01).x <<
                    "y_" << splajn.getPosition((float)i * 0.01).y << std::endl;
   }
    
    return 0;
    //return UnitTest::RunAllTests();
}
