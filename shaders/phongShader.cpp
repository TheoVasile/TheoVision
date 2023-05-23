#include "phongShader.h"

PhongShader::PhongShader(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){};

wxColour PhongShader::getPixelColour(int x, int y)
{
    Ray *ray = this->scene->getActiveCamera()->castRay(x, y, this->screenDim);
    ray->cast(this->scene->getMeshes());
    if (ray->hasHit) {
        int distance = (int) pow(255 / dist(ray->getCollisionPoint(), this->scene->getActiveCamera()->getPos()), 2);
        return wxColour(distance, distance, distance);
    }
    return wxColour(255, 255, 255);
}