#include "main.h"

/**
 * get_matcher - .
 * @s: pointer to the format string
 * Return: NULL or the corresponding print function
 */
int (*get_matcher(char *s))(va_list, flags_t *)
{
	int i = 0;
	matcher_t m[] = {
		{"d", _print_digit},
		{"i", _print_digit},
		{"c", _print_char},
		{"s", _print_string},
		{"%", _print_percent},
		{NULL, NULL}};

	while (m[i].token != NULL)
	{ /* Compare the value of (s) against the specifier */
		if (m[i].token[0] == *s)
			return (m[i].func);
		i++;
	}

	return (NULL);
}

/**
 * _print_match_fnc - .
 * @s: pointer to the format string
 * @vlp: pointer to the arg list
 * @flags: pointer to the flags struct
 * Return: int
 */
int _print_match_fnc(char *s, va_list vlp, flags_t *flags)
{
	int (*func)(va_list, flags_t *) = get_matcher(s);

	if (func)
		return (func(vlp, flags));
	return (0);
}
