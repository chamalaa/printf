#include "main.h"
/**
 * pri_hex- write unsigned hex num for lowercase
 * @ap: the argument pointer
 * @prms: the parameters struct
 * Return: bytes printed
 */
int pri_hex(va_list ap, prms_t *prms)
{
	unsigned long lo;
	int x = 0;
	char *s;

	if (prms->1_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (prms->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);
	s = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, prms);
	if (prms->hashtag_fg && lo)
	{
		*--s = 'x';
		*--s = '0';
	}
	prms->unsign = 1;
	return (x += pri_number(s, prms));
}
/**
 * pri_HEX - write unsigned hex num for uppercase
 * @ap: the argument pointer
 * @prms: the parameters struct
 * Return: bytes printed
 */
int pri_HEX(va_list ap, prms_t *prms)
{
	unsigned long lo;
	int x = 0;
	char *s;

	if (prms->1_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (prms->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);
	s = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_UPPERCASE, prms);
	if (prms->hashtag_fg && lo)
	{
		*--s = 'X';
		*--s = '0';
	}
	prms->unsign = 1;
	return (x += pri_number(s, prms));
}
/**
 * pri_binary - write unsigned binary
 * @ap: the arg pointer
 * @prms: the parameters
 * Return: bytes
 */
int pri_binary(va_list ap, prms_t *prms)
{
	unsigned int i = va_arg(ap, unsigned int);
	char *s = convert(i, 2, CONVERT UNSIGNED, prms);
	int x  = 0;

	if (prms->hashtag_fg && i)
		*--s = '0';
	prms->unsign = 1;
	return (x += pri_number(s, prms));
}
/**
 * pri_octal - unsigned octal numbers
 * @ap: pointer
 * @prms: parametr
 * Return: bytes writed
 */
int pri_octal(va_list ap, prms_t *prms)
{
	unsigned long lo;
	int x = 0;
	char *s;

	if (prms->1_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (prms->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);
	s = convert(lo, 8, CONVERT_UNSIGNED, prms);
	if (prms->hashtag_fg && lo)
	{
		*--s = '0';
	}
	prms->unsign = 1;
	return (x += pri_number(s, prms));
}
