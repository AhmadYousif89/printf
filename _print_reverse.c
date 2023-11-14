#include "main.h"

/**
 * _print_reverse - Print string in reverse
 * @vlp: pointer to argument list
 * @flags: pointer to flags struct
 * Return: length
 */
int _print_reverse(va_list vlp, flags_t *flags)
{
	int i = 0, len = 0;
	char *s = va_arg(vlp, char *);

	UNUSED(flags);

	if (s != NULL)
	{
		while (*s) /* Move the pinter to the last char */
		{
			i++;
			s++;
		}
		s--; /* Set the pointer before the null terminator */
		for (; i > 0; i--, s--)
			len += _putchar(*s); /* Print in reverse */
	}

	return (len);
}
