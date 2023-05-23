#include "phongShader.h"

PhongShader::PhongShader(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){
    this->specularConstant = 0.1;
    this->diffuseConstant = 0.5f;
    this->ambientConstant = 0.1f;
    this->shininessConstant = 10.0f;
};

wxColour PhongShader::getPixelColour(int x, int y)
{
    Ray *ray = this->scene->getActiveCamera()->castRay(x, y, this->screenDim);
    ray->cast(this->scene->getMeshes());
    if (ray->hasHit) {
        //int distance = (int) pow(255 / dist(ray->getCollisionPoint(), this->scene->getActiveCamera()->getOrigin()), 2);
        float intensity = this->ambientConstant;
        for (Light *currLight : this->scene->getLights()) {
            array<float, 3> lightDir = multiply(normalize(subtract(currLight->getOrigin(), ray->getCollisionPoint())), -1);
            array<float, 3> surfaceNormal = ray->getCollisionNormal();
            array<float, 3> reflRay = subtract(multiply(surfaceNormal, 2 * dot(lightDir, surfaceNormal)), lightDir);
            array<float, 3> viewerRay = multiply(scene->getActiveCamera()->getNormal(), -1);
            intensity += diffuseConstant * dot(lightDir, surfaceNormal);
            intensity += specularConstant * pow(dot(reflRay, viewerRay), shininessConstant);
        }
        int col = 255 * intensity;
        if (col > 255) {col = 255;}
        else if (col < 0) {col = 0;}
        return wxColour(col, col, col);
    }
    return wxColour(255, 255, 255);
}