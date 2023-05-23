#ifndef DIFFUSE_SHADER_H
#define DIFFUSE_SHADER_H

#include "shader.h"

class DiffuseShader : public Shader{
    public:
        DiffuseShader(Scene *scene, wxSize screenDim);
        using Shader::ApplyShading;
    protected:
        using Shader::drawPoly;
        wxColour getPixelColour(int x, int y) override;
};

#endif