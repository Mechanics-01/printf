#include "main.h"
/**
 * convert_to_binary - Converts an integer to binary and prints it.
 * @value_bin: The integer to be converted and printed in binary.
 *
 * Return: Number of binary digits printed.
 */

int convert_to_binary(int value_bin)
{
	int box[50];
	int count_b = 0;
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
		box[i] = value_bin % 2;
		value_bin = value_bin / 2;
		i++;
		count_b++;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar(48 + box[j]);

	return (count_b);
}
