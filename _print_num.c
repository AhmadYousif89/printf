#include "main.h"

/**
 * _print_num - helper function for _print_digit
 * @s: the base number as string
 * @flags: pointer to flags struct
 * Return: length
 */
int _print_num(char *s, flags_t *flags)
{
	unsigned int len = _strlen(s);
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

	if (flags->_minus)
		return (_prnt_num_lft_pad(s, flags));
	else
		return (_prnt_num_rht_pad(s, flags));
}

/**
 * _prnt_num_rht_pad - Print number with applied right padding
 * @s: the base number as string
 * @flags: pointer to flags struct
 * Return: length
 */
int _prnt_num_rht_pad(char *s, flags_t *flags)
{
	unsigned int len = 0;
	/* TODO: the actual functionality */
	UNUSED(flags);
	len += _puts(s);

	return (len);
}

/**
 * _prnt_num_lft_pad - Print number with applied left padding
 * @s: the base number as string
 * @flags: pointer to flags struct
 * Return: length
 */
int _prnt_num_lft_pad(char *s, flags_t *flags)
{
	unsigned int len = 0;
	/* TODO: the actual functionality */
	UNUSED(flags);
	len += _puts(s);

	return (len);
}
