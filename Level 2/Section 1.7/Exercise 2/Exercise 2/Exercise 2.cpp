// Section 1.7 Exercise 2
// [Author] Cliff Chen
// [Description] Complete the function Length().
//				 Length() would return the length of the string.

/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30
// String lenght declaration

int Length(char str[]);
// [Description] Coun the length of str.
// [Input] str : the address of the string.
// [Output] integer number of characters in str.

int main()
{
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
	int c; // The input character
	int i = 0; // The counter

	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c; // Type casting.
	}

	string[i] = '\0'; // String must be closed with \0

	printf("String length is %d\n", Length(string));

	return 0;
}

/* Implement the Length() function here */
int Length(char str[])
{
	int length = 0; // The length of string.

	// Continue read the str until '\0'.
	while (str[length] != '\0')
	{
		length++; // Increase length by 1 if not end('\0').
	}

	return length;
}
