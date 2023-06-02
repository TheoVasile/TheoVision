#ifndef OBJECT_H
#define OBJECT_H

#include <array>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Object{
    public:
        Object(vec3 pos);
        Object(array<float, 3> pos);
        Object(float x, float y, float z);

        virtual void scale(vec3 scalingFactor);
        void scale(float x, float y, float z);
        void scale(array<float, 3> scalingFactor);
        void scale(float size);

        virtual void move(vec3 translation);
        void move(float x, float y, float z);
        void move(array<float, 3> translation);

        virtual void rotate(vec3 rot);
        void rotate(array<float, 3> rot);
        void rotate(float xrot, float yrot, float zrot);
        
        virtual Object *copy();

        vec3 origin;
};

#endif