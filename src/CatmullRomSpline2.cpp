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

    CatmullRomSpline2::CatmullRomSpline2() : _c(0.5), _length(0.0), _closed(0), _numSegments(0), _numSamples(16)
    {
        
    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::vector<gtypes::Vector2> &vectors, int closed) : _closed(closed), _numSamples(16)
    {
        for(int i = 0; i < vectors.size(); ++i)
        {
            addPoint(vectors[i]);
        }
    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::list<gtypes::Vector2> &vectors, int closed) : _closed(closed), _numSamples(16)
    {
        for(std::list<gtypes::Vector2>::iterator it = vectors.begin(); it != vectors.end(); it++)
        {
            addPoint(*it);
        }
    }
    
    CatmullRomSpline2::CatmullRomSpline2(gtypes::Vector2 *vectors, int n, int closed) : _closed(closed), _numSamples(16)
    {
        for(int i = 0; i < n; ++i)
        {
            addPoint(vectors[i]);
        }
    
    }
        
    CatmullRomSpline2::~CatmullRomSpline2()
    {
        
    }
    
    void CatmullRomSpline2::closeSpline()
    {
        
    }
    
    void CatmullRomSpline2::addPoint(double x, double y)
    {
        addPoint(gtypes::Vector2(x,y));
    }
    
    void CatmullRomSpline2::addPoint(gtypes::Vector2 point)
    {
        _points.push_back(point);
        if(_points.size() > 2)
            _calcLength();
    }
    
    void CatmullRomSpline2::setStartingTangent(gtypes::Vector2 tangent)
    {
        
    }
    
    void CatmullRomSpline2::setEndingTangent(gtypes::Vector2 tangent)
    {
        
    }
    
    gtypes::Vector2 CatmullRomSpline2::_resampledPos(double t)
    {
        if(t > 1.0)
            t -= (int)t;
        else if(t < 0.0)
            t += (int)t;
            
        double prevLen = 0.0, len = _lengths[0], l = t * _length;
        int i;
        
        for(i = 1; i < _lengths.size(); ++i)
        {
            prevLen += _lengths[i-1];
            len += _lengths[i];
            if(len > l)
                break;
        }
        
        if(l <= _lengths[0])
        {
            i = 0;
            prevLen = 0.0;
        }
        
        double newt = (l - prevLen) / _lengths[i];
        if(newt > 1.0)
        {
            newt -= (int)newt;
            ++i;
            if(i >= _lengths.size())
            {
                i = 0;
            }
        }
        else if(newt < 0.0)
        {
            newt += (int)newt;
            --i;
            if(i < 0)
                i = _lengths.size();
        }
        
        return _calcSegmentPosition(newt, i);
    }
    
    void CatmullRomSpline2::_resample(int quality)
    {
        std::vector<gtypes::Vector2> npoints;
        npoints.push_back(_points[0]);
        for(int i = 0; i <= quality; ++i)
            npoints.push_back(_resampledPos((double)i / quality));
        npoints.push_back(_points[_points.size()-1]);
        _points.clear();
        for(int i = 0; i < npoints.size(); ++i)
            addPoint(npoints[i]);
    }
    
    void CatmullRomSpline2::subdivide(int numSubdivisions)
    {
        
    }
    
    void CatmullRomSpline2::resample(int numSamples)
    {
        
    }
    
    gtypes::Vector2 CatmullRomSpline2::_calcSegmentPosition(double t, int index)
    {
        gtypes::Vector2 vec;
        int i0 = index - 1, i1 = index, i2 = index + 1, i3 = index + 2;
        if(i0 < 0)
            i0 = 0;
        if(i3 > (_points.size() - 1))
            i3 = _points.size() - 1;
        
        
        double t2 = t*t;
        double t3 = t2*t;
        
        vec = _points[i0] * (-t*_c + t2*2.0*_c - t3*_c) +
              _points[i1] * (1.0 + t2*(_c-3.0) + t3*(2.0-_c)  ) +
              _points[i2] * ( t*_c + t2*(3.0-2.0*_c) + t3*(_c-2.0) ) +
              _points[i3] * ( t3*_c - t2*_c);

        return vec;
    }
    
    gtypes::Vector2 CatmullRomSpline2::calcPosition(double t)
    {
        // ensure that t is in [0,1]
        if(t > 1.0f)
            t -= (int)t;
        else if(t < 0)
            t += (int)t;
            
        int index;
        float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time        
        double lt = (t - delta_t * (double)index) / delta_t;
        return _calcSegmentPosition(lt, index + 1);
    }
    
    gtypes::Vector2 CatmullRomSpline2::calcTangent(double t)
    {
        // ensure that t is in [0,1]
        if(t >= 1.0f)
            t -= (int)t;
        else if(t < 0)
            t += (int)t;
            
        int index;
        float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time
        double lt = (t - delta_t * (double)index) / delta_t;
        
        return _calcSegmentTangent(lt, index + 1);
    }
    
    gtypes::Vector2 CatmullRomSpline2::calcNormal(double t)
    {
        gtypes::Vector2 vec = calcTangent(t);
        return gtypes::Vector2(vec.y, -vec.x);
    }
    
    double CatmullRomSpline2::_calcLength()
    {
        _length = 0;
        _lengths.clear();
        for(int i = 0; i < _points.size() - 3; ++i)
        {
            _lengths.push_back(_calcSegmentLength(i));
            _length += _lengths[i];
        }
        
        return _length;
    }
    
    double CatmullRomSpline2::_calcSegmentLength(int index)
    {
        double len;
        int i;
        
        for(len = 0, i = 1; i <= _numSamples; ++i)
        {
            len += (_calcSegmentPosition(((double)(i-1))/_numSamples, index) -
                    _calcSegmentPosition(((double)i)/_numSamples, index)).length();
        }
        return len;
    }
    
    double CatmullRomSpline2::getLength()
    {
        return _length;
    }
    
    gtypes::Vector2 CatmullRomSpline2::_calcSegmentTangent(double t, int index)
    {
        double t2 = t*t;
        gtypes::Vector2 tan;
        tan = _points[index - 1] * (-_c + 4.0 * _c * t - 3.0 * _c * t2) +
              _points[index]     * (2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
              _points[index + 1] * (_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
              _points[index + 2] * (-2.0 * _c * t + 3.0 * _c * t2);
        
        return tan.normalised();
    }
    
    gtypes::Vector2 CatmullRomSpline2::_calcSegmentNormal(double t, int index)
    {
        gtypes::Vector2 v;
        v = _calcSegmentTangent(t, index);
        
        return gtypes::Vector2(v.y, -v.x).normalised();
    }
    
    
    void CatmullRomSpline2::setCurvature(double c)
    {
        _c = c;
    }
    
    void CatmullRomSpline2::setLengthSamplingRate(int r)
    {
        _numSamples = r;
    }
    
    void CatmullRomSpline2::rebuild(gtypes::Vector2 *vectors, int n, int closed)
    {
        _points.clear();
        _lengths.clear();
        for(int i = 0; i < n; ++i)
            addPoint(vectors[i]);
    }
    
    void CatmullRomSpline2::rebuild(std::vector<gtypes::Vector2> &vectors, int closed)
    {
        _points.clear();
        _lengths.clear();
        for(int i = 0; i < vectors.size(); ++i)
            addPoint(vectors[i]);
    }
    
    void CatmullRomSpline2::rebuild(std::list<gtypes::Vector2> &vectors, int closed)
    {
        _points.clear();
        _lengths.clear();
        for(std::list<gtypes::Vector2>::iterator it = vectors.begin(); it != vectors.end(); it++)
            addPoint(*it);
    }


}
