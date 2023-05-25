#include "pointLight.h"

PointLight::PointLight(vec3 pos, float power):Light(pos, power){}
PointLight::PointLight(array<float, 3> pos, float power):Light(pos, power){}
PointLight::PointLight(float x, float y, float z, float power):Light(x, y, z, power){}

float PointLight::getIntensity(vec3 pos)
{
    return this->power / pow(distance(pos, this->origin), 2);
}