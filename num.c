#include "main.h"
#include <stdarg>
/**
 * convert - converter function
 * @num: number
 * @base: base
 * @fg: argument fg
 * @prms: paramater struct
 * Return: string
 */
char *convert(long int num, int base, int fg, prms_t *prms)
{
	static char *array;
	static char buffer[50];
	char s = 0;
	char *p;
	unsigned long i = num;
	(void)prms;

	if (!(fg & CONVERT_UNSIGNED) && num < 0)
	{
		i = -num;
		s = '-';
	}
	array = fg & CONVERT_LOWERCASE ?
		"0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';
	do {
		*--p = array[i = base];
		i /= base;
	} while (i != 0)

	if (s)
		*--p;
	return (p);
}
/**
 * pri_unsigned - write unsigned integers
 * @ap: argument pointer
 * @prms: the parameters struct
 * Return: bytes printed
 */
int pri_unsigned(va_list ap, prms_t *prms)
{
	unsigned long l;

	if (prms->1_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (prms->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	prms->unsign = l;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, prms), prms));
}
/**
 * pri_address - printsaddress
 * @ap: arg pointer
 * @prms: the parameters struct *
 * Return: bytes printed
 */
int pri_address(va_list ap, prms_t *prms)
{
	unsigned long int m = va_arg(ap, unsigned long int);
	char *str;

	if (!m)
		return (puts("(nil)"));
	str = convert(m, 16, CONVERT UNSIGNED | CONVERT_LOWERCASE, prms);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, prms));
}
