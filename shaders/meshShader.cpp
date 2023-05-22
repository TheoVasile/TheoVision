#include "MeshShader.h"

MeshShader::MeshShader(vector<Mesh *> meshes)
{
    this->meshes = meshes;
}

void MeshShader::LoadShader(const wxString& shaderFilePath)
{
    shaderFilePath = shaderFilePath;
    // Load the shader logic from the file
    // Perform any necessary initialization or parsing of the shader file
}

void MeshShader::ApplyShading(wxGraphicsContext* gc, const wxPoint& cameraPos)
{
    // Apply shading using the loaded shader logic
    // Use the shader code from the loaded file to perform shading
    // Iterate through the mesh faces and apply the shader logic
}