#ifndef SHADER_H
#define SHADER_H

#include "../scene.h"
#include "../camera.h"
#include "../objects/bmesh.h"
#include "ray.h"
#include <wx/wx.h>
#include <vector>
#include <iostream>

using namespace std;

class Shader{
    public:
        Shader(Scene *scene, wxSize screenDim);
        wxBitmap ApplyShading(int pixelSize = 10);
    protected:
        void drawPoly(vector<array<float, 3> > positions);
        virtual wxColour getPixelColour(int x, int y);
        Scene *scene;
        wxSize screenDim;
};

#endif