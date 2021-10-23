// Section 2.5 Exercise 3
// Test.cpp
// [Author] Cliff Chen
// [Description] Test namespace
// [Modifications]
// 2021-07-18  CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Line.hpp" // Class Line is declared in Line.hpp.
#include "Circle.hpp" // Class Circle is declared in Circle.hpp.
#include "Array.hpp" // Class Array is declared in Array.hpp

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	// Full name for Point class
	CHENJIANXIANG::CAD::Point p1(0.0, 0.0);
	CHENJIANXIANG::CAD::Point p2(1.0, 0.0);

	// Using declaration for using a single class
	using CHENJIANXIANG::CAD::Line;
	Line l1(p1, p2);

	// using declaration for a complete namesapce Containers
	using namespace CHENJIANXIANG::Containers;
	Array a1(1);
	a1[0] = p1;

	// Using the Circle class by create a shorter alias for the YourName::CAD namesapce
	namespace CjxCAD = CHENJIANXIANG::CAD;
	using namespace CjxCAD;

	CjxCAD::Circle c1(p1, 1.0);

	// Output results
	cout << p1 << " " << p2 << endl;
	cout << l1 << endl;
	cout << c1 << endl;
	cout << a1[0] << endl;

}


