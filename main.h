#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define _PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
/**
 *  struct parameters - struct to get the pramters
 *  @unsign : unsigned par
 *  @plus_f :plus flag
 *  @space_f: space flag
 *  @hashtag_f:hashtag flag
 *  @zero_f :zero flag
 *  @minus_f :minus flag
 *  @width :field width specified
 *  @precision: field precision specified
 *  @h_modif: field h_modifier specified
 *  @l_modif: field l_modifier specified
 */
typedef struct parameters
{
	unsigned int unsign :1;
	unsigned int plus_f :1;
	unsigned int space_f :1;
	unsigned int hashtag_f :1;
	unsigned int zero_f :1;
	unsigned int minus_f :1;
	unsigned int width :1;
	unsigned int precision :1;
	unsigned int h_modif :1;
	unsigned int l_modif :1;
} par_t;

int _printf(const char *format, ...);
int _putchar(int p);
int print_char(va_list ap, par_t *pars);
int print_string(va_list ap, par_t *pars);
int print_percent(va_list ap, par_t *pars);

int print_binary(va_list ap, par_t *pars);
void init_parameters(par_t *pars, va_list ap);

#endif
