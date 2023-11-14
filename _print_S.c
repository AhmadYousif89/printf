#include "main.h"

/**
 * _print_S - Print strings with non-printable characters escaped in hex
 * @vlp: pointer to argument list
 * @flags: pointer to the flags struct
 * Return: length
 */
int _print_S(va_list vlp, flags_t *flags)
{
	int len = 0;
	char *s = va_arg(vlp, char *);

	if (s == NULL)
		return (_puts("(null)"));

	for (; *s; s++)
	{
		if (*s < 32 || *s >= 127)
		{
			len += _putchar('\\') + _putchar('x');
			if (*s < 16)
				len += _putchar('0');
			len += _puts(convert(*s, 16, 0, flags));
		}
		else
			len += _putchar(*s);
	}

	return (len);
}
