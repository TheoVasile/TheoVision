#include "main.h"
#include "display.h"

 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    Camera *frame = new Camera();
    frame->Show(true);
    return true;
}