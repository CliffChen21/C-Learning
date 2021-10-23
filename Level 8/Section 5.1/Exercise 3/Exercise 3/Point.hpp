// Section 3.4 Exercise 2
// Point.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class point with:
//					- Members x and y privately;
//					- X()/Y()/Distance() functions publicly.
//                  - Also declare default constructor, destructor, copy constructor and constructor accepting x- and y- coordinates.
//                  - User-defined operator -, *, +, ==, = and *=.
// [Modifications]
// 2021-10-03 CC Establish the 1st Version.


#ifndef POINT_H
#define POINT_H

#include <iostream>  // Library contains count/cin.
#include "Shape.hpp" // Import Shape library.

using namespace std;
class Point : public Shape
{
private:
	double x; // x-coordinate.
	double y; // y-coordinate.

public:
	// Constructors
	Point(); // Default constructor
	Point(const Point& p); // Copy constructor
	Point(double x_val, double y_val); // Constructor with x, y values
	virtual ~Point(); // Destructor

	// Member operator overloading	
	Point& operator = (const Point& source); // Assignment operator.

	// Functionality
	double X() const; // X-Getter
	double Y() const; // Y-Getter
	void X(double dx); // X-Setter
	void Y(double dy); // Y-Setter

	string ToString() const;
	// [Description] Return string description of the point.
	// [Input] None.
	// [Output] (string) "Point(x, y)".

	void Draw() const;
	// Override the PVMF to draw graph.

	// Global friend operator overloading
	friend ostream& operator << (ostream& os, const Point& p); // Global << operator function for Point description.
};

#endif // POINT_H
