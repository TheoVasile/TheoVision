#include "flatShader.h"

FlatShader::FlatShader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera){
    this->meshes = meshes;
    this->gc = gc;
    this->screenDim = screenDim;
    this->camera = camera;
}

void FlatShader::drawPoly(vector<vec3> positions)
{
    vec3 startPos = positions[0];
    // Break the polygon into tris
    for (int i=2; i < positions.size(); i++){
        wxGraphicsPath path = gc->CreatePath();
        vec2 screenCoord = camera->projectPoint(startPos, screenDim);
        path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
        screenCoord = camera->projectPoint(positions[i-1], screenDim);
        path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
        screenCoord = camera->projectPoint(positions[i], screenDim);
        path.AddLineToPoint((int)screenCoord[0], (int)screenCoord[1]);
        path.CloseSubpath();
        
        vec3 v1 = positions[i-1] - startPos;
        vec3 v2 = positions[i] - startPos;

        vec3 faceNormals = normalize(cross(v1, v2));
        float fresnel = dot(faceNormals, camera->getNormal());
        if (fresnel > 0) {
            wxColour brushColour((int) (fresnel * 255), (int) (fresnel * 255), (int) (fresnel * 255));

            gc->SetPen(brushColour);
            gc->SetBrush(brushColour);
            gc->StrokePath(path);
            gc->FillPath(path);
        }
    }
}

void FlatShader::ApplyShading()
{
    // Loop through meshes
    for (int i=0; i < this->meshes.size(); i++) {
        Mesh *currMesh = this->meshes[i];
        // Loop through faces
        for (int j=0; j < currMesh->getFaces().size(); j++){
            Face *currFace = currMesh->getFace(j);
            this->drawPoly(currFace->getPoints());
        }
    }
}