/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_SPLINE2_H
#define GTYPES_SPLINE2_H

#include "gtypesExport.h"

#include "Vector2.h"
#include <math.h>
#include <vector>
#include <list>

namespace gtypes
{

	class gtypesExport CatmullRomSpline2
	{
        
    // private:
    public:
        int _numSamples;
        int _numSegments;
        int _closed;
        double _length;
		double _c;
        
        std::vector<gtypes::Vector2> _points;
        std::vector<double> _lengths;
    
	public:
    
		CatmullRomSpline2();
        CatmullRomSpline2(std::vector<gtypes::Vector2> &vectors, int closed = 0);
        CatmullRomSpline2(std::list<gtypes::Vector2> &vectors, int closed = 0);
        CatmullRomSpline2(gtypes::Vector2 *vectors, int n, int closed = 0);
		~CatmullRomSpline2();
        
        gtypes::Vector2 calcPosition(double t);
        gtypes::Vector2 calcTangent(double t);
        gtypes::Vector2 calcNormal(double t);
        
        void closeSpline();
        
        void addPoint(gtypes::Vector2 point);
        void addPoint(double x, double y);
        
        void subdivide(int numSubdivisions);
        void resample(int numSamples);
        
        void rebuild(std::vector<gtypes::Vector2> &vectors, int closed = 0);
        void rebuild(std::list<gtypes::Vector2> &vectors, int closed = 0);
        void rebuild(gtypes::Vector2 *vectors, int n, int closed = 0);
        
        void setLengthSamplingRate(int r);
        void setCurvature(double c);
        void setStartingTangent(gtypes::Vector2 tangent);
        void setEndingTangent(gtypes::Vector2 tangent);
        
        double getLength();
        
    //private:
    public:
    
		double _calcLength();
        double _calcSegmentLength(int index);
        gtypes::Vector2 _calcSegmentPosition(double t, int index);
        gtypes::Vector2 _calcSegmentTangent(double t, int index);
        gtypes::Vector2 _calcSegmentNormal(double t, int index);
        void _resample(int quality);
        gtypes::Vector2 _resampledPos(double t);
	};

}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::CatmullRomSpline2 crs2;
}
#endif

#endif // GTYPES_SPLINE2_H
