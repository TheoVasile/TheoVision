#ifndef FACE_H
#define FACE_H

#include <array>
#include <vector>
#include <iostream>
#include "../utils.h"

using namespace std;

class Vertex;

class Edge;

class Face{
    public:
        Face(Edge *edge);
        array<float, 3> getMidpoint();
        vector<array<float, 3> > getPoints();
        vector<array<array<float, 3>, 3> > getTris();
        void setEdge(Edge *edge);
        Edge *getEdge();
    private:
        Edge *edge;
};

#endif