// Section 1.8 Exercise 1
// [Author] Cliff Chen
// [Description] Create a struct Article with 3 fields:
//				 * Article number
//				 * Quantity
//				 * Description

#include <stdio.h>

struct Article
{
	int article_num; // Article number.
	int quantity; // Quantity.
	char description[21]; // Description of max 20 characters.
};

void Print(struct Article* pointer);
// [Description] Print the fields of Article.
// [Input] pinter : address of an Article instance.
// [Output] None

void main()
{
	// Initialization and assignment.
	struct Article article = {1, 5, "The first article."}; // Don't forget keyword struct.
	
	// Print the value of an Article instance.
	Print(&article);
}

void Print(struct Article* pointer) // Attention : it is call by reference.
{
	// pointer->filename methods to get characteristics value and print.
	printf("Article number : %d\n", pointer->article_num);
	printf("Quantity : %d\n", pointer->quantity);
	printf("Description : %s", pointer->description);
}