#ifndef VERTEX_H
#define VERTEX_H

#include <array>
#include <iostream>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class Edge;

class Vertex{
    public:
        Vertex(vec3 pos);
        Vertex(vec3 pos, vector<Edge *> edges);
        Vertex(array<float, 3> pos);
        Vertex(array<float, 3> pos, vector<Edge *> edges);
        Vertex(float x, float y, float z);
        Vertex(float x, float y, float z, vector<Edge *> edges);
        vec3 getPos();
        float getX();
        float getY();
        float getZ();
        void setPos(vec3 pos);
        void setPos(float x, float y, float z);
        void setPos(array<float, 3> pos);
        void setX(float x);
        void setY(float y);
        void setZ(float z);

        vector<Edge *> getEdges();
        void setEdges(vector<Edge *> edges);
        void addEdge(Edge *edge);
    private:
        vec3 pos;
        vector<Edge *> edges;
};
#endif