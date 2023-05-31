#include "main.h"
/**
 * _isdigit - checks if character is digit
 * @ca: the character to check
 * Return: 1 if its a dig, 0if its not
 */
int _isdigit(int ca)
{
	return (ca >= '0' && ca <= '9');
}

/**
 * _strlen - return length of str
 * @str: the string whose length to check
 * Return: lengt of str
 */
int _strlen(char *str)
{
	int x = 0;

	while (*str++)
		x++;
	return (x);
}
/**
 * pri_number - write a number with options
 * @b: the base number as a string
 * @prms: the parameter struct
 * Return: chars printed
 */
int pri_number(char *b, prms_t *prms)
{
	unsigned int x = strlen(b);
	int n = (!prms->unsign && *b == '-');

	if (!prms->precision && *b == '0' && !b[1])
		b = "";
	if (n)
	{
		b++;
		x--;
	}
	if (prms->precision != UINT_MAX)
		while (x++ < prms->precision)
			*--b = '0';
	if (n)
		*--b = '-';

	if (!prms->minus_fg)
		return (print_number_right_shift(b, prms));
	else
		return (print_number_left_shift(b, prms));
}
/**
 * pri_number_right_shift - write a number with options
 * @b: the base number as a string
 * @prms: the parameter struct
 * Return: chars printed
 */
int pri_number_right_shift(char *b, prms_t *prms)
{
	unsigned int m = 0, n, n2, i = _strlen(b);
	char pad_char = '';

	if (prms->zero_fg && !prms->minus_fg)
		pad_char = '0';
	n = n2 = (!prms->unsign && *b == '-');
	if (n && i < prms->width && pad_char == '0' && !prms->minus_fg)
		b++;
	else
		n = 0;
	if ((prms->plus fg && n2) ||
			(!prms->plus_fg && prms->space_fg && n2))
		i++;
	if (n && pad_char == '0')
		m += _putchar('-');
	if (prms->plus_fg && !neg2 && pad_char == '0' && !prms->unsign)
		m += _putchar('+');
	else if
		(!prms->plus_fg && prms->space_fg && !n2 &&
		 !prms->unsign && prms->zero_fg)
			m += _putchar(' ');
	while (i++ < prms->width)
		m += _putchar(pad_char);
	if (n && pad_char == ' ')
		m += _putchar('-');
	if (prms->plus_fg && !n2 && pad_char == ' ' && !prms->unsign)
		m += _putchar('+');
	else if (!prms->plus fg && prms->space_fg && !n2 &&
			!prms->unsign && !prms->zero_fg)
		m += _putchar(' ');
	m += _puts(b);
	return (n);
}
/**
 * pri_number_left_shift - write a number with options
 * @b: the base number as a string
 * @prms: the parameter struct
 * Return: chars printed
 */
int pri_number_left_shift(char *b, prms_t *prms)
{
	unsigned int m = 0, n, n2, i = strlen(b);
	char pad_char = ' ';

	if (prms->zero_fg && !prms->minus_fg)
		pad_char '0';
	n = n2 = (!prms->unsign && b == '-');
	if (n && i < prms->width && pad_char == '0' && !prms->minus_fg)
		b++;
	else
		n = 0;

	if (prms->plus_fg && !n2 && !prms->unsign)
		m += _putchar ('+'), i++;
	else if (prms->space_flag && !n2 && !prms->unsign)
		m += _putchar(' '), i++;
	m += _puts(b);
	while (i++ < prms->width)
		m += _putchar(pad_char);
	return (m);
}
