#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "light.h"

class PointLight : public Light{
    public:
        PointLight(array<float, 3> pos, float power);
        PointLight(float x, float y, float z, float power);
        float getIntensity(array<float, 3> pos) override;
        using Light::getIntensity;
        using Light::scale;
        using Light::move;
        using Light::rotate;
        using Light::getOrigin;
        using Light::setOrigin;
};

#endif