#include "object.h"

Object::Object(vec3 pos) {
    this->origin = pos;
}

Object::Object(array<float, 3> pos){
    this->origin[0] = pos[0];
    this->origin[1] = pos[1];
    this->origin[2] = pos[2];
}

Object::Object(float x, float y, float z){
    this->origin[0] = x;
    this->origin[1] = y;
    this->origin[2] = z;
}

void Object::scale(vec3 scalingFactor){}

void Object::scale(float x, float y, float z) {
    this->scale(vec3(x, y, z));
}
void Object::scale(float size)
{
    this->scale(size, size, size);
}
void Object::scale(array<float, 3> scalingFactor) {
    this->scale(scalingFactor[0], scalingFactor[1], scalingFactor[2]);
}


void Object::move(vec3 translation) {
    origin += translation;
}

void Object::move(float x, float y, float z)
{
    this->move(vec3(x, y, z));
}
void Object::move(array<float, 3> translation){
    this->move(translation[0], translation[1], translation[2]);
}


void Object::rotate(vec3 rot){}

void Object::rotate(float xrot, float yrot, float zrot)
{
    this->rotate(vec3(xrot, yrot, zrot));
}
void Object::rotate(array<float, 3> rot)
{
    this->rotate(rot[0], rot[1], rot[2]);
}

Object *Object::copy() {
    Object *newObject = new Object(this->origin);
    return newObject;
}