// Section 2.2 Exercise 1
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Program for class Point in Point.hpp and Point.cpp. 
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

int main()
{
	// Declare x, y coordinates for user to input.
	double x;
	double y;

	// Ask the user for the x - and y - coordinates using the std::cin object.
	cout << "Please input the value of x-coordinate." << endl;
	cin >> x;
	cout << "Please input the value of y-coordinate." << endl;
	cin >> y;

	// Create Point object using the default constructor.
	Point test_point;

	// Set the coordinates entered by the user using the setter functions.
	test_point.SetX(x);
	test_point.SetY(y);

	// Print the description of the point returned by the ToString() function.
	cout << test_point.ToString() << endl;

	// Print the point coordinates using the get functions.
	cout << "GetX() = " << test_point.GetX() << endl;
	cout << "GetY() = " << test_point.GetY() << endl;

}