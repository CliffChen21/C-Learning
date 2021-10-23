// Section 2.3 Exercise 2
// Point.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Point.h.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add copy constructor and constructor that accepts x- and y-coordinates.
//            CC Change call-by-value in Distance to call-by-constant-reference.

#include "Point.hpp" // Referring Point header file.

#include <sstream>   // Library contains stringstream/str().
#include <cmath>     // Library contains sqrt().

using namespace std; // New standard of iostream (old : iostream.h).


// Default constructor and destructor
Point::Point() : x(x), y(0)
{
	// Default constructor should initialize everything.
	cout << "Call the default constructor." << endl;
}

// Copy constructor.
Point::Point(const Point& p) : x(p.x), y(p.y)
{
	cout << "Call the copy constructor." << endl;
}

// Constructor accepts x-/y-coordinates.
Point::Point(double x_val, double y_val) : x(x_val), y(y_val)
{
	cout << "Call the constructor accepts x- and y- coordinats." << endl;
}

// Default destructor.
Point::~Point()
{
	// Destructor will be automatically called by the system when object is out-of-scope.
	cout << "Call the default destructor." << endl;
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

// Get the description string of Point.
string Point::ToString()
{
	stringstream description; // declare a stringstream to  store the description.

	description << "Point(" << x << ", " << y << ")"; // store description to stringstream by cin.

	return description.str(); // select string of stringstream to return.
}

// Calculate the distance between two points.
double Point::Distance(const Point& p)
{
	//p.x = 0; It would raise a compilation error.
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)); // Pythagoras algorithm.
}

// Calculate the distance to the origin (0, 0).
double Point::DistanceOrigin()
{
	return sqrt(pow(x - 0, 2) + pow(y - 0, 2)); // Pythagoras algorithm.
}