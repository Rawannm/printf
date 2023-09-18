#include "main.h"

/**
 * init_parameters - clears struct fields and reset buf
 * @pars: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_parameters(par_t *pars, va_list ap)
{
	pars->unsign = 0;

	pars->plus_flag = 0;
	pars->space_flag = 0;
	pars->hashtag_flag = 0;
	pars->zero_flag = 0;
	pars->minus_flag = 0;

	pars->width = 0;
	pars->precision = UINT_MAX;

	pars->h_modifier = 0;
	pars->l_modifier = 0;
	(void)ap;
}
