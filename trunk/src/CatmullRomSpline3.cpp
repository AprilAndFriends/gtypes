/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#include <iostream>

#include "CatmullRomSpline3.h"

namespace gtypes
{

    CatmullRomSpline3::CatmullRomSpline3() : _c(0.5), _length(0.0), _closed(0),
    _numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
    {
        
    }
    
    CatmullRomSpline3::CatmullRomSpline3(std::vector<gtypes::Vector3> &vectors, int closed, gtypes::Vector3 t1, gtypes::Vector3 t2) : _closed(closed),
    _c(0.5), _length(0.0), _numSegments(0), _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0), _prevIndex(-1)
    {
        for(int i = 0; i < vectors.size(); ++i)
        {
            addPoint(vectors[i]);
        }
        compile(this->_points, closed, t1, t2);
    }
    
    CatmullRomSpline3::CatmullRomSpline3(std::list<gtypes::Vector3> &vectors, int closed, gtypes::Vector3 t1, gtypes::Vector3 t2) : _closed(closed),
    _c(0.5), _length(0.0), _numSegments(0), _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0), _prevIndex(-1)
    {
        for(std::list<gtypes::Vector3>::iterator it = vectors.begin(); it != vectors.end(); it++)
        {
            addPoint(*it);
        }
        compile(this->_points, closed, t1, t2);
    }
    
    CatmullRomSpline3::CatmullRomSpline3(gtypes::Vector3 *vectors, int n, int closed, gtypes::Vector3 t1, gtypes::Vector3 t2) : _closed(closed),
    _c(0.5), _length(0.0), _numSegments(0), _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0), _prevIndex(-1)
    {
        for(int i = 0; i < n; ++i)
        {
            addPoint(vectors[i]);
        }
        compile(this->_points, closed, t1, t2);
    
    }
        
    CatmullRomSpline3::~CatmullRomSpline3()
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
        if(_points.size() < 1)
        {
            return gtypes::Vector3(0.0, 0.0, 0.0);
        }
        //std::cerr << t << std::endl;
        // ensure that t is in [0,1]
        if(t > 1.0)
        {
            t -= (int)t;
        }
        
        int index = 0;
        double lt, lp;
        
        // Using Arc-Length aprametrization
        _prevlen = 0.0;
        lp = _arcLengthMap.begin()->first;
        for(std::map<double, int>::iterator it = _arcLengthMap.begin(); it != _arcLengthMap.end(); it++)
        {
            if( (t >= _prevlen) && (t < (it->first)) )
            {
                //std::cerr << " t e[" << _prevlen << "," << it->first << "> , t = " << t << std::endl;
                lt = (t - _prevlen) * (1.0/(it->first-_prevlen));
                index = it->second;
                //std::cerr << "                  lt = " << lt << " Index : " << index << " PrevLen = " 
                //          << _prevlen << " [Prvi] = " << (it->first-_prevlen) <<std::endl;
                          
                //std::cerr << "(" << t << " - " << _prevlen << ") * ( 1.0 / (" << it->first << " - " << _prevlen << "))" << std::endl;
                /*if(_prevIndex == it->second)
                    index = it->second+1;
                else
                {
                    index = it->second;
                }*/
                
                break;
            }
            _prevIndex = it->second;
            _prevlen = it->first;
            
            //std::cerr << " Prevlen " << _prevlen << " Index " << index << " t = " << t << std::endl;
        }
        //
        
        // If asumming that all data points are equaly spaced we can use this code instead
        /*float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time        
        lt = (t - delta_t * (double)index) / delta_t;*/
        
        return _calcSegmentPosition(lt, index + 1);
    }
	
	gtypes::Vector3 CatmullRomSpline3::calcStaticTangent(double t)
	{
		// first we find the segment we are in
		int index = 0, lt = _arcLengthMap.begin()->first;
		
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
		
		gtypes::Vector3 staticTangent = (this->_points[index+2] - this->_points[index+1]).normalised();
		return staticTangent;
		
	}
    
    gtypes::Vector3 CatmullRomSpline3::calcTangent(double t)
    {
        if(_points.size() < 1)
        {
            return gtypes::Vector3(0.0, 0.0, 0.0);
        }
        // ensure that t is in [0,1]
        //if(t > 1.0)
        //    t -= (int)t;
			
		if((t > 0.989))
			return prevTangent;
			
		gtypes::Vector3 tan;
		tan = gtypes::Vector3( calcPosition(t + 0.01) - calcPosition(t) ).normalised();
		prevTangent = tan;
		return tan;
            
        // Analytical version
        /*int index;
        float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time
        double lt = (t - delta_t * (double)index) / delta_t;
        
        return _calcSegmentTangent(lt, index + 1);*/
    }
    
    gtypes::Vector3 CatmullRomSpline3::calcNormal(double t)
    {
        if(_points.size() < 1)
        {
            return gtypes::Vector3(0.0, 0.0, 0.0);
        }
        // ensure that t is in [0,1]
        if(t > 1.0)
            t -= (int)t;
            
        gtypes::Vector3 e1, e2, nor;
        double dot;
        e1 = calcTangent(t);
        e2 = gtypes::Vector3( calcTangent(t) - calcTangent(t + 0.03)).normalised();
        nor = e1.cross(e1);
        nor.normalise();
        
        dot = nor.dot(_prevNor);
        dot < 0 ? dot = -1 : dot = 1;
        
        _prevDot == 0 ? _prevDot = dot : NULL;
        
        if( dot != _prevDot )
        {
            _inflexed = !_inflexed;
            //std::cerr << " inflexija " << std::endl;
        }
        
        if(_inflexed)
        {
            //nor = -nor;
        }
        
        _prevNor = nor;
        _prevDot = dot;
        
        return nor;
          
        // Analytical version
        /*int index;
        float delta_t = 1.0 / (double)(_points.size()-3);
        
        // find the index of a segment in which our t lies
        index = (int)(t / delta_t);
        
        // find the localized time
        double lt = (t - delta_t * (double)index) / delta_t;
        
        return _calcSegmentNormal(lt, index + 1);*/
        
    }
    
    double CatmullRomSpline3::_calcLength()
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
    
    double CatmullRomSpline3::_calcSegmentLength(int index)
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
        double dot;
        
        tmp1 = _points[index - 1] * (-_c + 4.0 * _c * t - 3.0 * _c * t2) +
               _points[index]     * (2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
               _points[index + 1] * (_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
               _points[index + 2] * (-2.0 * _c * t + 3.0 * _c * t2);
        tmp1.normalise();
        
        tmp2 = _points[index - 1] * (4.0 * _c - 6.0 * _c * t) +
               _points[index]     * (2.0 * (_c - 3.0) + 6.0 * (2.0 - _c) * t) +
               _points[index + 1] * (2.0 * (3.0 - 2.0 * _c) + 6.0 * (_c - 2.0) * t) +
               _points[index + 2] * (-2.0 * _c + 6.0 * _c * t);

        nor = (tmp2 - tmp1*tmp2.dot(tmp1)) ;
        nor.normalise();
        
        dot = nor.dot(_prevNor);
        if( (dot <= -0.982) &&
            (dot >= -1.018) )
        {
            _inflexed = !_inflexed;
        }
        
        _prevNor = nor;
        
        if(_inflexed)
        {
            nor = -nor;
        }
        
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
    
    void CatmullRomSpline3::compile(gtypes::Vector3 *vectors, int n, int closed, gtypes::Vector3 startingTangent, gtypes::Vector3 endingTangent)
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
            if(startingTangent != gtypes::Vector3(0,0,0))
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
            if(endingTangent != gtypes::Vector3(0,0,0))
                addPoint(_points[_points.size() - 2] + endingTangent*2);
            else
                addPoint(_points[_points.size() - 1]);
        }
		
		prevTangent = gtypes::Vector3( calcPosition(0.01) - calcPosition(0.0) ).normalised();
    }
    
    void CatmullRomSpline3::compile(std::vector<gtypes::Vector3> &vectors, int closed, gtypes::Vector3 startingTangent, gtypes::Vector3 endingTangent)
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
            if(startingTangent != gtypes::Vector3(0,0,0))
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
            if(endingTangent != gtypes::Vector3(0,0,0))
                addPoint(_points[_points.size() - 2] + endingTangent*2);
            else
                addPoint(_points[_points.size() - 1]);
        }
		
		prevTangent = gtypes::Vector3( calcPosition(0.01) - calcPosition(0.0) ).normalised();
    }
    
    void CatmullRomSpline3::compile(std::list<gtypes::Vector3> &vectors, int closed, gtypes::Vector3 startingTangent, gtypes::Vector3 endingTangent)
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
            if(startingTangent != gtypes::Vector3(0,0,0))
                addPoint(*(vectors.begin()++) - startingTangent*2);
            else
                addPoint(*vectors.begin());
        }
        for(std::list<gtypes::Vector3>::iterator it = vectors.begin(); it != vectors.end(); it++)
            addPoint(*it);
        if(closed)
        {
            addPoint(_points[1]);
            addPoint(_points[2]);
        }
        else
        {
            if(endingTangent != gtypes::Vector3(0,0,0))
                addPoint(_points[_points.size() - 2] + endingTangent*2);
            else
                addPoint(_points[_points.size() - 1]);
        }
        
		prevTangent = gtypes::Vector3( calcPosition(0.01) - calcPosition(0.0) ).normalised();
    }
    
    void CatmullRomSpline3::_arcLengthReparametrization()
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
