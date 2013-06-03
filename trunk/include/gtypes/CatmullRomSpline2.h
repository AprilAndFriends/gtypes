/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
/// @version 1.4
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// DOCUMENT ME

#ifndef GTYPES_SPLINE2_H
#define GTYPES_SPLINE2_H

#include <map>
#include <vector>

#include "Vector2.h"

#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport CatmullRomSpline2
	{
	public:
		CatmullRomSpline2();
		CatmullRomSpline2(std::vector<Vector2>& vectors, int closed = 0, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());
		CatmullRomSpline2(Vector2 vectors[], int n, int closed = 0, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());
		~CatmullRomSpline2();
		
		Vector2 calcPosition(double t);
		Vector2 calcTangent(double t);
		Vector2 calcNormal(double t);
		
		Vector2 getTangent() const;
		Vector2 getNormal() const;
		
		void addPoint(Vector2 point);
		void addPoint(float x, float y);
		
		void compile(std::vector<Vector2>& vectors, int closed = 0, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());
		void compile(Vector2 vectors[], int n, int closed = 0, Vector2 t1 = Vector2(), Vector2 t2 = Vector2());
		
		void setLengthSamplingRate(int r);
		void setCurvature(double c);
		
		double getLength() const;
		int getNumPoints() const;
	
	protected:
		int _numSamples;
		int _numSegments;
		int _closed;
		double _length;
		double _c;
		
		bool _inflexed;
		Vector2 _prevNor;
		double _prevDot;
		
		std::vector<Vector2> _points;
		std::vector<double> _lengths;
		
		std::map<double, int> _arcLengthMap;
		int _prevIndex;
		double _prevlen;
	
		double _calcLength();
		double _calcSegmentLength(int index);
		Vector2 _calcSegmentPosition(double t, int index);
		Vector2 _calcSegmentTangent(double t, int index);
		Vector2 _calcSegmentNormal(double t, int index);
		void _arcLengthReparametrization();

	};

}

typedef gtypes::CatmullRomSpline2 gcrs2;

#endif // GTYPES_SPLINE2_H
