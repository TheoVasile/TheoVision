#ifndef MODIFIER_H
#define MODIFIER_H

#include "../objects/meshes/bmesh.h"

class Mesh;

class Modifier {
    public:
        Modifier();
        virtual Mesh *apply(Mesh *mesh);
};

#endif