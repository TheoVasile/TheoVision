#include "raytraceShader.h"

RayTraceShader::RayTraceShader(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){
    this->samples = 10;
};

wxColour RayTraceShader::getPixelColour(int x, int y) {
    Ray *ray = this->scene->getActiveCamera()->castRay(x, y, this->screenDim);
    vec3 colour = this->tracePath(ray, 2);
    colour[0] = clamp(colour[0], 0.0f, 1.0f);
    colour[1] = clamp(colour[1], 0.0f, 1.0f);
    colour[2] = clamp(colour[2], 0.0f, 1.0f);
    return wxColour(colour[0] * 255, colour[1] * 255, colour[2] * 255);
}

vec3 RayTraceShader::getBRDF(Ray *ray, Light *light) {
    ray->cast(this->scene->getMeshes());
    return ray->getCollisionMesh()->material->getEmittance();
}

vec3 RayTraceShader::getRandomHemisphereVector(vec3 normal) {
    float u = rand() % 100 / 100.0f;
    float v = rand() % 100 / 100.0f;

    float radial = sqrt(u);
    float theta = 2.0 * M_PI * v;

    float x = radial * cosf(theta);
    float y = radial * sinf(theta);
    float z = sqrt(1 - u);
    vec3 vector = vec3(x, y, z);

    float angle = acos(dot(vector, normal));
    vec3 axis = cross(vector, normal);

    return Rotate(vector, axis * angle);
}

vec3 RayTraceShader::tracePath(Ray *ray, int depth) {
    if (depth < 1) {
        return scene->backgroundColor;
    }
    ray->cast(this->scene->getMeshes());
    if (!ray->hasHit) {
        return scene->backgroundColor;
    }
    vec3 colour = vec3(0, 0, 0);
    for (int i=0; i < this->samples; i++) {
        Ray *reflectedRay = new Ray(ray->getCollisionPoint(), this->getRandomHemisphereVector(ray->getCollisionNormal()));
        vec3 lightColor = this->scene->backgroundColor;
        Light *selectedLight = this->scene->getLights()[0];
        vec3 l = normalize(selectedLight->getOrigin() - ray->getCollisionPoint());
        Ray *shadowRay = new Ray(ray->getCollisionPoint(), l);
        shadowRay->cast(this->scene->getMeshes());
        if (shadowRay->hasHit) {
            lightColor += selectedLight->power / pow(distance(selectedLight->getOrigin(), ray->getCollisionPoint()), 2.0f) * vec3(1, 1, 1);
        }
        colour += this->tracePath(reflectedRay, depth - 1) * lightColor * this->getBRDF(reflectedRay, selectedLight) * clamp(dot(reflectedRay->direction, ray->getCollisionNormal()), 0.0f, 1.0f);
    }
    colour /= this->samples;
    return colour;
}