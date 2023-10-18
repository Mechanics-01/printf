#include "main.h"

/**
 * convert_to_heXa - Converts an integer to hexadecimal and prints it.
 * @value_bin: The integer to be converted and printed in hexadecimal.
 *
 * Return: Numbers of hexadecimal in digit is printed.
 */

int convert_to_heXa(int value_bin)
{
	int box[100];
	int count_b = 0;
	int divided;
	char digits;
	int i = 0;
	int j = 0;

	if (value_bin == 0)
	{
		_putchar('0');
		count_b++;
		return (count_b);
	}

	while (value_bin > 0)
	{
		divided = value_bin % 16;
		if (divided < 10)
			digits = divided + '0';
		else
			digits = (divided - 10) + 'A';

		box[i] = digits;

		value_bin = value_bin / 16;
		i++;
		count_b++;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar(box[j]);

	return (count_b);
}
