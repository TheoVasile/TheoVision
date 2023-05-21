#include "bmesh.h"

Mesh::Mesh(float x, float y, float z)
{
    this->setOrigin(x, y, z);
}

void Mesh::addVert(array<float, 3> pos)
{
    this->addVert(pos[0], pos[1], pos[2]);
}

void Mesh::addVert(array<float, 3> pos, Edge *edge)
{
    this->addVert(pos[0], pos[1], pos[2], edge);
}

void Mesh::addVert(float x, float y, float z)
{
    this->vertices.push_back(new Vertex(x, y, z));
}

void Mesh::addVert(float x, float y, float z, Edge *edge)
{
    this->vertices.push_back(new Vertex(x, y, z, edge));
}

void Mesh::addEdge(Vertex *vertStart, Vertex *vertEnd)
{
    this->edges.push_back(new Edge(vertStart, vertEnd));
}

void Mesh::addFace(Edge *edge)
{
    this->faces.push_back(new Face(edge));
}

array<float, 3> Mesh::getOrigin()
{
    return this->origin;
}

void Mesh::setOrigin(float x, float y, float z)
{
    this->origin[0] = x;
    this->origin[1] = y;
    this->origin[2] = z;
}

void Mesh::setOrigin(array<float, 3> pos)
{
    this->setOrigin(pos[0], pos[1], pos[2]);
}

vector<Vertex *> Mesh::getVerts()
{
    return this->vertices;
}
vector<Edge *> Mesh::getEdges()
{
    return this->edges;
}
vector<Face *> Mesh::getFaces()
{
    return this->faces;
}
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
void Mesh::scale(float size)
{
    this->scale(size, size, size);
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
void Mesh::move(array<float, 3> translation)
{
    this->move(translation[0], translation[1], translation[2]);
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
void Mesh::rotate(float xrot, float yrot, float zrot)
{
    array<float, 3> rot = {xrot, yrot, zrot};
    this->rotate(rot);
}