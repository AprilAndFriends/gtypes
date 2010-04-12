/************************************************************************************\
* This source file is part of the C++ Geometry Types Library (libgtypes)             *
* For latest info, see http://libgtypes.sourceforge.net/                             *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef GTYPES_MATRIX4
#define GTYPES_MATRIX4

namespace gtypes
{

	class Matrix4
	{
	public:
		Matrix4();
		~Matrix4();
		
	};

}

#ifdef GTYPES_ABREV

namespace gt
{
	typedef gtypes::Matrix4 mat4;
}

#endif // GTYPES_ABREV

#endif // GTYPES_MATRIX4
