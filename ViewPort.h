// Computer Graphics Project Assignment 1 Ray Tracing
// ViewPort.h
#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "Vector3.h"
#include "IntegersForVector2.h"

struct ViewPort
{
public:
    ViewPort();

    Vector3 getFrom() const;
    Vector3 getAt() const;
    Vector3 getUp() const;
    float getAngle() const;
    float getHither() const;
    IntegersForVector2 getResolution() const;

    friend std::istream& operator>> (std::istream&, ViewPort&);

private:
    Vector3 from;
    Vector3 at;
    Vector3 up;
    float angle;
    float hither;
    IntegersForVector2 resolution;
};

#endif

