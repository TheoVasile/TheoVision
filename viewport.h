#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <wx/wx.h>
#include "scene.h"
#include "utils.h"
#include "./shaders/flatShader.h"
#include "./shaders/phongShader.h"
#include "./shaders/diffuseShader.h"
#include "./shaders/wireframe.h"
#include <iostream>
#include <list>

using namespace std;

class Viewport : public wxFrame
{
public:
    Viewport(Scene *scene);
 
private:
    wxPanel *panel;
    Shader *shader;
    Scene *scene;
    float fov;
    vec2 prev_cursor_pos;
    vec2 mouse_motion;
    int opID;
    void OnKeyUp(wxKeyEvent& event);
    void OnKeyPress(wxKeyEvent& event);
    void OnMouseMotion(wxMouseEvent& event);
    void OnMouseWheel(wxMouseEvent& event);
    void OnClick(wxMouseEvent& event);
    void OnShow(wxShowEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnExit(wxCommandEvent& event);
};
#endif