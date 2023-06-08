// Talha Hussain
// Computer Graphics Project Assignment 1 Ray Tracing
// Vector3.h
#ifndef VECTOR3_H
#define VECTOR3_H

#include<iostream>

struct Vector3
{
public:
    Vector3();
    Vector3(float, float, float);
    virtual ~Vector3();

    float getX() const;
    float getY() const;
    float getZ() const;

    Vector3 operator +(const Vector3&) const;
    Vector3 operator -(const Vector3&) const;
    Vector3 operator *(const float&) const;
    Vector3 operator /(const float&) const;

    Vector3& operator +=(const Vector3&);

    static Vector3 cross(const Vector3&, const Vector3&);
    static float dot(const Vector3&, const Vector3&);

    float squareLength() const;
    float magnitude() const;

    static Vector3 normalize(const Vector3&);

    friend std::istream& operator >> (std::istream&, Vector3&);

private:
    float x;
    float y;
    float z;
};

#endif
