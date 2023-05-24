#ifndef MODIFIER_H
#define MODIFIER_H

#include "../objects/bmesh.h"

class Mesh;

class Modifier {
    public:
        Modifier();
        virtual Mesh *apply(Mesh *mesh);
};

#endif