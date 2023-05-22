#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <array>
#include <vector>
#include <math.h>

#define PI 3.1415

using namespace std;

float dist(array<float, 3> startPos, array<float, 3> endPos);
int sign(float val);
float magnitude(array<float, 3> vector);
array<float, 3> normalize(array<float, 3> vector);
array<float, 3> cross(array<float, 3> vector1, array<float, 3> vector2);
float dot(array<float, 3> vector1, array<float, 3> vector2);
array<float, 3> project_onto_plane(array<float, 3> dir, array<float, 3> normal);
array<float, 3> Rotate(array<float, 3> pos, array<float, 3> rot);
#endif