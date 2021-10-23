// Section 2.3 Exercise 5
// Line.cpp
// [Author] Cliff Chen
// [Description] Test Program for class Line in Line.hpp and Line.cpp.
// [Modifications]
// 2021-06-26 CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Line.hpp"  // Class Line is declared in Line.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	double x_start;
	double y_start;
	double x_end;
	double y_end;

	// Ask user to input start-point
	cout << "Please input the x- and y- coordinates for start-point. (format : x y)" << endl;
	// Read x y to buffer.
	cin >> x_start >> y_start;

	// Create start point p1.
	Point p1(x_start, y_start); //start-point.
	
	// Print start point.
	cout << "start-point : " << p1.ToString() << endl;


	// Ask user to input end-point
	cout << "Please input the x- and y- coordinates for end-point. (format : x y)" << endl;
	// Read x y to buffer.
	cin >> x_end >> y_end;

	// Create end point p2.
	Point p2(x_end, y_end); // end-point.

	// Print end point.
	cout << "end-point : " << p2.ToString() << endl;

	Line line(p1, p2); // Line objects

	// Print line description.
	cout << endl << "You created a line! " << line.ToString() << "." << endl;
	// Print the length.
	cout << "The length of the line is " << line.Length() << "." << endl;

}


