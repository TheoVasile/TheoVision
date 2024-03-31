#include "face.h"
#include "edge.h"
#include "vertex.h"

Face::Face(Edge *edge){
    this->normDir = 1.0f;
    this->setEdge(edge);
}

void Face::flipNormal() {
    this->normDir *= -1.0f;
}

vec3 Face::getMidpoint() {
    vec3 midPoint(0, 0, 0);
    vector<vec3 > points = this->getPoints();
    for (vec3 currPoint : points) {
        midPoint += currPoint;
    }
    return midPoint / (float) points.size();
}

vec3 Face::getNormal() {
    vec3 normal(0, 0, 0);
    for (array<vec3, 3> currTri : this->getTris()) {
        vec3 v1 = normalize(currTri[1] - currTri[0]);
        vec3 v2 = normalize(currTri[2] - currTri[0]);
        normal += normalize(cross(v1, v2));
    }
    return normalize(normal * this->normDir);
}

vector<vec3> Face::getPoints()
{
    vector<vec3> vertPositions;
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

vector<array<vec3, 3> > Face::getTris()
{
    vector<vec3> vertPositions = this->getPoints();
    vector<array<vec3, 3> > tris;
    for (int i=2; i < vertPositions.size(); i++){
        array<vec3, 3> currTri = {vertPositions[0], vertPositions[i-1], vertPositions[i]};
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