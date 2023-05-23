#include "shaderUtils.h"

/*
array<float, 3> castRay(Mesh *mesh, array<float, 3> pos, array<float, 3> direction)
{
    array<float, 3> finalPos;
    float minDist = 1000000000000.0;
    for (int i=0; i < mesh->getFaces().size(); i++){
        array<float, 3> currPos = castRay(mesh->getFace(i), pos, direction);
        float currDist = dist(currPos, pos);
        if (currDist < minDist){
            minDist = currDist;
            finalPos = currPos;
        }
    }
    return finalPos;
}
*/

array<float, 3> getNormal(array<array<float, 3>, 3> tri)
{
    array<float, 3> v1 = normalize(subtract(tri[1], tri[0]));
    array<float, 3> v2 = normalize(subtract(tri[2], tri[0]));
    return normalize(cross(v1, v2));
}