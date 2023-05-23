#ifndef SUNLIGHT_H
#define SUNLIGHT_H

#include "light.h"

class SunLight : public Light {
    public:
        SunLight(array<float, 3> pow, float power, array<float, 3> direction={0, 0, -1});
        SunLight(float x, float y, float z, float power, array<float, 3> direction={0, 0, -1});
        float getIntensity(array<float, 3> pos) override;
        using Light::getIntensity;
        using Light::scale;
        using Light::move;
        void rotate(array<float, 3> rot) override;
        using Light::rotate;
        using Light::getOrigin;
        using Light::setOrigin;
    protected:
        array<float, 3> direction;
};

#endif