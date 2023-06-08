// Computer Graphics Project Assignment 1 Ray Tracing
// NffParser.cpp
#include "NffParser.h"
#include "Polygon.h"
#include "Sphere.h"
#include <fstream>

NffParser::NffParser(std::string fileName)
{
        backgroundColor = {0, 0, 0};

	parse(fileName);
}

// Ensure that the created elements inside the objects vector get deleted to prevent a memory leak.
NffParser::~NffParser()
{
	for(std::vector<Intersectable*>::iterator iter = objects.begin(); iter != objects.end(); ++iter)
	{
		delete(*iter);
	}
	objects.clear();
}

Color NffParser::getBackgroundColor()
{
	return backgroundColor;
}

ViewPort NffParser::getViewPort()
{
	return viewPort;
}

std::vector<Intersectable*> NffParser::getObjects()
{
	return objects;
}

void NffParser::parse(std::string fileName)
{
	std::ifstream file(fileName);
	if(!file.good())
	{
		throw std:: runtime_error("Error: Unable to open Neutral File Format NFF file, that is .nff File, for reading.");
	}

	Shading current = { {0,0,0}, 0,0,0,0,0};

	// Loop through the lines until reaching the end.
	while(!file.eof())
	{
		// Reset the "char element" to 0 so that the input is not repeated.
		char element = 0;
		file >> element;
		switch (element)
		{
		// Fill the background color with the specified values.
		case 'b':
		    file >> backgroundColor;
		    break;

		// Viewpoint
		case 'v':
		    file >> viewPort;
		    break;

		// Fill Shading.
		case 'f':
		    file >> current;
		    break;

		// Polygon
		case 'p':
		{
		    Polygon *p = new Polygon();
		    file >> *p;
		    p->setShading(current);
		    objects.push_back(p);
		}
		    break;

		// Sphere
		case 's':
		{
		    Sphere *s = new Sphere();
		    file >> *s;
		    s->setShading(current);
		    objects.push_back(s);
		}

		// Skip current line when it cannot recognize a element to parse.
		default:
		    file.ignore(255, '\n');
		    break;
		}
	}

	file.close();
}


