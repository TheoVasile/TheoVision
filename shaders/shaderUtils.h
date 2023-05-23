#ifndef SHADERUTILS_H
#define SHADERUTILS_H

#include <array>
#include <iostream>
#include "../objects/bmesh.h"
#include "../utils.h"

using namespace std;

/**
 * Determines where a ray hits a mesh
 * 
 * @param mesh The mesh to check collisions with.
 * @param pos The position the ray starts from.
 * @param direction The direction the ray goes to.
 * @return a float array containing the coordinates of where the ray hit the mesh.
 */
//array<float, 3> castRay(Mesh *mesh, array<float, 3> pos, array<float, 3> direction);

/**
 * Calculates the normal of a tri
 * 
 * @param tri An array with 3 float arrays representing coordinates of points.
 * @return A float array with the normal of the face made up by the given points
 */
array<float, 3> getNormal(array<array<float, 3>, 3> tri);

/**
 * Determines where a ray hits a face
 * 
 * @param face The face to check collisions with.
 * @param pos The position the ray starts from.
 * @param direction The direction the ray goes to.
 * @return a float array containing the coordinates of where the ray hit the mesh.
 */
//array<float, 3> castRay(Face *face, array<float, 3> pos, array<float, 3> direction);


#endif