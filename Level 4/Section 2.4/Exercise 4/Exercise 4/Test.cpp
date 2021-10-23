// Section 2.4 Exercise 4
// Test.cpp
// [Author] Cliff Chen
// [Description] Test operators in class Point/Line/Circle in Point.hpp/Line.hpp/Circle.hpp.
// [Modifications]
// 2021-07-11 CC established the 1st version.
// 2021-07-18 CC Adapt test program for << operator function of Point, Line and Circle.
//			  CC Delete the tests for Circle.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Line.hpp"  // Class Line is declared in Line.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	// Test Point operators -, *, +, ==, =, *=
	
	Point p1(1.0, -1.0); // Create two test points p1.
	Point p2(10.0, -10.0); // Create two test points p2.
	cout << "p1 = " << p1 << " and p2 = " << p2 << " created." << endl;

	// - Test - operator
	cout << "-p1 = " << (-p1) << endl;

	// - Test * operator
	double factor = -10.0;
	cout << p1 << " * (" << factor << ")" << " = " << (p1 * factor) << endl;

	// - Test + operator
	cout << p1 << " + " << p2 << " = " << (p1 + p2) << endl;

	// - Test == operator
	factor = 10.0; // change factor value.
	cout << boolalpha; // enable to print true or false rather than 1 or 0.
	cout << p1 << " == " << p2 << " : " << (p1 == p2) << endl;
	cout << (p1 * factor ) << " == " << p2 << " : " << ((p1 * factor) == p2) << endl;

	// - Test = operator
	Point p3 = p2;
	cout << "p3 = " << p3 << " (after p3=p2)" << endl;
	p3 = p2 = p1;
	cout << "p3 = " << p3 << " (after p3=p2=p1)" << endl;

	// - Test =* operator
	p3 *= factor;
	cout << "p3 =  " << p3 << " (after p3 *= " << factor << ")" << endl;
	cout << endl;

	// Test Line

	// - Test = operator
	Line l1(p1, p3); // Create test line.
	cout << "Create Line : l1 = " << l1 << endl;

	Line l2 = l1; // Assign l1 to l2.	
	cout << "l2 = " << l2 << " (after l2 = l1)" << endl;
	cout << endl;

}


