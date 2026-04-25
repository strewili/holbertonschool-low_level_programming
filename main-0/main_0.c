#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - check the code
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	int res;
	char *content = "Hello, World!";

	if (ac > 1)
		content = av[1];

	res = append_text_to_file("file.txt", content);
	if (res == 1)
		printf("-> %d)\n", res);
	else
		printf("Error\n");

	return (0);
}
