#include "object.h"

Object::Object(array<float, 3> pos){
    this->origin = origin;
}

Object::Object(float x, float y, float z){
    this->origin[0] = x;
    this->origin[1] = y;
    this->origin[2] = z;
}

void Object::scale(float size)
{
    this->scale(size, size, size);
}

void Object::scale(float x, float y, float z){}

void Object::move(float x, float y, float z)
{
    this->origin[0] += x;
    this->origin[1] += y;
    this->origin[2] += z;
}
void Object::move(array<float, 3> translation){
    this->move(translation[0], translation[1], translation[2]);
}

void Object::rotate(float xrot, float yrot, float zrot)
{
    array<float, 3> rot = {xrot, yrot, zrot};
    this->rotate(rot);
}

void Object::rotate(array<float, 3> rot){}

array<float, 3> Object::getOrigin(){
    return this->origin;
}

void Object::setOrigin(float x, float y, float z)
{
    this->origin[0] = x;
    this->origin[1] = y;
    this->origin[2] = z;
}

void Object::setOrigin(array<float, 3> pos)
{
    this->setOrigin(pos[0], pos[1], pos[2]);
}