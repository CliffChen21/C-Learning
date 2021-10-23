// Section 3.4 Exercise 2
// Circle.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class circle with 
//                - Members center and radius privately;
//                - CenterPoint()/radius()/Diameter()/ Area()/Circumference()/ToString() functions publicly.
//                - Declare default constructor, destructor, copy constructor and constructor accepting center and radius
//                - Assignment operator
// [Modifications]
// 2021-10-03 CC establised the first version.


#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.hpp"
#include "Shape.hpp"

#include <iostream>
using namespace std;

class Circle : public Shape
{
private:
	Point center;
	double radius;

public:
	// Constructors
	Circle(); // Default constructor
	Circle(const Circle& circle); // Copy consturctor
	Circle(const Point& center, double radius); // Constructor accepts center and radius
	virtual ~Circle(); // Destructor.

	// Member operator overloading	
	Circle& operator = (const Circle& source); // Assignment operator.
	
	Point CenterPoint() const; //  Get the center point of circle.

	void CenterPoint(const Point& center_val); // const call by reference for user defined class.
	// [Description] Set the value of center.
	// [Input] Point object as circle point.
	// [Output] None.

	string ToString() const; // Constant member function.
	// [Description] Generate circle object dscriptions.
	// [Input] None.
	// [Output] The circle is locatd at (center) with radius (radius).

	void Draw() const; 
	// [Description] Override the PVMF to draw graph.
};

ostream& operator << (ostream& os, const Circle& c); // Global << operator function for Circle description.

#endif // CIRCLE_HPP