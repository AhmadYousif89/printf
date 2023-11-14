#include "main.h"

/**
 * _print_char - Print a char
 * @vlp: pointer to the arg list
 * @flags: pointer to the flags struct
 * Return: int
 */
int _print_char(va_list vlp, flags_t *flags)
{
	char p_char = ' ';
	int c = va_arg(vlp, int);
	unsigned int p_count = 0, len = 0;

	/* Case we have a (-) flag print before padding */
	if (flags->_minus)
		len += _putchar(c);

	while (flags->_width > p_count++)
		len += _putchar(p_char); /* Print the padding */

	/* Case we don't have a (-) flag print after padding */
	if (!flags->_minus)
		len += _putchar(c);

	return (len);
}
