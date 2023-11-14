#include "main.h"

/**
 * _puts - Print string to stdout
 * @s: pointer to the string
 * Return: string length
 */
int _puts(char *s)
{
	int l = 0;

	while (s[l] != '\0')
		_putchar(s[l++]);

	return (l);
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
	static char buf[BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= BUFFER_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[i++] = c;
	return (1);
}
