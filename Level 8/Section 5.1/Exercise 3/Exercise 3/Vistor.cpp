// Section 5.1 Exercise 3
// Vistor.cpp
// [Author] Cliff Chen
// [Description] Source file contains implementation of Vistor class in Vistor.hpp
// [Modifications]
// 2021-10-11 CC Establish the 1st Version.

#include "Visitor.hpp"

Visitor::Visitor() : boost::static_visitor<void>()
{ // Default constructor
	m_dx = 0.0;
	m_dy = 0.0;
}

Visitor::Visitor(const Visitor& source) : boost::static_visitor<void>(source)
{ // Copy constructor
	m_dx = source.m_dx;
	m_dy = source.m_dy;
}

Visitor::Visitor(double dx, double dy) : boost::static_visitor<void>()
{ // Constructor accepting x- and y-coordinates
	m_dx = dx;
	m_dy = dy;
}

Visitor::~Visitor()
{ // Destructor
}

Visitor& Visitor::operator = (const Visitor& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Visitor::operator = (source);

	// Copy state
	m_dx = source.m_dx;
	m_dy = source.m_dy;

	return *this;
}

void Visitor::operator () (Point& source) const
{ // () operator for Point

	source.X(source.X() + m_dx);
	source.Y(source.Y() + m_dy);
}

void Visitor::operator () (Line& source) const
{ // () operator for Line

	Point p1 = source.P1();
	Point p2 = source.P2();
	p1.X(p1.X() + m_dx);
	p1.Y(p1.Y() + m_dy);
	p2.X(p2.X() + m_dx);
	p2.Y(p2.Y() + m_dy);

	source.P1(p1);
	source.P2(p2);
}

void Visitor::operator () (Circle& source) const
{ // () operator for Circle

	Point center = source.CenterPoint();
	center.X(center.X() + m_dx);
	center.Y(center.Y() + m_dy);

	source.CenterPoint(center);
}