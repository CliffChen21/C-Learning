// Section 1.5 Exercise 1
// [Author] Cliff Chen
// [Description] Create a function minus to compute the difference between 
//				 two numbers. And call it in the main function.

#include <stdio.h>

double minus(double x, double y);
// [Description] calculate the difference between x and y.
// [Input] x : any real number with limited precision.
//         y : any real number with limited precision.
// [Output] x - y.

void main()
{
	double first_num; // First number to calculate.
	double second_num; // Second number to calculate.

	printf("Please enter two double-floating numbers.\n");

	// Read number from console and check if the data type is valid.
	if (scanf_s("%lf %lf", &first_num, &second_num))
	{
		printf("%lf - %lf = %lf\n", first_num, second_num, minus(first_num, second_num));
	}
	else
	{
		// Type Error. There should be two double-type data separated by whitespace.
		printf("Error-Please input a valid number.\n");
	}
}

double minus(double x, double y)
{
	return x - y;
}