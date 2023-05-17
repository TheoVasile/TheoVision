#include "object.h"
#include <wx/wx.h>
//#include <blaze/Math.h>


Mesh::Mesh(float x, float y, float z)
{
    this->origin[0] = x;
    this->origin[1] = y;
    this->origin[2] = z;
}

void Mesh::scale(float size){
    // Scale the vertices around the origin of the mesh
    for (int i=0; i < this->vertices.size(); i++){
        this->vertices[i][0] = (this->vertices[i][0] - this->origin[0]) * size + this->origin[0];
        this->vertices[i][1] = (this->vertices[i][1] - this->origin[1]) * size + this->origin[1];
        this->vertices[i][2] = (this->vertices[i][2] - this->origin[2]) * size + this->origin[2];
    }
}

void Mesh::move(float x, float y, float z){
    // Translate the position of each vertice in the mesh as well as the origin

    this->origin[0] += x;
    this->origin[1] += y;
    this->origin[2] += z;
    for (int i=0; i < this->vertices.size(); i++){
        //wxPrintf("%f\n", this->vertices[i][2]);
        this->vertices[i][0] += x;
        this->vertices[i][1] += y;
        this->vertices[i][2] += z;
        //wxPrintf("%f\n--\n", this->vertices[i][2]);
    }
    //wxPrintf("Loop ended\n");
}

void Mesh::rotate(array<float, 3> rot){
    array<float, 3> currOrigin = this->origin;
    this->move(-this->origin[0], -this->origin[1], -this->origin[2]);
    for (int i=0; i < this->vertices.size(); i++){
        this->vertices[i] = Rotate(this->vertices[i], rot);
    }
    this->move(currOrigin[0], currOrigin[1], currOrigin[2]);
}

void Mesh::rotate(float xrot, float yrot, float zrot){
    array<float, 3> rot = {xrot, yrot, zrot};
    this->rotate(rot);
}

void Mesh::add_vert(array<float, 3> pos){
    this->vertices.push_back(pos);
}
void Mesh::add_vert(float x, float y, float z){
    array<float, 3> pos = {x, y, z};
    this->add_vert(pos);
}

void Mesh::add_edge(int vert1, int vert2){
    array<int, 2> edge = {vert1, vert2};
    this->edges.push_back(edge);
}

vector<array<float, 3> > Mesh::get_verts(){
    return this->vertices;
}

vector<array<int, 2> > Mesh::get_edges(){
    return this->edges;
}