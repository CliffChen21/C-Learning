// Section 1.9 Exercise 1
// [Author] Cliff Chen
// [Description] The program read characters from the keyboard 
//	             and display them line by line.
//				 Stop with Ctrl^A.

#include <stdio.h>			

int main()
{
	int input;

	// Input guide.
	printf("Input characters here.\nHit 'enter' to show.\nExit with Ctrl^A\n");

	// Read characters using buffer function. Stop with Ctrl^A/ Ctrl + Shift^A.
	while ((input = getchar()) != 1) { // Ctrl^A (ASCII-value : 1).
		// Print the characters when user hits the 'enter'.
		putchar(input);  
	}

	// Exit message.
	printf("CTRL + A is a correct ending.\n");  

	return 0;
}