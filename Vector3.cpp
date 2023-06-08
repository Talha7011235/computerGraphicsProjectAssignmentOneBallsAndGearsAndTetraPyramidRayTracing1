// Talha Hussain
// Computer Graphics Project Assignment 1 Ray Tracing
// Vector3.cpp
#include "Vector3.h"
#include <cmath>

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
Vector3::~Vector3() {}

float Vector3::getX() const
{
	return x;
}

float Vector3::getY() const
{
	return y;
}

float Vector3::getZ() const
{
	return z;
}

Vector3 Vector3::operator +(const Vector3& right) const
{
	return { x + right.getX(), y + right.getY(), z + right.getZ() };
}

Vector3 Vector3::operator -(const Vector3& right) const
{
	return { x - right.getX(), y - right.getY(), z - right.getZ() };
}

Vector3 Vector3::operator *(const float& right) const
{
	return { x * right, y * right, z * right };
}

Vector3 Vector3::operator /(const float& right) const
{
	return { x / right, y / right, z / right };
}

Vector3& Vector3::operator+=(const Vector3& right)
{
	x += right.x;
	y += right.y;
	z += right.z;
	return *this; 
}
float Vector3::dot(const Vector3& left, const Vector3& right)
{
	return left.getX() * right.getX() + left.getY() * right.getY() + left.getZ() * right.getZ();
}


Vector3 Vector3::cross(const Vector3& left, const Vector3& right)
{
	// Determine the Cross Product using a method described at https://cs.wellesley.edu/~cs307/readings/08-geometry.html.
	float x = left.getY() * right.getZ() - left.getZ() * right.getY();
	float y = left.getZ() * right.getX() - left.getX() * right.getZ();
	float z = left.getX() * right.getY() - left.getY() * right.getX();

	return { x, y, z };
}

std::istream& operator>> (std::istream& in, Vector3& value)
{
	in >> value.x >> value.y >> value.z;
	return in;
}

Vector3 Vector3::normalize(const Vector3& value)
{
	// Create a Unit Length 1 Vector by dividing each element by the length of the Vector. 
	float magnitude = value.magnitude();
	return value / magnitude;
}

float Vector3::squareLength() const
{
	return x * x + y * y + z * z;
}

float Vector3::magnitude() const
{
	return sqrt(squareLength());
}
