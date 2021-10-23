// Section 1.4 Exercise 6
// [Author] Cliff Chen
// [Description] Count and print the number of times 0~4 has been typed.
//				 Also typing times of other characters.
//				 Construction : switch-case.
//               Terminated with EOF.

#include <stdio.h>

void main()
{
	char input = NULL; // typed text.
	int num_count[6] = {0, 0, 0, 0, 0 , 0}; // counter for each classes.

	printf("Please type characters below and stop with Ctrl^Z (EOF).\n");

	// Halt the input if encounters EOF (Ctrl^Z). And Ctrl^Z (ASCII-value : 26) if Ctrl^Z is not in a new line.
	// For details, referring Avi's post in https://quantnet.com/threads/ctrl-d-and-ctrl-z-issues-1-4.8655/#post-75426.
	while ((input = getchar()) != EOF && input!= 26)
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
		printf("%d has been typed %d times\n", i, num_count[i]);
	}

	// Print counting result for other characters.
	printf("Other character has been typed %d times\n", num_count[5]);
}