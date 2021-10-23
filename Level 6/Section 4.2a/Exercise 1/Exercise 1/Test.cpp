// Section 4.2a Exercise 1
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Array class with templates.
// [Modifications]
// 2021-10-06  CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Array.hpp" // Class Array is declared in Array.hpp

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	int size = 3;

	// Create an array of points.
	Array<Point> points(size);

	// Test [] operator.
	points[0] = Point(1, 2);
	points[1] = Point(3, 4);
	points[2] = Point(5, 6);

	// Test GetElement().
	cout << points.GetElement(0) << ", " << points.GetElement(1) << ", " << points.GetElement(2) << endl;

	// Test SetElement().
	points.SetElement(0, Point(7, 8));
	cout << points[0] << ", " << points[1] << ", " << points[2] << endl;

}