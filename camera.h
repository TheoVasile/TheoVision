#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"
#include "./shaders/ray.h"
#include <array>
#include <iostream>
#include <wx/wx.h>

using namespace std;

class Camera{
    public:
        Camera(float x, float y, float z);
        void move(array<float, 3> translation);
        void rotate(float xrot, float yrot, float zrot);
        void rotate(array<float, 3> rot);
        void zoom();
        array<float, 2> projectPoint(array<float, 3> pos, wxSize screenDim);
        array<float, 2> projectPoint(float x, float y, float z, wxSize screenDim);
        Ray *castRay(int x, int y, wxSize screenDim);
        array<float, 3> getPos();
        void setFov(float fov);
        float getFov();
        array<float, 3> getNormal();
        array<float, 3> getVertical();
    private:
        array<float, 3> pos;
        array<float, 3> normal;
        array<float, 3> vertical;
        float fov;
};
#endif