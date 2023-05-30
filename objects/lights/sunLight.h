#ifndef SUNLIGHT_H
#define SUNLIGHT_H

#include "light.h"
#include <glm/glm.hpp>
#include "../../utils.h"

using namespace glm;

class SunLight : public Light {
    public:
        SunLight(vec3 pos, float power, vec3 direction = vec3(0, 0, -1));
        SunLight(array<float, 3> pos, float power, array<float, 3> direction={0, 0, -1});
        SunLight(float x, float y, float z, float power, array<float, 3> direction={0, 0, -1});
        float getIntensity(vec3 pos) override;
        using Light::getIntensity;
        using Light::scale;
        using Light::move;
        void rotate(vec3 rot) override;
        using Light::rotate;
        using Light::getOrigin;
        using Light::setOrigin;
        vec3 direction;
};

#endif