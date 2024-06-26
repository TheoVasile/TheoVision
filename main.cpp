#include "main.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Scene *scene = new Scene();
    scene->addUVSphere(0, 0, 20, 8, 16);
    scene->addLight(new PointLight(-1, 0, 10, 100));
    //scene->addCube(0, 0, 20);
    scene->addCube(0, -2, 10);
    Viewport *frame = new Viewport(scene);
    frame->Show(true);
    return true;
}