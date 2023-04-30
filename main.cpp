#include "main.h"

 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    float pos[3] = {0.0, 0.0, 0.0};
    Mesh *cube = new Mesh(pos);
    meshes.push_back(cube);
    Viewport *frame = new Viewport(meshes);
    frame->Show(true);
    return true;
}