#include "main.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Scene *scene = new Scene();
    //scene->addUVSphere(0, 0, 20, 4, 8);
    scene->addLight(new PointLight(0, 1, 10, 10));
    scene->addCube(0, 0, 20);
    scene->getMeshes()[0]->addModifier(new SubdivisionSurface());
    Viewport *frame = new Viewport(scene);
    frame->Show(true);
    return true;
}