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
        void flipNormal();
        vec3 getMidpoint();
        vec3 getNormal();
        vector<vec3> getPoints();
        vector<array<vec3, 3> > getTris();
        void setEdge(Edge *edge);
        Edge *getEdge();
    private:
        float normDir;
        Edge *edge;
};

#endif