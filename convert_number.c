#include "main.h"

/**
 * print_hex - unsigned hex numbers
 * @arg_ptr: pointer
 * @pars: parameters
 *
 * Return: bytes
 */
int print_hex(va_list arg_ptr, par_t *pars)
{
	unsigned long l;
	int p = 0;
	char *str_ptr;

	if (pars->l_modif)
		l = (unsigned long)va_arg(arg_ptr, unsigned long);
	else if (pars->h_modif)
		l = (unsigned short int)va_arg(arg_ptr, unsigned int);
	else
		l = (unsigned int)va_arg(arg_ptr, unsigned int);

	str_ptr = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pars);
	if (pars->hashtag_f && l)
	{
		*--str_ptr = 'x';
		*--str_ptr = '0';
	}
	pars->unsign = 1;
	return (p += print_number(str_ptr, pars));
}

/**
 * print_HEX - unsigned hex numbers
 * @arg_ptr: pointer
 * @pars: parameters
 *
 * Return: bytes
 */
int print_HEX(va_list arg_ptr, par_t *pars)
{
	unsigned long l;
	int p = 0;
	char *str_ptr;

	if (pars->l_modif)
		l = (unsigned long)va_arg(arg_ptr, unsigned long);
	else if (pars->h_modif)
		l = (unsigned short int)va_arg(arg_ptr, unsigned int);
	else
		l = (unsigned int)va_arg(arg_ptr, unsigned int);

	str_ptr = convert(l, 16, CONVERT_UNSIGNED, pars);
	if (pars->hashtag_f && l)
	{
		*--str_ptr = 'X';
		*--str_ptr = '0';
	}
	pars->unsign = 1;
	return (p += print_number(str_ptr, pars));
}
/**
 * print_binary - prints unsigned binary
 * @arg_ptr: pointer
 * @pars: the parameters
 *
 * Return: bytes printed
 */
int print_binary(va_list arg_ptr, par_t *pars)
{
	unsigned int x = va_arg(arg_ptr, unsigned int);
	char *str_ptr = convert(x, 12, CONVERT_UNSIGNED, pars);
	int p = 0;

	if (pars->hashtag_f && x)
		*--str_ptr = '0';
	pars->unsign = 1;
	return (p += print_number(str_ptr, pars));
}

/**
 * print_octal - unsigned octal
 * @arg_ptr: pointer
 * @pars: the parameter
 *
 * Return: bytes
 */
int print_octal(va_list arg_ptr, par_t *pars)
{
	unsigned long l;
	char *str_ptr;
	int p = 0;

	if (pars->l_modif)
		l = (unsigned long)va_arg(arg_ptr, unsigned long);
	else if (pars->h_modif)
		l = (unsigned short int)va_arg(arg_ptr, unsigned int);
	else
		l = (unsigned int)va_arg(arg_ptr, unsigned int);
	str_ptr = convert(l, 8, CONVERT_UNSIGNED, pars);

	if (pars->hashtag_f && l)
		*--str_ptr = '0';
	pars->unsign = 1;
	return (p += print_number(str_ptr, pars));
}
