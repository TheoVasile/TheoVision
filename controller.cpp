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

void Controller::addUVSphere(float x, float y, float z, float rings, float segments){
    Mesh *uvsphere = new Mesh(0, 0, 0);
    for (int i=0; i < rings+1; i++){
        float curr_height = sinf((((float)i)/rings - 0.5) * PI);
        for (int j=0; j < segments; j++){
            // create vertices
            float curr_y = pow(1 - pow(curr_height, 2), 0.5) * sinf(((float)j) / segments * 2.0 * PI);
            float curr_x = pow(1 - pow(curr_height, 2), 0.5) * cosf(((float)j) / segments * 2.0 * PI);
            uvsphere->addVert(curr_x, curr_y, curr_height);

            // create edges
            if (uvsphere->getVerts().size() > 1){
                if (j == 0){
                    uvsphere->addEdge(uvsphere->getVerts()[(i-1) * segments], uvsphere->getVerts()[i * segments - 1]);
                } else{
                    uvsphere->addEdge(uvsphere->getVerts()[i * segments + j - 1], uvsphere->getVerts()[i * segments + j]);
                }
            }
            if (i > 0){
                uvsphere->addEdge(uvsphere->getVerts()[i * segments + j], uvsphere->getVerts()[(i-1) * segments + j]);
            }

            /*
            // create faces
            if (i != 0 && i != 1 && i != rings){
                if (j != 0) {
                    vector<int> face;
                    face.push_back(i * segments + j - 1);
                    face.push_back(i * segments + j);
                    face.push_back((i-1) * segments + j);
                    face.push_back((i-1) * segments + j - 1);
                    uvsphere->addFace(face);
                }
            }
            */
        }
    }

    uvsphere->move(x, y, z);
    this->objects.push_back(uvsphere);
    this->selected.push_back(this->objects.size()-1);
    this->meshes.push_back(this->objects.size()-1);
}