#include "display.h"


Viewport::Viewport(Scene *scene)
    : wxFrame(NULL, wxID_ANY, "TheoVision 3D", wxDefaultPosition, wxSize(800, 600), wxDEFAULT_FRAME_STYLE | wxWS_EX_PROCESS_UI_UPDATES)
{
    wxPanel * panel = new wxPanel(this);
    this->scene = scene;

    wxPaintDC dc(this);
    wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
    this->shader = new DiffuseShader(this->scene, this->GetSize());

    SetBackgroundColour(wxColour(* wxWHITE));

    // Initialize default attributes
    this->normal = (array<float, 3>){0.0, 0.0, 1.0};
    this->vertical = (array<float, 3>){0.0, 1.0, 0.0};
    this->fov = 30.6;
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->pos[2] = 0;

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

    dc.DrawBitmap(this->shader->ApplyShading(), 0, 0);
}

void Viewport::OnMouseMotion(wxMouseEvent& event)
{
    this->scene->cursor_movement[0] = event.GetX() - this->prev_cursor_pos[0];
    this->prev_cursor_pos[0] = event.GetX();
    this->scene->cursor_movement[1] = event.GetY() - this->prev_cursor_pos[1];
    this->prev_cursor_pos[1] = event.GetY();
    this->scene->operate();
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
    this->scene->setOperation(0);
}

void Viewport::OnKeyPress(wxKeyEvent& event)
{
    switch(event.GetUnicodeKey()){
        case 'G':
            this->scene->setOperation(ID_GRAB);
            break;
        case 'R':
            this->scene->setOperation(ID_ROTATE);
            break;
        case 'S':
            this->scene->setOperation(ID_SCALE);
            break;
        case 'W':
            this->scene->setOperation(ID_ZOOM_IN);
            break;
    }
    Refresh();
    event.Skip();
}

void Viewport::OnKeyUp(wxKeyEvent& event){
    switch(event.GetUnicodeKey()){
        case 'W':
            this->scene->setOperation(0);
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