#include "main.h"

/**void pri_buf(char bfr[], int *bfr_in);*/
void pri_buf(char bfr[], int *bfr_in);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Pri_nt chars.
 */
int _printf(const char *format, ...)
{
	int i, pri_nt = 0, pri_nt_chars = 0;
	int flg, wdt, prsion, sznt, bfr_in = 0;
	va_list app;
	char bfr[BUF_SIZ];

	if (format == NULL)
		return (-1);

	va_start(app, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bfr[bfr_in++] = format[i];
			if (bfr_in == BUF_SIZ)
				pri_buf(bfr, &bfr_in);

			/* write(1, &format[i], 1);*/
			pri_nt_chars++;
		}
		else
		{
			pri_buf(bfr, &bfr_in);
			flg = getfonct_flag(format, &i);
			wdt = getfonct_wdts(format, &i, app);
			prsion = get_prsion(format, &i, app);
			sznt = getfonct_sizes(format, &i);
			++i;
			pri_nt = handle_print(format, &i, app, bfr,
				flg, wdt, prsion, sznt);
			if (pri_nt == -1)
				return (-1);
			pri_nt_chars += pri_nt;
		}
	}

	pri_buf(bfr, &bfr_in);

	va_end(app);

	return (pri_nt_chars);
}

/**
 * pri_buf - Prints the contents of the bfr if it exist
 * @bfr: Array of chars
 * @bfr_in: Index at which to add next char, represents the length.
 */
void pri_buf(char bfr[], int *bfr_in)
{
	if (*bfr_in > 0)
		write(1, &bfr[0], *bfr_in);

	*bfr_in = 0;
}
