#include "main.h"

int format_specifier(va_list args_list, char format)
{
	int count_n = 0;
	char a;
	char *string;
	int number;

	if (format == 'c')
	{
		a = va_arg(args_list, int);
		write(1, &a, 1);
		count_n++;
	}
	else if (format == 's')
	{
		string = va_arg(args_list, char *);
		for (; *string != '\0'; string++, count_n++)
		{
			write(1, string, 1);
		}
	}
	else if (format == '%')
	{
		write(1, "%", 1);
		count_n++;
	}
	else if (format == 'd' || format == 'i')
	{
		number = va_arg(args_list, int);
		count_n += convert_to_string(number);
	}
	else if (format == 'b')
	{
		number = va_arg(args_list, int);
		count_n += convert_to_binary(number);
	}
	else if (format == 'u')
	{
		number = va_arg(args_list, int);
		count_n += convert_to_string(number);
	}
	else if (format == 'o')
	{
		number = va_arg(args_list, int);
		count_n += convert_to_octal(number);
	}
	else if (format == 'X')
	{
		number = va_arg(args_list, int);
		count_n += convert_to_heXa(number);
	}
	else if (format == 'x')
	{
		number = va_arg(args_list, int);
		count_n += convert_to_hexa(number);
	}
	return (count_n);
}