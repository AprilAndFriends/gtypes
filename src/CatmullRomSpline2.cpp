/// @file
/// @version 1.5
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

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
	
	CatmullRomSpline2::CatmullRomSpline2(std::vector<Vector2>& vectors, bool closed, Vector2 t1, Vector2 t2) : _c(0.5), _length(0.0), _closed(closed),
		_numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
	{
		this->compile(vectors, closed, t1, t2);
	}
		
	CatmullRomSpline2::CatmullRomSpline2(Vector2 vectors[], int n, bool closed, Vector2 t1, Vector2 t2) : _c(0.5), _length(0.0), _closed(closed),
		_numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
	{
		this->compile(vectors, n, closed, t1, t2);
	}
		
	CatmullRomSpline2::~CatmullRomSpline2()
	{
	}
	
	void CatmullRomSpline2::addPoint(float x, float y)
	{
		this->addPoint(Vector2(x, y));
	}
	
	void CatmullRomSpline2::addPoint(Vector2 point)
	{
		this->_points.push_back(point);
		if (this->_points.size() > 2)
		{
			this->_calcLength();
		}
	}
	
	Vector2 CatmullRomSpline2::_calcSegmentPosition(double t, int index)
	{
		int i0 = index - 1;
		int i1 = index;
		int i2 = index + 1;
		int i3 = index + 2;
		if (i0 < 0)
		{
			i0 = 0;
		}
		if (i3 > (int)(this->_points.size() - 1))
		{
			i3 = this->_points.size() - 1;
		}
		double t2 = t * t;
		double t3 = t2 * t;
		Vector2 vec = this->_points[i0] * (float)(-t * _c + t2 * 2.0 * _c - t3 * _c) +
					  this->_points[i1] * (float)(1.0 + t2 * (_c - 3.0) + t3 * (2.0 - _c)) +
					  this->_points[i2] * (float)(t * _c + t2 * (3.0 - 2.0 *_c) + t3 * (_c - 2.0)) +
					  this->_points[i3] * (float)(t3 * _c - t2 * _c);
		return vec;
	}

	Vector2 CatmullRomSpline2::calcPosition(double t)
	{
		if (this->_points.size() < 1)
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
		this->_prevlen = 0.0;
		lp = this->_arcLengthMap.begin()->first;
		foreach_stdmap (double, int, it, this->_arcLengthMap)
		{
			if (t >= this->_prevlen && t < (it->first))
			{
				lt = (t - this->_prevlen) * (1.0 / (it->first - this->_prevlen));
				index = it->second;
				break;
			}
			this->_prevIndex = it->second;
			this->_prevlen = it->first;
		}
		return this->_calcSegmentPosition(lt, index + 1);
	}
	
	Vector2 CatmullRomSpline2::calcTangent(double t)
	{
		if (this->_points.size() < 1)
		{
			return Vector2();
		}
		if (t > 1.0)
		{
			t -= (int)t;
		}
		return Vector2(this->calcPosition(t + 0.01) - this->calcPosition(t)).normalized();
	}
	
	Vector2 CatmullRomSpline2::calcNormal(double t)
	{
		// ensure that t is in [0,1]
		if (t > 1.0)
		{
			t -= (int)t;
		}
		Vector2 nor = this->calcTangent(t);
		nor.set(-nor.y, nor.x);
		return nor;
	}
	
	double CatmullRomSpline2::_calcLength()
	{
		this->_length = 0;
		this->_lengths.clear();
		for (unsigned int i = 0; i < this->_points.size() - 3; ++i)
		{
			this->_lengths.push_back(this->_calcSegmentLength(i + 1));
			this->_length += this->_lengths[i];
		}
		if (this->_length > 0)
		{
			this->_arcLengthReparametrization();
		}
		return this->_length;
	}
	
	double CatmullRomSpline2::_calcSegmentLength(int index)
	{
		double len = 0;
		for (int i = 1; i <= this->_numSamples; ++i)
		{
			len += (this->_calcSegmentPosition(((double)(i - 1)) / this->_numSamples, index) -
					this->_calcSegmentPosition(((double)i) / this->_numSamples, index)).length();
		}
		return len;
	}
	
	double CatmullRomSpline2::getLength() const
	{
		return this->_length;
	}
	
	int CatmullRomSpline2::getNumPoints() const
	{
		int n = this->_points.size() - 2;
		return (n < 0) ? 0 : n;
	}

	Vector2 CatmullRomSpline2::_calcSegmentTangent(double t, int index)
	{
		double t2 = t * t;
		Vector2 tan = this->_points[index - 1] * (float)(-_c + 4.0 * _c * t - 3.0 * _c * t2) +
					  this->_points[index] * (float)(2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
					  this->_points[index + 1] * (float)(_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
					  this->_points[index + 2] * (float)(-2.0 * _c * t + 3.0 * _c * t2);
		return tan.normalized();
	}
	
	Vector2 CatmullRomSpline2::_calcSegmentNormal(double t, int index)
	{
		Vector2 nor = this->_calcSegmentTangent(t, index);
		nor.set(-nor.y, nor.x);
		return nor;
	}
	
	void CatmullRomSpline2::setCurvature(double c)
	{
		this->_c = c;
	}
	
	void CatmullRomSpline2::setLengthSamplingRate(int r)
	{
		this->_numSamples = r;
	}
	
	void CatmullRomSpline2::compile(std::vector<Vector2>& vectors, bool closed, Vector2 t1, Vector2 t2)
	{
		this->_points.clear();
		this->_lengths.clear();
		this->_closed = closed;
		if (this->_closed)
		{
			this->addPoint(*vectors.end());
		}
		else if (!t1.isNull())
		{
			this->addPoint(vectors[1] - t1 * 2);
		}
		else
		{
			this->addPoint(vectors[0]);
		}
		foreach_stdvector (Vector2, it, vectors)
		{
			this->addPoint(*it);
		}
		if (this->_closed)
		{
			this->addPoint(this->_points[1]);
			this->addPoint(this->_points[2]);
		}
		else if (!t2.isNull())
		{
			this->addPoint(this->_points[this->_points.size() - 2] + t2 * 2);
		}
		else
		{
			this->addPoint(this->_points[this->_points.size() - 1]);
		}
	}
	
	void CatmullRomSpline2::compile(Vector2 vectors[], int n, bool closed, Vector2 t1, Vector2 t2)
	{
		this->_points.clear();
		this->_lengths.clear();
		this->_closed = closed;
		if (this->_closed)
		{
			this->addPoint(vectors[n - 1]);
		}
		else if (!t1.isNull())
		{
			this->addPoint(vectors[1] - t1 * 2);
		}
		else
		{
			this->addPoint(vectors[0]);
		}
		for (int i = 0; i < n; ++i)
		{
			this->addPoint(vectors[i]);
		}
		if (this->_closed)
		{   
			this->addPoint(this->_points[1]);
			this->addPoint(this->_points[2]);
		}
		else if (!t2.isNull())
		{
			this->addPoint(this->_points[this->_points.size() - 2] + t2 * 2);
		}
		else
		{
			this->addPoint(this->_points[this->_points.size() - 1]);
		}
	}
	
	void CatmullRomSpline2::_arcLengthReparametrization()
	{
		this->_arcLengthMap.clear();
		double prevlen = 0;
		for (unsigned int i = 0; i < this->_lengths.size(); ++i)
		{
			this->_arcLengthMap[prevlen + (this->_lengths[i] / this->_length)] = i;
			prevlen += this->_lengths[i] / this->_length;
		}
	}

}
