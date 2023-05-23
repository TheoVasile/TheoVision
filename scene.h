#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <wx/wx.h>
#include <limits>
#include "./objects/object.h"
#include "./objects/bmesh.h"
#include "./objects/light.h"
#include "camera.h"
#include "utils.h"
#include <math.h>

using namespace std;

#define ID_GRAB 1
#define ID_ROTATE 2
#define ID_SCALE 3
#define ID_ZOOM_IN 4
#define ID_ZOOM_OUT 5

class Scene{
    public:
        Scene();
        void move(float x, float y, float z);
        void move(array<float, 3> translation);
        void rotate(float xrot, float yrot, float zrot);
        void rotate(array<float, 3> rot);
        void scale(float size);
        void scale(float x, float y, float z);
        Camera *getActiveCamera();
        vector<Object *> getSelected();
        vector<Mesh *> getMeshes();
        vector<Light *> getLights();
        void select(int x, int y);
        void select(array<int, 2> cursorPos);
        void setOperation(int operation);
        void addLight(Light *light);
        void addCube(float x, float y, float z);
        void addUVSphere(float x, float y, float z, int rings, int segments);
    private:
        Camera *activeCamera;
        vector<Object *> objects;
        vector<Object *> selected;
        vector<Mesh *> meshes;
        vector<Light *> lights;
};
#endif