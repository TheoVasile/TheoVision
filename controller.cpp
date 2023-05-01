#include "controller.h"

Controller::Controller(){

}

vector<Mesh *> Controller::getSelected(){
    vector<Mesh *> selected_objects;
    for (int i=0; i < this->selected.size(); i++){
        selected_objects.push_back(this->objects[this->selected[i]]);
    }
    return selected_objects;
}

vector<Mesh *> Controller::getMeshes(){
    vector<Mesh *> mesh_objs;
    for (int i=0; i < this->meshes.size(); i++){
        mesh_objs.push_back(this->objects[this->meshes[i]]);
    }
    return mesh_objs;
}

void Controller::addCube(float x, float y, float z){
    Mesh *cube = new Mesh(x, y, z);
    cube->add_vert(1.0, 1.0, 1.0);
    cube->add_vert(1.0, -1.0, 1.0);
    cube->add_vert(-1.0, 1.0, 1.0);
    cube->add_vert(-1.0, -1.0, 1.0);
    cube->add_vert(1.0, 1.0, -1.0);
    cube->add_vert(1.0, -1.0, -1.0);
    cube->add_vert(-1.0, 1.0, -1.0);
    cube->add_vert(-1.0, -1.0, -1.0);
    cube->add_edge(0, 1);
    cube->add_edge(0, 2);
    cube->add_edge(0, 4);
    cube->add_edge(1, 3);
    cube->add_edge(1, 5);
    cube->add_edge(2, 3);
    cube->add_edge(2, 6);
    cube->add_edge(4, 5);
    cube->add_edge(4, 6);
    cube->add_edge(7, 3);
    cube->add_edge(7, 5);
    cube->add_edge(7, 6);

    this->objects.push_back(cube);
    this->meshes.push_back(this->objects.size()-1);
}