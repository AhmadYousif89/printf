#include "main.h"

/**
 * _print_string - Print a string
 * @vlp: pointer to the arg list
 * @flags: pointer to the flags struct
 * Return: Nothing.
 */
int _print_string(va_list vlp, flags_t *flags)
{
	char p_char = ' ';
	char *s = va_arg(vlp, char *);
	unsigned int i, c, len = 0, p_count = 0;

	UNUSED(flags);

	if (s == NULL)
		s = "(null)";
	/* Set (c) and (p_count) = length of (s) */
	c = p_count = _strlen(s);
	/* Case the value of percision is greater than the pad count */
	if (flags->_percision < p_count)
		c = p_count = flags->_percision;
	/* Case we have (-) flag then print before padding */
	if (flags->_minus)
	{
		if (flags->_percision == UINT_MAX)
			len += _puts(s);
		else
			for (i = 0; i < p_count; i++)
				len += _putchar(*s++);
	}

	while (flags->_width > c++)
		len += _putchar(p_char); /* Print the padding */

	/* Case the (-) flag isn't present then print after padding */
	if (!flags->_minus)
	{
		if (flags->_percision == UINT_MAX)
			len += _puts(s);
		else
			for (i = 0; i < p_count; i++)
				len += _putchar(*s++);
	}

	return (len);
}
