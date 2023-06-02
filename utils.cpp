#include "utils.h"

vec3 project_onto_plane(vec3 dir, vec3 normal){
    float mag = length(dir);
    vec3 norm_dir = normalize(dir);
    double angle = acos(dot(norm_dir, normal));
    
    vec3 new_dir = cross(cross(normal, norm_dir), normal);
    float new_mag = mag * (float) sin(angle);

    new_dir *= new_mag;

    return new_dir;
}

vec3 Rotate(vec3 pos, vec3 rot){
    /*
    Return the new 3D coordinate of the provided point around the origin

    precondition: given angles of rotation must be in radians
    */
    vec3 newPos(0, 0, 0);
    newPos[0] = pos[0] * cosf(rot[1]) * cosf(rot[0]) + pos[1] * cosf(rot[1]) * sinf(rot[0]) - pos[2] * sinf(rot[1]);
    newPos[1] = pos[0] * (sinf(rot[2]) * sinf(rot[1]) * cosf(rot[0]) - cosf(rot[2]) * sinf(rot[0])) + pos[1] * (sinf(rot[2]) * sinf(rot[1]) * sinf(rot[0]) + cosf(rot[2]) * cosf(rot[0])) + pos[2] * sinf(rot[2]) * cosf(rot[1]);
    newPos[2] = pos[0] * (cosf(rot[2]) * sinf(rot[1]) * cosf(rot[0]) + sinf(rot[2]) * sinf(rot[0])) + pos[1] * (cosf(rot[2]) * sinf(rot[1]) * sinf(rot[0]) - sinf(rot[2]) * cosf(rot[0])) + pos[2] * cos(rot[2]) * cos(rot[1]);

    return newPos;
}

vec3 getNormal(array<vec3, 3> tri)
{
    vec3 v1 = normalize(tri[1] - tri[0]);
    vec3 v2 = normalize(tri[2] - tri[0]);
    return normalize(cross(v1, v2));
}