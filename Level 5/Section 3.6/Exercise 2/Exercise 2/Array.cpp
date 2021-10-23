// Section 2.5 Exercise 3
// Array.cpp
// [Author] Cliff Chen
// [Description] Source file contains implementation of Array class in Array.hpp
// [Modifications]
// 2021-07-18 CC Establish the 1st Version.

#include "Point.hpp"
#include "Array.hpp"
#include "OutOfBoundsException.hpp"

using namespace std;


// Default constructor and destructor
Array::Array() : m_data(new Point[10]), arr_size(10)
{
	// Default constructor should initialize everything.
}

// Copy constructor.
Array::Array(const Array& arr)
{
	m_data = new Point[arr.arr_size]; // Allocate a new C array.
	arr_size = arr.arr_size;

	// Copy each Array objects separately.
	for (int i = 0; i < arr_size; i++)
	{
		m_data[i] = arr.m_data[i];
	}
}

// Constructor accepts array size.
Array::Array(int size) : m_data(new Point[size]), arr_size(size) // colon syntax.
{
}

// Default destructor.
Array::~Array()
{
	// Destructor will be automatically called by the system when object is out-of-scope.
	delete[] m_data; // Manually delete the m_data
}

// Member operator overloadings

// - Assignment operator
Array& Array::operator= (const Array& source)
{
	if (&source != this)
	{
	// Check if recursive assignment on the same array.
		delete[] m_data; // Release the memory of old m_data.

		m_data = new Point[source.arr_size]; // Create a new array with same size as source
		arr_size = source.arr_size;

		// Assign each Array objects separately.
		for (int i = 0; i < arr_size; i++)
		{
			m_data[i] = source.m_data[i];
		}
	}

	return *this;
}

// - Square operator.
Point& Array::operator [](int index)
{
	if (index < 0 || index >= arr_size)
	{
		throw OutOfBoundsException(index); // Throw error
	}
	else
	{
		return m_data[index];
	}
}

// - Const square operator.
const Point& Array::operator [](int index) const
{
	if (index < 0 || index >= arr_size)
	{
		throw  OutOfBoundsException(index); // Throw error
	}
	else
	{
		return m_data[index];
	}
	// Reason for extra [] operator:
	// Make [] able to read const Point elements in the Array.
}

// Accessing functions

// - Get the value of array size.
int Array::Size() const
{

	return arr_size;
}

// - Get the value of elements.
Point& Array::GetElement(int index) const
{
	if (index < 0 || index >= arr_size)
	{
		throw  OutOfBoundsException(index); // Throw error
	}
	
	return m_data[index];
}

// Modifiers

// - Set x-coordinate.
void Array::SetElement(int index, const Point& point_val)
{
	if (index < 0 || index >= arr_size)
	{
		throw  OutOfBoundsException(index); // Throw error
	}

	m_data[index] = point_val;
	
}

