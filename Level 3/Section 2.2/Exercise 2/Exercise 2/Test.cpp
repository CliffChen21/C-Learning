// Section 2.2 Exercise 2
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Program for class Point in Point.hpp and Point.cpp. 
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add test scripts for Distance() and DistanceOrigin() functions.

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

	// Create Point 1 and 2.
	Point point1;
	Point point2;

	// Set the coordinates entered by the user using the setter functions for point 1 and 2.
	// -Point 1
	point1.SetX(x1);
	point1.SetY(y1);
	// -Point 2
	point2.SetX(x2);
	point2.SetY(y2);

	// Calculate and print the distance between origin and point 1.
	cout << "The distance between " << point1.ToString() << " and Point(0, 0) is " << point1.DistanceOrigin() << "." << endl;
	// Calculate and print the distance between origin and point 1.
	cout << "The distance between " << point2.ToString() << " and Point(0, 0) is " << point2.DistanceOrigin() << "." << endl;
	
	// Calculate the distance between two points.
	cout << "The distance between " << point1.ToString() << " and " << point2.ToString() << " is " << point1.Distance(point2) << "." << endl;

}