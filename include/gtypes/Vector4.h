/// @file
/// @author  Domagoj Cerjan
/// @author  Kresimir Spes
/// @author  Boris Mikic
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

#ifndef GTYPES_VECTOR4_H
#define GTYPES_VECTOR4_H

#include "gtypesExport.h"

namespace gtypes
{
	class gtypesExport Vector4
	{
	public:
		float x;
		float y;
		float z;
		float w;
	
		Vector4();
		Vector4(float x, float y, float z, float w);
		Vector4(const float v[]);
		void set(float x, float y, float z, float w);

	};

}

typedef gtypes::Vector4 gvec4;

#endif // GTYPES_VECTOR4_H
