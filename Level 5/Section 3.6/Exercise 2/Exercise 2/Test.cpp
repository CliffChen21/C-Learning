// Section 3.6 Exercise 1
// Test.cpp
// [Author] Cliff Chen
// [Description] Test Array class with exception handling.
// [Modifications]
// 2021-10-06  CC established the 1st version.

// Include the point header file.
#include "Point.hpp" // Class Point is declared in Point.hpp.
#include "Array.hpp" // Class Array is declared in Array.hpp
#include "OutOfBoundsException.hpp"

#include <iostream> // string class is defined here but << and >> not. 
#include <string>   // << and >> is defined in string.

using namespace std; // Standard namespace. (New standard).

void main()
{
	Array array(0);
	// if access an element out of bound, there would be an unhandled exception.

	try
	{
		cout << array[-1] << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl; // print an error message

	}

	try
	{
		cout << array[1] << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl; // print an error message

	}
}