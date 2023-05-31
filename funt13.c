#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg.
 * @wdt: get wdt.
 * @prsion: prsion specifier
 * @sznt: sznt specifier
 *
 * Return: Number of chars pri_nt.
 */
int handle_write_char(char c, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{ /* char is stored at left and padd_ingind at bfr's right */
	int i = 0;
	char padd_ing = ' ';

	INITV(prsion);
	INITV(sznt);

	if (flg & FG_ZERO)
		padd_ing = '0';

	bfr[i++] = c;
	bfr[i] = '\0';

	if (wdt > 1)
	{
		bfr[BUF_SIZ - 1] = '\0';
		for (i = 0; i < wdt - 1; i++)
			bfr[BUF_SIZ - i - 2] = padd_ing;

		if (flg & FG_MIN)
			return (write(1, &bfr[0], 1) +
					write(1, &bfr[BUF_SIZ - i - 1], wdt - 1));
		else
			return (write(1, &bfr[BUF_SIZ - i - 1], wdt - 1) +
					write(1, &bfr[0], 1));
	}

	return (write(1, &bfr[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: appa of arguments
 * @ind: char types.
 * @bfr: Bfr array to handle print
 * @flg:  Determine the value of the var flg
 * @wdt: get wdt.
 * @prsion: prsion specifier
 * @sznt: sznt specifier
 *
 * Return: Number of chars pri_nt.
 */
int write_number(int is_negative, int ind, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	int length = BUF_SIZ - ind - 1;
	char padd_ing = ' ', extra_ch = 0;

	INITV(sznt);

	if ((flg & FG_ZERO) && !(flg & FG_MIN))
		padd_ing = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flg & FG_PLUS)
		extra_ch = '+';
	else if (flg & FG_SPACE)
		extra_ch = ' ';

	return (write_num(ind, bfr, flg, wdt, prsion,
		length, padd_ing, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the bfr
 * @bfr: Bfr
 * @flg: Flg
 * @wdt: wdt
 * @prec: Prsion specifier
 * @length: Number length
 * @padd_ing: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of pri_nt chars.
 */
int write_num(int ind, char bfr[],
	int flg, int wdt, int prec,
	int length, char padd_ing, char extra_c)
{
	int i, padd_ing_start = 1;

	if (prec == 0 && ind == BUF_SIZ - 2 && bfr[ind] == '0' && wdt == 0)
		return (0); /* printf(".0d", 0)  no char is pri_nt */
	if (prec == 0 && ind == BUF_SIZ - 2 && bfr[ind] == '0')
		bfr[ind] = padd_ing = ' '; /* wdt is displayed with pading ' ' */
	if (prec > 0 && prec < length)
		padd_ing = ' ';
	while (prec > length)
		bfr[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (wdt > length)
	{
		for (i = 1; i < wdt - length + 1; i++)
			bfr[i] = padd_ing;
		bfr[i] = '\0';
		if (flg & FG_MIN && padd_ing == ' ')/* Asign extra char to left of bfr */
		{
			if (extra_c)
				bfr[--ind] = extra_c;
			return (write(1, &bfr[ind], length) + write(1, &bfr[1], i - 1));
		}
		else if (!(flg & FG_MIN) && padd_ing == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				bfr[--ind] = extra_c;
			return (write(1, &bfr[1], i - 1) + write(1, &bfr[ind], length));
		}
		else if (!(flg & FG_MIN) && padd_ing == '0')/* extra char to left of padd_ing */
		{
			if (extra_c)
				bfr[--padd_ing_start] = extra_c;
			return (write(1, &bfr[padd_ing_start], i - padd_ing_start) +
				write(1, &bfr[ind], length - (1 - padd_ing_start)));
		}
	}
	if (extra_c)
		bfr[--ind] = extra_c;
	return (write(1, &bfr[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the bfr
 * @bfr: Array of chars
 * @flg: Flg specifiers
 * @wdt: Wdt specifier
 * @prsion: Prsion specifier
 * @sznt: sznt specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	/* The number is stored at the bfr's right and starts at position i */
	int length = BUF_SIZ - ind - 1, i = 0;
	char padd_ing = ' ';

	INITV(is_negative);
	INITV(sznt);

	if (prsion == 0 && ind == BUF_SIZ - 2 && bfr[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is pri_nt */

	if (prsion > 0 && prsion < length)
		padd_ing = ' ';

	while (prsion > length)
	{
		bfr[--ind] = '0';
		length++;
	}

	if ((flg & FG_ZERO) && !(flg & FG_MIN))
		padd_ing = '0';

	if (wdt > length)
	{
		for (i = 0; i < wdt - length; i++)
			bfr[i] = padd_ing;

		bfr[i] = '\0';

		if (flg & FG_MIN) /* Asign extra char to left of bfr [bfr>padd_ing]*/
		{
			return (write(1, &bfr[ind], length) + write(1, &bfr[0], i));
		}
		else /* Asign extra char to left of pading [padd_ing>bfr]*/
		{
			return (write(1, &bfr[0], i) + write(1, &bfr[ind], length));
		}
	}

	return (write(1, &bfr[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @bfr: Arrays of chars
 * @ind: Index at which the number starts in the bfr
 * @length: Length of number
 * @wdt: Wdt specifier
 * @flg: Flg specifier
 * @padd_ing: Char representing the pading
 * @extra_c: Char representing extra char
 * @padd_ing_start: Index at which pading should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char bfr[], int ind, int length,
	int wdt, int flg, char padd_ing, char extra_c, int padd_ing_start)
{
	int i;

	if (wdt > length)
	{
		for (i = 3; i < wdt - length + 3; i++)
			bfr[i] = padd_ing;
		bfr[i] = '\0';
		if (flg & FG_MIN && padd_ing == ' ')/* Asign extra char to left of bfr */
		{
			bfr[--ind] = 'x';
			bfr[--ind] = '0';
			if (extra_c)
				bfr[--ind] = extra_c;
			return (write(1, &bfr[ind], length) + write(1, &bfr[3], i - 3));
		}
		else if (!(flg & FG_MIN) && padd_ing == ' ')/* extra char to left of bfr */
		{
			bfr[--ind] = 'x';
			bfr[--ind] = '0';
			if (extra_c)
				bfr[--ind] = extra_c;
			return (write(1, &bfr[3], i - 3) + write(1, &bfr[ind], length));
		}
		else if (!(flg & FG_MIN) && padd_ing == '0')/* extra char to left of padd_ing */
		{
			if (extra_c)
				bfr[--padd_ing_start] = extra_c;
			bfr[1] = '0';
			bfr[2] = 'x';
			return (write(1, &bfr[padd_ing_start], i - padd_ing_start) +
				write(1, &bfr[ind], length - (1 - padd_ing_start) - 2));
		}
	}
	bfr[--ind] = 'x';
	bfr[--ind] = '0';
	if (extra_c)
		bfr[--ind] = extra_c;
	return (write(1, &bfr[ind], BUF_SIZ - ind - 1));
}
