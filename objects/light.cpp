#include "light.h"

Light::Light(vec3 pos, float power):Object(pos){
    this->power = power;
}
Light::Light(float x, float y, float z, float power):Object(x, y, z){
    this->power = power;
}
Light::Light(array<float, 3> pos, float power):Object(pos){
    this->power = power;
}

float Light::getIntensity(vec3 pos) {
    return 1.0;
}
float Light::getIntensity(array<float, 3> pos){
    return this->getIntensity(pos[0], pos[1], pos[2]);
}

float Light::getIntensity(float x, float y, float z){
    vec3 pos(x, y, z);
    return this->getIntensity(pos);
}