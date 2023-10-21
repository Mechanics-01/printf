#include "main.h"

/**
 * format_specifier - Handles format specifiers for custom printf function.
 * @args_list: List of arguments to process.
 * @format: Format specifier character.
 * @flag_h: Flag for hash (#) modifier.
 * @flag_p: Flag for plus (+) modifier.
 * @flag_s: Flag for space ( ) modifier.
 * Return: Number of characters printed (excluding null byte).
 */

int format_specifier(va_list args_list, char format, int flag_h, int flag_p, int flag_s)
{
	int number, k;
	int count_n = 0;
	unsigned int number1;
	char a, box[3] = {0};
	char *string;
	void *point;
	long unsigned int char_point;

	if (format == 'c')
	{
		a = va_arg(args_list, int);
		write(1, &a, 1);
		count_n++;
	}
	else if (format == 's')
	{
		string = va_arg(args_list, char *);
		if (string != NULL)
		{
			for (; *string != '\0'; string++, count_n++)
				write(1, string, 1);
		}
		else
		{
			write(1, "(null)", 6);
			count_n = count_n + 6;
		}
	}
	else if (format == '%')
	{
		write(1, "%", 1);
		count_n++;
	}
	else if (format == '\0')
	{
		return (count_n);
	}
	else if (format == 'd' || format == 'i')
	{
		number = va_arg(args_list, int);
		if (flag_p && number >= 0)
		{
			_putchar('+');
			count_n++;
		}
		else if (flag_s && number >= 0)
		{
			_putchar(' ');
			count_n++;
		}
		count_n += convert_to_string(number);
	}
	else if (format == 'b')
	{
		number = va_arg(args_list, int);
		count_n += convert_to_binary(number);
	}
	else if (format == 'u')
	{
		number1 = va_arg(args_list, int);
		count_n += convert_to_string(number1);
	}
	else if (format == 'o')
	{
		number1 = va_arg(args_list, int);
		if (flag_h && number1)
		{
			_putchar('0');
			count_n++;
		}
		count_n += convert_to_octal(number1);
	}
	else if (format == 'x')
	{
		number = va_arg(args_list, int);
		if (flag_h && number)
		{
			_putchar('0');
			_putchar('x');
			count_n += 2;
		}
		count_n += convert_to_hexa(number);
	}
	else if (format == 'X')
	{
		number = va_arg(args_list, int);
		if (flag_h && number)
		{
			_putchar('0');
			_putchar('X');
			count_n += 2;
		}
		count_n += convert_to_heXa(number);
	}
	else if (format == 'S')
	{
		string = va_arg(args_list, char *);
		for (; *string != '\0'; string++, count_n++)
		{
			if ((*string < 32) || (*string >= 127))
			{

				box[0] = ((*string / 16) % 16) + '0';
				box[0] += (box[0] > '9') ? 7 : 0;
				box[1] = (*string % 16) + '0';
				box[1] += (box[1] > '9') ? 7 : 0;
				write(1, "\\x", 2);
				write(1, box, 2);
				count_n += 3;
			}
			else
				write(1, string, 1);
		}
	}
	else if (format == 'r')
	{
		string = va_arg(args_list, char *);
		for (k = strlen(string) - 1; k >= 0; k--)
		{
			_putchar(string[k]);
			count_n++;
		}
		count_n--;
	}
	else if (format == 'p')
	{
		point = va_arg(args_list, void *);
		if (point != NULL)
		{
			char_point = (long int)point;
			_putchar('0');
			_putchar('x');
			count_n = count_n + convert_to_hexa(char_point) + 2;
		}
		else
		{
			write(1, "(nil)", 5);
			count_n = count_n + 5;
		}
	}
	else
	{
		write(1, "%", 1);
		write(1, &format, 1);
		count_n = count_n + 2;
	}
	return (count_n);
}
