#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "vertex.h"
#include "face.h"

using namespace std;

class Vertex;

/**
 * @class Edge
 * @brief Represents a connection between two vertices.
 * 
 * This is a winged edge representation of an edge, with adjascency information included.
 */
class Edge{
    public:
        Edge(Vertex *vertStart, Vertex *vertEnd);
        Edge(Edge *edge);
        void setNextEdge(Edge *edge);
        void setPreviousEdge(Edge *edge);
        array<float, 3> getMidpoint();
        Vertex *vertStart;
        Vertex *vertEnd;
        Edge *pair;
        Edge *nextEdge;
        Edge *previousEdge;
        Face *face;
};

#endif