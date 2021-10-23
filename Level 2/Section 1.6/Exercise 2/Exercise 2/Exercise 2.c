// Section 1.6 Exercise 2
// [Author] Cliff Chen
// [Description] Read x, y, z to test two marcos

#include<stdio.h>
#include"Defs.h" // User-defined header to define macros.

int main()
{
	// data to be compared.
	double x;
	double y;
	double z;

	// Print the program description and manual.
	printf("The program will print the max(x, y) and max(x, y, z).\n\n");
	printf("Please input x y z (numbers, separeted by space).\n");

	// Read and check the input data.
	if (scanf_s("%lf %lf %lf", &x, &y, &z))
	{
		// Print the max number between x and y.
		printf("MAX2(%.3lf, %.3lf) = %.3lf\n", x, y, MAX2(x, y));
		// Print the max number among x, y, z using macro.
		printf("MAX3(%.3lf, %.3lf, %.3lf) = %.3lf\n", x, y, z, MAX3(x, y, z));
	}
	else
	{
		// Print error message.
		printf("Error-There should be 3 numbers x, y, z inputed.\n");
	}
}