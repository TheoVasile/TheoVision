#include <wx/wx.h>
#include "mesh.h"

public:
    void drawMesh(Mesh *mesh, wxPaintDC dc);
private:
    void drawVertex(float x, float y, float z);
    void drawEdge();