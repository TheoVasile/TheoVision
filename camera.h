#ifndef CAMERA_H
#define CAMERA_H

#include "./objects/object.h"
#include "utils.h"
#include "./shaders/ray.h"
#include <array>
#include <iostream>
#include <wx/wx.h>

using namespace std;

class Camera : public Object{
    public:
        Camera(float x, float y, float z);
        using Object::move;
        void rotate(array<float, 3> rot);
        using Object::rotate;
        array<float, 2> projectPoint(array<float, 3> pos, wxSize screenDim);
        array<float, 2> projectPoint(float x, float y, float z, wxSize screenDim);
        Ray *castRay(int x, int y, wxSize screenDim);
        void setFov(float fov);
        float getFov();
        array<float, 3> getNormal();
        array<float, 3> getVertical();
    protected:
        array<float, 3> normal;
        array<float, 3> vertical;
        float fov;
};
#endif