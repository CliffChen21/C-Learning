// Section 4.2b Exercise 2
// Array.cpp
// [Author] Cliff Chen
// [Description] Source file contains implementation of Array class in NumericArray.hpp
// [Modifications]
// 2021-10-06 CC Establish the 1st Version.

#ifndef NumericArray_CPP
#define NumericArray_CPP


#include "NumericArray.hpp"
#include "InconsistentDimensionException.hpp"

template <typename T>
NumericArray<T>::NumericArray() : Array<T>()
{ // Default constructor.
}

template <typename T>
NumericArray<T>::NumericArray(int size) : Array<T>(size)
{// Constructor accepts arguments.
}

template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source)
{ // Copy constructor.
}

template <typename T>
NumericArray<T>::~NumericArray()
{ // Destructor
}

template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
{
	// Check to make sure not assigning to myself
	if (this == &source) return *this;
	else
	{
		// Call base class assignment operator
		Array<T>::operator = (source);
	}
	return *this;  // Return reference, NOT a copy of the object
}

template <typename T>
NumericArray<T> NumericArray<T>::operator * (const T& factor) const
{
	NumericArray<T> num_array(*this);

	for (int i = 0; i < num_array.Size(); i++)
	{
		num_array[i] *= factor;
	}

	return num_array;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& b) const
{
	if (Array<T>::Size() != b.Size())
	{
		throw InconsistentDimensionException();
	}

	NumericArray<T> result(*this);

	for (int i = 0; i < result.Size(); i++)
	{
		result[i] += b[i];
	}

	return result;
}


template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& b) const
{ // Calculate dot product.

	if (Array<T>::Size() != b.Size())
	{
		throw InconsistentDimensionException();
	}

	T result(0);

	for (int i = 0; i < Array<T>::Size(); i++)
	{
		result += (Array<T>::operator [] (i) * b[i]);
	}

	return result;
}

#endif