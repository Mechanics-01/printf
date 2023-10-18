#include "main.h"

/**
 * convert_to_binary - Converts an integer to binary and prints it.
 * @value_bin: The integers to be converted and printed in binary.
 *
 * Return: Numbers of 32 binary digits are printed.
 */

int convert_to_binary(long int value_bin)
{
	char box[33];
	int count_b = 31;
	int i = 0, j;

	if (value_bin < 0)
		value_bin = -value_bin - 1;
	
	if (value_bin == 0)
		_putchar('0');

	while (value_bin > 0)
	{
		box[i++] = value_bin % 2;
		value_bin = value_bin / 2;
		count_b++;
	}
	
	for (j = i - 1; j >= 0; j--)
		_putchar(48 + box[j]);

	
	return (count_b);
}
