#ifndef SCENE_H
#define SCENE_H
#include <limits>
#include "./objects/object.h"
#include "./objects/meshes/bmesh.h"
#include "camera.h"
#include "./objects/lights/light.h"
#include "utils.h"
#include <math.h>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Scene{
    public:
        Scene();
        void move(vec3 translation);
        void move(float x, float y, float z);
        void move(array<float, 3> translation);
        void rotate(vec3 rotate);
        void rotate(float xrot, float yrot, float zrot);
        void rotate(array<float, 3> rot);
        void scale(vec3 scalingFactor);
        void scale(float size);
        void scale(float x, float y, float z);
        vec3 getMedianPoint();
        Camera *getActiveCamera();
        vector<Object *> getSelected();
        vector<Mesh *> getMeshes();
        vector<Light *> getLights();
        void select(int x, int y);
        void select(array<int, 2> cursorPos);
        void select(vec2 cursorPos);
        void setOperation(int operation);
        void addLight(Light *light);
        void addCube(float x, float y, float z);
        void addUVSphere(float x, float y, float z, int rings, int segments);
        int screenDim[2];
        vec3 backgroundColor;
    private:
        Camera *activeCamera;
        vector<Object *> objects;
        vector<Object *> selected;
        vector<Mesh *> meshes;
        vector<Light *> lights;
};
#endif