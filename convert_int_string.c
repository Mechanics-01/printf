#include "main.h"

/**
 * convert_to_string - Converts an integer to a string
 * and prints it.
 * @number: The integer to be converted and printed.
 * Return: Number of characters printed.
 */

int convert_to_string(int number)
{
	char box[40];
	int count_p = 0;
	int i = 0, j = 0;

	if (number < 0)
	{
		_putchar('-');
		count_p++;
		number = -number;
	}

	while (number > 0)
	{
		box[i] = (number % 10) + '0';
		number = number / 10;
		i++;
		count_p++;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar(box[j]);

	return (count_p);
}
