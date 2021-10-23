// Section 3.5 Exercise 3
// Test.cpp
// [Author] Cliff Chen
// [Description] Test the code of virtual destructor.
// [Modifications]
// 2021-10-03 CC establised the first version.

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];

	// If Shape destructor is not virtual,
	// Point destructor will be only called at new Line.

	// If Shape destructor is virtual,
	// The proper destructor will be called.

}