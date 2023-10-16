#include "main.h"

/**
 * _stringlength - Calculates the length of a string.
 * @str: The input string.
 * Return: The length of the string (excluding the null terminator '\0').
 */

int _stringlength(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
