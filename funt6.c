#include "main.h"

/**
 * prri_pointer - Prints the value of a pointer variable
 * @types: app a of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt.
 */
int prri_pointer(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	char extra_c = 0, padd_ing = ' ';
	int ind = BUF_SIZ - 2, length = 2, padd_ing_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	INITV(wdt);
	INITV(sznt);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	bfr[BUF_SIZ - 1] = '\0';
	INITV(prsion);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		bfr[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flg & FG_ZERO) && !(flg & FG_MIN))
		padd_ing = '0';
	if (flg & FG_PLUS)
		extra_c = '+', length++;
	else if (flg & FG_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &bfr[i], BUF_SIZ - i - 1));*/
	return (write_pointer(bfr, ind, length,
		wdt, flg, padd_ing, extra_c, padd_ing_start));
}

/**
 * prri_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int prri_non_printable(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	INITV(flg);
	INITV(wdt);
	INITV(prsion);
	INITV(sznt);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			bfr[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], bfr, i + offset);

		i++;
	}

	bfr[i + offset] = '\0';

	return (write(1, bfr, i + offset));
}

/**
 * prri_reverse - Prints reverse string.
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Numbers of chars pri_nt
 */

int prri_reverse(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	char *str;
	int i, count = 0;

	INITV(bfr);
	INITV(flg);
	INITV(wdt);
	INITV(sznt);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		INITV(prsion);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * prri_rot13string - Print a string in rot13.
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Numbers of chars pri_nt
 */
int prri_rot13string(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	INITV(bfr);
	INITV(flg);
	INITV(wdt);
	INITV(prsion);
	INITV(sznt);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
