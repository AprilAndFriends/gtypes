#ifndef _GTYPES_LINKEDLERP3_H_
#define _GTYPES_LINKEDLERP3_H_

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
