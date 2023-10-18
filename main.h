#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#define BUFF 1024

int _printf(const char *format, ...);
int _stringlength(const char *str);
int convert_to_string(int number);
int convert_to_binary(int value_bin);
int convert_to_heXa(int value_bin);
int convert_to_hexa(int value_bin);
int convert_to_octal(int value_o);
int _putchar(char c);
int format_specifier(va_list args_list, char format);

#endif/*MAIN_H*/
