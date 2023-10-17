#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero
 * Return: The number of characters printed (excluding
 */
int _printf(const char *format, ...)
{
	int i, count_n = 0;
	char *string, a;
	va_list args_list;

	if (format == NULL)
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
			if (format[i + 1] == 'c')
			{
				a = va_arg(args_list, int);
				write(1, &a, 1);
				count_n++;
			}
			else if (format[i + 1] == 's')
			{
				string = va_arg(args_list, char *);
				for (; *string != '\0' && (++count_n, 1); write(1, string++, 1))
					;
			}
			else if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				count_n++;
			}
			i++;
		}
	}
	va_end(args_list);
	return (count_n);
}
