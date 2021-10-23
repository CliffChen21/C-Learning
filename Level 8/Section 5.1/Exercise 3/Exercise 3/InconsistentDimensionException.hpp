// Section 4.2b Exercise 2
// ArrayException.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class InconsistentDimensionException
//                 - Fields : m_index
//                 - Canonical header.
//                 - GetMessage() 
// [Modifications]
// 2021-10-06 CC Establish the 1st Version.

#ifndef InConsistentDimentionException_HPP
#define InConsistentDimentionException_HPP

#include "ArrayException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

// Derived class from ArrayException
class InconsistentDimensionException : public ArrayException
{
public:
	InconsistentDimensionException() : ArrayException()
	{// Default constructor
	}

	InconsistentDimensionException(const InconsistentDimensionException& source) : ArrayException(source)
	{// Copy constructor
	}

	virtual ~InconsistentDimensionException()
	{// Destructor
	}

	string GetMessage() const
	{
		// Message about error.
		stringstream stream;

		stream << "The dimension of two arraies is inconsistent.";

		return stream.str();
	}
};


#endif