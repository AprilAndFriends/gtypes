/// @file
/// @author  Domagoj Cerjan
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

#ifndef GTYPES_SPLINE3_H
#define GTYPES_SPLINE3_H

#include <list>
#include <map>
#include <vector>

#include "Vector3.h"

#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport CatmullRomSpline3
	{
	public:
		CatmullRomSpline3();
		CatmullRomSpline3(std::vector<Vector3>& vectors, int closed = 0, Vector3 t1 = Vector3(), Vector3 t2 = Vector3() );
		CatmullRomSpline3(std::list<Vector3>& vectors, int closed = 0, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		CatmullRomSpline3(Vector3 vectors[], int n, int closed = 0, Vector3 t1 = Vector3(),  Vector3 t2 = Vector3());
		~CatmullRomSpline3();
		
		Vector3 calcPosition(double t);
		Vector3 calcTangent(double t);
		Vector3 calcStaticTangent(double t);
		Vector3 calcNormal(double t);
		
		Vector3 getTangent() const;
		Vector3 getNormal() const;
		
		void addPoint(Vector3 point);
		void addPoint(float x, float y, float z);
		
		void compile(std::vector<Vector3>& vectors, int closed = 0, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		void compile(std::list<Vector3>& vectors, int closed = 0, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		void compile(Vector3 vectors[], int n, int closed = 0, Vector3 t1 = Vector3(), Vector3 t2 = Vector3());
		
		void setLengthSamplingRate(int r);
		void setCurvature(double c);
		
		double getLength() const;
		
	protected:
		int _numSamples;
		int _numSegments;
		int _closed;
		double _length;
		double _c;
		
		bool _inflexed;
		Vector3 _prevNor;
		double _prevDot;
		
		gvec3 prevTangent;
		
		std::vector<Vector3> _points;
		std::vector<double> _lengths;
		
		std::map<double, int> _arcLengthMap;
		int _prevIndex;
		double _prevlen;
	
		double _calcLength();
		double _calcSegmentLength(int index);
		Vector3 _calcSegmentPosition(double t, int index);
		Vector3 _calcSegmentTangent(double t, int index);
		Vector3 _calcSegmentNormal(double t, int index);
		void _arcLengthReparametrization();

	};

}

typedef gtypes::CatmullRomSpline3 gcrs3;

#endif // GTYPES_SPLINE3_H
