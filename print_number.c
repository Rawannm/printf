#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _stringlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _stringlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @pars: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, par_t *pars)
{
	unsigned int i = _stringlen(str);
	int neg = (!pars->unsign && *str == '-');

	if (!pars->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (pars->precision != UINT_MAX)
		while (i++ < pars->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!pars->minus_f)
		return (print_number_rs(str, pars));
	else
		return (print_number_ls(str, pars));
}

/**
 * print_number_rs - prints a number with options
 * @str: the base number as a string
 * @pars: the parameter struct
 *
 * Return: chars printed
 */
int print_number_rs(char *str, par_t *pars)
{
	unsigned int n = 0, neg, neg2, i = _stringlen(str);
	char pad_char = ' ';

	if (pars->zero_f && !pars->minus_f)
		pad_char = '0';
	neg = neg2 = (!pars->unsign && *str == '-');
	if (neg && i < pars->width && pad_char == '0' && !pars->minus_f)
		str++;
	else
		neg = 0;
	if ((pars->plus_f && !neg2) ||
		(!pars->plus_f && pars->space_f && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (pars->plus_f && !neg2 && pad_char == '0' && !pars->unsign)
		n += _putchar('+');
	else if (!pars->plus_f && pars->space_f && !neg2 &&
		!pars->unsign && pars->zero_f)
		n += _putchar(' ');
	while (i++ < pars->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (pars->plus_f && !neg2 && pad_char == ' ' && !pars->unsign)
		n += _putchar('+');
	else if (!pars->plus_f && pars->space_f && !neg2 &&
		!pars->unsign && !pars->zero_f)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_ls - prints a number with options
 * @str: the base number as a string
 * @pars: the parameter struct
 *
 * Return: chars printed
 */
int print_number_ls(char *str, par_t *pars)
{
	unsigned int n = 0, neg, neg2, i = _stringlen(str);
	char pad_char = ' ';

	if (pars->zero_f && !pars->minus_f)
		pad_char = '0';
	neg = neg2 = (!pars->unsign && *str == '-');
	if (neg && i < pars->width && pad_char == '0' && !pars->minus_f)
		str++;
	else
		neg = 0;

	if (pars->plus_f && !neg2 && !pars->unsign)
		n += _putchar('+'), i++;
	else if (pars->space_f && !neg2 && !pars->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < pars->width)
		n += _putchar(pad_char);
	return (n);
}
