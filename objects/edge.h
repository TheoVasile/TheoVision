#ifndef EDGE_H
#define EDGE_H
#include <iostream>

using namespace std;

class Vertex;

class Face;

class Edge{
    public:
        Edge(Vertex *vertStart, Vertex *vertEnd);
        Vertex *vertStart;
        Vertex *vertEnd;
        Face *faceCW;
        Face *faceCCW;
        Edge *edgePreviousCW;
        Edge *edgeNextCW;
        Edge *edgePreviousCCW;
        Edge *edgeNextCCW;
};
#endif