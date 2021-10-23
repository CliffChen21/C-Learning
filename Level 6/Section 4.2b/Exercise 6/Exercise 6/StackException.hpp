// Section 4.2b Exercise 5
// StackException.hpp
// [Author] Cliff Chen
// [Description] Header file declares a base class StackException and its derived classes StackEmptyException and StackFullException:
//                 - Fields : m_index
//                 - Canonical header.
//                 - GetMessage() 
// [Modifications]
// 2021-10-10 CC Establish the 1st Version.

#ifndef StackException_HPP
#define StackException_HPP

#include <sstream>
#include <iostream>
using namespace std;

class StackException
{
public:

	StackException()
	{ // Default constructor
	}

	virtual ~StackException()
	{ // Destructor
	}

	virtual string GetMessage() = 0;
};

class StackFullException : public StackException
{
public:
	// Constructors and destructor
	StackFullException() : StackException()
	{ // Default constructor
	}

	~StackFullException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "Stack is full.";

		return stream.str();
	}
};

class StackEmptyException : public StackException
{
public:
	// Constructors and destructor
	StackEmptyException() : StackException()
	{ // Default constructor
	}

	~StackEmptyException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "Stack is empty.";

		return stream.str();
	}
};

#endif