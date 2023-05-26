#include "scene.h"

Scene::Scene(){
    this->activeCamera = new Camera(0, 0, 0);
    this->backgroundColor = vec3(0.2, 0.2, 0.2);
}

Camera *Scene::getActiveCamera(){
    return this->activeCamera;
}

void Scene::move(vec3 translation) {
    for (int i=0; i < this->getSelected().size(); i++){
        this->getSelected()[i]->move(translation);
    }
}

void Scene::move(float x, float y, float z){
    /*
    Translate all the selected objects
    */
    this->move(vec3(x, y, z));
}

void Scene::move(array<float, 3> translation){
    this->move(translation[0], translation[1], translation[2]);
}

void Scene::rotate(vec3 rot) {
    for (int i=0; i < this->getSelected().size(); i++){
        this->getSelected()[i]->rotate(rot);
    }
}

void Scene::rotate(float xrot, float yrot, float zrot){
    /*
    Rotate all the selected objects
    */
    this->rotate(vec3(xrot, yrot, zrot));
}

void Scene::rotate(array<float, 3> rot){
    this->rotate(rot[0], rot[1], rot[2]);
}

void Scene::scale(vec3 scalingFactor) {
    for (int i=0; i<this->getSelected().size(); i++){
        this->getSelected()[i]->scale(scalingFactor);
    }
}

void Scene::scale(float x, float y, float z){
    /*
    Scale all selected objects
    */
    this->scale(vec3(x, y, z));
}

void Scene::scale(float size){
    this->scale(size, size, size);
}

void Scene::select(int x, int y) {
    this->select(vec2(x, y));
}

void Scene::select(vec2 cursorPos) {
    float minDist = numeric_limits<float>::infinity();
    Object *selection;
    for (Object *currObject : this->objects) {
        vec2 screenOrigin = this->activeCamera->projectPoint(currObject->getOrigin(), this->screenDim);
        float currDist = distance(cursorPos, screenOrigin);
        if (currDist < minDist) {
            minDist = currDist;
            selection = currObject;
        }
    }
    selected.clear();
    selected.push_back(selection);
}

vec3 Scene::getMedianPoint() {
    vec3 median(0.0f, 0.0f, 0.0f);
    for (Object *currObject : this->selected) {
        median += currObject->getOrigin();
    }
    median = median / (float) this->selected.size();
    return median;
}

vector<Object *> Scene::getSelected() {
    return this->selected;
}

vector<Mesh *> Scene::getMeshes() {
    return this->meshes;
}

vector<Light *> Scene::getLights() {
    return this->lights;
}

void Scene::addLight(Light *light)
{
    this->objects.push_back(light);
    this->lights.push_back(light);
}

void Scene::addCube(float x, float y, float z){
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
    this->selected.push_back(cube);
    this->meshes.push_back(cube);
}

void Scene::addUVSphere(float x, float y, float z, int rings, int segments){
    Mesh *uvsphere = new Mesh(0, 0, 0);
   // Create vertices
    for (int i = 0; i <= rings; i++) {
        float curr_height = sinf((((float)i)/rings - 0.5) * M_PI);
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
            uvsphere->addEdge(i * segments + j, i * segments + next_j);
            uvsphere->addEdge(i * segments + j, next_i * segments + j);
        }
    }

    for (int i=0; i < uvsphere->getEdges().size() - 2 * segments - 1; i+=2) {
        if (i % (2 * segments - 2) == 0 && false) {
            /*
            uvsphere->getEdge(i)->setNextEdge(uvsphere->getEdge(i-2 * segments - 3));
            uvsphere->getEdge(i-2 * segments - 3)->setNextEdge(uvsphere->getEdge(i + 2)->pair);
            uvsphere->getEdge(i + 2)->pair->setNextEdge(uvsphere->getEdge(i+1)->pair);
            uvsphere->getEdge(i+1)->pair->setNextEdge(uvsphere->getEdge(i));
            uvsphere->addFace(i);
            */
        } else {
            uvsphere->getEdge(i)->setNextEdge(uvsphere->getEdge(i+3));
            uvsphere->getEdge(i+3)->setNextEdge(uvsphere->getEdge(i + 2 * segments)->pair);
            uvsphere->getEdge(i + 2 * segments)->pair->setNextEdge(uvsphere->getEdge(i+1)->pair);
            uvsphere->getEdge(i+1)->pair->setNextEdge(uvsphere->getEdge(i));
            uvsphere->addFace(i);
        }
    }

    uvsphere->flipNormals();
    /*
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
    this->selected.push_back(uvsphere);
    this->meshes.push_back(uvsphere);
}