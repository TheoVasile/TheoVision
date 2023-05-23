#ifndef RAY_H
#define RAY_H

#include <array>
#include <vector>
#include <limits>
#include <iostream>
#include "../vector.h"
#include "ray.h"
#include "shaderUtils.h"
#include "../objects/face.h"
#include "../objects/bmesh.h"

using namespace std;

class Ray {
    public:
        Ray(Vector *vector);
        Ray(array<float, 3> pos, array<float, 3> direction);
        array<float, 3> getCollisionPoint();
        void cast(array<array<float, 3>, 3> tri);
        void cast(Face *face);
        void cast(Mesh *mesh);
        void cast(vector<Mesh *> meshes);
        bool hasHit;
    private:
        Vector *_vector;
        array<float, 3> collisionPoint;
};

#endif