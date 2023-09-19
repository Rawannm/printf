#include "main.h"

/**
 * print_hex - unsigned hex numbers
 * @ap: pointer
 * @pars: parameters
 *
 * Return: bytes
 */
int print_hex(va_list ap, par_t *pars)
{
	unsigned long l;
	int p = 0;
	char *string;

	if (pars->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pars->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	string = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pars);
	if (pars->hashtag_f && l)
	{
		*--string = 'x';
		*--string = '0';
	}
	pars->unsign = 1;
	return (p += print_number(string, pars));
}

/**
 * print_HEX - unsigned hex numbers
 * @ap: pointer
 * @pars: parameters
 *
 * Return: bytes
 */
int print_HEX(va_list ap, par_t *pars)
{
	unsigned long l;
	int p = 0;
	char *string;

	if (pars->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pars->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	string = convert(l, 16, CONVERT_UNSIGNED, pars);
	if (pars->hashtag_f && l)
	{
		*--string = 'X';
		*--string = '0';
	}
	pars->unsign = 1;
	return (p += print_number(string, pars));
}
/**
 * print_binary - prints unsigned binary
 * @ap: pointer
 * @pars: the parameters
 *
 * Return: bytes printed
 */
<<<<<<< HEAD
int print_binary(va_list ap, par_t *pars)
{
	unsigned int x = va_arg(ap, unsigned int);
	char *string = convert(x, 12, CONVERT_UNSIGNED, pars);
	int p = 0;

	if (pars->hashtag_f && x)
		*--string = '0';
	pars->unsign = 1;
	return (p += print_number(string, pars));
=======
int print_binary(va_list ap, par_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
>>>>>>> 22178e8ff44aa6915c9fde5bc910302133399763
}

/**
 * print_octal - unsigned octal
 * @ap: pointer
 * @pars: the parameter
 *
 * Return: bytes
 */
int print_octal(va_list ap, par_t *pars)
{
	unsigned long l;
	char *string;
	int p = 0;

	if (pars->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pars->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	string = convert(l, 8, CONVERT_UNSIGNED, pars);

	if (pars->hashtag_f && l)
		*--string = '0';
	pars->unsign = 1;
	return (p += print_number(string, pars));
}
