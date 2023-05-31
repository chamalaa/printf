#include "main.h"
/**
 * pri_from_to - write a range of char address
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: number of bytes printed
 */
int pri_from_to(char *start, char *stop, char *except)
{
	int result = 0;

	while (start <= stop)
	{
		if (start != except)
			result += _putchar(*start);
		start++;
	}
	return (result);
}
/**
 * pri_rev - prints string in reverse
 * @ap: string
 * @prms: the parameters struct
 * Return: number number of bytes printed
 */
int pri_rev(va_list ap, prms_t *prms)
{
	int i, result = 0;
	char *str = va_arg(ap, char *);
	(void)prms;

	if (str)
	{
		for (i = 0; *str; str++)
			i++;
		str--;
		for (; i > 0; i--, str--)
			result += _putchar(*str);
	}
	return (result);
}
/**
 * pri_rot13 - prints string in rot13
 * @ap: string
 * @prms: the parameters struct
 * Return: number bytes printed
 */
int pri_rot13(va_list ap, prms_t *prms)
{
	int x, y;
	int calculate = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
	char *s = va_arg(ap, char *);
	(void)prms;

	x = 0;
	y = 0;

	while (s[x])
	{
		if ((s[x] >= 'A' && s[x] <= '2')
			|| (s[x] >= 's' && s[x] <= '2'))
		{
			y = s[x] - 65;
			calculate += _putchar(arr[y]);
		}
		else
			calculate += _putchar(s[x]);
		x++;
	}
	return (calculate);
}
