#include "main.h"
/**
 * init_parameters - clears struct and buf
 * @pars :struct parameters
 * @ap: pointer arg
 * Return : void
 */
void init_parameters(par_t *pars, va_list ap)
{
	pars->plus_f = 0;
	pars->space_f = 0;
	pars->hashtag_f = 0;
	pars->zero_f = 0;
	pars->minus_f = 0;
	pars->width = 0;
	pars->precision = UNIT_MAX;
	pars->h_modif = 0;
	pars->l_modif = 0;
	pars->unsign = 0;
	(void)ap;
}
