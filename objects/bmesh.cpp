#include "bmesh.h"

Mesh::Mesh(float x, float y, float z):Object(x, y, z){
    this->material = new Material(wxColour(0, 0, 255), 0.1, 0.5, 1.4);
}
Mesh::Mesh(array<float, 3> pos):Object(pos){
    this->material = new Material(wxColour(0, 0, 255), 0.1, 0.5, 1.4);
}
Mesh::Mesh(vec3 pos):Object(pos){
    this->material = new Material(wxColour(0, 0, 255), 0.1, 0.5, 1.4);
}

void Mesh::scale(vec3 scalingFactor)
{
    vec3 _origin = this->origin;
    this->move(-this->origin);

    for (Vertex *currVert : this->vertices){
        currVert->setPos(currVert->getPos() * scalingFactor);
    }

    this->move(_origin);
}

void Mesh::move(vec3 translation)
{
    this->setOrigin(this->origin + translation);
    for (Vertex *currVert : this->vertices){
        currVert->setPos(currVert->getPos() + translation);
    }
}

void Mesh::rotate(vec3 rot)
{
    vec3 _origin = this->origin;
    this->move(-_origin);

    for (Vertex *currVert : this->vertices){
        currVert->setPos(Rotate(currVert->getPos(), rot));
    }
    this->move(_origin);
}

void Mesh::flipNormals() {
    for (Face *currFace : this->faces) {
        currFace->flipNormal();
    }
}

void Mesh::addVert(array<float, 3> pos)
{
    this->addVert(pos[0], pos[1], pos[2]);
}

void Mesh::addVert(vec3 pos) {
    this->vertices.push_back(new Vertex(pos));
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

void Mesh::addVert(vec3 pos, vector<Edge *>) {
    this->vertices.push_back(new Vertex(pos, edges));
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
    this->faces.push_back(face);
    Edge *startEdge = face->getEdge();
    Edge *currEdge = startEdge;
    currEdge->face = face;
    int x = 0;
    while (currEdge->nextEdge != startEdge) {
        //wxPrintf("There should be 24 of these\n");
        currEdge->nextEdge->face = face;
        currEdge = currEdge->nextEdge;
        x++;
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
    Mesh *newMesh = this->copy();
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