// Section 2.3 Exercise 6
// Circle.cpp
// [Author] Cliff Chen
// [Description] Test Program for class Circle in Circle.hpp and Circle.cpp.
// [Modifications]
// 2021-06-26 CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Circle.hpp"

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	double cx; // x-coordinate for center point.
	double cy; // y-coordinate for center point.
	double redius;  // redius of circle.

	// Ask the user for the x- and y-coordinates of the center.
	cout << "Please input x and y of the center point here. (format: x y)" << endl;

	cin >> cx >> cy; // read x, y value from console.

	// Ask the user to input the radius.
	cout << "Please input radius" << endl;

	cin >> redius; // read redius from console.

	// Create center object.
	Point center_point(cx, cy);

	// Create circle object.
	Circle circle(center_point, redius);
	
	// Test member functions.
	cout << circle.ToString() << endl << endl;
	cout << "Diameter: " << circle.Diameter() << ", Area: " << circle.Area() << ", Circumference: " << circle.Circumference() << "." << endl;

}


