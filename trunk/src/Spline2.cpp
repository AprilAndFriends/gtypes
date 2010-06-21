/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "Spline2.h"

namespace gtypes
{

    Spline2::Spline2() : _lenght(0.0), _numSegments(0)
    {
        _segments.clear();
        
        Segment seg;
        seg.v0 = seg.v1 = seg.v2 = gtypes::Vector2(0.0, 0.0);
        seg.lenght = 0.0;
        _segments.push_back(seg);
        
        _numSamples = 10; // default number  of segments used for lenght calculations
    }
        
    Spline2::~Spline2()
    {
    }
    
    void Spline2::setSamplingRate(int i)
    {
        _numSamples = i;
    }
    
    void Spline2::addSegment(double x, double y)
    {
        addSegment(gtypes::Vector2(x,y));
    }
    
    void Spline2::addSegment(gtypes::Vector2 vertex)
    {
        if(_numSegments == 0)
        {
            _segments[0].v2 = vertex;
            _segments[0].v1 = ((vertex + _segments[0].v0) * 0.5);
            
            _lenght = _calculateLenght();
            
            ++_numSegments;
            
        }
        else
        {
            Segment seg;
            seg.v0 = _segments[_numSegments-1].v2;
            seg.v2 = vertex;
            seg.v1 = seg.v0 + (_segments[_numSegments-1].v2 - _segments[_numSegments-1].v1);
            
            _segments.push_back(seg);
			++_numSegments;
            
            _lenght = _calculateLenght();
        }
    }
    
    void Spline2::setOrigin(double x, double y)
    {
        setOrigin(gtypes::Vector2(x,y));
    }
    
    void Spline2::setOrigin(gtypes::Vector2 origin)
    {
        _segments[0].v0 = origin;
        _segments[0].v1 = ((origin + _segments[0].v2) * 0.5);
        
        _lenght = _calculateLenght();
    }
    
    double Spline2::getLenght()
    {
        return _lenght;
    }
    
    double Spline2::lenght()
    {
        return _lenght;
    }
    
    double Spline2::_calculateSegmentLenght(Segment &segment)
    {
        segment.lenght = 0.0;
        for(int i = 1; i < _numSamples; ++i)
        {
            gtypes::Vector2 vec1, vec2, result;
            vec1 = _splineSegmentPosition( (float)(i - 1) / _numSamples, segment);
            vec2 = _splineSegmentPosition( (float)i / _numSamples, segment);
            result = vec2 - vec1;
            segment.lenght += result.length();
        }
        
        return segment.lenght;
    }
    
    double Spline2::_calculateLenght()
    {
        double _lenght = 0;
        for(int i = 0; i < _segments.size(); ++i)
          _lenght += _calculateSegmentLenght(_segments[i]);  
        return _lenght;
    }
    
    gtypes::Vector2 Spline2::_splineSegmentPosition(double t, Segment &seg)
    {
        double t2 = t*t;
        gtypes::Vector2 vec;
        
        vec.x = t2*(seg.v0.x - 2*seg.v1.x + seg.v2.x) + t*(2*seg.v1.x - 2*seg.v0.x) + seg.v0.x;
        vec.y = t2*(seg.v0.y - 2*seg.v1.y + seg.v2.y) + t*(2*seg.v1.y - 2*seg.v0.y) + seg.v0.y;
        
        return vec;
    }
    
    gtypes::Vector2 Spline2::getPosition(double t)
    {
        // if we have only one segment then the vertex lies in it
        if(_numSegments == 1)
        {
            return _splineSegmentPosition(t, _segments[0]);
        }
        
        // NOTE! 
        // this piece of code does not return precise coordinates 
        // because unlinear mapping of the interpolant is not implemented yet !

        // first, we find in what segment our vertex lies
        int i;
        double seg, segprev;
        for(seg = 0, i = 0; seg <= t * _lenght; seg += _segments[i].lenght, i++);
        // then, we must find the position of an interpolant
        segprev = seg - _segments[i].lenght;
        double newT = ((t * _lenght) - segprev) / (seg - segprev);
        gtypes::Vector2 vec = _splineSegmentPosition(newT, _segments[i]);
        // and thus return it
        return vec;
    }

}

