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
	int count = 0;

	if (value_bin < 0)
	{
		box[0] = '1';
		value_bin = -value_bin - 1;
	}
	else
		box[0] = '0';

	for (i = 0; i < 31; i++)
	{
		box[count_b--] = (value_bin % 2) + '0';
		value_bin = value_bin / 2; 
		count++;
	}
	for (j = 0; j < 32; j++)
		_putchar(box[j]);
		
	box[32] = '\0';
	return (count);
}
