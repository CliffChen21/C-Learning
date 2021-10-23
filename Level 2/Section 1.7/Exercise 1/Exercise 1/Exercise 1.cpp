// Section 1.7 Exercise 1
// [Author] Cliff Chen
// [Description] The program will 
//               exchange the value of two variables using pointers.

#include<stdio.h>

void Swap(int* i_pointer, int* j_pointer);
// [Description] exchange the values stored at two pointers, i_pointer, j_pointer.
// [Input] i_pointer : the pointer (address) of integer i.
//         j_pointer : the pointer (address) of integer j.
// [Ouput] None.

void main()
{
	int i; // Number to be exchanged.
	int j; // Number to be exchanged.

	// Print input guide.
	printf("Please input two integer i and j, sepqrated by space.\n");
	
	// Read value of i and j from console, and check their type.
	if (scanf_s("%d", &i) && scanf_s("%d", &j))
	{
		// Print the value of i, j before swap.
		printf("Before swap : i=%d, j=%d\n", i, j);

		// Exchange i and j.
		Swap(&i, &j);

		// Print the value of i, j after swap.
		printf("After swap : i=%d, j=%d\n", i, j);
	}
	else
	{
		// Error message.
		printf("Error-i and j should be integers.\n");
	}
	
}

void Swap(int* i_pointer, int* j_pointer)
{
	int tmp = (*i_pointer); // Declare and get the value stored in i_pointer and assign to tmp.
	(*i_pointer) = (*j_pointer); // Assign the value at j_pointer to i_pointer.
	(*j_pointer) = tmp; // Assign value of tmp to j_pointer.
}