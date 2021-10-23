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


namespace CHENJIANXIANG
{
	namespace CAD
	{
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

		const Point Line::P1() const
		{
			return p1; // Get the Point object p1.
		}

		const Point Line::P2() const
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

		Line& Line::operator = (const Line& source)
		{
			if (this != &source)
			{// Avoid doing assign to myself
				this->p1 = source.p1;
				this->p2 = source.p2;
			}

			return (*this);
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

		// Global functions
		ostream& operator << (ostream& os, const Line& l)
		{
			os << l.ToString();

			return os; // return ostream of line description.
		}

	}
}