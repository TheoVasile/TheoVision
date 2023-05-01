#include "object.h"


Mesh::Mesh(float pos[3])
{
    this->origin[0] = pos[0];
    this->origin[1] = pos[1];
    this->origin[2] = pos[2];
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
        this->vertices[i][0] += x;
        this->vertices[i][1] += y;
        this->vertices[i][2] += z;
    }
}

void Mesh::add_vert(array<float, 3> pos){
    this->vertices.push_back(pos);
}
void Mesh::add_vert(float x, float y, float z){
    array<float, 3> pos = {x, y, z};
    this->add_vert(pos);
}

vector<array<float, 3> > Mesh::get_verts(){
    return this->vertices;
}

vector<array<int, 2> > Mesh::get_edges(){
    return this->edges;
}