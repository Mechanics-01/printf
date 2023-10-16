#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero
 * Return: The number of characters printed (excluding
 */
int _printf(const char *format, ...)
{
	int count_n = 0;
	char *string, a;
	va_list args_list;

	if (format == NULL)
		return (-98);
	va_start(args_list, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count_n++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				a = va_arg(args_list, int);
				write(1, &a, 1);
				count_n++;
			}
			else if (*format == 's')
			{
				string = va_arg(args_list, char *);
				while (*string != '\0')
				{
					write(1, string, 1);
					count_n++;
					string++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count_n++;
			}
		}
		format++;
	}
	va_end(args_list);
	return (count_n - 1);
}
