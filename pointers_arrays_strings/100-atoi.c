#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: converted integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int digit;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;

		if (s[i] >= '0' && s[i] <= '9')
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				digit = s[i] - '0';

				/* build number as negative to avoid overflow */
				if (result < (INT_MIN + digit) / 10)
					return (sign == 1 ? INT_MAX : INT_MIN);

				result = result * 10 - digit;
				i++;
			}

			if (sign == 1)
			{
				if (result == INT_MIN)
					return (INT_MAX);
				return (-result);
			}

			return (result);
		}

		i++;
	}

	return (0);
}
