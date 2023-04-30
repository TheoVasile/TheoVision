#include <iostream>
#include <list>
#include <array>

using namespace std;

class Mesh{

public:
    Mesh(float pos[3]);
    void add_vert(array<float, 3> pos);

private:
    float pos[3];
    list<array<float, 3> > vertices;
    list<array<int, 2> > edges;
    list<list<int> > faces;
};