#include <wx/wx.h>
#include "object.h"
#include <iostream>
#include <list>

using namespace std;

class Viewport : public wxFrame
{
public:
    Viewport(vector<Mesh *> meshes);
 
private:
    vector<Mesh *> meshes;
    array<float, 3> normal;
    array<float, 3> vertical;
    float fov;
    array<float, 3> pos;
    void OnHello(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    array<float, 2> projectPoint(float x, float y, float z);
    array<float, 2> projectPoint(array<float, 3> pos);
};