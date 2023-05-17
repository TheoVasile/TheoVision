#include "camera.h"

Camera::Camera(float x, float y, float z){
    this->pos = (array<float, 3>){x, y, z};
    this->normal = (array<float, 3>){0.0, 0.0, 1.0};
    this->vertical = (array<float, 3>){0.0, 1.0, 0.0};
    this->fov = 30.6;
}

array<float, 2> Camera::projectPoint(array<float, 3> pos, wxSize screenDim){
    this->projectPoint(pos[0], pos[1], pos[2], screenDim);
}

array<float, 2> Camera::projectPoint(float x, float y, float z, wxSize screenDim){
    /*
    Return a 2D location on screen where the camera would see a given 3D point.
    */
    array<float, 3> dir = { x - this->pos[0],
                            y - this->pos[1],
                            z - this->pos[2]};
    /*
    dir[0] = x - this->pos[0];
    dir[1] = y - this->pos[1];
    dir[2] = z - this->pos[2];
    */

    // Get the angle away from the normal of the horizontal component of the direction vector
    array<float, 3> x_component = project_onto_plane(dir, this->vertical);
    x_component = normalize(x_component);

    float x_angle = acos(dot(x_component, this->normal)) * 180.0 / PI;
    x_angle = x_angle * (float) sign(dot(x_component, cross(this->vertical, this->normal)));

    // Get the angle away from the normal of the vertical component of the direction vector
    array<float, 3> y_component = project_onto_plane(dir, cross(this->vertical, this->normal));
    y_component = normalize(y_component);

    float y_angle = acos(dot(y_component, this->normal)) * 180.0 / PI;
    y_angle = y_angle * (float) sign(dot(y_component, this->vertical));

    // X and Y coordinates measure the angles relative to the fov, and scale them up according to the screen dimensions
    int scale_factor = min(screenDim.GetHeight(), screenDim.GetWidth());
    return (array<float, 2>){x_angle / this->fov * 2 * scale_factor + screenDim.GetWidth() / 2, y_angle / this->fov * 2 * scale_factor + screenDim.GetHeight() / 2};
}

void Camera::setFov(float fov){
    this->fov = fov;
}
float Camera::getFov(){
    return this->fov;
}