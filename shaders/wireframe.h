#ifndef WIREFRAME_H
#define WIREFRAME_H

#include "shader.h"

class Wireframe : public Shader{
    public:
        Wireframe(Scene *scene, wxSize screenDim);
        wxBitmap ApplyShading(int pixelSize = 10);
};

#endif