/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include "CatmullRomSpline3.h"


#include <iostream>

namespace gtypes
{

    CatmullRomSpline3::CatmullRomSpline3() : _c(0.5), _length(0.0), _closed(0), _numSegments(0), _resampled(0)
    {
        
    }
    
    CatmullRomSpline3::CatmullRomSpline3(std::vector<gtypes::Vector3> &vectors, int closed) : _closed(closed), _resampled(0)
    {
        for(int i = 0; i < vectors.size(); ++i)
        {
            addPoint(vectors[i]);
        }
    }
    
    CatmullRomSpline3::CatmullRomSpline3(std::list<gtypes::Vector3> &vectors, int closed) : _closed(closed), _resampled(0)
    {
        for(std::list<gtypes::Vector3>::iterator it = vectors.begin(); it != vectors.end(); it++)
        {
            addPoint(*it);
        }
    }
    
    CatmullRomSpline3::CatmullRomSpline3(gtypes::Vector3 *vectors, int n, int closed) : _closed(closed), _resampled(0)
    {
        for(int i = 0; i < n; ++i)
        {
            addPoint(vectors[i]);
        }
    
    }
        
    CatmullRomSpline3::~CatmullRomSpline3()
    {
        
    }
    
    void CatmullRomSpline3::closeSpline()
    {
        Segment seg;
        seg.v0 = _segments[_segments.size()-1].v1;
        seg.v1 = _segments[_segments.size()-1].v2;
        seg.v2 = _segments[0].v1;
        seg.v3 = _segments[0].v2;
        
        _segments[0].v0 = seg.v1;
        _segments[_segments.size() - 1].v3 = seg.v2;
        _segments[_segments.size() - 1].v2 = seg.v1;
        
        _segments.push_back(seg);
        _numSegments;
        
        _closed = 1;
        
        _calculateLength();
    }
    
    void CatmullRomSpline3::addPoint(double x, double y, double z, int remember)
    {
        addPoint(gtypes::Vector3(x,y,z), remember);
    }
    
    void CatmullRomSpline3::addPoint(gtypes::Vector3 point, int remember)
    {
        if(remember)
        {
            _originalPoints.push_back(point);
        }
        if(_segments.size() == 0)
        {
            Segment seg;
            seg.v0 = seg.v1 = seg.v2 = seg.v3 = point;
            _segments.push_back(seg);
            _numSegments = 1;
        }
        else if(_numSegments == 1)
        {
            _segments[0].v2 = _segments[0].v3 = point;
            _numSegments++;
        }
        else
        {
            Segment seg;
            _segments[_segments.size()-1].v3 = seg.v3 = point;
            seg.v0 = _segments[_segments.size()-1].v1;
            seg.v1 = _segments[_segments.size()-1].v2;
            seg.v2 = _segments[_segments.size()-1].v3;
            
            _segments.push_back(seg);
            _numSegments++;
        }
        _calculateLength();
    }
    
    gtypes::Vector3 CatmullRomSpline3::_calculateSegmentPosition(float t, Segment &seg)
    {
        gtypes::Vector3 vec;
        
        double t2 = t*t;
        double t3 = t2*t;
        
        vec = seg.v0 * (-t*_c + t2*2.0*_c - t3*_c) +
              seg.v1 * (1.0 + t2*(_c-3.0) + t3*(2.0-_c)  ) +
              seg.v2 * ( t*_c + t2*(3.0-2.0*_c) + t3*(_c-2.0) ) +
              seg.v3 * ( t3*_c - t2*_c);

        return vec;
        
    }
    
    gtypes::Vector3 CatmullRomSpline3::calcPosition(double t)
    {
        if(t >= 1.0)
            t -= (int)t;
        else if(t < 0.0)
            t += (int)t;
            
        double prevLen = 0.0, len = _segments[0].length, l = t * _length;
        int i;
        
        for(i = 1; i < _segments.size(); ++i)
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
        if(newt >= 1.0)
        {
            newt -= (int)newt;
            ++i;
            if(i >= _segments.size())
            {
                i = 0;
            }
        }
        else if(newt < 0.0)
        {
            newt += (int)newt;
            --i;
            if(i < 0)
                i = _segments.size();
        }
        return _calculateSegmentPosition(newt, _segments[i]);
    }
    
    gtypes::Vector3 CatmullRomSpline3::calcTangent(double t)
    {
        gtypes::Vector3 tangent;
        tangent = (calcPosition(t + 0.01f) - calcPosition(t));
        tangent.normalise();
        return tangent;
    }
    
    gtypes::Vector3 CatmullRomSpline3::calcNormal(double t, const gtypes::Vector3 &upVector)
    {
        gtypes::Vector3 normal;
        normal.cross(calcTangent(t), upVector);
        normal.normalise();
       // normal.cross(calcTangent(t));
       // normal.normalise();
        return normal;
    }
    
    double CatmullRomSpline3::_calculateSegmentLength(Segment &seg)
    {
        seg.length = 0.0;
        
        for(int i = 1; i < _segments.size(); ++i)
        {
            seg.length += (_calculateSegmentPosition((double)i/_segments.size(), seg) - 
                           _calculateSegmentPosition((double)(i-1)/_segments.size(), seg)).length();
        }
        
        return seg.length;
    }
    
    double CatmullRomSpline3::_calculateLength()
    {
        
        _length = 0.0;
        for(int i = 0; i < _segments.size(); ++i)
            _length += _calculateSegmentLength(_segments[i]);
            
        return _length;
    }
    
    void CatmullRomSpline3::setCurvature(double c)
    {
        _c = c;
    }
    
    void CatmullRomSpline3::setLengthSamplingRate(int r)
    {
        _numSamples = r;
    }
    
    void CatmullRomSpline3::resample(int n, int fromOriginal) {
        std::vector<gtypes::Vector3> points;
        if(n < 1)
        {
            n = 1;
        }
        if(fromOriginal)
        {
            _segments.clear();
            _numSegments = 0;
            for(int i = 0; i < _originalPoints.size(); ++i)
            {
                addPoint(_originalPoints[i], 0);
            }
            if(_closed)
            {
                closeSpline();
            }
        }
        for(int i = 0; i <n; ++i)
        {
            points.push_back(calcPosition((double)i/n));
        }
        _segments.clear();
        _numSegments = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            addPoint(points[i], 0);
        }
        
        if(_closed)
        {
            closeSpline();
        }
        
    }
    
    void CatmullRomSpline3::rebuild(gtypes::Vector3 *vectors, int n, int remember, int closed)
    {
        int r = 0;
        if(remember)
        {
            _originalPoints.clear();
            r = 1;
        }
        _segments.clear();
        for(int i = 0; i < n; ++i)
        {
            addPoint(vectors[i], r);
        }
        if(closed)
        {
            closeSpline();
        }
    }
    
    void CatmullRomSpline3::rebuild(std::vector<gtypes::Vector3> &vectors, int remember, int closed)
    {
        int r = 0;
        if(remember)
        {
            _originalPoints.clear();
            r = 1;
        }
        _segments.clear();
        for(int i = 0; i < vectors.size(); ++i)
        {
            addPoint(vectors[i], r);
        }
        if(closed)
        {
            closeSpline();
        }
    }
    
    void CatmullRomSpline3::rebuild(std::list<gtypes::Vector3> &vectors, int remember, int closed)
    {
        int r = 0;
        if(remember)
        {
            _originalPoints.clear();
            r = 1;
        }
        _segments.clear();
        for(std::list<gtypes::Vector3>::iterator it = vectors.begin(); it != vectors.end(); it++)
        {
            addPoint(*it, r);
        }
        if(closed)
        {
            closeSpline();
        }
    }


}

