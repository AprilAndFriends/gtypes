/// @file
/// @version 1.5
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause

#include <math.h>
#include <stdio.h>

#include "CatmullRomSpline3.h"
#include "gtypesUtil.h"
#include "Vector3.h"

namespace gtypes
{
	CatmullRomSpline3::CatmullRomSpline3() : _c(0.5), _length(0.0), _closed(false),
		_numSegments(0), _numSamples(16), _inflexed(false), _prevIndex(-1), _prevlen(0.0), _prevDot(0)
	{
	}
	
	CatmullRomSpline3::CatmullRomSpline3(std::vector<Vector3>& vectors, bool closed, Vector3 t1, Vector3 t2) : _closed(closed),
		_c(0.5), _length(0.0), _numSegments(0), _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0), _prevIndex(-1)
	{
		foreach_stdvector (Vector3, it, vectors)
		{
			this->addPoint(*it);
		}
		this->compile(this->_points, closed, t1, t2);
	}
	
	CatmullRomSpline3::CatmullRomSpline3(std::list<Vector3>& vectors, bool closed, Vector3 t1, Vector3 t2) : _closed(closed),
		_c(0.5), _length(0.0), _numSegments(0), _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0), _prevIndex(-1)
	{
		foreach_stdlist (Vector3, it, vectors)
		{
			this->addPoint(*it);
		}
		this->compile(this->_points, closed, t1, t2);
	}
	
	CatmullRomSpline3::CatmullRomSpline3(Vector3 vectors[], int n, bool closed, Vector3 t1, Vector3 t2) : _closed(closed),
		_c(0.5), _length(0.0), _numSegments(0), _numSamples(16), _inflexed(false), _prevlen(0.0), _prevDot(0), _prevIndex(-1)
	{
		for (int i = 0; i < n; ++i)
		{
			this->addPoint(vectors[i]);
		}
		this->compile(this->_points, closed, t1, t2);
	}
		
	CatmullRomSpline3::~CatmullRomSpline3()
	{
	}
	
	void CatmullRomSpline3::addPoint(float x, float y, float z)
	{
		this->addPoint(Vector3(x, y, z));
	}
	
	void CatmullRomSpline3::addPoint(Vector3 point)
	{
		this->_points.push_back(point);
		if (this->_points.size() > 2)
		{
			this->_calcLength();
		}
	}
	
	Vector3 CatmullRomSpline3::_calcSegmentPosition(double t, int index)
	{
		int i0 = index - 1;
		int i1 = index;
		int i2 = index + 1;
		int i3 = index + 2;
		if (i0 < 0)
		{
			i0 = 0;
		}
		if (i3 >((int)this->_points.size() - 1))
		{
			i3 = this->_points.size() - 1;
		}
		double t2 = t*t;
		double t3 = t2*t;
		Vector3 vec = this->_points[i0] * (float)(-t * _c + t2 * 2.0 * _c - t3 * _c) +
					  this->_points[i1] * (float)(1.0 + t2 * (_c - 3.0) + t3 * (2.0 - _c)) +
					  this->_points[i2] * (float)(t * _c + t2 * (3.0 - 2.0 * _c) + t3 * (_c - 2.0)) +
					  this->_points[i3] * (float)(t3 * _c - t2 * _c);
		return vec;
	}
	
	Vector3 CatmullRomSpline3::calcPosition(double t)
	{
		if (this->_points.size() < 1)
		{
			return Vector3();
		}
		// ensure that t is in [0,1]
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
	
	Vector3 CatmullRomSpline3::calcStaticTangent(double t)
	{
		// first we find the segment we are in
		int index = 0;
		int lt = (int)this->_arcLengthMap.begin()->first;
		foreach_stdmap (double, int, it, this->_arcLengthMap)
		{
			if ((t >= this->_prevlen) && (t < (it->first)))
			{
				lt = (int)((t - this->_prevlen) * (1.0 / (it->first - this->_prevlen)));
				index = it->second;
				break;
			}
			this->_prevIndex = it->second;
			this->_prevlen = it->first;
		}
		return (this->_points[index + 2] - this->_points[index + 1]).normalized();
	}
	
	Vector3 CatmullRomSpline3::calcTangent(double t)
	{
		if (this->_points.size() < 1)
		{
			return Vector3();
		}
		// ensure that t is in [0,1]
		//if (t > 1.0)
		//	t -= (int)t;
		if ((t <= 0.989) || this->_closed)
		{
			this->prevTangent = Vector3(this->calcPosition(t + 0.01) - this->calcPosition(t)).normalized();
		}
		return this->prevTangent;

		// Analytical version
		/*int index;
		float delta_t = 1.0 / (double)(_points.size()-3);
		
		// find the index of a segment in which our t lies
		index = (int)(t / delta_t);
		
		// find the localized time
		double lt = (t - delta_t * (double)index) / delta_t;
		
		return _calcSegmentTangent(lt, index + 1);*/
	}
	
	Vector3 CatmullRomSpline3::calcNormal(double t)
	{
		if (this->_points.size() < 1)
		{
			return Vector3();
		}
		// ensure that t is in [0,1]
		if (t > 1.0)
		{
			t -= (int)t;
		}
		Vector3 e1 = this->calcTangent(t);
		Vector3 e2 = Vector3(this->calcTangent(t) - this->calcTangent(t + 0.03)).normalized();
		Vector3 nor = e1.cross(e2);
		nor.normalize();
		double dot = nor.dot(this->_prevNor);
		dot < 0 ? dot = -1 : dot = 1;
		//_prevDot == 0 ? _prevDot = dot : NULL; commenting, seems to do nothing useful
		this->_prevDot = 0.0;
		if (dot != this->_prevDot)
		{
			this->_inflexed = !this->_inflexed;
			//std::cerr << " inflexija " << std::endl;
		}
		if (this->_inflexed)
		{
			//nor = -nor;
		}
		this->_prevNor = nor;
		this->_prevDot = dot;
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
	
	double CatmullRomSpline3::_calcSegmentLength(int index)
	{
		double len = 0;
		for (int i = 1; i <= this->_numSamples; ++i)
		{
			len += (this->_calcSegmentPosition(((double)(i - 1)) / this->_numSamples, index) -
					this->_calcSegmentPosition(((double)i) / this->_numSamples, index)).length();
		}
		//std::cerr << len << std::endl;
		return len;
	}
	
	double CatmullRomSpline3::getLength() const
	{
		return this->_length;
	}
	
	Vector3 CatmullRomSpline3::_calcSegmentTangent(double t, int index)
	{
		double t2 = t * t;
		Vector3 tan = this->_points[index - 1] * (float)(-_c + 4.0 * _c * t - 3.0 * _c * t2) +
					  this->_points[index] * (float)(2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
					  this->_points[index + 1] * (float)(_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
					  this->_points[index + 2] * (float)(-2.0 * _c * t + 3.0 * _c * t2);
		return tan.normalized();
	}
	
	Vector3 CatmullRomSpline3::_calcSegmentNormal(double t, int index)
	{
		double t2 = t * t;
		Vector3 tmp1 = this->_points[index - 1] * (float)(-_c + 4.0 * _c * t - 3.0 * _c * t2) +
					   this->_points[index] * (float)(2.0 * (_c - 3.0) * t + 3.0 * (2.0 - _c) * t2) +
					   this->_points[index + 1] * (float)(_c + 2.0 * (3.0 - 2.0 * _c) * t + 3.0 * (_c - 2.0) * t2) +
					   this->_points[index + 2] * (float)(-2.0 * _c * t + 3.0 * _c * t2);
		tmp1.normalize();
		Vector3 tmp2 = this->_points[index - 1] * (float)(4.0 * _c - 6.0 * _c * t) +
					   this->_points[index] * (float)(2.0 * (_c - 3.0) + 6.0 * (2.0 - _c) * t) +
					   this->_points[index + 1] * (float)(2.0 * (3.0 - 2.0 * _c) + 6.0 * (_c - 2.0) * t) +
					   this->_points[index + 2] * (float)(-2.0 * _c + 6.0 * _c * t);
		Vector3 nor(tmp2 - tmp1 * tmp2.dot(tmp1));
		nor.normalize();
		double dot = nor.dot(this->_prevNor);
		if (dot <= -0.982 && dot >= -1.018)
		{
			this->_inflexed = !this->_inflexed;
		}
		this->_prevNor = nor;
		if (this->_inflexed)
		{
			nor = -nor;
		}
		return nor;
	}
	
	void CatmullRomSpline3::setCurvature(double c)
	{
		this->_c = c;
	}
	
	void CatmullRomSpline3::setLengthSamplingRate(int r)
	{
		this->_numSamples = r;
	}
	
	void CatmullRomSpline3::compile(Vector3* vectors, int n, bool closed, Vector3 t1, Vector3 t2)
	{
		this->_points.clear();
		this->_lengths.clear();
		this->_closed = closed;
		if (this->_closed)
		{
			this->addPoint(vectors[n - 1]);
		}
		else if (t1.x != 0.0f || t1.y != 0.0f || t1.z != 0.0f)
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
		else if (t2.x != 0.0f || t2.y != 0.0f || t2.z != 0.0f)
		{
			this->addPoint(this->_points[this->_points.size() - 2] + t2 * 2);
		}
		else
		{
			this->addPoint(this->_points[this->_points.size() - 1]);
		}
		this->prevTangent = Vector3(this->calcPosition(0.01) - this->calcPosition(0.0)).normalized();
	}
	
	void CatmullRomSpline3::compile(std::vector<Vector3> &vectors, bool closed, Vector3 t1, Vector3 t2)
	{
		this->_points.clear();
		this->_lengths.clear();
		this->_closed = closed;
		if (this->_closed)
		{
			this->addPoint(*vectors.end());
		}
		else if (t1.x != 0.0f || t1.y != 0.0f || t1.z != 0.0f)
		{
			this->addPoint(vectors[1] - t1 * 2);
		}
		else
		{
			this->addPoint(vectors[0]);
		}
		foreach_stdvector (Vector3, it, vectors)
		{
			this->addPoint(*it);
		}
		if (this->_closed)
		{
			this->addPoint(this->_points[1]);
			this->addPoint(this->_points[2]);
		}
		else if (t2.x != 0.0f || t2.y != 0.0f || t2.z != 0.0f)
		{
			this->addPoint(this->_points[this->_points.size() - 2] + t2 * 2);
		}
		else
		{
			this->addPoint(this->_points[this->_points.size() - 1]);
		}
		this->prevTangent = Vector3(this->calcPosition(0.01) - this->calcPosition(0.0)).normalized();
	}
	
	void CatmullRomSpline3::compile(std::list<Vector3> &vectors, bool closed, Vector3 t1, Vector3 t2)
	{
		this->_points.clear();
		this->_lengths.clear();
		this->_closed = closed;
		if (this->_closed)
		{
			this->addPoint(*(vectors.rbegin()));
		}
		else if (t1.x != 0.0f || t1.y != 0.0f || t1.z != 0.0f)
		{
			this->addPoint(*(vectors.begin()++) - t1 * 2);
		}
		else
		{
			this->addPoint(*vectors.begin());
		}
		foreach_stdlist (Vector3, it, vectors)
		{
			this->addPoint(*it);
		}
		if (this->_closed)
		{
			this->addPoint(this->_points[1]);
			this->addPoint(this->_points[2]);
		}
		else if (t2.x != 0.0f || t2.y != 0.0f || t2.z != 0.0f)
		{
			this->addPoint(this->_points[this->_points.size() - 2] + t2 * 2);
		}
		else
		{
			this->addPoint(this->_points[this->_points.size() - 1]);
		}
		this->prevTangent = Vector3(this->calcPosition(0.01) - this->calcPosition(0.0)).normalized();
	}
	
	void CatmullRomSpline3::_arcLengthReparametrization()
	{
		this->_arcLengthMap.clear();
		double prevlen = 0.0;
		for (unsigned int i = 0; i < this->_lengths.size(); ++i)
		{
			this->_arcLengthMap[prevlen + (this->_lengths[i] / this->_length)] = i;
			//std::cerr << "Index : " << i << " Len : " << _lengths[i]/_length << " Prevlen : " << prevlen << std::endl;
			prevlen += this->_lengths[i] / this->_length;
		}
		//std::cerr << "x" << std::endl;
	}

}
