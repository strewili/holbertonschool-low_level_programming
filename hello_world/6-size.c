/*
 * File: 6-size.c
 * Auth: strewixi
 */

#include <stdio.h>

/**
 * main - Prints "with proper grammar, but the outcome is
 *                a piece of art," folowed be any line you like go for it
 *
 * Return: Always 0.
 */
int main(void)
{
  printf("Size of a char: %lu byte(s)\n", sizeof(char));
    printf("Size of an int: %lu byte(s)\n", sizeof(int));
    printf("Size of a long int: %lu byte(s)\n", sizeof(long int));
    printf("Size of a long long int: %lu byte(s)\n", sizeof(long long int));
    printf("Size of a float: %lu byte(s)\n", sizeof(float));
	return (0);
}
