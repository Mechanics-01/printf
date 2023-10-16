#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *str, c;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str != '\0')
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
