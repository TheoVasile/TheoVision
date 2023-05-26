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
    // Find the point of intersection with the plane
    vec3 normal = getNormal(tri);
    float numerator = -dot(normal, (this->pos - tri[0]));
    float denominator = dot(normal, this->direction);
    if (denominator == 0) {
        return;
    }
    float t = numerator / denominator;
    vec3 collision = this->pos + (this->direction * t);

    // See if the point lies within the tri.
    vec3 v1 = collision - tri[0];
    vec3 v2 = collision - tri[1];
    vec3 v3 = collision - tri[2];
    float angle = acos(dot(v1, v2) / (length(v1) * length(v2)));
    angle += acos(dot(v3, v2) / (length(v3) * length(v2)));
    angle += acos(dot(v3, v1) / (length(v3) * length(v1)));

    if (abs(angle - 2 * M_PI) < 0.1) {
        this->collisionPoint = collision;
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