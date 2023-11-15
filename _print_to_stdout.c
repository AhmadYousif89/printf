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
 * _putchar - Print to stdout using (write)
 * @c: The character to print
 * Return: 1 On success, -1 On error, and errno is set automatically
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
