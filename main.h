#include <wx/wxprec.h>
#include <iostream>
#include <vector>
#include <array>
#include "./modifiers/subdivisionSurface.h"
#include "viewport.h"
#include "./objects/lights/sunLight.h"
#include "./objects/lights/pointLight.h"
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

using namespace std;

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};