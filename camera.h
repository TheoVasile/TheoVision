#ifndef CAMERA_H
#define CAMERA_H

#include "./objects/object.h"
#include "utils.h"
#include "./objects/ray.h"
#include <array>
#include <iostream>
#include <glm/glm.hpp>

using namespace std;

class Camera : public Object{
    public:
        Camera(float x, float y, float z);
        using Object::move;
        void rotate(vec3 rot);
        using Object::rotate;
        vec2 projectPoint(vec3 pos, int screenDim[2]);
        vec2 projectPoint(array<float, 3> pos, int screenDim[2]);
        vec2 projectPoint(float x, float y, float z, int screenDim[2]);
        Ray *castRay(int x, int y, int screenDim[2]);
        void setFov(float fov);
        float getFov();
        vec3 getNormal();
        vec3 getVertical();
    protected:
        vec3 normal;
        vec3 vertical;
        float fov;
};
#endif