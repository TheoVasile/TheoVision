#ifndef PHONG_H
#define PHONG_H

#include "shader.h"

using namespace std;

class PhongShader : public Shader{
    public:
        PhongShader(Scene *scene, wxSize screenDim);
        using Shader::ApplyShading;
    protected:
        void drawPoly(vector<array<float, 3> > positions);
        wxColour getPixelColour(int x, int y) override;
};

#endif