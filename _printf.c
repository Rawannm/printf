#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list arg_ptr;
	char *c, *s;
	par_t pars = pars_INIT;

	va_start(arg_ptr, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_parameters(&pars, arg_ptr);
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
		c = get_width(c, &pars, arg_ptr);
		c = get_precision(c, &pars, arg_ptr);
		if (get_modifier(c, &pars))
			c++;
		if (!get_specifier(c))
			sum += print_from_to(s, c,
				pars.l_modif || pars.h_modif ? c - 1 : 0);
		else
			sum += get_print_func(c, arg_ptr, &pars);
	}
	_putchar(BUF_FLUSH);
	va_end(arg_ptr);
	return (sum);
}
