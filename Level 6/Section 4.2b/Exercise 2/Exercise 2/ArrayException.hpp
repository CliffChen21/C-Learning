// Section 4.2b Exercise 1
// ArrayException.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class ArrayException
//                 - Fields : None
//                 - Canonical header.
//                 - GetMessage() 
// [Modifications]
// 2021-10-06 CC Establish the 1st Version.

#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <iostream>
using namespace std;

// Base class for Array exception.
// Member function: -GetMessage()
class ArrayException
{
public:
	ArrayException()
	{// Default constructor
	}

	ArrayException(const ArrayException& source)
	{// Copy constructor
	}

	virtual ~ArrayException()
	{// Destructor
	}

	virtual string GetMessage() const = 0; // Message about error.

};
#endif