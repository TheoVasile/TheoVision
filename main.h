#include <wx/wxprec.h>
#include <iostream>
#include <vector>
#include <array>
#include "display.h"
#include "./objects/sunLight.h"
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

using namespace std;

class MyApp : public wxApp
{
public:
    vector<Mesh *> meshes;
    virtual bool OnInit();
};