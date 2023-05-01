#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Mesh{

public:
    Mesh(float x, float y, float z);
    void add_vert(array<float, 3> pos);
    void add_vert(float x, float y, float z);
    void add_edge(int vert1, int vert2);
    vector<array<float, 3> > get_verts();
    vector<array<int, 2> > get_edges();
    void scale(float size);
    void move(float x, float y, float z);

private:
    float origin[3];
    vector<array<float, 3> > vertices;
    vector<array<int, 2> > edges;
    vector<vector<int> > faces;
};