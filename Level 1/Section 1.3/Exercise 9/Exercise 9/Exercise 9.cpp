// Section 1.3 Exercise 9
// [Author] Cliff Chen
// [Description] Predict the print results with comments.

#include <stdio.h>

/* Conditional expressions */

#include <stdio.h>

int main()
{
	int x = 1;
	int y = 1;
	int z = 1;

	/*
	3

	2
	3
	3
	*/
	x += y += x; // x += (y += x)
	printf("%d\n\n", (x < y) ? y : x);      // Number 1
	printf("%d\n", (x < y) ? x++ : y++);    // Number 2
	printf("%d\n", x);                      // Number 3
	printf("%d\n", y);                      // Number 4

	return 0;
}