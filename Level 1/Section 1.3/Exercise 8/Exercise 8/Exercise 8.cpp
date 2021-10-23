// Section 1.3 Exercise 8
// [Author] Cliff Chen
// [Description] Predict the print results with comments.

/* Assignment operators */

#include <stdio.h>

int main()
{
	int x = 2;
	int y;
	int z;

	// x = x * (3 + 2)
	// x=10
	x *= 3 + 2;
	printf("x=%d\n", x);

	// y has defined here since assign operator, =, is evaluate from right to left.
	// and = has higher priority than *=
	// x = x * (y = (z = 4))
	// x=40
	x *= y = z = 4;
	printf("x=%d\n", x);

	// x = (y == z)
	// x=1
	x = y == z;
	printf("x=%d\n", x);

	return 0;
}