#include "main.h"

/**
 * _print_rot13 - Print string in rot13
 * @vlp: pointer to argument list
 * @flags: pointer to the flags struct
 * Return: length
 */
int _print_rot13(va_list vlp, flags_t *flags)
{
	int i = 0, len = 0;
	char *s = va_arg(vlp, char *);

	UNUSED(flags);

	while (s[i])
	{
		char c = s[i];

		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			char base = (c >= 'a') ? 'a' : 'A';

			len += _putchar((c - base + 13) % 26 + base);
		}
		else
			len += _putchar(c);

		i++;
	}

	return (len);
}
