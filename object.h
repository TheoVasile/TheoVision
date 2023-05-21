#include <array>
#include <iostream>
#include <wx/wx.h>

using namespace std;

class Object{
    public:
        Object(float x, float y, float z);
        virtual void scale(float x, float y, float z);
        virtual void scale(float size);
        void move(float x, float y, float z);
        void move(array<float, 3> translation);
        virtual void rotate(array<float, 3> rot);
        virtual void rotate(float xrot, float yrot, float zrot);
        array<float, 3> getOrigin();
    private:
        array<float, 3> origin;
};