// Section 1.7 Exercise 3
// [Author] Cliff Chen
// [Description] Prediction the output of program. And the answer is,
/*
01234
01234

01234
024

43210
43210
43210
*/

/* Predict what will be printed on the screen */
#include <stdio.h>

#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line
// Create and initialse array
int a[] = { 0, 1, 2, 3, 4 };

int main()
{
	int i;
	int* p;

	for (i = 0; i <= 4; i++) PRD(a[i]); // 1
	NL; // Print with array indexing.

	for (p = &a[0]; p <= &a[4]; p++) PRD(*p); // 2
	NL; // Print with address dereferencing.
	NL;

	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]); // 3
	NL; // Print with address dereferencing. 

	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 4
	NL; // Print (*a), (* (a + 2) ), (* (a + 4) ).
	NL;

	for (p = a + 4; p >= a; p--) PRD(*p); // 5
	NL; // Print using address reversely.
	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]); // 6
	NL; // Print from the tail. (More easy to understand by address).

	for (p = a + 4; p >= a; p--) PRD(a[p - a]); // 7
	NL; // Print with index 4 3 2 1 0.

	return 0;
}