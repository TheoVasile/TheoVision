#include "main.h"

 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    float pos[3] = {0.0, 0.0, 0.0};
    Controller *controller = new Controller();
    controller->addUVSphere(0, 0, 10, 8, 16);
    Viewport *frame = new Viewport(controller);
    frame->Show(true);
    return true;
}