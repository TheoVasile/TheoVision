#ifndef SHADER_H
#define SHADER_H

#include "../camera.h"
#include "../objects/bmesh.h"
#include "ray.h"
#include <wx/wx.h>
#include <vector>
#include <iostream>

using namespace std;

class Shader{
    public:
        Shader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera);
        wxBitmap ApplyShading(int pixelSize = 10);
    protected:
        void drawPoly(vector<array<float, 3> > positions);
        virtual wxColour getPixelColour(int x, int y);
        vector<Mesh *> meshes;
        wxGraphicsContext *gc;
        wxSize screenDim;
        Camera *camera;
};

#endif