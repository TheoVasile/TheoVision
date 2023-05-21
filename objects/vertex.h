#ifndef VERTEX_H
#define VERTEX_H
#include <array>
#include <iostream>

using namespace std;

class Edge;

class Vertex{
    public:
        Vertex(float x, float y, float z);
        Vertex(float x, float y, float z, Edge *edge);
        array<float, 3> getPos();
        float getX();
        float getY();
        float getZ();
        void setPos(float x, float y, float z);
        void setPos(array<float, 3> pos);
        void setX(float x);
        void setY(float y);
        void setZ(float z);

        bool hasEdge();
        Edge *getEdge();
        void setEdge(Edge *edge);
    private:
        array<float, 3> pos;
        Edge *edge;
};
#endif