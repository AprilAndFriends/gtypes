/// @file
/// @version 1.6
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
	CatmullRomSpline2::CatmullRomSpline2() :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevLength(0.0), _prevIndex(-1)
	{
	}

	CatmullRomSpline2::CatmullRomSpline2(const std::vector<Vector2>& vectors, bool closed, int samples, Vector2 t1, Vector2 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevLength(0.0), _prevIndex(-1)
	{
		this->set(vectors, closed, samples, t1, t2);
	}

	CatmullRomSpline2::CatmullRomSpline2(const Vector2 vectors[], int n, bool closed, int samples, Vector2 t1, Vector2 t2) :
		closed(false), length(0.0), curvature(0.5), samples(16), _prevLength(0.0), _prevIndex(-1)
	{
		this->set(vectors, n, closed, samples, t1, t2);
	}

	CatmullRomSpline2::~CatmullRomSpline2()
	{
	}

	void CatmullRomSpline2::set(const Vector2 vectors[], int n, bool closed, int samples, Vector2 t1, Vector2 t2)
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
		this->_prevTangent = Vector2(this->calcPosition(0.01) - this->calcPosition(0.0)).normalized();
		this->_calcLength();
	}

	void CatmullRomSpline2::set(const std::vector<Vector2>& vectors, bool closed, int samples, Vector2 t1, Vector2 t2)
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
		this->_prevTangent = Vector2(this->calcPosition(0.01) - this->calcPosition(0.0)).normalized();
		this->_calcLength();
	}

	Vector2 CatmullRomSpline2::calcPosition(double t)
	{
		if (this->points.size() == 0)
		{
			return Vector2();
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

	Vector2 CatmullRomSpline2::calcTangent(double t)
	{
		if (this->points.size() == 0)
		{
			return Vector2();
		}
		if (t <= 0.989 || this->closed)
		{
			this->_prevTangent = Vector2(this->calcPosition(t + 0.01) - this->calcPosition(t)).normalized();
		}
		return this->_prevTangent;
	}

	Vector2 CatmullRomSpline2::calcStaticTangent(double t)
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

	Vector2 CatmullRomSpline2::calcNormal(double t)
	{
		if (this->points.size() == 0)
		{
			return Vector2();
		}
		Vector2 normal = this->calcTangent(t);
		normal.set(-normal.y, normal.x);
		return normal;
	}

	double CatmullRomSpline2::_calcLength()
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

	double CatmullRomSpline2::_calcSegmentLength(int index)
	{
		double length = 0.0;
		for (int i = 1; i <= this->samples; ++i)
		{
			length += (this->_calcSegmentPosition(((double)(i - 1)) / this->samples, index) - this->_calcSegmentPosition(((double)i) / this->samples, index)).length();
		}
		return length;
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
		if (i3 >((int)this->points.size() - 1))
		{
			i3 = this->points.size() - 1;
		}
		double t2 = t * t;
		double t3 = t2 * t;
		Vector2 position = this->points[i0] * (float)(-t * this->curvature + t2 * 2.0 * this->curvature - t3 * this->curvature) +
						   this->points[i1] * (float)(1.0 + t2 * (this->curvature - 3.0) + t3 * (2.0 - this->curvature)) +
						   this->points[i2] * (float)(t * this->curvature + t2 * (3.0 - 2.0 * this->curvature) + t3 * (this->curvature - 2.0)) +
						   this->points[i3] * (float)(t3 * this->curvature - t2 * this->curvature);
		return position;
	}

	Vector2 CatmullRomSpline2::_calcSegmentTangent(double t, int index)
	{
		double t2 = t * t;
		Vector2 tangent = this->points[index - 1] * (float)(-this->curvature + 4.0 * this->curvature * t - 3.0 * this->curvature * t2) +
						  this->points[index] * (float)(2.0 * (this->curvature - 3.0) * t + 3.0 * (2.0 - this->curvature) * t2) +
						  this->points[index + 1] * (float)(this->curvature + 2.0 * (3.0 - 2.0 * this->curvature) * t + 3.0 * (this->curvature - 2.0) * t2) +
						  this->points[index + 2] * (float)(-2.0 * this->curvature * t + 3.0 * this->curvature * t2);
		return tangent.normalized();
	}

	Vector2 CatmullRomSpline2::_calcSegmentNormal(double t, int index)
	{
		Vector2 normal = this->_calcSegmentTangent(t, index);
		normal.set(-normal.y, normal.x);
		return normal;
	}

	void CatmullRomSpline2::_arcLengthReparametrization()
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
