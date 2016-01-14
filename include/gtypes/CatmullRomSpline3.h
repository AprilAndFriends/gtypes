/// @file
/// @version 1.6
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Represents a Catmull Rom Spline in 3D space.

#ifndef GTYPES_CATMULL_ROM_SPLINE_3_H
#define GTYPES_CATMULL_ROM_SPLINE_3_H

#include <map>
#include <math.h>
#include <stdio.h>
#include <vector>

#include "gtypesExport.h"
#include "gtypesUtil.h"
#include "Vector3.h"

namespace gtypes
{
	/// @brief Represents a Catmull Rom Spline in 3D space.
	class gtypesExport CatmullRomSpline3
	{
	public:
		/// @brief Basic Constructor.
		CatmullRomSpline3();
		/// @brief Constructor.
		/// @param[in] vectors Points in 3D space to define the CatmullRomSpline3.
		/// @param[in] closed Whether the CatmullRomSpline3 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline3.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		CatmullRomSpline3(const std::vector<Vector3>& vectors, bool closed = false, double curvature = 0.5, int samples = 16, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		/// @brief Constructor.
		/// @param[in] vectors Array of points in 3D space to define the CatmullRomSpline3.
		/// @param[in] n Number of points in vectors.
		/// @param[in] closed Whether the CatmullRomSpline3 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline3.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		CatmullRomSpline3(const Vector3 vectors[], int n, bool closed = false, double curvature = 0.5, int samples = 16, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		
		/// @brief Sets the CatmullRomSpline3's values.
		/// @param[in] vectors Points in 3D space to define the CatmullRomSpline3.
		/// @param[in] closed Whether the CatmullRomSpline3 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline3.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		inline void set(const std::vector<Vector3>& vectors, bool closed, double curvature, int samples, Vector3 t1, Vector3 t2)
		{
			this->points.clear();
			this->lengths.clear();
			this->_arcLengths.clear();
			this->closed = closed;
			this->curvature = curvature;
			this->samples = samples;
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
		/// @brief Sets the CatmullRomSpline3's values.
		/// @param[in] vectors Array of points in 3D space to define the CatmullRomSpline3.
		/// @param[in] n Number of points in vectors.
		/// @param[in] closed Whether the CatmullRomSpline3 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline3.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		inline void set(const Vector3 vectors[], int n, bool closed, double curvature, int samples, Vector3 t1, Vector3 t2)
		{
			this->points.clear();
			this->lengths.clear();
			this->_arcLengths.clear();
			this->closed = closed;
			this->curvature = curvature;
			this->samples = samples;
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

		/// @return The length of the CatmullRomSpline3.
		inline double getLength() const { return this->length; }
		/// @return True if the CatmullRomSpline3 is closed.
		inline bool isClosed() const { return this->closed; }
		/// @return The points of the CatmullRomSpline3.
		inline const std::vector<Vector3>& getPoints() const { return this->points; }

		/// @brief Calculates the position of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 position.
		/// @note t is in range [0,1].
		inline Vector3 calcPosition(double t)
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
			foreach_stdmap(double, int, it, this->_arcLengths)
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
		/// @brief Calculates the tangent of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 tangent.
		/// @note t is in range [0,1].
		inline Vector3 calcTangent(double t)
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
		/// @brief Calculates the static tangent of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 static tangent.
		/// @note t is in range [0,1].
		inline Vector3 calcStaticTangent(double t)
		{
			int index = 0;
			foreach_stdmap(double, int, it, this->_arcLengths)
			{
				if ((t >= this->_prevLength) && (t < (it->first)))
				{
					index = it->second;
					break;
				}
				this->_prevIndex = it->second;
				this->_prevLength = it->first;
			}
			return (this->points[index + 2] - this->points[index + 1]).normalized();
		}
		/// @brief Calculates the normal of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 normal.
		/// @note t is in range [0,1].
		inline Vector3 calcNormal(double t)
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

	protected:
		/// @brief Whether the CatmullRomSpline3 is closed.
		bool closed;
		/// @brief The length.
		double length;
		/// @brief The curvature parameter.
		double curvature;
		/// @brief The number of samples used for calculating the CatmullRomSpline3.
		int samples;
		/// @brief The points defining the CatmullRomSpline3.
		std::vector<Vector3> points;
		/// @brief The lengths of all segments.
		std::vector<double> lengths;

		/// @brief Pre-calculates the length as length-calculation is expensive.
		/// @return The length.
		inline double _calcLength()
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
		/// @brief Calculates the length of a segment.
		/// @param[in] index Index of the segment.
		/// @return The length of a segment.
		inline double _calcSegmentLength(int index)
		{
			double length = 0.0;
			for (int i = 1; i <= this->samples; ++i)
			{
				length += (this->_calcSegmentPosition(((double)(i - 1)) / this->samples, index) - this->_calcSegmentPosition(((double)i) / this->samples, index)).length();
			}
			return length;
		}
		/// @brief Calculates the position of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The position of a segment.
		/// @note t is in range [0,1].
		inline Vector3 _calcSegmentPosition(double t, int index)
		{
			int i0 = index - 1;
			int i1 = index;
			int i2 = index + 1;
			int i3 = index + 2;
			int psize = (int)this->points.size();
			if (i0 < 0)
			{
				i0 = 0;
			}
			if (i3 >(psize - 1))
			{
				i3 = psize - 1;
			}
			double t2 = t * t;
			double t3 = t2 * t;
			Vector3 position = this->points[i0] * (float)(-t * this->curvature + t2 * 2.0 * this->curvature - t3 * this->curvature) +
				this->points[i1] * (float)(1.0 + t2 * (this->curvature - 3.0) + t3 * (2.0 - this->curvature)) +
				this->points[i2] * (float)(t * this->curvature + t2 * (3.0 - 2.0 * this->curvature) + t3 * (this->curvature - 2.0)) +
				this->points[i3] * (float)(t3 * this->curvature - t2 * this->curvature);
			return position;
		}
		/// @brief Calculates the tangent of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The tangent of a segment.
		/// @note t is in range [0,1].
		inline Vector3 _calcSegmentTangent(double t, int index)
		{
			double t2 = t * t;
			Vector3 tangent = this->points[index - 1] * (float)(-this->curvature + 4.0 * this->curvature * t - 3.0 * this->curvature * t2) +
				this->points[index] * (float)(2.0 * (this->curvature - 3.0) * t + 3.0 * (2.0 - this->curvature) * t2) +
				this->points[index + 1] * (float)(this->curvature + 2.0 * (3.0 - 2.0 * this->curvature) * t + 3.0 * (this->curvature - 2.0) * t2) +
				this->points[index + 2] * (float)(-2.0 * this->curvature * t + 3.0 * this->curvature * t2);
			return tangent.normalized();
		}
		/// @brief Calculates the normal of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The normal of a segment.
		/// @note t is in range [0,1].
		inline Vector3 _calcSegmentNormal(double t, int index)
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
		/// @brief Reparametrizes the lengths of a each arc.
		inline void _arcLengthReparametrization()
		{
			this->_arcLengths.clear();
			double prevLength = 0.0;
			for (unsigned int i = 0; i < this->lengths.size(); ++i)
			{
				this->_arcLengths[prevLength + (this->lengths[i] / this->length)] = i;
				prevLength += this->lengths[i] / this->length;
			}
		}

	private:
		/// @brief Previously stored index for length-calculation.
		/// @note Used internally only.
		int _prevIndex;
		/// @brief Previously calculated length.
		/// @note Used internally only.
		double _prevLength;
		/// @brief Previously calculated tangent
		/// @note Used internally only.
		Vector3 _prevTangent;
		/// @brief The length of every arc.
		/// @note Used internally only.
		std::map<double, int> _arcLengths;
		/// @brief Previously calculated dot-product for normal-calculation.
		/// @note Used internally only.
		double _prevDot;
		/// @brief Previously calculated normal.
		/// @note Used internally only.
		Vector3 _prevNormal;
		/// @brief Whether the normal is inflexed.
		/// @note Used internally only.
		bool _inflexed;

	};

}

typedef gtypes::CatmullRomSpline3 gcrs3;

#endif
