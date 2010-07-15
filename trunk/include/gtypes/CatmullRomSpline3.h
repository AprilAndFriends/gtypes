/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_SPLINE3_H
#define GTYPES_SPLINE3_H

#include "gtypesExport.h"

#include "Vector3.h"
#include <math.h>
#include <vector>
#include <list>

namespace gtypes
{

	class gtypesExport CatmullRomSpline3
	{
	// private:
    public:
        int _numSamples;
        int _numSegments;
        double _length;
		double _c;
        
        int _closed;
        int _resampled;
        
        struct Segment {
            
            // segment of a Catmull-Rom spline

            gtypes::Vector3 v0;
            gtypes::Vector3 v1;
            gtypes::Vector3 v2;
            gtypes::Vector3 v3;
            
            double length;
        };
        
        std::vector<Segment> _segments;
        std::vector<gtypes::Vector3> _originalPoints;
    
	public:
    
		CatmullRomSpline3();
        CatmullRomSpline3(std::vector<gtypes::Vector3> &vectors, int closed = 0);
        CatmullRomSpline3(std::list<gtypes::Vector3> &vectors, int closed = 0);
        CatmullRomSpline3(gtypes::Vector3 *vectors, int n, int closed = 0);
		~CatmullRomSpline3();
        
        gtypes::Vector3 calcPosition(double t);
        gtypes::Vector3 calcTangent(double t);
        gtypes::Vector3 calcNormal(double t, const gtypes::Vector3 &upVector);
        
        void closeSpline();
        
        void addPoint(gtypes::Vector3 point, int remember = 1);
        void addPoint(double x, double y, double z, int remember = 1);
        
        void rebuild(std::vector<gtypes::Vector3> &vectors, int remember = 1, int closed = 0);
        void rebuild(std::list<gtypes::Vector3> &vectors, int remember = 1, int closed = 0);
        void rebuild(gtypes::Vector3 *vectors, int n, int remember = 1, int closed = 0);
        
        void resample(int n, int fromOriginal = 1);
        
        void setLengthSamplingRate(int r);
        void setCurvature(double c);
        
        
        
    private:
    
        double _calculateSegmentLength(Segment &segment);
        double _calculateLength();
        
    public: // only here temporary
        gtypes::Vector3 _calculateSegmentPosition(float t, Segment &segment);
	};

}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::CatmullRomSpline3 crs3;
}
#endif

#endif // GTYPES_SPLINE3_H
