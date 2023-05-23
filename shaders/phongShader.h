#ifndef PHONG_H
#define PHONG_H

#include "../camera.h"
#include "../objects/bmesh.h"
#include "ray.h"
#include <wx/wx.h>
#include <vector>
#include <iostream>

using namespace std;

class PhongShader{
    public:
        PhongShader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera);
        wxBitmap ApplyShading();
    private:
        void drawPoly(vector<array<float, 3> > positions);
        wxColour getPixelColour(int x, int y);
        vector<Mesh *> meshes;
        wxGraphicsContext *gc;
        wxSize screenDim;
        Camera *camera;
};

#endif