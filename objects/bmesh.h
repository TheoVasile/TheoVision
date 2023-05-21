#ifndef BMESH_H
#define BMESH_H

#include <vector>
#include <wx/wx.h>
#include "../operations.h"
#include "vertex.h"
#include "edge.h"
#include "face.h"

using namespace std;

/**
 * @class Mesh
 * @brief Represents a mesh composed of vertices, edges, and faces.
 *
 * The Mesh class provides functionality to manipulate and operate on a mesh structure. It is based ont he winged edge data structure
 */
class Mesh{

public:
    /**
     * @brief Constructs a Mesh object with the given coordinates.
     *
     * @param x The x-coordinate of the mesh.
     * @param y The y-coordinate of the mesh.
     * @param z The z-coordinate of the mesh.
     */
    Mesh(float x, float y, float z);

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
    void addVert(array<float, 3> pos, Edge *edge);

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
    void addVert(float x, float y, float z, Edge *edge);

    /**
     * @brief Adds an edge to the mesh between the given start and end vertices.
     *
     * @param vertStart The starting vertex of the edge.
     * @param vertEnd   The ending vertex of the edge.
     */
    void addEdge(Vertex *vertStart, Vertex *vertEnd);

    /**
     * @brief Adds a face to the mesh with the given associated edge.
     *
     * @param edge The associated edge for the face.
     */
    void addFace(Edge *edge);

    /**
     * @brief Retrieves the origin coordinates of the mesh.
     *
     * @return An array of floats representing the origin coordinates [x, y, z].
     */
    array<float, 3> getOrigin();

    /**
     * @brief Assigns a new coordinate to the origin.
     * 
     * @param x The x-coordinate of the origin
     * @param y The y-coordinate of the origin
     * @param z The z-coordinate of the origin
     */
    void setOrigin(float x, float y, float z);

    /**
     * @brief Assigns a new coordinate to the origin.
     * 
     * @param pos An array of floats representing the new origin coordinates [x, y, z].
     */
    void setOrigin(array<float, 3> pos);

    /**
     * @brief Retrieves a vector of all vertices in the mesh.
     *
     * @return A vector of Vertex pointers representing all vertices in the mesh.
     */
    vector<Vertex *> getVerts();

    /**
     * @brief Retrieves a vector of all edges in the mesh.
     *
     * @return A vector of Edge pointers representing all edges in the mesh.
     */
    vector<Edge *> getEdges();

    /**
     * @brief Retrieves a vector of all faces in the mesh.
     *
     * @return A vector of Face pointers representing all faces in the mesh.
     */
    vector<Face *> getFaces();

    /**
     * @brief Scales the mesh by the given scale factors for each axis.
     *
     * @param x The scaling factor for the x-axis.
     * @param y The scaling factor for the y-axis.
     * @param z The scaling factor for the z-axis.
     */
    void scale(float x, float y, float z);

    /**
     * @brief Scales the mesh uniformly by the given size.
     *
     * @param size The scaling factor to be applied uniformly to all axes.
     */
    void scale(float size);

    /**
     * @brief Moves the mesh by the given translation in each axis.
     *
     * @param x The translation along the x-axis.
     * @param y The translation along the y-axis.
     * @param z The translation along the z-axis.
     */
    void move(float x, float y, float z);

    /**
     * @brief Moves the mesh by the given translation vector.
     *
     * @param translation The translation vector as an array of floats [x, y, z].
     */
    void move(array<float, 3> translation);

    /**
     * @brief Rotates the mesh by the given rotation angles.
     *
     * @param rot The rotation angles as an array of floats [xrot, yrot, zrot].
     */
    void rotate(array<float, 3> rot);

    /**
     * @brief Rotates the mesh by the given rotation angles for each axis.
     *
     * @param xrot The rotation angle around the x-axis.
     * @param yrot The rotation angle around the y-axis.
     * @param zrot The rotation angle around the z-axis.
     */
    void rotate(float xrot, float yrot, float zrot);

private:
    array<float, 3> origin; /**< The origin coordinates of the mesh. */
    vector<Vertex*> vertices; /**< The collection of vertices in the mesh. */
    vector<Edge*> edges; /**< The collection of edges in the mesh. */
    vector<Face*> faces; /**< The collection of faces in the mesh. */
};

#endif