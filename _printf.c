#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int i;
	int count_n = 0;

	va_list args_list;

	if (format == NULL)
		return (-1);
	
	if (*format == '\0')
		return (0);
	
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
			int init = format[i + 1];
			count_n += format_specifier(args_list, init);
			i++;
		}
	}
	va_end(args_list);
	return (count_n);
}
