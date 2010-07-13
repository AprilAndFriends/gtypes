/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "CatmullRomSpline2.h"

#include <iostream>

namespace gtypes
{

    CatmullRomSpline2::CatmullRomSpline2()
    {
        Segment seg;
        seg.v0 = seg.v1 = seg.v2 = seg.v3 = gtypes::Vector2(0.0, 0.0);
        _segments.push_back(seg);
        _c = 1.0;
        _length = 0.0;
        _numSegments = 0;
        
    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::vector<gtypes::Vector2> &vectors, int closed)
    {
        
    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::list<gtypes::Vector2> &vectors, int closed)
    {
    
    }
        
    CatmullRomSpline2::~CatmullRomSpline2()
    {
        
    }
    
    void CatmullRomSpline2::closeSpline()
    {
        Segment seg;
        seg.v3 = _segments[0].v2;
        seg.v2 = _segments[0].v1;
        seg.v0 = _segments[_numSegments - 1].v1;
        seg.v1 = _segments[_numSegments - 1].v2;
        
        _segments[0].v0 = _segments[_numSegments - 1].v2;
        _segments[_numSegments - 1].v3 = _segments[0].v1;
        
        _segments.push_back(seg);
        
        ++_numSegments;
        
        _calculateLength();
    }
    
    void CatmullRomSpline2::addPoint(float x, float y)
    {
        addPoint(gtypes::Vector2(x,y));
    }
    
    void CatmullRomSpline2::setOrigin(float x, float y)
    {
        setOrigin(gtypes::Vector2(x,y));
    }
    
    void CatmullRomSpline2::setOrigin(gtypes::Vector2 vec)
    {
        _segments[0].v0 = _segments[0].v1 = vec;
    }
    
    void CatmullRomSpline2::addPoint(gtypes::Vector2 point)
    {
        if(_numSegments == 0)
        {
            _segments[0].v2 = point;
            //_segments[0].v0 = (_segments[0].v1 - (_segments[0].v2 - _segments[0].v1));
            //_segments[0].v3 = _segments[0].v2 + (_segments[0].v2 - _segments[0].v1);
            _segments[0].v0 = _segments[0].v1;
            _segments[0].v3 = point;
            ++_numSegments;


            _calculateLength();
        }
        else
        {
           Segment seg;
           
           seg.v0 = (_segments[_numSegments - 1].v1);
           seg.v1 = _segments[_numSegments - 1].v2;
           
           _segments[_numSegments - 1].v3 = point;
           
           seg.v2 = point;
           //seg.v3 = seg.v2 + (seg.v2 - seg.v1);
           seg.v3 = point;
           _segments.push_back(seg);
           ++_numSegments;
           
           _calculateLength();
        }
    }
    
    gtypes::Vector2 CatmullRomSpline2::_calculateSegmentPosition(float t, Segment &seg)
    {
        gtypes::Vector2 vec;
        
        double t2 = t*t;
        double t3 = t2*t;
        
        vec = seg.v0 * (-t*_c + t2*2.0*_c - t3*_c) +
              seg.v1 * (1.0 + t2*(_c-3.0) + t3*(2.0-_c)  ) +
              seg.v2 * ( t*_c + t2*(3.0-2.0*_c) + t3*(_c-2.0) ) +
              seg.v3 * ( t3*_c - t2*_c);

        return vec;
        
    }
    
    gtypes::Vector2 CatmullRomSpline2::calcPosition(double t)
    {
        double prevLen = 0.0, len = _segments[0].length, l = t * _length;
        int i;
        
        for(i = 1; i <= _numSegments; ++i)
        {
            prevLen += _segments[i-1].length;
            len += _segments[i].length;
            if(len > l)
                break;
        }
        
        if(l <= _segments[0].length)
        {
            i = 0;
            prevLen = 0.0;
        }
        
        double newt = (l - prevLen) / _segments[i].length;
        return _calculateSegmentPosition(newt, _segments[i]);
    }
    
    double CatmullRomSpline2::_calculateSegmentLength(Segment &seg)
    {
        seg.length = 0.0;
        
        for(int i = 1; i <= _numSamples; ++i)
        {
            seg.length += (_calculateSegmentPosition((double)i/_numSamples, seg) - _calculateSegmentPosition((double)(i-1)/_numSamples, seg)).length();
        }
        
        return seg.length;
    }
    
    double CatmullRomSpline2::_calculateLength()
    {
        
        _length = 0.0;
        for(int i = 0; i < _numSegments; ++i)
            _length += _calculateSegmentLength(_segments[i]);
            
        return _length;
    }
    
    void CatmullRomSpline2::setCurvature(double c)
    {
        _c = c;
    }
    
    void CatmullRomSpline2::setSamplingRate(int r)
    {
        _numSamples = r;
    }
    
    void CatmullRomSpline2::rebuildSpline(int n) {
        std::vector<gtypes::Vector2> points;
        double step = (1.0 / n);
        for(double t = 0; t < 1.0; t += step)
        {
            points.push_back(calcPosition(t));
        }
        _numSegments = 0;
        _segments.clear();
        Segment seg;
        seg.v0 = seg.v1 = seg.v2 = seg.v3 = points[0];
        _segments.push_back(seg);
        for(int i = 1; i < points.size(); ++i)
        {
            addPoint(points[i]);
        }
        
    }


}

