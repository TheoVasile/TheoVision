#include "operations.h"
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Mesh{

public:
    Mesh(float x, float y, float z);
    void addVert(array<float, 3> pos);
    void addVert(float x, float y, float z);
    void addEdge(int vert1, int vert2);
    void addFace(vector<int> verts);
    array<float, 3> getOrigin();
    vector<array<float, 3> > getVerts();
    vector<array<int, 2> > getEdges();
    void scale(float x, float y, float z);
    void scale(float size);
    void move(float x, float y, float z);
    void rotate(array<float, 3> rot);
    void rotate(float xrot, float yrot, float zrot);

private:
    array<float, 3> origin;
    vector<array<float, 3> > vertices;
    vector<array<int, 2> > edges;
    vector<vector<int> > faces;
};