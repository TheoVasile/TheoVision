#include <vector>
#include <wx/wx.h>
#include "../utils.h"
#include "vertex.h"
#include "edge.h"
#include "face.h"

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
    vector<vector<int> > getFaces();
    void scale(float x, float y, float z);
    void scale(float size);
    void move(float x, float y, float z);
    void move(array<float, 3> translation);
    void rotate(array<float, 3> rot);
    void rotate(float xrot, float yrot, float zrot);

private:
    array<float, 3> origin;
    vector<array<float, 3> > vertices;
    vector<array<int, 2> > edges;
    vector<vector<int> > faces;
};