#include "main.h"

/**
 * print_char - prints character
 * @arg_ptr: argument pointer
 * @pars: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list arg_ptr, par_t *pars)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(arg_ptr, int);

	if (pars->minus_f)
		sum += _putchar(ch);
	while (pad++ < pars->width)
		sum += _putchar(pad_char);
	if (!pars->minus_f)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @arg_ptr: argument pointer
 * @pars: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list arg_ptr, par_t *pars)
{
	long l;

	if (pars->l_modif)
		l = va_arg(arg_ptr, long);
	else if (pars->h_modif)
		l = (short int)va_arg(arg_ptr, int);
	else
		l = (int)va_arg(arg_ptr, int);
	return (print_number(convert(l, 10, 0, pars), pars));
}

/**
 * print_string - prints string
 * @arg_ptr: argument pointer
 * @pars: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list arg_ptr, par_t *pars)
{
	char *str = va_arg(arg_ptr, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)pars;
	switch ((int)(!str))
		case 1:
			str = NULL_stringING;

	j = pad = _stringlen(str);
	if (pars->precision < pad)
		j = pad = pars->precision;

	if (pars->minus_f)
	{
		if (pars->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < pars->width)
		sum += _putchar(pad_char);
	if (!pars->minus_f)
	{
		if (pars->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @arg_ptr: argument pointer
 * @pars: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list arg_ptr, par_t *pars)
{
	(void)arg_ptr;
	(void)pars;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @arg_ptr: argument pointer
 * @pars: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list arg_ptr, par_t *pars)
{
	char *str = va_arg(arg_ptr, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_stringING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, pars);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
