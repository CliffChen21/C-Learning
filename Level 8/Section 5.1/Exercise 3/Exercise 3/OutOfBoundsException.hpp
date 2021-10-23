// Section 4.2b Exercise 1
// ArrayException.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class OutOfBoundsException
//                 - Fields : m_index
//                 - Canonical header.
//                 - GetMessage() 
// [Modifications]
// 2021-10-06 CC Establish the 1st Version.

#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

#include "ArrayException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

// Derived class from ArrayException
class OutOfBoundsException : public ArrayException
{
private:
	int m_index; // erroneous array index

public:
	OutOfBoundsException() : ArrayException()
	{// Default constructor
	}
	OutOfBoundsException(int index) : m_index(index)
	{// Constructor accepts index.
	}
	OutOfBoundsException(const OutOfBoundsException& source) : ArrayException(source), m_index(source.m_index)
	{// Copy constructor
	}

	virtual ~OutOfBoundsException()
	{// Destructor
	}

	string GetMessage() const
	{
		// Message about error.
		stringstream stream;

		stream << "Index " << m_index << " is out of bound.";

		return stream.str();
	}
};


#endif