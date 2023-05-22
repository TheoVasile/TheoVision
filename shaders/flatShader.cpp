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
            gc->SetPen( *wxRED_PEN );
            gc->SetBrush(*wxRED_BRUSH);
            wxGraphicsPath path = gc->CreatePath();
            Edge *startEdge = currFace->getEdge();
            Edge *currEdge = startEdge;
            if (currEdge == NULL){
                wxPrintf("very very bad\n");
                continue;
            }

            Vertex *currVert = currEdge->vertStart;
            array<float, 2> screenCoord = camera->projectPoint(currVert->getPos(), screenDim);
            path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
            
            while (currEdge->nextEdge != startEdge){
                currVert = currEdge->vertEnd;
                screenCoord = camera->projectPoint(currVert->getPos(), screenDim);
                path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
                if (currEdge->nextEdge == NULL){
                    wxPrintf("NO EDGE\n");
                    break;
                }
                currEdge = currEdge->nextEdge;
                wxPrintf("(%f, %f)\n", screenCoord[0], screenCoord[1]);
            }
            path.CloseSubpath();

            gc->FillPath(path);
        }
    }
}