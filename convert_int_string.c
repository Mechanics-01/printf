#include "main.h"

/**
 * convert_to_string - It convert an integer to strings.
 * and prints it.
 * @number: The integers are converted and printed.
 *
 * Return: Numbers of characters printed.
 */

int convert_to_string(int number)
{
	char box[40];
	int count_p = 0;
	int i = 0;
	int j = 0;

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
