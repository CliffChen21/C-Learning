// Section 5.1 Exercise 3
// Shape.hpp
// [Author] Cliff Chen
// [Description] Derived class for boost::static_vistor
// [Modifications]
// 2021-10-11 CC establised the first version.

#ifndef Visitor_HPP
#define Visitor_HPP

#include <boost/variant/static_visitor.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

class Visitor : public boost::static_visitor<void>
{
private:
	double m_dx; // x-coordinate
	double m_dy; // y-coordinate

public:
	// Constructor and destructor
	Visitor(); // Default constructor
	Visitor(const Visitor& source); // Copy constructor
	Visitor(double dx, double dy); // Constructor accepting x- and y-coordinates
	~Visitor(); // Destructor

	// Member operator overloading
	Visitor& operator = (const Visitor& source); // Assignment operator
	void operator () (Point& source) const; // () operator function for Point
	void operator () (Line& source) const; // () operator function for Line
	void operator () (Circle& source) const; // () operator function for Circle
};

#endif