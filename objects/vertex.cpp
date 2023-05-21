#include "vertex.h"
#include <wx/wx.h>

Vertex::Vertex(float x, float y, float z)
{
    this->setPos(x, y, z);
    this->edge = NULL;
}

Vertex::Vertex(float x, float y, float z, Edge *edge)
{
    this->setPos(x, y, z);
    this->setEdge(edge);
}

array<float, 3> Vertex::getPos()
{
    return this->pos;
}

float Vertex::getX()
{
    return this->pos[0];
}
float Vertex::getY()
{
    return this->pos[1];
}
float Vertex::getZ()
{
    return this->pos[2];
}

void Vertex::setPos(float x, float y, float z)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}

void Vertex::setPos(array<float, 3> pos)
{
    this->setPos(pos[0], pos[1], pos[2]);
}

void Vertex::setX(float x)
{
    this->pos[0] = x;
}

void Vertex::setY(float y)
{
    this->pos[1] = y;
}

void Vertex::setZ(float z)
{
    this->pos[2] = z;
}

Edge *Vertex::getEdge(){
    return this->edge;
}

void Vertex::setEdge(Edge *edge){
    this->edge = edge;
}

bool Vertex::hasEdge(){
    return (this->edge != NULL);
}