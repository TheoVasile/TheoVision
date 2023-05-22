#ifndef FLATSHADER_H
#define FLATSHADER_H

#include "../camera.h"
#include "../objects/bmesh.h"
#include <wx/wx.h>
#include <vector>
#include <iostream>

using namespace std;

class FlatShader{
    public:
        FlatShader(vector<Mesh *> meshes);
        void ApplyShading(wxGraphicsContext *gc, wxSize screenDim, Camera *camera);
    private:
        vector<Mesh *> meshes;
};
#endif