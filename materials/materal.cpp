#include "material.h"

Material::Material(wxColour albedo, float roughness, float specular, float ior) {
    this->albedo = albedo;
    this->roughness = roughness;
    this->specular = specular;
    this->ior = ior;
}

Material::Material(array<float, 3> albedo, float roughness, float specular, float ior) {
    this->albedo = wxColour(albedo[0], albedo[1], albedo[2]);
    this->roughness = roughness;
    this->specular = specular;
    this->ior = ior;
}
/*
wxColour Material::getEmittance() {
    return this->albedo;
}*/
vec3 Material::getEmittance() {
    float red = static_cast<float>(this->albedo.Red()) / 255.0f;
    float green = static_cast<float>(this->albedo.Green()) / 255.0f;
    float blue = static_cast<float>(this->albedo.Blue()) / 255.0f;

    return vec3(red, green, blue);
}