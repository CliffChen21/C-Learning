// Section 3.4 Exercise 2
// Point.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Point.h.
// [Modifications]
// 2021-10-03 CC Establish the 1st Version.

#include "Point.hpp" // Referring Point header file.

#include <sstream>   // Library contains stringstream/str().
#include <cmath>     // Library contains sqrt().

using namespace std; // New standard of iostream (old : iostream.h).

// Default constructor and destructor
Point::Point() : Shape()
{// Default constructor should initialize everything.
	x = 0.0;
	y = 0.0;
}

Point::Point(const Point& p) : Shape(p)
{// Copy constructor.
	x = p.x;
	y = p.y;
}

Point::Point(double x_val, double y_val) : Shape()
{// Constructor accepts x-/y-coordinates.
	x = x_val;
	y = y_val;
}

// Default destructor.
Point::~Point()
{// Destructor will be automatically called by the system when object is out-of-scope.
}

Point& Point::operator = (const Point& source)
{
	if (this != &source)
	{// Avoid doing assign to myself
		Shape::operator=(source);
		this->x = source.x;
		this->y = source.y;
	}

	return (*this); // return current object as this pointer
}

// Functionality

// - Get the description string of Point.
string Point::ToString() const
{
	stringstream description; // declare a stringstream to  store the description.

	std::string s = Shape::ToString(); // Shape description string.

	description << "Point(" << x << ", " << y << "), " << s; // store description to stringstream by cin.

	return description.str(); // select string of stringstream to return.
}

void Point::Draw() const
{
	cout << "Draw a point." << endl;
}

// Global functions
ostream& operator << (ostream& os, const Point& p)
{
	os << "Point(" << p.x << ", " << p.y << ")"; // Access private member.

	return os; // return ostream of point description.
}

