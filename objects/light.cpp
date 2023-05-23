#include "light.h"

Light::Light(float x, float y, float z, float power):Object(x, y, z){
    this->power = power;
}

Light::Light(array<float, 3> pos, float power):Object(pos){
    this->power = power;
}

Light::getIntensity(array<float, 3> pos){}