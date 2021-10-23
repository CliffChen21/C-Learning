// Section 2.6 Exercise 1
// Circle.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class circle with 
//                - Members center and redius privately;
//                - CenterPoint()/Redius()/Diameter()/ Area()/Circumference()/ToString() functions publicly.
//                - Declare default constructor, destructor, copy constructor and constructor accepting center and redius
//                - Assignment operator
// [Modifications]
// 2021-06-27 CC establised the first version.
// 2021-07-11 CC Add assignment operator to amend canonical header file.
// 2021-07-18 CC Add << operator for description output.
// 2021-07-21 CC Included class into namesapce CHENJIANXIANG::CAD

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.hpp"

#include <iostream>
using namespace std;

namespace CHENJIANXIANG
{
	namespace CAD
	{

		class Circle
		{
		private:
			Point center;
			double redius;

		public:
			// Constructors
			Circle(); // Default constructor
			Circle(const Circle& circle); // Copy consturctor
			Circle(const Point& center, double redius); // Constructor accepts center and redius
			~Circle(); // Destructor.

			// Accessing functions	
			Point CenterPoint() const; //  Get the center point of circle.
			double Redius() const; // Get the redius of circle.

			// Modifiers
			void CenterPoint(const Point& center_val); // Set the value of center.
			void Redius(double redius_val); // Set the value of redius.

			// Member operator overloading	
			Circle& operator = (const Circle& source); // Assignment operator.

			// Functionality
			double Diameter() const; // Constant member function.
			// [Description] Compute the diameter for the circle.
			// [Input] None
			// [Output] Double floating-point number as circle's diameter.
			double Area() const; // Constant member function.
			// [Description] Calculate the area of circle.
			// [Input] None.
			// [Output] Area of circle.
			double Circumference() const; // Constant member function.
			// [Description] Calculate the circumference of the circle.
			// [Input] None.
			// [Output] Circumference of the circle.
			string ToString() const; // Constant member function.
			// [Description] Generate circle object dscriptions.
			// [Input] None.
			// [Output] The circle is locatd at (center) with redius (redius).
		};

		ostream& operator << (ostream& os, const Circle& c); // Global << operator function for Circle description.


	}
}
#endif // CIRCLE_HPP