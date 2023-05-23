#ifndef SHADER_H
#define SHADER_H

#include "../scene.h"
#include "../camera.h"
#include "../objects/bmesh.h"
#include "../objects/sunLight.h"
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
        void drawLight(Light *light);
        virtual wxColour getPixelColour(int x, int y);
        wxMemoryDC memDC;
        Scene *scene;
        wxSize screenDim;
};

#endif