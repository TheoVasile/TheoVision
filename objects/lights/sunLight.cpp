#include "sunLight.h"

SunLight::SunLight(vec3 pos, float power, vec3 direction):Light(pos, power) {
    this->direction = direction;
}

SunLight::SunLight(array<float, 3> pos, float power, array<float, 3> direction):Light(pos, power){
    this->direction = vec3(direction[0], direction[1], direction[2]);
}

SunLight::SunLight(float x, float y, float z, float power, array<float, 3> direction):Light(x, y, z, power){
    this->direction = vec3(direction[0], direction[1], direction[2]);
}

float SunLight::getIntensity(vec3 pos)
{
    return this->power;
}

void SunLight::rotate(vec3 rot)
{
    this->direction = Rotate(this->direction, rot);
}