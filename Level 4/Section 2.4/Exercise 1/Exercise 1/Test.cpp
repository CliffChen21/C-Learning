// Section 2.4 Exercise 1
// Test.cpp
// [Author] Cliff Chen
// [Description] Test operators in class Point/Line/Circle in Point.hpp/Line.hpp/Circle.hpp.
// [Modifications]
// 2021-07-11 CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Line.hpp"  // Class Line is declared in Line.hpp.
#include "Circle.hpp" // Class Circle is declared in Circle.hpp.

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	// Test Point operators -, *, +, ==, =, *=
	
	Point p1(1.0, -1.0); // Create two test points p1.
	Point p2(10.0, -10.0); // Create two test points p2.
	cout << "p1 = " << p1.ToString() << " and p2 = " << p2.ToString() << " created." << endl;

	// - Test - operator
	cout << "-p1 = " << (-p1).ToString() << endl;

	// - Test * operator
	double factor = -10.0;
	cout << p1.ToString() << " * (" << factor << ")" << " = " << (p1 * factor).ToString() << endl;

	// - Test + operator
	cout << p1.ToString() << " + " << p2.ToString() << " = " << (p1 + p2).ToString() << endl;

	// - Test == operator
	factor = 10.0; // change factor value.
	cout << boolalpha; // enable to print true or false rather than 1 or 0.
	cout << p1.ToString() << " == " << p2.ToString() << " : " << (p1 == p2) << endl;
	cout << (p1 * factor ).ToString() << " == " << p2.ToString() << " : " << ((p1 * factor) == p2) << endl;

	// - Test = operator
	Point p3 = p2;
	cout << "p3 = " << p3.ToString() << " (after p3=p2)" << endl;
	p3 = p2 = p1;
	cout << "p3 = " << p3.ToString() << " (after p3=p2=p1)" << endl;

	// - Test =* operator
	p3 *= factor;
	cout << "p3 =  " << p3.ToString() << "(after p3 *= " << factor << ")" << endl;
	cout << endl;

	// Test Line

	// - Test = operator
	Line l1(p1, p3); // Create test line.
	cout << "Create Line : l1 = " << l1.ToString() << endl;

	Line l2 = l1; // Assign l1 to l2.	
	cout << "l2 = " << l2.ToString() << " (after l2 = l1)" << endl;
	cout << endl;

	// Test Circle

	// - Test = operator
	double r1 = 5.0; // Declare redius for testing Circle.
	Circle c1(p1, r1); // Create testing circle.
	cout << "Create Circle : c1 = " << c1.ToString() << endl;

	Circle c2 = c1; // Assign c1 to c2
	cout << "c2 = " << c2.ToString() << " (after c2 = c1)" << endl;

}


