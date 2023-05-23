#ifndef OBJECT_H
#define OBJECT_H

#include <array>
#include <iostream>
#include <vector>
#include <wx/wx.h>
#include "../utils.h"

using namespace std;

class Object{
    public:
        Object(float x, float y, float z);
        virtual void scale(float x, float y, float z);
        void scale(float size);
        virtual void move(float x, float y, float z);
        void move(array<float, 3> translation);
        virtual void rotate(array<float, 3> rot);
        void rotate(float xrot, float yrot, float zrot);
        array<float, 3> getOrigin();
        void setOrigin(array<float, 3> pos);
        void setOrigin(float x, float y, float z);
    protected:
        array<float, 3> origin;
};

#endif