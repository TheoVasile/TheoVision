#include "edge.h"

Edge::Edge(Vertex *vertStart, Vertex *vertEnd){
    this->vertStart = vertStart;
    this->vertEnd = vertEnd;
    this->nextEdge = NULL;
    this->previousEdge = NULL;
    this->pair = new Edge(this);
}

Edge::Edge(Edge *edge)
{
    this->vertStart = edge->vertEnd;
    this->vertEnd = edge->vertStart;
    this->nextEdge = NULL;
    this->previousEdge = NULL;
    this->pair = edge;
}

void Edge::setNextEdge(Edge *edge)
{
    edge->previousEdge = this;
    this->nextEdge = edge;
}
void Edge::setPreviousEdge(Edge *edge)
{
    edge->nextEdge = this;
    this->previousEdge = edge;
}