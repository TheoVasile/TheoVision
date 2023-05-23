#ifndef PHONG_H
#define PHONG_H

#include "shader.h"
/*
#include "../camera.h"
#include "../objects/bmesh.h"
#include "ray.h"
#include <wx/wx.h>
#include <vector>
#include <iostream>
*/

using namespace std;

class PhongShader : public Shader{
    public:
        PhongShader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera);
        using Shader::ApplyShading;
    protected:
        void drawPoly(vector<array<float, 3> > positions);
        wxColour getPixelColour(int x, int y) override;
};

#endif