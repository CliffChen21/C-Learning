// Section 2.3 Exercise 4
// Point.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class point with members x and y
//               privately, and X()/Y()/Distance() functions publicly.
//               Also declare default constructor, destructor, copy constructor and constructor accepting x- and y- coordinates.
//				 Using overloading techniiques.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.
// 2021-06-21 CC Add Distance() and DistanceOrigin() functions to compute the distance between any two points and the origin.
// 2021-06-26 CC Add copy constructor and constructor accepts x-/y-coordinates.
//            CC Change call-by-value in Distance to call-by-constant-reference.
//            CC Overload SetX()/GetX() tO X(), SetY()/GetY() tO Y(), DistanceOrigin() to Distance()
//            and three constructor to the same name Point.
//            CC Change the getter functions, ToString() and Distance() to constant member functions.

#ifndef POINT_H
#define POINT_H

#include <iostream>  // Library contains count/cin.

using namespace std;


class Point
{
private:
	double x; // x-coordinate.
	double y; // y-coordinate.

public:
	// Default Constructors
	Point();
	// Copy constructor.
	Point(const Point& p);
	// Constructor accepts x-/y-coordinates.
	Point(double x_val, double y_val);

	// Default destructor.
	~Point();


	// ********Member Functions********
	// Accessing functions

	double X() const;
	// [Description] Getter function for x.
	// [Input] None.
	// [Output] (double) x-coordinates.
	double Y() const;
	// [Description] Getter function for y.
	// [Input] None.
	// [Output] (double) y-coordinates.

	//  Modifiers

	void X(double x_val);
	// [Description] Setter function for x.
	// [Input] (double) x-coordinate value.
	// [Output] None.
	void Y(double y_val);
	// [Description] Setter function for y.
	// [Input] (double) y-coordinate value.
	// [Output] None.

	// Others

	string ToString() const;
	// [Description] Return string description of the point.
	// [Input] None.
	// [Output] (string) "Point(x, y)".
	double Distance() const;
	// [Description] Calculate the distance to the origin (0, 0).
	// [Input] None.
	// [Output] Distance between this point and origin.
	double Distance(const Point& p) const;
	// [Description] Calculate the distance between two points.
	// [Input] Pint objects.
	// [Output] Distance between this point and user input point.
};


#endif
