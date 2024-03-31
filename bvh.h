#ifndef BVH_H
#define BVH_H
#include <wx/wx.h>
#include "utils.h"
#include "./objects/meshes/bmesh.h"
#include "aabb.h"

using namespace std;

struct BVHNode;

class BVH {
    public:
        BVH(vector<Mesh *> meshes);
        void build();
    private:
        BVHNode* root;
        vector<Mesh *> meshes;
};

struct BVHNode {
    AABB bounding_box;
};
#endif