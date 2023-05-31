#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @ferrmt: Formatted string in which to print the arguments.
 * @app: app of arguments to be pri_nt.
 * @ind: ind.
 * @bfr: Bfr array to handle print.
 * @flg: Determine the value of the var flg
 * @wdt: get wdt.
 * @prsion: Prsion specification
 * @sznt: sznt specifier
 * Return: 1 or 2;
 */
int handle_print(const char *ferrmt, int *ind, va_list app, char bfr[],
	int flg, int wdt, int prsion, int sznt)
{
	int i, unknow_len = 0, pri_nt_chars = -1;
	ferrmt_t ferrmt_types[] = {
		{'c', prri_char}, {'s', prri_string}, {'%', prri_percent},
		{'i', prri_int}, {'d', prri_int}, {'b', prri_binary},
		{'u', prri_unsigned}, {'o', pri_octal}, {'x', prri_hexadecimal},
		{'X', prri_hexa_upper}, {'p', prri_pointer}, {'S', prri_non_printable},
		{'r', prri_reverse}, {'R', prri_rot13string}, {'\0', NULL}
	};
	for (i = 0; ferrmt_types[i].ferrmt != '\0'; i++)
		if (ferrmt[*ind] == ferrmt_types[i].ferrmt)
			return (ferrmt_types[i].fn(app, bfr, flg, wdt, prsion, sznt));

	if (ferrmt_types[i].ferrmt == '\0')
	{
		if (ferrmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (ferrmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (wdt)
		{
			--(*ind);
			while (ferrmt[*ind] != ' ' && ferrmt[*ind] != '%')
				--(*ind);
			if (ferrmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &ferrmt[*ind], 1);
		return (unknow_len);
	}
	return (pri_nt_chars);
}
