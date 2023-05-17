#include "main.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    std::cout << __cplusplus << std::endl;
    float pos[3] = {0.0, 0.0, 0.0};
    Controller *controller = new Controller();
    //controller->addCube(0, 0, 10);
    controller->addUVSphere(0, 0, 20, 16, 8);
    Viewport *frame = new Viewport(controller);
    frame->Show(true);
    return true;
}