// Section 2.6 Exercise 1
// Array.hpp
// [Author] Cliff Chen
// [Description] Header file declares a class point with:
//                 - Fields : 
//                   1) m_data : store Point array.
//                   2) arr_size : size of array.
//                 - Canonical header.
//                 - Member operator overloadings: = and []
//                 - GetElement() and SetElement
// [Modifications]
// 2021-07-18 CC Establish the 1st Version.
// 2021-07-21 CC Included class into namesapce CHENJIANXIANG::Containers

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "Point.hpp"

using namespace std;

namespace CHENJIANXIANG
{
	namespace Containers
	{
		class Array
		{
		private:
			CAD::Point* m_data; // Dynamic C array of Point objects
			int arr_size; // Size of array

		public:
			// Constructors
			Array(); // Default constructor
			Array(const Array& a); // Copy constructor
			Array(int size); // Constructor with size of array
			~Array(); // Destructor

			// Member operator overloading	
			Array& operator = (const Array& source); // Assignment operator.
			CAD::Point& operator [] (int index);  // read and write elemebt by index.
			const CAD::Point& operator [] (int index) const;  // read elemebt by index.
			// Reason for extra [] operator:
			// Make [] able to read const Point elements in the Array.

			// Accessing functions
			int Size() const;
			CAD::Point& GetElement(int index) const;

			// Modifers
			void SetElement(int index, const CAD::Point& point_val);


		};

	}
}
#endif