// Section 1.3 Exercise 4
// [Author] Cliff Chen
// [Description] Using marriage status survey to test the integer True/False-intepretation in C.

#include <stdio.h>

void main() 
{
	int married;

	// Query user married or not. married(0)/unmarried(1).
	printf("Are you married? (Please 1 for married and 0 for unmarried)\n");

	// Retrieve validate the inputs (int ?, within 0/1 ?).
	if (scanf_s("%d", &married) && (married == 0 || married == 1))
	{
		// Print marriage status.
		// 'You're married.\n' if married == 1.
		// 'You're unmarried.\n' if married == 0.
		printf(married ? "You're married.\n" : "You aren't married.\n");
	}
	else
	{
		// Print an error if input is invalid.
		printf("Error-Invalid input: Please input an integer in {0, 1}.");
	}
}
