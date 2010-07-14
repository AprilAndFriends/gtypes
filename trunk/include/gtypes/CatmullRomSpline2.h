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
        double _length;
		double _c;
        
        int _closed;
        
        struct Segment {
            
            // segment of a Catmull-Rom spline

            gtypes::Vector2 v0;
            gtypes::Vector2 v1;
            gtypes::Vector2 v2;
            gtypes::Vector2 v3;
            
            double length;
        };
        
        std::vector<Segment> _segments;
        std::vector<gtypes::Vector2> _originalPoints;
    
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
        
        void addPoint(gtypes::Vector2 point, int remember = 1);
        void addPoint(float x, float y, int remember = 1);
        
        void rebuild(std::vector<gtypes::Vector2> &vectors, int remember = 1, int closed = 0);
        void rebuild(std::list<gtypes::Vector2> &vectors, int remember = 1, int closed = 0);
        void rebuild(gtypes::Vector2 *vectors, int n, int remember = 1, int closed = 0);
        
        void resample(int n, int fromOriginal = 1);
        
        void setLengthSamplingRate(int r);
        void setCurvature(double c);
        
        
        
    private:
    
        double _calculateSegmentLength(Segment &segment);
        double _calculateLength();
        
    public: // only here temporary
        gtypes::Vector2 _calculateSegmentPosition(float t, Segment &segment);

	};

}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::CatmullRomSpline2 crs2;
}
#endif

#endif // GTYPES_SPLINE2_H
