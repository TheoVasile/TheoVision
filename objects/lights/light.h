#ifndef LIGHT_H
#define LIGHT_H

#include "../object.h"
#include <array>
#include <iostream>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Light : public Object {
    public:
        Light(vec3 pos, float power);
        Light(array<float, 3> pos, float power);
        Light(float x, float y, float z, float power);
        virtual float getIntensity(vec3 pos);
        float getIntensity(array<float, 3> pos);
        float getIntensity(float x, float y, float z);
        using Object::scale;
        using Object::move;
        using Object::rotate;
        using Object::getOrigin;
        using Object::setOrigin;
        vec3 colour;
        float power;
};

#endif