#include "face.h"

Face::Face(Edge *edge){
    this->setEdge(edge);
}

void Face::setEdge(Edge *edge){
    this->edge = edge;
}

Edge * Face::getEdge(){
    return this->edge;
}