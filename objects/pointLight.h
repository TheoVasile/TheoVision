#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "light.h"
#include <glm/gtx/norm.hpp>

using namespace glm;

class PointLight : public Light{
    public:
        PointLight(vec3 pos, float power);
        PointLight(array<float, 3> pos, float power);
        PointLight(float x, float y, float z, float power);
        float getIntensity(vec3 pos) override;
        using Light::getIntensity;
        using Light::scale;
        using Light::move;
        using Light::rotate;
        using Light::getOrigin;
        using Light::setOrigin;
};

#endif