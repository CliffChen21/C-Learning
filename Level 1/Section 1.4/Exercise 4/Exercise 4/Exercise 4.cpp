// Section 1.4 Exercise 4
// [Author] Cliff Chen
// [Description] Print temperature with Fahrenheit (int the left),
//				 and Celsius (in the right).
//               Format : %10.1f.
#include <stdio.h>

void print_temperature(double temperature_fahrenheit);
//		[Description] print given temperature (Fahrenheit) in Fahrenheit and Celsius.
//      [Input] temperature_fahrenheit : temperature in Fahrenheit.
//      [Output] string of both temperatures, separated with comma.

void main()
{
	// Initializing. (For futhre maintaining)
	int start_temperature_fahrenheit = 0; // in Fahrenheit.
	int end_temperature_fahrenheit = 300; // in Fahrenheit.
	int step = 20; // step size.

	int temperature_fahrenheit = start_temperature_fahrenheit;

	printf("%10s, %10s\n", "Fahrenheit", "Celsius");

	while (temperature_fahrenheit <= end_temperature_fahrenheit)
	{
		// Type conversion : int->double.
		print_temperature((double) temperature_fahrenheit);
		temperature_fahrenheit += step;
	}
}

void print_temperature(double temperature_fahrenheit)
{
	double temperature_celisus = (5.0 / 9.0) * (temperature_fahrenheit - 32.0);

	printf("%10.1f, %10.1f\n", temperature_fahrenheit, temperature_celisus);
}
