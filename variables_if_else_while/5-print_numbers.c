#include <stdio.h>

/**
 * main - prints all single digit numbers of base 10
 *
 * Return: Always 0
 */
int main(void)
{
	int n;

	n = 0;

	while (n <= 9)
	{
		printf("%d", n);
		n++;
	}

	printf("\n");

	return (0);
}
