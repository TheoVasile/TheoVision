#include "sunLight.h"

SunLight::SunLight(array<float, 3> pos, float power, array<float, 3> direction={0, 0, -1}):Light(pos, power){
    this->direction = direction;
}

SunLight::SunLight(float x, float y, float z, float power, array<float, 3> direction={0, 0, -1}):Light(x, y, z, power){
    this->direction = direction;
}

float SunLight::getIntensity(array<float, 3> pos)
{
    return this->power * dot(this->direction, subtract(pos, this->pos));
}

void SunLight::rotate(array<float, 3> rot)
{
    this->direction = Rotate(this->direction, rot);
}