#include "main.h"

/**
 * _printf - Custom Printf
 * @format: pointer to the given string
 * Return: the number of characters given to the function
 */
int _printf(const char *format, ...)
{
	int len = 0;
	char *start, *s;
	flags_t flags = INIT_FLAGS;

	va_list(vlp);
	va_start(vlp, format);

	if (!format
		|| (format[0] == '%' && !format[1])
		|| (format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);

	s = (char *)format;
	for (; *s; s++)
	{/* Skip chars and claculate the length til we get to (%) */
		init_flags(&flags, vlp);
		if (*s != '%')
		{
			len += _putchar(*s);
			continue;
		}
		start = s; /* Mark starting position */
		s++;
		if (get_flag(s, &flags))
			s++;
		if (get_modifier(s, &flags))
			s++;
		s = get_width(s, vlp, &flags);
		s = get_percision(s, vlp, &flags);
		if (get_matcher(s))
			len += _print_match_fnc(s, vlp, &flags);
		else
			len += _print_range(start, s, flags._long || flags._short ? s - 1 : 0);
	}

	_putchar(BUFFER_FLUSH);
	va_end(vlp);
	return (len);
}
