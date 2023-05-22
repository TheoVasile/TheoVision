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
            vector<array<float, 3> > vertPositions;
            Face *currFace = currMesh->getFace(j);

            // Trace the path of the edges until the face is completed.
            wxGraphicsPath path = gc->CreatePath();
            Edge *startEdge = currFace->getEdge();
            Edge *currEdge = startEdge;
            if (currEdge == NULL){
                throw runtime_error("Face incorrectly defined.\n");
            }

            Vertex *currVert = currEdge->vertStart;
            vertPositions.push_back(currVert->getPos());
            array<float, 2> screenCoord = camera->projectPoint(currVert->getPos(), screenDim);
            path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
            while (currEdge->nextEdge != startEdge){
                currVert = currEdge->vertEnd;
                vertPositions.push_back(currVert->getPos());
                screenCoord = camera->projectPoint(currVert->getPos(), screenDim);
                path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
                if (currEdge->nextEdge == NULL){
                    throw runtime_error("Face is not complete.\n");
                }
                currEdge = currEdge->nextEdge;
            }
            path.CloseSubpath();

            array<float, 3> faceNormals = normalize(cross(subtract(vertPositions[1], vertPositions[0]), subtract(vertPositions[2], vertPositions[0])));
            float fresnel = dot(faceNormals, camera->getNormal());

            wxColour brushColour((int) (fresnel * 255), (int) (fresnel * 255), (int) (fresnel * 255));

            gc->SetBrush(brushColour);
            gc->FillPath(path);
        }
    }
}