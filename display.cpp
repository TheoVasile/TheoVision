#include "display.h"

enum
{
    ID_Hello = 1
};

Viewport::Viewport(vector<Mesh *> meshes)
    : wxFrame(NULL, wxID_ANY, "TheoVision 3D")
{
    for (int i=0; i < meshes.size(); i++){
        this->meshes.push_back(meshes[i]);
    }

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
    for (int i = 0; i < this->meshes.size(); i++){
        // Vert loop
        vector<array<float, 3> > curr_verts = this->meshes[i]->get_verts();
        for (int j = 0; j < this->meshes[i]->get_verts().size(); j++){
            array<float, 2> screen_coords = this->projectPoint(curr_verts[j]);
            dc.DrawCircle((int)screen_coords[0], (int)screen_coords[1], 1);
        }
    }
    wxCoord x1 = 50, y1 = 60;
    wxCoord x2 = 190, y2 = 60;

    dc.DrawLine(x1, y1, x2, y2);
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
    return {x / z * this->fov, y / z * this->fov};
}

array<float, 2> Viewport::projectPoint(array<float, 3> pos){
    return this->projectPoint(pos[0], pos[1], pos[2]);
}
