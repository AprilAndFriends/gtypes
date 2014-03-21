/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.46
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#include <math.h>
#include <stdio.h>

#include "CatmullRomSpline2.h"
#include "gtypesUtil.h"
#include "Vector2.h"

namespace gtypes
{
	CatmullRomSpline2::CatmullRomSpline2() : _c(0.5), _length(0.0), _closed(0),
		_numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
	{
	}
	
	CatmullRomSpline2::CatmullRomSpline2(std::vector<Vector2>& vectors, int closed, Vector2 t1, Vector2 t2) : _c(0.5), _length(0.0), _closed(closed),
		_numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
	{
		this->compile(vectors, closed, t1, t2);
	}
		
	CatmullRomSpline2::CatmullRomSpline2(Vector2 vectors[], int n, int closed, Vector2 t1,  Vector2 t2) : _c(0.5), _length(0.0), _closed(closed),
		_numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
	{
		this->compile(vectors, n, closed, t1, t2);
	}
		
	CatmullRomSpline2::~CatmullRomSpline2()
	{

	}
	
	void CatmullRomSpline2::addPoint(float x, float y)
	{
		addPoint(Vector2(x, y));
	}
	
	void CatmullRomSpline2::addPoint(Vector2 point)
	{
		_points.push_back(point);
		if (_points.size() > 2)
		{
			_calcLength();
		}
	}
	
	Vector2 CatmullRomSpline2::_calcSegmentPosition(double t, int index)
	{
		Vector2 vec;
		int i0 = index - 1, i1 = index, i2 = index + 1, i3 = index + 2;
		if (i0 < 0)
		{
			i0 = 0;
		}
		if (i3 > (int)(_points.size() - 1))
		{
			i3 = _points.size() - 1;
		}
		
		double t2 = t * t;
		double t3 = t2 * t;
		
		vec = _points[i0] * (float)(-t * _c + t2 * 2.0 * _c - t3 * _c) +
			  _points[i1] * (float)(1.0 + t2 * (_c - 3.0) + t3 * (2.0 - _c)) +
			  _points[i2] * (float)(t * _c  + t2 * (3.0 - 2.0 *_c) + t3 * (_c - 2.0)) +
			  _points[i3] * (float)(t3 * _c - t2 * _c);

		return vec;
	}

	Vector2 CatmullRomSpline2::calcPosition(double t)
	{
		if (_points.size() < 1)
		{
			return Vector2();
		}
		if (t > 1.0)
		{
			t -= (int)t;
		}
		int index = 0;
		double lt = 0.0;
		double lp = 0.0;
		// Using Arc-Length aprametrization
		_prevlen = 0.0;
		lp = _arcLengthMap.begin()->first;
		foreach_stdmap (double, int, it, _arcLengthMap)
		{
			if (t >= _prevlen && t < (it->first))
			{
				lt = (t - _prevlen) * (1.0 / (it->first - _prevlen));
				index = it->second;
				break;
			}
			_prevIndex = it->second;
			_prevlen = it->first;
		}
		return _calcSegmentPosition(lt, index + 1);
	}
	
	Vector2 CatmullRomSpline2::calcTangent(double t)
	{
		if (_points.size() < 1)
		{
			return Vector2();
		}
		if (t > 1.0)
		{
			t -= (int)t;
		}
		return Vector2(calcPosition(t + 0.01) - calcPosition(t)).normalized();
	}
	
	Vector2 CatmullRomSpline2::calcNormal(double t)
	{
		// ensure that t is in [0,1]
		if (t > 1.0)
		{
			t -= (int)t;
		}
		Vector2 nor = calcTangent(t);
		nor = Vector2(-nor.y, nor.x);
		return nor;
	}
	
	double CatmullRomSpline2::_calcLength()
	{
		_length = 0;
		_lengths.clear();
		for (unsigned int i = 0; i < _points.size() - 3; ++i)
		{
			_lengths.push_back(_calcSegmentLength(i + 1));
			_length += _lengths[i];
		}
		if (_length > 0)
		{
			_arcLengthReparametrization();
		}
		return _length;
	}
	
	double CatmullRomSpline2::_calcSegmentLength(int index)
	{
		double len = 0;
		for (int i = 1; i <= _numSamples; ++i)
		{
			len += (_calcSegmentPosition(((double)(i - 1)) / _numSamples, index) -
					_calcSegmentPosition(((double)i) / _numSamples, index)).length();
		}
		return len;
	}
	
	double CatmullRomSpline2::getLength() const
	{
		return _length;
	}
	
	int CatmullRomSpline2::getNumPoints() const
	{
		int n = _points.size() - 2;
		return (n < 0) ? 0 : n;
	}

	Vector2 CatmullRomSpline2::_calcSegmentTangent(double t, int index)
	{
		double t2 = t*t;
		Vector2 tan;
		tan = _points[index - 1] * (float)(-_c + 4.0 * _c * t - 3.0 * _c * t2) +
			  _points[index]	 * (float)(2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
			  _points[index + 1] * (float)(_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
			  _points[index + 2] * (float)(-2.0 * _c * t + 3.0 * _c * t2);
		
		return tan.normalized();
	}
	
	Vector2 CatmullRomSpline2::_calcSegmentNormal(double t, int index)
	{
		Vector2 nor = _calcSegmentTangent(t, index);
		nor = Vector2(-nor.y, nor.x);
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
	
	void CatmullRomSpline2::compile(std::vector<Vector2>& vectors, int closed, Vector2 t1, Vector2 t2)
	{
		_points.clear();
		_lengths.clear();
		if (closed)
		{
			_closed = 1;
			addPoint(*vectors.end());
		}
		else 
		{
			_closed = 0;
			if (!t1.isNull())
			{
				addPoint(vectors[1] - t1 * 2);
			}
			else
			{
				addPoint(vectors[0]);
			}
		}
		foreach_stdvector (Vector2, it, vectors)
		{
			addPoint(*it);
		}
		if (closed)
		{
			addPoint(_points[1]);
			addPoint(_points[2]);
		}
		else if (!t2.isNull())
		{
			addPoint(_points[_points.size() - 2] + t2 * 2);
		}
		else
		{
			addPoint(_points[_points.size() - 1]);
		}
	}
	
	void CatmullRomSpline2::compile(Vector2 vectors[], int n, int closed, Vector2 t1, Vector2 t2)
	{
		_points.clear();
		_lengths.clear();
		if (closed)
		{
			_closed = 1;
			addPoint(vectors[n-1]);
		}
		else 
		{
			_closed = 0;
			if (!t1.isNull())
			{
				addPoint(vectors[1] - t1 * 2);
			}
			else
			{
				addPoint(vectors[0]);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			addPoint(vectors[i]);
		}
		if (closed)
		{   
			addPoint(_points[1]);
			addPoint(_points[2]);
		}
		else if (!t2.isNull())
		{
			addPoint(_points[_points.size() - 2] + t2 * 2);
		}
		else
		{
			addPoint(_points[_points.size() - 1]);
		}
	}
	
	void CatmullRomSpline2::_arcLengthReparametrization()
	{
		_arcLengthMap.clear();
		double prevlen = 0;
		for (unsigned int i = 0; i < _lengths.size(); ++i)
		{
			_arcLengthMap[prevlen + (_lengths[i] / _length)] = i;
			prevlen += _lengths[i] / _length;
		}
	}

}
