#include "main.h"

/**
 * _print_range - Print a range of characters
 * @start: Pointer to the starting position
 * @end: Pointer to the ending position
 * @exclude: Pointer to the excluding position
 * Return: the length of printed chars.
 */
int _print_range(char *start, char *end, char *exclude)
{
	int len = 0;

	while (start <= end)
	{
		if (start != exclude)
			len += _putchar(*start);
		start++;
	}

	return (len);
}
