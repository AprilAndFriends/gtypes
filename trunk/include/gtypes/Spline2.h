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

namespace gtypes
{

	class gtypesExport Spline2
	{
        
    public:
        
        int _numSegments;
        int _numSamples;
        double _lenght;
		double _curvature;
        
        struct Segment {
            
            // segment of a bernsteine spline of second degree

            gtypes::Vector2 v0;
            gtypes::Vector2 v1;
            gtypes::Vector2 v2;
            
            double weights[3];
            
            double lenght;
        };
        
        std::vector<Segment> _segments;
    
	public:
		Spline2();
		~Spline2();
        
        void setOrigin(gtypes::Vector2 origin); // sets the origin of a spline
        void setOrigin(double x, double y); // sets the origin of a spline
        void setSamplingRate(int i);
		void setCurvature(double c);
        
        void addSegment(gtypes::Vector2 vertex); // ads a segment to a spline
        void addSegment(double x, double y); // ads a segment to a spline
        void removeSegment(int index); // removes a segment of a spline
        void popSegment(); // removes a last segment of a spline
        
        const std::vector<gtypes::Vector2> &getVertices();
        double getLenght();
        double lenght();
        
        gtypes::Vector2 getTangent(double t);
        gtypes::Vector2 tangent(double t) { return getTangent(t); }
        
        gtypes::Vector2 getPosition(double t);
        gtypes::Vector2 getOrigin();
        gtypes::Vector2 getEnd();
        
        void reset();
        
        
    //private:
    public:
    
        double _calculateSegmentLenght(Segment &segment);
        double _calculateLenght();
        gtypes::Vector2 _splineSegmentPosition(double t, Segment &segment);
        
        

	};

}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::Spline2 sp2;
}
#endif

#endif // GTYPES_SPLINE2_H
