// Computer Graphics Project Assignment 1 Ray Tracing
// Color.h
#ifndef COLOR_H
#define COLOR_H

#include<iostream>

struct Color
{
public:
    Color();
    Color(float, float, float);

    friend std::istream& operator >> (std::istream&, Color&);
    friend std::ostream& operator << (std::ostream&, const Color&);

    float getColorRed() const;
    float getColorGreen() const;
    float getColorBlue() const;

    unsigned char getRedColorByte() const;
    unsigned char getBlueColorByte() const;
    unsigned char getGreenColorByte() const;

private:
    float redColor;
    float greenColor;
    float blueColor;
};

#endif
