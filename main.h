#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define BUFF 1024


/*function names used*/
int _printf(const char *format, ...);
int _stringlength(const char *str);
int convert_to_string(long int number);
int convert_to_binary(long int value_bin);
int convert_to_heXa(int value_bin);
int convert_to_hexa(long int value_bin);
int convert_to_octal(int value_o);
int _putchar(char c);
int format_specifier(va_list args_list, char format, int a, int b, int c);

#endif/*MAIN_H*/
