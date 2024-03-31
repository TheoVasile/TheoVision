#include "ray.h"

Ray::Ray(vec3 pos, vec3 direction) {
    this->pos = pos;
    this->direction = direction;
    this->hasHit = false;
}

Ray::Ray(array<float, 3> pos, array<float, 3> direction) {
    this->pos = vec3(pos[0], pos[1], pos[2]);
    this->direction = vec3(direction[0], direction[1], direction[2]);
    this->hasHit = false;
}

vec3 Ray::getPoint(float t)
{
    return this->pos + (this->direction * t);
}

vec3 Ray::getCollisionPoint()
{
    return this->collisionPoint;
}

vec3 Ray::getCollisionNormal()
{
    return normalize(this->collisionNormal);
}

vec3 Ray::getOutgoingDirection() {
    return this->outgoingDirection;
}

Mesh *Ray::getCollisionMesh() {
    return this->collisionMesh;
}

void Ray::cast(array<vec3, 3> tri)
{
    this->hasHit = false;
    constexpr float epsilon = std::numeric_limits<float>::epsilon();
    vec3 edge1 = tri[1] - tri[0];
    vec3 edge2 = tri[2] - tri[0];
    vec3 ray_cross_edge2 = cross(this->direction, edge2);
    float determinant = dot(edge1, ray_cross_edge2);

    // Check if ray is parallel to the triangle
    if (determinant > -epsilon && determinant < epsilon) {
        return;
    }

    float inverse_determinant = 1.0 / determinant;
    vec3 s = this->pos - tri[0];
    float u = inverse_determinant * dot(s, ray_cross_edge2);

    if (u < 0 || u > 1) {
        return;
    }

    vec3 s_cross_edge1 = cross(s, edge1);
    float v = inverse_determinant * dot(this->direction, s_cross_edge1);

    if (v < 0 || u+v > 1) {
        return;
    }

    // Compute point where ray intersects triangle
    float t = inverse_determinant * dot(edge2, s_cross_edge1);

    if (t > epsilon) {
        this->collisionPoint = this->pos + this->direction * t;
        this->collisionNormal = getNormal(tri);
        this->outgoingDirection = this->direction - 2 * dot(this->collisionNormal, this->direction) * this->collisionNormal;
        this->hasHit = true;
    }
}

void Ray::cast(Face *face)
{
    bool hit = false;
    float minDist = numeric_limits<float>::infinity();
    vec3 closestPoint;
    vec3 closestNormal;
    vec3 closestOutgoing;
    vector<array<vec3, 3> > tris = face->getTris();
    for (array<vec3, 3> currTri : tris){
        this->cast(currTri);
        if (!this->hasHit) {
            continue;
        }
        float currDist = distance(this->collisionPoint, this->pos);
        if (currDist < minDist) {
            minDist = currDist;
            closestPoint = this->collisionPoint;
            closestNormal = face->getNormal();
            closestOutgoing = this->outgoingDirection;
            hit = true;
        }
    }
    this->hasHit = hit;
    this->collisionPoint = closestPoint;
    this->collisionNormal = closestNormal;
    this->outgoingDirection = closestOutgoing;
}

void Ray::cast(Mesh *mesh)
{
    bool hit = false;
    float minDist = numeric_limits<float>::infinity();
    vec3 closestPoint;
    vec3 closestNormal;
    vec3 closestOutgoing;
    vector<Face *> faces = mesh->getFaces();
    for (Face *currFace : faces) {
        this->cast(currFace);
        if (!this->hasHit) {
            continue;
        }
        float currDist = distance(this->collisionPoint, this->pos);
        if (currDist < minDist) {
            minDist = currDist;
            closestPoint = this->collisionPoint;
            closestNormal = this->collisionNormal;
            closestOutgoing = this->outgoingDirection;
            hit = true;
        }
    }
    this->hasHit = hit;
    this->collisionPoint = closestPoint;
    this->collisionNormal = closestNormal;
    this->outgoingDirection = closestOutgoing;
    this->collisionMesh = mesh;
}

void Ray::cast(vector<Mesh *> meshes)
{
    bool hit = false;
    float minDist = numeric_limits<float>::infinity();
    vec3 closestPoint;
    vec3 closestNormal;
    vec3 closestOutgoing;
    for (Mesh *currMesh : meshes) {
        this->cast(currMesh);
        if (!this->hasHit) {
            continue;
        }
        float currDist = distance(this->collisionPoint, this->pos);
        if (currDist < minDist) {
            minDist = currDist;
            closestPoint = this->collisionPoint;
            closestNormal = this->collisionNormal;
            closestOutgoing = this->outgoingDirection;
            this->collisionMesh = currMesh;
            hit = true;
        }
    }
    this->hasHit = hit;
    this->collisionPoint = closestPoint;
    this->collisionNormal = closestNormal;
    this->outgoingDirection = closestOutgoing;
}