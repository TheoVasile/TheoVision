#ifndef FLATSHADER_H
#define FLATSHADER_H

#include "../camera.h"
#include "../objects/bmesh.h"
#include <wx/wx.h>
#include <vector>
#include <iostream>

using namespace std;

class FlatShader{
    public:
        FlatShader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera);
        void ApplyShading();
    private:
        void drawPoly(vector<array<float, 3> > positions);
        vector<Mesh *> meshes;
        wxGraphicsContext *gc;
        wxSize screenDim;
        Camera *camera;
};
#endif