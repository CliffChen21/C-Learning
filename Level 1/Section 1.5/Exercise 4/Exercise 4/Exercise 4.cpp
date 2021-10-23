// Section 1.5 Exercise 4
// [Author] Cliff Chen
// [Description] Write a recursive function to print integers digit-by-digit.

#include <stdio.h>

void printnumber(int number);
// [Description] Using putchar() to print an integer digit-by-digit.
// [Input] number : number will be printed.
// [Output] None

void main()
{
	int number;

	// Message to user.
	printf("Please an integer.\n");

	// Read and check the data.
	if (scanf_s("%d", &number))
	{
		// Call printnumber function.
		printnumber(number);
	}
	else
	{
		// Print error message.
		printf("Error-data is not integer.\n");
	}
}

void printnumber(int number)
{
	int rest_number; // number after divides by 10.

	// If number is negative, print a '-' and feed its absolute value to printnumber.
	if (number < 0) 
	{
		putchar('-');
		printnumber(-number);
	}
	else
	{
		// Decimal number is counted in 10.
		if (number >= 10)
		{
			// Divide by 10 to get a smaller part of the number.
			rest_number = number / 10;
			printnumber(rest_number);

			// Print the modulo from the highest digits.
			// It prints reversely  since the first losed case is number < 9.
			putchar(number % 10 + 48);		
		}
		else
		{
			// Print the first digits.
			putchar(number + 48);
		}

	}
}