#include "viewport.h"


Viewport::Viewport(Scene *scene)
    : wxFrame(NULL, wxID_ANY, "TheoVision 3D", wxDefaultPosition, wxSize(800, 600), wxDEFAULT_FRAME_STYLE | wxWS_EX_PROCESS_UI_UPDATES)
{
    wxPanel * panel = new wxPanel(this);
    scene->screenDim = wxSize(800, 600);
    this->scene = scene;
    this->opID = 0;
    this->shader = new GGXShader(this->scene, this->GetSize());

    SetBackgroundColour(wxColour(* wxWHITE));

    // Make sure the frame has focus and keyboard input is enabled
    SetFocus();
    Bind(wxEVT_SHOW, &Viewport::OnShow, this);
    if ((GetWindowStyleFlag() & wxWS_EX_PROCESS_UI_UPDATES) != wxWS_EX_PROCESS_UI_UPDATES)
    {
        wxLogError("Keyboard input not enabled on frame");
    }

    // Define graphics behavior
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(Viewport::OnPaint));
    this->Centre();

    // Define menu
    wxMenu *menuFile = new wxMenu;
    // Define exit
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    panel->Bind(wxEVT_KEY_DOWN, &Viewport::OnKeyPress, this);
    panel->Bind(wxEVT_KEY_UP, &Viewport::OnKeyUp, this);
    panel->Bind(wxEVT_MOTION, &Viewport::OnMouseMotion, this);
    panel->Bind(wxEVT_LEFT_DOWN, &Viewport::OnClick, this);
    panel->Bind(wxEVT_MOUSEWHEEL, &Viewport::OnMouseWheel, this);
    Bind(wxEVT_MENU, &Viewport::OnExit, this, wxID_EXIT);
}


void Viewport::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void Viewport::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);

    dc.DrawBitmap(this->shader->ApplyShading(5), 0, 0);

    switch(opID){
        case ID_SCALE:{
            vec2 p1 = this->scene->getActiveCamera()->projectPoint(this->scene->getMedianPoint(), this->scene->screenDim);
            vec2 p2 = {this->prev_cursor_pos[0], this->prev_cursor_pos[1]};
            
            wxPen pen(wxColour(0, 0, 0), 1, wxPENSTYLE_SHORT_DASH);
            dc.SetPen(pen);
            dc.DrawLine((int) p1[0], (int) p1[1], (int) p2[0], (int) p2[1]);
            break;
        }
    }
}

void Viewport::OnMouseMotion(wxMouseEvent& event)
{
    this->mouse_motion[0] = event.GetX() - this->prev_cursor_pos[0];
    this->prev_cursor_pos[0] = event.GetX();
    this->mouse_motion[1] = event.GetY() - this->prev_cursor_pos[1];
    this->prev_cursor_pos[1] = event.GetY();
    switch(this->opID){
        case ID_GRAB: {
            float movementFactor = distance(scene->getActiveCamera()->getOrigin(), scene->getSelected()[0]->getOrigin()) / 1000;
            scene->move(cross(scene->getActiveCamera()->getNormal(), scene->getActiveCamera()->getVertical()) * (-this->mouse_motion[0] * movementFactor));
            scene->move(scene->getActiveCamera()->getVertical() * this->mouse_motion[1] * movementFactor);
            break;
        }
        case ID_ROTATE: {
            scene->rotate(0, mouse_motion[0] * M_PI / 180, -mouse_motion[1] * M_PI / 180);
            break;
        }
        case ID_SCALE:
            vec2 screenOrigin = scene->getActiveCamera()->projectPoint(scene->getMedianPoint(), scene->screenDim);
            vec2 dir = this->prev_cursor_pos - screenOrigin;
            float movementFactor = (this->mouse_motion[0] * dir[0] + this->mouse_motion[1] * dir[1]) / (pow(dir[0], 2) + pow(dir[1], 2));
            scene->scale(movementFactor+1);
            break;
    }
    Refresh();
}

void Viewport::OnMouseWheel(wxMouseEvent& event)
{
    float rotation = event.GetWheelRotation();
    if (rotation != 0) {
        // Scroll up event detected
        this->scene->getActiveCamera()->rotate(0, 0, rotation * M_PI / 360);
    }
    Refresh();
    event.Skip();
}

void Viewport::OnClick(wxMouseEvent& event)
{
    if (this->opID != 0) {
        this->opID = 0;
    } else {
        this->scene->select(event.GetX(), event.GetY());
    }
}

void Viewport::OnKeyPress(wxKeyEvent& event)
{
    switch(event.GetUnicodeKey()){
        case 'G':
            this->opID = ID_GRAB;
            break;
        case 'R':
            this->opID = ID_ROTATE;
            break;
        case 'S':
            this->opID = ID_SCALE;
            break;
        case 'W':
            wxPrintf("zoom\n");
            this->opID = ID_ZOOM_IN;
            break;
    }
    Refresh();
    event.Skip();
}

void Viewport::OnKeyUp(wxKeyEvent& event){
    switch(event.GetUnicodeKey()){
        case 'W':
            wxPrintf("zoom end\n");
            this->opID = 0;
            break;
    }
    Refresh();
    event.Skip();
}

void Viewport::OnShow(wxShowEvent& event)
{
    // Call SetFocus to ensure the window has keyboard focus
    SetFocus();

    // Unbind the OnShow handler since we only need to call SetFocus once
    Unbind(wxEVT_SHOW, &Viewport::OnShow, this);
}