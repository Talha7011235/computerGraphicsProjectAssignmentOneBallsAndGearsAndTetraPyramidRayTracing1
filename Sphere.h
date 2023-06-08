// Computer Graphics Project Assignment 1 Ray Tracing
// Sphere.h
#ifndef SPHERE_H
#define SPHERE_H

#include "Intersectable.h"
#include "Vector3.h"
#include "Shading.h"

struct Sphere : public Intersectable
{
public:
    Sphere();

    float getRadius() const;
    virtual Shading getShading() const;
    virtual Vector3 getCenter() const;

    void setShading(Shading);

    friend std::istream& operator>> (std::istream&, Sphere&);

    virtual bool Intersect(const Vector3&, const Vector3&, float&, float) const;

private:
    Vector3 center;
    float radius;
    Shading shading;
};

#endif
