#include "main.h"

/**
 * _print_binary - Print binary number
 * @vlp: pointer to argument list
 * @flags: pointer to the flags struct
 * Return: length
 */
int _print_binary(va_list vlp, flags_t *flags)
{
	int len = 0;
	unsigned int b = va_arg(vlp, unsigned int);
	char *s = convert(b, 2, 2, flags);

	if (flags->_hash && b)
		*--s = '0';

	flags->_unsign = 1;

	len += _print_num(s, flags);

	return (len);
}
