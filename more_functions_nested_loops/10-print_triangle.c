#include "main.h"

/**
 * print_triangle - prints a triangle using #
 * @size: size of the triangle
 *
 * Return: Nothing
 */
void print_triangle(int size)
{
	int i;
	int j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		/* Print spaces */
		for (j = 0; j < size - i; j++)
		{
			_putchar(' ');
		}

		/* Print #'s */
		for (j = 0; j < i; j++)
		{
			_putchar('#');
		}

		_putchar('\n');
	}
}
