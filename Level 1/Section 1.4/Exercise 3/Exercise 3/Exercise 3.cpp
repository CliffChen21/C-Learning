// Section 1.4 Exercise 3
// [Author] Cliff Chen
// [Description] Read text from keyboard and print:
//					1. Amount of characters.
//					2. Amount of words.
//					3. Amount of is_newlines.
//				, multiply consecutive spaces shouldn't count as multiple words.
//				Please use switch instead of if-else.
#include <stdio.h>

void main()
{
	int input = NULL; // input character in ASCII-value.
	int num_characters = 0; // number of characters input.
	int num_words = 0; // number of words input.
	int num_lines = 0; // number of lines input.
	bool is_character = false; // assign true if current input is character except special characters. 
	bool is_newline = false; // assign true if there is a '\n'

	printf("Please type text below. Stop with Ctrl^D.\n");

	// Stop the input. Ctrl^D(ASCII-value : 4), Ctrl^Z(ASCII-value : 26), EOF (ASCII-value : -1)
	while ((input = getchar()) != 4 && input != 26 && input != EOF)
	{
		// All ASCII-value except Ctrl^D, Ctrl^Z and EOF should be counted as a character.
		num_characters++; 

		switch (is_newline)
		{
			case true:
				num_lines++;

				is_newline = false;
				break;

			default:
				break;
		}

		switch (input) 
		{
			case 32: 
			// whitespace(ASCII-value : 32)
				switch (is_character)
				{
					case true:
					// If a whitespace is preceded by a normal character, counted as a word.
						num_words++;
						break;

					default:
						break;
				}

				is_character = false;
				break;

			case 10: 
			// new line(ASCII-value : 10)
				switch (is_character)
				{
					case true:
					// If a new line is preceded by a normal character, counted as a word.
						num_words++;
						break;

					default:
						break;
				}

				is_character = false;
				is_newline = true;
				break;

			default:				
				is_character = true;
				break;
		}

	}

	// In the end of input, a last consecutive combination of normal characters should be counted as a word.
	switch (is_character)
	{
		case true:
			num_words++;
			break;

		default:
			break;
	}

	// If only one line.
	switch (num_characters != 0 || is_newline)
	{
	case true:
		num_lines++;
		break;

	default:
		break;
	}

	printf("The number of characters is %d.\nThe number of words is      %d.\nThe number of new lines is  %d.\n",
		num_characters, num_words, num_lines);
}

/*
Test Case From Forum:
Case 1
	Input
	-----
	a bb c
	 ^D

	Output
	------
	8 3 2

Case 2
	Input
	-----
	a bb c

	aaa^D

	Output
	------
	11 4 3

Case 3
	Input
	-----
	aaa
	bbb^D

	Output
	------
	7 2 2

Case 4
	Input
	-----
	^D

	Output
	------
	0 0 0

Case 5
	Input
	-----

	^D

	Output
	------
	1 0 1

Case 6
	Input
	-----
	1111


	111
	^D

	Output
	------
	11 2 4

Case 7
	Input
	-----
	1111


	111^D


	Output
	------
	10 2 4
*/