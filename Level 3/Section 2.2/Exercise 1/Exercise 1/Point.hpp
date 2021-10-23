// Section 2.2 Exercise 1
// Point.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class point with members x and y
//               privately, and Get()/Set()/ToString() functions publicly.
//               Also declare default constructor and destructor.
// [Modifications]
// 2021-06-21 CC Establish the 1st Version.

#ifndef POINT_H // Avoid the multiply inclusion error.
#define POINT_H

#include <iostream>  // Library contains count/cin.

using namespace std;


class Point
{
private:
	double x; // x-coordinate.
	double y; // y-coordinate.

public:
	// Default Constructors and Destuctor
	Point();
	~Point();

	
	// ********Member Functions********
	// Accessing functions

	double GetX(); 
	// [Description] Getter function for x.
	// [Input] None.
	// [Output] (double) x-coordinates.
	double GetY();
	// [Description] Getter function for y.
	// [Input] None.
	// [Output] (double) y-coordinates.

	//  Modifiers

	void SetX(double x_val); 
	// [Description] Setter function for x.
	// [Input] (double) x-coordinate value.
	// [Output] None.
	void SetY(double y_val);
	// [Description] Setter function for y.
	// [Input] (double) y-coordinate value.
	// [Output] None.

	// Others

	string ToString();
	// [Description] Return string description of the point.
	// [Input] None.
	// [Output] (string) "Point(x, y)".
};


#endif