#include "controller.h"

Controller::Controller(){
    this->operation=0;
    this->activeCamera = new Camera(0, 0, 0);
}

Camera *Controller::getActiveCamera(){
    return this->activeCamera;
}

void Controller::move(float x, float y, float z){
    /*
    Translate all the selected objects
    */
    for (int i=0; i < this->getSelected().size(); i++){
        this->getSelected()[i]->move(x, y, z);
    }
}

void Controller::move(array<float, 3> translation){
    this->move(translation[0], translation[1], translation[2]);
}

void Controller::rotate(float xrot, float yrot, float zrot){
    /*
    Rotate all the selected objects
    */
    for (int i=0; i < this->getSelected().size(); i++){
        this->getSelected()[i]->rotate(xrot, yrot, zrot);
    }
}

void Controller::rotate(array<float, 3> rot){
    this->rotate(rot[0], rot[1], rot[2]);
}

void Controller::scale(float x, float y, float z){
    /*
    Scale all selected objects
    */
    for (int i=0; i<this->getSelected().size(); i++){
        this->getSelected()[i]->scale(x, y, z);
    }
}

void Controller::scale(float size){
    this->scale(size, size, size);
}

void Controller::operate(){
    /*
    Perform the current operation on all selected objects
    */
    switch(this->operation){
        case ID_GRAB:
            this->move(this->cursor_movement[0]/10, this->cursor_movement[1]/10, 0);
            break;
        case ID_ROTATE:
            this->rotate(this->cursor_movement[0]/10 * PI / 180, this->cursor_movement[1]/10 * PI / 180, 0);
            break;
        case ID_SCALE:
            this->scale(this->cursor_movement[0]/10+1);
            break;
        case ID_ZOOM_IN:
            this->activeCamera->zoom();
            break;
    }
}

void Controller::setOperation(int operation){
    this->operation=operation;
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
    Mesh *cube = new Mesh(0, 0, 0);
    cube->addVert(1.0, 1.0, 1.0);
    cube->addVert(1.0, -1.0, 1.0);
    cube->addVert(-1.0, 1.0, 1.0);
    cube->addVert(-1.0, -1.0, 1.0);
    cube->addVert(1.0, 1.0, -1.0);
    cube->addVert(1.0, -1.0, -1.0);
    cube->addVert(-1.0, 1.0, -1.0);
    cube->addVert(-1.0, -1.0, -1.0);
    /*
    cube->addEdge(0, 1);
    cube->addEdge(0, 2);
    cube->addEdge(0, 4);
    cube->addEdge(1, 3);
    cube->addEdge(1, 5);
    cube->addEdge(2, 3);
    cube->addEdge(2, 6);
    cube->addEdge(4, 5);
    cube->addEdge(4, 6);
    cube->addEdge(7, 3);
    cube->addEdge(7, 5);
    cube->addEdge(7, 6);
    */
    cube->move(x, y, z);

    this->objects.push_back(cube);
    this->selected.push_back(this->objects.size()-1);
    this->meshes.push_back(this->objects.size()-1);
}

void Controller::addUVSphere(float x, float y, float z, int rings, int segments){
    Mesh *uvsphere = new Mesh(0, 0, 0);
   // Create vertices
    for (int i = 0; i <= rings; i++) {
        float curr_height = sinf((((float)i)/rings - 0.5) * PI);
        for (int j = 0; j < segments; j++) {
            float curr_y = sqrt(1 - curr_height * curr_height) * sin(static_cast<float>(j) / segments * 2.0f * M_PI);
            float curr_x = sqrt(1 - curr_height * curr_height) * cos(static_cast<float>(j) / segments * 2.0f * M_PI);
            uvsphere->addVert(curr_x, curr_y, curr_height);
        }
    }

    // Create edges
    for (int i = 0; i < rings; i++) {
        int next_i = (i + 1) % (rings + 1);
        for (int j = 0; j < segments; j++) {
            int next_j = (j + 1) % segments;
            uvsphere->addEdge(uvsphere->getVertex(i * segments + j), uvsphere->getVertex(i * segments + next_j));
            uvsphere->addEdge(uvsphere->getVertex(i * segments + j), uvsphere->getVertex(next_i * segments + j));
        }
    }

    // Create faces
    for (int i = 0; i < rings; i++) {
        for (int j = 0; j < segments; j++) {
            int next_i = (i + 1) % rings;
            int next_j = (j + 1) % segments;
            uvsphere->addFace(uvsphere->getEdge(i * segments + j));
            uvsphere->addFace(uvsphere->getEdge(i * segments + j));
            uvsphere->addFace(uvsphere->getEdge(next_i * segments + next_j));
            uvsphere->addFace(uvsphere->getEdge(i * segments + j));
            uvsphere->addFace(uvsphere->getEdge(next_i * segments + j));
            uvsphere->addFace(uvsphere->getEdge(next_i * segments + next_j));
        }
    }

    uvsphere->move(x, y, z);
    this->objects.push_back(uvsphere);
    this->selected.push_back(this->objects.size()-1);
    this->meshes.push_back(this->objects.size()-1);
}