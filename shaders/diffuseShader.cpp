#include "diffuseShader.h"

DiffuseShader::DiffuseShader(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){};

wxColour DiffuseShader::getPixelColour(int x, int y) {
    Ray *ray = this->scene->getActiveCamera()->castRay(x, y, this->screenDim);
    ray->cast(this->scene->getMeshes());
    if (ray->hasHit) {
        int col = (int) 255 * this->scene->getLights()[0]->getIntensity(ray->getCollisionPoint());
        return wxColour(col, col, col);
    }
    return wxColour(255, 255, 255);
}