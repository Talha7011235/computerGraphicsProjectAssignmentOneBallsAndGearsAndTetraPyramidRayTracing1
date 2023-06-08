// Computer Graphics Project Assignment 1 Ray Tracing
// PpmFile.h
#ifndef PPMFILE_H
#define PPMFILE_H

#include "IntegersForVector2.h"
#include "Color.h"
#include <string>
#include <vector>

class PpmFile
{
public:
    static void write(const std::string fileName, IntegersForVector2 resolution, std::vector<Color> pixels);
};

#endif
