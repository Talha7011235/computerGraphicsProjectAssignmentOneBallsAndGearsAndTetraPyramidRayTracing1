// Computer Graphics Project Assignment 1 Ray Tracing
// ViewPort.cpp
#include "ViewPort.h"

ViewPort::ViewPort() : from(0, 0, 0), at(0, 0, 1), up(0, 1, 0), angle(45), hither(0.1f), resolution(512, 512) {}

Vector3 ViewPort::getFrom() const
{
	return from;
}

Vector3 ViewPort::getAt() const
{
	return at;
}

Vector3 ViewPort::getUp() const
{
	return up;
}

float ViewPort::getAngle() const
{
	return angle;
}

float ViewPort::getHither() const
{
	return hither;
}

IntegersForVector2 ViewPort::getResolution() const
{
	return resolution;
}

std::istream& operator>> (std::istream& in, ViewPort& value)
{
	std::string ignore;
	in >> ignore >> value.from;
	in >> ignore >> value.at;
	in >> ignore >> value.up;
	in >> ignore >> value.angle;
	in >> ignore >> value.hither;
	in >> ignore >> value.resolution;
	return in;
}
