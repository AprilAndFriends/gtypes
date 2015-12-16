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
/// Represents a Catmull Rom Spline in 2D space.

#ifndef GTYPES_CATMULL_ROM_SPLINE_2_H
#define GTYPES_CATMULL_ROM_SPLINE_2_H

#include <map>
#include <vector>

#include "gtypesExport.h"
#include "Vector2.h"

namespace gtypes
{
	/// @brief Represents a Catmull Rom Spline in 2D space.
	class gtypesExport CatmullRomSpline2
	{
	public:
		/// @brief Basic Constructor.
		CatmullRomSpline2();
		/// @brief Constructor.
		/// @param[in] vectors Points in 2D space to define the CatmullRomSpline2.
		/// @param[in] closed Whether the CatmullRomSpline2 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline2.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		CatmullRomSpline2(const std::vector<Vector2>& vectors, bool closed = false, double curvature = 0.5, int samples = 16, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());
		/// @brief Constructor.
		/// @param[in] vectors Array of points in 2D space to define the CatmullRomSpline2.
		/// @param[in] n Number of points in vectors.
		/// @param[in] closed Whether the CatmullRomSpline2 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline2.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		CatmullRomSpline2(const Vector2 vectors[], int n, bool closed = false, double curvature = 0.5, int samples = 16, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());

		/// @brief Sets the CatmullRomSpline2's values.
		/// @param[in] vectors Points in 2D space to define the CatmullRomSpline2.
		/// @param[in] closed Whether the CatmullRomSpline2 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline2.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		void set(const std::vector<Vector2>& vectors, bool closed = false, double curvature = 0.5, int samples = 16, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());
		/// @brief Sets the CatmullRomSpline2's values.
		/// @param[in] vectors Array of points in 2D space to define the CatmullRomSpline2.
		/// @param[in] n Number of points in vectors.
		/// @param[in] closed Whether the CatmullRomSpline2 is closed.
		/// @param[in] curvature Curvature of the CatmullRomSpline2.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		void set(const Vector2 vectors[], int n, bool closed = false, double curvature = 0.5, int samples = 16, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());

		/// @return The length of the CatmullRomSpline2.
		inline double getLength() const { return this->length; }
		/// @return True if the CatmullRomSpline2 is closed.
		inline bool isClosed() const { return this->closed; }
		/// @return The points of the CatmullRomSpline2.
		inline const std::vector<Vector2>& getPoints() const { return this->points; }

		/// @brief Calculates the position of a point on the CatmullRomSpline2.
		/// @param[in] t Segment range position.
		/// @return Vector2 position.
		/// @note t is in range [0,1].
		Vector2 calcPosition(double t);
		/// @brief Calculates the tangent of a point on the CatmullRomSpline2.
		/// @param[in] t Segment range position.
		/// @return Vector2 tangent.
		/// @note t is in range [0,1].
		Vector2 calcTangent(double t);
		/// @brief Calculates the static tangent of a point on the CatmullRomSpline2.
		/// @param[in] t Segment range position.
		/// @return Vector2 static tangent.
		/// @note t is in range [0,1].
		Vector2 calcStaticTangent(double t);
		/// @brief Calculates the normal of a point on the CatmullRomSpline2.
		/// @param[in] t Segment range position.
		/// @return Vector2 normal.
		/// @note t is in range [0,1].
		Vector2 calcNormal(double t);

	protected:
		/// @brief Whether the CatmullRomSpline2 is closed.
		bool closed;
		/// @brief The length.
		double length;
		/// @brief The curvature parameter.
		double curvature;
		/// @brief The number of samples used for calculating the CatmullRomSpline2.
		int samples;
		/// @brief The points defining the CatmullRomSpline2.
		std::vector<Vector2> points;
		/// @brief The lengths of all segments.
		std::vector<double> lengths;

		/// @brief Pre-calculates the length as length-calculation is expensive.
		/// @return The length.
		double _calcLength();
		/// @brief Calculates the length of a segment.
		/// @param[in] index Index of the segment.
		/// @return The length of a segment.
		double _calcSegmentLength(int index);
		/// @brief Calculates the position of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The position of a segment.
		/// @note t is in range [0,1].
		Vector2 _calcSegmentPosition(double t, int index);
		/// @brief Calculates the tangent of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The tangent of a segment.
		/// @note t is in range [0,1].
		Vector2 _calcSegmentTangent(double t, int index);
		/// @brief Calculates the normal of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The normal of a segment.
		/// @note t is in range [0,1].
		Vector2 _calcSegmentNormal(double t, int index);
		/// @brief Reparametrizes the lengths of a each arc.
		void _arcLengthReparametrization();

	private:
		/// @brief Previously stored index for length-calculation.
		/// @note Used internally only.
		int _prevIndex;
		/// @brief Previously calculated length.
		/// @note Used internally only.
		double _prevLength;
		/// @brief Previously calculated tangent
		/// @note Used internally only.
		Vector2 _prevTangent;
		/// @brief The length of every arc.
		/// @note Used internally only.
		std::map<double, int> _arcLengths;

	};

}

typedef gtypes::CatmullRomSpline2 gcrs2;

#endif
