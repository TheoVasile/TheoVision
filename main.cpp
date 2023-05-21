#include "main.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    std::cout << __cplusplus << std::endl;
    Controller *controller = new Controller();
    controller->addUVSphere(0, 0, 20, 16, 32);
    //controller->addCube(0, 0, 20);
    Viewport *frame = new Viewport(controller);
    frame->Show(true);
    return true;
}