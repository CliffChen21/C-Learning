// Section 1.4 Exercise 5
// [Author] Cliff Chen
// [Description] Print temperature with Celsius (int the left),
//				 and Fahrenheit (in the right).
//               Format : %10.1f.
#include <stdio.h>

void print_temperature(double temperature_celsius);
//		[Description] print given temperature (Celsius) in Celsius and Fahrenheit.
//      [Input] temperature_celsius : temperature in celsius.
//      [Output] string of both temperatures, separated with comma.

void main()
{
	// Initializing.
	int start_temperature_celsius = 0; // in Celsius.
	int end_temperature_celsius = 19; // in Celsius.

	int temperature_celsius = start_temperature_celsius;

	printf("%10s, %10s\n", "Celsius", "Fahrenheit");

	for (int temperature_celsius = start_temperature_celsius; temperature_celsius <= end_temperature_celsius; temperature_celsius++)
	{
		// Type conversion : int->double.
		print_temperature((double) temperature_celsius);
	}
}

void print_temperature(double temperature_celsius)
{
	// Compute Fahrenheit with Celsius.
	double temperature_fahrenheit = (9.0 / 5.0) * temperature_celsius + 32.0;

	printf("%10.1f, %10.1f\n", temperature_celsius, temperature_fahrenheit);
}
