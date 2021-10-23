// Section 4.2b Exercise 2
// Array.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class Array with:
//                 - Fields : 
//                   1) m_data : store Point array.
//                   2) arr_size : size of array.
//                 - Canonical header.
//                 - Member operator overloadings: = and []
//                 - GetElement() and SetElement
// [Modifications]
// 2021-10-06 CC Establish the 1st Version.

#ifndef Array_HPP
#define Array_HPP

template <typename T>
class Array
{
private:
	T* m_data; // Dynamic C array of Point objects
	int arr_size; // Size of array

public:
	// Constructors
	Array(); // Default constructor
	Array(const Array<T>& a); // Copy constructor
	Array(int size); // Constructor with size of array
	virtual ~Array(); // Destructor

	// Member operator overloading	
	Array<T>& operator = (const Array<T>& source); // Assignment operator.
	T& operator [] (int index);  // read and write elemebt by index.
	const T& operator [] (int index) const;  // read elemebt by index.
	// Reason for extra [] operator:
	// Make [] able to read const Point elements in the Array.

	// Accessing functions
	int Size() const;
	T& GetElement(int index) const;

	// Modifers
	void SetElement(int index, const T& T_val);
};

#endif