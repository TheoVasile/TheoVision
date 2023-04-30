#include <wx/wx.h>
#include "object.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Viewport : public wxFrame
{
public:
    Viewport(vector<Mesh *> meshes);
 
private:
    vector<Mesh *> meshes;
    void OnHello(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};