#ifndef MATERIAL_H
#define MATERIAL_H

#include <wx/wx.h>
#include <array>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Material {
    public:
        Material(vec3 baseColor, float roughness, float specular, float ior);
        Material(array<float, 3> baseColor, float roughness, float specular, float ior);
        vec3 getEmittance();
        vec3 baseColor;
        float roughness;
        float specular;
        float ior;
};

#endif