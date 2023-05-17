#include "operations.h"
#include <array>
#include <iostream>
#include <wx/wx.h>

using namespace std;

class Camera{
    public:
        Camera(float x, float y, float z);
        void move(array<float, 3> translation);
        void zoom();
        array<float, 2> projectPoint(array<float, 3> pos, wxSize screenDim);
        array<float, 2> projectPoint(float x, float y, float z, wxSize screenDim);
        void setFov(float fov);
        float getFov();
        array<float, 3> getNormal();
    private:
        array<float, 3> pos;
        array<float, 3> normal;
        array<float, 3> vertical;
        float fov;
};