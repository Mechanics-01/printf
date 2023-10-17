#include "main.h"

/**
 * convert_to_octal - Converts an integer to octal and prints it.
 * @value_o: The integer to be converted and printed in octal.
 *
 * Return: Number of octal digits printed.
 */

int convert_to_octal(int value_o)
{
	int box[50];
	int count_b = 0;
	int i = 0;
	int j = 0;

	if (value_o == 0)
	{
		_putchar('0');
		count_b++;
		return (count_b);
	}

	while (value_o > 0)
	{
		box[i] = value_o % 8;
		value_o = value_o / 8;
		i++;
		count_b++;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar('0' + box[j]);

	return (count_b);
}
