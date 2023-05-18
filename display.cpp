#include "display.h"
#include "operations.h"


Viewport::Viewport(Controller * controller)
    : wxFrame(NULL, wxID_ANY, "TheoVision 3D", wxDefaultPosition, wxSize(800, 600), wxDEFAULT_FRAME_STYLE | wxWS_EX_PROCESS_UI_UPDATES)
{
    wxPanel * panel = new wxPanel(this);
    this->controller = controller;

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
    Bind(wxEVT_MENU, &Viewport::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Viewport::OnExit, this, wxID_EXIT);
}


void Viewport::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void Viewport::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);

    // Mesh loop
    for (int i = 0; i < this->controller->getMeshes().size(); i++){
        Camera *cam = this->controller->getActiveCamera();
        // Draw vertices
        vector<array<float, 3> > curr_verts = this->controller->getMeshes()[i]->getVerts();
        for (int j = 0; j < curr_verts.size(); j++){
            array<float, 2> screen_coords = cam->projectPoint(curr_verts[j], this->GetSize());
            dc.DrawCircle((int)screen_coords[0], (int)screen_coords[1], 1);
        }

        // Draw edges
        vector<array<int, 2> > curr_edges = this->controller->getMeshes()[i]->getEdges();
        for (int j=0; j < curr_edges.size(); j++){
            array<float, 2> v1_coords = cam->projectPoint(curr_verts[curr_edges[j][0]], this->GetSize());
            array<float, 2> v2_coords = cam->projectPoint(curr_verts[curr_edges[j][1]], this->GetSize());
            dc.DrawLine((int)v1_coords[0], (int)v1_coords[1],(int)v2_coords[0], (int)v2_coords[1]);
        }

        wxColor col(255, 0, 0);
        dc.SetPen( wxPen(col) );
        dc.SetBrush( wxBrush(col) );
        array<float, 2> originPos = cam->projectPoint(this->controller->getMeshes()[i]->getOrigin(), this->GetSize());
        dc.DrawCircle((int)originPos[0], (int)originPos[1], 1);
    }
}

void Viewport::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void Viewport::OnHello(wxCommandEvent& event)
{
    wxLogMessage("3D interactive display using wxWidgets");
}

void Viewport::OnMouseMotion(wxMouseEvent& event)
{
    this->controller->cursor_movement[0] = event.GetX() - this->prev_cursor_pos[0];
    this->prev_cursor_pos[0] = event.GetX();
    this->controller->cursor_movement[1] = event.GetY() - this->prev_cursor_pos[1];
    this->prev_cursor_pos[1] = event.GetY();
    this->controller->operate();
    Refresh();
}

void Viewport::OnClick(wxMouseEvent& event)
{
    this->controller->setOperation(0);
}

void Viewport::OnKeyPress(wxKeyEvent& event)
{
    switch(event.GetUnicodeKey()){
        case 'G':
            this->controller->setOperation(ID_GRAB);
            break;
        case 'R':
            this->controller->setOperation(ID_ROTATE);
            break;
        case 'S':
            this->controller->setOperation(ID_SCALE);
            break;
        case 'W':
            this->controller->setOperation(ID_ZOOM_IN);
            break;
    }
    Refresh();
    event.Skip();
}

void Viewport::OnKeyUp(wxKeyEvent& event){
    switch(event.GetUnicodeKey()){
        case 'W':
            this->controller->setOperation(0);
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


array<float, 2> Viewport::projectPoint(float x, float y, float z){
    array<float, 3> dir;
    dir[0] = x - this->pos[0];
    dir[1] = y - this->pos[1];
    dir[2] = z - this->pos[2];

    array<float, 3> x_component = project_onto_plane(dir, this->vertical);
    x_component = normalize(x_component);

    array<float, 3> y_component = project_onto_plane(dir, cross(this->vertical, this->normal));
    y_component = normalize(y_component);

    float x_angle = acos(dot(x_component, this->normal)) * 180.0 / PI;
    x_angle = x_angle * (float) sign(dot(x_component, cross(this->vertical, this->normal)));

    float y_angle = acos(dot(y_component, this->normal)) * 180.0 / PI;
    y_angle = y_angle * (float) sign(dot(y_component, this->vertical));

    wxSize screen_dim = this->GetSize();
    int scale_factor = min(screen_dim.GetHeight(), screen_dim.GetWidth());
    return {x_angle / this->fov * 2 * scale_factor + screen_dim.GetWidth() / 2, y_angle / this->fov * 2 * scale_factor + screen_dim.GetHeight() / 2};
}

array<float, 2> Viewport::projectPoint(array<float, 3> pos){
    return this->projectPoint(pos[0], pos[1], pos[2]);
}
