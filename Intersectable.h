// Computer Graphics Project Assignment 1 Ray Tracing
// Intersectable.h
#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include "Vector3.h"
#include "Shading.h"

// Create an interface class specifically a Structure for Polygons and Spheres to ensure that they are interchangeable for testing purposes.
struct Intersectable
{
public:
    virtual bool Intersect(const Vector3& origin, const Vector3& direction, float& depth, float near) const = 0;
    virtual Shading getShading() const = 0;
    virtual Vector3 getCenter() const = 0;
};

#endif
