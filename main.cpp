// Computer Graphics Project Assignment 1 Ray Tracing
// main.cpp
#define _USE_MATH_DEFINES

#include "NffParser.h"
#include "PpmFile.h"
#include "IntegersForVector2.h"
#include "Matrix.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>

// Convert a Degree to a Radian.
inline float convertDegreeToRadian(const float& dDegree)
{
	return dDegree * M_PI / 180;
}

// Pass the C++ Command Line Arguments argc and argv to the main() Function.
int main (int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Ray Tracer" << std::endl;
		std::cout << "Usage: " << argv[0] << " filename" << std::endl;
		return 1;
	}

	// Parse the .nff File and prepare the scene.
	NffParser settings(argv[1]);

	// Get the values from the .nff File.
	Color background = settings.getBackgroundColor();
	ViewPort view = settings.getViewPort();
	std::vector<Intersectable*> objects = settings.getObjects();

	// Get the Resolution and set up the Calculations.
	IntegersForVector2 resolution = view.getResolution();
	float radians = convertDegreeToRadian(view.getAngle() * 0.5);
	float scaleAngle = tan(radians);
	float aspectRatio = resolution.getX() / (float)resolution.getY();
	float inverseOfWidth = 1 / (float)resolution.getX();
	float invHeight = 1 / (float)resolution.getY();
	float pixelCount = resolution.getX() * resolution.getY();
	float pixelIterator = 0;

	// Build the Pixel Vector and size the Pixel Vector to the final image.
	std::vector<Color> pixels;
	// Change the vector to be the Pixel Count Size that is represented by the Float Variable "float pixelCount".
	pixels.resize(pixelCount);
	// Set the Pixel Vector to the default color.
	std::fill(pixels.begin(), pixels.end(), background);

	// Make the world view matrix.
	Matrix world;
	world.LookAt(view.getFrom(), view.getAt(), view.getUp());

	// Create the ray origin space from the view matrix.
	Vector3 origin = world.TransformPoint({0, 0, 0});

	std::sort(objects.begin(), objects.end(), [&origin](Intersectable* i, Intersectable* j) { return (i->getCenter() - origin).squareLength() < (j->getCenter() - origin).squareLength(); });

	// Loop through pixel locations.
	for (int y = 0; y < resolution.getY(); ++y)
	{
		for (int x = 0; x < resolution.getX(); ++x, ++pixelIterator)
		{
			std::cout << "Casting: " << (pixelIterator * 100 / pixelCount) << "%           " << std::endl << "\x1b[A";
			// Create a Ray to send.
			float xDirection = (2 * (x + 0.5) * inverseOfWidth - 1) * scaleAngle * aspectRatio;
			float yDirection = (1 - 2 * (y + 0.5) * invHeight) * scaleAngle;
			Vector3 direction = Vector3::normalize(world.TransformDirection({ xDirection, yDirection, -1 }));

			// Loop through the Polygons to see if there is a Hit Record.
			float near = std::numeric_limits<float>::max();
			Intersectable* hitRecord = nullptr;
			for (std::vector<Intersectable*>::iterator iter = objects.begin(); iter != objects.end(); ++iter)
			{
				float tValueIsTheDepth = std::numeric_limits<float>::max();
				if ((*iter)->Intersect(view.getFrom(), direction, tValueIsTheDepth, near))
				{
					// If there is a Hit Record, then check the t-value that is represented by the Float Variable "float tValueIsTheDepth" to
					// see if the New Hit Record is closer than the Old Hit Record.
					if (tValueIsTheDepth > view.getHither() && tValueIsTheDepth < near)
					{
						near = tValueIsTheDepth;
						hitRecord = *iter;
					}
				}
			}

			// If there is a Hit Record, then update the Pixel.
			if (hitRecord)
			{
				pixels[pixelIterator] = hitRecord->getShading().getColor();
			}
		}
	}

	// Write the final image to the Portable Pix Map PPM File that is the .ppm File.
	PpmFile::write("./output.ppm", resolution, pixels);

	return 0;
}
