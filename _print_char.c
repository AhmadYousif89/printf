#include "main.h"

/**
 * _print_char - Print a char
 * @vlp: pointer to the arg list
 * @flags: pointer to the flags struct
 * Return: int
 */
int _print_char(va_list vlp, flags_t *flags)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(vlp, int);

	if (flags->_minus)
		sum += _putchar(ch);
	while (pad++ < flags->_width)
		sum += _putchar(pad_char);
	if (!flags->_minus)
		sum += _putchar(ch);
	return (sum);
}
