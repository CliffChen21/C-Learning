// Section 2.5 Exercise 2
// Point.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Point.h.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add copy constructor and constructor that accepts x- and y-coordinates.
//            CC Change call-by-value in Distance to call-by-constant-reference.
//            CC Overload SetX()/GetX() tO X(), SetY()/GetY() tO Y(), DistanceOrigin() to Distance()
//               and three constructor to the same name Point.
//            CC Change the getter functions, ToString() and Distance() to constant member functions.
// 2021-07-11 CC Add operator functions based on the mathematically logic.
// 2021-07-18 CC Add << operator for description output.
//            CC Change << operator as a friend function.

#include "Point.hpp" // Referring Point header file.

#include <sstream>   // Library contains stringstream/str().
#include <cmath>     // Library contains sqrt().

using namespace std; // New standard of iostream (old : iostream.h).


// Default constructor and destructor
Point::Point() : x(0.0), y(0.0)
{
	// Default constructor should initialize everything.
}

// Copy constructor.
Point::Point(const Point& p) : x(p.x), y(p.y) // colon syntax.
{
}

// Constructor accepts x-/y-coordinates.
Point::Point(double x_val, double y_val) : x(x_val), y(y_val) // colon syntax.
{
}

// Default destructor.
Point::~Point()
{
	// Destructor will be automatically called by the system when object is out-of-scope.
}

// Accessing functions

// - Get the value of x-coordinate.
double Point::X() const
{

	return x;
}

// - Get the value of y-coordinate.
double Point::Y() const
{

	return y;
}

// Modifiers

// - Set x-coordinate.
void Point::X(double x_val)
{
	x = x_val; // set user-defined value x_val to x-coordinate.
}

// - Set y-coordinate.
void Point::Y(double y_val)
{
	y = y_val; // set user-defined value y_val to y-coordinate.
}

// Member operator overloadings

Point Point::operator - () const
{
	
	return Point(-x, -y);
}

Point Point::operator * (double factor) const
{
	
	return Point(factor * x, factor * y);
}

Point Point::operator + (const Point& p) const
{
	
	return Point(x + p.x, y + p.y);
}

bool Point::operator == (const Point& p) const
{
	
	return (x == p.x) && (y == p.y);
}

Point& Point::operator = (const Point& source)
{
	if (this != &source)
	{// Avoid doing assign to myself
		this->x = source.x;
		this->y = source.y;
	}
	
	return (*this); // return current object as this pointer
}

Point& Point::operator *= (double factor)
{
	this->x *= factor;
	this->y *= factor;

	return (*this);
}

// Functionality

// - Get the description string of Point.
string Point::ToString() const
{
	stringstream description; // declare a stringstream to  store the description.

	description << "Point(" << x << ", " << y << ")"; // store description to stringstream by cin.

	return description.str(); // select string of stringstream to return.
}

// - Calculate the distance between two points.
double Point::Distance(const Point& p) const
{
	//p.x = 0; It would raise a compilation error.
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)); // Pythagoras algorithm.
}

// - Calculate the distance to the origin (0, 0).
double Point::Distance() const
{
	
	return sqrt(pow(x - 0, 2) + pow(y - 0, 2)); // Pythagoras algorithm.
}

// Global functions
ostream& operator << (ostream& os, const Point& p)
{
	os << "Point(" << p.x << ", " << p.y << ")"; // Access private member.

	return os; // return ostream of point description.
}
