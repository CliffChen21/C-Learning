// Section 3.5 Exercise 4
// Test.cpp
// [Author] Cliff Chen
// [Description] Test abstract functions.
// [Modifications]
// 2021-10-03 CC establised the first version.

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	Shape* shapes[10];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[3] = new Circle;
	shapes[4] = new Circle;
	shapes[5] = new Circle;
	shapes[6] = new Line;
	shapes[7] = new Point;
	shapes[8] = new Line;
	shapes[9] = new Point;
	for (int i = 0; i != 10; i++) shapes[i]->Draw();
	for (int i = 0; i != 10; i++) delete shapes[i];

	// It's impossible to create a Shape instance.
}