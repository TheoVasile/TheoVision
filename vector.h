#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <iostream>
#include "utils.h"

using namespace std;

class Vector{
    public:
        Vector(array<float, 3> pos, array<float, 3> direction);
        array<float, 3> getPoint(float t);
        array<float, 3> pos;
        array<float, 3> direction;
};

#endif