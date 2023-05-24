#include "wireframe.h"

Wireframe::Wireframe(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){};

wxBitmap Wireframe::ApplyShading(int pixelSize){
    wxBitmap bitmap = Shader::ApplyShading(pixelSize);

    memDC.SelectObject(bitmap);

    wxColour colour(0, 0, 0);
    memDC.SetPen(colour);
    memDC.SetBrush(wxBrush(colour));
    for (Mesh *currMesh : scene->getMeshes()){
        currMesh = currMesh->getModifiedMesh();
        for (Edge *currEdge : currMesh->getEdges()) {
            array<float, 2> v1_coords = this->scene->getActiveCamera()->projectPoint(currEdge->vertStart->getPos(), this->screenDim);
            array<float, 2> v2_coords = this->scene->getActiveCamera()->projectPoint(currEdge->vertEnd->getPos(), this->screenDim);
            memDC.DrawLine((int)v1_coords[0], (int)v1_coords[1],(int)v2_coords[0], (int)v2_coords[1]);
        }
        for (Vertex *currVert : currMesh->getVerts()){
            array<float, 2> screenCoord = scene->getActiveCamera()->projectPoint(currVert->getPos(), this->screenDim);
            memDC.DrawCircle((int) screenCoord[0], (int) screenCoord[1], 1);
        }
    }

    return bitmap;
}