#include "object.h"


Mesh::Mesh(float pos[3])
{
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
    this->pos[2] = pos[2];
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