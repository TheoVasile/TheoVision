#include "flatShader.h"

FlatShader::FlatShader(vector<Mesh *> meshes){
    this->meshes = meshes;
}

void FlatShader::ApplyShading(wxGraphicsContext *gc, wxSize screenDim, Camera *camera)
{
    // Loop through meshes
    for (int i=0; i < this->meshes.size(); i++) {
        Mesh *currMesh = this->meshes[i];
        // Loop through faces
        for (int j=0; j < currMesh->getFaces().size(); j++){
            Face *currFace = currMesh->getFace(j);

            // Trace the path of the edges until the face is completed.
            wxGraphicsPath path = gc->CreatePath();
            Edge *startEdge = currFace->getEdge();
            Edge *currEdge = startEdge;
            if (currEdge == NULL){
                wxPrintf("very very bad\n");
                continue;
            }
            while (currEdge->edgeNextCW != startEdge){
                Vertex *currVert = currEdge->vertEnd;
                array<float, 2> screenCoord = camera->projectPoint(currVert->getPos(), screenDim);
                path.MoveToPoint((int)screenCoord[0], (int)screenCoord[1]);
                path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
                if (currEdge->edgeNextCW == NULL){
                    wxPrintf("NO EDGE\n");
                    break;
                }
                currEdge = currEdge->edgeNextCW;
            }
            path.CloseSubpath();
        }
    }
}