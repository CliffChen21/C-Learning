// Section 2.3 Exercise 6
// Circle.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Circle.hpp.
// [Modifications]
// 2021-06-27 CC establised the first version.
#define _USE_MATH_DEFINES // Enable pi definition.

#include "Point.hpp"
#include "Circle.hpp"

#include <iostream>
#include <sstream>

using namespace std;

// Constructors and Desctrucotrs

Circle::Circle() : center(Point()), redius(0.0)
{
	// Default constructor.
}

Circle::Circle(const Circle& circle) : center(circle.center), redius(circle.redius)
{
	// Copy constructor.
}

Circle::Circle(const Point& center_val, double redius_val)
{
	center = center_val;
	if (redius_val >= 0)
	{
		redius = redius_val;
	}
	else
	{
		redius = 0;
		cout << "Redius should be nonegative. Has already reset redius to zero." << endl;
	}
	// constructor accepts center point and redius.
}
Circle::~Circle()
{
	// Default destructor.
}


// Accessing functions

Point Circle::CenterPoint() const // constant member function
{
	return center; // Point objects
}

double Circle::Redius() const // constant member function
{ 
	return redius; // double number.
}

// Modifiers

void Circle::CenterPoint(const Point& center_val) // constant reference
{
	center = center_val;
}

void Circle::Redius(double redius_val) // constant reference
{
	redius = redius_val;
}


// Others

double Circle::Diameter() const
{
	return redius * 2.0;
}

double Circle::Area() const
{
	return M_PI * pow(redius, 2);
}

double Circle::Circumference() const
{
	return 2.0 * M_PI * redius;
}

string Circle::ToString() const
{
	stringstream description;

	description << "The circle is located " << center.ToString() << " with " << "redius, " << redius << ".";

	return description.str(); // Read string from buffer.
}