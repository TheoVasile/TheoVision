#include "operations.h"

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