#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <array>
#include <vector>
#include <math.h>

#define PI 3.1415

using namespace std;

/**
 * Multiplies a vector by a scalar coefficient.
 * 
 * @param vector: The input vector.
 * @param coefficient: The scalar coefficient.
 * @return The result of multiplying the vector by the coefficient.
 */
array<float, 3> multiply(array<float, 3> vector, float coefficient);

/**
 * Subtracts vector2 from vector1 element-wise.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The result of subtracting vector2 from vector1.
 */
array<float, 3> subtract(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Adds vector1 and vector2 element-wise.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The result of adding vector1 and vector2.
 */
array<float, 3> add(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Element-wise vector to the power of exponent.
 * 
 * @param vector: The input vector
 * @param exponent: What to set every element to the power of.
 * @return The result of setting every element to the power of exponent
 */
array<float, 3> power(array<float, 3> vector, float exponent);

float sum(array<float, 3> vector);

/**
 * Calculates the Euclidean distance between startPos and endPos.
 * 
 * @param startPos: The starting position.
 * @param endPos: The ending position.
 * @return The Euclidean distance between startPos and endPos.
 */
float dist(array<float, 3> startPos, array<float, 3> endPos);

/**
 * Determines the sign of a float value.
 * 
 * @param val: The input value.
 * @return 1 if val is positive or zero, -1 if val is negative.
 */
int sign(float val);

/**
 * Calculates the magnitude (length) of a vector.
 * 
 * @param vector: The input vector.
 * @return The magnitude of the vector.
 */
float magnitude(array<float, 3> vector);

/**
 * Normalizes a vector to have unit length.
 * 
 * @param vector: The input vector.
 * @return The normalized vector.
 */
array<float, 3> normalize(array<float, 3> vector);

/**
 * Calculates the cross product of two vectors.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The cross product of vector1 and vector2.
 */
array<float, 3> cross(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Calculates the dot product of two vectors.
 * 
 * @param vector1: The first input vector.
 * @param vector2: The second input vector.
 * @return The dot product of vector1 and vector2.
 */
float dot(array<float, 3> vector1, array<float, 3> vector2);

/**
 * Projects a direction vector onto a plane defined by its normal.
 * 
 * @param dir: The direction vector to be projected.
 * @param normal: The normal vector of the plane.
 * @return The projection of dir onto the plane defined by normal.
 */
array<float, 3> project_onto_plane(array<float, 3> dir, array<float, 3> normal);

/**
 * Rotates a position vector according to the given rotation vector.
 * 
 * @param pos: The position vector to be rotated.
 * @param rot: The rotation vector specifying the rotation angles around x, y, and z axes.
 * @return The rotated position vector.
 */
array<float, 3> Rotate(array<float, 3> pos, array<float, 3> rot);

#endif