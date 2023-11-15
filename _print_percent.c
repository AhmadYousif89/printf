#include "main.h"

/**
 * _print_percent - Print the character (%)
 * @vlp: pointer to the arg list
 * @flags: pointer to the flags struct
 * Return: int -> length
 */
int _print_percent(va_list vlp, flags_t *flags)
{
	UNUSED(vlp);
	UNUSED(flags);
	return (_putchar('%'));
}
