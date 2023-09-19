#include "main.h"

/**
* _printf - to print
* @format: a character string
*
* Return: number of bytes
*/
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *c, *s;
	par_t pars =  _PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && !format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_parameters(&pars, ap);
		if (*c != '%')
		{
			sum += _putchar(*c);
			continue;
		}
		s = c;
		c++;
		while (get_flag(c, &pars))
		{
			c++;
		}
		c = get_flag(c, &pars, ap);
		c = get_percision(c, &pars, ap);
		if (get_modif(c, &pars))
			c++;
		if (!get_specifier(c))
			sum += print_from_to(s, c, pars.l_modif || pars.h_modif ? c - 1 : 0);
		else
			sum += get_print_func(c, ap, &pars);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
