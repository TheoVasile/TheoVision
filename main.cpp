#include "main.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Scene *scene = new Scene();
    //scene->addUVSphere(1, 0, 20, 4, 8);
    scene->addLight(new PointLight(0, 1, 10, 10));
    scene->addCube(0, 0, 20);
    scene->addCube(1, 0, 10);
    Viewport *frame = new Viewport(scene);
    frame->Show(true);
    return true;
}