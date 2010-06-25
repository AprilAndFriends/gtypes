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
        int _numSegments;
        int _numSamples;
        float _lenght;
		float _curvature;
        
        int _closed;
        
        struct Segment {
            
            // segment of a Catmull-Rom spline

            gtypes::Vector2 v0;
            gtypes::Vector2 v1;
            gtypes::Vector2 v2;
            gtypes::Vector2 v3;
            
            double lenght;
        };
        
        std::vector<Segment> _segments;
    
	public:
    
		CatmullRomSpline2();
        CatmullRomSpline2(std::vector<gtypes::Vector2> &vectors, int closed = 0);
        CatmullRomSpline2(std::list<gtypes::Vector2> &vectors, int closed = 0);
		~CatmullRomSpline2();
        
        gtypes::Vector2 calcPosition(float t);
        gtypes::Vector2 calcTangent(float t);
        gtypes::Vector2 calcNormal(float t);
        
        void closeSpline();
        
        void setOrigin(float x, float y);
        void setOrigin(gtypes::Vector2 vec);
        
        void addPoint(gtypes::Vector2 point);
        void addPoint(float x, float y);
        
        void rebuild(std::vector<gtypes::Vector2> &vectors, int closed = 0);
        void rebuild(std::list<gtypes::Vector2> &vectors, int closed = 0);
        
        void setSamplingRate(int r);
        void setCurvature(float c);
        
        
        
    //private:
    public:
    
        float _calculateSegmentLenght(Segment &segment);
        float _calculateLenght();
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
