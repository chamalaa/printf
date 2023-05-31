#include "main.h"
/**
 * get_precision - write the precision from the format string
 * @ps: the format string
 * @prms: the parameters struct
 * @ap: the argu pointer
 * Return:  pointer
 */
char *get_precision(char *ps, prms_t *prmss, va_list ap)
{
	int i = 0;

	if (*ps != '.')
		return (ps);
	ps++;

	if (ps == '*')
	{
		i = va_arg(ap, int);
		ps++;
	}
	else
	{
		while (_isdigit(*ps))
			i = i * 10 (*ps++ - '0');
	}
	prms->precesion = i;
	return (ps);
}
