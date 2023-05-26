#ifndef GGX_SHADER_H
#define GGX_SHADER_H

#include "shader.h"
#include <glm/glm.hpp>

using namespace glm;

class GGXShader : public Shader {
    public:
        GGXShader(Scene *scene, wxSize screenDim);
        using Shader::ApplyShading;
    protected:
        using Shader::drawPoly;
        wxColour getPixelColour(int x, int y) override;
        vec3 tracePath(Ray *ray, int depth);
        float getX(float x);
        float getBRDF(Ray *ray, Light *light);
        float getDistribution(Ray *ray, Light *light);
        float getFresnel(Ray *ray, Light *light);
        float getGeometry(Ray *ray, Light *light);
};

#endif