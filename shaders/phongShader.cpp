#include "phongShader.h"

PhongShader::PhongShader(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera)
{
    this->meshes = meshes;
    this->gc = gc;
    this->screenDim = screenDim;
    this->camera = camera;
}

wxBitmap PhongShader::ApplyShading()
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
    for (int x=0; x < this->screenDim.GetWidth(); x++){
        for (int y=0; y < this->screenDim.GetHeight(); y++){
            //wxColour colour((int) x * 255 / this->screenDim.GetWidth(), (int) y * 255 / this->screenDim.GetHeight(), 255);
            memDC.SetPen(getPixelColour(x, y));
            memDC.DrawPoint(x, y);
        }
    }

    return bitmap;
}

wxColour PhongShader::getPixelColour(int x, int y)
{
    Ray *ray = this->camera->castRay(x, y, this->screenDim);
    ray->cast(this->meshes);
    if (ray->hasHit) {
        int distance = (int) 255 / dist(ray->getCollisionPoint(), camera->getPos());
        wxPrintf("%d\n", distance);
        return wxColour(distance, distance, distance);
    }
    return wxColour(0, 0, 0);
}