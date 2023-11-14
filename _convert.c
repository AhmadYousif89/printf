#include "main.h"

/**
 * convert - Convert long integers into a string representation
 * @ln: long number
 * @base: base value (10, 16, etc...)
 * @args: arg flags number
 * @flags: pointer to flags struct
 * Return: pointer to string
 */
char *convert(long int ln, int base, int args, flags_t *flags)
{
	static char *arr;
	static char buf[50];
	unsigned long ul = ln;
	char sign = 0;
	char *p;

	UNUSED(flags);

	if (!(args & 2) && ln < 0)
	{
		ul = -ln;
		sign = '-';
	}
	arr = args & 1 ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do {
		*--p = arr[ul % base];
		ul /= base;
	} while (ul != 0);

	if (sign)
		*--p = sign;

	return (p);
}
