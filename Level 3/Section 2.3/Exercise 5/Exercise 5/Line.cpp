// Section 2.3 Exercise 5
// Point.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class Line with start-point p1 and end-point p2
//               privately, and P1()/P2()/Length()/ToString() functions publicly.
// [Modifications]
// 2021-06-26 CC established the 1st version.

#include "Line.hpp"
#include "Point.hpp"
#include <sstream>


Line::Line() : p1(0.0, 0.0), p2(0.0, 0.0)
{
	// Default constructor
}

Line::Line(const Point& p1_val, const Point& p2_val) : p1(p1_val), p2(p2_val)
{
	// Constructor accepts p1 and p2
}

Line::Line(const Line& line) : p1(line.p1), p2(line.p2)
{
	// Copy constructor.
}

Line::~Line()
{
	// Destructor
}

Point Line::P1() const
{
	return p1; // Get the Point object p1.
}

Point Line::P2() const
{
	return p2; // Get the Point object p2.
}

void Line::P1(const Point& p1_val)
{
	p1 = p1_val; // Set the vslue of p1.
}

void Line::P2(const Point& p2_val)
{
	p1 = p2_val; // Set the vslue of p2.
}

double Line::Length() const
{
	return p1.Distance(p2); // Using Point member to compute the length of line.
}

string Line::ToString() const
{
	stringstream description; // using stringstream to store buffer text.
	
	description << "Line : start-point " << p1.ToString() << ", end-point " << p2.ToString(); // Delegation.

	return description.str(); // Using str() to read the buffer.
}