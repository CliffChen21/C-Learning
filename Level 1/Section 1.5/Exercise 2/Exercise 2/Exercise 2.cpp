// Section 1.5 Exercise 2
// [Author] Cliff Chen
// [Description] Create a function to calculate the factorials. And call it in the main function.

#include <stdio.h>

long long int factorials (long long int n);
// [Description] calculate the factorials for a given number n.
// [Input] n : a nonnegative integer to be calculated.
// [Output] factorials.

void main()
{
	long long int number;
	long long int result = 0;

	printf("Please enter a nonnegative integer here.\n");

	// Read number from the console and check its nonnegativity.
	if (scanf_s("%lld", &number) && number >= 0)
	{
		// Call recursive function.
		result = factorials(number);

		// Check if the calculation result is valid.
		if (result > 0)
		{
			printf("%lld! = %lld\n", number, result);
		}
		else
		{
			printf("Stack Overflow-Result exceeds the maxium data storage.\n");
		}
	}
	else
	{
		printf("Error-there should be a nonnegative integer.\n");
	}
}

long long int factorials(long long int n)
{
	long long int result;

	// 0!=1
	if (n == 0)
	{
		return 1;
	}
	else
	{
		result = factorials(n - 1);

		// Since it should be positive, if negative number appears, raising a 0 exception.
		// Depends on platform, this can also prevent recursive stack overflow on my pc.
		if (result > 0)
		{
			return n * result;
		}
		else
		{
			return 0; // Using zero since zero times any number is zero.
		}
	}
}