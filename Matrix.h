// Computer Graphics Project Assignment 1 Ray Tracing
// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include "Vector3.h"
#include <array>

struct Matrix
{
public:
    Matrix();

    void LookAt(const Vector3&, const Vector3&, const Vector3&);
    Vector3 TransformPoint(const Vector3&) const;
    Vector3 TransformDirection(const Vector3&) const;

private:
    std::array<float, 16> data;
};

#endif
