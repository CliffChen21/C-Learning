// Section 1.4 Exercise 7
// [Author] Cliff Chen
// [Description] Extension of Exercise 6. 
//               Print number 3 appearing times in words.
// [Description for exercise 6]
//				 Count and print the number of times 0~4 has been typed.
//				 Also typing times of other characters.
//				 Construction : switch-case.
//               Terminated with EOF.

#include <stdio.h>

void main()
{
	char input = NULL; // typed text.
	int num_count[6] = { 0, 0, 0, 0, 0 , 0 }; // counter for each classes.

	printf("Please type characters below and stop with Ctrl^Z (EOF).\n");

	// Halt the input if encounters EOF (Ctrl^Z). And Ctrl^Z (ASCII-value : 26) if Ctrl^Z is not in a new line.
	// For details, referring Avi's post in https://quantnet.com/threads/ctrl-d-and-ctrl-z-issues-1-4.8655/#post-75426.
	while ((input = getchar()) != EOF && input != 26)
	{
		switch (input) // Count the number of times each characters has been typed.
		{
		case '0':
			num_count[0]++;
			break;

		case '1':
			num_count[1]++;
			break;

		case '2':
			num_count[2]++;
			break;

		case '3':
			num_count[3]++;
			break;

		case '4':
			num_count[4]++;
			break;

		default:
			num_count[5]++;
			break;
		}
	}

	// Print the counting results of 0~4.
	for (int i = 0; i < 5; i++)
	{
		printf("Number %d has been typed %d times\n", i, num_count[i]);
	}

	// Print counting result for other characters.
	printf("Other character has been typed %d times\n", num_count[5]);

	// Extension : print the number of appearing times of number 3 in words.
	switch (num_count[3])
	{
	case 0:
		printf("Number three appears zero times.\n");
		break;

	case 1:
		printf("Number three appears one times.\n");
		break;

	case 2:
		printf("Number three appears two times.\n");
		break;

	default:
		printf("The number three appears more than two times.\n");
		break;
	}
}