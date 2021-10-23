// Section 1.5 Exercise 3
// [Author] Cliff Chen
// [Description] Call print in Print.c
//               And print is used to multiply a number by 2 and print it.

#include <stdio.h>
#include "Print.h"

void main()
{
	double i; // Used to feed value to print.

	printf("Please input a number.\n"); // Message to user.

	// Read and check the data.
	if (scanf_s("%lf", &i))
	{
		// print i * 2.
		print(i);
	}
	else
	{
		// Error message of input data is not valid.
		printf("Error-Please input a double-floating number.\n");
	}
}