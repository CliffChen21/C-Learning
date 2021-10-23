// Section 1.3 Exercise 6
// [Author] Cliff Chen
// [Description] right shift input number 2 places.

#include <stdio.h>

void main()
{
	long long int num; // Variable to store input numbers.
	long long int num_right_shifted_2_place; // Variables to store shifted numbers.

	if (scanf_s("%lld", &num))
	{
		// Shift 2 places to right.
		num_right_shifted_2_place = num >> 2;

		// Print shifted number.
		printf("The 2-place right arithmetic shift of %lld is : %lld\n", num, num_right_shifted_2_place);
	}
	else
	{
		// Print an error message if input isn't an integer.
		printf("Error-Invalid Type: Please input an integer.\n");
	}

}