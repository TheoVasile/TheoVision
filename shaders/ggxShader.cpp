#include "ggxShader.h"

GGXShader::GGXShader(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){};

wxColour GGXShader::getPixelColour(int x, int y) {
    Ray *ray = this->scene->getActiveCamera()->castRay(x, y, this->screenDim);
    vec3 colour = this->tracePath(ray, 2);
    return wxColour(colour[0] * 255, colour[1] * 255, colour[2] * 255);
}

float GGXShader::getX(float x) {
    if (x > 0) {
        return 1.0f;
    }
    return 0.0f;
}

float GGXShader::getBRDF(Ray *ray, Light *light) {
    Material *material = ray->getCollisionMesh()->material;
    vec3 lightDir = normalize(light->getOrigin() - ray->pos);
    float rd = 1.0f;
    float rs = this->getDistribution(ray, light) * this->getFresnel(ray, light) * this->getGeometry(ray, light) / (4 * dot(lightDir, ray->getCollisionNormal()) * dot(ray->getCollisionNormal(), -ray->direction));
    return dot(lightDir, ray->getCollisionNormal()) * (material->specular * rd + (1 - material->specular) * rs);
    //return ray->getCollisionMesh->material->getAlbedo() / M_PI + this->getDistribution(ray) * this->getFresnel(ray) * this->getGeometry(ray) / (-4 * dot(ray->direction, ray->getCollisionNormal()) * dot(ray->getOutgoingDirection(), ray->getCollisionNormal()));
}

float GGXShader::getDistribution(Ray *ray, Light *light) {
    vec3 h = normalize(normalize(light->getOrigin() - ray->getCollisionPoint()) - ray->direction);
    vec3 n = ray->getCollisionNormal();
    vec3 m = normalize(light->getOrigin() - ray->getCollisionPoint());//ray->getOutgoingDirection();
    float a = ray->getCollisionMesh()->material->roughness;
    return pow(a, 2) * this->getX(dot(h, n)) / (M_PI * (pow(dot(m, n), 2) * pow(pow(a, 2) + (1-pow(dot(m, n), 2)) / pow(dot(m, n), 2), 2)));
}

float GGXShader::getGeometry(Ray *ray, Light *light) {
    vec3 w = normalize(light->getOrigin() - ray->getCollisionPoint());
    vec3 m = normalize(w - ray->direction);
    vec3 n = ray->getCollisionNormal();
    float a = ray->getCollisionMesh()->material->roughness;
    return this->getX(dot(w, m) / dot(w, n)) * 2 / (1 + pow(1 + pow(a, 2) * (1 - pow(dot(w, m), 2)) / pow(dot(w, m), 2), 0.5));
}

float GGXShader::getFresnel(Ray *ray, Light *light) {
    float n = ray->getCollisionMesh()->material->ior;
    vec3 w = normalize(light->getOrigin() - ray->getCollisionPoint());
    vec3 h = ray->getCollisionNormal();
    float F = pow(n-1, 2) / pow(n+1, 2);
    return F + (1 - F) * pow(1 - dot(w, h), 5);
}

vec3 GGXShader::tracePath(Ray *ray, int depth) {
    if (depth < 1) {
        return this->scene->backgroundColor;
    }
    ray->cast(this->scene->getMeshes());
    if (ray->hasHit) {
        Material *material = ray->getCollisionMesh()->material;
        vec3 emittance = material->getEmittance();

        //vec3 dir(random(), random(), random());
        //dir = ray->direction - 2 * dot(ray->getCollisionNormal(), ray->direction) * ray->getCollisionNormal();
        //dir = normalize(dir);

        Ray *newRay = new Ray(ray->getCollisionPoint(), ray->getOutgoingDirection());
        vec3 BRDF = emittance;
        for (Light *currLight : this->scene->getLights()) {
            vec3 lightDir = normalize(currLight->getOrigin() - ray->getCollisionPoint());
            Ray *shadowRay = new Ray(ray->getCollisionPoint(), lightDir);
            shadowRay->cast(this->scene->getMeshes());
            if (!shadowRay->hasHit){
                BRDF += currLight->colour * this->getBRDF(ray, currLight);
            }
        }

        // Recursively trace reflected light sources.
        vec3 indirectLight = material->specular * this->tracePath(newRay, depth - 1);

        // Apply the Rendering Equation here.
        return BRDF + indirectLight;
    }
    return this->scene->backgroundColor;
}