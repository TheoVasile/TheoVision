#include "vector.h"

Vector::Vector(array<float, 3> pos, array<float, 3> direction)
{
    this->pos = pos;
    this->direction = direction;
}

array<float, 3> Vector::getPoint(float t)
{
    return add(this->pos, multiply(this->direction, t));
}