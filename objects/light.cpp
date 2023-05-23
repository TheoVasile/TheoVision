#include "light.h"

Light::Light(float x, float y, float z, float power):Object(x, y, z){
    this->power = power;
}

Light::Light(array<float, 3> pos, float power):Object(pos){
    this->power = power;
}

float Light::getIntensity(array<float, 3> pos){}

float Light::getIntensity(float x, float y, float z){
    array<float, 3> pos = {x, y, z};
    return this->getIntensity(pos);
}