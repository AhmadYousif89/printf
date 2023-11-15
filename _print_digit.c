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

/**
 * _print_num - helper function for _print_digit
 * @s: the base number as string
 * @flags: pointer to flags struct
 * Return: length
 */
int _print_num(char *s, flags_t *flags)
{
	unsigned int n = 0, len = _strlen(s);
	int is_negative = *s == '-' && !flags->_unsign;

	if (*s == '0' && !s[1] && !flags->_percision)
		s = "";
	if (is_negative)
	{
		s++;
		len--;
	}
	while (flags->_percision != UINT_MAX && flags->_percision > len++)
		*--s = '0';

	if (is_negative)
		*--s = '-';

	n += _puts(s);

	return (n);
}
