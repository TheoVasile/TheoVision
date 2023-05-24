#ifndef SUBDIVISION_SURFACE_H
#define SUBDIVISION_SURFACE_H

#include "modifier.h"

class SubdivisionSurface : public Modifier {
    public:
        SubdivisionSurface();
        Mesh *apply(Mesh *mesh) override;
};

#endif