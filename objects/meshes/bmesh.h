#ifndef BMESH_H
#define BMESH_H

#include <glm/glm.hpp>
#include <array>
#include <vector>
#include "../object.h"
#include "../../utils.h"
#include "../../modifiers/modifier.h"
#include "../../materials/material.h"

using namespace glm;
using namespace std;

class Edge;
class Face;
class Modifier;

class Vertex{
    public:
        Vertex(vec3 pos);
        Vertex(vec3 pos, vector<Edge *> edges);
        Vertex(array<float, 3> pos);
        Vertex(array<float, 3> pos, vector<Edge *> edges);
        Vertex(float x, float y, float z);
        Vertex(float x, float y, float z, vector<Edge *> edges);

        vector<Edge *> getEdges();
        void setEdges(vector<Edge *> edges);
        void addEdge(Edge *edge);
        vec3 pos;
        vector<Edge *> edges;
};

class Edge{
    public:
        Edge(Vertex *vertStart, Vertex *vertEnd);
        Edge(Edge *edge);
        void setNextEdge(Edge *edge);
        Edge *getNextEdge();
        void setPreviousEdge(Edge *edge);
        Edge *getPreviousEdge();
        vec3 getMidpoint();
        Vertex *vertStart;
        Vertex *vertEnd;
        Edge *pair;
        Face *face;
        Edge *nextEdge;
        Edge *previousEdge;
};

class Face{
    public:
        Face(Edge *edge);
        void flipNormal();
        vec3 getMidpoint();
        vec3 getNormal();
        vector<vec3> getPoints();
        vector<array<vec3, 3> > getTris();
        void setEdge(Edge *edge);
        Edge *getEdge();
    private:
        float normDir;
        Edge *edge;
};

class Mesh : public Object{
    public:
        /**
         * @brief Constructs a Mesh object with the given coordinates.
         *
         * @param x The x-coordinate of the mesh.
         * @param y The y-coordinate of the mesh.
         * @param z The z-coordinate of the mesh.
         */
        Mesh(vec3 pos);
        Mesh(float x, float y, float z);
        Mesh(array<float, 3> pos);

        void flipNormals();

        void addVert(array<float, 3> pos);
        void addVert(vec3 pos);
        void addVert(array<float, 3> pos, vector<Edge *> edges);
        void addVert(vec3 pos, vector<Edge *> edges);
        void addVert(float x, float y, float z);
        void addVert(float x, float y, float z, vector<Edge *> edges);
        void addVert(Vertex *vert);

        void addEdge(Vertex *vertStart, Vertex *vertEnd);
        void addEdge(int vertStartIndex, int vertEndIndex);
        void addEdge(Edge *edge);

        void addFace(Edge *edge, bool pair=false);
        void addFace(int edgeIndex, bool pair=false);
        void addFace(Face *face);

        vector<Vertex *> getVerts();

        Vertex *getVertex(int index);

        vector<Edge *> getEdges();

        Edge *getEdge(int index);

        vector<Face *> getFaces();

        Face *getFace(int index);

        void addModifier(Modifier *modifier);

        Mesh *getModifiedMesh();

        void scale(vec3 rot) override;
        using Object::scale;

        void move(vec3 translation) override;
        using Object::move;

        void rotate(vec3 rot) override;
        using Object::rotate;

        Mesh *copy() override;

        Material *material;

    protected:
        vector<Modifier *> modifiers;
        vector<Vertex*> vertices; /**< The collection of vertices in the mesh. */
        vector<Edge*> edges; /**< The collection of edges in the mesh. */
        vector<Face*> faces; /**< The collection of faces in the mesh. */
};

#endif