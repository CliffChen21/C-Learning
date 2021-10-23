// Section 1.6 Exercise 1 : Macro.c
// [Author] Cliff Chen
// [Description] Read a, b from console and use macros in Defs.h to print them.
//               PRINT1 : print a.
//			     PRINT2 : print a and b.
#include <stdio.h>
#include "Defs.h"

void main()
{
	char a;
	char b;

	// Ask the user to input a and b.
	printf("Input variable a, b and separated by space.\n");

	// Read and check input.
	if (scanf_s(" %c", &a) && scanf_s(" %c", &b))
	{
		// Print variable a.
		PRINT1(a);

		// Print variable a and b.
		PRINT2(a, b);
	}
	else
	{
		// Print error message.
		printf("Input Error.\n");
	}
}