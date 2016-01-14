/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include <math.h>
#include <stdio.h>

#include "CatmullRomSpline3.h"
#include "gtypesUtil.h"
#include "Vector3.h"

namespace gtypes
{
	CatmullRomSpline3::CatmullRomSpline3() :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevIndex(-1), _prevLength(0.0), _prevDot(0), _inflexed(false)
	{
	}

	CatmullRomSpline3::CatmullRomSpline3(const std::vector<Vector3>& vectors, bool closed, double curvature, int samples, Vector3 t1, Vector3 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevIndex(-1), _prevLength(0.0), _prevDot(0), _inflexed(false)
	{
		this->set(vectors, closed, curvature, samples, t1, t2);
	}

	CatmullRomSpline3::CatmullRomSpline3(const Vector3 vectors[], int n, bool closed, double curvature, int samples, Vector3 t1, Vector3 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevIndex(-1), _prevLength(0.0), _prevDot(0), _inflexed(false)
	{
		this->set(vectors, n, closed, curvature, samples, t1, t2);
	}
}
