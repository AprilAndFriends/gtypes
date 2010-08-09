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

    CatmullRomSpline3::CatmullRomSpline3() : _c(0.5), _length(0.0), _closed(0), _numSegments(0), _numSamples(16)
    {
        
    }
    
    CatmullRomSpline3::CatmullRomSpline3(std::vector<gtypes::Vector3> &vectors, int closed) : _closed(closed), _numSamples(16)
    {
        for(int i = 0; i < vectors.size(); ++i)
        {
            addPoint(vectors[i]);
        }
    }
    
    CatmullRomSpline3::CatmullRomSpline3(std::list<gtypes::Vector3> &vectors, int closed) : _closed(closed), _numSamples(16)
    {
        for(std::list<gtypes::Vector3>::iterator it = vectors.begin(); it != vectors.end(); it++)
        {
            addPoint(*it);
        }
    }
    
    CatmullRomSpline3::CatmullRomSpline3(gtypes::Vector3 *vectors, int n, int closed) : _closed(closed), _numSamples(16)
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
        
    }
    
    void CatmullRomSpline3::addPoint(double x, double y, double z)
    {
        addPoint(gtypes::Vector3(x,y,z));
    }
    
    void CatmullRomSpline3::addPoint(gtypes::Vector3 point)
    {
        _points.push_back(point);
        if(_points.size() > 2)
            _calcLength();
    }
    
    void CatmullRomSpline3::setStartingTangent(gtypes::Vector3 tangent)
    {
        
    }
    
    void CatmullRomSpline3::setEndingTangent(gtypes::Vector3 tangent)
    {
        
    }
    
    gtypes::Vector3 CatmullRomSpline3::_resampledPos(double t)
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
    
    void CatmullRomSpline3::_resample(int quality)
    {
        std::vector<gtypes::Vector3> npoints;
        npoints.push_back(_points[0]);
        for(int i = 0; i <= quality; ++i)
            npoints.push_back(_resampledPos((double)i / quality));
        npoints.push_back(_points[_points.size()-1]);
        _points.clear();
        for(int i = 0; i < npoints.size(); ++i)
            addPoint(npoints[i]);
    }
    
    void CatmullRomSpline3::subdivide(int numSubdivisions)
    {
        
    }
    
    void CatmullRomSpline3::resample(int numSamples)
    {
        
    }
    
    gtypes::Vector3 CatmullRomSpline3::_calcSegmentPosition(double t, int index)
    {
        gtypes::Vector3 vec;
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
    
    gtypes::Vector3 CatmullRomSpline3::calcPosition(double t)
    {
        // ensure that t is in [0,1]
        double dummy;
        t = modf(t, &dummy);
            
        int index;
        float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time        
        double lt = (t - delta_t * (double)index) / delta_t;
        return _calcSegmentPosition(lt, index + 1);
    }
    
    gtypes::Vector3 CatmullRomSpline3::calcTangent(double t)
    {
        // ensure that t and t - epsilon are in [0,1]
        double dummy;
        t = modf(t, &dummy);
            
        int index;
        float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time
        double lt = (t - delta_t * (double)index) / delta_t;
        
        return _calcSegmentTangent(lt, index + 1);
    }
    
    gtypes::Vector3 CatmullRomSpline3::calcNormal(double t)
    {
        // ensure that t is in [0,1]
        double dummy;
        t = modf(t, &dummy);
            
        int index;
        float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time
        double lt = (t - delta_t * (double)index) / delta_t;
        
        return _calcSegmentNormal(lt, index + 1);
        
    }
    
    double CatmullRomSpline3::_calcLength()
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
    
    double CatmullRomSpline3::_calcSegmentLength(int index)
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
    
    double CatmullRomSpline3::getLength()
    {
        return _length;
    }
    
    gtypes::Vector3 CatmullRomSpline3::_calcSegmentTangent(double t, int index)
    {
        double t2 = t*t;
        gtypes::Vector3 tan;
        tan = _points[index - 1] * (-_c + 4.0 * _c * t - 3.0 * _c * t2) +
              _points[index]     * (2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
              _points[index + 1] * (_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
              _points[index + 2] * (-2.0 * _c * t + 3.0 * _c * t2);
        
        return tan.normalised();
    }
    
    gtypes::Vector3 CatmullRomSpline3::_calcSegmentNormal(double t, int index)
    {
        gtypes::Vector3 tmp1, tmp2, nor;
        double t2 = t*t;
        
        tmp1 = _points[index - 1] * (-_c + 4.0 * _c * t - 3.0 * _c * t2) +
               _points[index]     * (2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
               _points[index + 1] * (_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
               _points[index + 2] * (-2.0 * _c * t + 3.0 * _c * t2);
        tmp1.normalise();
        
        tmp2 = _points[index - 1] * (4.0 * _c - 6.0 * _c * t) +
               _points[index]     * (2.0 * (_c - 3.0) + 6.0 * (2.0 - _c) * t) +
               _points[index + 1] * (2.0 * (3.0 - 2.0 * _c) + 6.0 * (_c - 2.0) * t) +
               _points[index + 2] * (-2.0 * _c + 6.0 * _c * t);
                  
        nor = (tmp2 - tmp1*gtypes::Vector3::dotProduct(tmp2, tmp1)) ;
        nor.normalise();

        return nor;
    }
    
    
    
    void CatmullRomSpline3::setCurvature(double c)
    {
        _c = c;
    }
    
    void CatmullRomSpline3::setLengthSamplingRate(int r)
    {
        _numSamples = r;
    }
    
    void CatmullRomSpline3::rebuild(gtypes::Vector3 *vectors, int n, int closed)
    {
        _points.clear();
        _lengths.clear();
        for(int i = 0; i < n; ++i)
            addPoint(vectors[i]);
    }
    
    void CatmullRomSpline3::rebuild(std::vector<gtypes::Vector3> &vectors, int closed)
    {
        _points.clear();
        _lengths.clear();
        for(int i = 0; i < vectors.size(); ++i)
            addPoint(vectors[i]);
    }
    
    void CatmullRomSpline3::rebuild(std::list<gtypes::Vector3> &vectors, int closed)
    {
        _points.clear();
        _lengths.clear();
        for(std::list<gtypes::Vector3>::iterator it = vectors.begin(); it != vectors.end(); it++)
            addPoint(*it);
    }


}
