#include "main.h"

/**
 * get_specifier - format func
 * @s: string
 *
 * Return: number of bytes
 */
int (*get_specifier(char *s))(va_list ap, par_t *pars)
{
	spec_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int n = 0;

	while (specifiers[n].specifier)
	{
		if (*s == specifiers[n].specifier[0])
		{
			return (specifiers[n].func);
		}
		n++;
	}
	return (NULL);
}

/**
 * get_print_func - format func
 * @s: string
 * @ap: pointer
 * @pars: struct
 *
 * Return: number of bytes printed
 */
int get_print_func(char *s, va_list ap, par_t *pars)
{
	int (*func)(va_list, par_t *) = get_specifier(s);

	if (func)
		return (func(ap, pars));
	return (0);
}

/**
 * get_flag - flag func
 * @s: string
 * @pars: struct
 *
 * Return: if valid
 */
int get_flag(char *s, par_t *pars)
{
	int n = 0;

	switch (*s)
	{
		case '+':
			n = pars->plus_f = 1;
			break;
		case ' ':
			n = pars->space_f = 1;
			break;
		case '#':
			n = pars->hashtag_f = 1;
			break;
		case '-':
			n = pars->minus_f = 1;
			break;
		case '0':
			n = pars->zero_f = 1;
			break;
	}
	return (n);
}

/**
 * get_modifier - modifier func
 * @s: the string
 * @pars: parameters stru
 *
 * Return: if m valid
 */
int get_modifier(char *s, par_t *pars)
{
	int n = 0;

	switch (*s)
	{
	case 'h':
		n = pars->h_modif = 1;
		break;
	case 'l':
		n = pars->l_modif = 1;
		break;
	}
	return (n);
}

/**
 * get_width - gets the width
 * @s: string
 * @pars: parameters
 * @ap: pointer
 *
 * Return: pointer
 */
char *get_width(char *s, par_t *pars, va_list ap)
{
	int g = 0;

	if (*s == '*')
	{
		g = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			g = g * 10 + (*s++ - '0');
	}
	pars->width = g;
	return (s);
}
