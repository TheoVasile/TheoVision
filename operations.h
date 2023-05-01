#include <iostream>
#include <array>
#include <math.h>

using namespace std;

float magnitude(array<float, 3> vector);
array<float, 3> normalize(array<float, 3> vector);
array<float, 3> cross(array<float, 3> vector1, array<float, 3> vector2);
float dot(array<float, 3> vector1, array<float, 3> vector2);
array<float, 3> project_onto_plane(array<float, 3> dir, array<float, 3> normal);