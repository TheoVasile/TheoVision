#include "shaderUtils.h"

vec3 getNormal(array<vec3, 3> tri)
{
    vec3 v1 = normalize(tri[1] - tri[0]);
    vec3 v2 = normalize(tri[2] - tri[0]);
    return normalize(cross(v1, v2));
}