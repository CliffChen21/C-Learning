// Section 1.3 Exercise 5
// [Author] Cliff Chen
// [Description] show difference b/w --i and i--

#include <stdio.h>

void main()
{
	int i = 0; // declare and define integer i mentionned in the question.
	
	printf("This scripts will show the difference between --i and i--.\n\n");
	// Print initial value of i, should be i=0.
	printf("i=%d\n", i);
	// Print value of --i, should be --i=-1.
	printf("--i=%d\n", --i);
	//Print value of i after --i, should i=-1.
	printf("i=%d (after)\n\n", i);

	// Reset i to 0.
	i = 0;
	// Print initial value of i, should be i=0.
	printf("i=%d\n", i);
	//Print value of i--, should be i=0.
	printf("i--=%d\n", i--);
	// Print value of i after i--, should be i=-1
	printf("i=%d (after)\n\n", i);

	// Summary
	printf("i-- would create a temporal variable for i and i-- returns initial value 0.\n");
	printf("However, since the priority of ++/-- is higher than =, --i would add 1 to i and then assign the updated i, which --i returns -1.\n");
	printf("In summary, --i is more recommended because of performance reason.\n");
}
