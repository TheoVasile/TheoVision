#include "phongShader.h"

PhongShader::PhongShader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera) : Shader(meshes, gc, screenDim, camera){};

wxColour PhongShader::getPixelColour(int x, int y)
{
    Ray *ray = this->camera->castRay(x, y, this->screenDim);
    ray->cast(this->meshes);
    if (ray->hasHit) {
        int distance = (int) pow(255 / dist(ray->getCollisionPoint(), camera->getPos()), 2);
        return wxColour(distance, distance, distance);
    }
    return wxColour(255, 255, 255);
}