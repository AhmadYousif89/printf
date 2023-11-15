#ifndef _PRINTF_H
#define _PRINTF_H

/* HEADERS */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/* MACROS */
#define BUFFER_FLUSH -1
#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)
#define INIT_FLAGS { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

/* STRUCTURES */
/**
 * struct flags - Structure containing all possible flags given to (_printf)
 * @_unsign: checks for unsigned values
 * @_plus: checks for the (+) flag to convert nigative values
 * @_minus: checks for the (-) flag to convert positive values
 * @_zero: checks for the (0) flag to add zero padding
 * @_blank: checks for the (' ') flag if exist
 * @_hash: checks for the (#) flag to convert to an "alternative form"
 * @_short: checks for short or unsigned short flag (h)
 * @_long: checks for long or unsigned long flag (l)
 * @_width: checks for the _width flag if given
 * @_percision: checks for the (.) percision flag if given
 */
typedef struct flags
{
	unsigned int _unsign : 1;
	unsigned int _plus : 1;
	unsigned int _minus : 1;
	unsigned int _zero : 1;
	unsigned int _blank : 1;
	unsigned int _hash : 1;
	unsigned int _short : 1;
	unsigned int _long : 1;
	unsigned int _width;
	unsigned int _percision;
} flags_t;

/**
 * struct matcher - .
 * @token: pointer to the given flag
 * @func: function pointer to the corresponding print function
 */
typedef struct matcher
{
	char *token; /* c, s, d ...etc*/
	int (*func)(va_list, flags_t *);
} matcher_t;

/* PROTOTYPES */
int _printf(const char *format, ...);

int _puts(char *);
int _putchar(int);
int _print_range(char *, char *, char *);

int _print_digit(va_list, flags_t *);
int _print_char(va_list, flags_t *);
int _print_string(va_list, flags_t *);
int _print_percent(va_list, flags_t *);

int (*get_matcher(char *))(va_list, flags_t *);
int _print_match_fnc(char *, va_list, flags_t *);

char *get_percision(char *, va_list, flags_t *);
char *get_width(char *, va_list, flags_t *);
int get_modifier(char *, flags_t *);
int get_flag(char *, flags_t *);

int _print_num(char *, flags_t *);
char *convert(long int, int, int, flags_t *);

int _print_S(va_list, flags_t *);
int _print_adds(va_list, flags_t *);
int _print_rot13(va_list, flags_t *);
int _print_binary(va_list, flags_t *);
int _print_reverse(va_list, flags_t *);

int _isdigit(char c);
int _strlen(char *s);
void init_flags(flags_t *, va_list);

#endif
