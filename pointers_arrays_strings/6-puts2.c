#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: string to print
 *
 * Return: Nothing
 */
void puts2(char *str)
{
	int i;
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
