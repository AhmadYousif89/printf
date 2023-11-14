#include "main.h"

/**
 * init_flags - Reset the flags struct
 * @flags: pointer to the flags struct
 * @vlp: pointer to the arg list
 */
void init_flags(flags_t *flags, va_list vlp)
{
	flags->_unsign = 0;
	flags->_plus = 0;
	flags->_minus = 0;
	flags->_zero = 0;
	flags->_blank = 0;
	flags->_hash = 0;
	flags->_short = 0;
	flags->_long = 0;
	flags->_width = 0;
	flags->_percision = UINT_MAX;
	UNUSED(vlp);
}

/**
 * _isdigit - Check if character is digit
 * @c: arg of type char
 * Return: 1 (c is digit) or 0
 */

int _isdigit(char c)
{
	int res = (c >= 48 && c <= 57) ? 1 : 0;

	return (res);
}

/**
 * _strlen - Return the length of string
 * @s: pointer of type char *
 * Return: Length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;

	return (i);
}
