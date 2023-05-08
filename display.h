#include <wx/wx.h>
#include "controller.h"
#include <iostream>
#include <list>

using namespace std;

class Viewport : public wxFrame
{
public:
    Viewport(Controller *controller);
 
private:
    wxPanel * panel;
    Controller *controller;
    array<float, 3> normal;
    array<float, 3> vertical;
    float fov;
    array<float, 3> pos;
    void OnGrab(wxKeyEvent& event);
    void OnShow(wxShowEvent& event);
    void OnHello(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    array<float, 2> projectPoint(float x, float y, float z);
    array<float, 2> projectPoint(array<float, 3> pos);
};