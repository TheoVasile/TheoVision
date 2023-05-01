#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Mesh{

public:
    Mesh(float pos[3]);
    void add_vert(array<float, 3> pos);
    void add_vert(float x, float y, float z);
    vector<array<float, 3> > get_verts();
    void scale(float size);

private:
    float pos[3];
    vector<array<float, 3> > vertices;
    vector<array<int, 2> > edges;
    vector<vector<int> > faces;
};