/// @file
/// @author  Domagoj Cerjan
/// @version 1.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// DOCUMENT ME

#ifndef GTYPES_LINKED_LERP3_H
#define GTYPES_LINKED_LERP3_H

#include "gtypesExport.h"
#include "Vector3.h"
#include <vector>
#include <list>
#include <map>

namespace gtypes
{

	class gtypesExport LinkedLERP3
	{

	public:
	
		std::vector<gvec3> points;
		std::map<double, int> _arcLengthMap;
		float len;
	
		LinkedLERP3();
		LinkedLERP3(const std::vector<gvec3>& points);
		LinkedLERP3(const std::list<gvec3>& points);
		LinkedLERP3(gvec3* points, int n);
		~LinkedLERP3();
		
		void addPoint(gvec3 point);
		
		gvec3 getPosition(float t);
		gvec3 getTangent(float t);
		
		float getLen();

	};

}

#endif // _GTYPES_LINKEDLERP3_H_
