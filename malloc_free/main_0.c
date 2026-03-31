#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0
 */
int main(void)
{
	char *s;
	unsigned int i;

	s = create_array(5, 'A');
	if (s == NULL)
		return (1);

	for (i = 0; i < 5; i++)
		_putchar(s[i]);
	_putchar('\n');

	free(s);
	return (0);
}
