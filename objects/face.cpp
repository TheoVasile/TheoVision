#include "face.h"
#include "edge.h"
#include "vertex.h"

Face::Face(Edge *edge){
    this->setEdge(edge);
}

vector<array<float, 3> > Face::getPoints()
{
    vector<array<float, 3> > vertPositions;
    Edge *startEdge = this->edge;
    Edge *currEdge = startEdge;
    vertPositions.push_back(startEdge->vertStart->getPos());
    while (currEdge->nextEdge != startEdge){
        Vertex *currVert = currEdge->vertEnd;
        vertPositions.push_back(currVert->getPos());
        currEdge = currEdge->nextEdge;
    }
    return vertPositions;
}

vector<array<array<float, 3>, 3> > Face::getTris()
{
    vector<array<float, 3> > vertPositions = this->getPoints();
    vector<array<array<float, 3>, 3> > tris;
    for (int i=2; i < vertPositions.size(); i++){
        array<array<float, 3>, 3> currTri = {vertPositions[0], vertPositions[i-1], vertPositions[i]};
        tris.push_back(currTri);
    }
    return tris;
}

void Face::setEdge(Edge *edge)
{
    this->edge = edge;
}

Edge * Face::getEdge(){
    return this->edge;
}