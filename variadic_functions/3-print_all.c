#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a char
 * @list: list of arguments
 *
 * Return: nothing
 */
void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * print_int - prints an integer
 * @list: list of arguments
 *
 * Return: nothing
 */
void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_float - prints a float
 * @list: list of arguments
 *
 * Return: nothing
 */
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * print_string - prints a string
 * @list: list of arguments
 *
 * Return: nothing
 */
void print_string(va_list list)
{
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	int i;
	char *sep;
	va_list list;
	token_t tokens[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};
	int j;

	i = 0;
	sep = "";
	va_start(list, format);
	while (format && format[i])
	{
		j = 0;
		while (tokens[j].token)
		{
			if (format[i] == tokens[j].token[0])
			{
				printf("%s", sep);
				tokens[j].f(list);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(list);
	printf("\n");
}
