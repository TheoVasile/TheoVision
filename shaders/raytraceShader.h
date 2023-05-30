#ifndef RAYTRACE_SHADER_H
#define RAYTRACE_SHADER_H


#include "shader.h"
#include <glm/glm.hpp>
using namespace glm;

class RayTraceShader : public Shader {
    public:
        RayTraceShader(Scene *scene, wxSize screenDim);
        using Shader::ApplyShading;
        int samples;
    protected:
        using Shader::drawPoly;
        wxColour getPixelColour(int x, int y) override;
        vec3 getRandomHemisphereVector(vec3 normal);
        vec3 tracePath(Ray *ray, int depth);
        virtual vec3 getBRDF(Ray *ray, Light *light);
};

#endif