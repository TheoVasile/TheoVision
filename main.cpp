#include "main.h"

 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    float pos[3] = {0.0, 0.0, 0.0};
    Mesh *cube = new Mesh(pos);
    cube->add_vert(1.0, 1.0, 1.0);
    cube->add_vert(1.0, -1.0, 1.0);
    cube->add_vert(-1.0, 1.0, 1.0);
    cube->add_vert(-1.0, -1.0, 1.0);
    meshes.push_back(cube);
    Viewport *frame = new Viewport(meshes);
    frame->Show(true);
    return true;
}