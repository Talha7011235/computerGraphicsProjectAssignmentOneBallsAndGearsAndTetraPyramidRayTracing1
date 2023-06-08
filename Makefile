rtrace: main.cpp Color.cpp IntegersForVector2.cpp Vector3.cpp Matrix.cpp Shading.cpp ViewPort.cpp Polygon.cpp Sphere.cpp NffParser.cpp PpmFile.cpp
	g++ -O3 -o rtrace main.cpp Color.cpp IntegersForVector2.cpp Vector3.cpp Matrix.cpp Shading.cpp ViewPort.cpp Polygon.cpp Sphere.cpp NffParser.cpp PpmFile.cpp

gears: rtrace
	./rtrace gears.nff

tetra: rtrace
	./rtrace tetra-3.nff

balls: rtrace
	./rtrace balls.nff

clean:
	rm rtrace

