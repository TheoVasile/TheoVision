#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <array>
#include <vector>
#include <math.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

/**
 * Projects a direction vector onto a plane defined by its normal.
 * 
 * @param dir: The direction vector to be projected.
 * @param normal: The normal vector of the plane.
 * @return The projection of dir onto the plane defined by normal.
 */
vec3 project_onto_plane(vec3 dir, vec3 normal);

/**
 * Rotates a position vector according to the given rotation vector.
 * 
 * @param pos: The position vector to be rotated.
 * @param rot: The rotation vector specifying the rotation angles around x, y, and z axes.
 * @return The rotated position vector.
 */
vec3 Rotate(vec3 pos, vec3 rot);

vec3 getNormal(array<vec3, 3> tri);

#endif