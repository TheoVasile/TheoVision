#ifndef GGX_SHADER_H
#define GGX_SHADER_H


#include "shader.h"
#include <glm/glm.hpp>
using namespace glm;

class GGXShader : public Shader {
    public:
        GGXShader(Scene *scene, wxSize screenDim);
        using Shader::ApplyShading;
        int samples;
    protected:
        using Shader::drawPoly;
        wxColour getPixelColour(int x, int y) override;
        vec3 getRandomHemisphereVector(vec3 normal);
        vec3 getDiffuse(Ray *ray);
        vec3 getSpecular(Ray *ray, Light *light);
        float getDirectLighting(Ray *ray);
        vec3 getIndirectLighting(Ray *ray);
        vec3 tracePath(Ray *ray, int depth);
        float getX(float x);
        vec3 getBRDF(Ray *ray, Light *light);
        float getVisibility(Ray *ray, float val);
        float getDistribution(Ray *ray, Light *light);
        vec3 getFresnel(Ray *ray, Light *light);
        float getGeometry(Ray *ray, Light *light);
};

#endif