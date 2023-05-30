#ifndef GGX_SHADER_H
#define GGX_SHADER_H


#include "raytraceShader.h"
#include <glm/glm.hpp>
using namespace glm;

class GGXShader : public RayTraceShader {
    public:
        GGXShader(Scene *scene, wxSize screenDim);
        using RayTraceShader::ApplyShading;
        int samples;
    protected:
        using RayTraceShader::drawPoly;
        using RayTraceShader::getPixelColour;
        using RayTraceShader::getRandomHemisphereVector;
        using RayTraceShader::tracePath;
        using RayTraceShader::getBRDF;
        vec3 getDiffuse(Ray *ray);
        vec3 getSpecular(Ray *ray, Light *light);
        float getDirectLighting(Ray *ray);
        vec3 getIndirectLighting(Ray *ray);
        vec3 tracePath(Ray *ray, int depth);
        float getX(float x);
        vec3 getBRDF(Ray *ray, Light *light) override;
        float getVisibility(Ray *ray, float val);
        float getDistribution(Ray *ray, Light *light);
        vec3 getFresnel(Ray *ray, Light *light);
        float getGeometry(Ray *ray, Light *light);
};

#endif