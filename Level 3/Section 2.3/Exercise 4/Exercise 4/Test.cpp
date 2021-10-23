// Section 2.3 Exercise 4
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Program for class Point in Point.hpp and Point.cpp.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add test scripts for Distance() and DistanceOrigin() functions.
// 2021-06-26 CC Delete : Setter functions.
//				 Add : using constructor to set user input values.
//            CC Modified the test scripts to fit the overloading code.
//			  CC Delete all previous tests.
//               Add tests for const Point object.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

int main()
{
	// Create a constant point and try to set x-coordinate.
	const Point cp(1.5, 3.9);
	
	// Print the x-coordiante of cp point.
	cout << cp.X() << endl;

	// Print the ToString() result.
	// Print distance to the origin.
	cout << "Distance between " << cp.ToString() << " and (0, 0) is " << cp.Distance() << endl;

	// Print the distance to another point.
	cout << "Distance between " << cp.ToString() << " and (1, 1) is " << cp.Distance(Point(1.0, 1.0)) << endl;

}


