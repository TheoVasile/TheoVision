#include "display.h"

enum
{
    ID_Hello = 1
};

Camera::Camera()
    : wxFrame(NULL, wxID_ANY, "TheoVision 3D")
{
    this->Connect(wxEVT_PAINT, wxPaintEventHandler(Camera::OnPaint));
    this->Centre();
    
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );
 
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
 
    Bind(wxEVT_MENU, &Camera::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &Camera::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Camera::OnExit, this, wxID_EXIT);
}


void Camera::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void Camera::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);
  
    wxCoord x1 = 50, y1 = 60;
    wxCoord x2 = 190, y2 = 60;

    dc.DrawLine(x1, y1, x2, y2);
}

void Camera::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void Camera::OnHello(wxCommandEvent& event)
{
    wxLogMessage("3D interactive display using wxWidgets");
}