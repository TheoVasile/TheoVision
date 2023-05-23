#include "bmesh.h"

Mesh::Mesh(float x, float y, float z):Object(x, y, z){};

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

void Mesh::addFace(Edge *edge, bool pair)
{
    if (pair) {
        edge = edge->pair;
    }
    this->faces.push_back(new Face(edge));
}

void Mesh::addFace(int edgeIndex, bool pair)
{
    this->addFace(this->getEdge(edgeIndex), pair);
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