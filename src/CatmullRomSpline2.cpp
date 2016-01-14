/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include <math.h>
#include <stdio.h>

#include "CatmullRomSpline2.h"
#include "gtypesUtil.h"
#include "Vector2.h"

namespace gtypes
{
	CatmullRomSpline2::CatmullRomSpline2() :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevIndex(-1), _prevLength(0.0)
	{
	}

	CatmullRomSpline2::CatmullRomSpline2(const std::vector<Vector2>& vectors, bool closed, double curvature, int samples, Vector2 t1, Vector2 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevIndex(-1), _prevLength(0.0)
	{
		this->set(vectors, closed, curvature, samples, t1, t2);
	}

	CatmullRomSpline2::CatmullRomSpline2(const Vector2 vectors[], int n, bool closed, double curvature, int samples, Vector2 t1, Vector2 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevIndex(-1), _prevLength(0.0)
	{
		this->set(vectors, n, closed, curvature, samples, t1, t2);
	}
}
