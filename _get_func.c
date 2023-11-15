#include "main.h"

/**
 * get_modifier - Checks for the modifiers (h) and (l) and set the flags
 * @s: pointer to the format string
 * @flags: pointer to the flags struct
 * Return: int
 */
int get_modifier(char *s, flags_t *flags)
{
	int x = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'h')
			x = flags->_short = 1;
		if (s[i] == 'l')
			x = flags->_long = 1;
	}

	return (x);
}

/**
 * get_flag - Checks for the flags (+, -, ' ', 0, and #) and set the flags
 * @s: pointer to the format string
 * @flags: pointer to the flags struct
 * Return: int
 */
int get_flag(char *s, flags_t *flags)
{
	int x = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '0')
			x = flags->_zero = 1;
		if (s[i] == '+')
			x = flags->_plus = 1;
		if (s[i] == '-')
			x = flags->_minus = 1;
		if (s[i] == ' ')
			x = flags->_blank = 1;
		if (s[i] == '#')
			x = flags->_hash = 1;
	}

	return (x);
}

/**
 * get_width - Checks for the _width flag (*) and set the flag
 * @s: pointer to the format string
 * @vlp: the argument list pointer
 * @flags: pointer to the flags struct
 * Return: pointer
 */
char *get_width(char *s, va_list vlp, flags_t *flags)
{
	int w = 0;

	if (*s == '*')
	{
		w = va_arg(vlp, int);
		s++;
	}
	else
		while (_isdigit(*s))
		{
			w *= 10;
			w += *s - '0';
			s++;
		}

	flags->_width = w;
	return (s);
}

/**
 * get_percision - Checks for the percision flag (.) and set the flag
 * @s: pointer to the format string
 * @vlp: the argument list pointer
 * @flags: pointer to the flags struct
 * Return: pointer
 */
char *get_percision(char *s, va_list vlp, flags_t *flags)
{
	int n = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		n = va_arg(vlp, int);
		s++;
	}
	else
		while (_isdigit(*s))
		{
			n *= 10;
			n += *s - '0';
			s++;
		}

	flags->_percision = n;
	return (s);
}
