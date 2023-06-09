#ifndef SUBDIVISION_SURFACE_H
#define SUBDIVISION_SURFACE_H

#include "modifier.h"
#include <glm/glm.hpp>

using namespace glm;

class SubdivisionSurface : public Modifier {
    public:
        SubdivisionSurface(int subdivisions=2);
        Mesh *apply(Mesh *mesh) override;
    private:
        int subdivisions;
};

#endif