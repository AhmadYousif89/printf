#include "main.h"

/**
 * _print_digit - Print any given number
 * @vlp: pointer to the arg list
 * @flags: pointer to the flags struct
 * Return: length
 */
int _print_digit(va_list vlp, flags_t *flags)
{
	long ln;
	char *result;

	if (flags->_long)
		ln = va_arg(vlp, long);
	else if (flags->_short)
		ln = (short)va_arg(vlp, int);
	else
		ln = (int)va_arg(vlp, int);

	result = convert(ln, 10, 0, flags);

	return (_print_num(result, flags));
}
