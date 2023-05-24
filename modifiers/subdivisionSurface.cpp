#include "subdivisionSurface.h"

SubdivisionSurface::SubdivisionSurface():Modifier(){};

Mesh *SubdivisionSurface::apply(Mesh *mesh) {
    for (Face *currFace : mesh->getFaces()) {
        array<float, 3> facePoint = currFace->getMidpoint();
        Vertex *faceVert = new Vertex(facePoint);
        mesh->addVert(faceVert);
        Edge *startEdge = currFace->getEdge();
        Edge *currEdge = startEdge;
        int x = 0;
        while (currEdge->nextEdge != startEdge) {
            array<float, 3> edgePoint = {0, 0, 0};
            if (currEdge->face){
                edgePoint = add(edgePoint, currEdge->face->getMidpoint());
            } else {wxPrintf("No face\n");}
            if (currEdge->pair->face){
                edgePoint = add(edgePoint, currEdge->pair->face->getMidpoint());
            } else {wxPrintf("No face\n");}
            
            edgePoint = multiply(edgePoint, 0.5);
            edgePoint = multiply(add(edgePoint, currEdge->getMidpoint()), 0.5);
            Vertex *edgeVert = new Vertex(edgePoint);
            mesh->addVert(edgeVert);
            mesh->addEdge(edgeVert, faceVert);
            currEdge = currEdge->nextEdge;
            wxPrintf("%d\n", x);
            x++;
        }
    }
    return mesh;
}