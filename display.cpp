#include "display.h"
#include "operations.h"

enum
{
    ID_Hello = 1
};

Viewport::Viewport(Controller * controller)
    : wxFrame(NULL, wxID_ANY, "TheoVision 3D")
{
    this->controller = controller;

    SetBackgroundColour(wxColour(* wxWHITE));

    // Initialize default attributes
    this->normal = (array<float, 3>){0.0, 0.0, 1.0};
    this->vertical = (array<float, 3>){0.0, 1.0, 0.0};
    this->fov = 30.6;
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->pos[2] = 0;

    // Define graphics behavior
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(Viewport::OnPaint));
    this->Centre();
    
    // Define menu
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    
    // Define exit
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    // Define help menu
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );
 
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
 
    Bind(wxEVT_MENU, &Viewport::OnHello, this, ID_Hello);
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
        // Draw vertices
        vector<array<float, 3> > curr_verts = this->controller->getMeshes()[i]->get_verts();
        for (int j = 0; j < curr_verts.size(); j++){
            array<float, 2> screen_coords = this->projectPoint(curr_verts[j]);
            dc.DrawCircle((int)screen_coords[0], (int)screen_coords[1], 1);
        }
        // Draw edges
        vector<array<int, 2> > curr_edges = this->controller->getMeshes()[i]->get_edges();
        for (int j=0; j < curr_edges.size(); j++){
            array<float, 2> v1_coords = this->projectPoint(curr_verts[curr_edges[j][0]]);
            array<float, 2> v2_coords = this->projectPoint(curr_verts[curr_edges[j][1]]);
            dc.DrawLine((int)v1_coords[0], (int)v1_coords[1],(int)v2_coords[0], (int)v2_coords[1]);
        }
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

array<float, 2> Viewport::projectPoint(float x, float y, float z){
    array<float, 3> dir;
    dir[0] = x - this->pos[0];
    dir[1] = y - this->pos[1];
    dir[2] = z - this->pos[2];

    array<float, 3> x_component = project_onto_plane(dir, this->vertical);
    x_component = normalize(x_component);

    array<float, 3> y_component = project_onto_plane(dir, this->normal);
    y_component = normalize(y_component);

    float x_angle = acos(dot(x_component, this->normal)) * 180 / PI;
    x_angle = x_angle * (float) sign(dot(x_component, cross(this->vertical, this->normal)));

    float y_angle = acos(dot(x_component, this->normal)) * 180 / PI;
    y_angle = y_angle * (float) sign(dot(y_component, this->vertical));

    wxSize screen_dim = this->GetSize();
    return {x_angle / this->fov * 2 + screen_dim.GetWidth() / 2, y_angle / this->fov * 2 + screen_dim.GetHeight() / 2};
    //return {x / z * this->fov, y / z * this->fov};
}

array<float, 2> Viewport::projectPoint(array<float, 3> pos){
    return this->projectPoint(pos[0], pos[1], pos[2]);
}
