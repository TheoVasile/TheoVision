#include "pointLight.h"

PointLight::PointLight(array<float, 3> pos, float power):Light(pos, power){}
PointLight::PointLight(float x, float y, float z, float power):Light(x, y, z, power){}

float PointLight::getIntensity(array<float, 3> pos)
{
    return this->power / pow(dist(pos, this->origin), 2);
}