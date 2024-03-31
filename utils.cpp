#include "utils.h"

/*
array<float, 3> multiply(array<float, 3> vector, float coefficient)
{
    array<float, 3> vector2 = {coefficient, coefficient, coefficient};
    return multiply(vector, vector2);
}

array<float, 3> multiply(array<float, 3> vector1, array<float, 3> vector2)
{
    vector1[0] *= vector2[0];
    vector1[1] *= vector2[1];
    vector1[2] *= vector2[2];
    return vector1;
}

array<float, 3> subtract(array<float, 3> vector1, array<float, 3> vector2)
{
    vector1[0] -= vector2[0];
    vector1[1] -= vector2[1];
    vector1[2] -= vector2[2];
    return vector1;
}

array<float, 3> add(array<float, 3> vector1, array<float, 3> vector2)
{
    vector1[0] += vector2[0];
    vector1[1] += vector2[1];
    vector1[2] += vector2[2];
    return vector1;
}

array<float, 3> power(array<float, 3> vector, float exponent)
{
    vector[0] = pow(vector[0], exponent);
    vector[1] = pow(vector[1], exponent);
    vector[2] = pow(vector[2], exponent);
    return vector;
}

float sum(array<float, 3> vector)
{
    return vector[0] + vector[1] + vector[2];
}

float dist(array<float, 3> startPos, array<float, 3> endPos)
{
    return sqrt(sum(power(subtract(startPos, endPos), 2)));
}

int sign(float val){
    if (val > 0){
        return 1;
    } else if (val < 0){
        return -1;
    }
    return 0;
}

float magnitude(array<float, 3> vector){
    return pow(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2), 0.5);
}
float magnitude(Vector *vector){
    return magnitude(vector->direction);
}

array<float, 3> normalize(array<float, 3> vector){
    float mag;
    mag = magnitude(vector);
    if (mag != 0){
        vector[0] = vector[0] / mag;
        vector[1] = vector[1] / mag;
        vector[2] = vector[2] / mag;
    }
    return vector;
}

array<float, 3> cross(array<float, 3> vector1, array<float, 3> vector2){
    array<float, 3> cross_product;
    cross_product[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    cross_product[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    cross_product[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
    return cross_product;
}

float dot(array<float, 3> vector1, array<float, 3> vector2){
    return vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] * vector2[2];
}

array<float, 3> collideLines(Vector *vector1, Vector *vector2)
{
    float t = (vector2->pos[1] - vector1->pos[1] - vector1->direction[0] / vector1->direction[1] * (vector2->pos[0] - vector1->pos[0])) / (vector1->direction[0] / vector1->direction[1] * vector2->direction[0] - vector2->direction[1]);
    if (vector1->getPoint(t)[2] == vector2->getPoint(t)[2]){
        return vector1->getPoint(t);
    }
    return {};
}
*/
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