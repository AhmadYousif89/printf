#include "main.h"

/**
 * _puts - Print string to stdout
 * @s: pointer to the string
 * Return: string length
 */
int _puts(char *s)
{
	char *start = s;

	while (*s)
		_putchar(*s++);

	return (s - start);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buffer[BUFFER_SIZE];

	if (c != BUFFER_FLUSH)
		buffer[i++] = c;
	if (i >= BUFFER_SIZE || c == BUFFER_FLUSH)
	{
		write(1, buffer, i);
		i = 0;
	}

	return (1);
}
