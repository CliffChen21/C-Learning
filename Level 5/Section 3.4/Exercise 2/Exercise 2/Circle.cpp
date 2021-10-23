// Section 3.4 Exercise 2
// Circle.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Circle.hpp.
// [Modifications]
// 2021-10-03 CC establised the first version.

#define _USE_MATH_DEFINES // Enable pi definition.

#include "Point.hpp"
#include "Circle.hpp"

#include <iostream>
#include <sstream>

using namespace std;


// Constructors and Desctrucotrs

Circle::Circle() : Shape()
{ // Default constructor
	center = Point(0.0, 0.0);
	radius = 1.0;
}

Circle::Circle(const Circle& circle) : Shape(circle)
{ // Copy constructor.
	center = circle.center;
	radius = circle.radius;
}

Circle::Circle(const Point& center_val, double radius_val) : Shape()
{
	center = center_val;
	if (radius_val >= 0)
	{
		radius = radius_val;
	}
	else
	{
		radius = 0;
		cout << "radius should be nonegative. Has already reset radius to zero." << endl;
	}
	// constructor accepts center point and radius.
}
Circle::~Circle()
{
	// Default destructor.
}


// Member operator overloading	

Circle& Circle::operator = (const Circle& source)
{
	if (this != &source)
	{// Avoid doing assign to myself
		
		Shape::operator=(source); // Call base assignment.

		this->center = source.center;
		this->radius = source.radius;
	}

	return (*this);
}

string Circle::ToString() const
{
	stringstream description;

	description << "The circle is located at " << center.ToString() << " with " << "radius, " << radius << ".";

	return description.str(); // Read string from buffer.
}

// Global functions
ostream& operator << (ostream& os, const Circle& c)
{
	os << c.ToString();

	return os; // return ostream of circle description.
}












