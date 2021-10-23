// Section 2.2 Exercise 1
// Point.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Point.h.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.

#include "Point.hpp" // Referring Point header file.

#include <sstream>   // Library contains stringstream/str().

using namespace std; // New standard of iostream (old : iostream.h).


// Default constructor and destructor
Point::Point()
{
	// Default Initializing.
	x = 0.0;
	y = 0.0;
}

Point::~Point()
{
	// Destructor will be automatically called by the system when object is out-of-scope.
}

// ********Member Functions********
// Accessing functions

// Get the value of x-coordinate.
double Point::GetX()
{
	return x;
}

// Get the value of y-coordinate.
double Point::GetY()
{
	return y;
}

// Modifiers

// Set x-coordinate.
void Point::SetX(double x_val)
{
	x = x_val; // set user-defined value x_val to x-coordinate.
}

// Set y-coordinate.
void Point::SetY(double y_val)
{
	y = y_val; // set user-defined value y_val to y-coordinate.
}

// Others

// Get the description string of Point.
string Point::ToString()
{
	stringstream description; // declare a stringstream to  store the description.

	description << "Point(" << x << ", " << y << ")"; // store description to stringstream by cin.

	return description.str(); // select string of stringstream to return.
}