#include "main.h"

/**
 * getfonct_wdts - Determine value of wdt for printing
 * @format: Formatted string in which to print the arguments.
 * @i: app of arguments to be pri_nt.
 * @app: app of arguments.
 *
 * Return: wdt.
 */
int getfonct_wdts(const char *format, int *i, va_list app)
{
	int curr_i;
	int wdt = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			wdt *= 10;
			wdt += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			wdt = va_arg(app, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (wdt);
}

