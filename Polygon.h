// Computer Graphics Project Assignment 1 Ray Tracing
// Polygon.h
#ifndef POLYGON_H
#define POLYGON_H

#include "Intersectable.h"
#include "Vector3.h"
#include "Shading.h"
#include <vector>

struct Polygon : public Intersectable
{
public:
    Polygon();
    ~Polygon();

    int getCount() const;
    std::vector<Vector3>getVerticies() const;
    virtual Shading getShading() const;
    virtual Vector3 getCenter() const;

    void setShading(Shading);

    friend std::istream& operator>> (std::istream&, Polygon&);

    // Apply the Triangle Fan Method.
    // 0, 1, 2, 3, 4 => (0, 1, 2), (0, 2, 3), (0, 3, 4)
    virtual bool Intersect(const Vector3&, const Vector3&, float&, float) const;

private:
    bool IntersectTriangle(const int, const int, const int, Vector3, Vector3, float&) const;
    int count;
    float squareRadius;
    std::vector<Vector3> verticies;
    std::vector<int> indicies;
    Vector3 center;
    Shading shading;
};

#endif
