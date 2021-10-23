// Section 1.7 Exercise 4
// [Author] Cliff Chen
// [Description] Create a function DayName().
//				 It will return the name of day with given day-number.

#include <stdio.h>

void DayName(int day_number);
// [Description] Print the day name of given number in a week.
// [Input] day_number : integer between 1~7.
// [Output] None.

void main()
{
	int day_number; // Number of day in a week.

	// Print the input guide.
	printf("Please input a number between 1 and 7.\n");

	// Read number from console. Validate the input.
	if (scanf_s("\%d", &day_number) && (day_number >= 1 && day_number <= 7))
	{
		// Call DayName to print the day name for the given number.
		DayName(day_number);
	}
	else
	{
		// Error message.
		printf("Error-Input is wrong. Please type a integer within [1, 7].\n");
	}
}

void DayName(int day_number)
{
	// Define an array of strings for day name. Second dimension is 10 because max length of string with /0 is 10.
	char day_names[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
							"Saturday" }; 

	printf("Day %d is a %s.\n", day_number, day_names[day_number - 1]); // -1 since array starts from 0.
}