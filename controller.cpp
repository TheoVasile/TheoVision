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
        case ID_GRAB: {
            float movementFactor = dist(this->activeCamera->getPos(), this->getSelected()[0]->getOrigin()) / 1000;
            this->move(multiply(cross(this->activeCamera->getNormal(), this->activeCamera->getVertical()), -this->cursor_movement[0] * movementFactor));
            this->move(multiply(this->activeCamera->getVertical(), this->cursor_movement[1] * movementFactor));
            break;
        }
        case ID_ROTATE: {
            this->rotate(0, cursor_movement[0] * M_PI / 180, -cursor_movement[1] * M_PI / 180);
            break;
        }
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

    // Vertices
    cube->addVert(1.0, 1.0, 1.0);
    cube->addVert(1.0, -1.0, 1.0);
    cube->addVert(-1.0, 1.0, 1.0);
    cube->addVert(-1.0, -1.0, 1.0);
    cube->addVert(1.0, 1.0, -1.0);
    cube->addVert(1.0, -1.0, -1.0);
    cube->addVert(-1.0, 1.0, -1.0);
    cube->addVert(-1.0, -1.0, -1.0);

    // Edges
    cube->addEdge(0, 2);
    cube->addEdge(2, 6);
    cube->addEdge(4, 0);
    cube->addEdge(0, 1);
    cube->addEdge(2, 3);
    cube->addEdge(6, 4);
    cube->addEdge(6, 7);
    cube->addEdge(1, 3);
    cube->addEdge(3, 7);
    cube->addEdge(7, 5);
    cube->addEdge(5, 4);
    cube->addEdge(1, 5);

    // Adjascency information
    cube->getEdge(0)->setNextEdge(cube->getEdge(1));
    cube->getEdge(0)->pair->setNextEdge(cube->getEdge(3));

    cube->getEdge(1)->setNextEdge(cube->getEdge(5));
    cube->getEdge(1)->pair->setNextEdge(cube->getEdge(4));
    
    cube->getEdge(2)->setNextEdge(cube->getEdge(0));
    cube->getEdge(2)->pair->setNextEdge(cube->getEdge(10)->pair);
    
    cube->getEdge(3)->setNextEdge(cube->getEdge(7));
    cube->getEdge(3)->pair->setNextEdge(cube->getEdge(2)->pair);

    cube->getEdge(4)->setNextEdge(cube->getEdge(8));
    cube->getEdge(4)->pair->setNextEdge(cube->getEdge(0)->pair);

    cube->getEdge(5)->setNextEdge(cube->getEdge(2));
    cube->getEdge(5)->pair->setNextEdge(cube->getEdge(6));
    
    cube->getEdge(6)->setNextEdge(cube->getEdge(9));
    cube->getEdge(6)->pair->setNextEdge(cube->getEdge(1)->pair);
    
    cube->getEdge(7)->setNextEdge(cube->getEdge(4)->pair);
    cube->getEdge(7)->pair->setNextEdge(cube->getEdge(11));

    cube->getEdge(8)->setNextEdge(cube->getEdge(6)->pair);
    cube->getEdge(8)->pair->setNextEdge(cube->getEdge(7)->pair);
    
    cube->getEdge(9)->setNextEdge(cube->getEdge(10));
    cube->getEdge(9)->pair->setNextEdge(cube->getEdge(8)->pair);

    cube->getEdge(10)->setNextEdge(cube->getEdge(5)->pair);
    cube->getEdge(10)->pair->setNextEdge(cube->getEdge(11)->pair);

    cube->getEdge(11)->setNextEdge(cube->getEdge(9)->pair);
    cube->getEdge(11)->pair->setNextEdge(cube->getEdge(3)->pair);

    // Faces
    cube->addFace(2);
    cube->addFace(11, true);
    cube->addFace(3);
    cube->addFace(1, true);
    cube->addFace(10);
    cube->addFace(11);


    cube->move(x, y, z);

    this->objects.push_back(cube);
    this->selected.push_back(this->objects.size()-1);
    this->meshes.push_back(this->objects.size()-1);
}

void Controller::addUVSphere(float x, float y, float z, int rings, int segments){
    Mesh *uvsphere = new Mesh(0, 0, 0);
   // Create vertices
   /*
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

    // Provide more edge information
    for (int i = 0; i < uvsphere->getEdges().size(); i++) {
        if (i % 2 == 0) {
            if (i < uvsphere->getEdges().size() - 1){
                if (i > 2 * segments){
                    uvsphere->getEdge(i)->edgeNextCCW = uvsphere->getEdge(i - 2 * segments + 1);
                }
                uvsphere->getEdge(i)->edgePreviousCW = uvsphere->getEdge(i+1);
            }
            if (i < uvsphere->getEdges().size() - 3){
                if (i > 2 * segments){
                    uvsphere->getEdge(i)->edgePreviousCCW = uvsphere->getEdge(i - 2 * segments + 3);
                }
                uvsphere->getEdge(i)->edgeNextCW = uvsphere->getEdge(i+3);
            }
        } else {
            uvsphere->getEdge(i)->edgeNextCCW = uvsphere->getEdge(i-1);
            if (i >= 3){
                uvsphere->getEdge(i)->edgePreviousCW = uvsphere->getEdge(i-3);
            }
            if (i < uvsphere->getEdges().size() - 2 * segments + 1) {
                uvsphere->getEdge(i)->edgePreviousCCW = uvsphere->getEdge(i+2*segments-1);
            }
            if (i < uvsphere->getEdges().size() - 2 * segments + 3){
                uvsphere->getEdge(i)->edgeNextCW = uvsphere->getEdge(i+2*segments-3);
            }
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
    */

    uvsphere->move(x, y, z);
    this->objects.push_back(uvsphere);
    this->selected.push_back(this->objects.size()-1);
    this->meshes.push_back(this->objects.size()-1);
}