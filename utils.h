#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <array>
#include <vector>
#include <math.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;


//class Vector;

/**
 * Multiplies a vector by a scalar coefficient.
 * 
 * @param vector: The input vector.
 * @param coefficient: The scalar coefficient.
 * @return The result of multiplying the vector by the coefficient.
 */
//array<float, 3> multiply(array<float, 3> vector, float coefficient);

/**
 * Elementwise multiplication of the vectors.
 * 
 * @param vector1 The first input vector
 * @param vector2 The second input vector
 * @return The result of multiplying each element of vector1 with the corresponding element of vector2
 */
//array<float, 3> multiply(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Subtracts vector2 from vector1 element-wise.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The result of subtracting vector2 from vector1.
 */
//array<float, 3> subtract(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Adds vector1 and vector2 element-wise.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The result of adding vector1 and vector2.
 */
//array<float, 3> add(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Element-wise vector to the power of exponent.
 * 
 * @param vector: The input vector
 * @param exponent: What to set every element to the power of.
 * @return The result of setting every element to the power of exponent
 */
//array<float, 3> power(array<float, 3> vector, float exponent);

//float sum(array<float, 3> vector);

/**
 * Calculates the Euclidean distance between startPos and endPos.
 * 
 * @param startPos: The starting position.
 * @param endPos: The ending position.
 * @return The Euclidean distance between startPos and endPos.
 */
//float dist(array<float, 3> startPos, array<float, 3> endPos);

/**
 * Determines the sign of a float value.
 * 
 * @param val: The input value.
 * @return 1 if val is positive or zero, -1 if val is negative.
 */
//int sign(float val);

/**
 * Calculates the magnitude (length) of a vector.
 * 
 * @param vector: The input vector.
 * @return The magnitude of the vector.
 */
//float magnitude(array<float, 3> vector);

/**
 * Calculates the magnitude (length) of a vector.
 * 
 * @param vector: The input vector.
 * @return The magnitude of the vector.
 */
//float magnitude(Vector *vector);

/**
 * Normalizes a vector to have unit length.
 * 
 * @param vector: The input vector.
 * @return The normalized vector.
 */
//array<float, 3> normalize(array<float, 3> vector);

/**
 * Calculates the cross product of two vectors.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The cross product of vector1 and vector2.
 */
//array<float, 3> cross(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Calculates the dot product of two vectors.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The dot product of vector1 and vector2.
 */
//float dot(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Projects a direction vector onto a plane defined by its normal.
 * 
 * @param dir: The direction vector to be projected.
 * @param normal: The normal vector of the plane.
 * @return The projection of dir onto the plane defined by normal.
 */
vec3 project_onto_plane(vec3 dir, vec3 normal);

/**
 * Finds the point of intersection between 2 lines
 * 
 * @param vector1 The first input vector
 * @param vector2 The second input vector
 * @return The point of intersection between vector1 and vector2
 */
//array<float, 3> collideLines(Vector *vector1, Vector *vector2);

/**
 * Rotates a position vector according to the given rotation vector.
 * 
 * @param pos: The position vector to be rotated.
 * @param rot: The rotation vector specifying the rotation angles around x, y, and z axes.
 * @return The rotated position vector.
 */
vec3 Rotate(vec3 pos, vec3 rot);

#endif