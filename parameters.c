#include "main.h"
/**
 * init_parameters - clears struct and buf
 * @pars :struct parameters
 * @ap: pointer arg
 * Return : void
 */
void init_parameters(par_t *pars, va_list ap)
{
	par->plus_f = 0;
	par->space_f = 0;
	par->hashtag_f = 0;
	par->zero_f = 0;
	par->minus_f = 0;
	par->width = 0;
	par->precision = UNIT_MAX;
	par->h_modif = 0;
	par->l_modif = 0;
	par->unsign = 0;
	(void)ap;
}
