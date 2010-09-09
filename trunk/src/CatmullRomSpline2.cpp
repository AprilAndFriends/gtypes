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

    CatmullRomSpline2::CatmullRomSpline2() : _c(0.5), _length(0.0), _closed(0),
    _numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
    {
        
    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::vector<gtypes::Vector2> &vectors, int closed) : _closed(closed),
    _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0)
    {
        for(int i = 0; i < vectors.size(); ++i)
        {
            addPoint(vectors[i]);
        }
    }
    
    CatmullRomSpline2::CatmullRomSpline2(std::list<gtypes::Vector2> &vectors, int closed) : _closed(closed),
    _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0)
    {
        for(std::list<gtypes::Vector2>::iterator it = vectors.begin(); it != vectors.end(); it++)
        {
            addPoint(*it);
        }
    }
    
    CatmullRomSpline2::CatmullRomSpline2(gtypes::Vector2 *vectors, int n, int closed) : _closed(closed),
    _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0)
    {
        for(int i = 0; i < n; ++i)
        {
            addPoint(vectors[i]);
        }
    
    }
        
    CatmullRomSpline2::~CatmullRomSpline2()
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
        if(t > 1.0)
            t -= (int)t;
            
        int index = 0;
        double lt, lp;
        
        // Using Arc-Length aprametrization
        _prevlen = 0.0;
        lp = _arcLengthMap.begin()->first;
        for(std::map<double, int>::iterator it = _arcLengthMap.begin(); it != _arcLengthMap.end(); it++)
        {
            if( (t >= _prevlen) && (t < (it->first)) )
            {
                lt = (t - _prevlen) * (1.0/(it->first-_prevlen));
                index = it->second;
                break;
            }
            _prevIndex = it->second;
            _prevlen = it->first;
        }
        
        return _calcSegmentPosition(lt, index + 1);
    }
    
    gtypes::Vector2 CatmullRomSpline2::calcTangent(double t)
    {
        if(t > 1.0)
            t -= (int)t;
        return gtypes::Vector2( calcPosition(t + 0.01) - calcPosition(t) ).normalised();
    }
    
    gtypes::Vector2 CatmullRomSpline2::calcNormal(double t)
    {
        // ensure that t is in [0,1]
        if(t > 1.0)
            t -= (int)t;
            
        gtypes::Vector2 nor = calcTangent(t);
        nor = gtypes::Vector2(-nor.y, nor.x);
        return nor;
    }
    
    double CatmullRomSpline2::_calcLength()
    {
        _length = 0;
        _lengths.clear();
        for(int i = 0; i < _points.size() - 3; ++i)
        {
            _lengths.push_back(_calcSegmentLength(i+1));
            _length += _lengths[i];
        }
        
        if(_length > 0)
            _arcLengthReparametrization();
        
        return _length;
    }
    
    double CatmullRomSpline2::_calcSegmentLength(int index)
    {
        double len = 0;
        int i;
        
        for(i = 1; i <= _numSamples; ++i)
        {
            len += (_calcSegmentPosition(((double)(i-1))/_numSamples, index) -
                    _calcSegmentPosition(((double)i)/_numSamples, index)).length();
        }
        //std::cerr << len << std::endl;
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
        gtypes::Vector2 nor = _calcSegmentTangent(t, index);
        nor = gtypes::Vector2(-nor.y, nor.x);
        return nor;
    }
    
    void CatmullRomSpline2::setCurvature(double c)
    {
        _c = c;
    }
    
    void CatmullRomSpline2::setLengthSamplingRate(int r)
    {
        _numSamples = r;
    }
    
    void CatmullRomSpline2::compile(gtypes::Vector2 *vectors, int n, int closed, gtypes::Vector2 startingTangent, gtypes::Vector2 endingTangent)
    {
        _points.clear();
        _lengths.clear();
        if(closed)
        {
            _closed = 1;
            addPoint(vectors[n-1]);
        }
        else 
        {
            _closed = 0;
            if(startingTangent != gtypes::Vector2(0,0))
                addPoint(vectors[1] - startingTangent*2);
            else
                addPoint(vectors[0]);
        }
        for(int i = 0; i < n; ++i)
            addPoint(vectors[i]);
        if(closed)
        {   
            addPoint(_points[1]);
            addPoint(_points[2]);
        }
        else
        {
            if(endingTangent != gtypes::Vector2(0,0))
                addPoint(_points[_points.size() - 2] + endingTangent*2);
            else
                addPoint(_points[_points.size() - 1]);
        }
    }
    
    void CatmullRomSpline2::compile(std::vector<gtypes::Vector2> &vectors, int closed, gtypes::Vector2 startingTangent, gtypes::Vector2 endingTangent)
    {
        _points.clear();
        _lengths.clear();
        if(closed)
        {
            _closed = 1;
            addPoint(*vectors.end());
        }
        else 
        {
            _closed = 0;
            if(startingTangent != gtypes::Vector2(0,0))
                addPoint(vectors[1] - startingTangent*2);
            else
                addPoint(vectors[0]);
        }
        for(int i = 0; i < vectors.size(); ++i)
            addPoint(vectors[i]);
        if(closed)
        {
            addPoint(_points[1]);
            addPoint(_points[2]);
        }
        else
        {
            if(endingTangent != gtypes::Vector2(0,0))
                addPoint(_points[_points.size() - 2] + endingTangent*2);
            else
                addPoint(_points[_points.size() - 1]);
        }
    }
    
    void CatmullRomSpline2::compile(std::list<gtypes::Vector2> &vectors, int closed, gtypes::Vector2 startingTangent, gtypes::Vector2 endingTangent)
    {
        _points.clear();
        _lengths.clear();
        if(closed)
        {
            _closed = 1;
            addPoint(*(vectors.rbegin()));
        }
        else 
        {
            _closed = 0;
            if(startingTangent != gtypes::Vector2(0,0))
                addPoint(*(vectors.begin()++) - startingTangent*2);
            else
                addPoint(*vectors.begin());
        }
        for(std::list<gtypes::Vector2>::iterator it = vectors.begin(); it != vectors.end(); it++)
            addPoint(*it);
        if(closed)
        {
            addPoint(_points[1]);
            addPoint(_points[2]);
        }
        else
        {
            if(endingTangent != gtypes::Vector2(0,0))
                addPoint(_points[_points.size() - 2] + endingTangent*2);
            else
                addPoint(_points[_points.size() - 1]);
        }
        
    }
    
    void CatmullRomSpline2::_arcLengthReparametrization()
    {
        _arcLengthMap.clear();
        double prevlen = 0;
        for(int i = 0; i < _lengths.size(); ++i)
        {
            _arcLengthMap[prevlen + (_lengths[i]/_length)] = i;
            //std::cerr << "Index : " << i << " Len : " << _lengths[i]/_length << " Prevlen : " << prevlen << std::endl;
            prevlen += _lengths[i]/_length;
        }
        //std::cerr << "x" << std::endl;
    }

}
