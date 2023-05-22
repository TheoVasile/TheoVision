#include "operations.h"

array<float, 3> multiply(array<float, 3> vector, float coefficient)
{
    vector[0] *= coefficient;
    vector[1] *= coefficient;
    vector[2] *= coefficient;
    return vector;
}

float dist(array<float, 3> startPos, array<float, 3> endPos)
{
    return sqrt(pow((startPos[0] - endPos[0]), 2) + pow((startPos[1] - endPos[1]), 2) + pow((startPos[2] - endPos[2]), 2));
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

array<float, 3> project_onto_plane(array<float, 3> dir, array<float, 3> normal){
    float mag = magnitude(dir);
    array<float, 3> norm_dir = normalize(dir);
    double angle = acos(dot(norm_dir, normal));
    
    array<float, 3> new_dir = cross(cross(normal, norm_dir), normal);
    float new_mag = mag * (float) sin(angle);

    new_dir[0] = new_dir[0] * new_mag;
    new_dir[1] = new_dir[1] * new_mag;
    new_dir[2] = new_dir[2] * new_mag;

    return new_dir;
}

array<float, 3> Rotate(array<float, 3> pos, array<float, 3> rot){
    /*
    Return the new 3D coordinate of the provided point around the origin

    precondition: given angles of rotation must be in radians
    */
    array<float, 3> newPos;
    newPos[0] = pos[0] * cosf(rot[1]) * cosf(rot[0]) + pos[1] * cosf(rot[1]) * sinf(rot[0]) - pos[2] * sinf(rot[1]);
    newPos[1] = pos[0] * (sinf(rot[2]) * sinf(rot[1]) * cosf(rot[0]) - cosf(rot[2]) * sinf(rot[0])) + pos[1] * (sinf(rot[2]) * sinf(rot[1]) * sinf(rot[0]) + cosf(rot[2]) * cosf(rot[0])) + pos[2] * sinf(rot[2]) * cosf(rot[1]);
    newPos[2] = pos[0] * (cosf(rot[2]) * sinf(rot[1]) * cosf(rot[0]) + sinf(rot[2]) * sinf(rot[0])) + pos[1] * (cosf(rot[2]) * sinf(rot[1]) * sinf(rot[0]) - sinf(rot[2]) * cosf(rot[0])) + pos[2] * cos(rot[2]) * cos(rot[1]);

    return newPos;
}
