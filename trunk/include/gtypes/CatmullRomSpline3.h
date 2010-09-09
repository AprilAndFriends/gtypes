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
#include <map>

namespace gtypes
{

	class gtypesExport CatmullRomSpline3
	{
        
    // private:
    public:
        int _numSamples;
        int _numSegments;
        int _closed;
        double _length;
		double _c;
        
        bool _inflexed;
        gtypes::Vector3 _prevNor;
        double _prevDot;
        
        std::vector<gtypes::Vector3> _points;
        std::vector<double> _lengths;
        
        std::map<double, int> _arcLengthMap;
        int _prevIndex;
        double _prevlen;
    
	public:
    
		CatmullRomSpline3();
        CatmullRomSpline3(std::vector<gtypes::Vector3> &vectors, int closed = 0, gtypes::Vector3 t1 = gtypes::Vector3(0,0,0), gtypes::Vector3 t2 = gtypes::Vector3(0,0,0) );
        CatmullRomSpline3(std::list<gtypes::Vector3> &vectors, int closed = 0, gtypes::Vector3 t1 = gtypes::Vector3(0,0,0), gtypes::Vector3 t2 = gtypes::Vector3(0,0,0));
        CatmullRomSpline3(gtypes::Vector3 *vectors, int n, int closed = 0, gtypes::Vector3 t1 = gtypes::Vector3(0,0,0),  gtypes::Vector3 t2 = gtypes::Vector3(0,0,0));
		~CatmullRomSpline3();
        
        gtypes::Vector3 calcPosition(double t);
        gtypes::Vector3 calcTangent(double t);
        gtypes::Vector3 calcNormal(double t);
        
        gtypes::Vector3 getTangent();
        gtypes::Vector3 getNormal();
        
        void addPoint(gtypes::Vector3 point);
        void addPoint(double x, double y, double z);
        
        void compile(std::vector<gtypes::Vector3> &vectors, int closed = 0,
                        gtypes::Vector3 startingTangent = gtypes::Vector3(0,0,0),
                        gtypes::Vector3 endingTangent = gtypes::Vector3(0,0,0) );
        void compile(std::list<gtypes::Vector3> &vectors, int closed = 0, 
                        gtypes::Vector3 startingTangent = gtypes::Vector3(0,0,0),
                        gtypes::Vector3 endingTangent = gtypes::Vector3(0,0,0) );
        void compile(gtypes::Vector3 *vectors, int n, int closed = 0,
                        gtypes::Vector3 startingTangent = gtypes::Vector3(0,0,0),
                        gtypes::Vector3 endingTangent = gtypes::Vector3(0,0,0) );
        
        void setLengthSamplingRate(int r);
        void setCurvature(double c);
        
        double getLength();
        
    //private:
    public:
    
		double _calcLength();
        double _calcSegmentLength(int index);
        gtypes::Vector3 _calcSegmentPosition(double t, int index);
        gtypes::Vector3 _calcSegmentTangent(double t, int index);
        gtypes::Vector3 _calcSegmentNormal(double t, int index);
        void _arcLengthReparametrization();
	};

}

typedef gtypes::CatmullRomSpline3 gcrs3;

#endif // GTYPES_SPLINE3_H
