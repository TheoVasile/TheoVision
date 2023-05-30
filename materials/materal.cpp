#include "material.h"

Material::Material(vec3 baseColor, float roughness, float specular, float ior) {
    this->baseColor = baseColor;
    this->roughness = roughness;
    this->specular = specular;
    this->ior = ior;
}

Material::Material(array<float, 3> baseColor, float roughness, float specular, float ior) {
    this->baseColor = vec3(baseColor[0], baseColor[1], baseColor[2]);
    this->roughness = roughness;
    this->specular = specular;
    this->ior = ior;
}
/*
wxColour Material::getEmittance() {
    return this->albedo;
}*/
vec3 Material::getEmittance() {
    return this->baseColor;
}