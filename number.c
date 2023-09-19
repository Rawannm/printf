#include "main.h"

/**
 * convert - converter function
 * @number: flagber
 * @base: base
 * @flag: flag
 * @pars: paramater
 *
 * Return: string
 */
char *convert(long int number, int base, int flag, par_t *pars)
{
	static char *arr;
	static char buffer[50];
	char y = 0;
	char *t;
	unsigned long x = number;
	(void)pars;

	if (!(flag & CONVERT_UNSIGNED) && number < 0)
	{
		x = -flag;
		y = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	t = &buffer[49];
	*t = '\0';

	do	{
		*--t = arr[n % base];
		x /= base;
	} while (x != 0);

	if (y)
		*--t = y;
	return (t);
}

/**
 * print_unsigned - prints unsigned integer flagbers
 * @ap: argument pointer
 * @pars: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, par_t *pars)
{
	unsigned long l;

	if (pars->l_modif)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pars->h_modif)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	pars->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, pars), pars));
}



/**
 * print_address - prints address
 * @ap: argument pointer
 * @pars: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list ap, par_t *pars)
{
	unsigned long int x = va_arg(ap, unsigned long int);
	char *string;

	if (!x)
		return (_puts("(nil)"));
	string = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pars);
	*--string = 'x';
	*--string = 'o';
	return (print_number(string, pars));
}

