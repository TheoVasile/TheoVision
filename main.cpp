#include "main.h"

 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    float pos[3] = {0.0, 0.0, 0.0};
    Controller *controller = new Controller();
    controller->addCube(0, 0, 0);
    Viewport *frame = new Viewport(controller);
    frame->Show(true);
    return true;
}