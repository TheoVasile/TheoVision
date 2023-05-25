#ifndef SHADERUTILS_H
#define SHADERUTILS_H

#include <array>
#include <iostream>
#include "../objects/bmesh.h"
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

/**
 * Calculates the normal of a tri
 * 
 * @param tri An array with 3 float arrays representing coordinates of points.
 * @return A float array with the normal of the face made up by the given points
 */
vec3 getNormal(array<vec3, 3> tri);

#endif