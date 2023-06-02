#include "bmesh.h"

Vertex::Vertex(vec3 pos) {
    this->pos = pos;
}
Vertex::Vertex(vec3 pos, vector<Edge *> edges) {
    this->pos = pos;
    this->edges = edges;
}
Vertex::Vertex(array<float, 3> pos) {
    this->pos = vec3(pos[0], pos[1], pos[2]);
}
Vertex::Vertex(array<float, 3> pos, vector<Edge *> edges) {
    this->pos = vec3(pos[0], pos[1], pos[2]);
    this->edges = edges;
}
Vertex::Vertex(float x, float y, float z) {
    this->pos = vec3(x, y, z);
}
Vertex::Vertex(float x, float y, float z, vector<Edge *> edges) {
    this->pos = vec3(x, y, z);
    this->edges = edges;
}
void Vertex::addEdge(Edge *edge) {
    this->edges.push_back(edge);
}


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
vec3 Edge::getMidpoint() {
    return 2.0f * (vertStart->pos + vertEnd->pos);
}
void Edge::setNextEdge(Edge *edge) {
    edge->previousEdge = this;
    this->nextEdge = edge;
}
Edge *Edge::getNextEdge() {
    return this->nextEdge;
}
void Edge::setPreviousEdge(Edge *edge) {
    edge->nextEdge = this;
    this->previousEdge = edge;
}
Edge *Edge::getPreviousEdge() {
    return this->previousEdge;
}


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
    vertPositions.push_back(startEdge->vertStart->pos);
    while (currEdge->nextEdge != startEdge){
        Vertex *currVert = currEdge->vertEnd;
        vertPositions.push_back(currVert->pos);
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


Mesh::Mesh(float x, float y, float z):Object(x, y, z){
    this->material = new Material(vec3(0, 0, 255), 0.1, 0.5, 1.45);
}
Mesh::Mesh(array<float, 3> pos):Object(pos){
    this->material = new Material(vec3(0, 0, 255), 0.1, 0.5, 1.45);
}
Mesh::Mesh(vec3 pos):Object(pos){
    this->material = new Material(vec3(0, 0, 255), 0.1, 0.5, 1.45);
}
void Mesh::scale(vec3 scalingFactor)
{
    vec3 _origin = this->origin;
    this->move(-this->origin);

    for (Vertex *currVert : this->vertices){
        currVert->pos = currVert->pos * scalingFactor;
    }

    this->move(_origin);
}
void Mesh::move(vec3 translation)
{
    this->origin = this->origin + translation;
    for (Vertex *currVert : this->vertices){
        currVert->pos = currVert->pos + translation;
    }
}
void Mesh::rotate(vec3 rot)
{
    vec3 _origin = this->origin;
    this->move(-_origin);

    for (Vertex *currVert : this->vertices){
        currVert->pos = Rotate(currVert->pos, rot);
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