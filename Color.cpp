// Computer Graphics Project Assignment 1 Ray Tracing
// Color.cpp
#include "Color.h"

Color::Color() : redColor(0), greenColor(0), blueColor(0) {}
Color::Color(float r, float g, float b) : redColor(r), greenColor(g), blueColor(b) {}
float Color::getColorRed() const
{
	return redColor;
}

float Color::getColorGreen() const
{
	return greenColor;
}

float Color::getColorBlue() const
{
	return blueColor;
}

unsigned char Color::getRedColorByte() const
{
	return (unsigned char)(redColor * 255);
}

unsigned char Color::getGreenColorByte() const
{
	return (unsigned char) (greenColor * 255);
}

unsigned char Color::getBlueColorByte() const
{
	return (unsigned char) (blueColor * 255);
}

std::istream& operator >> (std::istream& in, Color& value)
{
	in >> value.redColor >> value.greenColor >> value.blueColor;
	return in;
}


std::ostream& operator << (std::ostream& out, const Color& value)
{
	// To support the Portable Pixel Map Versin 6 P6 Style of the Portable Pixel Map PPM, specifically .ppm File, output as bytes instead of as Floating Point
	// American Standard Code for Informatin Interchange ASCII values.
	out << value.getRedColorByte() << value.getGreenColorByte() << value.getBlueColorByte();
	return out;
}
