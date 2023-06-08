// Computer Graphics Project Assignment 1 Ray Tracing
// NffParser.h
#ifndef NFFPARSER_H
#define NFFPARSER_H

#include "Color.h"
#include "ViewPort.h"
#include "Intersectable.h"
#include <string>
#include <vector>

class NffParser
{
public:
    NffParser(std::string fileName);
    ~NffParser();

    Color getBackgroundColor();
    ViewPort getViewPort();
    std::vector<Intersectable*> getObjects();

private:
    void parse(std::string fileName);

    Color backgroundColor;
    ViewPort viewPort;
    std::vector<Intersectable*> objects;
};

#endif

