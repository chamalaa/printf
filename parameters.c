#include "main.h"

/**
* init_prms - clears struct fields and reset buf
* @prms: the parameters struct
* @ap: the argument pointer
* Return: void
*/
void init_prms(prms_t *prms, va_list ap)
{

prms->unsign = 0;
prms->plus_fg = 0;
prms->space_fg = 0;
prms->hashtag_fg = 0;
prms->zero_fg = 0;
prms->minus_fg = 0;
prms->width = 0;
prms->precision = UINT_MAX;
prms->h_modifier = 0;
prms->l_modifier = 0;
(void) ap;
}
