// Section 2.5 Exercise 3
// Array.cpp
// [Author] Cliff Chen
// [Description] Source file contains implementation of Array class in Array.hpp
// [Modifications]
// 2021-07-18 CC Establish the 1st Version.

#ifndef Array_cpp
#define Array_cpp

#include "Array.hpp"
#include "OutOfBoundsException.hpp"

using namespace std;

// Initialize static variable.
template <typename T>
int Array<T>::static_size = 3;

// Default constructor and destructor.
template <typename T>
Array<T>::Array() : m_data(new T[static_size]), arr_size(static_size)
{
	// Default constructor should initialize everything.
}

// Copy constructor.
template <typename T>
Array<T>::Array(const Array<T>& arr)
{
	m_data = new T[arr.arr_size]; // Allocate a new C array.
	arr_size = arr.arr_size;

	// Copy each Array objects separately.
	for (int i = 0; i < arr_size; i++)
	{
		m_data[i] = arr.m_data[i];
	}
}

// Constructor accepts array size.
template <typename T>
Array<T>::Array(int size) : m_data(new T[size]), arr_size(size) // colon syntax.
{
}

// Default destructor.
template <typename T>
Array<T>::~Array()
{
	// Destructor will be automatically called by the system when object is out-of-scope.
	delete[] m_data; // Manually delete the m_data
}

// Member operator overloadings

// - Assignment operator
template <typename T>
Array<T>& Array<T>::operator= (const Array<T>& source)
{
	if (&source != this)
	{
	// Check if recursive assignment on the same array.
		delete[] m_data; // Release the memory of old m_data.

		m_data = new T[source.arr_size]; // Create a new array with same size as source
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
template <typename T>
T& Array<T>::operator [](int index)
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
template <typename T>
const T& Array<T>::operator [](int index) const
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
	// Make [] able to read const T elements in the Array.
}

// Accessing functions

// - Get the value of array size.
template <typename T>
int Array<T>::Size() const
{

	return arr_size;
}

// - Get the value of elements.
template <typename T>
T& Array<T>::GetElement(int index) const
{
	if (index < 0 || index >= arr_size)
	{
		throw  OutOfBoundsException(index); // Throw error
	}
	
	return m_data[index];
}

template <typename T>
int Array<T>::DefaultSize()
{
	return static_size;
}

// Modifiers

// - Set x-coordinate.
template <typename T>
void Array<T>::SetElement(int index, const T& T_val)
{
	if (index < 0 || index >= arr_size)
	{
		throw  OutOfBoundsException(index); // Throw error
	}

	m_data[index] = T_val;
	
}


template <typename T>
void Array<T>::DefaultSize(int size)
{
	static_size = size;
}


#endif