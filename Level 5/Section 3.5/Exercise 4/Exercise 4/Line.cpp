// Section 3.4 Exercise 2
// Line.cpp
// [Author] Cliff Chen
// [Description] Source file defines and implements the class and its
//				 memebr functions in Line.hpp.
// [Modifications]
// 2021-10-03 CC established the 1st version.


#include "Line.hpp"
#include "Point.hpp"
#include <sstream>


Line::Line() : Shape()
{// Default constructor
	p1 = Point(0.0, 0.0);
	p2 = Point(0.0, 0.0);

}

Line::Line(const Point& p1_val, const Point& p2_val) : Shape()
{// Constructor accepts p1 and p2
	p1 = p1_val;
	p2 = p2_val;
}

Line::Line(const Line& line) : Shape(line)
{// Copy constructor.
	p1 = line.p1;
	p2 = line.p2;
}

Line::~Line()
{// Destructor
	cout << "The Line destructor is called." << endl;
}

Line& Line::operator = (const Line& source)
{
	if (this != &source)
	{// Avoid doing assign to myself
		
		Shape::operator=(source); // Call base assignment.

		this->p1 = source.p1;
		this->p2 = source.p2;
	}

	return (*this);
}

string Line::ToString() const
{
	stringstream description; // using stringstream to store buffer text.

	std::string s = Shape::ToString(); // Shape description string.

	description << "Line : start-point " << p1.ToString() << ", end-point, " << p2.ToString() << s; // Delegation.

	return description.str(); // Using str() to read the buffer.
}

void Line::Draw() const
{
	cout << "Draw a line." << endl;
}

// Global functions
ostream& operator << (ostream& os, const Line& l)
{
	os << l.ToString();

	return os; // return ostream of line description.
}
