#include "object.h"
#include <math.h>

#define PI 3.141592653589793

class Controller{
    public:
        Controller();
        void move(float x, float y, float z);
        vector<Mesh *> getSelected();
        vector<Mesh *> getMeshes();
        void addCube(float x, float y, float z);
        void addUVSphere(float x, float y, float z, float rings, float segments);
    private:
        vector<int> selected;
        vector<Mesh *> objects;
        vector<int> meshes;
};