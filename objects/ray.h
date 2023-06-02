#ifndef RAY_H
#define RAY_H

#include <array>
#include <vector>
#include <limits>
#include <iostream>
#include <glm/glm.hpp>
#include "../objects/meshes/bmesh.h"

using namespace std;
using namespace glm;

class Ray {
    public:
        Ray(vec3 pos, vec3 direction);
        Ray(array<float, 3> pos, array<float, 3> direction);
        vec3 getCollisionPoint();
        vec3 getCollisionNormal();
        vec3 getOutgoingDirection();
        Mesh *getCollisionMesh();
        vec3 getPoint(float t);
        void cast(array<vec3, 3> tri);
        void cast(Face *face);
        void cast(Mesh *mesh);
        void cast(vector<Mesh *> meshes);
        bool hasHit;
        vec3 pos;
        vec3 direction;
    protected:
        vec3 outgoingDirection;
        vec3 collisionPoint;
        vec3 collisionNormal;
        Mesh *collisionMesh;
};

#endif