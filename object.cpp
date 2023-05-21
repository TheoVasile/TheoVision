#include "object.h"

Object::Object(float x, float y, float z){
    this->origin[0] = x;
    this->origin[1] = y;
    this->origin[2] = z;
}

void Object::move(float x, float y, float z){
    this->origin[0] += x;
    this->origin[1] += y;
    this->origin[2] += z;
}
void Object::move(array<float, 3> translation){
    this->move(translation[0], translation[1], translation[2]);
}

array<float, 3> Object::getOrigin(){
    return this->origin;
}