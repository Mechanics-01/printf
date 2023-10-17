#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int k;


	_printf("%c\n", 's');
	_printf("%o\n", 1024);
	_printf("%X\n", 1024672465);
	_printf("%x\n", 1024);
	k = _printf("%u\n",102446573);
	printf("%d\n", k);
	
	return (0);
}
