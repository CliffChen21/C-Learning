// Section 2.3 Exercise 6
// Circle.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class circle with members center and redius
//               privately, and CenterPoint()/Redius()/Diameter()/ Area()/Circumference()/ToString() functions publicly.
//               Also declare default constructor, destructor, copy constructor and constructor accepting center and redius
//				 Using overloading techniiques.
// [Modifications]
// 2021-06-27 CC establised the first version.

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.hpp"

#include <iostream>
using namespace std;

class Circle
{
private:
	Point center;
	double redius;

public:
	Circle(); // Default constructor
	Circle(const Circle& circle); // Copy consturctor
	Circle(const Point& center, double redius); // Constructor accepts center and redius

	~Circle(); // Destructor.

	
	// Accessing functions
	
	Point CenterPoint() const; // Constant member function.
	// [Description] Get the center point of circle.
	// [Input] None.
	// [Output] Point object.
	double Redius() const;
	// [Description] Get the redius of circle.
	// [Input] None.
	// [Output] Floating-point number. 


	// Modifiers

	void CenterPoint(const Point& center_val); // const call by reference for user defined class.
	// [Description] Set the value of center.
	// [Input] Point object as circle point.
	// [Output] None.
	void Redius(double redius_val);
	// [Description] Set the value of redius.
	// [Input] Double floating-point number as circle's redius.
	// [Output] None.


	// Others

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


#endif