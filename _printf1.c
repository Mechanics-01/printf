#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The character string that contains 0.
 * Return: The numbers of characters to be printed.
 */

int _printf(const char *format, ...)
{
	int i;
	int count_n = 0, flag_p = 0, flag_s = 0, flag_h;
	char init;

	va_list args_list;

	if (format == NULL)
		return (-1);
	if (*format == '\0')
		return (-1);
	va_start(args_list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count_n++;
		}
		else
		{
			while (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#')
			{
				if (format[i + 1] == '+')
					flag_p = 1;
				else if (format[i + 1] == ' ')
					flag_s = 1;
				else if (format[i + 1] == '#')
					flag_h = 1;
				i++;
			}
			init = format[i + 1];
			count_n += format_specifier(args_list, init, flag_h, flag_p, flag_s);
			i++;
		}
	}
	va_end(args_list);
	return (count_n);
}
