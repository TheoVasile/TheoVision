#include "camera.h"

Camera::Camera(float x, float y, float z){
    this->pos = (array<float, 3>){x, y, z};
    this->normal = (array<float, 3>){0.0, 0.0, 1.0};
    this->vertical = (array<float, 3>){0.0, 1.0, 0.0};
    this->fov = 30.6;
}

void Camera::move(array<float, 3> translation){
    this->pos[0] += translation[0];
    this->pos[1] += translation[1];
    this->pos[2] += translation[2];
}

void Camera::rotate(float xrot, float yrot, float zrot)
{
    array<float, 3> rot = {xrot, yrot, zrot};
    this->rotate(rot);
}

void Camera::rotate(array<float, 3> rot)
{
    this->normal = Rotate(this->normal, rot);
    this->vertical = Rotate(this->vertical, rot);
}

void Camera::zoom(){
    this->move(this->normal);
}

array<float, 2> Camera::projectPoint(array<float, 3> pos, wxSize screenDim){
    return this->projectPoint(pos[0], pos[1], pos[2], screenDim);
}

array<float, 2> Camera::projectPoint(float x, float y, float z, wxSize screenDim){
    array<float, 3> dir;
    dir[0] = x - this->pos[0];
    dir[1] = y - this->pos[1];
    dir[2] = z - this->pos[2];

    array<float, 3> x_component = project_onto_plane(dir, this->vertical);
    x_component = normalize(x_component);

    array<float, 3> y_component = project_onto_plane(dir, cross(this->vertical, this->normal));
    y_component = normalize(y_component);

    float x_angle = acos(dot(x_component, this->normal)) * 180.0 / PI;
    x_angle = x_angle * (float) sign(dot(x_component, cross(this->vertical, this->normal)));

    float y_angle = acos(dot(y_component, this->normal)) * 180.0 / PI;
    y_angle = y_angle * (float) sign(dot(y_component, this->vertical));

    int scale_factor = min(screenDim.GetHeight(), screenDim.GetWidth());
    array<float, 2> screenCoord;
    screenCoord[0] = x_angle / this->fov * 2 * scale_factor + screenDim.GetWidth() / 2;
    screenCoord[1] = y_angle / this->fov * 2 * scale_factor + screenDim.GetHeight() / 2;
    return screenCoord;
}

array<float, 3> Camera::getNormal(){
    return this->normal;
}

array<float, 3> Camera::getPos()
{
    return this->pos;
}

void Camera::setFov(float fov){
    this->fov = fov;
}
float Camera::getFov(){
    return this->fov;
}