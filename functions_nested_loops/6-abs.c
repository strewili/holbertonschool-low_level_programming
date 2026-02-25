#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @c: the number to compute
 *
 * Return: the absolute value of c
 */
int _abs(int c)
{
	if (c < 0)
	{
		return (-c);
	}

	return (c);
}
