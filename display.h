#include <wx/wx.h>

class Camera : public wxFrame
{
public:
    Camera();
 
private:
    void OnHello(wxCommandEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};