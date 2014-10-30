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
#include <vector>

#include "gtypesExport.h"
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
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		CatmullRomSpline3(const std::vector<Vector3>& vectors, bool closed = false, int samples = 16, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		/// @brief Constructor.
		/// @param[in] vectors Array of points in 3D space to define the CatmullRomSpline3.
		/// @param[in] n Number of points in vectors.
		/// @param[in] closed Whether the CatmullRomSpline3 is closed.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		CatmullRomSpline3(const Vector3 vectors[], int n, bool closed = false, int samples = 16, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		/// @brief Destructor.
		~CatmullRomSpline3();
		
		/// @brief Sets the CatmullRomSpline3's values.
		/// @param[in] vectors Points in 3D space to define the CatmullRomSpline3.
		/// @param[in] closed Whether the CatmullRomSpline3 is closed.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		void set(const std::vector<Vector3>& vectors, bool closed = false, int samples = 16, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		/// @brief Sets the CatmullRomSpline3's values.
		/// @param[in] vectors Array of points in 3D space to define the CatmullRomSpline3.
		/// @param[in] n Number of points in vectors.
		/// @param[in] closed Whether the CatmullRomSpline3 is closed.
		/// @param[in] samples How many samples to use for calculation.
		/// @param[in] t1 Custom beginning point.
		/// @param[in] t2 Custom ending point.
		void set(const Vector3 vectors[], int n, bool closed = false, int samples = 16, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());

		/// @return The length of the CatmullRomSpline3.
		inline double getLength() const { return this->length; }
		/// @return True if the CatmullRomSpline3 is closed.
		inline bool isClosed() const { return this->closed; }
		
		/// @brief Calculates the position of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 position.
		/// @note t is in range [0,1].
		Vector3 calcPosition(double t);
		/// @brief Calculates the tangent of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 tangent.
		/// @note t is in range [0,1].
		Vector3 calcTangent(double t);
		/// @brief Calculates the static tangent of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 static tangent.
		/// @note t is in range [0,1].
		Vector3 calcStaticTangent(double t);
		/// @brief Calculates the normal of a point on the CatmullRomSpline3.
		/// @param[in] t Segment range position.
		/// @return Vector3 normal.
		/// @note t is in range [0,1].
		Vector3 calcNormal(double t);

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
		Vector3 _calcSegmentPosition(double t, int index);
		/// @brief Calculates the tangent of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The tangent of a segment.
		/// @note t is in range [0,1].
		Vector3 _calcSegmentTangent(double t, int index);
		/// @brief Calculates the normal of a segment.
		/// @param[in] t Segment range position.
		/// @param[in] index Index of the segment.
		/// @return The normal of a segment.
		/// @note t is in range [0,1].
		Vector3 _calcSegmentNormal(double t, int index);
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
