#include "edge.h"

Edge::Edge(Vertex *vertStart, Vertex *vertEnd){
    this->vertStart = vertStart;
    this->vertEnd = vertEnd;
    this->edgeNextCCW = NULL;
    this->edgeNextCW = NULL;
    this->edgePreviousCCW = NULL;
    this->edgePreviousCW = NULL;
}