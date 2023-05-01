#include "object.h"


Mesh::Mesh(float pos[3])
{
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
    this->pos[2] = pos[2];
}

void Mesh::scale(float size){
    for (int i=0; i < this->vertices.size(); i++){
        this->vertices[i][0] = this->vertices[i][0] * size;
        this->vertices[i][1] = this->vertices[i][1] * size;
        this->vertices[i][2] = this->vertices[i][2] * size;
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