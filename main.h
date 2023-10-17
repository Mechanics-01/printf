#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _stringlength(const char *str);
int convert_to_string(int number);
int convert_to_binary(int value_bin);
int convert_to_heXa(int value_bin);
int convert_to_hexa(int value_bin);
int convert_to_octal(int value_o);
int _putchar(char c);

#endif/*MAIN_H*/
