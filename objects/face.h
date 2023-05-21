#ifndef FACE_H
#define FACE_H

class Edge;

class Face{
    public:
        Face(Edge *edge);
        void setEdge(Edge *edge);
        Edge *getEdge();
    private:
        Edge *edge;
};
#endif