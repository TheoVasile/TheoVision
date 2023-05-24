#include "bmesh.h"

Mesh::Mesh(float x, float y, float z):Object(x, y, z){}
Mesh::Mesh(array<float, 3> pos):Object(pos){}

void Mesh::scale(float x, float y, float z)
{
    array<float, 3> _origin = this->origin;
    this->move(-this->origin[0], -this->origin[1], -this->origin[2]);

    for (int i=0; i<this->vertices.size(); i++){
        this->vertices[i]->setX(this->vertices[i]->getX() * x);
        this->vertices[i]->setY(this->vertices[i]->getY() * y);
        this->vertices[i]->setZ(this->vertices[i]->getZ() * z);
    }

    this->move(_origin);
}

void Mesh::move(float x, float y, float z)
{
    this->setOrigin(this->origin[0] + x, this->origin[1] + y, this->origin[2] + z);
    for (int i=0; i<this->vertices.size(); i++){
        this->vertices[i]->setX(this->vertices[i]->getX() + x);
        this->vertices[i]->setY(this->vertices[i]->getY() + y);
        this->vertices[i]->setZ(this->vertices[i]->getZ() + z);
    }
}

void Mesh::rotate(array<float, 3> rot)
{
    array<float, 3> _origin = this->origin;
    this->move(-this->origin[0], -this->origin[1], -this->origin[2]);

    for (int i=0; i<this->vertices.size(); i++){
        this->vertices[i]->setPos(Rotate(this->vertices[i]->getPos(), rot));
    }
    this->move(_origin);
}

void Mesh::addVert(array<float, 3> pos)
{
    this->addVert(pos[0], pos[1], pos[2]);
}

void Mesh::addVert(array<float, 3> pos, vector<Edge *> edges)
{
    this->addVert(pos[0], pos[1], pos[2], edges);
}

void Mesh::addVert(float x, float y, float z)
{
    this->vertices.push_back(new Vertex(x, y, z));
}

void Mesh::addVert(float x, float y, float z, vector<Edge *> edges)
{
    this->vertices.push_back(new Vertex(x, y, z, edges));
}

void Mesh::addVert(Vertex *vert){
    this->vertices.push_back(vert);
}

void Mesh::addEdge(Vertex *vertStart, Vertex *vertEnd)
{
    Edge *newEdge = new Edge(vertStart, vertEnd);
    newEdge->vertStart->addEdge(newEdge);
    newEdge->vertEnd->addEdge(newEdge);
    this->edges.push_back(newEdge);
}

void Mesh::addEdge(int vertStartIndex, int vertEndIndex)
{
    Vertex *vertStart = this->vertices[vertStartIndex];
    Vertex *vertEnd = this->vertices[vertEndIndex];
    this->addEdge(vertStart, vertEnd);
}

void Mesh::addEdge(Edge *edge) {
    this->edges.push_back(edge);
}

void Mesh::addFace(Edge *edge, bool pair)
{
    if (pair) {
        edge = edge->pair;
    }
    this->addFace(new Face(edge));
}

void Mesh::addFace(int edgeIndex, bool pair)
{
    this->addFace(this->getEdge(edgeIndex), pair);
}

void Mesh::addFace(Face *face) {
    wxPrintf("There should be 12 of these\n");
    this->faces.push_back(face);
    Edge *startEdge = face->getEdge();
    Edge *currEdge = startEdge;
    while (currEdge->nextEdge != startEdge) {
        currEdge->face = face;
        currEdge = currEdge->nextEdge;
    }
}

vector<Vertex *> Mesh::getVerts()
{
    return this->vertices;
}

Vertex *Mesh::getVertex(int index)
{
    return this->vertices[index];
}

vector<Edge *> Mesh::getEdges()
{
    return this->edges;
}

Edge *Mesh::getEdge(int index)
{
    return this->edges[index];
}

vector<Face *> Mesh::getFaces()
{
    return this->faces;
}

Face *Mesh::getFace(int index)
{
    return this->faces[index];
}

void Mesh::addModifier(Modifier *modifier) {
    this->modifiers.push_back(modifier);
}

Mesh *Mesh::getModifiedMesh() {
    Mesh *newMesh = this;//->copy();
    for (Modifier *modifier : this->modifiers) {
        newMesh = modifier->apply(newMesh);
    }
    return newMesh;
}

Mesh *Mesh::copy() {
    Mesh *newMesh = new Mesh(this->origin);
    for (Vertex *currVert : this->vertices) {
        newMesh->addVert(currVert);
    }
    for (Edge *currEdge : this->edges) {
        newMesh->addEdge(currEdge);
    }
    for (Face *currFace : this->faces) {
        newMesh->addFace(currFace);
    }

    return newMesh;
}