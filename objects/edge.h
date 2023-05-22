#ifndef EDGE_H
#define EDGE_H
#include <iostream>

using namespace std;

class Vertex;

class Face;

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
        Vertex *vertStart;
        Vertex *vertEnd;
        Edge *pair;
        Edge *nextEdge;
        Edge *previousEdge;
};
#endif