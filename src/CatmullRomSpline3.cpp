/// @file
/// @version 1.6
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
	CatmullRomSpline3::CatmullRomSpline3() :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevLength(0.0), _prevIndex(-1), _prevDot(0), _inflexed(false)
	{
	}

	CatmullRomSpline3::CatmullRomSpline3(const std::vector<Vector3>& vectors, bool closed, int samples, Vector3 t1, Vector3 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevLength(0.0), _prevIndex(-1), _prevDot(0), _inflexed(false)
	{
		this->set(vectors, closed, samples, t1, t2);
	}

	CatmullRomSpline3::CatmullRomSpline3(const Vector3 vectors[], int n, bool closed, int samples, Vector3 t1, Vector3 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevLength(0.0), _prevIndex(-1), _prevDot(0), _inflexed(false)
	{
		this->set(vectors, n, closed, samples, t1, t2);
	}

	CatmullRomSpline3::~CatmullRomSpline3()
	{
	}

	void CatmullRomSpline3::set(const Vector3 vectors[], int n, bool closed, int samples, Vector3 t1, Vector3 t2)
	{
		this->points.clear();
		this->lengths.clear();
		this->closed = closed;
		if (this->closed)
		{
			this->points.push_back(vectors[n - 1]);
		}
		else if (!t1.isNull())
		{
			this->points.push_back(vectors[1] - t1 * 2);
		}
		else
		{
			this->points.push_back(vectors[0]);
		}
		this->points.insert(this->points.end(), vectors, vectors + n);
		if (this->closed)
		{
			this->points.push_back(this->points[1]);
			this->points.push_back(this->points[2]);
		}
		else if (!t1.isNull())
		{
			this->points.push_back(this->points[this->points.size() - 2] + t2 * 2);
		}
		else
		{
			this->points.push_back(this->points[this->points.size() - 1]);
		}
		this->_prevTangent = Vector3(this->calcPosition(0.01) - this->calcPosition(0.0)).normalized();
		this->_calcLength();
	}

	void CatmullRomSpline3::set(const std::vector<Vector3>& vectors, bool closed, int samples, Vector3 t1, Vector3 t2)
	{
		this->points.clear();
		this->lengths.clear();
		this->closed = closed;
		if (this->closed)
		{
			this->points.push_back(vectors.back());
		}
		else if (!t1.isNull())
		{
			this->points.push_back(vectors[1] - t1 * 2);
		}
		else
		{
			this->points.push_back(vectors[0]);
		}
		this->points.insert(this->points.end(), vectors.begin(), vectors.end());
		if (this->closed)
		{
			this->points.push_back(this->points[1]);
			this->points.push_back(this->points[2]);
		}
		else if (!t1.isNull())
		{
			this->points.push_back(this->points[this->points.size() - 2] + t2 * 2);
		}
		else
		{
			this->points.push_back(this->points[this->points.size() - 1]);
		}
		this->_prevTangent = Vector3(this->calcPosition(0.01) - this->calcPosition(0.0)).normalized();
		this->_calcLength();
	}

	Vector3 CatmullRomSpline3::calcPosition(double t)
	{
		if (this->points.size() == 0)
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
		this->_prevLength = 0.0;
		double lp = this->_arcLengths.begin()->first;
		foreach_stdmap (double, int, it, this->_arcLengths)
		{
			if (t >= this->_prevLength && t < (it->first))
			{
				lt = (t - this->_prevLength) * (1.0 / (it->first - this->_prevLength));
				index = it->second;
				break;
			}
			this->_prevIndex = it->second;
			this->_prevLength = it->first;
		}
		return this->_calcSegmentPosition(lt, index + 1);
	}
	
	Vector3 CatmullRomSpline3::calcTangent(double t)
	{
		if (this->points.size() == 0)
		{
			return Vector3();
		}
		if (t <= 0.989 || this->closed)
		{
			this->_prevTangent = Vector3(this->calcPosition(t + 0.01) - this->calcPosition(t)).normalized();
		}
		return this->_prevTangent;
	}
	
	Vector3 CatmullRomSpline3::calcStaticTangent(double t)
	{
		int index = 0;
		int lt = (int)this->_arcLengths.begin()->first;
		foreach_stdmap (double, int, it, this->_arcLengths)
		{
			if ((t >= this->_prevLength) && (t < (it->first)))
			{
				lt = (int)((t - this->_prevLength) * (1.0 / (it->first - this->_prevLength)));
				index = it->second;
				break;
			}
			this->_prevIndex = it->second;
			this->_prevLength = it->first;
		}
		return (this->points[index + 2] - this->points[index + 1]).normalized();
	}

	Vector3 CatmullRomSpline3::calcNormal(double t)
	{
		if (this->points.size() == 0)
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
		Vector3 normal = e1.cross(e2);
		normal.normalize();
		double dot = normal.dot(this->_prevNormal);
		dot < 0 ? dot = -1 : dot = 1;
		this->_prevDot = 0.0;
		if (dot != this->_prevDot)
		{
			this->_inflexed = !this->_inflexed;
		}
		this->_prevNormal = normal;
		this->_prevDot = dot;
		return normal;
	}

	double CatmullRomSpline3::_calcLength()
	{
		this->length = 0.0;
		this->lengths.clear();
		for (unsigned int i = 0; i < this->points.size() - 3; ++i)
		{
			this->lengths.push_back(this->_calcSegmentLength(i + 1));
			this->length += this->lengths[i];
		}
		if (this->length > 0)
		{
			this->_arcLengthReparametrization();
		}
		return this->length;
	}

	double CatmullRomSpline3::_calcSegmentLength(int index)
	{
		double length = 0.0;
		for (int i = 1; i <= this->samples; ++i)
		{
			length += (this->_calcSegmentPosition(((double)(i - 1)) / this->samples, index) - this->_calcSegmentPosition(((double)i) / this->samples, index)).length();
		}
		return length;
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
		if (i3 > ((int)this->points.size() - 1))
		{
			i3 = this->points.size() - 1;
		}
		double t2 = t * t;
		double t3 = t2 * t;
		Vector3 position = this->points[i0] * (float)(-t * this->curvature + t2 * 2.0 * this->curvature - t3 * this->curvature) +
						   this->points[i1] * (float)(1.0 + t2 * (this->curvature - 3.0) + t3 * (2.0 - this->curvature)) +
						   this->points[i2] * (float)(t * this->curvature + t2 * (3.0 - 2.0 * this->curvature) + t3 * (this->curvature - 2.0)) +
						   this->points[i3] * (float)(t3 * this->curvature - t2 * this->curvature);
		return position;
	}

	Vector3 CatmullRomSpline3::_calcSegmentTangent(double t, int index)
	{
		double t2 = t * t;
		Vector3 tangent = this->points[index - 1] * (float)(-this->curvature + 4.0 * this->curvature * t - 3.0 * this->curvature * t2) +
						  this->points[index] * (float)(2.0 * (this->curvature - 3.0) * t + 3.0 * (2.0 - this->curvature) * t2) +
						  this->points[index + 1] * (float)(this->curvature + 2.0 * (3.0 - 2.0 * this->curvature) * t + 3.0 * (this->curvature - 2.0) * t2) +
						  this->points[index + 2] * (float)(-2.0 * this->curvature * t + 3.0 * this->curvature * t2);
		return tangent.normalized();
	}
	
	Vector3 CatmullRomSpline3::_calcSegmentNormal(double t, int index)
	{
		double t2 = t * t;
		Vector3 tmp1 = this->points[index - 1] * (float)(-this->curvature + 4.0 * this->curvature * t - 3.0 * this->curvature * t2) +
					   this->points[index] * (float)(2.0 * (this->curvature - 3.0) * t + 3.0 * (2.0 - this->curvature) * t2) +
					   this->points[index + 1] * (float)(this->curvature + 2.0 * (3.0 - 2.0 * this->curvature) * t + 3.0 * (this->curvature - 2.0) * t2) +
					   this->points[index + 2] * (float)(-2.0 * this->curvature * t + 3.0 * this->curvature * t2);
		tmp1.normalize();
		Vector3 tmp2 = this->points[index - 1] * (float)(4.0 * this->curvature - 6.0 * this->curvature * t) +
					   this->points[index] * (float)(2.0 * (this->curvature - 3.0) + 6.0 * (2.0 - this->curvature) * t) +
					   this->points[index + 1] * (float)(2.0 * (3.0 - 2.0 * this->curvature) + 6.0 * (this->curvature - 2.0) * t) +
					   this->points[index + 2] * (float)(-2.0 * this->curvature + 6.0 * this->curvature * t);
		Vector3 normal(tmp2 - tmp1 * tmp2.dot(tmp1));
		normal.normalize();
		double dot = normal.dot(this->_prevNormal);
		if (dot <= -0.982 && dot >= -1.018)
		{
			this->_inflexed = !this->_inflexed;
		}
		this->_prevNormal = normal;
		if (this->_inflexed)
		{
			normal = -normal;
		}
		return normal;
	}
	
	void CatmullRomSpline3::_arcLengthReparametrization()
	{
		this->_arcLengths.clear();
		double prevLength = 0.0;
		for (unsigned int i = 0; i < this->lengths.size(); ++i)
		{
			this->_arcLengths[prevLength + (this->lengths[i] / this->length)] = i;
			prevLength += this->lengths[i] / this->length;
		}
	}

}
