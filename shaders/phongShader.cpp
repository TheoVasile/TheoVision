#include "phongShader.h"

PhongShader::PhongShader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera)
{
    this->meshes = meshes;
    this->gc = gc;
    this->screenDim = screenDim;
    this->camera = camera;
}

wxBitmap PhongShader::ApplyShading(int pixelSize)
{
    int depth = 24;
    int x = 10;
    int y = 10;
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
            //memDC.DrawPoint(x, y);
            memDC.DrawRectangle(x, y, pixelSize, pixelSize);
        }
    }

    return bitmap;
}

wxColour PhongShader::getPixelColour(int x, int y)
{
    Ray *ray = this->camera->castRay(x, y, this->screenDim);
    ray->cast(this->meshes);
    if (ray->hasHit) {
        int distance = (int) pow(255 / dist(ray->getCollisionPoint(), camera->getPos()), 2);
        return wxColour(distance, distance, distance);
    }
    return wxColour(255, 255, 255);
}