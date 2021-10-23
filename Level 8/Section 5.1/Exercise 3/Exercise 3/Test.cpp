// Section 5.1 Exercise 3
// Test.cpp
// [Author] Cliff Chen
// [Description] Test variant in Boost.
// [Modifications]
// 2021-10-10  CC established the 1st version.


#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.cpp"
#include "Visitor.hpp"
#include <iostream>

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType CreateShape()
{


	cout << "Select a shape: Point, Line, Circle." << endl;
	string selection;
	cin >> selection;

	// Return the selected shape.
	if (selection == "Point")
	{
		return Point();
	}
	else if (selection == "Line")
	{
		return Line();
	}
	else if (selection == "Circle")
	{
		return Circle();
	}
	else
	{
		return ShapeType();
	}
}

void main()
{
	// Test CreateShape function.
	ShapeType s = CreateShape();
	cout << s << endl;

	// If shape doesn't contain line, it would return an exception.
	try
	{
		Line l = boost::get<Line>(s);
	}
	catch (boost::bad_get& ex)
	{
		cout << ex.what() << endl;
	}

	// Test visitor.
	Visitor visitor(1.0, 1.0);
	boost::apply_visitor(visitor, s);
	cout << s << endl;
}