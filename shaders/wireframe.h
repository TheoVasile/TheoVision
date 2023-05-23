#ifndef WIREFRAME_H
#define WIREFRAME_H

#include "shader.h"

class Wireframe : public Shader{
    public:
        Wireframe(vector<Mesh *> meshes, wxGraphicsContext *gc, wxSize screenDim, Camera *camera);
        wxBitmap ApplyShading(int pixelSize = 10);
};

#endif