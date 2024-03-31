#ifndef AABB_H
#define AABB_H
#include <math.h>
#include <glm/glm.hpp>
#include <iostream>

using namespace glm;
using namespace std;

// Axis Aligned Bounding Box, the minimum box that contains all desired points
class AABB {
    public:
        AABB(vec3 min, vec3 max);
        void update(vec3 point); // Add a point for the AABB to encompass
    private:
        // min and max points the AABB contains
        vec3 min;
        vec3 max;
};
#endif