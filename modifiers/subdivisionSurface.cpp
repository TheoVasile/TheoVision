#include "subdivisionSurface.h"

SubdivisionSurface::SubdivisionSurface(int subdivisions):Modifier(){
    this->subdivisions = subdivisions;
};

Mesh *SubdivisionSurface::apply(Mesh *mesh) {
    for (int i=0; i < subdivisions; i++){
        int originalEdgeCount = mesh->getEdges().size();
        for (Face *currFace : mesh->getFaces()) {
            // Face point is average of all surrounding verts
            Vertex *faceVert = new Vertex(currFace->getMidpoint());
            mesh->addVert(faceVert);

            Edge *startEdge = currFace->getEdge();
            Edge *currEdge = startEdge;
            do {
                // Edge point is the average of neighboring facepoints and edge center
                vec3 edgePoint(0, 0, 0);
                if (currEdge->face){
                    edgePoint = edgePoint + currEdge->face->getMidpoint();
                } if (currEdge->pair->face){
                    edgePoint = edgePoint + currEdge->pair->face->getMidpoint();
                }
                edgePoint = (edgePoint * 0.5f + currEdge->getMidpoint()) * 0.5f;
                Vertex *edgeVert = new Vertex(edgePoint);
                mesh->addVert(edgeVert);
                mesh->addEdge(edgeVert, faceVert);
                currEdge = currEdge->nextEdge;
            } while (currEdge != startEdge);
        }
    }
    return mesh;
}