#ifndef MESHSHADER_H
#define MESHSHADER_H

#include <wx/wx.h>
#include "../objects/bmesh.h"
#include <vector>
#include <iostream>

using namespace std;

class MeshShader
{
public:
    MeshShader(vector<Mesh *> meshes);
    void LoadShader(const wxString& shaderFilePath);
    void ApplyShading(wxGraphicsContext* gc, const wxPoint& cameraPos);

private:
    vector<Mesh *> meshes;
    wxString shaderFilePath;
};

#endif