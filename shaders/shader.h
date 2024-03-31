#ifndef SHADER_H
#define SHADER_H

#include "../scene.h"
#include "../camera.h"
#include "../objects/meshes/bmesh.h"
#include "../objects/lights/sunLight.h"
#include "ray.h"
#include <glm/glm.hpp>
#include <wx/wx.h>
#include <vector>
#include <iostream>

using namespace std;
using namespace glm;

class Shader{
    public:
        Shader(Scene *scene, wxSize screenDim);
        virtual wxBitmap ApplyShading(int pixelSize = 20);
    protected:
        void drawPoly(vector<array<float, 3> > positions);
        void drawLight(Light *light);
        virtual wxColour getPixelColour(int x, int y);
        wxMemoryDC memDC;
        Scene *scene;
        wxSize screenDim;
};

#endif