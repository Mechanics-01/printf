#include "main.h"

/**
 * convert_to_binary - Converts an integer to binary and prints in digit.
 * @value_bin: The integers to be converted and printed in binary.
 * Return: Numbers of 32 binary digits are printed.
 */

int convert_to_binary(long int value_bin)
{
	char box[32];
	int count_b = 0;
	int i = 0, j;

	if (value_bin == 0)
	{
			_putchar('0');
			count_b++;
	}

	while (value_bin > 0)
	{
		box[i] = value_bin % 2;
		value_bin = value_bin / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(48 + box[j]);
		count_b++;
	}
	if (value_bin < 0)
	{
		value_bin = UINT_MAX + value_bin + 1;
		for (i = 0; i < 32; i++)
		{
			box[i] = value_bin % 2;
			value_bin = value_bin / 2;
			count_b++;
		}

		for (j = i - 1; j >= 0; j--)
			_putchar(48 + box[j]);
	}
	return (count_b);
}
