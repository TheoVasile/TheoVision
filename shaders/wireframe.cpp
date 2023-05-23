#include "wireframe.h"

Wireframe::Wireframe(Scene *scene, wxSize screenDim) : Shader(scene, screenDim){};

wxBitmap Wireframe::ApplyShading(int pixelSize){
    int depth = 24;
    // Create a wxBitmap with desired dimensions and color depth
    wxBitmap bitmap(this->screenDim.GetWidth(), this->screenDim.GetHeight(), depth);

    // Create a wxMemoryDC and associate it with the bitmap
    wxMemoryDC memDC;
    memDC.SelectObject(bitmap);

    // Draw onto the bitmap using the memory DC
    memDC.SetBackground(*wxWHITE_BRUSH);
    memDC.Clear();
    wxColour colour(0, 0, 0);
    memDC.SetPen(colour);
    memDC.SetBrush(wxBrush(colour));

    for (Mesh *currMesh : scene->getMeshes()){
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