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

namespace gtypes
{

    CatmullRomSpline2::CatmullRomSpline2() : _lenght(0.0), _numSegments(0), _curvature(0.3), _numSamples(10)
    {
        Segment seg;
        seg.v0 = seg.v1 = seg.v2 = seg.v3 = gtypes::Vector2(0.0, 0.0);
        _segments.push_back(seg);
    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::vector<gtypes::Vector2> &vectors, int closed) : _lenght(0.0), _numSegments(0)
    {

    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::list<gtypes::Vector2> &vectors, int closed) : _lenght(0.0), _numSegments(0)
    {

    }
        
    CatmullRomSpline2::~CatmullRomSpline2()
    {
        
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
            _segments[0].v2 = _segments[0].v3 = point;
            ++_numSegments;

            _calculateLenght();
        }
        else
        {
           Segment seg;
           
           seg.v0 = _segments[_numSegments - 1].v1;
           seg.v1 = _segments[_numSegments - 1].v2;
           
           _segments[_numSegments - 1].v3 = point;
           
           seg.v2 = seg.v3 = point;
           _segments.push_back(seg);
           ++_numSegments;
           
           _calculateLenght();
        }
    }
    
    gtypes::Vector2 CatmullRomSpline2::_calculateSegmentPosition(float t, Segment &seg)
    {
        gtypes::Vector2 vec;
        
        float t2 = t*t;
        float t3 = t*t*t;
        
        vec = ( ( -seg.v0 + seg.v1*3 - seg.v2*3 + seg.v3 ) * t3 +
                ( seg.v0*2 - seg.v1*5 + seg.v2*4- seg.v3 ) * t2 +
                ( -seg.v0 + seg.v2 ) * t +
                ( seg.v1*2 ) ) * 0.5;
        
        return vec;
        
    }
    
    gtypes::Vector2 CatmullRomSpline2::calcPosition(float t)
    {
        float prevLen = 0.0, len = _segments[0].lenght, l = t * _lenght;
        int i = 0;
        
        for(i = 1; i < _numSegments; ++i)
        {
            prevLen += _segments[i-1].lenght;
            len += _segments[i].lenght;
            if(len >= l)
                break;
        }
        
        float newt = (l - prevLen) / _segments[i].lenght;
        return _calculateSegmentPosition(newt, _segments[i]);
    }
    
    float CatmullRomSpline2::_calculateSegmentLenght(Segment &seg)
    {
        seg.lenght = 0.0;
        
        for(int i = 1; i <= _numSamples; ++i)
        {
            seg.lenght += (_calculateSegmentPosition((float)i/_numSamples, seg) - _calculateSegmentPosition((float)(i-1)/_numSamples, seg)).length();
        }
        
        return seg.lenght;
    }
    
    float CatmullRomSpline2::_calculateLenght()
    {
        
        _lenght = 0.0;
        for(int i = 0; i < _numSegments; ++i)
            _lenght += _calculateSegmentLenght(_segments[i]);
            
        return _lenght;
    }
    
    void CatmullRomSpline2::setCurvature(float c)
    {
        _curvature = c;
    }
    
    void CatmullRomSpline2::setSamplingRate(int r)
    {
        _numSamples = r;
    }


}

