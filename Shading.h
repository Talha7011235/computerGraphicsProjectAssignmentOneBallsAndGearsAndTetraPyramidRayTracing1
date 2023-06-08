// Computer Graphics Project Assignment 1 Ray Tracing
// Shading.h
#ifndef SHADING_H
#define SHADING_H

#include "Color.h"

struct Shading
{
public:
    Shading();
    Shading(Color, float, float, float, float, float);

    Color getColor();
    float getDiffuse();
    float getSpecular();
    float getShine();
    float getTransmittance();
    float getIndexOfRefraction();

    friend std::istream& operator>> (std::istream&, Shading&);

private:
    Color color;
    float diffuse;
    float specular;
    float shine;
    float transmittance;
    float indexOfRefraction;
};

// There is no Shading, meaning no actual usage for SHADING_H, involved for this Computer Graphics Project Assginment 1 Ray Tracing.
#endif

