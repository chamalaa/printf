#include "main.h"


/**
 * prri_char - Prints a char
 * @types: app a of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: Wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int prri_char(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, bfr, flg, wdt, prsion, sznt));
}
/**
 * prri_string - Prints a string
 * @types: app a of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt.
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int prri_string(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	INITV(bfr);
	INITV(flg);
	INITV(wdt);
	INITV(prsion);
	INITV(sznt);
	if (str == NULL)
	{
		str = "(null)";
		if (prsion >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (prsion >= 0 && prsion < length)
		length = prsion;

	if (wdt > length)
	{
		if (flg & FG_MIN)
		{
			write(1, &str[0], length);
			for (i = wdt - length; i > 0; i--)
				write(1, " ", 1);
			return (wdt);
		}
		else
		{
			for (i = wdt - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (wdt);
		}
	}

	return (write(1, str, length));
}
/**
 * prri_percent - Prints a percent sign
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt.
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int prri_percent(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	INITV(types);
	INITV(bfr);
	INITV(flg);
	INITV(wdt);
	INITV(prsion);
	INITV(sznt);
	return (write(1, "%%", 1));
}

/**
 * prri_int - Print int
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt.
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int prri_int(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	int i = BUF_SIZ - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, sznt);

	if (n == 0)
		bfr[i--] = '0';

	bfr[BUF_SIZ - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		bfr[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, bfr, flg, wdt, prsion, sznt));
}

/**
 * prri_binary - Prints an unsigned number
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt.
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Numbers of char pri_nt.
 */
int prri_binary(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	INITV(bfr);
	INITV(flg);
	INITV(wdt);
	INITV(prsion);
	INITV(sznt);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
