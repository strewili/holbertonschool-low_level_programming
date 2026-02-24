#include <stdio.h>

/**
 * main - prints the lowercase alphabet except q and e
 *
 * Return: Always 0
 */
int main(void)
{
	int c;

	c = 'a';

	while (c <= 'z')
	{
		if (c != 'q' && c != 'e')
		{
			putchar(c);
		}
		c++;
	}

	putchar('\n');

	return (0);
}
