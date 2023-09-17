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
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
