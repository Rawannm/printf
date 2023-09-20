#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @fmt_string: the format string
 * @pars: the parameters struct
 * @arg_ptr: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *fmt_string, par_t *pars, va_list arg_ptr)
{
	int d = 0;

	if (*fmt_string != '.')
		return (fmt_string);
	fmt_string++;
	if (*fmt_string == '*')
	{
		d = va_arg(arg_ptr, int);
		fmt_string++;
	}
	else
	{
		while (_isdigit(*fmt_string))
			d = d * 10 + (*fmt_string++ - '0');
	}

	pars->precision = d;
	return (fmt_string);
}
