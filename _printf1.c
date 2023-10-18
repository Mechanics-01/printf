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
	int number;
	char a;
	char *string;
	char buff_holder[BUFF];
	int buff_i = 0;

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
			buff_holder[buff_i++] = format[i];
			count_n++;
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				a = va_arg(args_list, int);
				buff_holder[buff_i++] = a;
				count_n++;
			}
			else if (format[i + 1] == 's')
			{
				string = va_arg(args_list, char *);
				for (; *string != '\0'; string++, count_n++)
				{
					buff_holder[buff_i++] = *string;;
				}
			}
			else if (format[i + 1] == '%')
			{
				buff_holder[buff_i++] = '%';
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
