// Section 3.4 Exercise 2
// Shape.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Shape.hpp.
// [Modifications]
// 2021-10-03 CC establised the first version.

#include "Shape.hpp"
#include <stdlib.h>
#include <sstream>

// Constructors and destructor
Shape::Shape() : m_id(rand())
{ // Default constructor
}

Shape::Shape(const Shape& source) : m_id(source.m_id)
{ // Copy constructor
}

Shape::~Shape()
{ // Destructor
}

// Operator overloading
Shape& Shape::operator = (const Shape& source)
{// Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_id = source.m_id;

	return *this;
}

string Shape::ToString() const
{
	stringstream stream;

	stream << "ID: " << m_id;

	return stream.str();
}

// Accessing functions
int Shape::ID() const
{
	return m_id;
}