#include "main.h"

/**
 * _print_string - Print a string
 * @vlp: pointer to the arg list
 * @flags: pointer to the flags struct
 * Return: Nothing.
 */
int _print_string(va_list vlp, flags_t *flags)
{
	char *str = va_arg(vlp, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)flags;

	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (flags->_percision < pad)
		j = pad = flags->_percision;

	if (flags->_minus)
	{
		if (flags->_percision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < flags->_width)
		sum += _putchar(pad_char);
	if (!flags->_minus)
	{
		if (flags->_percision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}
