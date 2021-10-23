// Section 5.1 Exercise 1
// Test.cpp
// [Author] Cliff Chen
// [Description] Test shared pointer in Boost.
// [Modifications]
// 2021-10-10  CC established the 1st version.


#include <boost\shared_ptr.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.cpp"
#include <iostream>

void main()
{
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	const int size = 3;

	ShapePtr sh_ptr1(new Point(1.0, -1.0)); // boost::shared_ptr<Shape>
	ShapePtr sh_ptr2(new Line(Point(0.0, 0.0), Point(1.0, 0.0))); // boost::shared_ptr<Shape>
	ShapePtr sh_ptr3(new Circle(Point(0.0, 0.0), 1.0)); // boost::shared_ptr<Shape>

	{
		ShapeArray shape_array(size); // Array<ShapePtr>

		shape_array[0] = sh_ptr1;
		shape_array[1] = sh_ptr2;
		shape_array[2] = sh_ptr3;

		// Print the shapes.
		for (int i = 0; i < size; i++)
		{
			cout << shape_array[i]->ToString() << endl;
		}

		cout << "The number of first shape pointer: " << sh_ptr1.use_count() << endl;
		cout << "The number of second shape pointer: " << sh_ptr2.use_count() << endl;
		cout << "The number of third shape pointer: " << sh_ptr3.use_count() << endl;
	}

	// Smart pointers are auto-deleted.
	cout << sh_ptr1.use_count() << endl;
	cout << sh_ptr2.use_count() << endl;
	cout << sh_ptr3.use_count() << endl;
}