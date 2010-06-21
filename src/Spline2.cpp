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
        _curvature = 1.0;
		
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
			gtypes::Vector2 vec = (_segments[_numSegments-1].v2 - _segments[_numSegments-1].v1).normalised();
            seg.v1 = seg.v0 + vec * _curvature;
            
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
		
		double newT = t * _numSegments;
		double l = _segments[int(newT)].lenght;
		gtypes::Vector2 vec = _splineSegmentPosition(newT - int(newT) , _segments[int(newT)]);
		return vec;
	}
	
	gtypes::Vector2 Spline2::getTangent(double t)
	{
		gtypes::Vector2 tangent;
		
		double newT = t * _numSegments;
		int seg = int(newT);
		double l = _segments[seg].lenght;
		newT = newT - seg;
	
		tangent.x = 2 * ((_segments[seg].v1.x - _segments[seg].v0.x) * (1.0 - newT) + (_segments[seg].v2.x - _segments[seg].v1.x) * newT);
		tangent.y = 2 * ((_segments[seg].v1.y - _segments[seg].v0.y) * (1.0 - newT) + (_segments[seg].v2.y - _segments[seg].v1.y) * newT);
		
		tangent.normalise();
		
		return tangent;
	}
	
	void Spline2::setCurvature(double c)
	{
		_curvature = c;
	}

}

