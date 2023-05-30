#include "ggxShader.h"

GGXShader::GGXShader(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){
    this->samples = 1;
};

wxColour GGXShader::getPixelColour(int x, int y) {
    Ray *ray = this->scene->getActiveCamera()->castRay(x, y, this->screenDim);
    vec3 colour = this->tracePath(ray, 2);
    colour[0] = clamp(colour[0], 0.0f, 1.0f);
    colour[1] = clamp(colour[1], 0.0f, 1.0f);
    colour[2] = clamp(colour[2], 0.0f, 1.0f);
    return wxColour(colour[0] * 255, colour[1] * 255, colour[2] * 255);
}

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

vec3 GGXShader::getRandomHemisphereVector(vec3 normal) {
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

vec3 GGXShader::tracePath(Ray *ray, int depth) {
    if (depth < 1) {
        return this->scene->backgroundColor;
    }
    ray->cast(this->scene->getMeshes());
    if (ray->hasHit) {
        int lightsCount = this->scene->getLights().size();
	    Light *lightToSample = this->scene->getLights()[rand() % lightsCount];

        vec3 localColor = this->getBRDF(ray, lightToSample);

        Ray *reflectedRay = new Ray(ray->getCollisionPoint(), ray->getOutgoingDirection());
        // Apply the Rendering Equation here.
        vec3 finalColor = localColor + ray->getCollisionMesh()->material->specular * this->tracePath(reflectedRay, depth - 1);
        return finalColor;
    }
    return this->scene->backgroundColor;
}