#ifndef DISPLAY_H
#define DISPLAY_H

#include <wx/wx.h>
#include "scene.h"
#include "utils.h"
#include "./shaders/flatShader.h"
#include "./shaders/phongShader.h"
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
    array<float, 3> normal;
    array<float, 3> vertical;
    float fov;
    float prev_cursor_pos[2];
    float mouse_motion[2];
    char operation;
    array<float, 3> pos;
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