#include "camera.h"

Camera::Camera(float x, float y, float z):Object(x, y, z){
    this->normal = vec3(0.0, 0.0, 1.0);
    this->vertical = vec3(0.0, 1.0, 0.0);
    this->fov = 30.6;
}

void Camera::rotate(vec3 rot)
{
    this->normal = Rotate(this->normal, rot);
    this->vertical = Rotate(this->vertical, rot);
}

vec2 Camera::projectPoint(vec3 pos, wxSize screenDim) {
    vec3 dir(pos - this->origin);

    vec3 x_component = project_onto_plane(dir, this->vertical);
    x_component = normalize(x_component);

    vec3 y_component = project_onto_plane(dir, cross(this->vertical, this->normal));
    y_component = normalize(y_component);

    float x_angle = acos(dot(x_component, this->normal)) * 180.0 / M_PI;
    x_angle = x_angle * (float) sign(dot(x_component, cross(this->vertical, this->normal)));

    float y_angle = acos(dot(y_component, this->normal)) * 180.0 / M_PI;
    y_angle = y_angle * (float) sign(dot(y_component, this->vertical));

    int scale_factor = std::min(screenDim.GetHeight(), screenDim.GetWidth());
    vec2 screenCoord(0, 0);
    screenCoord[0] = x_angle / this->fov * 2 * scale_factor + screenDim.GetWidth() / 2;
    screenCoord[1] = y_angle / this->fov * 2 * scale_factor + screenDim.GetHeight() / 2;
    return screenCoord;
}

vec2 Camera::projectPoint(array<float, 3> pos, wxSize screenDim){
    return this->projectPoint(pos[0], pos[1], pos[2], screenDim);
}

vec2 Camera::projectPoint(float x, float y, float z, wxSize screenDim){
    return this->projectPoint(vec3(x, y, z), screenDim);
}

Ray *Camera::castRay(int x, int y, wxSize screenDim)
{
    float angle = this->fov * M_PI / 360;
    float _x = screenDim.GetWidth() / 2 - x;
    vec3 xComponent = cross(this->normal, this->vertical) * _x;

    float _y = y - screenDim.GetHeight() / 2;
    vec3 yComponent = this->vertical * _y;

    int scale_factor = std::min(screenDim.GetHeight(), screenDim.GetWidth());
    vec3 direction = yComponent + xComponent + this->normal * (scale_factor * cosf(angle) / sinf(angle));
    
    Ray *ray = new Ray(this->origin, direction);
    return ray;
}

vec3 Camera::getNormal(){
    return this->normal;
}

vec3 Camera::getVertical()
{
    return this->vertical;
}

void Camera::setFov(float fov){
    this->fov = fov;
}
float Camera::getFov(){
    return this->fov;
}