#include "controller.h"
#include <wx/wx.h>

Controller::Controller(){

}

void Controller::move(float x, float y, float z){
    for (int i=0; i < this->getSelected().size(); i++){
        this->getSelected()[i]->move(x, y, z);
    }
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
    cube->move(x, y, z);

    this->objects.push_back(cube);
    this->meshes.push_back(this->objects.size()-1);
}

void Controller::addUVSphere(float x, float y, float z, float rings, float segments){
    Mesh *uvsphere = new Mesh(0, 0, 0);
    for (int i=0; i < segments; i++){
        float curr_height = 2 / rings * i - 1;
        curr_height = sin((i/rings - 0.5) * PI);
        for (int j=0; j < rings; j++){
            float curr_y = pow(1 - pow(curr_height, 2), 0.5) * sin(j / segments * 2 * PI);
            float curr_x = pow(1 - pow(curr_height, 2), 0.5) * cos(j / segments * 2 * PI);
            wxPrintf("%f, %f, %f\n", curr_x, curr_y, curr_height);
            uvsphere->add_vert(curr_x, curr_y, curr_height);
        }
    }

    //uvsphere->scale(1);
    uvsphere->move(x, y, z);
    this->objects.push_back(uvsphere);
    this->meshes.push_back(this->objects.size()-1);
}