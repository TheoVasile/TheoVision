#include "ray.h"

Ray::Ray(array<float, 3> pos, array<float, 3> direction):Vector(pos, direction)
{
    this->hasHit = false;
}

array<float, 3> Ray::getCollisionPoint()
{
    return this->collisionPoint;
}

array<float, 3> Ray::getCollisionNormal()
{
    return normalize(this->collisionNormal);
}

void Ray::cast(array<array<float, 3>, 3> tri)
{
    this->hasHit = false;
    // Find the point of intersection with the plane
    array<float, 3> normal = getNormal(tri);
    float numerator = -sum(multiply(normal, subtract(this->pos, tri[0])));
    float denominator = sum(multiply(normal, this->direction));
    if (denominator == 0) {
        return;
    }
    float t = numerator / denominator;
    array<float, 3> collision = add(this->pos, multiply(this->direction, t));

    // See if the point lies within the tri.
    array<float, 3> v1 = subtract(collision, tri[0]);
    array<float, 3> v2 = subtract(collision, tri[1]);
    array<float, 3> v3 = subtract(collision, tri[2]);
    float angle = acos(dot(v1, v2) / (magnitude(v1) * magnitude(v2)));
    angle += acos(dot(v3, v2) / (magnitude(v3) * magnitude(v2)));
    angle += acos(dot(v3, v1) / (magnitude(v3) * magnitude(v1)));

    if (abs(angle - 2 * M_PI) < 0.1) {
        this->collisionPoint = collision;
        this->collisionNormal = getNormal(tri);
    this->hasHit = true;
    }
}

void Ray::cast(Face *face)
{
    bool hit = false;
    float minDist = numeric_limits<float>::infinity();
    array<float, 3> closestPoint;
    array<float, 3> closestNormal;
    vector<array<array<float, 3>, 3> > tris = face->getTris();
    for (array<array<float, 3>, 3> currTri : tris){
        this->cast(currTri);
        if (!this->hasHit) {
            continue;
        }
        float currDist = dist(this->collisionPoint, this->pos);
        if (currDist < minDist) {
            minDist = currDist;
            closestPoint = this->collisionPoint;
            closestNormal = this->collisionNormal;
            hit = true;
        }
    }
    this->hasHit = hit;
    this->collisionPoint = closestPoint;
    this->collisionNormal = closestNormal;
}

void Ray::cast(Mesh *mesh)
{
    bool hit = false;
    float minDist = numeric_limits<float>::infinity();
    array<float, 3> closestPoint;
    array<float, 3> closestNormal;
    vector<Face *> faces = mesh->getFaces();
    for (Face *currFace : faces) {
        this->cast(currFace);
        if (!this->hasHit) {
            continue;
        }
        float currDist = dist(this->collisionPoint, this->pos);
        if (currDist < minDist) {
            minDist = currDist;
            closestPoint = this->collisionPoint;
            closestNormal = this->collisionNormal;
            hit = true;
        }
    }
    this->hasHit = hit;
    this->collisionPoint = closestPoint;
    this->collisionNormal = closestNormal;
}

void Ray::cast(vector<Mesh *> meshes)
{
    bool hit = false;
    float minDist = numeric_limits<float>::infinity();
    array<float, 3> closestPoint;
    array<float, 3> closestNormal;
    for (Mesh *currMesh : meshes) {
        this->cast(currMesh);
        if (!this->hasHit) {
            continue;
        }
        float currDist = dist(this->collisionPoint, this->pos);
        if (currDist < minDist) {
            minDist = currDist;
            closestPoint = this->collisionPoint;
            closestNormal = this->collisionNormal;
            hit = true;
        }
    }
    this->hasHit = hit;
    this->collisionPoint = closestPoint;
    this->collisionNormal = closestNormal;
}