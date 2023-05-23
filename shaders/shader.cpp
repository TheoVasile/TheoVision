#include "shader.h"

Shader::Shader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera)
{
    this->meshes = meshes;
    this->gc = gc;
    this->screenDim = screenDim;
    this->camera = camera;
}

wxBitmap Shader::ApplyShading(int pixelSize)
{
    int depth = 24;
    // Create a wxBitmap with desired dimensions and color depth
    wxBitmap bitmap(this->screenDim.GetWidth(), this->screenDim.GetHeight(), depth);

    // Create a wxMemoryDC and associate it with the bitmap
    wxMemoryDC memDC;
    memDC.SelectObject(bitmap);

    // Draw onto the bitmap using the memory DC
    memDC.SetBackground(*wxWHITE_BRUSH);
    memDC.Clear();
    for (int x=0; x < this->screenDim.GetWidth(); x+=pixelSize){
        for (int y=0; y < this->screenDim.GetHeight(); y+=pixelSize){
            wxColour colour = getPixelColour(x, y);
            memDC.SetPen(colour);
            memDC.SetBrush(wxBrush(colour));
            memDC.DrawRectangle((int) x - pixelSize/2, (int) y - pixelSize, pixelSize, pixelSize);
        }
    }

    wxColor col(255, 0, 0);
    memDC.SetPen(wxPen(col));
    memDC.SetBrush(wxBrush(col));
    for (Mesh *currMesh : this->meshes){
        array<float, 2> originPos = this->camera->projectPoint(currMesh->getOrigin(), this->screenDim);
        memDC.DrawCircle((int)originPos[0], (int)originPos[1], 1);
    }

    return bitmap;
}

wxColour Shader::getPixelColour(int x, int y)
{
    return wxColour(255, 255, 255);
}