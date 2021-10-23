// Section 1.3 Exercise 2
// [Author] Cliff Chen
// [Description] Calculate the surface of the orthogonal triangle 
//				 given base and height.

#include <stdio.h>

double calcluate_triangle_surface(double base, double height);
//		[Description] calculate the surface of orthogonal triangle.
//      [Input] base   : the base of target triangle.
//				height : the height of target triangle. 
//      [Output] The surface of target triangle.

int main() 
{
	double base; // The base of target triangle.
	double height; // The height of target triangle. 
	double surface; // The surface of target triangle.

	// Ask user to input base.
	printf("Please input base of triangle (cm).\n");

	// Verify if input is valid.
	if (scanf_s("%lf", &base) && (base > 0))
	{
		// Ask user to input height.
		printf("Please input height of triangle (cm) \n");

		// Verify if input is valid.
		if (scanf_s("%lf", &height) && (height > 0)) 
		{
			// Calculate triangle surface by calcluate_triangle_surface.
			surface = calcluate_triangle_surface(base, height);
			// Print result
			printf("The surface of triangle is %lf (cm^2)\n", surface);
		}
		else
		{
			// Print error message.
			printf("Error : height should be nonnegative numbers.");
		}
	}
	else
	{
		// Print error message.
		printf("Error : base should be nonnegative numbers.");
	}
}

double calcluate_triangle_surface(double base, double height) {
	return (base * height) / 2.0;
}