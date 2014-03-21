/// @file
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
/// Provides utility functions and macros.

#ifndef GTYPES_UTIL_H
#define GTYPES_UTIL_H

/// @brief Converts degrees into radians.
/// @param[in] degrees Angle in degrees.
/// @return Angle in radians.
#define DEG_TO_RAD(degrees) ((degrees) * 0.01745329251994329576923690768489)
/// @brief Converts radians into degrees.
/// @param[in] radians Angle in radians.
/// @return Angle in degrees.
#define RAD_TO_DEG(radians) ((radians) * 57.295779513082320876798154814105)

/// @brief gtypes e-tolerance.
#define G_E_TOLERANCE 0.000001

/// @brief Provides a simpler syntax to iterate through an std::list.
#define foreach_stdlist(type, name, container) for (std::list<type>::iterator name = (container).begin(); name != (container).end(); ++name)
/// @brief Provides a simpler syntax to iterate through an std::vector.
#define foreach_stdvector(type, name, container) for (std::vector<type>::iterator name = (container).begin(); name != (container).end(); ++name)
/// @brief Provides a simpler syntax to iterate through an std::map.
#define foreach_stdmap(type_key, type_value, name, container) for (std::map<type_key, type_value>::iterator name = container.begin(); name != container.end(); ++name)

#endif
