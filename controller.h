#include "object.h"

class Controller{
    public:
        Controller();
        vector<Mesh *> getSelected();
        vector<Mesh *> getMeshes();
        void addCube(float x, float y, float z);
    private:
        vector<int> selected;
        vector<Mesh *> objects;
        vector<int> meshes;
};