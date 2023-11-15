#include "main.h"

/**
 * _print_adds - Print the address for the given variable
 * @vlp: pointer to argument list
 * @flags: pointer to the flags struct
 * Return: length
 */
int _print_adds(va_list vlp, flags_t *flags)
{
	char *s;
	int n = 0;
	unsigned long int ln = va_arg(vlp, unsigned long int);

	if (!ln)
		return (_puts("(nil)"));

	s = convert(ln, 16, 2 | 1, flags);
	*--s = 'x';
	*--s = '0';
	n = _print_num(s, flags);

	return (n);
}
