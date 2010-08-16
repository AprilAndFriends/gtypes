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
#include <map>

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
        
        bool _inflexed;
        gtypes::Vector2 _prevNor;
        double _prevDot;
        
        std::vector<gtypes::Vector2> _points;
        std::vector<double> _lengths;
        
        std::map<double, int> _arcLengthMap;
        int _prevIndex;
        double _prevlen;
    
	public:
    
		CatmullRomSpline2();
        CatmullRomSpline2(std::vector<gtypes::Vector2> &vectors, int closed = 0);
        CatmullRomSpline2(std::list<gtypes::Vector2> &vectors, int closed = 0);
        CatmullRomSpline2(gtypes::Vector2 *vectors, int n, int closed = 0);
		~CatmullRomSpline2();
        
        gtypes::Vector2 calcPosition(double t);
        gtypes::Vector2 calcTangent(double t);
        gtypes::Vector2 calcNormal(double t);
        
        gtypes::Vector2 getTangent();
        gtypes::Vector2 getNormal();
        
        void addPoint(gtypes::Vector2 point);
        void addPoint(double x, double y);
        
        void compile(std::vector<gtypes::Vector2> &vectors, int closed = 0,
                        gtypes::Vector2 startingTangent = gtypes::Vector2(0,0),
                        gtypes::Vector2 endingTangent = gtypes::Vector2(0,0) );
        void compile(std::list<gtypes::Vector2> &vectors, int closed = 0, 
                        gtypes::Vector2 startingTangent = gtypes::Vector2(0,0),
                        gtypes::Vector2 endingTangent = gtypes::Vector2(0,0) );
        void compile(gtypes::Vector2 *vectors, int n, int closed = 0,
                        gtypes::Vector2 startingTangent = gtypes::Vector2(0,0),
                        gtypes::Vector2 endingTangent = gtypes::Vector2(0,0) );
        
        void setLengthSamplingRate(int r);
        void setCurvature(double c);
        
        double getLength();
        
    //private:
    public:
    
		double _calcLength();
        double _calcSegmentLength(int index);
        gtypes::Vector2 _calcSegmentPosition(double t, int index);
        gtypes::Vector2 _calcSegmentTangent(double t, int index);
        gtypes::Vector2 _calcSegmentNormal(double t, int index);
        void _arcLengthReparametrization();
	};

}

#ifdef GTYPES_ABREV

typedef gtypes::CatmullRomSpline2 gcrs2;

#endif

#endif // GTYPES_SPLINE2_H
