Talha Hussain, MyRaceTracingProjectAssignmentOne, Computer Science

Computer Graphics Project Assignment 1: Ray Tracing

Usage:
A make file has been included with the following commands
make rtrace - Runs the compilation using the g++ compiler

make clean - cleans the intermediate files and compiled target

After running make rtrace, choose one of the following make commands below to run and then make clean. Each .ppm File can be generated one at a time.
make gears - runs the compiled target using the gears.nff file
make balls - runs the compiled target using the balls.nff file
make tetra - runs the compiled target using the tetra-3.nff file

convert output.ppm output.png - Converts the output.ppm Files associated with tetra, gears, and balls to their respective output.png Files

Summary:
This is a simple ray tracing application utilizing a custom built basic math library and tesselation system to perform ray tracing on complex polygons and spheres.
There are no advanced features like lighting, shadow, or texture mapping implemented at this time only the basic ray tracing and collision with solid color
surfaces. From the NFF file, although I do store the information needed to perform advanced calculations, however, I do not use it anywhere in code because
it is simply to make parsing the file easier.

Instead of using the Test-Ray Method to handle arbitrary concave polygons, I used a Tesellation Method which uses a 2d planar calculation of angles between edges to
determine the smallest set of values that can be turned into a triangle and repeats until I have verticies that is 2 triangles inside the index buffer. As a result
of applying the Tesellation Method rather than the Test-Ray Method, I can use simple triangle intersection calculations to determine if the polygon has been struck
and to allow for better resolution than a Triangle Fan.


Polygon intersection works by testing all of the triangles produced in the tesselation until I have a valid connection. I first provide an early out to test
if the polygon's center is an amount further than the nearest value that I have found for the pixel. Then I loop through each triangle and do a simple Ray-Triangle
Intersection test and in the case of doing a simple Ray-Triangle Intersection Test, if one of the triangles returns true then I update the t-value and return
to the main function.

Sphere Intersection works similarly but without triangles. I determine if the ray is passing the sphere closer to the center than the radius. This allows me to
find both the first and second intersection points. I then check and return the closest point that is in front of the camera.

Once the pixel's closest intersection point has been found, I was then able to place that color on the screen, if no intersection has been found, then the
background color is shown.

Websites:
To complete my Computer Graphics Project Assignment 1 Ray Tracing, I received helpful inspiration from the following websites shown below:
The Magic of the LookAt Matrix - https://medium.com/@carmencincotti/lets-look-at-magic-lookat-matrices-c77e53ebdf78 
Reading: Geometry - https://cs.wellesley.edu/~cs307/readings/08-geometry.html
