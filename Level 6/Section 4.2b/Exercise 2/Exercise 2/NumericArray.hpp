// Section 4.2b Exercise 2
// Array.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class NumericArray with:
//                 - Fields : 
//                   1) m_data : store Point array.
//                   2) arr_size : size of array.
//                 - Canonical header.
//                 - Member operator overloadings: = and []
//                 - GetElement() and SetElement
// [Modifications]
// 2021-10-06 CC Establish the 1st Version.

#ifndef NUMERIC_ARRAY_HPP
#define NUMERIC_ARRAY_HPP

#include "Array.hpp"

template <typename T>
class NumericArray : public Array<T>
{
public:
	NumericArray(); // Default constructor.
	NumericArray(int size); // Constructor accepts arguments.
	NumericArray(const NumericArray<T>& source); // Copy constructor.

	virtual ~NumericArray(); // Destructor.

	// Member operator overloading
	NumericArray<T>& operator = (const NumericArray<T>& source);  // Assignment operator
	NumericArray<T> operator + (const NumericArray<T>& source) const; // Add two arraies together.
	NumericArray<T> operator * (const T& factor) const; // Scale the array by a factor.

	// Member functions
	T DotProduct(const NumericArray<T>& b) const; // Calculate the dot product with another array.

};


#endif