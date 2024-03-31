#ifndef CAMERA_H
#define CAMERA_H

#include "./objects/object.h"
#include "utils.h"
#include "./shaders/ray.h"
#include <array>
#include <iostream>
#include <wx/wx.h>
#include <glm/glm.hpp>

using namespace std;

class Camera : public Object{
    public:
        Camera(float x, float y, float z);
        using Object::move;
        void rotate(vec3 rot);
        using Object::rotate;
        vec2 projectPoint(vec3 pos, wxSize screenDim);
        vec2 projectPoint(array<float, 3> pos, wxSize screenDim);
        vec2 projectPoint(float x, float y, float z, wxSize screenDim);
        Ray *castRay(int x, int y, wxSize screenDim);
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