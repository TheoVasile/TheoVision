#ifndef BMESH_H
#define BMESH_H

#include <wx/wx.h>
#include "object.h"
#include "../modifiers/modifier.h"
#include "../utils.h"
#include "vertex.h"
#include "edge.h"
#include "face.h"

using namespace std;

class Modifier;

/**
 * @class Mesh
 * @brief Represents a mesh composed of vertices, edges, and faces.
 *
 * The Mesh class provides functionality to manipulate and operate on a mesh structure. It is based ont he winged edge data structure
 */
class Mesh : public Object{

public:
    /**
     * @brief Constructs a Mesh object with the given coordinates.
     *
     * @param x The x-coordinate of the mesh.
     * @param y The y-coordinate of the mesh.
     * @param z The z-coordinate of the mesh.
     */
    Mesh(float x, float y, float z);
    Mesh(array<float, 3> pos);

    /**
     * @brief Adds a vertex to the mesh with the given position.
     *
     * @param pos The position of the vertex as an array of floats [x, y, z].
     */
    void addVert(array<float, 3> pos);

    /**
     * @brief Adds a vertex to the mesh with the given position and associated edge.
     *
     * @param pos  The position of the vertex as an array of floats [x, y, z].
     * @param edge The associated edge for the vertex.
     */
    void addVert(array<float, 3> pos, vector<Edge *> edges);

    /**
     * @brief Adds a vertex to the mesh with the given coordinates.
     *
     * @param x The x-coordinate of the vertex.
     * @param y The y-coordinate of the vertex.
     * @param z The z-coordinate of the vertex.
     */
    void addVert(float x, float y, float z);

    /**
     * @brief Adds a vertex to the mesh with the given coordinates and associated edge.
     *
     * @param x    The x-coordinate of the vertex.
     * @param y    The y-coordinate of the vertex.
     * @param z    The z-coordinate of the vertex.
     * @param edge The associated edge for the vertex.
     */
    void addVert(float x, float y, float z, vector<Edge *> edges);

    void addVert(Vertex *vert);

    /**
     * @brief Adds an edge to the mesh between the given start and end vertices.
     *
     * @param vertStart The starting vertex of the edge.
     * @param vertEnd   The ending vertex of the edge.
     */
    void addEdge(Vertex *vertStart, Vertex *vertEnd);

    /**
     * @brief Adds an edge to the mesh between the vertices corresponding to the start and end indices.
     * 
     * @param vertStartIndex The index corresponding to the starting vertex of the edge.
     * @param vertEndIndex   The index corresponding to the ending vertex of the edge.
     */
    void addEdge(int vertStartIndex, int vertEndIndex);

    void addEdge(Edge *edge);

    /**
     * @brief Adds a face to the mesh with the given associated edge.
     *
     * @param edge The associated edge for the face.
     */
    void addFace(Edge *edge, bool pair=false);

    /**
     * @brief Adds a face to the mesh with the associated edge given by the provided index.
     * 
     * @param edgeIndex The index of the associated edge for the face.
     */
    void addFace(int edgeIndex, bool pair=false);

    void addFace(Face *face);

    
    using Object::getOrigin;

    using Object::setOrigin;

    /**
     * @brief Retrieves a vector of all vertices in the mesh.
     *
     * @return A vector of Vertex pointers representing all vertices in the mesh.
     */
    vector<Vertex *> getVerts();

    /**
     * @brief Returns a vertex at the specified index
     * 
     * @param index the index to retrieve the vertex
     * 
     * @return A vertex
     */
    Vertex *getVertex(int index);

    /**
     * @brief Retrieves a vector of all edges in the mesh.
     *
     * @return A vector of Edge pointers representing all edges in the mesh.
     */
    vector<Edge *> getEdges();

    /**
     * @brief Returns the edge at the specified index
     * 
     * @param index the index to retrieve the edge
     * 
     * @return the edge
     */
    Edge *getEdge(int index);

    /**
     * @brief Retrieves a vector of all faces in the mesh.
     *
     * @return A vector of Face pointers representing all faces in the mesh.
     */
    vector<Face *> getFaces();

    /**
     * @brief Returns a face at the specified index
     * 
     * @param index the index to retrieve the face
     * 
     * @return A face
     */
    Face *getFace(int index);

    void addModifier(Modifier *modifier);

    Mesh *getModifiedMesh();

    /**
     * @brief Scales the mesh by the given scale factors for each axis.
     *
     * @param x The scaling factor for the x-axis.
     * @param y The scaling factor for the y-axis.
     * @param z The scaling factor for the z-axis.
     */
    void scale(float x, float y, float z) override;
    using Object::scale;

    /**
     * @brief Moves the mesh by the given translation in each axis.
     *
     * @param x The translation along the x-axis.
     * @param y The translation along the y-axis.
     * @param z The translation along the z-axis.
     */
    void move(float x, float y, float z) override;
    using Object::move;

    /**
     * @brief Rotates the mesh by the given rotation angles.
     *
     * @param rot The rotation angles as an array of floats [xrot, yrot, zrot].
     */
    void rotate(array<float, 3> rot) override;
    using Object::rotate;

    Mesh *copy() override;

protected:
    vector<Modifier *> modifiers;
    vector<Vertex*> vertices; /**< The collection of vertices in the mesh. */
    vector<Edge*> edges; /**< The collection of edges in the mesh. */
    vector<Face*> faces; /**< The collection of faces in the mesh. */
};

#endif