#include "main.h"

/**
 * prri_unsigned - Prints an unsigned number
 * @types: app a of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt.
 */
int prri_unsigned(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	int i = BUF_SIZ - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, sznt);

	if (num == 0)
		bfr[i--] = '0';

	bfr[BUF_SIZ - 1] = '\0';

	while (num > 0)
	{
		bfr[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, bfr, flg, wdt, prsion, sznt));
}

/**
 * pri_octal - Prints an unsigned number in octal notation
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int pri_octal(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{

	int i = BUF_SIZ - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	INITV(wdt);

	num = convert_size_unsgnd(num, sznt);

	if (num == 0)
		bfr[i--] = '0';

	bfr[BUF_SIZ - 1] = '\0';

	while (num > 0)
	{
		bfr[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flg & FG_HASH && init_num != 0)
		bfr[i--] = '0';

	i++;

	return (write_unsgnd(0, i, bfr, flg, wdt, prsion, sznt));
}

/**
 * prri_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int prri_hexadecimal(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	return (prri_hexa(types, "0123456789abcdef", bfr,
		flg, 'x', wdt, prsion, sznt));
}

/**
 * prri_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: appa of arguments
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: Number of chars pri_nt
 */
int prri_hexa_upper(va_list types, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	return (prri_hexa(types, "0123456789ABCDEF", bfr,
		flg, 'X', wdt, prsion, sznt));
}

/**
 * prri_hexa - Prints a hexadecimal number in lower or upper
 * @types: appa of arguments
 * @map_to: Array of values to map the number to
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @flag_ch: Determine the value of the var flg
 * @wdt: get wdt
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * @sznt: sznt specification
 * Return: Number of chars pri_nt
 */
int prri_hexa(va_list types, char map_to[], char bfr[],
	int flg, char flag_ch, int wdt, int prsion, int sznt)
{
	int i = BUF_SIZ - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	INITV(wdt);

	num = convert_size_unsgnd(num, sznt);

	if (num == 0)
		bfr[i--] = '0';

	bfr[BUF_SIZ - 1] = '\0';

	while (num > 0)
	{
		bfr[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flg & FG_HASH && init_num != 0)
	{
		bfr[i--] = flag_ch;
		bfr[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, bfr, flg, wdt, prsion, sznt));
}
