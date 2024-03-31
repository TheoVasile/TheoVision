#include "aabb.h"

AABB::AABB(vec3 min, vec3 max) {
    this->min = min;
    this->max = max;
}

void AABB::update(vec3 point) {
    min.x = std::min(min.x, point.x);
    min.y = std::min(min.y, point.y);
    min.z = std::min(min.z, point.z);

    max.x = std::max(max.x, point.x);
    max.y = std::max(max.y, point.y);
    max.z = std::max(max.z, point.z);
}