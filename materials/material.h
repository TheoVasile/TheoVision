#ifndef MATERIAL_H
#define MATERIAL_H

#include <wx/wx.h>
#include <array>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Material {
    public:
        Material(wxColour albedo, float roughness, float specular, float ior);
        Material(array<float, 3> albedo, float roughness, float specular, float ior);
        //wxColour getEmittance();
        vec3 getEmittance();
        wxColour albedo;
        float roughness;
        float specular;
        float ior;
};

#endif