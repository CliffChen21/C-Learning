// Section 1.3 Exercise 7
// [Author] Cliff Chen
// [Description] Multiply the input number with the power of 2.
// Sample Input& Output
//		[Input]  3.5 3
//		[Output] 3.500000 * 2^3=28.000000

#include <stdio.h>
#include <limits.h>

long double compute_multiplication_factor(int power);
//		[Description] calculate multiplication factor 2^power.
//      [Input] power   : power of 2.
//      [Output] 2^power.

void main() {
	int n;            // Input power n.
	double num;       // Input number.
	int bit_size_lld = CHAR_BIT * sizeof(long long int); // Size of long long int in bit.
	double result;    // Variable to store result.
	double factor;    // multiplication factor, 2^n.

	// Ask user to input the value accroding required format. See Sample Input& Output.
	printf("Please the number and power as : number power.(separate by space)\n");

	// Verify the input and avoid the overflow in compute_multiplication_factor.
	// -2 for sign.
	if (scanf_s("%lf %d", &num, &n) && (n <= (bit_size_lld - 2) && n >= -(bit_size_lld - 2)))
	{
		// Compute and print the result of num * 2^n.
		if (n >= 0) {
			factor = compute_multiplication_factor(n);
		}
		else
		{
			factor = 1.0 / compute_multiplication_factor(-n);
		}
		result = num * factor;

		// Deal with stackoverflow.
		if (result / factor != num)
		{
			// Print overflow message.
			printf("Stack overflow. The number and power n is too large.");
		}
		else
		{ 
			// Print correct result.
			printf("%.2f * 2^%d=%.2f\n", num, n, result);
		}		
	}
	else
	{
		// Print error message if input is not : double int. 
		printf("Error : Please check that number should be a number\n");
		printf("	and power should be an integer within [-%d, %d].\n", bit_size_lld - 2, bit_size_lld - 2);
	}
}

long double compute_multiplication_factor(int power)
{
	// Initializing the base.
	long long int factor = 1;

	// Compute the power of n.
	factor = factor << power;

	// return factor with type conversion.
	return factor;
}



