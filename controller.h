#include "object.h"
#include "camera.h"
#include <math.h>

#define PI 3.141592653589793
#define ID_GRAB 1
#define ID_ROTATE 2
#define ID_SCALE 3
#define ID_ZOOM_IN 4
#define ID_ZOOM_OUT 5

class Controller{
    public:
        Controller();
        float cursor_movement[2];
        void move(float x, float y, float z);
        void rotate(float xrot, float yrot, float zrot);
        void scale(float size);
        void scale(float x, float y, float z);
        Camera *getActiveCamera();
        vector<Mesh *> getSelected();
        vector<Mesh *> getMeshes();
        void operate();
        void setOperation(int operation);
        void addCube(float x, float y, float z);
        void addUVSphere(float x, float y, float z, float rings, float segments);
    private:
        int operation;
        Camera *activeCamera;
        vector<int> selected;
        vector<Mesh *> objects;
        vector<int> meshes;
};