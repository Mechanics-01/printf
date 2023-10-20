#include "main.h"

/**
 * convert_to_octal - Converts an integer to octal and prints in digit.
 * @value_o: The integers to be converted and printed in octal.
 *
 * Return: Numbers of octals in digit is printed.
 */

int convert_to_octal(int value_o)
{
	int box[50];
	int count_b = 0;
	int i = 0;
	int j = 0;
	unsigned int number;

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
	if (value_o < 0)
	{
		number = 4294967296 + value_o;

		while (number > 0)
		{
			box[i] = number % 8;
			number = number / 8;
			i++;
			count_b++;
		}

		for (j = i - 1; j >= 0; j--)
			_putchar('0' + box[j]);
	}

	return (count_b);
}
