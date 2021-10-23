// Section 1.9 Exercise 2
// [Author] Cliff Chen
// [Description] The program read characters from the keyboard
//	             and write them into a file line by line.
//				 Stop with Ctrl^A.

#define _CRT_SECURE_NO_WARNINGS //Since scanf, fopen is deprecated in C++
#define MAX_PATH_LEN 100 // Max file path length.

#include <stdio.h>

void main()
{
	FILE* fp;  // File handlers.
	char file_path[MAX_PATH_LEN + 1]; // File path.
	int input; // Input text.

	// Print User message.
	printf("Please input the file path you want to output. (Max path length : %d)\n", MAX_PATH_LEN);
	
	// Read the file path.
	scanf("%s", file_path);

	// Create and open file.
	fp = fopen(file_path, "w");

	// Ask user to input.
	printf("\nInput characters here.\nHit 'enter' to show.\nExit with Ctrl^A\n");

	// Read characters using buffer function. Stop with Ctrl^A/ Ctrl + Shift^A.
	while ((input = getchar()) != 1) { // Ctrl^A (ASCII-value : 1).
			
		// Write the characters when user hits the 'enter'.
		fputc(input, fp);  
	}

	// Exit message.
	printf("CTRL + A is a correct ending.\n");

	// Close the file.
	fclose(fp);  

}