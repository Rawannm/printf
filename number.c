#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @arg_flags: argument flags
 * @pars: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int arg_flags, par_t *pars)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)pars;

	if (!(arg_flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = arg_flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @arg_ptr: argument pointer
 * @pars: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list arg_ptr, par_t *pars)
{
	unsigned long l;

	if (pars->l_modif)
		l = (unsigned long)va_arg(arg_ptr, unsigned long);
	else if (pars->h_modif)
		l = (unsigned short int)va_arg(arg_ptr, unsigned int);
	else
		l = (unsigned int)va_arg(arg_ptr, unsigned int);
	pars->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, pars), pars));
}

/**
 * print_address - prints address
 * @arg_ptr: argument pointer
 * @pars: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list arg_ptr, par_t *pars)
{
	unsigned long int n = va_arg(arg_ptr, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pars);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, pars));
}
