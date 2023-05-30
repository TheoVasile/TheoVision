#include "ggxShader.h"

GGXShader::GGXShader(Scene *scene, wxSize screenDim) : RayTraceShader(scene, screenDim){
};
float GGXShader::getX(float x) {
    if (x > 0) {
        return 1.0f;
    }
    return 0.0f;
}

vec3 GGXShader::getBRDF(Ray *ray, Light *light) {
    vec3 l = normalize(light->getOrigin() - ray->getCollisionPoint());
    Ray *shadowRay = new Ray(ray->getCollisionPoint(), l);
    shadowRay->cast(this->scene->getMeshes());
    if (shadowRay->hasHit) {
        vec3 diffuse = this->getDiffuse(ray);
        vec3 specular = this->getDistribution(ray, light) * this->getGeometry(ray, light) * this->getFresnel(ray, light);
        return diffuse + specular;
    }
    return this->scene->backgroundColor;
}

float GGXShader::getVisibility(Ray *ray, float val) {
    float a = pow(ray->getCollisionMesh()->material->roughness, 2.0f);

    return 2 * val / (val + sqrt(a + (1 - a) * pow(val, 2.0f)));
}

float GGXShader::getDistribution(Ray *ray, Light *light) {
    vec3 l = normalize(light->getOrigin() - ray->getCollisionPoint());
    vec3 n = ray->getCollisionNormal();
    vec3 h = normalize(l + n);
    float NdotH = clamp(dot(n, h), 0.0f, 1.0f);
    float a = pow(ray->getCollisionMesh()->material->roughness, 2.0f);
    return a / (M_PI * pow(NdotH, 2.0f) * (a - 1) + 1);
}

float GGXShader::getGeometry(Ray *ray, Light *light) {
    vec3 l = normalize(light->getOrigin() - ray->getCollisionPoint());
    vec3 n = ray->getCollisionNormal();
    vec3 v = -ray->direction;

    float NdotL = clamp(dot(n, l), 0.0f, 1.0f);
    float NdotV = clamp(dot(n, v), 0.0f, 1.0f);
    return this->getVisibility(ray, NdotL) * this->getVisibility(ray, NdotV);
}

vec3 GGXShader::getFresnel(Ray *ray, Light *light) {
    float n = ray->getCollisionMesh()->material->ior;
    vec3 l = normalize(light->getOrigin() - ray->getCollisionPoint());
    vec3 v = -ray->direction;
    vec3 h = normalize(l + v);
    float F = (float) pow(n-1, 2) / pow(n+1, 2);
    return vec3(F, F, F) + (vec3(1.0f, 1.0f, 1.0f) - vec3(F, F, F)) * (float)pow(1.0f - clamp(dot(v, h), 0.0f, 1.0f), 5);
}

vec3 GGXShader::getDiffuse(Ray *ray) {
    return ray->getCollisionMesh()->material->getEmittance() / (float) M_PI;
}

vec3 GGXShader::getSpecular(Ray *ray, Light *light) {
    return this->getDistribution(ray, light) * this->getGeometry(ray, light) * this->getFresnel(ray, light);
}