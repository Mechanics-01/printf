include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The character string that contains 0.
 *
 * Return: The numbers of characters to be printed.
 */

int _printf(const char *format, ...)
{
	int i;
	int count_n = 0;
	int number;
	char a;
	char *string;

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
			if (format[i + 1] == 'c')
			{
				a = va_arg(args_list, int);
				write(1, &a, 1);
				count_n++;
			}
			else if (format[i + 1] == 's')
			{
				string = va_arg(args_list, char *);
				for (; *string != '\0'; string++, count_n++)
				{
					write(1, string, 1);
				}
			}
			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				count_n++;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				number = va_arg(args_list, int);
				count_n += convert_to_string(number);
			}
			else if (format[i + 1] == 'b')
			{
				number = va_arg(args_list, int);
				count_n += convert_to_binary(number);
			}
			else if (format[i + 1] == 'u')
			{
				number = va_arg(args_list, int);
				count_n += convert_to_string(number);
			}
			else if (format[i + 1] == 'o')
			{
				number = va_arg(args_list, int);
				count_n += convert_to_octal(number);
			}
			else if (format[i + 1] == 'x')
			{
				number = va_arg(args_list, int);
				count_n += convert_to_hexa(number);
			}
			else if (format[i + 1] == 'X')
			{
				number = va_arg(args_list, int);
				count_n += convert_to_heXa(number);
			}
			i++;
		}
	}
	va_end(args_list);
	return (count_n);
}
