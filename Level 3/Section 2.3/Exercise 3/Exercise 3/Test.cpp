// Section 2.3 Exercise 3
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Program for class Point in Point.hpp and Point.cpp.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add test scripts for Distance() and DistanceOrigin() functions.
// 2021-06-26 CC Delete : Setter functions.
//				 Add : using constructor to set user input values.
//            CC Modified the test scripts to fit the overloading code.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

int main()
{
	// Declare two points.
	double x1, y1; // x-, y-coordinates for point 1.
	double x2, y2; // x-, y-coordinates for point 2.

	// Ask the user for the x - and y - coordinates using the std::cin object for point 1 and 2.
	cout << "Please input the value of x y for the first point." << endl;
	cin >> x1 >> y1;
	cout << "Please input the value of x y for the second point." << endl;
	cin >> x2 >> y2;

	// Create Point 1 and 2 and initialize by user-defined constructor using user input value.
	Point point1(x1, y1);
	Point point2;

	// Test the overloading set. 
	point2.X(x2); // Set value for x-coordinate.
	point2.Y(y2); // Set value for y-coordinate.
	
	// Print the x-/y-coordinates for point2.
	cout << "The second point : x-coordinate = " << point2.X() << ", y-ccoordinate = " << point2.Y() << "." << endl << endl;

	// Calculate and print the distance between origin and point 1.
	cout << "The distance between " << point1.ToString() << " and Point(0, 0) is " << point1.Distance() << "." << endl;
	// Calculate and print the distance between origin and point 1.
	cout << "The distance between " << point2.ToString() << " and Point(0, 0) is " << point2.Distance() << "." << endl;
	
	// Calculate the distance between two points.
	cout << "The distance between " << point1.ToString() << " and " << point2.ToString() << " is " << point1.Distance(point2) << "." << endl;

}


