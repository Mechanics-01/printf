#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The character string that contains 0.
 * Return: The numbers of characters to be printed.
 */

int _printf(const char *format, ...)
{
	int i, k;
	int count_n = 0;
	int number;
	unsigned int number1;
	char a, box[3] = {0};
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
			else if (format[i + 1] == '%')
			{
				write(1, "%", 1);
				count_n++;
			}
			else if (format[i + 1] == '\0')
			{
				return (count_n);
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
				number1 = va_arg(args_list, int);
				count_n += convert_to_string(number1);
			}
			else if (format[i + 1] == 'o')
			{
				number1 = va_arg(args_list, int);
				count_n += convert_to_octal(number1);
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
			else if (format[i + 1] == 'S')
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
			else if (format[i + 1] == 'r')
			{
				string = va_arg(args_list, char *);
				for (k = strlen(string) - k; k >= 0; k--)
				{
					_putchar(string[k]);
					count_n++;
				}
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i + 1], 1);
				count_n = count_n + 2;
			}
			i++;
		}
	}
	va_end(args_list);
	return (count_n);
}
