#ifndef LIGHT_H
#define LIGHT_H

#include "object.h"
#include <array>
#include <iostream>

using namespace std;

class Light : Object {
    public:
        Light(array<float, 3> pow, float power);
        Light(float x, float y, float z, float power);
        virtual float getIntensity(array<float, 3> pos);
        float getIntensity(float x, float y, float z);
        using Object::scale;
        using Object::move;
        using Object::rotate;
        using Object::getOrigin;
        using Object::setOrigin;
    protected:
        float power;
};

#endif