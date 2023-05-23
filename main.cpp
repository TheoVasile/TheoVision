#include "main.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Scene *scene = new Scene();
    //scene->addUVSphere(0, 0, 20, 4, 8);
    scene->addLight(new PointLight(0, 1, 20, 10));
    scene->addCube(0, 0, 20);
    Viewport *frame = new Viewport(scene);
    frame->Show(true);
    return true;
}