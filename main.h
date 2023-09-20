#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_stringING "(null)"

#define pars_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

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
	unsigned int width;
	unsigned int precision;
	unsigned int h_modif :1;
	unsigned int l_modif :1;
} par_t;

int _printf(const char *format, ...);
int _putchar(int p);
int print_char(va_list arg_ptr, par_t *pars);
int print_string(va_list arg_ptr, par_t *pars);
int print_percent(va_list arg_ptr, par_t *pars);

/**
 * struct specifier - stringuct
 *
 * @specifier: token
 * @func: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*func)(va_list, par_t *pars);
} spec_t;

int _puts(char *str_ptr);
int _putchar(int p);

int print_char(va_list arg_ptr, par_t *pars);
int print_int(va_list arg_ptr, par_t *pars);
int print_stringing(va_list arg_ptr, par_t *pars);
int print_percent(va_list arg_ptr, par_t *pars);
int print_S(va_list arg_ptr, par_t *pars);

char *convert(long int number, int base, int flag, par_t *pars);
int print_unsigned(va_list arg_ptr, par_t *pars);
int print_address(va_list arg_ptr, par_t *pars);

int (*get_specifier(char *s))(va_list arg_ptr, par_t *pars);
int get_print_func(char *s, va_list arg_ptr, par_t *pars);
int get_flag(char *s, par_t *pars);
int get_modifier(char *s, par_t *pars);
char *get_width(char *s, par_t *pars, va_list arg_ptr);

int print_hex(va_list arg_ptr, par_t *pars);
int print_HEX(va_list arg_ptr, par_t *pars);
int print_binary(va_list arg_ptr, par_t *pars);
int print_octal(va_list arg_ptr, par_t *pars);

int print_from_to(char *start, char *stop, char *ex);
int print_rev(va_list arg_ptr, par_t *pars);
int print_rot13(va_list arg_ptr, par_t *pars);

int _isdigit(int p);
int _stringlen(char *s);
int print_number(char *str_ptr, par_t *pars);
int print_number_rs(char *str_ptr, par_t *pars);
int print_number_ls(char *str_ptr, par_t *pars);

void init_parameters(par_t *pars, va_list arg_ptr);

char *get_precision(char *c, par_t *pars, va_list arg_ptr);

int _printf(const char *format, ...);

#endif
